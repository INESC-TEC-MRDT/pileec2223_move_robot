#pragma once

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_datatypes.h>

namespace pileec2223_move_robot {

class GoToXY {
 private:
  ros::NodeHandle nh_;

  ros::Publisher pub_cmd_vel_;
  ros::Subscriber sub_goal_;
  ros::Subscriber sub_odom_;

  ros::Timer run_timer_;

 public:
  GoToXY();
  ~GoToXY() = default;

 private:
  void readParam();

  void pubCmdVel(const double v, const double vn, const double w);

  void subGoal(const geometry_msgs::PoseStamped& msg_goal);
  void subOdom(const nav_msgs::Odometry& msg_odom);

  void update();
};

} // namespace pileec2223_move_robot
