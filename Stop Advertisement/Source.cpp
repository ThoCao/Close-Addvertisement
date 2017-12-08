#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <Windows.h>
#include <iostream>
#include "CaptureScreen.h"

using namespace std;
using namespace cv;


int main(int argc, char **argv)
{
	HWND hwndDesktop = GetDesktopWindow();
	namedWindow("output", WINDOW_NORMAL);
	int key = 0;

	while (key != 27)
	{
		Mat src = hwnd2mat(hwndDesktop);
		// you can do some image processing here
		imshow("output", src);
		key = waitKey(60); // you can change wait time
	}

}