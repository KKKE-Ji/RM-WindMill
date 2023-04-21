#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;
class Wind
{
public:
	//Ô¤´¦Àí
	void Pretreatment(Mat &img);
	//ÂÖÀª¼ì²â
	void AreaContour(Mat &img);
	
};