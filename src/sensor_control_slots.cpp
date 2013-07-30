/*
 * Brad Fletcher
 * brad@udel.edu
 * Thanks to Georgia Tech for allowing me to use their 
 * RViz panel code as a model for this.
 */


#include "sensor_control.h"

//added
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "rviz_sensor_control_panel/HokuyoCommand.h"
#include "rviz_sensor_control_panel/FleaCommand.h"

namespace ud_measurement_space
{

void MeasurementControlTab::refreshState()
{
	
} 

void MeasurementControlTab::hokuyoEditHandle()
{
    std::cerr << "Hokuyo Scan: start at: " << txtMinTheta->text().toStdString() << std::endl;
    
    //added ros stuff
 
    ros::Rate loop_rate(10);
    loop_rate.sleep();

    std::cerr << "hello!\n";

    printf("hokuyo edit\n"); fflush(stdout);

    
    rviz_sensor_control_panel::HokuyoCommand msg;
    msg.minTheta = txtMinTheta->text().toFloat();
    //msg.maxTheta = txtMaxTheta->text().toFloat();
    //msg.degreesPerSecond = txtDPS->text().toFloat();
    hokuyo_pub.publish(msg);
    

    //ROS_INFO("%s", msg.data.c_str());
    ros::spinOnce();

    //    loop_rate.sleep();
}

} // End: namespace ud_measurement_space
