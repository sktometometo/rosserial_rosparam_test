#ifndef _ROS_spot_msgs_ManipulatorState_h
#define _ROS_spot_msgs_ManipulatorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Twist.h"

namespace spot_msgs
{

  class ManipulatorState : public ros::Msg
  {
    public:
      typedef float _gripper_open_percentage_type;
      _gripper_open_percentage_type gripper_open_percentage;
      typedef bool _is_gripper_holding_item_type;
      _is_gripper_holding_item_type is_gripper_holding_item;
      typedef geometry_msgs::Vector3 _estimated_end_effector_force_in_hand_type;
      _estimated_end_effector_force_in_hand_type estimated_end_effector_force_in_hand;
      typedef uint8_t _stow_state_type;
      _stow_state_type stow_state;
      typedef geometry_msgs::Twist _velocity_of_hand_in_vision_type;
      _velocity_of_hand_in_vision_type velocity_of_hand_in_vision;
      typedef geometry_msgs::Twist _velocity_of_hand_in_odom_type;
      _velocity_of_hand_in_odom_type velocity_of_hand_in_odom;
      typedef uint8_t _carry_state_type;
      _carry_state_type carry_state;
      enum { STOWSTATE_UNKNOWN = 0 };
      enum { STOWSTATE_STOWED = 1 };
      enum { STOWSTATE_DEPLOYED = 2 };
      enum { CARRY_STATE_UNKNOWN = 0 };
      enum { CARRY_STATE_NOT_CARRIABLE = 1 };
      enum { CARRY_STATE_CARRIABLE = 2 };
      enum { CARRY_STATE_CARRIABLE_AND_STOWABLE = 3 };

    ManipulatorState():
      gripper_open_percentage(0),
      is_gripper_holding_item(0),
      estimated_end_effector_force_in_hand(),
      stow_state(0),
      velocity_of_hand_in_vision(),
      velocity_of_hand_in_odom(),
      carry_state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->gripper_open_percentage);
      union {
        bool real;
        uint8_t base;
      } u_is_gripper_holding_item;
      u_is_gripper_holding_item.real = this->is_gripper_holding_item;
      *(outbuffer + offset + 0) = (u_is_gripper_holding_item.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_gripper_holding_item);
      offset += this->estimated_end_effector_force_in_hand.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->stow_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stow_state);
      offset += this->velocity_of_hand_in_vision.serialize(outbuffer + offset);
      offset += this->velocity_of_hand_in_odom.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->carry_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->carry_state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gripper_open_percentage));
      union {
        bool real;
        uint8_t base;
      } u_is_gripper_holding_item;
      u_is_gripper_holding_item.base = 0;
      u_is_gripper_holding_item.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_gripper_holding_item = u_is_gripper_holding_item.real;
      offset += sizeof(this->is_gripper_holding_item);
      offset += this->estimated_end_effector_force_in_hand.deserialize(inbuffer + offset);
      this->stow_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->stow_state);
      offset += this->velocity_of_hand_in_vision.deserialize(inbuffer + offset);
      offset += this->velocity_of_hand_in_odom.deserialize(inbuffer + offset);
      this->carry_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->carry_state);
     return offset;
    }

    virtual const char * getType() override { return "spot_msgs/ManipulatorState"; };
    virtual const char * getMD5() override { return "2a7bffc976ab4c387a06137f80924918"; };

  };

}
#endif
