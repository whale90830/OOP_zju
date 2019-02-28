#ifndef MAT_H
#define MAT_H

#include <vector>
#include <qstring.h>
#include <qimage.h>

class Mat {
public:
    Mat() {}
    Mat(QImage &img):width(img.width()),height(img.height()), _img(img) {}

    void filldata();
    QString print();
    void printString();
    int getData(int);

private:
    int width;
    int height;
    QImage _img;
    std::vector<int> data;
};

#endif // MAT_H
