#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void show_img(Mat output)
{
    imshow("Cars", output);         //displaying output image file
    waitKey(0);                    //to exit press escape
}

void rotate(Mat src, double angle)   //rotate function returning mat object with parametres imagefile and angle    
{
    Mat img; 
    Point2f centre(src.cols / 2., src.rows / 2.);          //point from where to rotate    
    Mat r = getRotationMatrix2D(centre, angle, 1.0);      //Mat object for storing after rotation
    Rect2f bbox = RotatedRect(Point2f(), src.size(), angle).boundingRect2f();
    r.at<double>(0, 2) = r.at<double>(0, 2) + bbox.width / 2.0 - src.cols / 2.0;
    r.at<double>(1, 2) = r.at<double>(1, 2) + bbox.height / 2.0 - src.rows / 2.0;
    warpAffine(src, img, r, bbox.size());  //applie an affine transforation to image.
    resize(img, img, Size(500, 500));
    show_img(img);
}

int main()
{
    Mat img = imread("lamborghini.jpg");  //reading image file in mat object
    Mat output;    
    double angle;
    cout<<"\n\n\t\t----------Image Rotation-----------";
    cout<<"\n\tEnter The Angle to Rotate Image : ";
    cin>>angle;
    rotate(img, angle);     //rotating image with 30 degree angle
    return 0;
}