#include "pileec2223_move_robot/GoToXY.h"

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "gotoxy");

  pileec2223_move_robot::GoToXY gotoxy;
  ros::spin();

  return 0;
}
