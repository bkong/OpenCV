/*
 * Copyright (c) 2011. Philipp Wagner <bytefish[at]gmx[dot]de>.
 * Released to public domain under terms of the BSD Simplified license.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the organization nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *   See <http://www.opensource.org/licenses/bsd-license>
 */
#include <string>
#include <cv.h>
#include <highgui.h>
#include "colormap.hpp"
#include "helper.hpp"

using namespace cv;
using namespace std;


int main(int argc, const char *argv[]) {
	// example with an image
	Mat img0 = imread("01.jpg",1);
	colormap::Jet cm;

	imshow("cm", cm(img0));
	waitKey(0);

	Mat img1 = Mat::zeros(30, 256, CV_8UC1);
	for(int i = 0; i < 256; i++) {
		Mat roi = Mat(img1, Range::all(), Range(i,i+1));
		roi += i;
	}

	string prefix("colorscale_");
	colormap::imwrite(prefix + string("autumn.jpg"), img1, colormap::Autumn());
	colormap::imwrite(prefix + string("bone.jpg"), img1, colormap::Bone());
	colormap::imwrite(prefix + string("jet.jpg"), img1, colormap::Jet());
	colormap::imwrite(prefix + string("winter.jpg"), img1, colormap::Winter());
	colormap::imwrite(prefix + string("rainbow.jpg"), img1, colormap::Rainbow());
	colormap::imwrite(prefix + string("ocean.jpg"), img1, colormap::Ocean());
	colormap::imwrite(prefix + string("summer.jpg"), img1, colormap::Summer());
	colormap::imwrite(prefix + string("spring.jpg"), img1, colormap::Spring());
	colormap::imwrite(prefix + string("cool.jpg"), img1, colormap::Cool());
	colormap::imwrite(prefix + string("hsv.jpg"), img1, colormap::HSV());
	colormap::imwrite(prefix + string("pink.jpg"), img1, colormap::Pink());
	colormap::imwrite(prefix + string("hot.jpg"), img1, colormap::Hot());
	colormap::imwrite(prefix + string("mkpj1.jpg"), img1, colormap::MKPJ1());
	colormap::imwrite(prefix + string("mkpj2.jpg"), img1, colormap::MKPJ2());

	return 0; // success
}
