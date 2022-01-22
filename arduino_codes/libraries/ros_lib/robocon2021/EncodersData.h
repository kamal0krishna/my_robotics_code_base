#ifndef _ROS_robocon2021_EncodersData_h
#define _ROS_robocon2021_EncodersData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robocon2021
{

  class EncodersData : public ros::Msg
  {
    public:
      typedef int32_t _motor1_type;
      _motor1_type motor1;
      typedef int32_t _motor2_type;
      _motor2_type motor2;
      typedef int32_t _motor3_type;
      _motor3_type motor3;

    EncodersData():
      motor1(0),
      motor2(0),
      motor3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_motor1;
      u_motor1.real = this->motor1;
      *(outbuffer + offset + 0) = (u_motor1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor1);
      union {
        int32_t real;
        uint32_t base;
      } u_motor2;
      u_motor2.real = this->motor2;
      *(outbuffer + offset + 0) = (u_motor2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor2);
      union {
        int32_t real;
        uint32_t base;
      } u_motor3;
      u_motor3.real = this->motor3;
      *(outbuffer + offset + 0) = (u_motor3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_motor1;
      u_motor1.base = 0;
      u_motor1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor1 = u_motor1.real;
      offset += sizeof(this->motor1);
      union {
        int32_t real;
        uint32_t base;
      } u_motor2;
      u_motor2.base = 0;
      u_motor2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor2 = u_motor2.real;
      offset += sizeof(this->motor2);
      union {
        int32_t real;
        uint32_t base;
      } u_motor3;
      u_motor3.base = 0;
      u_motor3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor3 = u_motor3.real;
      offset += sizeof(this->motor3);
     return offset;
    }

    virtual const char * getType() override { return "robocon2021/EncodersData"; };
    virtual const char * getMD5() override { return "e262da34baefaecc21c36dd4a0adabae"; };

  };

}
#endif
