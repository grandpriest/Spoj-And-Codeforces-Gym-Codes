//ASSIGN - Assignments
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)

ll dp[1<<20];
ll N;
ll arr[20][20];

ll fun(ll mask)
{

	ll now=__builtin_popcount(mask);
	if(now==N)
		return 1;
	if(dp[mask]!=-1)
		return dp[mask];
	ll temp=0;
	ll i,j;
	for(i=0;i<N;i++)
	{
		if((mask&(1<<i))==0 && arr[now][i]==1)
			temp+=fun((mask|(1<<i)));
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
	scanf("%lld",&N);
	fill(dp,-1);
	fill(arr,0);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%lld",&arr[i][j]);
	}
	printf("%lld\n",fun(0));
}
return 0;
}

