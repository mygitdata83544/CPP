#include<iostream>
using namespace std;

enum EAccountType
{
    SAVING=1,CURRENT,DMAT
};

class inSufficientFundException
{

private:

    int accno;
    double currentBalance;
    double withDrawAmount;

public:
    inSufficientFundException( int accno, double currentBalance, double withDrawAmount)
    {
        this->accno=accno;
        this->currentBalance=currentBalance;
        this->withDrawAmount=withDrawAmount;
    }
    void displayEx()
    {
        cout<<endl;
        cout<<"INSUFFICIENT BALANCE::"<<endl;

        cout<<"FOR ACCNO : "<<accno<<"CURRENT BALANCE IS :  "<<currentBalance<<"YOU WANT TO WITHDRAW :   "<<withDrawAmount<<endl;
    }
    ~inSufficientFundException(){}

};

class account
{

private:
    
    int accno;
    EAccountType a;
    double balance;


public:
    account()
    {
      this->accno=0;
      this->balance=0;
      this->a=EAccountType(1);
    }
    account( int accno, EAccountType a, double balance)
    {
      this->accno=accno;
      this->balance=balance;
      this->a=a;
    }
    void accept()
    {
        int i;
        cout<<"enter accno : ";
        cin>>accno;
        cout<<"enter ACCOUNT type : 1. SAVING   2.CURRENT  3.DMAT "<<endl;
        cin>>i;

        a=EAccountType(i);  
        cout<<"enter balance : ";

        cin>>balance;
    }
    void display()
    {
        cout<<"accno :"<<accno<<endl;
        if (a == EAccountType(1))
        {
            cout<<"account type : SAVING"<<endl;
        }
        else if (a == EAccountType(2))
        {
            cout<<"account type : CURRENT"<<endl;
        }
        else
        {
             cout<<"account type : DMAT"<<endl;
        }
        cout<<" balance : "<<balance<<endl;
        
    }
    void deposit(double amount)
    {
        cout<<"balance before deposit = "<<balance<<endl;
        balance=balance+amount;
        cout<<"current balance = "<<balance<<endl;
    }
    void withdraw(double amount)
    {  
        if((balance-amount)<0)
          throw inSufficientFundException(getaccno(),getBalance(),amount);

        cout<<"balance before withdraw = "<<balance<<endl;
        balance=balance-amount;
        cout<<"balance after withdrawing = "<<balance<<endl;
    }
    int getBalance()
    {
        return balance;
    }
    int getaccno()
    {
        return accno;
    }

    ~account(){}
    
};

int main()
{
    // account a;
    // a.accept();
    // a.display();

    account *a[5];
    int choice;
    int index=0;

    do
    {
        cout<<"0.EXIT "<<endl;   
        cout<<"1. CREATE ACCOUNT"<<endl;   
        cout<<"2. DISPLAY ACCOUNT"<<endl;     
        cout<<"3. DEPOSITE"<<endl;     
        cout<<"4.WITHDRAW"<<endl;
        cout<<"enter choice : ";
        cin>>choice;

        switch (choice)
        {
        case 0:
            cout<<"THANK YOU"<<endl;
            break;

         case 1:
            if (index<5)
            {
                a[index] = new account();
                a[index] -> accept();
                index++;
            }
            
            break;

         case 2:
             {
                for (int i = 0; i < index; i++)
                {
                    a[i]-> display();    
                }
                
             }
      
            break;

         case 3:
          {
            int no;
            double amount;

            try
            {
            cout<<"enter account number : "<<endl;
            cin>>no;
            int flag=1;
            for (int i = 0; i < index; i++)
            {
                if (no==a[i]->getaccno())
                {
                    flag=0;
                }
                
            }
            if (flag==1)
            {
                throw 2.5;
            }
            
            
                    try
                    {

                            cout<<"enter amount : ";
                            cin>>amount;

                            if (amount<=0)
                            {
                                throw 1;
                            }

                            for (int i = 0; i < index; i++)
                            {
                                if (no==a[i]->getaccno())
                                {
                                    a[i]->deposit(amount);

                                }
                                break;
                                
                            }
                    


                    }
                    catch(int)
                    {
                        cout<<"deposit failed"<<endl;
                        cout<<"amount cannot be negative"<<endl;
                    }
            
           


          }
        
          catch(double)
          {
            cout<<"enter a valid account number"<<endl;
          }
          }
      
            break;

         case 4:
         {
            int no;
            double amount;


            try
            {
            cout<<"enter account number : "<<endl;
            cin>>no;
            int flag=1;
            for (int i = 0; i < index; i++)
            {
                if (no==a[i]->getaccno())
                {
                    flag=0;
                }
                
            }
            if (flag==1)
            {
                throw 2.5;
            }

            cout<<"enter amount : ";
            cin>>amount;

            try
            {

             for (int i = 0; i < index; i++)
                    {
                        if (no==a[i]->getaccno())
                        {
                            a[i]->withdraw(amount);
                        }
                        
                    }
            }
            catch(inSufficientFundException e)
            {
                e.displayEx();
            }
         }
         catch(double)
         {
            cout<<"enter a valid account number"<<endl;
         }
      
            break;
        
        default:
            cout<<"enter a valid choice"<<endl;
            break;
        }
        

    } 
    }while(choice!=0);
    

    return 0;
}
