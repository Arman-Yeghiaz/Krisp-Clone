#include <iostream>


const double PI = 3.14;

class Shape{
    public:
        double calculateArea() const{
            std::cout<<"Cant return the area of abstract Shape"<<std::endl;
            return 0;
        }

};

class Circle:public Shape{
    private:
        int radius;
    public:
        Circle(int r):radius(r){}

        double calculateArea() const{
            return PI*(radius*radius);
        }
        
};

class Rectangle:public Shape{
    private:
        int height;
        int width;
    public:
        Rectangle(int h,int w):height(h),width(w){}

        double calculateArea() const{
            return (width*height);
        }
};


int main(){
    Rectangle rec(10,20);
    Circle circle(50);
    std::cout<<"The are of circle is "<<circle.calculateArea()<<std::endl;
    return 0;
}
