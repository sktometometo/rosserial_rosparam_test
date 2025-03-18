#ifndef _ROS_spot_msgs_DockState_h
#define _ROS_spot_msgs_DockState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spot_msgs
{

  class DockState : public ros::Msg
  {
    public:
      typedef uint8_t _status_type;
      _status_type status;
      typedef uint8_t _dock_type_type;
      _dock_type_type dock_type;
      typedef uint32_t _dock_id_type;
      _dock_id_type dock_id;
      typedef uint8_t _power_status_type;
      _power_status_type power_status;
      enum { DOCK_STATUS_UNKNOWN =  0 };
      enum { DOCK_STATUS_DOCKED =  1 };
      enum { DOCK_STATUS_DOCKING =  2 };
      enum { DOCK_STATUS_UNDOCKED =  3 };
      enum { DOCK_STATUS_UNDOCKING =  4 };
      enum { DOCK_TYPE_UNKNOWN =  0 };
      enum { DOCK_TYPE_CONTACT_PROTOTYPE =  2 };
      enum { DOCK_TYPE_SPOT_DOCK =  3 };
      enum { LINK_STATUS_UNKNOWN =  0 };
      enum { LINK_STATUS_CONNECTED =  1 };
      enum { LINK_STATUS_ERROR =  2 };
      enum { LINK_STATUS_DETECTING =  3 };

    DockState():
      status(0),
      dock_type(0),
      dock_id(0),
      power_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->dock_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dock_type);
      *(outbuffer + offset + 0) = (this->dock_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dock_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dock_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dock_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dock_id);
      *(outbuffer + offset + 0) = (this->power_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      this->dock_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->dock_type);
      this->dock_id =  ((uint32_t) (*(inbuffer + offset)));
      this->dock_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->dock_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->dock_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->dock_id);
      this->power_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->power_status);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/DockState"; };
    virtual const char * getMD5() override { return "a5cf6a3afaa5e6b3ccda4170a976059d"; };

  };

}
#endif
