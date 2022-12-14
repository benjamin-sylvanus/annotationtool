// Import packages
#include <opencv2/opencv.hpp>
#include <ctime>
#include <vector>
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QCheckBox>
#include <QWindow>
#include <QImage>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>




//Using namespace to nullify use of cv::function(); syntax
using namespace cv;
using namespace std;

// Points to store the bounding box coordinates
Point top_left_corner, bottom_right_corner;
bool pressed;

// image image
Mat image;
Mat image_temp;
vector<Point> top;
vector<Point> bottom;
clock_t time_req;

// function which will be called on mouse input
void drawRectangle(int action, int x, int y, int flags, void *userdata)
{
    // Mark the top left corner when left mouse button is pressed
    if( action == EVENT_LBUTTONDOWN )
    {
        time_req = clock();
        pressed=true;
        top_left_corner = Point(x,y);
    }
        // When left mouse button is released, mark bottom right corner
    else if( action == EVENT_LBUTTONUP)
    {
        pressed = false;
        rectangle(image, top_left_corner, bottom_right_corner, Scalar(0,255,0), 1, 1 );
        image_temp = image.clone();
        cout<<top<<endl;
        cout<<bottom<<endl;
        top.push_back(top_left_corner);
        bottom.push_back(bottom_right_corner);
        imshow("Window", image);
    }

    else if(pressed)
    {
        bottom_right_corner = Point(x, y);
        if( action == EVENT_MOUSEMOVE)
        {
            if (float(clock()-time_req)/CLOCKS_PER_SEC > 0.001)
            {
                // Draw rectangle
                rectangle(image_temp, top_left_corner, bottom_right_corner, Scalar(200, 200, 0), 1, 8);
                // Display image

                imshow("Window", image_temp);
                image_temp = image.clone();
                time_req = clock();
            }
        }
        else
        {
            if (float(clock()-time_req)/CLOCKS_PER_SEC > 0.08)
            {
                cout << float(clock()-time_req) / CLOCKS_PER_SEC << endl;
                bottom_right_corner = Point(x, y);
                // Draw rectangle
                rectangle(image_temp, top_left_corner, bottom_right_corner, Scalar(200, 200, 0), 1, 4);
                // Display image
                imshow("Window", image_temp);
                image_temp = image.clone();
                time_req = clock();
            }
        }
    }
}

// Main function
int main(int argc, char *argv[])
{
    image = imread("/Users/benjaminsylvanus/CLionProjects/SampleProject/calcApp/lena.png");
    // Make a temporary image, which will be used to clear the image
    Mat temp = image.clone();
    image_temp = image.clone();
    // Create a named window
    namedWindow("Window",WINDOW_OPENGL);
    // highgui function called when mouse events occur
    setMouseCallback("Window", drawRectangle);

    time_req=clock();
    int k=0;
    // loop until q character is pressed
    while(k!=113)
    {
        imshow("Window", image);
        k= waitKey(0);
        // If c is pressed, clear the window, using the dummy image
        if(k == 99)
        {
            temp.copyTo(image);
            temp.copyTo(image_temp);
        }
    }
    cout<<top<<endl;
    cout<<bottom<<endl;
    destroyAllWindows();

    QApplication app (argc, argv);
    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");
    QPushButton *button6 = new QPushButton("Six");
    QVBoxLayout *vert = new QVBoxLayout(window);
    QHBoxLayout *layout1 = new QHBoxLayout();
    QHBoxLayout *layout2 = new QHBoxLayout();
    QHBoxLayout *layout3 = new QHBoxLayout();
    vert->addLayout(layout1);
    vert->addLayout(layout2);
    vert->addLayout(layout3);
    layout1->addWidget(button1);
    layout1->addWidget(button2);
    layout2->addWidget(button3);
    layout2->addWidget(button4);
    layout3->addWidget(button5);
    layout3->addWidget(button6);

    window->show();
    return QApplication::exec();

    return 0;
}