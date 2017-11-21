//Matrix Cutting
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  fill(a,v)  memset(a, v, sizeof a)

ll N,M;
ll arr[45][45];
ll dp[45][45][45][45];

ll fun(ll L,ll R,ll T,ll D)
{
	if(L>R || T>D)
		return 0;
	
	if(dp[L][R][T][D]!=-1)
		return dp[L][R][T][D];
	ll small=1e18;
	ll i,j;
	for(i=T;i<=D;i++)
	{
		for(j=L;j<=R;j++)
			small=min(small,arr[i][j]);
	}
	ll temp=0;
	for(i=L;i<R;i++)//horizontal cut
	{
		ll val=fun(L,i,T,D)+small+fun(i+1,R,T,D);
		temp=max(temp,val);
	}
	for(i=T;i<D;i++)//verical cut
	{
		ll val=fun(L,R,T,i)+small+fun(L,R,i+1,D);
		temp=max(temp,val);
	}
	return dp[L][R][T][D]=temp;
}

int main()
{
	//freopen("C-small-practice.in","r",stdin);
	freopen("output398.txt","w",stdout);
	ll i,j;
	ll T;
	cin>>T;
	for(ll test=1;test<=T;test++)
	{
		fill(dp,-1);
		cin>>N>>M;
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
				cin>>arr[i][j];
		}
		printf("Case #%lld: %lld\n",test,fun(0,M-1,0,N-1));
	}
return 0;
}