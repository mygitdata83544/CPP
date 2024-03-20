#include<iostream>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;

void initDate()
{
    day=00;
    month=00;
    year=00;
    cout<<"\nInitial date:"<<day<<":"<<month<<":"<<year<<endl;

}


void acceptDateFromConsole()
{
  cout<<"\nEnter Date:"<<endl;
  cin>>day>>month>>year;
}


void printDateOnConsole()
{
    cout<<"Date:"<<day<<":"<<month<<":"<<year<<endl;

}


bool isLeapYear()
{
    if((year % 4 == 0 && year % 100 !=0) || (year%400==0))
    return true;
    else
    return false;
}

};

int main()
{
  struct Date a;
  int choice;
  //initDate(&a);
  //acceptDateFromConsole(&a);
  //printDateOnConsole(&a);

  do
  {
    cout<<"0. To Exit"<<endl;
    cout<<"1. To Accept Date"<<endl;
    cout<<"2. To Display Date"<<endl;
    cout<<"3. To initial Date"<<endl;
    cout<<"4. To find Leap Year"<<endl;
    printf("Enter your choice:\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0:
               printf("Thank you!\n");
               break;

        case 1:
               a.acceptDateFromConsole();
               break;

        case 2:
               a.printDateOnConsole();
               a.isLeapYear();
        break;

        case 3:
               a.initDate();
               break;

        case 4:
              if(a.isLeapYear())
                cout<<"Leap Year"<<endl;
              else
                cout<<"Normal Year"<<endl;
              break;       

        default:
              printf("Wrong input");
              break;       

    }

  }while(choice!=0);

  return 0;


}