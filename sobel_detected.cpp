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

	cvtColor(src,src,CV_BGR2GRAY);
	
	Mat src_x,src_xx;
	Mat src_y,src_yy;
	
	Sobel(src,src_x,CV_16S,1,0,-1);
	Sobel(src,src_y,CV_16S,0,1,-1);
	
	convertScaleAbs(src_x,src_xx);
	convertScaleAbs(src_y,src_yy);
	
	window_name = "sobel detected xx";
	imshow(window_name,src_xx);
	
	window_name = "sobel detected yy";
	imshow(window_name,src_yy);
	
	Mat xx_yy;
	addWeighted(src_xx,0.5,src_yy,0.5,0,xx_yy);
	window_name = "sobel detected xx&yy";
	imshow(window_name,xx_yy);
	

	waitKey(0);
	
	return 0;
}
