//TWENDS - Two Ends
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1234];
ll dp[1234][1234];
ll fun(ll start,ll end)
{
	if(start>end)
	return 0;
	if(dp[start][end]!=-1)
	return dp[start][end];
	ll temp=0;
	if(arr[start+1]>=arr[end])
	temp=max(temp,arr[start]+fun(start+2,end));
	else
	temp=max(temp,arr[start]+fun(start+1,end-1));
	if(arr[start]<=arr[end-1])
	temp=max(temp,arr[end]+fun(start,end-2));
	else
	temp=max(temp,arr[end]+fun(start+1,end-1));
	return dp[start][end]=temp;
}
int main()
{
	ll N;
	ll test=0;
	while(1)
	{
		memset(dp,-1,sizeof dp);
		memset(arr,0,sizeof arr);
		scanf("%lld",&N);
		ll sum=0;
		if(N==0)
		break;
		ll i,j;
		for(i=0;i<N;i++)
		{
			scanf("%lld",&arr[i]);
			sum+=arr[i];	
		}
		ll ans=fun(0,N-1);
		test++;
		printf("In game %lld, the greedy strategy might lose by as many as %lld points.\n",test,2*ans-sum);
	}
	return 0;
}
