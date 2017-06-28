//PT07X - Vertex Cover
#include<bits/stdc++.h>
using namespace std;
#define ll long  long
ll dp[123456][2];
bool vis[123456];
vector <ll> v[123456];

ll dfs(ll node,ll prev)
{
	if(dp[node][prev]!=-1)
	return dp[node][prev];
	vis[node]=1;
	ll i,j;
	ll temp1=1;
	ll temp2=0;
	if(prev==0)
	{
		for(i=0;i<v[node].size();i++)//take it
		{
			if(!vis[v[node][i]])
			{
				temp1+=dfs(v[node][i],0);
				vis[v[node][i]]=0;	
			}
		}
		for(i=0;i<v[node].size();i++)//leave it
		{
			if(!vis[v[node][i]])
			{
				temp2+=dfs(v[node][i],1);
				vis[v[node][i]]=0;	
			}
		}
		return dp[node][prev]=min(temp1,temp2);
	}
	else
	{
		for(i=0;i<v[node].size();i++)//take it
		{
			if(!vis[v[node][i]])
			{
				temp1+=dfs(v[node][i],0);
				vis[v[node][i]]=0;	
			}
		}
		return dp[node][prev]=temp1;
	}
}

int main()
{
	memset(dp,-1,sizeof dp);
	memset(vis,0,sizeof vis);
	ll N,i,j;
	scanf("%lld",&N);
	for(i=1;i<N;i++)
	{
		ll X,Y;
		scanf("%lld%lld",&X,&Y);
		v[X].push_back(Y);
		v[Y].push_back(X);
	}
	printf("%lld\n",dfs(1,0));	
	return 0;
}
