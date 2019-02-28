#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <iostream>
#include <QMouseEvent>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "mat.h"

// #include "train.h"

#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cmath>
#include <time.h>

using namespace std;

const int FIRST = 784;		//The input layer contains 784=28*28 neurons
const int SECOND = 100;		//The second layer is a hidden layer, containing 100 neurons
const int THIRD = 10;		//The output layer contains 10 neurons
const double ALPHA = 0.35;	//Learning rate

int input[FIRST];		//The input vector of the images
int target[THIRD];		//The target output
double weight2[FIRST][SECOND];		//The weight matrix of the second layer
double weight3[SECOND][THIRD];		//The weight matrix of the third/output layer
double output2[SECOND];				//The output vector of the second layer
double output3[THIRD];				//The output vector of the third/output layer
double delta2[SECOND];				//The gradient vector of the second layer
double delta3[THIRD];				//The gradient vector of the third/output layer
double b2[SECOND];					//The bias vector of the second layer
double b3[THIRD];					//The bias vector of the third/output layer

double test_num = 0.0;
double test_success_count = 0.0;

//The sigmoid function
double Sigmoid(double x){
    return 1.0 / (1.0 + exp(-x));
}

//Calculate the output vector of the second layer
void cal_op2(){
    for (int j = 0; j < SECOND; j++){
        double sigma = 0;
        for (int i = 0; i < FIRST; i++){
            sigma += input[i] * weight2[i][j];
        }
        double x = sigma + b2[j];
        output2[j] = Sigmoid(x);
    }
}

//Calculate the output vector of the third/output layer
void cal_op3(){
    for (int k = 0; k < THIRD; k++){
        double sigma = 0;
        for (int j = 0; j < SECOND; j++){
            sigma += output2[j] * weight3[j][k];
        }
        double x = sigma + b3[k];
        output3[k] = Sigmoid(x);
    }
}

//Calculate the gradient vector of the second layer
void cal_delta3(){
    for (int k = 0; k < THIRD; k++){
        delta3[k] = (output3[k]) * (1.0 - output3[k]) * (output3[k] - target[k]);
    }
}

//Calculate the gradient vector of the third/output layer
void cal_delta2(){
    for (int j = 0; j < SECOND; j++){
        double sigma = 0;
        for (int k = 0; k < THIRD; k++){
            sigma += weight3[j][k] * delta3[k];
        }
        delta2[j] = (output2[j]) * (1.0 - output2[j]) * sigma;
    }
}

void feedback_second(){
    for (int j = 0; j < SECOND; j++){
        b2[j] = b2[j] - ALPHA * delta2[j];
        for (int i = 0; i < FIRST; i++){
            weight2[i][j] = weight2[i][j] - ALPHA * input[i] * delta2[j];
        }
    }
}

void feedback_third(){
    for (int k = 0; k < THIRD; k++){
        b3[k] = b3[k] - ALPHA * delta3[k];
        for (int j = 0; j < SECOND; j++){
            weight3[j][k] = weight3[j][k] - ALPHA * output2[j] * delta3[k];
        }
    }
}

//Initialize the weight matrix and the bias vector randomly
void initialize(){
    srand((int)time(0) + rand());
    for (int i = 0; i < FIRST; i++){
        for (int j = 0; j < SECOND; j++){
            weight2[i][j] = rand()%1000 * 0.001 - 0.5;
        }
    }
    for (int j = 0; j < SECOND; j++){
        for (int k = 0; k < THIRD; k++){
            weight3[j][k] = rand()%1000 * 0.001 - 0.5;
        }
    }

    for (int j = 0; j < SECOND; j++){
        b2[j] = rand()%1000 * 0.001 - 0.5;
    }
    for (int k = 0; k < THIRD; k++){
        b3[k] = rand()%1000 * 0.001 - 0.5;
    }
}

void training(){
    FILE *image_train;
    FILE *image_label;
    image_train = fopen("train-images.idx3-ubyte", "rb");
    image_label = fopen("train-labels.idx1-ubyte", "rb");
    if (image_train == NULL || image_label == NULL){
        cout << "can't open the file!" << endl;
        exit(0);
    }

    unsigned char image_buf[784];
    unsigned char label_buf[10];

    int useless[1000];
    fread(useless, 1, 16, image_train);
    fread(useless, 1, 8, image_label);

    int train_num = 0;
    cout << "Start training..." << endl;
    //60000 times
    while (!feof(image_train) && !feof(image_label)){
        memset(image_buf, 0, 784);
        memset(label_buf, 0, 10);
        fread(image_buf, 1, 784, image_train);
        fread(label_buf, 1, 1, image_label);

        //initialize the input by 28 x 28 (0,1)matrix of the images
        for (int i = 0; i < 784; i++){
            if ((unsigned int)image_buf[i] < 128){
                input[i] = 0;
            }
            else{
                input[i] = 1;
            }
        }

        //initialize the target output
        int target_value = (unsigned int)label_buf[0];
        for (int k = 0; k < THIRD; k++){
            target[k] = 0;
        }
        target[target_value] = 1;

        //get the output and start training
        cal_op2();
        cal_op3();
        cal_delta3();
        cal_delta2();
        feedback_second();
        feedback_third();

        train_num ++;
        if (train_num % 1000 == 0){
            cout << "training image: " << train_num << endl;
        }
    }
    cout << endl;
}


void testing(){
    FILE *image_test;
    FILE *image_test_label;
    image_test = fopen("t10k-images.idx3-ubyte", "rb");
    image_test_label = fopen("t10k-labels.idx1-ubyte", "rb");
    if (image_test == NULL || image_test_label == NULL){
        cout << "can't open the file!" << endl;
        exit(0);
    }

    unsigned char image_buf[784];
    unsigned char label_buf[10];

    int useless[1000];
    fread(useless, 1, 16, image_test);
    fread(useless, 1, 8, image_test_label);

    while (!feof(image_test) && !feof(image_test_label)){
        memset(image_buf, 0, 784);
        memset(label_buf, 0, 10);
        fread(image_buf, 1, 784, image_test);
        fread(label_buf, 1, 1, image_test_label);

        //initialize the input by 28 x 28 (0,1)matrix of the images
        for (int i = 0; i < 784; i++){
            if ((unsigned int)image_buf[i] < 128){
                input[i] = 0;
            }
            else{
                input[i] = 1;
            }
        }

        //initialize the target output
        for (int k = 0; k < THIRD; k++){
            target[k] = 0;
        }
        int target_value = (unsigned int)label_buf[0];
        target[target_value] = 1;

        //get the output and compare with the target
        cal_op2();
        cal_op3();

        double max_value = -99999;
        int max_index = 0;
        for (int k = 0; k < THIRD; k++){
            if (output3[k] > max_value){
                max_value = output3[k];
                max_index = k;
            }
        }

        //output == target
        if (target[max_index] == 1){
            test_success_count ++;
        }

        test_num ++;

        if ((int)test_num % 1000 == 0){
            cout << "test num: " << test_num << "  success: " << test_success_count << endl;
        }
    }
    cout << endl;
    cout << "The success rate: " << test_success_count / test_num << endl;
}

/*
void testOnImage(QImage &img) {
    Mat matrix(*img);
    for (int i = 0; i < FIRST; i++) {
        input[i] = matrix.getData(i);
    }
    cal_op2();
    cal_op3();

    double max_value = -99999;
    int max_index = 0;
    for (int k = 0; k < THIRD; k++){
        if (output3[k] > max_value){
            max_value = output3[k];
            max_index = k;
        }
    }
    cout << max_index << endl;
}
*/


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
//    initialize();
//    training();
//    testing();
    ui->setupUi(this);

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_openImage_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                                    ".",
                                                    tr("Image Files (*.png *.jpg *.bmp)"));
    if (filename.isEmpty()) {
        return;
    }
    else {
        QImage* img = new QImage;
        if (!(img->load(filename))) {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败！"));
            delete img;
            return;
        }
        QImage* imgScaled = new QImage;
        *imgScaled = img->scaled(140, 140, Qt::KeepAspectRatio);

        QImage* imgScaledTo28 = new QImage;
        *imgScaledTo28 = img->scaled(28, 28, Qt::KeepAspectRatio);
        //ui->imageLabel->setPixmap(QPixmap::fromImage(*img));
        ui->imageLabel->setPixmap(QPixmap::fromImage(*imgScaled));

        //Mat matrix(*img);
        //ui->imageLabel->setText(matrix.print());
        //cout << matrix.print() << endl;
        //QMessageBox::information(this, tr("Hello"), tr("hello!"));
        Mat matrix(*imgScaledTo28);
        // matrix.printString();
        matrix.filldata();
        for (int i = 0; i < FIRST; i++) {
            input[i] = matrix.getData(i);
        }
        cal_op2();
        cal_op3();

        double max_value = -99999;
        int max_index = 0;
        for (int k = 0; k < THIRD; k++){
            if (output3[k] > max_value){
                max_value = output3[k];
                max_index = k;
            }
        }
        //cout << max_value << endl;
        //cout << max_index << endl;
        QMessageBox::information(this, tr("预测结果"),tr("预测结果") + QString::number(max_index));
    }
}

void MainWidget::on_train_clicked()
{
    initialize();
    FILE *image_train;
    FILE *image_label;
    image_train = fopen("train-images.idx3-ubyte", "rb");
    image_label = fopen("train-labels.idx1-ubyte", "rb");
    if (image_train == NULL || image_label == NULL){
        cout << "can't open the file!" << endl;
        exit(0);
    }

    unsigned char image_buf[784];
    unsigned char label_buf[10];

    int useless[1000];
    fread(useless, 1, 16, image_train);
    fread(useless, 1, 8, image_label);

    int train_num = 0;
    // cout << "Start training..." << endl;
    //60000 times
    while (!feof(image_train) && !feof(image_label)){
        memset(image_buf, 0, 784);
        memset(label_buf, 0, 10);
        fread(image_buf, 1, 784, image_train);
        fread(label_buf, 1, 1, image_label);

        //initialize the input by 28 x 28 (0,1)matrix of the images
        for (int i = 0; i < 784; i++){
            if ((unsigned int)image_buf[i] < 128){
                input[i] = 0;
            }
            else{
                input[i] = 1;
            }
        }

        //initialize the target output
        int target_value = (unsigned int)label_buf[0];
        for (int k = 0; k < THIRD; k++){
            target[k] = 0;
        }
        target[target_value] = 1;

        //get the output and start training
        cal_op2();
        cal_op3();
        cal_delta3();
        cal_delta2();
        feedback_second();
        feedback_third();

        train_num ++;

        if (train_num % 1000 == 0){
            cout << "training image: " << train_num << endl;
            // ui->label->setText("Training image");
        }
        ui->label->setText("Training finished");
    }
}

void MainWidget::on_test_clicked()
{
    FILE *image_test;
    FILE *image_test_label;
    image_test = fopen("t10k-images.idx3-ubyte", "rb");
    image_test_label = fopen("t10k-labels.idx1-ubyte", "rb");
    if (image_test == NULL || image_test_label == NULL){
        cout << "can't open the file!" << endl;
        exit(0);
    }

    unsigned char image_buf[784];
    unsigned char label_buf[10];

    int useless[1000];
    fread(useless, 1, 16, image_test);
    fread(useless, 1, 8, image_test_label);

    while (!feof(image_test) && !feof(image_test_label)){
        memset(image_buf, 0, 784);
        memset(label_buf, 0, 10);
        fread(image_buf, 1, 784, image_test);
        fread(label_buf, 1, 1, image_test_label);

        //initialize the input by 28 x 28 (0,1)matrix of the images
        for (int i = 0; i < 784; i++){
            if ((unsigned int)image_buf[i] < 128){
                input[i] = 0;
            }
            else{
                input[i] = 1;
            }
        }

        //initialize the target output
        for (int k = 0; k < THIRD; k++){
            target[k] = 0;
        }
        int target_value = (unsigned int)label_buf[0];
        target[target_value] = 1;

        //get the output and compare with the target
        cal_op2();
        cal_op3();

        double max_value = -99999;
        int max_index = 0;
        for (int k = 0; k < THIRD; k++){
            if (output3[k] > max_value){
                max_value = output3[k];
                max_index = k;
            }
        }

        //output == target
        if (target[max_index] == 1){
            test_success_count ++;
        }

        test_num ++;

        if ((int)test_num % 1000 == 0){
            cout << "test num: " << test_num << "  success: " << test_success_count << endl;
        }
    }
    cout << endl;
    // cout << "The success rate: " << test_success_count / test_num << endl;
    ui->label_2->setText(QString::number(test_success_count / test_num));
}
