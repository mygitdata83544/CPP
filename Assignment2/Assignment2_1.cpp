/*Q1. Write a menu driven program to calculate volume of the box(length * width * height).
Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
Create the local objects in respective case and call the function to caluclate area.
Menu options ->
1. Calculate Volume with default values
2. Calculate Volume with length,breadth and height with same value
3. Calculate Volume with different length,breadth and height values.*/


#include<iostream>
using namespace std;

class box
{
 private:
    int LENGTH;
    int WIDTH;
    int HEIGHT;

 public:
 box()   //parameterless Constructor
 {
    LENGTH=1;
    WIDTH=1;
    HEIGHT=1;   
 }

 box(int length, int width, int height)  //paramitertized Constructor
 {
    LENGTH=length;
    WIDTH=width;
    HEIGHT=height; 
 }

 box(int a)  // single paramiterized constructor
 {
    LENGTH=WIDTH=HEIGHT=a;

 }

 void volume()
 {
   int v=LENGTH*WIDTH*HEIGHT;
   cout<<"Volume:"<<v<<endl;
 }


};


int main()
{
    int choice;
    box A1;
    box A2(6);
    box A3(2,3,5);

   // A1.volume();
    //A2.volume();
    //A3.volume();

    do
    {
        cout<<"0. To Exit:"<<endl;
        cout<<"1. Calculate Volume with default values"<<endl;
        cout<<"2. Calculate Volume with length,breadth and height with same value"<<endl;
        cout<<"3. Calculate Volume with different length,breadth and height values."<<endl;
        cout<<"Enter your Choice:"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 0:
                   cout<<"Thank you!"<<endl;
                   break;

            case 1:
                  A1.volume();
                  break;

            case 2:
                  A2.volume();
                  break;

            case 3:
                  A3.volume();
                  break;

            default:
                   cout<<"Wrong input"<<endl;
                   break;
        }

    } while (choice!=0);
    

    return 0;
}