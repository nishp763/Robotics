# Project #5 - Home Service Robot
<p align="center">
  <img src="images/demo.gif"/>
</p>

### Overview
In this project you will simulate a full home service robot capable of navigating to pick up and deliver virtual objects.

### Project Instructions
To program your home service robot, you will need to interface it with different ROS packages. Some of these packages are official ROS packages which offer great tools and others are packages that you’ll create. The goal of this section is to prepare and build your `catkin workspace`.

Here’s the list of the official ROS packages that you will need to grab, and other packages and directories that you’ll need to create at a later stage as you go through the project. Your `catkin_ws/src` directory should look as follows:

<b>Official ROS packages</b>
Import these packages now and install them in the `src` directory of your `catkin workspace`. Be sure to clone the full GitHub directory and not just the package itself.

1. [gmapping](https://wiki.ros.org/gmapping): With the <b>gmapping_demo.launch</b> file, you can easily perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.
2. [turtlebot_teleop](https://wiki.ros.org/turtlebot_teleop): With the <b>keyboard_teleop.launch</b> file, you can manually control a robot using keyboard commands.
3. [turtlebot_rviz_launchers](https://wiki.ros.org/turtlebot_rviz_launchers): With the <b>view_navigation.launch</b> file, you can load a preconfigured rviz workspace. You’ll save a lot of time by launching this file, because it will automatically load the robot model, trajectories, and map for you.
4. [turtlebot_gazebo](https://wiki.ros.org/turtlebot_gazebo): With the <b>turtlebot_world.launch</b> you can deploy a turtlebot in a gazebo environment by linking the world file to it.

<b>Your Packages and Directories</b>

1. <b>map:</b> Inside this directory, you will store your gazebo world file and the map generated from SLAM.
2. <b>scripts:</b> Inside this directory, you’ll store your shell scripts.
3. <b>rvizConfig:</b> Inside this directory, you’ll store your customized rviz configuration files.
4. <b>pick_objects:</b> You will write a node that commands your robot to drive to the pickup and drop off zones.
5. <b>add_markers:</b> You will write a node that model the object with a marker in rviz.

### Directory Structure
```bash
.Project5
```

### Build Instructions
1. Open Terminal/CLI by using `Ctrl + Alt + T` shortcut.
2. Create and initialize a `catkin_ws`
```bash
mkdir -p /<your_dir>/catkin_ws/src
cd /<your_dir>/catkin_ws/src
catkin_init_workspace
```
3. Clone this repo inside `/<your_dir>/catkin_ws/src`. Pull all submodules by running
```bash
git submodule update --init --recursive
```
4. Build the code and ensure there are no build errors reported
```bash
catkin_make
```
5. Switch to `catkin_ws`
```bash
cd /<your_dir>/catkin_ws
```
6. Ensure `gmapping`, `turtlebot_teleop`, `turtlebot_rviz_launchers`, `turtlebot_gazebo` packages are installed. If not, install by running the following:
```bash
source devel/setup.bash
rosdep -i install gmapping
rosdep -i install turtlebot_teleop
rosdep -i install turtlebot_rviz_launchers
rosdep -i install turtlebot_gazebo
```
7. Build the code and ensure there are no build errors reported
```bash
catkin_make
```