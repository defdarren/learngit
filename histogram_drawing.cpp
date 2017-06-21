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
	
	vector<Mat> rgb_planes;
	split(src,rgb_planes);

	int histSize = 255;
	
	float range[] = {0,255};
	const float* histRange = {range};

	bool uniform = true;
	bool accumulate = false;

	Mat r_hist,g_hist,b_hist;
	
	calcHist(&rgb_planes[0],1,0,Mat(),r_hist,1,&histSize,&histRange,uniform,accumulate);
	calcHist(&rgb_planes[1],1,0,Mat(),g_hist,1,&histSize,&histRange,uniform,accumulate);
	calcHist(&rgb_planes[2],1,0,Mat(),b_hist,1,&histSize,&histRange,uniform,accumulate);

	int hist_w = 400;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w/histSize);

	Mat histImage(hist_w,hist_h,CV_8UC3,Scalar(0,0,0));

	normalize(r_hist,r_hist,0,histImage.rows,NORM_MINMAX,-1,Mat());
	normalize(g_hist,g_hist,0,histImage.rows,NORM_MINMAX,-1,Mat());
	normalize(b_hist,b_hist,0,histImage.rows,NORM_MINMAX,-1,Mat());
	
	for(int i = 1; i < histSize; i++)
	{
		line(histImage,Point(bin_w*(i-1),hist_h-cvRound(r_hist.at<float>(i-1))),
			Point(bin_w*(i),hist_h-cvRound(r_hist.at<float>(i))),
			Scalar(0,0,255),2,8,0);
		
		line(histImage,Point(bin_w*(i-1),hist_h-cvRound(g_hist.at<float>(i-1))),
			Point(bin_w*(i),hist_h-cvRound(g_hist.at<float>(i))),
			Scalar(0,255,0),2,8,0);
		
		line(histImage,Point(bin_w*(i-1),hist_h-cvRound(b_hist.at<float>(i-1))),
			Point(bin_w*(i),hist_h-cvRound(b_hist.at<float>(i))),
			Scalar(255,0,0),2,8,0);
	}	

	window_name= "the histogram";
	imshow(window_name,histImage);
/*
	Mat src_gray;
	cvtColor(src,src_gray,CV_BGR2GRAY);
	window_name = "before_enhanced";
	imshow(window_name,src_gray);	

	Mat dst;
	equalizeHist(src_gray,dst);
	window_name = "enhanced_img";
	imshow(window_name,dst);
*/	
	waitKey(0);

	return 0;
}
