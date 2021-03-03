//
// Created by rarce on 02/08/20.
//

#ifndef RECTANGLES_RECTANGLE_H
#define RECTANGLES_RECTANGLE_H


class Rectangle {
private:
    int x0, x1, y0, y1;

public:
    Rectangle();
    Rectangle(int x0, int y0, int x1, int y1);
    int area();
    int perimeter();
    bool operator<(Rectangle &a);
    Rectangle operator+(Rectangle &a);
    void scale(int factor);
    void display();
};


#endif //RECTANGLES_RECTANGLE_H
