#include<stdio.h>
#include<conio.h>

void create_node();
void display();
void insert_data();
void ins_beg();
void ins_end();
void ins_anypos();
void _delete_data();
void del_beg();
void del_end();
void del_anypos();
void search();
void sort();
int length();

struct node
{
int data;
struct node *link;
};

struct node *head=NULL, *temp=NULL;

void main()
{
  int choice;
  clrscr();
   while(1)
    {
      printf("1. CREATE A LIST \n");
      printf("2. INSERT DATA \n");
      printf("3. DELETE DATA \n");
      printf("4. DISPLAY DATA \n");
      printf("5. SEARCH DATA \n");
      printf("6. EXIT ! \n");
      printf("Enter your choice: \n");
      scanf("%d",&choice);
      printf("\n");
   switch(choice)
    {
      case 1: create_node();
	      printf("\n");
	      break;
      case 2: insert_data();
	      printf("\n");
	      break;
      case 3: _delete_data();
	      printf("\n");
	      break;
      case 4: display();
	      printf("\n");
	      break;
      case 5: search();
	      printf("\n");
	      break;
      case 6: printf("The program is exited... \n");
	      getch();
	      exit(1);

      default:
	      printf("Your choice is invallid... \n");
	      printf("\n");
    }
  }
getch();
}

void create_node()
{
  int choice;
  struct node *new1;
   do
   {
    new1=(struct node*)malloc(sizeof(struct node));
    printf("The node is created: \n");
    printf("Enter the data: \n");
    scanf("%d",&new1->data);
    new1->link=NULL;
      if(head==NULL)
	head=new1;
      else
      {
	temp=head;
	while(temp->link!=NULL)
	{
	  temp=temp->link;
	}
	  temp->link=new1;
      }
    printf("Do you want to continue then press 1 otherwise 0: ");
    scanf("%d",&choice);
   }while(choice==1);
   printf("The list is created successfully. \n");
}

void display()
{
   int s;
   if(head==NULL)
     printf("Sorry ! The list is underflow, \n");
   else
   {
       temp=head;
      printf("The updated list elements are: \n");
      while(temp!=NULL)
       {
	 printf("Element = %d \n",temp->data);
	 temp=temp->link;
       }
     printf("Do you want to sort a list then press 1 otherwise press 0: \n");
     scanf("%d",&s);
     if(s==1)
     {
       sort();
       printf("The list is sorted successfully. \n");
	temp=head;
       printf("The updated list elements are: \n");
       while(temp!=NULL)
       {
	 printf("Element = %d \n",temp->data);
	 temp=temp->link;
       }
     }
   }
}

void insert_data()
{
   if(head==NULL)
     printf("Sorry ! The list is underflow, \n");
   else
   {
      int ch;
      printf("Where you want to insert: \n");
      printf("1. AT BEGINING \n");
      printf("2. AT END \n");
      printf("3. AT ANY POSITION \n");
      printf("Enter your choice: \n");
      scanf("%d",&ch);
      switch(ch)
      {
       case 1: ins_beg();
	       break;
       case 2: ins_end();
	       break;
       case 3: ins_anypos();
	       break;
       default:
		printf("Choice is invallid.. \n");
      }
  }
}

void _delete_data()
{
  if(head==NULL)
    printf("Sorry ! The list is underflow, \n");
  else
  {
    int ch;
      printf("Where you want to delete: \n");
      printf("1. AT BEGINING \n");
      printf("2. AT END \n");
      printf("3. AT ANY POSITION \n");
      printf("Enter your choice: \n");
      scanf("%d",&ch);
      switch(ch)
      {
       case 1: del_beg();
	       break;
       case 2: del_end();
	       break;
       case 3: del_anypos();
	       break;
       default:
		printf("Choice is invallid.. \n");
      }
  }
}

void search()
{
  int ele,p=0,flag=0;
   if(head==NULL)
     printf("Sorry ! The list is underflow, \n");
   else
    {
      printf("Enter the data you want to search: \n");
      scanf("%d",&ele);
      temp=head;
	while(temp!=NULL)
	 {
	   p++;
	  if(ele==temp->data)
	   {
	     printf("The data is found successfully. \n");
	     printf("The position of data in list is %d \n",p);
	     flag=1;
	   }
	  temp=temp->link;
	 }
	if(flag==0)
	  printf("Sorry ! The data is not found, \n");
     }
}



void ins_beg()
{
  struct node *new1;
  new1=(struct node*)malloc(sizeof(struct node));
  printf("The node is created: \n");
  printf("Enter the data: \n");
  scanf("%d",&new1->data);
   new1->link=NULL;
   new1->link=head;
   head=new1;
  printf("The data is inserted successfully. \n");
}

void ins_anypos()
{
  int pos,i=1;
  struct node *new1;
  new1=(struct node*)malloc(sizeof(struct node));
  printf("The node is created: \n");
  printf("Enter the data: \n");
  scanf("%d",&new1->data);
   new1->link=NULL;
  printf("Enter the position you want to insert: \n");
  scanf("%d",&pos);
   temp=head;
   while(i<pos)
   {
     temp=temp->link;
     i++;
   }
     new1->link=temp->link;
     temp->link=new1;
     printf("The data is inserted successfully. \n");
}

void ins_end()
{
  struct node *new1;
  new1=(struct node*)malloc(sizeof(struct node));
  printf("The node is created: \n");
  printf("Enter the data: \n");
  scanf("%d",&new1->data);
   new1->link=NULL;
   temp=head;
   while(temp->link!=NULL)
   {
     temp=temp->link;
   }
     temp->link=new1;
   printf("The data is inserted successfully. \n");
}

void del_anypos()
{
  int ele,pos,i=1;
  struct node *del;
  printf("Enter the position you want to delete: \n");
  scanf("%d",&pos);
   temp=head;
   while(i<pos-1)
   {
      temp=temp->link;
      i++;
   }
     del=temp->link;
     ele=del->data;
     temp->link=del->link;
     del->link=NULL;
     free(del);
   printf("The deleted data from the list is %d \n",ele);
}

void del_beg()
{
  int ele;
  struct node *del;
   del=head;
   ele=del->data;
   head=del->link;
   del->link=NULL;
   free(del);
  printf("The deleted data from the list is %d \n",ele);
}

void del_end()
{
  int ele;
  struct node *del;
   del=head;
   temp=head;
   while(del->link!=NULL)
   {
     temp=del;
     del=del->link;
   }
     ele=del->data;
     temp->link=NULL;
      free(del);
   printf("The deleted data from the list is %d \n",ele);
}

void sort()
{
 int i=1,j,k,temp1,flag;
 struct node *prv,*nxt;
 j=length();
 temp=head;
 while(i<j)
 {
   prv=temp;	
   nxt=temp->link;
   flag=0;
   k=1;
  while(k<=j-i)
  {
    if(prv->data > nxt->data)
    {
       temp1=prv->data;
       prv->data=nxt->data;
       nxt->data=temp1;
	 flag=1;
     }
     prv=prv->link;
     nxt=nxt->link;
     k++;
  }
    if(flag==0)
      break;
    i++;
 }
}

int length()
{
  int count=0;
    temp=head;
   while(temp!=NULL)
   {
     count=count+1;
     temp=temp->link;
   }
  return(count);
}
