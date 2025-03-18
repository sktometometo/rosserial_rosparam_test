#ifndef _ROS_SERVICE_Embedding_h
#define _ROS_SERVICE_Embedding_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openai_ros
{

static const char EMBEDDING[] = "openai_ros/Embedding";

  class EmbeddingRequest : public ros::Msg
  {
    public:
      typedef const char* _input_type;
      _input_type input;
      typedef const char* _model_type;
      _model_type model;

    EmbeddingRequest():
      input(""),
      model("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_input = strlen(this->input);
      varToArr(outbuffer + offset, length_input);
      offset += 4;
      memcpy(outbuffer + offset, this->input, length_input);
      offset += length_input;
      uint32_t length_model = strlen(this->model);
      varToArr(outbuffer + offset, length_model);
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_input;
      arrToVar(length_input, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_input; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_input-1]=0;
      this->input = (char *)(inbuffer + offset-1);
      offset += length_input;
      uint32_t length_model;
      arrToVar(length_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model-1]=0;
      this->model = (char *)(inbuffer + offset-1);
      offset += length_model;
     return offset;
    }

    virtual const char * getType() override { return EMBEDDING; };
    virtual const char * getMD5() override { return "b5da1c64590d4fa106c9f63ebfed436b"; };

  };

  class EmbeddingResponse : public ros::Msg
  {
    public:
      uint32_t embedding_length;
      typedef float _embedding_type;
      _embedding_type st_embedding;
      _embedding_type * embedding;
      typedef const char* _model_type;
      _model_type model;
      typedef int32_t _prompt_tokens_type;
      _prompt_tokens_type prompt_tokens;
      typedef int32_t _total_tokens_type;
      _total_tokens_type total_tokens;

    EmbeddingResponse():
      embedding_length(0), st_embedding(), embedding(nullptr),
      model(""),
      prompt_tokens(0),
      total_tokens(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->embedding_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->embedding_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->embedding_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->embedding_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->embedding_length);
      for( uint32_t i = 0; i < embedding_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->embedding[i]);
      }
      uint32_t length_model = strlen(this->model);
      varToArr(outbuffer + offset, length_model);
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
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
      uint32_t embedding_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      embedding_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      embedding_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      embedding_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->embedding_length);
      if(embedding_lengthT > embedding_length)
        this->embedding = (float*)realloc(this->embedding, embedding_lengthT * sizeof(float));
      embedding_length = embedding_lengthT;
      for( uint32_t i = 0; i < embedding_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_embedding));
        memcpy( &(this->embedding[i]), &(this->st_embedding), sizeof(float));
      }
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

    virtual const char * getType() override { return EMBEDDING; };
    virtual const char * getMD5() override { return "5e3a9cb8861b51920694df8b4c75f652"; };

  };

  class Embedding {
    public:
    typedef EmbeddingRequest Request;
    typedef EmbeddingResponse Response;
  };

}
#endif
