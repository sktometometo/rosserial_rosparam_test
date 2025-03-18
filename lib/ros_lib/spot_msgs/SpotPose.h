#ifndef _ROS_SERVICE_SpotPose_h
#define _ROS_SERVICE_SpotPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spot_msgs
{

static const char SPOTPOSE[] = "spot_msgs/SpotPose";

  class SpotPoseRequest : public ros::Msg
  {
    public:
      typedef uint8_t _pose_type_type;
      _pose_type_type pose_type;
      typedef float _euler_z_type;
      _euler_z_type euler_z;
      typedef float _euler_x_type;
      _euler_x_type euler_x;
      typedef float _euler_y_type;
      _euler_y_type euler_y;
      typedef float _height_type;
      _height_type height;
      typedef float _pose_hold_time_type;
      _pose_hold_time_type pose_hold_time;
      enum { STAND = 1       };
      enum { SIT = 2         };
      enum { LOOK_UP = 3     };
      enum { LOOK_DOWN = 4   };
      enum { HEAD_TILT = 5   };
      enum { CUSTOM = 6      };
      enum { POSE_HOLD_TIME_DEFAULT = -1.0  };
      enum { POSE_HOLD_TIME_INF = -2.0      };

    SpotPoseRequest():
      pose_type(0),
      euler_z(0),
      euler_x(0),
      euler_y(0),
      height(0),
      pose_hold_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pose_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pose_type);
      offset += serializeAvrFloat64(outbuffer + offset, this->euler_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->euler_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->euler_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      offset += serializeAvrFloat64(outbuffer + offset, this->pose_hold_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->pose_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pose_type);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->euler_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->euler_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->euler_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pose_hold_time));
     return offset;
    }

    virtual const char * getType() override { return SPOTPOSE; };
    virtual const char * getMD5() override { return "50005af2463fc75eea87fb3e6b53e28b"; };

  };

  class SpotPoseResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    SpotPoseResponse():
      success(0),
      message("")
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
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
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
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return SPOTPOSE; };
    virtual const char * getMD5() override { return "937c9679a518e3a18d831e57125ea522"; };

  };

  class SpotPose {
    public:
    typedef SpotPoseRequest Request;
    typedef SpotPoseResponse Response;
  };

}
#endif
