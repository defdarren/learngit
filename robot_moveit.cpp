#include<ros/ros.h>
#include<moveit/robot_model/robot_model.h>
#include<moveit/robot_state/robot_state.h>
#include<moveit/robot_model_loader/robot_model_loader.h>

using namespace Eigen;
using namespace ros;
using namespace robot_model_loader;
using namespace robot_model;
using namespace robot_state;
using namespace std;


int main(int argc,char** argv)
{
	init(argc,argv,"get_my_robot_move");
	NodeHandle nh;
	ROS_INFO("GET START");
	RobotModelLoader robot_model_loader("robot_description");
	RobotModelPtr kinematic_model = robot_model_loader.getModel();
	RobotStatePtr kinematic_state(new RobotState(kinematic_model));
//	kinematic_state->setToDefaultValues();
	kinematic_state->setToRandomPositions();
	const JointModelGroup* joint_model_group = kinematic_model->getJointModelGroup("one");
	const vector<string>& joint_names = joint_model_group->getJointModelNames();
	vector<double> joint_values;
	kinematic_state->copyJointGroupPositions(joint_model_group,joint_values);

	for(size_t i = 0 ;i < joint_names.size() ; i++ )
	{
		ROS_INFO("Joint-> %s : %f",joint_names[i].c_str(),joint_values[i]);		
	}
	
	vector<string> link_names = kinematic_model->getLinkModelNames();

	for(size_t i = 0 ;i < link_names.size() ; i++ )
	{
		ROS_INFO("Link-> %s",link_names[i].c_str());		
	}

	const Affine3d &end_eff_state = kinematic_state->getGlobalLinkTransform("link1");
	
	ROS_INFO_STREAM("Translation: \n" << end_eff_state.translation());
	ROS_INFO_STREAM("Rotation: \n" << end_eff_state.rotation());

	bool found_ik = kinematic_state->setFromIK(joint_model_group,end_eff_state,10,1);
	if(found_ik)
	{
		kinematic_state->copyJointGroupPositions(joint_model_group,joint_values);
		for(size_t i = 0;i < joint_names.size();i++)
		{
			ROS_INFO("Joint-> %s,%f",joint_names[i].c_str(),joint_values[i]);
		}
	}
	else
	{
		ROS_FATAL("Can't not find IK solution!!!");	
	}
	ROS_INFO("Model frame %s",kinematic_model->getModelFrame().c_str());
	ROS_INFO("THE NODE HAD DIED");
	return 0;
	}
