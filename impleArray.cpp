#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;
void display();
void insert();
void delete1();
void bubble_sort();
void binary_search();

int arr[50]={17,18,44,99,4,32,8};
int n=7;

int main()
{
int cho;
system("cls");
while(1)
{

cout<<"1 INSERT ELEMENT "<<endl;
cout<<"2 DELETE ELEMENT "<<endl;
cout<<"3 DISPLAY ELEMENT "<<endl;
cout<<"4 SORT ARRAY "<<endl;
cout<<"5 SEARCH ELEMENT "<<endl;
cout<<"6 EXIT ! "<<endl;
cout<<"Enter your choice:"<<endl;
cin>>cho;
  switch(cho)
  {
    case 1: insert();
	    break;
    case 2: delete1();
	    break;
    case 3: display();
	    break;
    case 4: bubble_sort();
	    break;
    case 5: binary_search();
	    break;
    case 6: exit(1);
    default:
	 cout<<"Invalid choice....."<<endl;
  }
}
getch();
return 0;
}

void display()
{
 int i;
 for(i=0;i<n;i++)
    cout<<"Element = "<<arr[i]<<endl;
}

void insert()
{
 int pos,i,ele;
 cout<<"Enter the element you want to insert:"<<endl;
 cin>>ele;
 cout<<"Enter the position:"<<endl;
 cin>>pos;
 for(i=n-1;i>=pos-1;i--)
 {
  arr[i+1]=arr[i];
 }
 arr[pos-1]=ele;
    n++;
 cout<<"The element is deleted successfully."<<endl;
}
void delete1()
{
 int i,ele,pos;
 cout<<"Eneter the position you want to delete:"<<endl;
 cin>>pos;
 ele=arr[pos-1];
 for(i=pos-1;i<n-1;i++)
 {
  arr[i]=arr[i+1];
 }
 n--;
 cout<<"The deleted element is "<<ele<<endl;
}

void bubble_sort()
{
  int i,j,flag,temp;
  for(i=0;i<n-1;i++)
  {
      flag=0;
    for(j=0;j<n-1-i;j++)
    {
      if(arr[j]>arr[j+1])
      {
       temp=arr[j];
       arr[j]=arr[j+1];
       arr[j+1]=temp;
       flag=1;
      }
    }
     if(flag==0)
       break;
  }
  cout<<"The list is sorted successfully"<<endl;
}

void binary_search()
{
 int i,j,mid,ele;
 cout<<"Enter the element you want to search:"<<endl;
 cin>>ele;
 i=0,j=n-1;
 while(i<=j)
 {
  mid=(i+j)/2;
  if(ele>arr[mid])
    i=mid+1;
  else if(ele<arr[mid])
    j=mid-1;
  else if(ele==arr[mid])
  {
   cout<<"The element is found successfully."<<endl;
   cout<<"The position of element is "<<mid+1<<endl;
   break;
  }
 }
 if(i>j)
   cout<<"Sorry element not found."<<endl;
}
