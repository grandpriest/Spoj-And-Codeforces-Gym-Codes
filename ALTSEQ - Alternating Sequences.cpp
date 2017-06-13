//ALTSEQ - Alternating Sequences
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
ll dp[5123];
ll arr[5123];
ll fun(ll idx)
{
//	cout<<idx<<"<--idx now "<<endl;
	if(idx==N)
	return 0;
	if(dp[idx]!=-1)
	return dp[idx];
	ll temp=1;
	ll i,j;
	for(i=idx+1;i<N;i++)
	{
		if(arr[idx]*arr[i]<0 && abs(arr[idx])<abs(arr[i]))
				temp=max(temp,1+fun(i));
	}
	temp=max(temp,fun(idx+1));
//	cout<<temp<<"<--dp for idx"<<idx<<endl;
	return dp[idx]=temp;
}

int main()
{
	scanf("%lld",&N);
	ll i,j;
	for(i=0;i<N;i++)
	scanf("%lld",&arr[i]);
	memset(dp,-1,sizeof dp);
	printf("%lld",fun(0));
	return 0;
}
