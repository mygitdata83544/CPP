/*Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
type Date.
Cretae a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.
Employee class should be inherited from Person.
Implement following classes. Test all functionalities in main().
(Note - Perform the Association and Inheritance in the above case.)
*/
#include<iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

    public:

        Date(){}
        Date(int d, int m, int y):day(d), month(m), year(y){}

    void acceptDate()
    {
       cout<<"Enter Date in the format DD/MM/YYYY:"<<endl;
       cin>>day>>month>>year;
    }

    void displayDate()
    {
        cout<<"Date:"<<day<<"/"<<month<<"/"<<year<<endl;

    }
      

};

class Person
{
    string name;
    string address;
    Date birthdate;

    public:

    Person(){}
    Person(string n, string a, Date b): name(a), address(a), birthdate(b){}

    void acceptData()
    {
        cout<<"Enter Name and address:"<<endl;
        cin>>name>>address;
        cout<<"Enter birthdate:"<<endl;
        birthdate.acceptDate();

    }

    void displayData()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"address:"<<address<<endl;
        cout<<"birthdate:";
        birthdate.displayDate();

    }
      
};

class Employee: public Person
{
    int id;
    double salary;
    string dept;
    Date doj;

    public:

    Employee(){}
    Employee(int ID, double s, string d, Date DOJ): id(ID), salary(s), dept(d), doj(DOJ){}

    void acceptData()
    {
        cout<<"Enter join date:";
        doj.acceptDate();
        Person::acceptData();
        cout<<"Enter Employee Id,department, Salary:"<<endl;
        cin>>id>>dept>>salary;

    }

    void displayData()
    {
        doj.displayDate();
        Person::displayData();
        cout<<"Employee Id:"<<id<<endl;
        cout<<"Department:"<<dept<<endl;
        cout<<"Salary:"<<salary<<endl;
    }


};

int main()
{
    Person P;
    P.acceptData();
    P.displayData();


    Employee e;
    e.acceptData();
    e.displayData();

    Person *ptr = new Employee();
    ptr->acceptData();
    ptr->displayData();

    delete ptr;
    ptr=NULL; 

    return 0;
}