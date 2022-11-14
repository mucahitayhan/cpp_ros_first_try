#include "../include/odev/odev.hpp"

namespace AESK_ASSIGNMENT
{
    Odev::Odev(ros::NodeHandle &t_node_handle)
        : m_node_handle{t_node_handle},
          m_p_msg{nullptr}
    {
        ROS_INFO(" [%s]  Constructor Odev is called.", __APP_NAME__);

        m_p_msg = new std_msgs::Float64();
        m_msg = std_msgs::Float64();
        m_pub = m_node_handle.advertise<std_msgs::Float64>("bias", 1000);

        while (ros::ok())
        {
            ROS_INFO(" [%s]  Constructor Odev is called.", __APP_NAME__);
            Odev::publish_data();
        }
    }

    Odev::~Odev()
    {
        ROS_INFO(" [%s]  Destructor Odev is called.", __APP_NAME__);
        delete m_p_msg;
    }

    void Odev::publish_data()
    {
        ROS_INFO(" [%s]  Publish Callback is called.", __APP_NAME__);

        m_vec_double = random_double_vector_generator();
        print_and_return_vector(m_vec_double);

        m_vec_int = vector_double_to_int(m_vec_double);
        auto pub_data = print_and_return_vector(m_vec_int);

        // m_msg.data = pub_data;
        // m_pub.publish(m_msg);
        // std::cout << "m_msg: " << m_msg << std::endl;

        m_p_msg->data = pub_data;
        m_pub.publish(*m_p_msg);
        std::cout << "m_p_msg: " << *m_p_msg << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::vector<double> Odev::random_double_vector_generator()
    {
        std::vector<double> random_vector(10, 0);
        for (int i = 0; i < random_vector.size(); i++)
        {
            random_vector[i] = ((double)rand() / RAND_MAX) * 100;
        }
        return random_vector;
    }

    std::vector<int> Odev::vector_double_to_int(std::vector<double> vector_double)
    {
        std::vector<int> vector_int;
        for (int i = 0; i < vector_double.size(); i++)
        {
            vector_int.push_back(vector_double[i]);
        }
        return vector_int;
    }

    template <typename T>
    T Odev::print_and_return_vector(std::vector<T> t_vector)
    {
        for (int i = 0; i < t_vector.size(); i++)
        {
            std::cout << t_vector[i] << std::endl;
        }
        auto min = std::min_element(t_vector.begin(), t_vector.end());
        std::cout << "Min element is " << *min << std::endl;

        auto max = std::max_element(t_vector.begin(), t_vector.end());
        std::cout << "Max element is " << *max << std::endl;

        auto max_min_divided_by_2 = (*max + *min) / 2;

        std::cout << "(Min + Max)/2 = " << max_min_divided_by_2 << std::endl;
        return max_min_divided_by_2;
    }
} // namespace AESK_ASSIGNMENT
