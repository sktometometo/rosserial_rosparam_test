#ifndef _ROS_spot_msgs_BatteryState_h
#define _ROS_spot_msgs_BatteryState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace spot_msgs
{

  class BatteryState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _identifier_type;
      _identifier_type identifier;
      typedef float _charge_percentage_type;
      _charge_percentage_type charge_percentage;
      typedef ros::Duration _estimated_runtime_type;
      _estimated_runtime_type estimated_runtime;
      typedef float _current_type;
      _current_type current;
      typedef float _voltage_type;
      _voltage_type voltage;
      uint32_t temperatures_length;
      typedef float _temperatures_type;
      _temperatures_type st_temperatures;
      _temperatures_type * temperatures;
      typedef uint8_t _status_type;
      _status_type status;
      enum { STATUS_UNKNOWN =  0 };
      enum { STATUS_MISSING =  1 };
      enum { STATUS_CHARGING =  2 };
      enum { STATUS_DISCHARGING =  3 };
      enum { STATUS_BOOTING =  4 };

    BatteryState():
      header(),
      identifier(""),
      charge_percentage(0),
      estimated_runtime(),
      current(0),
      voltage(0),
      temperatures_length(0), st_temperatures(), temperatures(nullptr),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_identifier = strlen(this->identifier);
      varToArr(outbuffer + offset, length_identifier);
      offset += 4;
      memcpy(outbuffer + offset, this->identifier, length_identifier);
      offset += length_identifier;
      offset += serializeAvrFloat64(outbuffer + offset, this->charge_percentage);
      *(outbuffer + offset + 0) = (this->estimated_runtime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->estimated_runtime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->estimated_runtime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->estimated_runtime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->estimated_runtime.sec);
      *(outbuffer + offset + 0) = (this->estimated_runtime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->estimated_runtime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->estimated_runtime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->estimated_runtime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->estimated_runtime.nsec);
      offset += serializeAvrFloat64(outbuffer + offset, this->current);
      offset += serializeAvrFloat64(outbuffer + offset, this->voltage);
      *(outbuffer + offset + 0) = (this->temperatures_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->temperatures_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->temperatures_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->temperatures_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperatures_length);
      for( uint32_t i = 0; i < temperatures_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->temperatures[i]);
      }
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_identifier;
      arrToVar(length_identifier, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_identifier; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_identifier-1]=0;
      this->identifier = (char *)(inbuffer + offset-1);
      offset += length_identifier;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->charge_percentage));
      this->estimated_runtime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->estimated_runtime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->estimated_runtime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->estimated_runtime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->estimated_runtime.sec);
      this->estimated_runtime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->estimated_runtime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->estimated_runtime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->estimated_runtime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->estimated_runtime.nsec);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->current));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->voltage));
      uint32_t temperatures_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      temperatures_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      temperatures_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      temperatures_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->temperatures_length);
      if(temperatures_lengthT > temperatures_length)
        this->temperatures = (float*)realloc(this->temperatures, temperatures_lengthT * sizeof(float));
      temperatures_length = temperatures_lengthT;
      for( uint32_t i = 0; i < temperatures_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_temperatures));
        memcpy( &(this->temperatures[i]), &(this->st_temperatures), sizeof(float));
      }
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/BatteryState"; };
    virtual const char * getMD5() override { return "d4f77065e2805bf6a288541cb5a848ce"; };

  };

}
#endif
