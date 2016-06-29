#ifndef IMAGEPROC_H
#define IMAGEPROC_H

#include <QWidget>
#include <opencv2/core.hpp>

class  ImageProc : public QWidget
{
	Q_OBJECT

public:
	ImageProc() {}
	~ImageProc() {}
signals:
	void processed(const cv::Mat & image);
public slots:
	void calculate(const cv::Mat & image)
	{
		emit(processed(process(image)));
	}
protected:
	virtual cv::Mat process(const cv::Mat & image) { return cv::Mat::zeros(0,0,0); };
};

#endif // IMAGEPROC_H
