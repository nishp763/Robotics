# Project #2 - Go Chase It!

### Summary of Tasks
In this project, you should create two ROS packages inside your `catkin_ws/src:` the `drive_bot` and the `ball_chaser`. Here are the steps to design the robot, house it inside your world, and program it to chase white-colored balls:
1. `drive_bot`:
	- Create a `my_robot` ROS package to hold your robot, the white ball, and the world.
	- Design a differential drive robot with the Unified Robot Description Format. Add two sensors to your robot: a lidar and a camera. Add Gazebo plugins for your robot’s differential drive, lidar, and camera. The robot you design should be significantly different from the one presented in the project lesson. Minimum required changes are adjusting the color, wheel radius, and chassis dimensions. You can also completely redesign the robot model!
	- Create a new world, which is different from the world you built in the <b>Build My World</b> project and house your robot inside that world.
	- Add a white-colored ball to your Gazebo world and save a new copy of this world.
	- The `world.launch` file should launch your world with the white-colored ball and your robot.

2. `ball_chaser`:
	- Create a `ball_chaser` ROS package to hold your C++ nodes.
	- Write a `drive_bot` C++ node that will provide a `ball_chaser/command_robot` service to drive the robot by controlling its linear x and angular z velocities. The service should publish to the wheel joints and return back the requested velocities.
	- Write a `process_image` C++ node that reads your robot’s camera image, analyzes it to determine the presence and position of a white ball. If a white ball exists in the image, your node should request a service via a client to drive the robot towards it.
	- The `ball_chaser.launch` should run both the `drive_bot` and the `process_image` nodes.

### Directory Structure
```bash

```

### Build Instructions
1. Open Terminal/CLI by using `Ctrl + Alt + T` shortcut.
2. Create and initialize a `catkin_ws`
```
mkdir -p /<your_dir>/catkin_ws/src
cd /<your_dir>/catkin_ws/src
catkin_init_workspace
```
3. Clone this repo inside `/<your_dir>/catkin_ws/src`
5. Ensure src directory has `my_robot` and `ball_chaser` directory inside it
6. Switch to `catkin_ws`
```bash
cd /<your_dir>/catkin_ws
```
7. Build the code and ensure there are no build errors reported
```bash
catkin_make
```
8. Launch RViz and Gazebo. This may take a while upon initial loading.
```bash
source devel/setup.bash
roslaunch my_robot world.launch
```
