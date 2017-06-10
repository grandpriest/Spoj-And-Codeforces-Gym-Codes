//BYTESM2 - Philosophers Stone
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[123][123];
ll arr[123][123];
ll N,M;

ll fun(ll x,ll y)
{
	if(x<1 || x>N || y<1 ||y>M)
	return 0;
	if(dp[x][y]!=-1)
	return dp[x][y];
	return dp[x][y]=arr[x][y]+max(fun(x+1,y),max(fun(x+1,y+1),fun(x+1,y-1)));
}
int main()
{
	ll T;
	cin>>T;
	while(T--)
	{
		memset(dp,-1,sizeof dp);
		memset(arr,0,sizeof arr);
		ll i,j;
		cin>>N>>M;
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			cin>>arr[i][j];
		}
		ll ans=0;
		for(i=1;i<=M;i++)
		ans=max(ans,fun(1,i));
		cout<<ans<<endl;
	}
	return 0;
}
