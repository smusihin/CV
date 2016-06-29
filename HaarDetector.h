#ifndef HAARDETECTOR_H
#define HAARDETECTOR_H

#include "imageproc.h"
#include "opencv2/objdetect.hpp"
#include "opencv2/core/types.hpp"
#include "QComboBox"

class HaarDetector : public ImageProc
{
	Q_OBJECT

public:
	HaarDetector();	
	~HaarDetector();
public slots:
	void init(const QString &file);
private:
	QComboBox *fileChanger;
	QString path;
	cv::CascadeClassifier detector;
protected:
	virtual cv::Mat process(const cv::Mat & image);
};
#endif//HAARDETECTOR_H

