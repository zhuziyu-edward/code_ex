//
//  main.cpp
//  computer_vision
//
//  Created by Edward dawson on 02/10/2017.
//  Copyright © 2017 Edward dawson. All rights reserved.
//

#include <iostream>
#include "opencv2/highgui.hpp"
int main(int argc, const char * argv[]) {
    IplImage* img = cvLoadImage(argv[1]);
    cvNamedWindow("example1", CV_WINDOW_AUTOSIZE);
    cvShowImage("example1", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("example1");
    return 0;
}
