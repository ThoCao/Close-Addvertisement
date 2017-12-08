#pragma once

#include <opencv2\opencv.hpp>
#include <Windows.h>
#include <iostream>

class CaptureScreen
{
public:
	CaptureScreen();
	~CaptureScreen();

	cv::Mat getImageFromScreenPC(void);
private:

	HWND hwndDesktop;

};

