//FARIDA - Princess Farida
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[12345];
ll arr[12345];
ll N;
ll fun(ll idx)
{
	if(idx>=N)
	return 0;
	if(dp[idx]!=-1)
	return dp[idx];
	return dp[idx]=max(fun(idx+1),arr[idx]+fun(idx+2));
}
int main()
{
	ll T;
	scanf("%lld",&T);
	ll test=0;
	while(T--)
	{
		memset(dp,-1,sizeof dp);
		memset(arr,0,sizeof arr);
		scanf("%lld",&N);
		ll i,j;
		for(i=0;i<N;i++)
		scanf("%lld",&arr[i]);
		test++;
		printf("Case %lld: %lld\n",test,fun(0));
	}
	return 0;
}
