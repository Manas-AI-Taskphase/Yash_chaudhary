#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

int main(int argc, char **argv) {
    ros::init(argc, argv, "chat_pub");
    ros::NodeHandle nh;

    ros::Publisher chat_pub = nh.advertise<std_msgs::String>("chat_messages", 1000);
    ros::Rate loop_rate(1); // 1 Hz, adjust as needed

    while (ros::ok()) {
        std_msgs::String msg;
        std::cout << "Type a message to send: ";
        std::getline(std::cin, msg.data);

        chat_pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
