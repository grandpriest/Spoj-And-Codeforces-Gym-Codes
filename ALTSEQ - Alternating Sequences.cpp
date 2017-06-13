//ALTSEQ - Alternating Sequences
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
ll dp[5123];
ll arr[5123];
ll fun(ll idx)
{
	if(idx==N)
	return 0;
	if(dp[idx]!=-1)
	return dp[idx];
	ll temp=0;
	ll i,j;
	for(i=idx+1;i<N;i++)
	{
		if(arr[idx]*arr[i]<0 && abs(arr[idx])<abs(arr[i]))
				temp=max(temp,1+fun(i));
	}
	return dp[idx]=temp;
}

int main()
{
	scanf("%lld",&N);
	ll i,j;
	for(i=0;i<N;i++)
	scanf("%lld",&arr[i]);
	memset(dp,-1,sizeof dp);
	ll ans=0;
	for(i=0;i<N;i++)
	ans=max(ans,1+fun(i));
	printf("%lld",ans);
	return 0;
}
