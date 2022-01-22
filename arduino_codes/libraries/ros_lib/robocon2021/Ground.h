#ifndef _ROS_robocon2021_Ground_h
#define _ROS_robocon2021_Ground_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robocon2021
{

  class Ground : public ros::Msg
  {
    public:
      typedef bool _upDown_type;
      _upDown_type upDown;
      typedef bool _lockUnlock_type;
      _lockUnlock_type lockUnlock;
      typedef bool _orient_type;
      _orient_type orient;

    Ground():
      upDown(0),
      lockUnlock(0),
      orient(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_upDown;
      u_upDown.real = this->upDown;
      *(outbuffer + offset + 0) = (u_upDown.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->upDown);
      union {
        bool real;
        uint8_t base;
      } u_lockUnlock;
      u_lockUnlock.real = this->lockUnlock;
      *(outbuffer + offset + 0) = (u_lockUnlock.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lockUnlock);
      union {
        bool real;
        uint8_t base;
      } u_orient;
      u_orient.real = this->orient;
      *(outbuffer + offset + 0) = (u_orient.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->orient);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_upDown;
      u_upDown.base = 0;
      u_upDown.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->upDown = u_upDown.real;
      offset += sizeof(this->upDown);
      union {
        bool real;
        uint8_t base;
      } u_lockUnlock;
      u_lockUnlock.base = 0;
      u_lockUnlock.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->lockUnlock = u_lockUnlock.real;
      offset += sizeof(this->lockUnlock);
      union {
        bool real;
        uint8_t base;
      } u_orient;
      u_orient.base = 0;
      u_orient.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->orient = u_orient.real;
      offset += sizeof(this->orient);
     return offset;
    }

    virtual const char * getType() override { return "robocon2021/Ground"; };
    virtual const char * getMD5() override { return "2a973ff00cbaf952763e465dc7ad7d8a"; };

  };

}
#endif
