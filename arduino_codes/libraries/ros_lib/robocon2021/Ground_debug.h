#ifndef _ROS_robocon2021_Ground_debug_h
#define _ROS_robocon2021_Ground_debug_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robocon2021
{

  class Ground_debug : public ros::Msg
  {
    public:
      typedef int32_t _pitch_type;
      _pitch_type pitch;
      typedef int32_t _yaw_type;
      _yaw_type yaw;
      typedef int32_t _arm_type;
      _arm_type arm;

    Ground_debug():
      pitch(0),
      yaw(0),
      arm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        int32_t real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        int32_t real;
        uint32_t base;
      } u_arm;
      u_arm.real = this->arm;
      *(outbuffer + offset + 0) = (u_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        int32_t real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        int32_t real;
        uint32_t base;
      } u_arm;
      u_arm.base = 0;
      u_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->arm = u_arm.real;
      offset += sizeof(this->arm);
     return offset;
    }

    virtual const char * getType() override { return "robocon2021/Ground_debug"; };
    virtual const char * getMD5() override { return "c2b23882141d4cbfb5b43f8875a8fe5c"; };

  };

}
#endif
