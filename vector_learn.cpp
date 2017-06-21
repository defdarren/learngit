#include<iostream>
#include<vector>

using namespace std;

int main(int argc,char** argv)
{
	vector<int>  iVec(10,0);
	vector<int>::iterator t,end_a;
	for(t = iVec.begin(),end_a = (iVec.end() - 1); t != iVec.end(); t++)
	{
		if(t != end_a)
		cout << *t << " ";
		else 
		cout << *t << "." << endl;
	}
	
	iVec[3] = 10;
	iVec[6] = 15;
	iVec[9] = 13;
	
	for(t = iVec.begin(),end_a = (iVec.end() - 1); t != iVec.end(); t++)
	{
		if(t != end_a)
		cout << *t << " ";
		else 
		cout << *t << "." << endl;
	}
	return 0;
}
