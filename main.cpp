#include"wind.h"

int main()
{
	/*VideoCapture capturel(0);
	if (!capturel.isOpened())
	{
		cout << "无法打开摄像头" << endl;
		return -1;
	}*/
	//导入视频流
	
	
		/*VideoCapture capturel("D:\\ROBOMarster\\wind\\wind.mp4");
		capturel >> img;
		if (img.empty())
		{
			cout << "视频流为没有输入" << endl;
			exit(-1);
		}*/
		Mat img = imread("D:\\ROBOMarster\\wind\\wind1.jpg");
		if (img.empty())
		{
			cout << "no image" << endl;
			return -1;
		}

		Wind windMill;
		//frame >> img;
		//获取视频帧
		//帧数转化为整数
		//int frameCountInt = capturel.get(5);
		//cout << frameCountInt << endl;
		//绘制帧数
		//putText(img, to_string(frameCountInt), Point(30, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2, 8);
		windMill.Pretreatment(img);

		windMill.AreaContour(img);
		imshow("视频流", img);
		waitKey(0);
	

	destroyAllWindows();
	return 0;
}