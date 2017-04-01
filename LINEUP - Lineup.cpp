//LINEUP - Lineup
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)

ll dp[1<<11];
ll arr[11][11];

ll fun(ll mask)
{
	ll now=__builtin_popcount(mask);
	if(now==11)
		return 0;
	if(dp[mask]!=-1)
		return dp[mask];
	ll temp=-INF;
	ll i,j;
	for(i=0;i<11;i++)
	{
		if(arr[now][i]>0 && (mask&(1<<i))==0)
			temp=max(temp,arr[now][i]+fun((mask|(1<<i))));
	}
	return dp[mask]=temp;
}

int main()
{
ll i,j;
ll T;
scanf("%lld",&T);
while(T--)
{
	for(i=0;i<11;i++)
		for(j=0;j<11;j++)
			scanf("%lld",&arr[i][j]);
	fill(dp,-1);
	printf("%lld\n",fun(0));
}
return 0;
}

