// MIT License

// Copyright (c) [2023] [Chevy WENG]

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cw1_class.h>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "cw1_solution_node");
  ros::NodeHandle nh;

  // MoveIt! requirement for non-blocking group.move()
  ros::AsyncSpinner spinner(1);
  spinner.start();

  ros::Duration(1, 0).sleep();

  // create an instance of the cw1 class
  cw1 cw_class(nh);

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub_cloud =
      nh.subscribe("/r200/camera/depth_registered/points",
                   1,
                   &cw1::pcCallBack,
                   &cw_class);
  // loop rate in Hz
  ros::Rate rate(100);

  while (ros::ok())
  {

    // spin and process all pending callbacks
    ros::spinOnce();

    // sleep to fulfill the loop rate
    rate.sleep();
  }
}
