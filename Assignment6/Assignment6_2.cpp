/*A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.
Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]*/


#include<iostream>
using namespace std;

class Product
{
   int id;
   string title; 
   double price;

   public:

   Product(){}

   Product(int ID, string t, double p): id(ID), title(t), price(p){}
    
    virtual void accept()
    {
        cout<<"Enter Id:";
        cin>>id;
        cout<<"\nEnter Title:";
        cin>>title;
        cout<<"\nEnter Price:";
        cin>>price;
    }

    virtual void display()
    {
        cout<<"\nID:"<<id<<endl<<"Title:"<<title<<endl<<"Price:"<<price<<endl;
    }

    double getPrice()
        {
            return price;
        }
        void setPrice(double price)
        {
            this->price=price;
        }
};

class Book: public Product
{
    string author;

    public:

    Book(){}

    Book(string a): author(a){}

     void accept()
     {
        double p;
        cout<<"\nEnter author name:";
        cin>>author;

        Product::accept();
           
            p=getPrice();
            p=(p-0.1*p);
            setPrice(p);

     }

     virtual void display()
     {
        Product::display();
        cout<<"Auther:"<<author;
        cout<<"\n After 10 percent discount:"<<getPrice();
     }
     


};

class Tape: public Product
{
    string artist;

    public:

    Tape(){}

    Tape(string a):artist(a){}

    void accept()
    {
        double p;
        cout<<"Enter artist name:";
        cin>>artist;

        Product::accept();
           
            p=getPrice();
            p=(p-0.05*p);
            setPrice(p);
    }

    void display()
    {
        Product::display();
        cout<<"\nArtist:"<<artist;
        cout<<"\n After 5 percent discount:"<<getPrice();


    }
    

     
};

int main()
{
  Product *arr[3];
  int choice;
  int i=0;

  do
  {
    cout<<"0 TO EXIT"<<endl;
    cout<<"1. TO BUY BOOK"<<endl;
    cout<<"2. TO BUY TAPE"<<endl;
    cout<<"3. TO CALCULATE TOTAL"<<endl;
    cout<<"4. TO SEE ALL LIST DETAILS"<<endl;
    cout<<"enter choice : ";
    cin>>choice;

    switch(choice)
    {
        case 0:
              cout<<"Thank You"<<endl;
              break;

        case 1:
                if(i<3)
                {
                  arr[i]=new Book();
                  arr[i]->accept();
                  i++;
                }
                else
                {
                    cout<<"list is full"<<endl;
                }
              break;

        case 2:
                if(i<3)
                {
                  arr[i]=new Tape();
                  arr[i]->accept();
                  i++;
                }
                else
                {
                    cout<<"list is full"<<endl;
                }
              break;

        case 3:
               { 
                    double total=0;
                   for (int j = 0; j < i; j++)
                   {
                    total=total+arr[j]->getPrice();
                   }

                   cout<<"total is : "<<total;
                   

                }

              break;

        case 4:
              for(int j=0;j<i;j++)
                {
                    arr[j]->display();
                    cout<<endl;
                    cout<<endl;
                }

        default:
    
                  cout<<"enter right choice"<<endl;
    }
  } while (choice!=0);

  for (int n = 0; n < i; n++)
{
    delete arr[n];
    arr[n]=NULL;
}
  
    return 0;
}