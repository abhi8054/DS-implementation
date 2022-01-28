#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;

#define MAX 5

void push(int);
void pop();
void peek();
void display();
int isFull();
int isEmpty();

int stack[MAX], top=-1;

int main()
{
  int cho,data;
  system("cls");
  while(1)
  {
   cout<<"1: PUSH ELEMENT "<<endl;
   cout<<"2: POP ELEMENT "<<endl;
   cout<<"3: PEEK ELEMENT "<<endl;
   cout<<"4: DISPLAY ELEMENT "<<endl;
   cout<<"5: EXIT !"<<endl;
   cout<<"ENTER YOUR CHOICE: "<<endl;
   cin>>cho;
   switch(cho)
   {
    case 1: cout<<"Enter an element you want to push: "<<endl;
	    cin>>data;
	    push(data);
	    cout<<endl;
	    break;

    case 2: pop();
	    cout<<endl;
	    break;

    case 3: peek();
	    cout<<endl;
	    break;

    case 4: display();
	    cout<<endl;
	    break;

    case 5: cout<<"The program is Exited.... press ENTER key... "<<endl;
	    getch();
	    exit(1);
   }
   getch();
  }
  return 0;
}

void push(int ele)
{
  if(isFull())
    cout<<"The stack is overflow..... "<<endl;
  else
  {
    top++;
    stack[top]=ele;
   cout<<"An element is pushed successfully."<<endl;
  }
}

void pop()
{
  int ele;
  if(isEmpty())
    cout<<"The stack is underflow......"<<endl;
  else
  {
    ele=stack[top];
      top--;
    cout<<"The poped element is "<<ele<<endl;
  }
}

void peek()
{
  if(isEmpty())
     cout<<"The stack is underflow......"<<endl;
  else
     cout<<"The top element is "<<stack[top]<<" ."<<endl;

}

void display()
{
 int i;
  if(isEmpty())
     cout<<"The stack is underflow......"<<endl;
  else
  {
     cout<<"The updated stack elements are: "<<endl;
     for(i=top;i>=0;i--)
     {
       cout<<"Element = "<<stack[i]<<endl;
     }
  }
}

int isFull()
{
  if(top==MAX-1)
    return 1;
  else
    return 0;
}

int isEmpty()
{
  if(top==-1)
    return 1;
  else
    return 0;
}
