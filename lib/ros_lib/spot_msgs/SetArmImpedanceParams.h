#ifndef _ROS_SERVICE_SetArmImpedanceParams_h
#define _ROS_SERVICE_SetArmImpedanceParams_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace spot_msgs
{

static const char SETARMIMPEDANCEPARAMS[] = "spot_msgs/SetArmImpedanceParams";

  class SetArmImpedanceParamsRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _linear_stiffness_type;
      _linear_stiffness_type linear_stiffness;
      typedef geometry_msgs::Vector3 _rotational_stiffness_type;
      _rotational_stiffness_type rotational_stiffness;
      typedef geometry_msgs::Vector3 _linear_damping_type;
      _linear_damping_type linear_damping;
      typedef geometry_msgs::Vector3 _rotational_damping_type;
      _rotational_damping_type rotational_damping;

    SetArmImpedanceParamsRequest():
      linear_stiffness(),
      rotational_stiffness(),
      linear_damping(),
      rotational_damping()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->linear_stiffness.serialize(outbuffer + offset);
      offset += this->rotational_stiffness.serialize(outbuffer + offset);
      offset += this->linear_damping.serialize(outbuffer + offset);
      offset += this->rotational_damping.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->linear_stiffness.deserialize(inbuffer + offset);
      offset += this->rotational_stiffness.deserialize(inbuffer + offset);
      offset += this->linear_damping.deserialize(inbuffer + offset);
      offset += this->rotational_damping.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETARMIMPEDANCEPARAMS; };
    virtual const char * getMD5() override { return "44644b8011fb42f74139f0b27de258b8"; };

  };

  class SetArmImpedanceParamsResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetArmImpedanceParamsResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return SETARMIMPEDANCEPARAMS; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetArmImpedanceParams {
    public:
    typedef SetArmImpedanceParamsRequest Request;
    typedef SetArmImpedanceParamsResponse Response;
  };

}
#endif
