//IITWPC4I - Petya and Repairment of Roads
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool arr[123456];
bool vis[123456];
vector <pair <ll,ll> > v[123456];
int main()
{
	ll i,j;
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		priority_queue <pair<ll,ll> > pq;
		ll N,M;
		scanf("%lld%lld",&N,&M);
		for(i=0;i<123456;i++)
		v[i].clear();	
		memset(vis,0,sizeof vis);
		memset(arr,0,sizeof arr);
		for(i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
		while(M--)
		{
			ll X,Y,Z;
			scanf("%lld%lld%lld",&X,&Y,&Z);
			v[X].push_back(make_pair(Z,Y));
			v[Y].push_back(make_pair(Z,X));
		}
		for(i=1;i<=N;i++)
		{
			if(arr[i])
			{
				vis[i]=1;
				for(j=0;j<v[i].size();j++)
				pq.push(make_pair(-v[i][j].first,v[i][j].second));
			}
		}
		ll ans=0;
		while(!pq.empty())
		{
			pair<ll,ll> t=pq.top();
			pq.pop();
			if(!vis[t.second])
			{
				vis[t.second]=1;
				ans+=-t.first;
				for(j=0;j<v[t.second].size();j++)
				pq.push(make_pair(-v[t.second][j].first,v[t.second][j].second));
			}
		}
		bool f=0;
		for(i=1;i<=N;i++)
		{
			if(!vis[i])
			f=1;
		}
		if(f==1)
		printf("impossible\n");
		else
		printf("%lld\n",ans);
	}
	return 0;
}
