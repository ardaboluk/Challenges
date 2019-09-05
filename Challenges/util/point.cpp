
#include <cmath>
#include <iostream>
#include "point.hpp"

#define EPSILON 1e-10

using namespace std;

Point::Point(const Point &org_point){
    x = org_point.x;
    y = org_point.y;
}

Point::Point(double p_x, double p_y){
    x = p_x;
    y = p_y;
}

Point::Point(){
    x = 0;
    y = 0;
}

Point::~Point(){

}

double Point::get_x(){
    return x;
}
double Point::get_y(){
    return y;
}

ostream& operator<< (ostream &output, const Point &p){
    output << p.x << " : " << p.y;
    return output;
}

bool Point::operator< (const Point& p){
    if(y < p.y){
        return true;
    }else if(abs(y-p.y) < EPSILON && x < p.x){
        return true;
    }
    return false;
}

bool Point::operator<= (const Point& p){
    if(y < p.y){
        return true;
    }else if(abs(y-p.y) < EPSILON && x < p.x){
        return true;
    }else if(abs(y-p.y) < EPSILON && abs(x-p.x) < EPSILON){
        return true;
    }
    return false;
}

bool Point::operator> (const Point& p){
    if(y > p.y){
        return true;
    }else if(abs(y-p.y) < EPSILON && x > p.x){
        return true;
    }
    return false;
}

bool Point::operator>= (const Point& p){
    if(y > p.y){
        return true;
    }else if(abs(y-p.y) < EPSILON && x > p.x){
        return true;
    }else if(abs(y-p.y) < EPSILON && abs(x-p.x) < EPSILON){
        return true;
    }
    return false;
}

bool Point::operator== (const Point& p){
    if(abs(x-p.x) < EPSILON && abs(y-p.y) < EPSILON){
        return true;
    }
    return false;
}

bool Point::operator!= (const Point& p){
    if(abs(x-p.x) > EPSILON || abs(y-p.y) > EPSILON){
        return true;
    }
    return false;
}
