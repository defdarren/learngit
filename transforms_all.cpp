#include<ros/ros.h>
#include<sensor_msgs/JointState.h>
#include<tf/transform_broadcaster.h>

using namespace ros;
using namespace tf;
using namespace sensor_msgs;

int main(int argc,char** argv)
{
	init(argc,argv,"all_transforms");
	NodeHandle nh;
/*
	JointState msg;
	Publisher pub_joint_state = nh.advertise<JointState>("joint_states",10);

	int count = 0;
	
	msg.header.frame_id = "base_link";
	
	msg.position.resize(3);
	msg.name.resize(3);
	msg.header.stamp = Time::now();
	msg.position[0] = 0;
	msg.name[0] = "joint_link1";
	msg.position[1] = 0;
	msg.name[1] = "joint_link2";
	msg.position[2] = 0;
	msg.name[2] = "joint_link3";
*/
	
	static TransformBroadcaster br;
	
	Transform trans1;
	Transform trans2;
	Transform trans3;
	Transform trans_fix;
	Quaternion q_fix;
	Quaternion q1;
	Quaternion q2;
	Quaternion q3;
	Rate loop(10);
	double degree =0 ;

	while(ok())
	{

		
/*		msg.header.stamp = Time::now();
		msg.position[1] += 0.01;
		pub_joint_state.publish(msg);
*/

		trans1.setOrigin(Vector3(0,0,0.04));
		//q1.setRPY(0,0,-1.9568);		
		q1.setRPY(0,0,0);		
		trans1.setRotation(q1);
		br.sendTransform(StampedTransform(trans1,Time::now(),"base_link","link1"));
		
		//trans2.setOrigin(Vector3(0,0,0.12749));
		//q2.setRPY(3.1415,0.6852-degree,0);

		trans2.setOrigin(Vector3(0,0.06521,0.1275));
		q2.setRPY(0,-1.57,1.57+degree);

		trans2.setRotation(q2);
		br.sendTransform(StampedTransform(trans2,Time::now(),"link1","link2"));
		
		/*trans_fix.setOrigin(Vector3(0,0.06521,0.1275));
		q_fix.setRPY(0,-1.57,1.57);

		trans_fix.setRotation(q_fix);
		br.sendTransform(StampedTransform(trans_fix,Time::now(),"link1","link1_fix"));

		trans2.setOrigin(Vector3(0,0,0));
		q2.setRPY(0,0,degree);

		trans2.setRotation(q2);
		br.sendTransform(StampedTransform(trans2,Time::now(),"link1_fix","link2"));*/

		
		//trans3.setOrigin(Vector3(0,0,-0.255));
		//q3.setRPY(0, 1.5604,-3.1415);
		trans3.setOrigin(Vector3(0.255,0,0));
		q3.setRPY(0,0,0);
		trans3.setRotation(q3);
		br.sendTransform(StampedTransform(trans3,Time::now(),"link2","link3"));
	
		degree += 0.05;

		loop.sleep();
	}

	return 0;
}
