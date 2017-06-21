#include<opencv/cv.h>
#include<opencv/highgui.h>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
	Mat src,src_gray;

	src = imread(argv[1],1);
	
	string window_name = "origin image";
	imshow(window_name,src);
	cvtColor(src,src_gray,CV_BGR2GRAY);

	GaussianBlur(src_gray,src_gray,Size(5,5),2,2);

	vector<Vec3f> circles;
	HoughCircles(src_gray,circles,CV_HOUGH_GRADIENT,1,src_gray.rows/20,100,43,0,0);

	for(size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]),cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);

		circle(src,center,3,Scalar(0,255,0),-1,8,0);
		circle(src,center,radius,Scalar(0,0,255),3,8,0);
	}

	 window_name = "Hough Circle Transform Demo";
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	imshow(window_name,src);	
	
	waitKey(0);

	return 0;
}
