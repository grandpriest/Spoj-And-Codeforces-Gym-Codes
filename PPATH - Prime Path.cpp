//PPATH - Prime Path
#include<bits/stdc++.h>
using namespace std;
#define ll int
vector <ll> prime;

void seive()
{
	ll i,j;
	bool vis[123456];
	memset(vis,0,sizeof vis);
	for(i=2;i<=sqrt(123456);i++)
	{
		if(!vis[i])
		{
			for(j=2*i;j<(123456);j+=i)
			 vis[j]=1;
		}
	}
	for(i=1000;i<=9999;i++)
	{
		if(vis[i]==0)
			prime.push_back(i);	
	}
}
ll check(ll num1,ll num2)
{
	ll ans=0;
	while(num1>0 && num2>0)
	{
		ll temp1=num1%10;
		ll temp2=num2%10;
		if(temp1!=temp2)
		ans++;
		num1/=10;
		num2/=10;
	}
	return ans;
}
int main()
{
	seive();	
	ll T;
	ll dist[12345];
	scanf("%d",&T);
	while(T--)
	{
		ll start;
		ll end;
		memset(dist,-1,sizeof dist);
		scanf("%d%d",&start,&end);
		queue < ll> q;
		bool f=0;
		dist[start]=0;
		q.push(start);
		while(!q.empty())
		{
			ll f=q.front();
			q.pop();
			if(f==end)
			break;
			for(ll i=0;i<prime.size();i++)
			{
				if(dist[prime[i]]==-1 && check(prime[i],f)==1)
				{
					dist[prime[i]]=dist[f]+1;
					q.push(prime[i]);
				}
			}
		}
		if(dist[end]!=-1)
		printf("%d\n",dist[end]);
		else
		printf("Impossible\n");
	}
	return 0;
}
