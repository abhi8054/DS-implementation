#include<iostream>
#include<conio.h>
#include<process.h>

using namespace std;

#define MAX 5

int quee[MAX];
int front=-1,rear=-1;

int isFull();
int isEmpty();
void insert(int);
void _delete();
void peek();
void display();

int main()
{
 int data,cho;
 system("cls");
 while(1)
  {
    cout<<"1: Insert element \n";
    cout<<"2: Delete element \n";
    cout<<"3: Peek element \n";
    cout<<"4: Display element \n";
    cout<<"5: EXIT ! \n";
    cout<<"ENTER YOUR CHOICE: \n";
    cin>>cho;
    cout<<endl;

    switch(cho)
     {
       case 1: cout<<"Enter an element you want to insert: \n";
	       cin>>data;
	       insert(data);
	       cout<<endl;
	       break;

       case 2: _delete();
	       cout<<endl;
	       break;

       case 3: peek();
	       cout<<endl;
	       break;

       case 4: display();
	       cout<<endl;
	       break;

       case 5: cout<<"The program is Exited...press ENTER key...\n";
	       getch();
	       exit(1);
       default:
	       cout<<"You have entered WRONG choice...\n\n";
     }
    getch();
  }
  return 0;
}

void insert(int ele)
{
 if(isFull())
   cout<<"The quee is OVERFLOW.....\n";
 else
 {
   if(front==-1 && rear==-1)
   {
     front=rear=0;
     quee[rear]=ele;
     cout<<"An element "<<ele<<" is inserted successfully. \n";
   }
   else
   {
     rear++;
     quee[rear]=ele;
     cout<<"An element "<<ele<<" is inserted successfully. \n";
   }
 }
}

void _delete()
{
  int ele;
   if(isEmpty())
     cout<<"The quee is UNDERFLOW.....\n";
   else
   {
     if(front==rear)
     {
       ele=quee[front];
       front=rear=-1;
       cout<<"An element "<<ele<<" is deleted successfully.\n";
     }
     else
     {
      ele=quee[front];
       front++;
      cout<<"An element "<<ele<<" is deleted successfully.\n";
     }
   }
}

void display()
{
 int i;
  if(isEmpty())
     cout<<"The quee is UNDERFLOW.....\n";
  else
  {
    cout<<"The updated QUEE elements are: \n";
     for(i=front;i<=rear;i++)
     {
       cout<<"Element = "<<quee[i]<<endl;
     }
  }	
}	

void peek()
{
 if(isEmpty())
   cout<<"The quee is UNDERFLOW.....\n";
 else
   cout<<"The peek element is "<<quee[front]<<".\n";
}

int isEmpty()
{
  if(front==-1 && rear==-1)
    return 1;
  else
    return 0;
}

int isFull()
{
  if(rear==MAX-1)
    return 1;
  else
    return 0;
}
