#ifndef _ROS_robocon2021_Imu_h
#define _ROS_robocon2021_Imu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace robocon2021
{

  class Imu : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Vector3 _accel_data_type;
      _accel_data_type accel_data;
      typedef geometry_msgs::Vector3 _mag_data_type;
      _mag_data_type mag_data;

    Imu():
      header(),
      accel_data(),
      mag_data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->accel_data.serialize(outbuffer + offset);
      offset += this->mag_data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->accel_data.deserialize(inbuffer + offset);
      offset += this->mag_data.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "robocon2021/Imu"; };
    virtual const char * getMD5() override { return "d49753342071a62fa283b6e28b6030f7"; };

  };

}
#endif
