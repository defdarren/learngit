#include<sensor_msgs/Image.h>
#include<camera_info_manager/camera_info_manager.h>
#include<sensor_msgs/CameraInfo.h>
#include<std_msgs/Header.h>
#include<ros/ros.h>
#include<image_transport/image_transport.h>
#include<opencv2/highgui/highgui.hpp>
#include<cv_bridge/cv_bridge.h>
#include<sstream>

using namespace camera_info_manager;
using namespace cv;
using namespace ros;
using namespace std;
using namespace image_transport;
using namespace sensor_msgs;
using namespace std_msgs;
using namespace cv_bridge;

int main(int argc,char** argv)
{
	if(argv[1] == NULL) return 1;

	init(argc,argv,"the_cv_bridge");

	NodeHandle nh;

	ImageTransport it(nh);	

	image_transport::Publisher pub = it.advertise("/camera/image_raw",1);

	istringstream video_sourceCmd(argv[1]);	
	
	int video_source;

	if(! (video_sourceCmd >> video_source)) return 1;
	
	VideoCapture cap(video_source);
	
	if(!cap.isOpened()) return 1;

	Mat frame ;

	ImagePtr image_msg;


	CameraInfoManager my_camera_info_manager(nh);

	ros::Publisher my_pubber = nh.advertise<CameraInfo>("camera/camera_info",10);

	CameraInfo info_msg = my_camera_info_manager.getCameraInfo();

	info_msg.header.frame_id = "head_camera";
	
	Time now_time;
	
	Rate loop_rate(30);
	
	while(ok())
	{
		cap >> frame;
		if(!frame.empty())
		{
			image_msg =CvImage(std_msgs::Header(),"bgr8",frame).toImageMsg();

			now_time = Time::now();

			image_msg->header.stamp = now_time;
			info_msg.header.stamp = now_time;

			pub.publish(image_msg);
			my_pubber.publish(info_msg);
			
			waitKey(1);
		}
		spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
