#ifndef _ROS_SERVICE_ChatCompletions_h
#define _ROS_SERVICE_ChatCompletions_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openai_ros
{

static const char CHATCOMPLETIONS[] = "openai_ros/ChatCompletions";

  class ChatCompletionsRequest : public ros::Msg
  {
    public:
      typedef const char* _model_type;
      _model_type model;
      typedef const char* _messages_type;
      _messages_type messages;
      typedef int32_t _max_tokens_type;
      _max_tokens_type max_tokens;
      typedef float _frequency_penalty_type;
      _frequency_penalty_type frequency_penalty;
      typedef float _temperature_type;
      _temperature_type temperature;

    ChatCompletionsRequest():
      model(""),
      messages(""),
      max_tokens(0),
      frequency_penalty(0),
      temperature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_model = strlen(this->model);
      varToArr(outbuffer + offset, length_model);
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
      uint32_t length_messages = strlen(this->messages);
      varToArr(outbuffer + offset, length_messages);
      offset += 4;
      memcpy(outbuffer + offset, this->messages, length_messages);
      offset += length_messages;
      union {
        int32_t real;
        uint32_t base;
      } u_max_tokens;
      u_max_tokens.real = this->max_tokens;
      *(outbuffer + offset + 0) = (u_max_tokens.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_tokens.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_tokens.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_tokens.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_tokens);
      union {
        float real;
        uint32_t base;
      } u_frequency_penalty;
      u_frequency_penalty.real = this->frequency_penalty;
      *(outbuffer + offset + 0) = (u_frequency_penalty.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frequency_penalty.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frequency_penalty.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frequency_penalty.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequency_penalty);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_model;
      arrToVar(length_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model-1]=0;
      this->model = (char *)(inbuffer + offset-1);
      offset += length_model;
      uint32_t length_messages;
      arrToVar(length_messages, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_messages; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_messages-1]=0;
      this->messages = (char *)(inbuffer + offset-1);
      offset += length_messages;
      union {
        int32_t real;
        uint32_t base;
      } u_max_tokens;
      u_max_tokens.base = 0;
      u_max_tokens.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_tokens.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_tokens.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_tokens.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_tokens = u_max_tokens.real;
      offset += sizeof(this->max_tokens);
      union {
        float real;
        uint32_t base;
      } u_frequency_penalty;
      u_frequency_penalty.base = 0;
      u_frequency_penalty.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frequency_penalty.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frequency_penalty.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frequency_penalty.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->frequency_penalty = u_frequency_penalty.real;
      offset += sizeof(this->frequency_penalty);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
     return offset;
    }

    virtual const char * getType() override { return CHATCOMPLETIONS; };
    virtual const char * getMD5() override { return "8f7615b9b653496f52b42ea427eb3a3b"; };

  };

  class ChatCompletionsResponse : public ros::Msg
  {
    public:
      typedef const char* _finish_reason_type;
      _finish_reason_type finish_reason;
      typedef const char* _content_type;
      _content_type content;
      typedef const char* _model_type;
      _model_type model;
      typedef int32_t _completion_tokens_type;
      _completion_tokens_type completion_tokens;
      typedef int32_t _prompt_tokens_type;
      _prompt_tokens_type prompt_tokens;
      typedef int32_t _total_tokens_type;
      _total_tokens_type total_tokens;

    ChatCompletionsResponse():
      finish_reason(""),
      content(""),
      model(""),
      completion_tokens(0),
      prompt_tokens(0),
      total_tokens(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_finish_reason = strlen(this->finish_reason);
      varToArr(outbuffer + offset, length_finish_reason);
      offset += 4;
      memcpy(outbuffer + offset, this->finish_reason, length_finish_reason);
      offset += length_finish_reason;
      uint32_t length_content = strlen(this->content);
      varToArr(outbuffer + offset, length_content);
      offset += 4;
      memcpy(outbuffer + offset, this->content, length_content);
      offset += length_content;
      uint32_t length_model = strlen(this->model);
      varToArr(outbuffer + offset, length_model);
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
      union {
        int32_t real;
        uint32_t base;
      } u_completion_tokens;
      u_completion_tokens.real = this->completion_tokens;
      *(outbuffer + offset + 0) = (u_completion_tokens.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_completion_tokens.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_completion_tokens.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_completion_tokens.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->completion_tokens);
      union {
        int32_t real;
        uint32_t base;
      } u_prompt_tokens;
      u_prompt_tokens.real = this->prompt_tokens;
      *(outbuffer + offset + 0) = (u_prompt_tokens.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_prompt_tokens.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_prompt_tokens.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_prompt_tokens.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->prompt_tokens);
      union {
        int32_t real;
        uint32_t base;
      } u_total_tokens;
      u_total_tokens.real = this->total_tokens;
      *(outbuffer + offset + 0) = (u_total_tokens.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_tokens.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_tokens.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_tokens.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_tokens);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_finish_reason;
      arrToVar(length_finish_reason, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_finish_reason; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_finish_reason-1]=0;
      this->finish_reason = (char *)(inbuffer + offset-1);
      offset += length_finish_reason;
      uint32_t length_content;
      arrToVar(length_content, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_content; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_content-1]=0;
      this->content = (char *)(inbuffer + offset-1);
      offset += length_content;
      uint32_t length_model;
      arrToVar(length_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model-1]=0;
      this->model = (char *)(inbuffer + offset-1);
      offset += length_model;
      union {
        int32_t real;
        uint32_t base;
      } u_completion_tokens;
      u_completion_tokens.base = 0;
      u_completion_tokens.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_completion_tokens.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_completion_tokens.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_completion_tokens.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->completion_tokens = u_completion_tokens.real;
      offset += sizeof(this->completion_tokens);
      union {
        int32_t real;
        uint32_t base;
      } u_prompt_tokens;
      u_prompt_tokens.base = 0;
      u_prompt_tokens.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_prompt_tokens.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_prompt_tokens.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_prompt_tokens.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->prompt_tokens = u_prompt_tokens.real;
      offset += sizeof(this->prompt_tokens);
      union {
        int32_t real;
        uint32_t base;
      } u_total_tokens;
      u_total_tokens.base = 0;
      u_total_tokens.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_tokens.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_tokens.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_tokens.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total_tokens = u_total_tokens.real;
      offset += sizeof(this->total_tokens);
     return offset;
    }

    virtual const char * getType() override { return CHATCOMPLETIONS; };
    virtual const char * getMD5() override { return "14308a0c0ef7c0703edd712e21286ac0"; };

  };

  class ChatCompletions {
    public:
    typedef ChatCompletionsRequest Request;
    typedef ChatCompletionsResponse Response;
  };

}
#endif
