#include <stdio.h>
#include <string.h>
#define CONS 23102009
long int number;
char x[1010],y[1010];
long d[1010][1010];
int c[1010][1010];
int
lcs(char x[],char y[],int c[][1010])
{
int m,n,i,j;
m=strlen(x);
n=strlen(y);
for(i=1;i<=m;i++)
c[i][0]=0;
for(j=0;j<=n;j++)
c[0][j]=0;
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
{
 if(x[i-1]==y[j-1])
 {
    c[i][j]=c[i-1][j-1]+1;
 }
 else if(c[i-1][j]>=c[i][j-1])
 {
   c[i][j]=c[i-1][j];
 }
 else
 {
   c[i][j]=c[i][j-1];
 }
}
return c[m][n];
}

long int distinct(int i,int j)
{
if(i<=0||j<=0)
   return 1;
if(d[i][j]!=-1)
   return d[i][j];

d[i][j]=0;
if(x[i-1]==y[j-1])//
   d[i][j]=distinct(i-1,j-1);
else//else if(c[i][j]!=0)
{
   if(c[i][j]==c[i-1][j])
      d[i][j]+=distinct(i-1,j);

   if(c[i][j]==c[i][j-1])
      d[i][j]+=distinct(i,j-1);

   if(c[i][j]==c[i-1][j-1])
      d[i][j]-=distinct(i-1,j-1);
}
return (d[i][j]+CONS)%CONS;
}

int main()
{
#ifndef ONLINE_JUDGE
     freopen("inp.txt", "r", stdin);
 #endif
 int no_test;
 int m,n;
 int i,j;
 scanf("%d",&no_test);
 while(no_test--)
 {
    scanf("%s",x);
    scanf("%s",y);
    m=strlen(x);
    n=strlen(y);

    for(i=0;i<=m;i++)
    for(j=0;j<=n;j++)
    d[i][j]=-1;

    if(lcs(x,y,c))
    {
      printf("%d %ld\n",c[m][n],distinct(m,n));
    }
    else
    printf("%d %ld\n",0,0l);
 }
 return 0;
}


