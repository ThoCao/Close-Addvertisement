#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <Windows.h>
#include <iostream>
#include "CaptureScreen.h"

using namespace std;
using namespace cv;


void matchingMethod(Mat &src,Mat &templ);

int main(int argc, char **argv)
{
	CaptureScreen captureScreen;
	namedWindow("output", WINDOW_NORMAL);
	int key = 0;

	// Load image 
	Mat templ = imread("template.png", 1);
	while (key != 27)
	{
		Mat src = captureScreen.getImageFromScreenPC();

		matchingMethod(src, templ);
		// you can do some image processing here
		imshow("output", src);
		key = waitKey(60); // you can change wait time
	}

}

void matchingMethod(Mat & src, Mat & templ){

	Mat img_process,img_gray;
	src.copyTo(img_process);
	templ.copyTo(img_gray);
	

	cvtColor(img_process, img_process, CV_BGR2GRAY);
	cvtColor(img_gray, img_gray, CV_BGR2GRAY);

	Mat result = Mat::zeros( src.rows - templ.rows + 1,src.cols - templ.cols + 1, CV_32FC1);

	cv::matchTemplate(img_process, img_gray, result, CV_TM_SQDIFF_NORMED);
	
	cv::normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
	/// Localizing the best match with minMaxLoc
	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;
	cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());


	matchLoc = minLoc;

	/// Show me what you got
	cv::rectangle(src, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), {0,255,0}, 2, 8, 0);
	
	
}
