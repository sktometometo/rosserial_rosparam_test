#ifndef _ROS_jsk_spot_sdp_localization_demo_StairArray_h
#define _ROS_jsk_spot_sdp_localization_demo_StairArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_spot_sdp_localization_demo/Stair.h"

namespace jsk_spot_sdp_localization_demo
{

  class StairArray : public ros::Msg
  {
    public:
      uint32_t stairs_length;
      typedef jsk_spot_sdp_localization_demo::Stair _stairs_type;
      _stairs_type st_stairs;
      _stairs_type * stairs;

    StairArray():
      stairs_length(0), st_stairs(), stairs(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stairs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stairs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stairs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stairs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stairs_length);
      for( uint32_t i = 0; i < stairs_length; i++){
      offset += this->stairs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t stairs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stairs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stairs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stairs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stairs_length);
      if(stairs_lengthT > stairs_length)
        this->stairs = (jsk_spot_sdp_localization_demo::Stair*)realloc(this->stairs, stairs_lengthT * sizeof(jsk_spot_sdp_localization_demo::Stair));
      stairs_length = stairs_lengthT;
      for( uint32_t i = 0; i < stairs_length; i++){
      offset += this->st_stairs.deserialize(inbuffer + offset);
        memcpy( &(this->stairs[i]), &(this->st_stairs), sizeof(jsk_spot_sdp_localization_demo::Stair));
      }
     return offset;
    }

    virtual const char * getType() override { return "jsk_spot_sdp_localization_demo/StairArray"; };
    virtual const char * getMD5() override { return "ea8287ad7e0aee91fcf3c147a32b22f1"; };

  };

}
#endif
