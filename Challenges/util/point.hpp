
#pragma once

#include <iostream>

using namespace std;

class Point{
private:
    double x;
    double y;
public:
    Point(const Point &org_point);  // COPY CONSTRUCTOR IS A MUST
    Point(double, double);
    Point();
    ~Point();
    double get_x();
    double get_y();

    friend ostream& operator<< (ostream &output, const Point &p);
    bool operator< (const Point& p);
    bool operator<= (const Point& p);
    bool operator> (const Point& p);
    bool operator>= (const Point& p);
    bool operator== (const Point& p);
    bool operator!= (const Point& p);
};
