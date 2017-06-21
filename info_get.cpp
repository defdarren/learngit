#include<math.h>
#include<std_msgs/Float64.h>
#include<ros/ros.h>
#include<moveit_msgs/DisplayTrajectory.h>
#include<sensor_msgs/JointState.h>

using namespace std_msgs;
using namespace std;
using namespace ros;
using namespace moveit_msgs;
using namespace sensor_msgs;

vector<double> turn_angle;
bool flag = false;

void theCallback(const JointState& msg)
{
	turn_angle.resize(msg.position.size());
	for(int i = 0; i < msg.position.size(); i++)
	{
		ROS_INFO_STREAM("receive moveit position: " << msg.position[i]);
		turn_angle[i] = msg.position[i];
		
	}
	flag = true;
//	ROS_INFO_STREAM("The turn_angle size(in Callback function):" << turn_angle.size());
}

int main(int argc,char** argv)
{
	init(argc,argv,"get_message_info");
	NodeHandle nh;
	Subscriber sub = nh.subscribe("move_group/fake_controller_joint_states",100,&theCallback);
	Publisher pub = nh.advertise<Float64>("servo",100);

	Float64 my_msg;

	while(ok())
	{	
		if(flag == true)
		{
//			ROS_INFO_STREAM("The turn_angle size(in main function):" << turn_angle.size());
//			for(int i = 0 ; i < turn_angle.size();i++)
//			{
				my_msg.data = (180*turn_angle[0])/3.1415926 + 90;
				pub.publish(my_msg);
				ROS_INFO_STREAM("write to servo data: " << my_msg.data);
			
//			}
			flag = false;
		}
		spinOnce();
	}
	return 0;
}



/*

// the servo test


#include<ros/ros.h>
#include<std_msgs/Float64.h>

using namespace ros;
using namespace std_msgs;

int main(int argc,char** argv)
{
	init(argc,argv,"my_servo_data_pub");
	NodeHandle nh;
	Publisher my_pub = nh.advertise<Float64>("servo",100);

	Rate loop(2);

	Float64 msg;
	msg.data = 0;
	while(1)
	{
		if(msg.data < 180)
		msg.data += 1;
		my_pub.publish(msg);
		loop.sleep();
	}

	return 0;
}
*/
