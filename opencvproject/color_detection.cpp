#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
  
using namespace cv;
using namespace std;

/// <summary>
/// /////////////////////// Color Detection //////////////////////////////
/// </summary>

Mat imgHSV,Mask;
int hmin = 0, smin = 110, vmin = 0;
int hmax = 179, smax = 255, vmax =  255;

void main() {
	 
	string path = "Resources/lambo.png";
	Mat img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (700, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 179);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 179);
	createTrackbar("Val Max", "Trackbars", &hmax, 255);

	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, Mask);

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", Mask);

		waitKey(1);
	}
}