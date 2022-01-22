#ifndef _ROS_robocon2021_Throw_h
#define _ROS_robocon2021_Throw_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robocon2021
{

  class Throw : public ros::Msg
  {
    public:
      typedef bool _trig_type;
      _trig_type trig;
      typedef bool _lock_type;
      _lock_type lock;

    Throw():
      trig(0),
      lock(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_trig;
      u_trig.real = this->trig;
      *(outbuffer + offset + 0) = (u_trig.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trig);
      union {
        bool real;
        uint8_t base;
      } u_lock;
      u_lock.real = this->lock;
      *(outbuffer + offset + 0) = (u_lock.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lock);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_trig;
      u_trig.base = 0;
      u_trig.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->trig = u_trig.real;
      offset += sizeof(this->trig);
      union {
        bool real;
        uint8_t base;
      } u_lock;
      u_lock.base = 0;
      u_lock.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->lock = u_lock.real;
      offset += sizeof(this->lock);
     return offset;
    }

    virtual const char * getType() override { return "robocon2021/Throw"; };
    virtual const char * getMD5() override { return "13b0e8f34016f2d18b8294639a8ba310"; };

  };

}
#endif
