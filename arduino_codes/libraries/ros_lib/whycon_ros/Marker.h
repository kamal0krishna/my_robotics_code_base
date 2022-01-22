#ifndef _ROS_whycon_ros_Marker_h
#define _ROS_whycon_ros_Marker_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Vector3.h"

namespace whycon_ros
{

  class Marker : public ros::Msg
  {
    public:
      typedef float _u_type;
      _u_type u;
      typedef float _v_type;
      _v_type v;
      typedef int32_t _size_type;
      _size_type size;
      typedef int8_t _id_type;
      _id_type id;
      typedef geometry_msgs::Pose _position_type;
      _position_type position;
      typedef geometry_msgs::Vector3 _rotation_type;
      _rotation_type rotation;

    Marker():
      u(0),
      v(0),
      size(0),
      id(0),
      position(),
      rotation()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_u;
      u_u.real = this->u;
      *(outbuffer + offset + 0) = (u_u.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u);
      union {
        float real;
        uint32_t base;
      } u_v;
      u_v.real = this->v;
      *(outbuffer + offset + 0) = (u_v.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v);
      union {
        int32_t real;
        uint32_t base;
      } u_size;
      u_size.real = this->size;
      *(outbuffer + offset + 0) = (u_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size);
      union {
        int8_t real;
        uint8_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->rotation.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_u;
      u_u.base = 0;
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u = u_u.real;
      offset += sizeof(this->u);
      union {
        float real;
        uint32_t base;
      } u_v;
      u_v.base = 0;
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v = u_v.real;
      offset += sizeof(this->v);
      union {
        int32_t real;
        uint32_t base;
      } u_size;
      u_size.base = 0;
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->size = u_size.real;
      offset += sizeof(this->size);
      union {
        int8_t real;
        uint8_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id = u_id.real;
      offset += sizeof(this->id);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->rotation.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "whycon_ros/Marker"; };
    virtual const char * getMD5() override { return "41e9fb6b03db610dfc04a2523c57e338"; };

  };

}
#endif
