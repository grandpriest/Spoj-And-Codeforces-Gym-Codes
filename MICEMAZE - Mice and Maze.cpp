//MICEMAZE - Mice and Maze
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N,E,T;
ll M;
vector <pair <ll,ll> > v[123];
ll dist[123];

void dij(ll start)
{
	ll i,j;
	dist[start]=0;
	priority_queue <pair <ll,ll> > pq;
	pq.push(make_pair(0,start));
	while(!pq.empty())
	{
		pair <ll,ll> top=pq.top();
		pq.pop();
		for(i=0;i<v[top.second].size();i++)
		{
			ll newdist=dist[top.second]+v[top.second][i].first;
			if(dist[v[top.second][i].second]==-1||dist[v[top.second][i].second]>newdist)
			{
				dist[v[top.second][i].second]=newdist;
				pq.push(make_pair(-newdist,v[top.second][i].second));
			}
		}
	}
}

int main()
{
	ll i,j;
	memset(dist,-1,sizeof dist);
	scanf("%lld%lld%lld%lld",&N,&E,&T,&M);
	while(M--)
	{
		ll X,Y,Z;
		scanf("%lld%lld%lld",&X,&Y,&Z);
		v[Y].push_back(make_pair(Z,X));
	}
	dij(E);
	ll ans=0;
	for(i=1;i<=N;i++)
	{
		if(dist[i]<=T)
		ans++;
	}
	printf("%lld",ans);
	return 0;
}
