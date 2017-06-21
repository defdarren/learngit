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
	window_name = "before_enhanced";
	imshow(window_name,src_gray);	

	Mat dst;
	equalizeHist(src_gray,dst);
	window_name = "enhanced_img";
	imshow(window_name,dst);
	
	waitKey(0);

	return 0;
}
