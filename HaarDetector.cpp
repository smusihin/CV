#include "HaarDetector.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/types_c.h"
#include <QVBoxLayout>
#include <QDir>
#include <QDebug>



HaarDetector::HaarDetector() 
	: path("c:\\OpenCV\\opencv\\sources\\data\\haarcascades\\")
{
	auto l = new  QVBoxLayout;
	fileChanger = new QComboBox;
	QDir dir(path);
	fileChanger->addItems(dir.entryList({ "*.xml" }, QDir::Files));
	l->addWidget(fileChanger);
	setLayout(l);
	init(fileChanger->currentText());
	connect(fileChanger,&QComboBox::currentTextChanged,this,&HaarDetector::init);
}

void HaarDetector::init(const QString & file) {
	detector.load(QString(path + file).toStdString());
}
HaarDetector::~HaarDetector()
{
}

cv::Mat  HaarDetector::process(const cv::Mat & image) {
	if (!detector.empty()) {
		std::vector<cv::Rect> rects;
		cv::Mat gray;
		cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
		detector.detectMultiScale(
			image,
			rects,
			1.1,
			2,
			0 | cv::CASCADE_SCALE_IMAGE,
			cv::Size(50, 50));
		cv::Mat img(image);
		for (auto &r : rects) {
			cv::rectangle(img, r, cv::Scalar(1, 1, 1));
		}
		return img;
	}
	return cv::Mat::zeros(image.size(),0);
}