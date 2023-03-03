# pileec2223_move_robot

This ROS package contains all the developments made in the course _Projeto_
_Integrador 2022/23_ of the Master of Science in Electrical and Computers
Engineering (ECE) at the Faculty of Engineering, University of Porto (FEUP).
The student responsible for this package is José Miguel Rodrigues Guedes
(up202005324@edu.fe.up.pt).

The project is a controller for the odometric pose of the robot. The main goal
is to implement at least a GoToXY controller.

## ROS

**Current version:**

- [Ubuntu 20.04.5 LTS](https://releases.ubuntu.com/focal/)
- [ROS Noetic](https://wiki.ros.org/noetic)

### Dependencies

- [roscpp](https://wiki.ros.org/roscpp)
- [geometry_msgs](https://wiki.ros.org/geometry_msgs)
- [nav_msgs](https://wiki.ros.org/nav_msgs)
- [tf](https://wiki.ros.org/tf)

### Parameters

- TBC
- \<name\> (`<type> = <default value>`): \<description\> (\<units\>)

### Subscribes

**GoToXY**

- move_goal
  ([PoseStamped.msg](http://docs.ros.org/en/noetic/api/geometry_msgs/html/msg/PoseStamped.html))
- odom
  ([Odometry.msg](https://docs.ros.org/en/noetic/api/nav_msgs/html/msg/Odometry.html))

### Publishes

- cmd_vel
  ([Twist.msg](https://docs.ros.org/en/noetic/api/geometry_msgs/html/msg/Twist.html))

### Services

None.

### Actions

None.

## Usage

### Build

```sh
# Create catkin workspace
mkdir -p ~/catkin_ws/src

# Clone repository
cd ~/catkin_ws/src
git@github.com:INESC-TEC-MRDT/pileec2223_move_robot.git

# Build
cd ..
catkin build
```

### Launch

**gotoxy**

```sh
roslaunch pileec2223_move_robot gotoxy.launch
```

## Contacts

If you have any questions or you want to know more about this work, please
contact one of the contributors of this package:

- Héber Miguel Sobreira ([gitlab](https://gitlab.inesctec.pt/heber.m.sobreira),
  [inesctec](mailto:heber.m.sobreira@inesctec.pt))
- José Miguel Guedes ([github](https://github.com/MKira99),
  [feup](mailto:up202005324@edu.fe.up.pt))
- Ricardo B. Sousa ([github](https://github.com/sousarbarb/),
  [gitlab](https://gitlab.com/sousarbarb/),
  [personal](mailto:sousa.ricardob@outlook.com),
  [feup:professor](mailto:rbs@fe.up.pt),
  [feup:student](mailto:up201503004@edu.fe.up.pt),
  [inesctec](mailto:ricardo.b.sousa@inesctec.pt))
