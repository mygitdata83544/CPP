#include<iostream>
using namespace std;

class Stack
{
   private:
   int size;
   int top;
   int *ptr;

 public:

 Stack(int size=5)
 {
  this->size=size;
  top = -1;
  ptr = new int(size);
 }

 void push(int element)
 {
    if(!isFull())
    {
        ptr[++top] = element;
    }

    else 
       cout<<"Stack Overflow"<<endl;
 }

 void pop()
 {
    if(!isEmpty())
    top--;

    else
    cout<<"Stack is Underflow"<<endl;
 }

 void peek()
 {
    if(isEmpty())
    cout<<"Stack is Empty"<<endl;
   
   else
    cout<<ptr[top]<<endl;
    }

 void print()
 {
    if(isEmpty())
    cout<<"Stack is Empty"<<endl;

    else
    {
        cout<<"Stack Element:"<<endl;
        for(int i=top; i>=0; i--)
        cout<<ptr[i]<<endl;
    }
 }

 bool isFull()
 {
    return top==(size-1);
 }

 bool isEmpty()
 {
    return top == -1;
 }

 ~Stack()
 {
    delete[] ptr;
    ptr = NULL;
 }

};

int main()
{
   /* 
   Stack S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.print();
    S.pop();
    S.print();
    return 0;
    */
    Stack S;
    int choice, element, size;
    cout<<"Enter size of stack:"<<endl;;
    cin>>size;
    Stack ptr(size);

    do {
        cout<<"0. Exit"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Print Stack"<<endl;
        cout<<"5. Check if Stack is Empty"<<endl;
        cout<<"6. Check if Stack is Full"<<endl;
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice)
         {

            case 0:
                cout << "Thank you!" << endl;
                break;
            case 1:
                cout << "Enter element to push: ";
                cin>>element;
                S.push(element);
                break;
            case 2:
                S.pop();
                break;
            case 3:
                cout<<"Top element is:"<<endl;;
                S.peek();
                break;
            case 4:
                S.print();
                break;
            case 5:
                if(S.isEmpty())
                  cout<<"Stack is Empty"<<endl;

                  else
                   cout<<"Stack is not Empty"<<endl;
                break;
            case 6:
                if(S.isFull())
                cout<< "Stack is Full"<<endl;
                else
                cout<<"Stack is not full"<<endl;
                break;
            default:
                cout << "Invalid choice" <<endl;
        }
    } while (choice != 0);

    return 0;
}

