#include "camviewer.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core.hpp"
#include "opencv2/core/types.hpp"
#include <QVBoxLayout>
#include <QDebug>

#include <cv.h>

CamViewer::CamViewer()
	: QWidget()
{
	auto lt = new QVBoxLayout(this);
	lt->addWidget(viewer_ = new QtOpenCVViewerGl);
//	capture_.open(0);
	capture_.open("http://91.201.117.136/mjpg/video.mjpg?COUNTER");
//	capture_.open("http://69.68.220.136/mjpg/video.mjpg?COUNTER");
	startTimer(15);
}

CamViewer::~CamViewer()
{

}
void CamViewer::timerEvent(QTimerEvent *event)
{
	//	cv::Point2f src_center(image.cols / 2.0F, image.rows / 2.0F);
//	cv::Mat rot_mat = cv::getRotationMatrix2D(src_center, 30, 1.0);
//	cv::warpAffine(image, image, rot_mat, image.size());	
	cv::Mat image = getImage();
	viewer_->showImage(image);
	emit(imageUpdate(image));
}
cv::Mat CamViewer::getImage() {
	cv::Mat image;
	capture_ >> image;
	cv::flip(image, image, 0);
	return image;
}
