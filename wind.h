#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;
class Wind
{
public:
	//Ԥ����
	void Pretreatment(Mat &img);
	//�������
	void AreaContour(Mat &img);
	
};