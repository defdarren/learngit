#include<ros/ros.h>
#include<iostream>
#include<sstream>
#include<string>
#include<opencv/cv.h>
#include<opencv/highgui.h>
//#include<opencv2/imgproc/imgproc.hpp>
//#include<opencv2/highgui/highgui.hpp>
#include<cmath>

using namespace cv;
using namespace std;


// findContours Demo

int thresh = 100;
int max_thresh = 255;

RNG rng(12345);

Mat src;
Mat src_gray;

void thresh_callback(int,void*)
{
	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	Canny(src_gray,canny_output,thresh,thresh*2,3);

	findContours(canny_output,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));

	Mat drawing = Mat::zeros(canny_output.size(),CV_8UC3);
	for(int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		drawContours(drawing,contours,i,color,2,8,hierarchy,0,Point());
	}
	
	namedWindow("Contours",CV_WINDOW_AUTOSIZE);
	imshow("Contours",drawing);
}

int main(int argc,char** argv)
{
/*
	double fscale = 0.15;
	Size outSize;
	Mat ResizeImage;
	Mat image = imread(argv[1],1);
	
	outSize.width = image.cols*fscale;
	outSize.height = image.rows*fscale;
	resize(image,src,outSize,0,0,INTER_AREA);
*/
	Mat src;
	src = imread(argv[1],1);

	cvtColor(src,src_gray,CV_BGR2GRAY);
	blur(src_gray,src_gray,Size(3,3));

	const char* source_window = "Source";
	namedWindow(source_window,CV_WINDOW_AUTOSIZE);
	imshow(source_window,src);

	createTrackbar("Canny_thresh","Source",&thresh,max_thresh,thresh_callback);
	thresh_callback(0,0);
	
	waitKey(0);
	return 0;
}

