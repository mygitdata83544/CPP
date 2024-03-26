#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        cout << "Inside Employee()" << endl;
    }
    Employee(int id, double salary)
    {
        cout << "Inside Employee(int,double)" << endl;
    }


    void setId(int ID)
  {
    id=ID;
  }

  int getid()
  {
    return id;
  }


  void setsalary(double s)
  {
     salary=s;
  }

  double getsalary()
  {
    return salary;
  }

    virtual void accept()
    {
        cout << "Enter the empid - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
        cout << "Inside Manager()" << endl;
    }
    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int,double,double)" << endl;
    }

    void setbonus(double b)
  {
     bonus=b;
  }

  double getbonus()
  {
    return bonus;
  }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission - " << commission << endl;
    }

public:
    Salesman()
    {
        cout << "Inside Salesman()" << endl;
    }
    Salesman(int id, double salary, double commission)
    {
        cout << "Inside Salesman(int,double,double)" << endl;
    }

    void setcommission(double c)
  {
     commission=c;
  }

  double getcommission()
  {
    return commission;
  }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout << "Inside Salesmanager()" << endl;
    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main()
{
    Employee *eptr[5];
    int i=0;
    int m=0;
    int s=0;
    int sm=0;
    int choice;

    do
    {
        cout<<"0. TO EXIT:"<<endl;
        cout<<"1. To Accept Employee:"<<endl;
        cout<<"2. Display the count of all employees with respect to designation:"<<endl;
        cout<<"3. Display All Managers:"<<endl;
        cout<<"4. Display All Salesman:"<<endl;
        cout<<"5. Display All SalesManagers:"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice)
        {
            case 0: 
                   cout<<"Thank you!"<<endl;
                 break;

            case 1:
                    int d;
                  do
                  {
                    cout<<"0. TO EXIT:"<<endl;
                    cout<<"1. To display Manager"<<endl;
                    cout<<"2. To display Salesman"<<endl;
                    cout<<"3. To display SalesManager"<<endl;
                    cout<<"Enter Your Designation:";
                    cin>>d;
                    switch(d)
                    {

                        case 0:
                              cout<<"Thank You!"<<endl;
                              break;
                      case 1:
                      {
                            if(i<5)
                            {
                             eptr[i]=new Manager();
                             eptr[i]->accept();
                             i++;
                            }

                            else
                              {
                                cout<<"array is full"<<endl;
                              }  
                      }   
                      break;

                      case 2:
                      {
                            if(i<5)
                            {
                             eptr[i]=new Salesman();
                             eptr[i]->accept();
                             i++;
                            }

                            else
                              {
                                cout<<"array is full"<<endl;
                              }  
                      }   
                      break;

                      case 3:
                      {
                            if(i<5)
                            {
                             eptr[i]=new SalesManager();
                             eptr[i]->accept();
                             i++;
                            }

                            else
                              {
                                cout<<"array is full"<<endl;
                              }   
                      } 
                      break;

                       default:
                              cout<<"Enter a valid choice"<<endl;
                              break;
                    }
                    
                    
                  } while (d!=0);
                  

                 break;

                 case 2:
                 { 
   
                  for (int n = 0; n < i; n++)
                  {
                     if(typeid(*eptr[n]).name()==typeid(Manager).name())
                  {
                    m++;
                  }
                 else if(typeid(*eptr[n]).name()==typeid(Salesman).name())
                  {
                    s++;
                  }
                 else if(typeid(*eptr[n]).name()==typeid(SalesManager).name())
                  {
                    sm++;
                  }
                  }
         cout<<"number of managers :        "<<m<<endl;
         cout<<"number of salesman :        "<<s<<endl;
         cout<<"number of salesmanager :    "<<sm<<endl;

         cout<<"total number of employees : "<<m+s+sm<<endl;
        }   
                 break;

                 case 3: 
                  {
            
                    cout<<"*****************************************************"<<endl;
                    cout<<"         information about managers      "<<endl;
            
                    int count=0;

                    for (int n = 0; n < i; n++)
                    {
                        if(typeid(*eptr[n])==typeid(Manager))
                         {
                            eptr[n]->display();
                            count++;
                            cout<<"***************************************"<<endl;
                         }
                    }

                if(count==0)
                {
                    cout<<".................THERE ARE NO MANAGERS IN THE COMPANY........................"<<endl;
                }
                
                   }
                 break;

                 case 4: 
                 {

                   cout<<"*****************************************************"<<endl;
                   cout<<"         information about salesman      "<<endl;

                   int count=0;

                    for (int n = 0; n < i; n++)
                     {

                        if(typeid(*eptr[n])==typeid(Salesman))
                         {
                           eptr[n]->display();
                           count++;
                           cout<<"***************************************"<<endl;
                         }
                     }

                    if (count==0)
                    {
                       cout<<"................THERE ARE NO SALESMAN IN THE COMPANY..........................."<<endl;
                    }
            }
                 break;

                 case 5: 
                 {

                    cout<<"*****************************************************"<<endl;
                    cout<<"         information about salesmanagers      "<<endl;

                    int count=0;
                    for (int n = 0; n < i; n++)
                     {
                       if(typeid(*eptr[n])==typeid(SalesManager))
                        {
                          eptr[n]->display();
                          count++;
                          cout<<"***************************************"<<endl;
                        }
                     }
                
                       if (count==0)
                       {
                         cout<<".................THERE ARE NO SALESMANAGERS IN THE COMPANY....................."<<endl;
                       }
                 }
                 break;

                 default:
                   cout<<"Enter a valid choice"<<endl;
        }
    } while (choice!=0);

    for(int n=0; n<i; n++)
    {
        delete eptr[n];
    }

    
}