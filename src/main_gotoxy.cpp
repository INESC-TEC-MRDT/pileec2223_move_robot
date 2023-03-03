#include <ros/ros.h>

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "pileec2223_move_robot");

  ros::spin();

  return 0;
}
