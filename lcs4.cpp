/**
* @author Gareve
* @problem
* @judge
*/
#define DEBUG
#ifndef NDEBUG	
	#define DBG(a) cout<<__LINE__<<": "<<#a<<"= "<<a<<endl;
#else
	#define DBG(a) ;
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
 
using namespace std;
 
const int MOD = 23102009;
const int X = 1009;
int la,lb;
int lcs[2][X];
int dp[2][X];
char a[X],b[X];
 
int f(int x){
	while(x<0)x+=MOD;
	return x%MOD;
}
void resuelva(){
	int x,y;
	int now=1,bef=0;
	scanf("%s%s",a,b);
	la = strlen(a);
	lb = strlen(b);
	
	for(int i=0;i<=la;i++)
	{
		swap(now,bef);
		for(int j=0;j<=lb;j++)
		{
			if(i==0 or j==0)
			{
				lcs[now][j] = 0;
				dp[now][j] = 1;
			}
			else
			{
				if(a[i-1]==b[j-1]){
					lcs[now][j] =  lcs[bef][j-1]+1;
				    dp[now][j] =  dp[bef][j-1];
				}else{
					lcs[now][j]=max(lcs[bef][j],lcs[now][j-1]);
					dp[now][j]=0;
					if(lcs[bef][j]==lcs[now][j])
						dp[now][j]=f(dp[now][j]+dp[bef][j]);
					if(lcs[now][j-1]==lcs[now][j])
						dp[now][j]=f(dp[now][j]+dp[now][j-1]);
					if(lcs[bef][j-1]==lcs[now][j])
						dp[now][j]=f(dp[now][j]-dp[bef][j-1]);
				}
			}
		}
	}
	printf("%d %d\n",lcs[now][lb],dp[now][lb]);
}
int main()
{
	#ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		resuelva();
}
 