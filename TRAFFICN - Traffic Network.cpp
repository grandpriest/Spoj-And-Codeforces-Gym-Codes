//TRAFFICN - Traffic Network
//here in dist1 we store the shortest dist from source to all other nodes in graph
//and in dist2 we store the shortest dist from target to all other node but in a reverse graph
//so if a new edge is added between vertices A and B then it can act as path to reach from source to end 
//if ans>dist1[A]+new_edge_length+dist2[B] so ans=dist1[A]+new_edge_length+dist2[B]
//here ans is the min posiible dist from source to target
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N,M,K,S,T;
ll dist1[12345];
ll dist2[12345];
vector <pair <ll,ll> > v[12345];
vector <pair <ll,ll> > rev[12345];

void dij1()
{
	dist1[S]=0;
	priority_queue <pair<ll,ll> > pq;
	pq.push(make_pair(0,S));
	while(!pq.empty())
	{
		pair<ll,ll> top=pq.top();
		pq.pop();
		ll i,j;
		for(i=0;i<v[top.second].size();i++)
		{
			ll newnode=v[top.second][i].second;
			ll newcost=dist1[top.second]+v[top.second][i].first;
			if(newcost<dist1[newnode])
			{
				dist1[newnode]=newcost;
				pq.push(make_pair(-newcost,newnode));
			}
		}
	}
}
void dij2()
{
	dist2[T]=0;
	priority_queue <pair<ll,ll> > pq;
	pq.push(make_pair(0,T));
	while(!pq.empty())
	{
		pair<ll,ll> top=pq.top();
		pq.pop();
		ll i,j;
		for(i=0;i<rev[top.second].size();i++)
		{
			ll newnode=rev[top.second][i].second;
			ll newcost=dist2[top.second]+rev[top.second][i].first;
			if(newcost<dist2[newnode])
			{
				dist2[newnode]=newcost;
				pq.push(make_pair(-newcost,newnode));
			}
		}
	}
}

int main()
{
	ll i,j;
	ll test ;
	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld%lld%lld%lld%lld",&N,&M,&K,&S,&T);
		for(i=0;i<12345;i++)
		{
			dist1[i]=1e18;
			dist2[i]=1e18;
			v[i].clear();
			rev[i].clear();
		}
		while(M--)
		{
			ll X,Y,Z;
			scanf("%lld%lld%lld",&X,&Y,&Z);
			v[X].push_back(make_pair(Z,Y));
			rev[Y].push_back(make_pair(Z,X));	
		}	
		ll ans=1e18;
		dij1();
		dij2();
		ans=dist1[T];
		while(K--)
		{
			ll A,B,C;
			scanf("%lld%lld%lld",&A,&B,&C);
			ans=min(ans,dist1[A]+C+dist2[B]);
			ans=min(ans,dist1[B]+C+dist2[A]);
		}
		if(ans==1e18)
		printf("-1\n");
		else
		printf("%lld\n",ans);
	}
	return 0;
}
