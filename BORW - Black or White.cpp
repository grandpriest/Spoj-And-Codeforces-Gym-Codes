//BORW - Black or White
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[212][212][212];
ll N;
ll arr[212];
ll fun(ll idx,ll B,ll W)
{
	if(idx==N+1)
	return 0;
	if(dp[idx][B][W]!=-1)
	return dp[idx][B][W];
	ll temp=1+fun(idx+1,B,W);
	
	if(B==0 || arr[idx]>arr[B])
	temp=min(temp,fun(idx+1,idx,W));
	
	if(W==0 || arr[idx]<arr[W])
	temp=min(temp,fun(idx+1,B,idx));
	
	return dp[idx][B][W]=temp;
}
int  main()
{
	while(1)
	{
		ll i,j;
		scanf("%lld",&N);
		if(N==-1)
		return 0;
		memset(dp,-1,sizeof dp);
		memset(arr,0,sizeof arr);
		for(i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
		printf("%lld\n",fun(1,0,0));
	}
	return 0;
}
