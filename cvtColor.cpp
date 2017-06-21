#include<opencv/cv.h>
#include<opencv/highgui.h>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
	Mat src,src_gray;
	src = imread(argv[1],1);
	cvtColor(src,src_gray,CV_BGR2GRAY);
	string window_name = "origin";
	imshow(window_name,src);
	window_name = "gray_img";
	imshow(window_name,src_gray);
	waitKey(0);
	return 0;
}
