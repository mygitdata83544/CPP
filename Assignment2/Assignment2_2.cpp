/*Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
collected. Model this tollbooth with a class called tollbooth.
The two data items are a type unsigned int to hold the total number of cars, and a type double to
hold the total amount of money collected.
A constructor initializes all data members to 0. A member function called payingCar() increments
the car total and adds 0.50 to the cash total. An other function, called nopayCar()
increments the car total but adds nothing to the cash total. Finally, a member function called
printOnConsole() displays the two totals and number of paying as well as non paying cars total.*/


#include<iostream>
using namespace std;

class tollbooth
{

 private:
       unsigned int TotalCars;
       double TotalMoney;
  
 public:
 tollbooth()
 {
    TotalCars=0;
    TotalMoney=0;
 }

 void payingCar()
 {
    TotalCars++;
    TotalMoney=TotalMoney + 0.50;
 }

 void noPayingCar()
 {
    TotalCars++;
 }

 void printOnConsole()
 {
    cout<<"Total Cars:"<<TotalCars<<endl;
    cout<<"Total Money:"<<TotalMoney<<endl;
    cout<<"Paying Cars:"<<TotalMoney/0.50<<endl;
    cout<<"Non Paying Car:"<<TotalCars-(TotalMoney/0.50)<<endl;
 }

};
int main()
{
    tollbooth A;
    A.payingCar();
    A.payingCar();
    A.noPayingCar();
    A.printOnConsole();


    return 0;
}