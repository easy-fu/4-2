#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat srcMat = imread("C:/Users/DELL/Desktop/3.jpg");
	if (srcMat.empty())
	{
		cout << "fail to read pic!" << endl;
		return 0;
	}
	Mat gryMat;
	cvtColor(srcMat, gryMat, COLOR_BGRA2GRAY);
	Mat stats;
	Mat centroids;
	Mat labels;
	Mat thresh_Mat;
	threshold(gryMat, thresh_Mat, 87, 255, THRESH_BINARY);
	int nComp = connectedComponentsWithStats(thresh_Mat, labels, stats, centroids, 8, CV_32S);
	cout << "Ó²±Ò¸öÊýÎª£º" << nComp - 1 << endl;
	for (int i = 1; i < nComp; i++)
	{
		Rect bandbox;
		bandbox.x = stats.at<int>(i, 0);
		bandbox.y = stats.at<int>(i, 1);
		bandbox.width = stats.at<int>(i, 2);
		bandbox.height = stats.at<int>(i, 3);
		rectangle(thresh_Mat, bandbox, 255, 1, 8, 0);

	}
	imshow("thresh_Mat", thresh_Mat);

	waitKey(0);
	return 0;

}