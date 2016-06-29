#ifndef CV_H
#define CV_H

#include <QWidget>
#include "camviewer.h"
#include "HaarDetector.h"
#include "MotionDetector.h"

class CV : public QWidget
{
	Q_OBJECT

public:
	CV();
	~CV();

private:
	CamViewer * viewer;
	HaarDetector * haarDetector;	
	
};

#endif // CV_H
