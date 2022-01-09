#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>
#define MAX 30
#define MALLOC(p,s,t)\
	p=(t)malloc(s);\
	if(p== NULL)\
	  {   \
	     printf("Insufficient memory \n");\
	     exit;\
	  }
struct List
{
    char Name[MAX];
    int quantity;
    struct List *link;
};

void Main_UI();
void Admin_UI();
void Customer_UI();
void Display_Car_List();
void Pending_Orders();
void Add_Car(char[]);
void Dequeue(char[]);
void Initialization();

typedef struct List *Node;
Node start;
char s[30][30];
char q[MAX][MAX];
int OrderCount = 0;
int CarCount = 0;
int done = 0;
int top = 0;
int front = 0;
int rear = -1;

int choice;

int main()
{
    start=NULL;
    start->link =NULL;
    Initialization();
    while(done == 0)
    {
      Main_UI();
    }
   return 0;
}



void Main_UI()
{
 // clrscr();
 printf("\t\t\t\tBSH CAR SHOWROOM\t\t\n");
 printf("--------------------------------------------------------------------------\n");
 printf("1. Adminstrative Access\n");
 printf("2. Customer Access\n\n");
 printf("3. Exit\n\n");
 printf("Enter your Choice : ");
 scanf("%d",&choice);
 switch(choice)
    {
       case 1 : Admin_UI();
		break;
       case 2 : Customer_UI();
		break;
       case 3 : done=1;;
		break;

       default: printf("Invalid Choice");

    }

}

void Admin_UI()
{
  int y = 0;
  char name[MAX];
 while(y==0)
  {
  clrscr();
  printf("\t\t\t\tBSH CAR SHOWROOM\t\t\n");
  printf("--------------------------------------------------------------------------\n");
  printf("1. Available Car List\n");
  printf("2. Pending Orders\n");
  printf("3. Last Sold Car\n");
  printf("4. Add New Car\n\n");
  printf("5. Back \n\n");
  printf("Enter your Choice : ");
  scanf("%d",&choice);

  switch(choice)
  {
       case 1 : Display_Car_List();
	       getch();
				  break;
       case 2 : Pending_Orders();
				  break;
       case 3 : printf("The last sold car is : %s ",s[top]);
		getch();
		break;
       case 4 : printf("Name : ");
		scanf("%s",name);
		Add_Car(name);
				break;
       case 5 : y = 1;
				break;
       default: printf("Invalid Choice");

  }
  }
}

void Customer_UI()
{
    int x =0,c_choice,i;
    char c;
    Node cur;

     while(x==0)
    {
    clrscr();
    cur = start;
    printf("\t\t\t\tBSH CAR SHOWROOM\t\t\n");
    printf("--------------------------------------------------------------------------\n");
    printf("1. Available Car List\n\n");
    printf("2. Back\n\n");
    printf("Enter your Choice :");
    scanf("%d",&choice);

    switch(choice)
    {
       case 1 : Display_Car_List();
		printf("Book Car w.r.t  Number : ");
		scanf("%d", &c_choice);
		if(c_choice>0 && c_choice <= CarCount)
		{
		for(i = 1 ; i< c_choice;i++)
		{
		  cur = cur->link;
		}
		printf("Confirm your order for %s (y/n) : ",cur->Name);
		scanf(" %c",&c);
		if(c == 'y')
		{
		rear = (rear+1)%MAX;
		strcpy(q[rear],cur->Name);
		OrderCount++;
		printf("Ordered placed successfully\nThank You\n");
		getch();
		}
		else
		{
		   printf("Order not placed\n ");
		   getch();
		}
		}
		else
		{
		   printf("Invalid Choice, Getting Back\n");
		   getch();
		}
				  break;
       case 2 : x = 1;
				  break;
       default: printf("Invalid Choice");

    }
    }
}
void Initialization()
{
  char Cars[5][30]={"Fortuner","Vitara Breeza","Swift","Swado","Innova"  };
  char Order[2][30]={"Vitara Breeza","Swift"};
  int i ;
  strcpy(s[top],"Nil");
  for(i =0 ;i<5;i++)
     Add_Car(Cars[i]);
  for(i=0;i<2;i++)
  {
     rear = (rear+1)%MAX;
     strcpy(q[rear],Order[i]);
     OrderCount++;
  }

}

void Display_Car_List()
{
    Node cur;
    int i;
    clrscr();
    printf("\t\t\t\tBSH CAR SHOWROOM\t\t\n");
    printf("--------------------------------------------------------------------------\n");
    cur = start;
    for( i = 1 ; cur != NULL; i++ )
    {
	printf("%d. %s \t\t : %d\n",i,cur->Name,cur->quantity);
	cur = cur->link;
    }

}

void Pending_Orders()
{
    char CurrentOrder[30];

    clrscr();
    printf("\t\t\t\tBSH CAR SHOWROOM\t\t\n");
    printf("--------------------------------------------------------------------------\n");
    printf("\nNo. of orders in Pending : %d\n",OrderCount);
    if(OrderCount == 0)
    {
	printf("\nNo Pending Orders ('-')\n");
	getch();
	return;
    }
    strcpy(CurrentOrder,q[front]);
    printf("CurrentOrder : %s\n",CurrentOrder);
    printf("1. Accept Order\n");
    printf("2. Reject Order\n\n");
    printf("3. Back\n\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
	case 1 : Dequeue(CurrentOrder);
		       break;
  case 2 : printf("Order Rejected\n");
	   front = (front + 1)%MAX;
	   OrderCount--;
	   getch();
	   return;
	case 3 : return;

	default: printf("Invalid Choice\n");

    }


}
void Dequeue(char order[])
{
   Node cur,pre;
   int flag=0;
   cur = start;
   pre = cur;
   while(cur != NULL)
   {
     if(strcmp(cur->Name,order) == 0)
     {
	 if(cur->quantity <= 1)
	 {
	   pre->link = cur->link;
	   if(start == cur)
	   {
	     start = cur->link;
	   }

	 }
	 else
	 {
	   cur->quantity--;
	 }
	  flag = 1;
	  OrderCount--;
	  front = (front+1)%MAX;
	  break;
     }
     pre = cur;
     cur = cur->link;
   }
   if(flag == 0)
   {
      printf("Out of Stock.\nRearranging the Pending orders :\n");
      rear = (rear + 1)%MAX;
      strcpy(q[rear],q[front]);
      front = (front + 1)%MAX;
      getch();
   }
   else
   {
    top = (top+1)%MAX;
    strcpy(s[top],order);
    printf("Order Accepted\n");
    CarCount--;
    getch();
   }

}

void Add_Car(char name[])
{
    Node temp,cur,pre;
    int d = 0;

    cur = start;
    MALLOC(temp,sizeof(struct List),Node);
    strcpy(temp->Name,name);
    temp->quantity = 1;
    temp->link = NULL;
    while(cur != NULL && d == 0)
    {
     if(strcmp(name,cur->Name) == 0 )
	{
	   cur->quantity++;
	   d = 1;

	}
	pre = cur;
	cur = cur->link;
    }
    if(d == 0)
    {
    CarCount++;
    if(start == NULL)
      start = temp;
    else
      pre->link = temp;
    }


}
