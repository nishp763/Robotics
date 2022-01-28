#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>
#include <algorithm>
#include <array>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // Request a service and pass the velocities to it to drive the robot
    ROS_INFO_STREAM("Setting Bot Velocity");
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the drive_bot service and pass the requested velocity values
    if (!client.call(srv))
        ROS_ERROR("Failed to call service drive_bot");
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int white_pixel = 255;

    std::array<int,3> whitePixelCounterByRegion; // 0 - left region, 1 - center region, 2 - right region
    int leftRegionBoundary = (int)(0.30*img.step); // 0 to 30% of image width
    int rightRegionBoundary = (int)(0.70*img.step); // > 70% of image width


    for (int i = 0; i < (img.height * img.step); i++)
    {
        if (img.data[i] == white_pixel) // white ball detected
        {
            if (i < leftRegionBoundary) // pixel belongs to left region
            {
                whitePixelCounterByRegion[0]++; // left counter
            }
            else if (i > rightRegionBoundary) // pixel belongs to right region
            {
                whitePixelCounterByRegion[2]++; // right counter
            }
            else // pixel belongs to center region
            {
                whitePixelCounterByRegion[1]++; // center counter
            }
        }
    }

    int maxCount = *(std::max_element(whitePixelCounterByRegion.cbegin(), whitePixelCounterByRegion.cend()));
    if (maxCount == whitePixelCounterByRegion[0]) // Move Left
    {
        drive_robot(0.0, 0.5);
    }
    else if (maxCount == whitePixelCounterByRegion[1]) // Move Forward
    {
        drive_robot(0.5, 0.0);
    }
    else if (maxCount == whitePixelCounterByRegion[2]) // Move Right
    {
        drive_robot(0.0, -0.5);
    }
    else // stop
    {
        drive_robot(0.0, 0.0);
    }

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}