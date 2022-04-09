# Project #5 - Home Service Robot
<p align="center">
  <img src="images/demo.jpg"/>
</p>

### Overview


### Project Instructions


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