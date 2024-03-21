/*Q1. Write a class to find volume of a Cylinder by using following members. (volume of
Cylinder=3.14 * radius * radius *height) ( use static wherever needed. hint-PI)
Class having following member functions:
Cylinder()
Cylinder(double radius, double height)
getRadius()
setRadius()
getHeight()
setHeight()
getVolume()
printVolume()
Initialize members using constructor member initializer list.
Optional – Use the Modular Apporach*/


#include<iostream>
using namespace std;

class Cylinder
{
    private:
       double radius;
       double height;

    public:
      Cylinder(): radius(1), height(1){};


      Cylinder(double a, double b): radius(a),height(b){}

      double getradius()
      {
        return radius;
      }

      void setradius(double a)
      {
        radius=a;
      }


       double getheight()
      {
        return height;
      }

      void setheight(double b)
      {
        height=b;
      }


      double getVolume()
      {
        return 3.14*radius*radius*height;
      }

     void printVolume()
      {
        cout<<"Volume of Cylinder:"<<getVolume()<<endl;
      }
};

//const double Cylinder:: PI=3.14;

int main()
{
    Cylinder A1;
    A1.setradius(2.3);
    A1.setheight(5.5);
    A1.printVolume();

    return 0;
}