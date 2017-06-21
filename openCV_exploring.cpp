//腐蚀和膨胀对比

#include<opencv/cv.h>
#include<opencv/highgui.h>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
//	cout << "No problem sir,this program could work." << endl;
	Mat src = imread(argv[1],1);

	string my_window1 = "原图像窗口";	
	string my_window2 = "处理后膨胀图像";	
	string my_window3 = "处理后腐蚀图像";	
	
	//namedWindow("原图像窗口");
	//namedWindow("处理后图像");
	namedWindow(my_window1);	
	namedWindow(my_window2);	
	namedWindow(my_window3);	
	imshow(my_window1,src);

	Mat element = getStructuringElement(MORPH_RECT,Size(45,45));

	Mat dilate_out;
	dilate(src,dilate_out,element);
	imshow(my_window2,dilate_out);
	
	Mat erode_out;
	erode(src,erode_out,element);
	imshow(my_window3,erode_out);

	waitKey(0);	
	return 0;
}
