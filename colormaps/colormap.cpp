#include <opencv2/highgui/highgui.hpp>
#include "colormap.hpp"
#include "helper.hpp"

bool cv::colormap::imwrite(const string& filename, const Mat& img,
		const cv::colormap::ColorMap& cm/*=cv::colormap::Jet()*/,
		const std::vector<int>& params/*=std::vector<int>()*/) {
	cv::Mat tmp = img.clone();
	tmp = cm(tmp);
	tmp.convertTo(tmp, CV_8UC3, 255);
	return cv::imwrite(filename, tmp, params);
}
