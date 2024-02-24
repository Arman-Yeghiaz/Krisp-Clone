#include <iostream>

const double PI = 3.14;

class Shape{
    public:
        virtual double calculateArea() const {
            throw std::logic_error("no dimensions for default shape");
        };
        
};

class Rectangle:public Shape{
    private:
        int width;
        int height;
    public:
        Rectangle(int w,int h):width(w),height(h){
            if (height<=0 || width <=0){
                throw std::invalid_argument("dimensions should be positive");
            }
        }
        
        double calculateArea() const override{
            return height*width;
        }
};

class Circle:public Shape{
    private:
        int radius;
    public:
        Circle(int r):radius(r){
            if (radius<=0){
                throw std::invalid_argument("Radius must be positive");
            }
        }
        double calculateArea() const override{
            return PI*radius*radius;
        }
};

int main(){
    try{
        Circle circle(5);
        std::cout<<"Area of circle is "<<circle.calculateArea()<<std::endl;
        Circle circle2(-5);
        std::cout<<"Area of circle2 is "<<circle2.calculateArea()<<std::endl;
    } catch(const std::exception& exc){
        std::cerr<<"Exception is caughted "<<exc.what()<<std::endl;
    }
    return 0;
}