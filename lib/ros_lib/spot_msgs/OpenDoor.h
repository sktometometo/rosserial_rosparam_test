#ifndef _ROS_SERVICE_OpenDoor_h
#define _ROS_SERVICE_OpenDoor_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spot_msgs
{

static const char OPENDOOR[] = "spot_msgs/OpenDoor";

  class OpenDoorRequest : public ros::Msg
  {
    public:

    OpenDoorRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return OPENDOOR; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenDoorResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef uint8_t _failure_reason_type;
      _failure_reason_type failure_reason;
      enum { FAILED_NO_ARM = 1 };
      enum { FAILED_NO_GRASP = 2 };
      enum { FAILED_COULD_NOT_OPEN = 3 };

    OpenDoorResponse():
      success(0),
      failure_reason(0)
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
      *(outbuffer + offset + 0) = (this->failure_reason >> (8 * 0)) & 0xFF;
      offset += sizeof(this->failure_reason);
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
      this->failure_reason =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->failure_reason);
     return offset;
    }

    virtual const char * getType() override { return OPENDOOR; };
    virtual const char * getMD5() override { return "b5d242251b98a1485b554f209a88c6e5"; };

  };

  class OpenDoor {
    public:
    typedef OpenDoorRequest Request;
    typedef OpenDoorResponse Response;
  };

}
#endif
