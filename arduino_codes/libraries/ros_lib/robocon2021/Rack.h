#ifndef _ROS_robocon2021_Rack_h
#define _ROS_robocon2021_Rack_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robocon2021
{

  class Rack : public ros::Msg
  {
    public:
      typedef bool _lock_type;
      _lock_type lock;
      typedef bool _grip_type;
      _grip_type grip;
      typedef int32_t _upDown_type;
      _upDown_type upDown;

    Rack():
      lock(0),
      grip(0),
      upDown(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_lock;
      u_lock.real = this->lock;
      *(outbuffer + offset + 0) = (u_lock.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lock);
      union {
        bool real;
        uint8_t base;
      } u_grip;
      u_grip.real = this->grip;
      *(outbuffer + offset + 0) = (u_grip.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grip);
      union {
        int32_t real;
        uint32_t base;
      } u_upDown;
      u_upDown.real = this->upDown;
      *(outbuffer + offset + 0) = (u_upDown.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_upDown.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_upDown.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_upDown.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->upDown);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_lock;
      u_lock.base = 0;
      u_lock.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->lock = u_lock.real;
      offset += sizeof(this->lock);
      union {
        bool real;
        uint8_t base;
      } u_grip;
      u_grip.base = 0;
      u_grip.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->grip = u_grip.real;
      offset += sizeof(this->grip);
      union {
        int32_t real;
        uint32_t base;
      } u_upDown;
      u_upDown.base = 0;
      u_upDown.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_upDown.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_upDown.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_upDown.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->upDown = u_upDown.real;
      offset += sizeof(this->upDown);
     return offset;
    }

    virtual const char * getType() override { return "robocon2021/Rack"; };
    virtual const char * getMD5() override { return "0fc59df9fc6038e0368a9bb3989f6186"; };

  };

}
#endif
