#include <iostream>


const double PI = 3.14;

class Shape{
    public:
        virtual double calculateArea() const = 0;

};

class Circle:public Shape{
    private:
        int radius;
    public:
        Circle(int r):radius(r){}

        double calculateArea() const override{
            return PI*(radius*radius);
        }
        
};

class Rectangle:public Shape{
    private:
        int height;
        int width;
    public:
        Rectangle(int h,int w):height(h),width(w){}

        double calculateArea() const override{
            return (width*height);
        }
};

void printArea(Shape* ob){
    std::cout<<"Area = "<<ob->calculateArea()<<std::endl;
}

int main(){
    Rectangle rec(10,20);
    Circle circle(50);

    printArea(&rec);
    printArea(&circle);
    return 0;
}
