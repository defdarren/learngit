#include<opencv/cv.h>
#include<opencv/highgui.h>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
	Mat src,binary_img;
	src = imread(argv[1],1);
	cvtColor(src,binary_img,CV_BGR2GRAY);
	threshold(binary_img,binary_img,70,255,CV_THRESH_BINARY);

	string window_name = "origin_img";
	imshow(window_name,src);

	window_name = "binary_img";
	imshow(window_name,binary_img);

	waitKey(0);

	return 0;
}
