#ifndef _ROS_jsk_spot_sdp_localization_demo_Stair_h
#define _ROS_jsk_spot_sdp_localization_demo_Stair_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"

namespace jsk_spot_sdp_localization_demo
{

  class Stair : public ros::Msg
  {
    public:
      typedef const char* _stair_name_type;
      _stair_name_type stair_name;
      typedef geometry_msgs::PointStamped _point_top_a_type;
      _point_top_a_type point_top_a;
      typedef geometry_msgs::PointStamped _point_top_b_type;
      _point_top_b_type point_top_b;
      typedef geometry_msgs::PointStamped _point_bottom_a_type;
      _point_bottom_a_type point_bottom_a;
      typedef geometry_msgs::PointStamped _point_bottom_b_type;
      _point_bottom_b_type point_bottom_b;

    Stair():
      stair_name(""),
      point_top_a(),
      point_top_b(),
      point_bottom_a(),
      point_bottom_b()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_stair_name = strlen(this->stair_name);
      varToArr(outbuffer + offset, length_stair_name);
      offset += 4;
      memcpy(outbuffer + offset, this->stair_name, length_stair_name);
      offset += length_stair_name;
      offset += this->point_top_a.serialize(outbuffer + offset);
      offset += this->point_top_b.serialize(outbuffer + offset);
      offset += this->point_bottom_a.serialize(outbuffer + offset);
      offset += this->point_bottom_b.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_stair_name;
      arrToVar(length_stair_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_stair_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_stair_name-1]=0;
      this->stair_name = (char *)(inbuffer + offset-1);
      offset += length_stair_name;
      offset += this->point_top_a.deserialize(inbuffer + offset);
      offset += this->point_top_b.deserialize(inbuffer + offset);
      offset += this->point_bottom_a.deserialize(inbuffer + offset);
      offset += this->point_bottom_b.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "jsk_spot_sdp_localization_demo/Stair"; };
    virtual const char * getMD5() override { return "7b4371bbfecd6918f64b49a6e6f7588d"; };

  };

}
#endif
