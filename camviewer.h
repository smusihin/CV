#ifndef CAMVIEWER_H
#define CAMVIEWER_H

#include <QWidget>
#include <qtopencvviewergl.h>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/objdetect.hpp"

class CamViewer : public QWidget
{
	Q_OBJECT

public:
	CamViewer();
	cv::Mat getImage();
	~CamViewer();
signals:
	void imageUpdate(cv::Mat image);

private:

	QtOpenCVViewerGl * viewer_;
	cv::VideoCapture capture_;


protected:
	void timerEvent(QTimerEvent *event);
	 
	
};

#endif // CAMVIEWER_H
