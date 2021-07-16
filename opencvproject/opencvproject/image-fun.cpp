#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/// <summary>
/// /////////////////////// img functions//////////////////////////////
/// </summary>

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize,imgCrop;

	//resize(img, imgResize, Size(1000, 500));
	resize(img, imgResize, Size(), 0.5, 0.5, 1);

	Rect roi(100, 100, 300, 250);
	imgCrop = img(roi); 

	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);
	waitKey(0);
}