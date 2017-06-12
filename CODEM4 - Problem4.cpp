//CODEM4 - Problem4
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[32][32][2];
ll arr[32];

ll fun1(ll start,ll end,ll ch)
{
	if(start>end)
	return 0;
	if(dp[start][end][ch]!=-1)
	return dp[start][end][ch];
	if(ch==0)
	return dp[start][end][ch]=max(arr[start]+fun1(start+1,end,1),arr[end]+fun1(start,end-1,1));
	return dp[start][end][ch]=max(fun1(start+1,end,0),fun1(start,end-1,0));
}


ll fun2(ll start,ll end,ll ch)
{
	if(start>end)
	return 0;
	if(dp[start][end][ch]!=-1)
	return dp[start][end][ch];
	if(ch==0)
	return dp[start][end][ch]=max(arr[start]+fun2(start+1,end,1),arr[end]+fun2(start,end-1,1));
	return dp[start][end][ch]=min(fun2(start+1,end,0),fun2(start,end-1,0));
}

int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		ll i,j;
		ll N;
		scanf("%lld",&N);		
		for(i=0;i<N;i++)
		scanf("%lld",&arr[i]);
		memset(dp,-1,sizeof dp);
		printf("%lld ",fun1(0,N-1,0));
		memset(dp,-1,sizeof dp);
		printf("%lld\n",fun2(0,N-1,0));	
	}	
	return 0;
}
