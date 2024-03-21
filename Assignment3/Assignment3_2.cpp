/*Q2. Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
Allocate the memory for the the object dynamically and test the functunalities using time ptr.*/

#include<iostream>
using namespace std;

class Time
{
    private:
         int Hour;
         int Minute;
         int Seconds;


    public:
    Time()
    {
        Hour=0;
        Minute=0;
        Seconds=0;
    }

    Time(int h, int m, int s)
    {
        Hour=h;
        Minute=m;
        Seconds=s;
    }

    int getHour()
    {
        return Hour;
    }

    int getMinute()
    {
        return Minute;
    }


    int getSeconds()
    {
        return Seconds;
    }


    void setHour(int h)
    {
        Hour=h;
    }


    void setMinute(int m)
    {
        Minute=m;
    }

    
    void setSeconds(int s)
    {
        Seconds=s;
    }


    void printTime()
    {
        cout<<"Time:"<<Hour<<":"<<Minute<<":"<<Seconds<<endl;
    }


};

int main()
{
    Time *t1=new Time(6,20,12);

    t1->printTime();
    return 0;
}