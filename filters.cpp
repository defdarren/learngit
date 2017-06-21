#include<opencv/cv.h>
#include<opencv/highgui.h>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
	Mat src,dst;
	
	src = imread(argv[1],1);
	string org_window = "The origin img";
	namedWindow(org_window,CV_WINDOW_AUTOSIZE);
	imshow(org_window,src);

	GaussianBlur(src,dst,Size(5,5),0);
	string window_name1 = "GaussianBlur Demo";
	imshow(window_name1,dst);

	medianBlur(src,dst,3);	
	window_name1 = "MedianBlur Demo";
	imshow(window_name1,dst);

	blur(src,dst,Size(3,3),Point(-1,-1));
	window_name1 = "Mean Blur";
	imshow(window_name1,dst);

	waitKey(0);
	return 0;
}

