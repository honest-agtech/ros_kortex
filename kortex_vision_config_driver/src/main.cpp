/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2018 Kinova inc. All rights reserved.
*
* This software may be modified and distributed under the
* terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
*/

/*
 * This file has been auto-generated and should not be modified.
 */
 
#include "node.h"

#include <sensor_msgs/JointState.h>
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "VisionConfig_Services");

    uint32_t device_id = 0;

    ros::NodeHandle n;
    bool valid_ip = false;

    if(argc > 2)
    {
        stringstream tempId;
        tempId << argv[2];
        tempId >> device_id;

        if(tempId.fail() || tempId.bad())
        {
            ROS_INFO("ERROR - Bad device ID, shutting down the node...");
            ros::shutdown();
            return 0;
        }
        ROS_INFO("Connecting to IP = %s - device ID = %s", argv[1], argv[2]);
    }
    else if(argc > 1)
    {
        ROS_INFO("Connecting to IP = %s", argv[1]);
    }
    else
    {
        ROS_INFO("You need to provide, at least, an IP adresse as the first parameter. An optional device ID can also be passed if you are using the device routing feature. ex: rosrun package node 192.168.1.10 [device_id]");
        ros::shutdown();
        return 0;
    }
    
    VisionConfig_Services services_object(argv[1], n, device_id);

    ros::ServiceServer serviceSetDeviceID = n.advertiseService("SetDeviceID", &VisionConfig_Services::SetDeviceID, &services_object);
    ros::ServiceServer serviceSetApiOptions = n.advertiseService("SetApiOptions", &VisionConfig_Services::SetApiOptions, &services_object);

    ros::ServiceServer serviceSetSensorSettings = n.advertiseService("SetSensorSettings", &VisionConfig_Services::SetSensorSettings, &services_object);
    ros::ServiceServer serviceGetSensorSettings = n.advertiseService("GetSensorSettings", &VisionConfig_Services::GetSensorSettings, &services_object);
    ros::ServiceServer serviceGetOptionValue = n.advertiseService("GetOptionValue", &VisionConfig_Services::GetOptionValue, &services_object);
    ros::ServiceServer serviceSetOptionValue = n.advertiseService("SetOptionValue", &VisionConfig_Services::SetOptionValue, &services_object);
    ros::ServiceServer serviceGetOptionInformation = n.advertiseService("GetOptionInformation", &VisionConfig_Services::GetOptionInformation, &services_object);
    ros::ServiceServer serviceOnNotificationVisionTopic = n.advertiseService("OnNotificationVisionTopic", &VisionConfig_Services::OnNotificationVisionTopic, &services_object);
    ros::ServiceServer serviceDoSensorFocusAction = n.advertiseService("DoSensorFocusAction", &VisionConfig_Services::DoSensorFocusAction, &services_object);
    ros::ServiceServer serviceGetIntrinsicParameters = n.advertiseService("GetIntrinsicParameters", &VisionConfig_Services::GetIntrinsicParameters, &services_object);
    

    ROS_INFO("Node's services initialized correctly.");

    ros::spin();
    
    return 1;
}