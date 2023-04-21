#include"wind.h"

void Wind::Pretreatment(Mat &img)
{
	//�ҶȻ�
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	//��˹�˲�
	Mat blur;
	GaussianBlur(gray, blur, Size(3, 3), 0);

	//��ֵ��
	Mat binary;
	threshold(blur, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
	//������
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(binary, binary, MORPH_CLOSE, kernel);
	//������
	morphologyEx(binary, binary, MORPH_OPEN, kernel);
	img= binary;
}
void Wind::AreaContour(Mat& img)
{
	//�������
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(img, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE, Point(0, 0));
	//����ɸѡ
	vector<vector<Point>> coutours_p();
	vector<double>area;
	for (int i = 0; i < contours.size(); i++)
	{
		area.push_back(contourArea(contours[i]));
		if (area[i] > 1000)
		{
			//�������
			drawContours(img, contours, i, Scalar(0), FILLED, 8, hierarchy);
		}

		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		//������
		morphologyEx(img, img, MORPH_CLOSE, kernel);
		cout<< contourArea(contours[i]) << endl;

	}
	
}