#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Range th(50, 128);
String title = "result"; //������ �̸�
Mat img; //�̹����� ������ �迭 ���������� ����

void onChange(int value, void* userdate) { //Thigh Ʈ���ٸ� �������� �� ȣ�� �Ǵ� �ݹ� �Լ�
	Mat tmp;

	Canny(img, tmp, th.start, th.end); //ĳ�Ͽ��� �ٽ� ����
	imshow(title, tmp);
}

int main() {
	img = imread("highway.jpg", IMREAD_GRAYSCALE);
	CV_Assert(img.data);
	Mat gau_img, canny;

	namedWindow(title, WINDOW_AUTOSIZE); //������ �̸�
	createTrackbar("Tlow", title, &th.start, 150, onChange); //Tlow Ʈ���� �����
	createTrackbar("Thigh", title, &th.end, 255, onChange); //Thigh Ʈ���� �����

	Canny(img, canny, th.start, th.end);

	imshow(title, canny);
	waitKey(0);
	return 0;
}