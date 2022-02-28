# Project #3 - Where Am I?
<p align="center">
  <img src="images/demo.gif"/>
</p>

### Summary of Tasks
Welcome to the Where Am I? localization project! In this project, you will learn to utilize ROS AMCL package to accurately localize a mobile robot inside a map in the Gazebo simulation environments.
- Create a ROS package that launches a custom robot model in a custom Gazebo world
- Utilize the ROS AMCL package and the Tele-Operation / Navigation Stack to localize the robot
- Explore, add, and tune specific parameters corresponding to each package to achieve the best possible localization results

### Directory Structure
```bash
.Project3
├── ball_chaser																	# ball_chaser package
│   ├── CMakeLists.txt													# compiler instructions
│   ├── launch																	# launch folder for launch files
│   │   └── ball_chaser.launch
│   ├── package.xml															# package info
│   ├── src 																		# source folder for C++ scripts
│   │   ├── drive_bot.cpp
│   │   └── process_image.cpp
│   └── srv  																		# service folder for ROS services
│       └── DriveToTarget.srv
├── images 																			# output results
│   └── demo.gif
├── my_robot																		# my_robot package
│   ├── CMakeLists.txt													# compiler instructions
│   ├── config          												# config files
│   │   ├── base_local_planner_params.yaml
│   │   ├── costmap_common_params.yaml
│   │   ├── global_costmap_params.yaml
│   │   ├── local_costmap_params.yaml
│   │   └── __MACOSX
│   ├── launch 																	# launch folder for launch files
│   │   ├── amcl.launch
│   │   ├── robot_description.launch
│   │   └── world.launch
│   ├── maps 																		# map details
│   │   ├── map.pgm
│   │   └── map.yaml
│   ├── meshes
│   │   └── hokuyo.dae
│   ├── package.xml															# package info
│   ├── RVIZLaunchConfig.rviz 									# RVIZ config file
│   ├── urdf 																		# urdf folder for xacro files
│   │   ├── my_robot.gazebo
│   │   └── my_robot.xacro
│   └── worlds 																	# world folder for world files
│       ├── empty.world
│       └── UdacityOffice.world
├── pgm_map_creator															# pgm_map_creator package
│   ├── CMakeLists.txt													# compiler instructions
│   ├── launch 																	# launch folder for launch files
│   │   └── request_publisher.launch
│   ├── LICENSE
│   ├── maps
│   │   └── map.pgm
│   ├── msgs
│   │   ├── CMakeLists.txt
│   │   └── collision_map_request.proto
│   ├── package.xml															# package info
│   ├── README.md
│   ├── src
│   │   ├── collision_map_creator.cc
│   │   └── request_publisher.cc
│   └── world
│       ├── udacity_mtv
│       └── UdacityOffice.world
├── README.md
└── teleop_twist_keyboard												# teleop_twist_keyboard package
    ├── CHANGELOG.rst
    ├── CMakeLists.txt													# compiler instructions
    ├── package.xml															# package info
    ├── README.md
    └── teleop_twist_keyboard.py

```

### Build Instructions
1. Open Terminal/CLI by using `Ctrl + Alt + T` shortcut.
2. Create and initialize a `catkin_ws`
```bash
mkdir -p /<your_dir>/catkin_ws/src
cd /<your_dir>/catkin_ws/src
catkin_init_workspace
```
3. Clone this repo inside `/<your_dir>/catkin_ws/src`
4. Ensure `ros-kinetic-navigation`, `ros-kinetic-map-server`, `ros-kinetic-move-base`, `ros-kinetic-amcl` packages are installed. If not, install by running the following:
```bash
sudo apt-get install ros-kinetic-navigation
sudo apt-get install ros-kinetic-map-server
sudo apt-get install ros-kinetic-move-base
sudo apt-get install ros-kinetic-amcl
```
5. Switch to `catkin_ws`
```bash
cd /<your_dir>/catkin_ws
```
6. Build the code and ensure there are no build errors reported
```bash
catkin_make
```
7. Launch RViz and Gazebo. This may take a while upon initial loading.
```bash
source devel/setup.bash
roslaunch my_robot world.launch
```
8. Open another Terminal/CLI by using `Ctrl + Alt + T` shortcut.
Switch to `catkin_ws`
```bash
cd /<your_dir>/catkin_ws
```
9. Run `map_server`, `amcl` and `move_base` nodes, which can be done by executing `amcl.launch`
```bash
source devel/setup.bash
roslaunch my_robot amcl.launch
```
10. Test the performance of AMCL package.
	1. `Option 1: Send 2D Navigation Goal`
	The `move_base` will try to navigate your robot based on the localization. Based on the new observation and the odometry, the robot to further perform the localization. Click the `2D Nav Goal` button in the toolbar, then click and drag on the map to send the goal to the robot. It will start moving and localize itself in the process.
	
	2. `Option 2: Use teleop Node`
	```bash
	rosrun teleop_twist_keyboard teleop_twist_keyboard.py
	```
	You could control your robot by keyboard commands now.


### PGM Map Package Install Instructions
1. Install dependencies
```bash
sudo apt-get install libignition-math2-dev protobuf-compiler
```
2. Switch into `src` directory inside `catkin_ws`
```bash
cd <your_dir>/catkin_ws/src/
```
3. Clone the repo
```bash
git clone https://github.com/hyfan1116/pgm_map_creator
```
4. Build the package
```bash
cd ..
catkin_make
source devel/setup.bash
```

### Teleop Package Install Instructions
1. Switch into `src` directory inside `catkin_ws`
```bash
cd <your_dir>/catkin_ws/src/
```
3. Clone the repo
```bash
git clone https://github.com/ros-teleop/teleop_twist_keyboard
```
4. Build the package
```bash
cd ..
catkin_make
source devel/setup.bash
```