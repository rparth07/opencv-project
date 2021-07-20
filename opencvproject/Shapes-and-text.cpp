#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/// <summary>
/// /////////////////////// Resize Shapes and Text //////////////////////////////
/// </summary>

void main() {
	//Blank Image 
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	//circle(img, Point(256, 256), 200, Scalar(255, 80, 46), 1);
	circle(img, Point(256, 256), 200, Scalar(255, 80, 46), FILLED);
	rectangle(img, Point(105, 150), Point(400, 250), Scalar(255, 255, 255), FILLED);
	circle(img, Point(155, 200), 40, Scalar(255, 80, 46), FILLED);
	circle(img, Point(345, 200), 40, Scalar(255, 80, 46), FILLED);
	//line(img, Point(110, 300), Point(390, 300), Scalar(255, 127, 0), 2);
	ellipse(img, Point(250, 350), Point(80, 20), 5, 0, 360, Scalar(255, 255, 255), -1);
	//putText(img, "Parth", Point(150, 295), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);

	imshow("Image", img);

	waitKey(0);
}