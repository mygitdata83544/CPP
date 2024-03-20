#include<iostream>
using namespace std;

class student
{
   private:
        int RollNO;
        string Name;
        double marks;


    public:
         void initStudent()
         {
            RollNO=0;
            Name="Harshal";
            marks=100;

            cout<<"Initial value\n RollNo:"<<RollNO<<"\nName:"<<Name<<"\nMarks"<<marks<<endl;

         }


         void acceptStudentFromConsole()
         {
             cout << "Enter roll no:";
             cin >> RollNO;
             cout << "Enter name:";
             cin >> Name;
             cout << "Enter marks:";
             cin >> marks;

         }
  

         void printStudentOnConsole()
         {
            cout << "Rollno:"<<RollNO<< endl;
            cout << "Name :"<< Name<<endl;
            cout << "Marks:"<< marks << endl;

         }
};

int main()
{
    student a;
    int choice;


  do
  {
    cout<<"0. To Exit"<<endl;
    cout<<"1. To Accept student Information"<<endl;
    cout<<"2. To Display student information"<<endl;
    cout<<"3. To initial student information"<<endl;
    printf("Enter your choice:\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0:
               printf("Thank you!\n");
               break;

        case 1:
               a.acceptStudentFromConsole();
               break;

        case 2:
               a.printStudentOnConsole();
            
        break;

        case 3:
               a.initStudent();
               break;     

        default:
              printf("Wrong input");
              break;       

    }

  }while(choice!=0);

  return 0;


}
