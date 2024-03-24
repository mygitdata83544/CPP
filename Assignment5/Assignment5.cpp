/*Implement following classes. Test all functionalities in main().
Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
type date.
Cretae a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.*/


#include <iostream>
#include <string>

using namespace std;

class Date
 {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y)
    {
         day=d; 
         month=m; 
         year=y;
    }

    void display()
     {
        cout<<day<<":"<<month<<":"<< year;
     }
};

class Person 
{
private:
    string name;
    string address;
    Date birthdate;

public:
    Person(string n, string addr, Date dob) : name(n), address(addr), birthdate(dob) {}

    void display() 
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Birthdate: ";
        birthdate.display();
        cout<<endl;
    }
};

class Employee 
{
private:
    string id;
    double sal;
    string dept;
    Date joiningDate;

public:
    Employee(string empId, double salary, string department, Date joinDate)
        : id(empId), sal(salary), dept(department), joiningDate(joinDate) {}

    void display() 
    {
        cout<<"Employee ID: "<<id<<endl;
        cout<<"Salary: "<<sal<<endl;
        cout<<"Department: "<<dept<<endl;
        cout<<"Joining Date: ";
        joiningDate.display();
        cout<<endl;
    }
};

int main() 
{
    // Creating Date objects
    Date dob(15, 7, 2000);
    Date joinDate(6, 10, 2020);

    // Creating Person object
    Person person("Harshal", "Ghatanji", dob);

    // Creating Employee object
    Employee employee("1234", 70000, "IT", joinDate);

    // Displaying details
    cout << "Person Details:" << endl;
    person.display();
    
    cout << "Employee Details:" << endl;
    employee.display();

    return 0;
}
