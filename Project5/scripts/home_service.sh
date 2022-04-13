#!/bin/sh

# launch turtlebot.launch to deploy the turtlebot in the gazebo environment
xterm -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../world/minimap.world" &
sleep 5

# launch amcl_demo.launch to localize the turtlebot
xterm -e  " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/../map/map.yaml \
             initial_pose_x:="0.0" initial_pose_y:="0.0" initial_pose_a:="4.71239" " &
sleep 5

# launch view_navigation.launch to observe the map in rviz
xterm -e  " roslaunch add_markers view_navigation.launch " &
sleep 10

# launch pick_objects node
xterm -e " rosrun pick_objects pick_objects " &

# launch add_markers node
xterm -e " rosrun add_markers add_markers "