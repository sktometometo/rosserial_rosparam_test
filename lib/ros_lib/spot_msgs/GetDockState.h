#ifndef _ROS_SERVICE_GetDockState_h
#define _ROS_SERVICE_GetDockState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "spot_msgs/DockState.h"

namespace spot_msgs
{

static const char GETDOCKSTATE[] = "spot_msgs/GetDockState";

  class GetDockStateRequest : public ros::Msg
  {
    public:

    GetDockStateRequest()
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

    virtual const char * getType() override { return GETDOCKSTATE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetDockStateResponse : public ros::Msg
  {
    public:
      typedef spot_msgs::DockState _dock_state_type;
      _dock_state_type dock_state;

    GetDockStateResponse():
      dock_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->dock_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->dock_state.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETDOCKSTATE; };
    virtual const char * getMD5() override { return "01a4a21c7545e2e6d9b2173fc84d1af7"; };

  };

  class GetDockState {
    public:
    typedef GetDockStateRequest Request;
    typedef GetDockStateResponse Response;
  };

}
#endif
