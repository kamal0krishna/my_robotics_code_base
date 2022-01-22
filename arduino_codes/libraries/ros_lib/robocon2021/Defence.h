#ifndef _ROS_robocon2021_Defence_h
#define _ROS_robocon2021_Defence_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robocon2021
{

  class Defence : public ros::Msg
  {
    public:
      typedef bool _dcmotor_type;
      _dcmotor_type dcmotor;
      typedef bool _gripper_type;
      _gripper_type gripper;

    Defence():
      dcmotor(0),
      gripper(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_dcmotor;
      u_dcmotor.real = this->dcmotor;
      *(outbuffer + offset + 0) = (u_dcmotor.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dcmotor);
      union {
        bool real;
        uint8_t base;
      } u_gripper;
      u_gripper.real = this->gripper;
      *(outbuffer + offset + 0) = (u_gripper.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gripper);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_dcmotor;
      u_dcmotor.base = 0;
      u_dcmotor.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->dcmotor = u_dcmotor.real;
      offset += sizeof(this->dcmotor);
      union {
        bool real;
        uint8_t base;
      } u_gripper;
      u_gripper.base = 0;
      u_gripper.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gripper = u_gripper.real;
      offset += sizeof(this->gripper);
     return offset;
    }

    virtual const char * getType() override { return "robocon2021/Defence"; };
    virtual const char * getMD5() override { return "d5cda9deea8f237f92929abc6da9e965"; };

  };

}
#endif
