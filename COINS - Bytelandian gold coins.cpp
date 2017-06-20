//COINS - Bytelandian gold coins
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[123456789];

ll fun(ll num)
{
	if(num>=123456789)
	return max(num,fun(num/2)+fun(num/3)+fun(num/4));
	else
	{
		if(dp[num]!=-1)
		return dp[num];
		return dp[num]=max(num,fun(num/2)+fun(num/3)+fun(num/4));
	}
}

int main()
{
	ll N;
	memset(dp,-1,sizeof dp);
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	while(cin>>N)
	printf("%lld\n",fun(N));
	return 0;
}

