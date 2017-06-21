#include<ros/ros.h>
#include<camera_info_manager/camera_info_manager.h>
#include<sensor_msgs/CameraInfo.h>

using namespace sensor_msgs;
using namespace ros;
using namespace camera_info_manager;

int main(int argc,char** argv)
{
	init(argc,argv,"my_camera_info_publish");
	NodeHandle nh;

	CameraInfoManager my_camera_info_manager(nh);

	Publisher my_pubber = nh.advertise<CameraInfo>("camera/camera_info",10);
	CameraInfo msg = my_camera_info_manager.getCameraInfo();
	msg.header.frame_id = "head_camera";
	Rate loop(5);
	while(ok())
	{
		msg.header.stamp = Time::now();
		my_pubber.publish(msg);
		loop.sleep();
	}
	return 0;
}
