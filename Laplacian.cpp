#include<opencv/cv.h>
#include<opencv/highgui.h>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
	Mat src;
	src = imread(argv[1],1);
	string window_name = "origin img";
	imshow(window_name,src);

	Mat src_gray;

	cvtColor(src,src_gray,CV_BGR2GRAY);
	
	Mat dst;
	Laplacian(src_gray,dst,CV_16S,3,1,0,BORDER_DEFAULT);	

	Mat abs_dst;
	convertScaleAbs(dst,abs_dst);
	
	window_name = "Laplacian detected";
	imshow(window_name,abs_dst);

	waitKey(0);
	
	return 0;
}
