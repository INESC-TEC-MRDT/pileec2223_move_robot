#include "pileec2223_move_robot/GoToXY.h"

namespace pileec2223_move_robot {

GoToXY::GoToXY() {
  readParam();

  pub_cmd_vel_ = nh_.advertise<geometry_msgs::Twist>("cmd_vel", 1);
  sub_goal_ = nh_.subscribe("move_goal", 1, &GoToXY::subGoal, this);
  sub_odom_ = nh_.subscribe("odom", 1, &GoToXY::subOdom, this);
}

void GoToXY::readParam() {
  ros::NodeHandle nh_private("~");

  std::string example_param_1;
  double example_param_2;

  // Read parameter without a default value (defined by us in the code)
  if (nh_private.hasParam("example_param_1")) {
    nh_private.getParam("example_param_1", example_param_1);
    ROS_INFO("[gotoxy] Ok. Example param 1 is set: %s",
             example_param_1.c_str());
  } else {
    ROS_INFO("[gotoxy] Ok. Example param 1 not set");
  }

  // Read parameter. If not set, leave by its default value
  nh_private.param<double>("example_param_2", example_param_2, 0.05);
  ROS_INFO("[gotoxy] Example param 2: %f", example_param_2);
}

void GoToXY::pubCmdVel(const double v, const double vn, const double w) {
  geometry_msgs::Twist msg_cmd_vel;

  msg_cmd_vel.linear.x = v;
  msg_cmd_vel.linear.y = vn;
  msg_cmd_vel.linear.z = 0;

  msg_cmd_vel.angular.x = 0;
  msg_cmd_vel.angular.y = 0;
  msg_cmd_vel.angular.z = w;

  pub_cmd_vel_.publish(msg_cmd_vel);
}

void GoToXY::subGoal(const geometry_msgs::PoseStamped& msg_goal) {
  // Process goal message (remove example debug message)
  ROS_INFO("[gotoxy] Goal: %f m %f m (%f deg)",
           msg_goal.pose.position.x, msg_goal.pose.position.y,
           tf::getYaw(msg_goal.pose.orientation) * 180.0 / M_PI);

  // Update the internal state of the class with the new goal
}

void GoToXY::subOdom(const nav_msgs::Odometry& msg_odom) {
  // Process odom message (remove example debug message)
  ROS_INFO("[gotoxy] Odom: %f m %f m (%f deg)",
           msg_odom.pose.pose.position.x, msg_odom.pose.pose.position.y,
           tf::getYaw(msg_odom.pose.pose.orientation) * 180.0 / M_PI);

  // Update state machine
  update();

  // Publish new velocity
  pubCmdVel(0.0, 0.0, 0.0);
}

void GoToXY::update() {
  // Possibly, put your state machine here!!
  // Goal: compute new v, vn, w (e.g., declared them as members of the class)
}

} // namespace pileec2223_move_robot
