//AIBOHP - Aibohphobia
#include<bits/stdc++.h>
using namespace std;
#define ll int
int  N;
string str1;
string str2;
int dp[6123][6123];
ll fun(ll idx1,ll idx2)
{
	if(idx1==N || idx2==N)
	return 0;
	if(dp[idx1][idx2]!=-1)
	return dp[idx1][idx2];
	if(str1[idx1]==str2[idx2])
	return dp[idx1][idx2]=1+fun(idx1+1,idx2+1);
	return dp[idx1][idx2]=max(fun(idx1+1,idx2),fun(idx1,idx2+1));
}
int main()
{
	ll T;
	 ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		memset(dp,-1,sizeof dp);
		cin>>str1;
		str2=str1;
		N=str1.size();
		reverse(str2.begin(),str2.end());
		printf("%d\n",N-fun(0,0));	
	}
	return 0;
}
