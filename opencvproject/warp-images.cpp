#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/// <summary>
/// /////////////////////// How to crop images //////////////////////////////
/// </summary>

float w = 250, h = 350;
Mat matrix, imgWarpKing, imgWarpQueen, imgWarpJack, imgWarp9;

void main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	Point2f srcKing[4] = { {529,142}, {771,190},{405,395},{674,457} };
	Point2f srcQueen[4] = { {65,323}, {333,279},{92,636},{405,567} };
	Point2f srcJack[4] = { {776,106}, {1016,81},{846,358},{1113,326} };
	Point2f src9[4] = { {741,385}, {1022,440},{645,706},{970,778} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(srcKing, dst);
	warpPerspective(img, imgWarpKing, matrix, Point(w, h));

	matrix = getPerspectiveTransform(srcQueen, dst);
	warpPerspective(img, imgWarpQueen, matrix, Point(w, h));

	matrix = getPerspectiveTransform(srcJack, dst);
	warpPerspective(img, imgWarpJack, matrix, Point(w, h));

	matrix = getPerspectiveTransform(src9, dst);
	warpPerspective(img, imgWarp9, matrix, Point(w, h));

	for (int i = 0; i < 4; i++) {

		circle(img, srcKing[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, srcQueen[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, srcJack[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, src9[i], 10, Scalar(0, 0, 255), FILLED);
	}
	imshow("Image", img);
	imshow("Image Warp King", imgWarpKing);
	imshow("Image Warp Queen", imgWarpQueen);
	imshow("Image Warp Jack", imgWarpJack);
	imshow("Image Warp 9", imgWarp9);
	waitKey(0);

}