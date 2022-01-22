#ifndef _ROS_grid2021_track_h
#define _ROS_grid2021_track_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace grid2021
{

  class track : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef geometry_msgs::Vector3 _start_type;
      _start_type start;
      typedef geometry_msgs::Vector3 _intermediate_type;
      _intermediate_type intermediate;
      typedef geometry_msgs::Vector3 _end_type;
      _end_type end;

    track():
      id(0),
      start(),
      intermediate(),
      end()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->start.serialize(outbuffer + offset);
      offset += this->intermediate.serialize(outbuffer + offset);
      offset += this->end.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->intermediate.deserialize(inbuffer + offset);
      offset += this->end.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "grid2021/track"; };
    virtual const char * getMD5() override { return "02088753002233058f262f959db0c0fa"; };

  };

}
#endif
