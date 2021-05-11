#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Range th(50, 128);
String title = "result"; //윈도우 이름
Mat img; //이미지를 저장할 배열 전역변수로 선언

void onChange(int value, void* userdate) { //Thigh 트랙바를 움직였을 때 호출 되는 콜백 함수
	Mat tmp;

	Canny(img, tmp, th.start, th.end); //캐니에지 다시 생성
	imshow(title, tmp);
}

int main() {
	img = imread("highway.jpg", IMREAD_GRAYSCALE);
	CV_Assert(img.data);
	Mat gau_img, canny;

	namedWindow(title, WINDOW_AUTOSIZE); //윈도우 이름
	createTrackbar("Tlow", title, &th.start, 150, onChange); //Tlow 트랙바 만들기
	createTrackbar("Thigh", title, &th.end, 255, onChange); //Thigh 트랙바 만들기

	Canny(img, canny, th.start, th.end);

	imshow(title, canny);
	waitKey(0);
	return 0;
}