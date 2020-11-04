#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
void main() {
    Mat img=imread("D:\\1.jpg",0);
    Mat rst,dstMat;
    /*
    Canny(img,rst,110,160);

    float angle=-10.0,scale=1;
    Point2f center(img.cols*0.5,img.rows*0.5);
    const Mat affine_matrix=getRotationMatrix2D(center,angle,scale);
    warpAffine(img,dstMat,affine_matrix,img.size());

    const Point2f src_pt[]={
        Point2f(200,200),
        Point2f(250,200),
        Point2f(200,100)
    };
    const Point2f dst_pt[]={
        Point2f(300,100),
        Point2f(300,50),
        Point2f(200,100)
    };
    const Mat affine_matrix=getAffineTransform(src_pt,dst_pt);
    warpAffine(img,dstMat,affine_matrix,img.size());

    Point2f pts1[]={
        Point2f(150,150),
        Point2f(150,300),
        Point2f(350,300),
        Point2f(350,150)
    };
     Point2f pts2[]={
        Point2f(200,150),
        Point2f(200,300),
        Point2f(340,270),
        Point2f(340,180)
    };
    Mat per_mat=getPerspectiveTransform(pts1,pts2);
    warpPerspective(img,dstMat,per_mat,img.size());
    */
    const int row = img.rows;
    int ts[1920][2];
    int k = 0;
    float s = 0;
    Vec3b bgr1, bgr2;
    for (int i=0;i<img.rows;i++){
        for(int j=1;j<img.cols;j++){
            bgr1 = img.at<Vec3b>(i, j);
            bgr2 = img.at<Vec3b>(i, j-1);
            if (abs(bgr1[0]+bgr1[1]+bgr1[2]- bgr2[0] - bgr2[1] - bgr2[2])>60){
            ts[i][k]=j;
            k++;
            if (k = 2) {
                k = 0;
                break;
            }
            }
        }
    }
    for (int i = 1;i < row;i++)
        s = s + atan(ts[i][1]/ i);
    float angle = s / row;
    float scale = 1;
    Point2f center(img.cols * 0.5, img.rows * 0.5);
    const Mat affine_matrix = getRotationMatrix2D(center, angle, scale);
    warpAffine(img, dstMat, affine_matrix, img.size());
    imshow("dst", dstMat);
    waitKey(0);
}