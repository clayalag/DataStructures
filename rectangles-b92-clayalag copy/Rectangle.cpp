//
// Created by rarce on 02/08/20.
//

#include "Rectangle.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

Rectangle::Rectangle() : x0(0), y0(0), x1(0), y1(0) {

}
 Rectangle:: Rectangle(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1) {

}

int Rectangle::area() {
    return (abs(x1 - x0) * abs(y1 - y0));
}

int Rectangle::perimeter() {
 return (2 * (abs(x1 - x0) + abs(y1 - y0)));
}

bool Rectangle::operator<(Rectangle &a) {
    int midx = x1/2 + x0/2;
    int midy = y1/2 + y0/2;
    int amidx = a.x1/2 + a.x0/2;
    int amidy = a.y1/2 + a.y0/2;
    int dist1 = sqrt(midx*midx + midy*midy);
    int dist2 = sqrt(amidx*amidx + amidy*amidy);
    return (dist1 < dist2);
}

Rectangle Rectangle::operator+(Rectangle &a) {
    int minx=0, miny=0, maxx=0, maxy=0;
    int size = 4;
    int x[]={x0, x1, a.x0, a.x1};
    int y[]={y0, y1, a.y0, a.y1};
    
    for (int i = 0; i < (size-1); i++){
        int minInd = i;
        int minValX = x[i];
        for (int j = i + 1; j < size; j++){
            if (x[j] < minValX){
                minValX = x[j];
                minInd = j;
            }
        }
        x[minInd] = x[i];
        x[i] = minValX;
    }
    for (int i = 0; i < (size-1); i++){
        int minInd = i;
        int minValY = y[i];
        for (int k = i + 1; k < size; k++){
            if (y[k] < minValY){
                minValY = y[k];
                minInd = k;
            }
        }
        y[minInd] = y[i];
        y[i] = minValY;
    }
    minx = x[0];
    maxx = x[size-1];
    miny = y[0];
    maxy = y[size-1];
    return Rectangle(minx,miny,maxx,maxy);
}

void Rectangle::scale(int factor) {
    int dist1 = sqrt(x0*x0 + y0*y0);
    int dist2 = sqrt(x1*x1 + y1*y1);
    if (dist1 > dist2){
        x0 = x1 * factor;
        y0 = y1 * factor;
    }
    else {
        x1 = x0 * factor;
        y1 = y0 * factor;
    }
}

void Rectangle::display() {
    cout << "(" << x0 << ", " << y0 << ")" << "(" << x1 << ", " << y1 << ")\n";
}
