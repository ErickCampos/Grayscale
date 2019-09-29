#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <string>
#include "iostream"
#include <sys/times.h>


using namespace cv;
using namespace std;

int max(int b, int g, int r);
int min(int b, int g, int r);

Mat first(Mat src, Mat dst);
Mat second(Mat src, Mat dst);
Mat third(Mat src, Mat dst);
Mat fourth(Mat src, Mat dst);
Mat fifth(Mat src, Mat dst, string dec); //string dec: "max" | "min"
Mat sixth(Mat src, Mat dst, string channel); //string channel: "blue" | "green" | "red" 
Mat seventh(Mat src, Mat dst, int numberOfShades);

int main(){
    clock_t ti, tf;
    ti = clock();
	
	char name[20];
	unsigned int x=1;  
	while(x<5001){
		sprintf(name,"img/image%d.jpg",x);
		Mat img = imread(name);

		Mat img1 = img.clone();
		Mat img2 = img.clone();
		Mat img3 = img.clone();
		Mat img4 = img.clone();
		Mat img5 = img.clone();
		Mat img6 = img.clone();
		Mat img7 = img.clone();
		Mat img8 = img.clone();
		Mat img9 = img.clone();
		Mat img10 = img.clone();
		first(img,img1);
		second(img, img2);
		third(img, img3);
		fourth(img, img4);
		fifth(img, img5,"min");
		fifth(img,img6,"max");
		sixth(img,img7,"blue");
		sixth(img,img8,"green");
		sixth(img,img9,"red");
		seventh(img,img10,40);
//		cout<<x<<endl; 
		x++;
	}
    tf = clock();
    cout<<(int)((tf-ti)*0.000001)/60<<" minutos e "<<((tf-ti)*0.000001/60 - (int)(tf-ti)*0.000001/60) * 60<< " segundos"<<endl; 
	return 0;
}


int max(int b, int g, int r){
    if(b>g && b>=r)
        return b;
    else if(g>=b && g>=r)
            return g;
    else
        return r;
}

int min(int b, int g, int r){
    int min = 0;
    while(b && g && r){
        b--;
        g--;
        r--;
        min++;
    }
    return min;
}

// first
Mat first(Mat src, Mat dst){
    for (int y = 0; y < dst.cols; y++) {
        for (int x = 0; x < dst.rows; x++) {
            Vec3b pixel = src.at<Vec3b>(x, y);
            int mean = (pixel.val[0]+pixel.val[1]+pixel.val[2])/3;
            dst.at<Vec3b>(x, y).val[0] = mean;
            dst.at<Vec3b>(x, y).val[1] = mean;
            dst.at<Vec3b>(x, y).val[2] = mean;
        }
    }
    return dst;
}

//second
Mat second(Mat src, Mat dst){
    for (int y = 0; y < dst.cols; y++) {
        for (int x = 0; x < dst.rows; x++) {
            Vec3b pixel = src.at<Vec3b>(x, y);
            //*int blue = pixel.val[0];
            //*int green = pixel.val[1];
            //*int red = pixel.val[2];
            int mean = (pixel.val[0]*0.11+pixel.val[1]*0.59+pixel.val[2]*0.3);
            dst.at<Vec3b>(x, y).val[0] = mean;
            dst.at<Vec3b>(x, y).val[1] = mean;
            dst.at<Vec3b>(x, y).val[2] = mean;
        }
    }
    return dst;
}

//third
Mat third(Mat src, Mat dst){
    for (int y = 0; y < dst.cols; y++) {
        for (int x = 0; x < dst.rows; x++) {
            Vec3b pixel = src.at<Vec3b>(x, y);
            //*int blue = pixel.val[0];
            //*int green = pixel.val[1];
            //*int red = pixel.val[2];
            int mean = (pixel.val[0]*0.0722+pixel.val[1]*0.7152+pixel.val[2]*0.2126);
            dst.at<Vec3b>(x, y).val[0] = mean;
            dst.at<Vec3b>(x, y).val[1] = mean;
            dst.at<Vec3b>(x, y).val[2] = mean;
        }
    }
    return dst;
}

//fourth
Mat fourth(Mat src, Mat dst){
    for (int y = 0; y < dst.cols; y++) {
        for (int x = 0; x < dst.rows; x++) {
            Vec3b pixel = src.at<Vec3b>(x, y);
            //*int blue = pixel.val[0];
            //*int green = pixel.val[1];
            //*int red = pixel.val[2];
            int mean = ( (max((int)pixel.val[0],(int)pixel.val[1],(int)pixel.val[2])   + min((int)pixel.val[0],(int)pixel.val[1],(int)pixel.val[2])) / 2);
            dst.at<Vec3b>(x, y).val[0] = mean;
            dst.at<Vec3b>(x, y).val[1] = mean;
            dst.at<Vec3b>(x, y).val[2] = mean;
        }
    }
    return dst;
}

Mat fifth(Mat src, Mat dst, string dec){

    if(dec=="max"){    
        for (int y = 0; y < dst.cols; y++) {
            for (int x = 0; x < dst.rows; x++) {
                Vec3b pixel = src.at<Vec3b>(x, y);
                //*int blue = pixel.val[0];
                //*int green = pixel.val[1];
                //*int red = pixel.val[2];
                int mean = max((int)pixel.val[0],(int)pixel.val[1],(int)pixel.val[2]);
                dst.at<Vec3b>(x, y).val[0] = mean;
                dst.at<Vec3b>(x, y).val[1] = mean;
                dst.at<Vec3b>(x, y).val[2] = mean;
            }
        }
    }

    if(dec=="min"){    
        for (int y = 0; y < dst.cols; y++) {
            for (int x = 0; x < dst.rows; x++) {
                Vec3b pixel = src.at<Vec3b>(x, y);
                //*int blue = pixel.val[0];
                //*int green = pixel.val[1];
                //*int red = pixel.val[2];
                int mean = min((int)pixel.val[0],(int)pixel.val[1],(int)pixel.val[2]);
                dst.at<Vec3b>(x, y).val[0] = mean;
                dst.at<Vec3b>(x, y).val[1] = mean;
                dst.at<Vec3b>(x, y).val[2] = mean;
            }
        }
    }
    return dst;
}

Mat sixth(Mat src, Mat dst, string channel){

    if(channel=="blue"){    
        for (int y = 0; y < dst.cols; y++) {
            for (int x = 0; x < dst.rows; x++) {
                Vec3b pixel = src.at<Vec3b>(x, y);
                int mean = pixel.val[0]; //blue
                dst.at<Vec3b>(x, y).val[0] = mean;
                dst.at<Vec3b>(x, y).val[1] = mean;
                dst.at<Vec3b>(x, y).val[2] = mean;
            }
        }
    }

    else if(channel=="green"){    
        for (int y = 0; y < dst.cols; y++) {
            for (int x = 0; x < dst.rows; x++) {
                Vec3b pixel = src.at<Vec3b>(x, y);
                int mean = pixel.val[1]; //green
                dst.at<Vec3b>(x, y).val[0] = mean;
                dst.at<Vec3b>(x, y).val[1] = mean;
                dst.at<Vec3b>(x, y).val[2] = mean;
            }
        }
    }

    else if(channel=="red"){    
        for (int y = 0; y < dst.cols; y++) {
            for (int x = 0; x < dst.rows; x++) {
                Vec3b pixel = src.at<Vec3b>(x, y);
                int mean = pixel.val[2]; //red
                dst.at<Vec3b>(x, y).val[0] = mean;
                dst.at<Vec3b>(x, y).val[1] = mean;
                dst.at<Vec3b>(x, y).val[2] = mean;
            }
        }
    }
    return dst;
}


Mat seventh(Mat src, Mat dst, int numberOfShades){
    if(numberOfShades<=1)
        numberOfShades=2;
    
    int conversionFactor = 255/(numberOfShades-1);
    
    for (int y = 0; y < dst.cols; y++) {
        for (int x = 0; x < dst.rows; x++) {
            Vec3b pixel = src.at<Vec3b>(x, y);
            int mean = (pixel.val[0]+pixel.val[1]+pixel.val[2])/3;
            dst.at<Vec3b>(x, y).val[0] = ((mean/conversionFactor) + 0.5)*conversionFactor;
            dst.at<Vec3b>(x, y).val[1] = ((mean/conversionFactor) + 0.5)*conversionFactor;
            dst.at<Vec3b>(x, y).val[2] = ((mean/conversionFactor) + 0.5)*conversionFactor;
        }
    }
    return dst;
}
