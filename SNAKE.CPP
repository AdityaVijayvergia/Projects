#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<time.h>
#include<stdlib.h>

int snake[40][2],point[20][2],dead[200][2],nd,len,n=20,m=39,pos[2];
void create()
{
   int i;
   len=5;
   srand(time(NULL));
   for(i=0;i<len;i++)
       {
	 snake[i][1]=i;
       }
   for(i=0;i<20;i++)
      {
	 point[i][0]=rand() %20;
	 point[i][1]=rand() %40;
      }
   srand(time(NULL));
   for(i=0;i<nd;i++)
      {
	 dead[i][0]=rand() %20;
	 dead[i][1]=rand() %40;
      }
}

int found(int x,int y)
{
for(int i=0;i<len;i++)
   if(snake[len-1][0]==x&&snake[len-1][1]==y)
     return 2;

   else if(snake[i][0]==x&&snake[i][1]==y)
     return 1;
return 0;
}

int ifdead(int x,int y)
{

   for(int j=0;j<nd;j++)
   if(dead[j][0]==x&&dead[j][1]==y)
       return 1;
   return 0;
}
int ifpoint(int x,int y)
{
   for(int i=0;i<20;i++)
   {
   if(point[i][0]==x&&point[i][1]==y)
      return 1;
   }
   return 0;
}

void show()
{
   clrscr();
   cout<<"\n";
   for(int k=0;k<m+1;k++)
   cout<<"__";
   cout<<"\n";
   for(int i=0;i<n;i++)
   {
   cout<<"|";
   for(int j=0;j<m;j++)
   {
       if(found(i,j)==2)
       cout<<" m";
       else if(found(i,j)==1)
       cout<<" o";
       else if(ifpoint(i,j))
       cout<<" *";
       else
       if(ifdead(i,j))
       cout<<" X";
       else
       cout<<"  ";
   }
   cout<<"|";
   }
   for(k=0;k<m+1;k++)
   cout<<"__";
}

void changepoint(int x,int y)
{
   for(int i=0;i<20;i++)
   if(point[i][0]==x&&point[i][1]==y)
   {
       point[i][0]=-1;
       point[i][1]=-1;
   }
}


void move(int x,int y)
{
    x=(x+n)%n;
    y=(y+m)%m;
    if(ifpoint(x,y))
    {
	 pos[0]=x;
	 pos[1]=y;
	 changepoint(x,y);

    }
    else
    if(ifdead(x,y))
    {
      clrscr();
      cout<<"\n\n\n\t\tGAME OVER\n\n\t\tScore:"<<len-5;

      getch();
      exit(0);
    }
    for(int i=0;i<len-1;i++)
    for(int j=0;j<2;j++)
       snake[i][j]=snake[i+1][j];
    snake[i][0]=x;
    snake[i][1]=y;
    show();

    if(snake[len-1][0]==pos[0]&&snake[len-1][1]==pos[1])
    {
	len++;
	 if(len-5==20)
	 {
	    clrscr();
	    cout<<"\n\n\n\t\tVICTORY";
	    exit(0);
	 }
	for(i=len-1;i>0;i--)
	for(j=0;j<2;j++)
	    snake[i][j]=snake[i-1][j];
	snake[0][0]=pos[0];
	snake[0][1]=pos[1];
	pos[0]=-1;
	pos[1]=-1;
    }
}

void menu()
{
   int choice;
   cout<<"\n\n\tSANKE GAME";
   cout<<"\n\n\n1.easy\n2.normal\n3.hard";
   cin>>choice;
   switch(choice)
   {

   case 1:nd=50;
	  break;
   case 2:nd=125;
	  break;
   case 3:nd=200;
	  break;
   }
}

void main()
{
    clrscr();
    menu();
    create();
    show();
    pos[0]=-1;
    pos[1]=-1;
    char m;
    while(1)
    {
    cout<<"\n\t\t";
    cout<<"enter choice:";
    cin>>m;
    switch(m)
    {
    case 'd':move(snake[len-1][0],snake[len-1][1]+1);
	     break;
    case 'w':move(snake[len-1][0]-1,snake[len-1][1]);
	     break;
    case 's':move(snake[len-1][0]+1,snake[len-1][1]);
	     break;
    case 'a':move(snake[len-1][0],snake[len-1][1]-1);
	     break;
    case 'p':exit(0);
    }
    }
}