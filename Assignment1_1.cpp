#include<stdio.h>
struct Date
{
    int day;
    int month;
    int year;
};
void initDate(struct Date *ptrDate)
{
    ptrDate->day=00;
    ptrDate->month=00;
    ptrDate->year=00;
    printf("\nInitial date:%d:%d:%d",ptrDate->day,ptrDate->month,ptrDate->year);

}


void acceptDateFromConsole(struct Date *ptrDate)
{
  printf("\nEnter Day:\n");
    scanf("%d%d%d",&ptrDate->day,&ptrDate->month,&ptrDate->year);
}
void printDateOnConsole(struct Date *ptrDate)
{
    printf("Date: %d:%d:%d",ptrDate->day,ptrDate->month,ptrDate->year);

}

int main()
{
  struct Date a;
  int choice;
  //initDate(&a);
  //acceptDateFromConsole(&a);
  //printDateOnConsole(&a);

  do
  {
    printf("\n0. Exit\n");
    printf("1.initial Date\n");
    printf("2. Display Date\n");
    printf("3. Accept Date\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0:
               printf("Thank you!\n");
               break;

        case 1:
               initDate(&a);
               break;

        case 2:
               printDateOnConsole(&a);
        break;

         case 3:
               acceptDateFromConsole(&a);
               break;

        default:
              printf("Wrong input");
              break;       

    }

  }while(choice!=0);

  return 0;


}