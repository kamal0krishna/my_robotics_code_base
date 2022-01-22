#ifndef _ROS_robocon2021_PotPositions_h
#define _ROS_robocon2021_PotPositions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace robocon2021
{

  class PotPositions : public ros::Msg
  {
    public:
      uint32_t centers_length;
      typedef geometry_msgs::Point _centers_type;
      _centers_type st_centers;
      _centers_type * centers;
      uint32_t deltas_length;
      typedef geometry_msgs::Point _deltas_type;
      _deltas_type st_deltas;
      _deltas_type * deltas;
      uint32_t distances_length;
      typedef float _distances_type;
      _distances_type st_distances;
      _distances_type * distances;

    PotPositions():
      centers_length(0), st_centers(), centers(nullptr),
      deltas_length(0), st_deltas(), deltas(nullptr),
      distances_length(0), st_distances(), distances(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->centers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->centers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->centers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->centers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->centers_length);
      for( uint32_t i = 0; i < centers_length; i++){
      offset += this->centers[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->deltas_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->deltas_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->deltas_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->deltas_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deltas_length);
      for( uint32_t i = 0; i < deltas_length; i++){
      offset += this->deltas[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->distances_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->distances_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->distances_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->distances_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distances_length);
      for( uint32_t i = 0; i < distances_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->distances[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t centers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      centers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      centers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      centers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->centers_length);
      if(centers_lengthT > centers_length)
        this->centers = (geometry_msgs::Point*)realloc(this->centers, centers_lengthT * sizeof(geometry_msgs::Point));
      centers_length = centers_lengthT;
      for( uint32_t i = 0; i < centers_length; i++){
      offset += this->st_centers.deserialize(inbuffer + offset);
        memcpy( &(this->centers[i]), &(this->st_centers), sizeof(geometry_msgs::Point));
      }
      uint32_t deltas_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      deltas_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      deltas_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      deltas_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->deltas_length);
      if(deltas_lengthT > deltas_length)
        this->deltas = (geometry_msgs::Point*)realloc(this->deltas, deltas_lengthT * sizeof(geometry_msgs::Point));
      deltas_length = deltas_lengthT;
      for( uint32_t i = 0; i < deltas_length; i++){
      offset += this->st_deltas.deserialize(inbuffer + offset);
        memcpy( &(this->deltas[i]), &(this->st_deltas), sizeof(geometry_msgs::Point));
      }
      uint32_t distances_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->distances_length);
      if(distances_lengthT > distances_length)
        this->distances = (float*)realloc(this->distances, distances_lengthT * sizeof(float));
      distances_length = distances_lengthT;
      for( uint32_t i = 0; i < distances_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_distances));
        memcpy( &(this->distances[i]), &(this->st_distances), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "robocon2021/PotPositions"; };
    virtual const char * getMD5() override { return "7e74a1f53d4b7a23e6b6a6ac04a328d3"; };

  };

}
#endif
