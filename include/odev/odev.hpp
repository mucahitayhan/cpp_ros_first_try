#pragma once

#include <ros/ros.h>
#include "std_msgs/Float64.h"
#include <thread>
#include <iostream>
#include <ctime>
#define __APP_NAME__ "AESK_ASSIGNMENT"

namespace AESK_ASSIGNMENT
{
    class Odev
    {
    private:
        ros::NodeHandle &m_node_handle;
        void publish_data();
        ros::Publisher m_pub;
        std_msgs::Float64 m_msg;
        std_msgs::Float64 *m_p_msg;
        std::vector<double> m_vec_double;
        std::vector<int> m_vec_int;
        std::vector<double> random_double_vector_generator();
        std::vector<int> vector_double_to_int(std::vector<double> t_vector_float);

        template <typename T>
        T print_and_return_vector(std::vector<T> t_vector);

    public:
        /*!
         * Constructor.
         * @param nodeHandle the ROS node handle.
         */
        Odev(ros::NodeHandle &t_node_handle);
        ~Odev();
    };
}