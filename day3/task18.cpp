#include <iostream>

const double PI = 3.14;

template <typename T>
class Shape{
    public:
        virtual double calculateArea() const = 0;
        virtual ~Shape() = default;
};

template <typename T>
class Circle:public Shape<T>{
    private:
        T radius;
    public:
        Circle(T r):radius(r){}
        double calculateArea() const override{
            return PI*radius*radius;
        }
};

template <typename T>
class Rectangle:public Shape<T>{
    private:
        T width;
        T height;
    public:
        Rectangle(T w,T h):width(w),height(h){}
        double calculateArea() const override{
            return width*height;
        }
};

int main(){
    Rectangle<double> rec(4,5);
    Circle<int> ob(10);

    std::cout<<"Area of rectangle is "<<rec.calculateArea()<<std::endl;
    std::cout<<"Are of circle is "<<ob.calculateArea()<<std::endl;
    return 0;
}