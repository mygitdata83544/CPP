/*Q3. Write a class Address with data members (string building, string street, string city ,int pin)
Implement constructors, getters, setters, accept(), and display() methods.
Test the class functunalities by creating the object of class and calling all the functions.*/

#include<iostream>
using namespace std;

class Address
{
   private:
       string building;
       string street;
       string city;
       int pin;

    public:

    Address()
    {
      
    }
       Address(string a, string b, string c, int d) //constructor
       {
        building=a;
        street=b;
        city=c;
        pin=d;
       }

       string getbuilding() const  //getter function
       {
          return building;
       }

       string getstreet() const
       {
        return street;
       }

       string getcity() const
       {
        return city;
       }

       int getpin() const
       {
        return pin;
       }


       void setbuilding(string a)
       {
          building=a;
       }

       void setstreet(string b)
       {
          street=b;
       }

       void setcity(string c)
       {
          city=c;
       }

       void setpin(int d)
       {
          pin=d;
       }

       void accept()
       {
         cout<<"Enter building name:"<<endl;
         cin>>building;

         cout<<"Enter street Name:"<<endl;
         cin>>street;

         cout<<"Enter City Name:"<<endl;
         cin>>city;

         cout<<"Enter Pin:"<<endl;
         cin>>pin;
       }

       void display()
       {
         cout<<"building:"<<building<<endl;

         cout<<"street:"<<street<<endl;

         cout<<"City:"<<city<<endl;

         cout<<"Pin:"<<pin<<endl;
       }




};
int main()
{
   Address A;

   A.accept();
   A.display();
    return 0;
}