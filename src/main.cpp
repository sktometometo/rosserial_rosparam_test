#include <Arduino.h>
#include <math.h>

#if defined(STAMPS3)
#include "ArduinoHWCDCHardware.h"
#elif defined(STAMPC3)
#include "ArduinoHardware.h"
#endif

#include "node_handle_ex.h" // #include "ros/node_handle.h"

#include <string>
#include <vector>

std::vector<std::string> string_vector;
ros::NodeHandleEx<ArduinoHardware> nh;

void setup()
{
    nh.initNode();

    while (not nh.connected())
    {
        nh.spinOnce();
        delay(1000);
    }

    nh.getParam("~fuga", string_vector);

    for (int i = 0; i < string_vector.size(); i++)
    {
        nh.loginfo("~fuga[%d]: %s", i, string_vector[i].c_str());
    }
    nh.spinOnce();

    char paramname[128];
    std::string paramvalue;
    int value;
    std::vector<int> int_vector;
    memset(paramname, 0, sizeof(paramname));
    bool success = false;
    for (int i = 0; i < string_vector.size(); i++)
    {
        snprintf(paramname, sizeof(paramname), "~%s/path1", string_vector[i].c_str());
        nh.loginfo("Loading parameters from %s", paramname);
        nh.spinOnce();
        success = nh.getParam(paramname, paramvalue);
        if (success)
        {
            nh.loginfo("%s: %s", paramname, paramvalue.c_str());
        }
        else
        {
            nh.loginfo("Failed to get param: %s", paramname);
        }
        sprintf(paramname, "~%s/path2", string_vector[i].c_str());
        nh.loginfo("Loading parameters from %s", paramname);
        nh.spinOnce();
        success = nh.getParam(paramname, paramvalue);
        if (success)
        {
            nh.loginfo("%s: %s", paramname, paramvalue.c_str());
        }
        else
        {
            nh.loginfo("Failed to get param: %s", paramname);
        }
        sprintf(paramname, "~%s/trajectory", string_vector[i].c_str());
        nh.loginfo("Loading parameters from %s", paramname);
        nh.getParam(paramname, int_vector);
        for (int j = 0; j < int_vector.size(); j++)
        {
            nh.loginfo("%s[%d]: %d", paramname, j, int_vector[j]);
        }
    }
}

void loop()
{
    nh.spinOnce();
    delay(10000);
    nh.loginfo("Hello, world!");
}
