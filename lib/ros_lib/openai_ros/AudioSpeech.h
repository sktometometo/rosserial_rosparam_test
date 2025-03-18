#ifndef _ROS_SERVICE_AudioSpeech_h
#define _ROS_SERVICE_AudioSpeech_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openai_ros
{

static const char AUDIOSPEECH[] = "openai_ros/AudioSpeech";

  class AudioSpeechRequest : public ros::Msg
  {
    public:
      typedef const char* _model_type;
      _model_type model;
      typedef const char* _voice_type;
      _voice_type voice;
      typedef const char* _input_type;
      _input_type input;
      typedef const char* _response_format_type;
      _response_format_type response_format;

    AudioSpeechRequest():
      model(""),
      voice(""),
      input(""),
      response_format("")
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
      uint32_t length_voice = strlen(this->voice);
      varToArr(outbuffer + offset, length_voice);
      offset += 4;
      memcpy(outbuffer + offset, this->voice, length_voice);
      offset += length_voice;
      uint32_t length_input = strlen(this->input);
      varToArr(outbuffer + offset, length_input);
      offset += 4;
      memcpy(outbuffer + offset, this->input, length_input);
      offset += length_input;
      uint32_t length_response_format = strlen(this->response_format);
      varToArr(outbuffer + offset, length_response_format);
      offset += 4;
      memcpy(outbuffer + offset, this->response_format, length_response_format);
      offset += length_response_format;
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
      uint32_t length_voice;
      arrToVar(length_voice, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_voice; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_voice-1]=0;
      this->voice = (char *)(inbuffer + offset-1);
      offset += length_voice;
      uint32_t length_input;
      arrToVar(length_input, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_input; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_input-1]=0;
      this->input = (char *)(inbuffer + offset-1);
      offset += length_input;
      uint32_t length_response_format;
      arrToVar(length_response_format, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_response_format; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_response_format-1]=0;
      this->response_format = (char *)(inbuffer + offset-1);
      offset += length_response_format;
     return offset;
    }

    virtual const char * getType() override { return AUDIOSPEECH; };
    virtual const char * getMD5() override { return "16a6f742e029b5e2ad5ce0911a20cc0e"; };

  };

  class AudioSpeechResponse : public ros::Msg
  {
    public:
      uint32_t content_length;
      typedef uint8_t _content_type;
      _content_type st_content;
      _content_type * content;

    AudioSpeechResponse():
      content_length(0), st_content(), content(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->content_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->content_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->content_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->content_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->content_length);
      for( uint32_t i = 0; i < content_length; i++){
      *(outbuffer + offset + 0) = (this->content[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->content[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t content_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      content_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      content_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      content_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->content_length);
      if(content_lengthT > content_length)
        this->content = (uint8_t*)realloc(this->content, content_lengthT * sizeof(uint8_t));
      content_length = content_lengthT;
      for( uint32_t i = 0; i < content_length; i++){
      this->st_content =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_content);
        memcpy( &(this->content[i]), &(this->st_content), sizeof(uint8_t));
      }
     return offset;
    }

    virtual const char * getType() override { return AUDIOSPEECH; };
    virtual const char * getMD5() override { return "72abf3d8306e84a4caf970654ef2815d"; };

  };

  class AudioSpeech {
    public:
    typedef AudioSpeechRequest Request;
    typedef AudioSpeechResponse Response;
  };

}
#endif
