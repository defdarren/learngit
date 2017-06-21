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

	Canny(src,src,150,100,3);
	window_name = "canny detected";
	imshow(window_name,src);

	waitKey(0);
	
	return 0;
}
