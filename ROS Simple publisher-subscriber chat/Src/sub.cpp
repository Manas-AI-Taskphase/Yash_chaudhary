#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

void chatCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Received message: %s", msg->data.c_str());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "sub_cpp");
    ros::NodeHandle nh;

    ros::Subscriber chat_sub = nh.subscribe("chat_messages", 1000, chatCallback);

    ros::spin();

    return 0;
}
