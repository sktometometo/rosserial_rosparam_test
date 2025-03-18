#ifndef _ROS_SERVICE_Completion_h
#define _ROS_SERVICE_Completion_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openai_ros
{

static const char COMPLETION[] = "openai_ros/Completion";

  class CompletionRequest : public ros::Msg
  {
    public:
      typedef const char* _prompt_type;
      _prompt_type prompt;
      typedef float _temperature_type;
      _temperature_type temperature;

    CompletionRequest():
      prompt(""),
      temperature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_prompt = strlen(this->prompt);
      varToArr(outbuffer + offset, length_prompt);
      offset += 4;
      memcpy(outbuffer + offset, this->prompt, length_prompt);
      offset += length_prompt;
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
      uint32_t length_prompt;
      arrToVar(length_prompt, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_prompt; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_prompt-1]=0;
      this->prompt = (char *)(inbuffer + offset-1);
      offset += length_prompt;
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

    virtual const char * getType() override { return COMPLETION; };
    virtual const char * getMD5() override { return "baed42867a51156dac4eb8ca2f7b9070"; };

  };

  class CompletionResponse : public ros::Msg
  {
    public:
      typedef const char* _finish_reason_type;
      _finish_reason_type finish_reason;
      typedef const char* _text_type;
      _text_type text;
      typedef const char* _model_type;
      _model_type model;
      typedef int32_t _completion_tokens_type;
      _completion_tokens_type completion_tokens;
      typedef int32_t _prompt_tokens_type;
      _prompt_tokens_type prompt_tokens;
      typedef int32_t _total_tokens_type;
      _total_tokens_type total_tokens;

    CompletionResponse():
      finish_reason(""),
      text(""),
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
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
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
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
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

    virtual const char * getType() override { return COMPLETION; };
    virtual const char * getMD5() override { return "fa9c0100323fbf296ec48b14bcd05846"; };

  };

  class Completion {
    public:
    typedef CompletionRequest Request;
    typedef CompletionResponse Response;
  };

}
#endif
