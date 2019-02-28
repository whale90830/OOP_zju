#include "mat.h"
#include <iostream>
#include <string>

using namespace std;

void Mat::filldata() {
    for(int i=0;i<width;i++)
        { for(int j=0;j<height;j++)
            {
              data.push_back(qGray(_img.pixel(i,j)));
              //最初在写这里的时候使用了Qrgb value =_img.pixel(i,j)
              //data.push_back(qGray(value))，但是这样导致了所有灰度值均为0；
              //目前还不知道原因
            }
        }
}

QString Mat::print()
{
    Mat::filldata();
    QString sdata;
    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
          sdata =sdata+"  "+QString::number(data.at(i*height+j),10);
          //i*height+j,将height和width转为一列
        }
        sdata =sdata+'\n';
    }

    return sdata;
}

void Mat::printString() {
    Mat::filldata();
    string s = "";
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            s = s + to_string(data.at(i * height + j)) + "\n";
        }
        //s = s + "\n";
    }
    cout << s << endl;
}


int Mat::getData(int i) {
    // cout << data.size() << endl;
    if (data.at(i) < 128) {
        return 0;
    }
    else {
        return 1;
    }
}

