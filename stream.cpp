#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

void seperate();

int main(int argc,char** argv)
{
/*

	//demo ofstream

	ofstream myfile;
	myfile.open("do/doit/file.txt",ios::out|ios::trunc);
	if(myfile.fail())
	{
		cout << "fail to open the file!" << endl;
		return 1;
	}
	myfile << "人生如梦" << endl << "网址" << "www.cppblog.com/andxie99" << endl;
	myfile.close();
*/

/*

	//demo ifstream

	ifstream myfile;
	myfile.open("do/doit/file.txt",ios::in);
	if(!myfile)
	{
		cout << "fail to read the file";
		return 1;
	}
	char ch;
	string content;
	while(myfile.get(ch))
	{
		content += ch;
		cout.put(ch);
	}
	seperate();
	myfile.close();
	cout << content;
*/
/*
	fstream myfile;
	myfile.open("my_file",ios::out|ios::app);
	if(!myfile)
	{
		cout << "fail to open the file" << endl;
	}
	myfile << "I want to add this kind of thing in it" << endl;
	myfile.close();

	myfile.open("my_file",ios::in);
	if(!myfile)
	{
		cout << "fail to open the file" << endl;
	}
	char ch;
	while(myfile.get(ch))
	{
		cout.put(ch);
	}
	myfile.close();
*/

/*	char name[] = "www.baidu.com/index";	
	int arraySize = strlen(name) + 1;
	istrstream is(name,arraySize);
	char temp;
	is >> temp;
	cout << temp;
*/

/*
	stringstream ostr("ccc");
	ostr.put('a');
	ostr.put('e');
	ostr << "fg" ;
	string gstr = ostr.str();
	cout << gstr << endl;

	char a;
	ostr >> a;
	cout << a << endl;
*/


/*
	stringstream sstr;	
	int a = 100;
	string str;
	sstr << a;
	sstr >> str;
	cout << str << endl;
	sstr.clear();

	string name= "starbark"; 
	char cname[200];
	sstr << name;
	sstr >> cname;
	cout << cname << endl;
*/

/*	
	int a;
	cin >> a;
	cout << cin.rdstate() << endl;
//	if(cin.rdstate() == ios::goodbit)
	if(cin.good())
	{	
		cout << "you did a good job!!!" << endl;
	}
	if(cin.fail())
	{
		cout << "I'm sorry fail to input." << endl;
	}
*/

/*
	int a;
	cin >> a;
	cout << cin.rdstate() << endl;
	cin.clear(ios::goodbit);
	cout << cin.rdstate() << endl;
*/

/*
	int a;
	while(1)
	{
		cin >> a;
		if(!cin)
		{
			cout << "fail to input,please try again" << endl;
			cin.clear();
			cin.get();
		}
		else
		{
			cout << a << endl;
			break;
		}
	}
*/
/*
	ifstream file_input("my_file",ios_base::in);

	if(file_input.fail())
	{
		cout << "fail to open the file" << endl;
	}
	else
	{
		char ch;
		while(file_input.get(ch))
		{
			cout << ch;
		}
		if(file_input.eof())
		{
			cout << "all content had been read" << endl;
		}
		seperate();
		while(file_input.get(ch))
		{
			cout << ch;
		}
	}
	
*/
	return 0;
}

void seperate()
{
	cout <<"---------------------------------------------" <<endl;
}

