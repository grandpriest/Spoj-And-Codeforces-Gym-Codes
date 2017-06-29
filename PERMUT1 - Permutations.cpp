//PERMUT1 - Permutations
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1<<12][101];
ll N,K;
ll fun(ll mask,ll remain)
{
	if(mask==((1<<N)-1))
	{
		if(remain==0)
		return 1;
		else
		return 0;
	}
	if(dp[mask][remain]!=-1)
	return dp[mask][remain];
	ll temp=0;
	ll i,j;
	for(i=0;i<N;i++)
	{
		if((mask&(1<<i))==0)
		{
			ll count=0;
			for(j=i+1;j<N;j++)
			{
				if((mask&(1<<j))==0)
					count++;
			}
			if(remain-count>=0)
			temp+=fun((mask|(1<<i)),remain-count);
		}
	}
	return dp[mask][remain]=temp;
}

int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		memset(dp,-1,sizeof dp);
		scanf("%lld%lld",&N,&K);
		printf("%lld\n",fun(0,K));		
	}
	return 0;
}
