#include "cv.h"
#include <QHBoxLayout>

CV::CV()
	: QWidget()
{
	viewer = new CamViewer;
	auto output = new QtOpenCVViewerGl;
//	haarDetector = new HaarDetector;
	auto mainLayout = new QHBoxLayout(this);
//	mainLayout->addWidget(haarDetector);
	auto moveDetect = new MotionDetector;
	mainLayout->addWidget(viewer);
	mainLayout->addWidget(output);
	setMinimumSize(QSize(600,400));
	connect(moveDetect, &ImageProc::processed, output, &QtOpenCVViewerGl::showImage);
	connect(viewer, &CamViewer::imageUpdate, moveDetect, &ImageProc::calculate);
}

CV::~CV()
{

}
