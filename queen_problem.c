#include <stdio.h>
#include<stdlib.h>
#define N 8


bool checkvalidity(int r , int c, int column[])
{ 
  int r1,c1;
  for (int j=0;j<r;j++)
  { 
     c1=column[j];

     if (c==c1)
      return false;
     
     if(abs(r-j)==abs(c-c1))
      return false;
  }
 return true;  
}

bool queen(int column[], int n, int r) 
{
  if(r==n) {

   printf("found the solution \n");
   return true ;
  }

  for (int c = 0; c<N; c++)
  {
     if(checkvalidity(r,c,column))
      {
         column[r]=c;
         if(queen(column,n,r+1))
          return true;
      }

  }  

 return false; 
}


int main() 
{
 int n = N; 
 int column[N]; 
 queen(column,n,0);
 for (int i=0;i<n;i++)
    printf("r=%d  c=%d\n",i,column[i]);
 return 0;
}
