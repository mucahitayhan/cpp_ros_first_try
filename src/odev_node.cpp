#include "../include/odev/odev.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "cpp_ros_first_try");
    ros::NodeHandle node_handle("~"); 

    AESK_ASSIGNMENT::Odev odev(node_handle);
    ros::spin();
    return 0;
}
