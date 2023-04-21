#include"wind.h"

void Wind::Pretreatment(Mat &img)
{
	//灰度化
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	//高斯滤波
	Mat blur;
	GaussianBlur(gray, blur, Size(3, 3), 0);

	//二值化
	Mat binary;
	threshold(blur, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
	//开运算
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(binary, binary, MORPH_CLOSE, kernel);
	//闭运算
	morphologyEx(binary, binary, MORPH_OPEN, kernel);
	img= binary;
}
void Wind::AreaContour(Mat& img)
{
	//轮廓检测
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(img, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE, Point(0, 0));
	//轮廓筛选
	vector<vector<Point>> coutours_p();
	vector<double>area;
	for (int i = 0; i < contours.size(); i++)
	{
		area.push_back(contourArea(contours[i]));
		if (area[i] > 1000)
		{
			//填充轮廓
			drawContours(img, contours, i, Scalar(0), FILLED, 8, hierarchy);
		}

		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		//闭运算
		morphologyEx(img, img, MORPH_CLOSE, kernel);
		cout<< contourArea(contours[i]) << endl;

	}
	
}