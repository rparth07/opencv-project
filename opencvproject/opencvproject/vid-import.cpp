#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/// <summary>
/// /////////////////////// How to import videos //////////////////////////////
/// </summary>

void main() {    

	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(10);
	}
}

///// for WebCam ////// 
/*
void main() {

	VideoCapture cap(0);
	Mat img;
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(10);
	}
}

*/