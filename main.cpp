#include"wind.h"

int main()
{
	/*VideoCapture capturel(0);
	if (!capturel.isOpened())
	{
		cout << "�޷�������ͷ" << endl;
		return -1;
	}*/
	//������Ƶ��
	
	
		/*VideoCapture capturel("D:\\ROBOMarster\\wind\\wind.mp4");
		capturel >> img;
		if (img.empty())
		{
			cout << "��Ƶ��Ϊû������" << endl;
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
		//��ȡ��Ƶ֡
		//֡��ת��Ϊ����
		//int frameCountInt = capturel.get(5);
		//cout << frameCountInt << endl;
		//����֡��
		//putText(img, to_string(frameCountInt), Point(30, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2, 8);
		windMill.Pretreatment(img);

		windMill.AreaContour(img);
		imshow("��Ƶ��", img);
		waitKey(0);
	

	destroyAllWindows();
	return 0;
}