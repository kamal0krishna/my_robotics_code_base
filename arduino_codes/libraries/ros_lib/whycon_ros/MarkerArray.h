#ifndef _ROS_whycon_ros_MarkerArray_h
#define _ROS_whycon_ros_MarkerArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "whycon_ros/Marker.h"

namespace whycon_ros
{

  class MarkerArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t markers_length;
      typedef whycon_ros::Marker _markers_type;
      _markers_type st_markers;
      _markers_type * markers;

    MarkerArray():
      header(),
      markers_length(0), st_markers(), markers(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->markers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->markers_length);
      for( uint32_t i = 0; i < markers_length; i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t markers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->markers_length);
      if(markers_lengthT > markers_length)
        this->markers = (whycon_ros::Marker*)realloc(this->markers, markers_lengthT * sizeof(whycon_ros::Marker));
      markers_length = markers_lengthT;
      for( uint32_t i = 0; i < markers_length; i++){
      offset += this->st_markers.deserialize(inbuffer + offset);
        memcpy( &(this->markers[i]), &(this->st_markers), sizeof(whycon_ros::Marker));
      }
     return offset;
    }

    virtual const char * getType() override { return "whycon_ros/MarkerArray"; };
    virtual const char * getMD5() override { return "20d8631f7610a8406066409783850746"; };

  };

}
#endif
