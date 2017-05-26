//SAMER08A - Almost Shortest Path
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N,M;
ll S,D;
vector <pair <ll,ll> > v[512];
ll dist[512];
ll parent[512];
set <pair <ll,ll> >s;

void removeroads(ll prev,ll now)
{
	while(prev!=-1)
	{
		s.insert(make_pair(prev,now));
		now=prev;
		prev=parent[prev];
	}
}


void dij1(ll start)
{
	dist[start]=0;
	priority_queue < pair <ll,ll> >pq;
	pq.push(make_pair(0,start));
	while(!pq.empty())
	{
		pair <ll,ll> top=pq.top();
		pq.pop();
		ll i,j;
	//	cout<<top.second<<"<--node now "<<top.first<<"<--dist now"<<endl;
		for(i=0;i<v[top.second].size();i++)
		{
			ll nextnode=v[top.second][i].second;
			ll nextcost=dist[top.second]+v[top.second][i].first;
			if(nextnode==D)
			{
			//	cout<<nextnode<<"<--dest reaced"<<endl;
				if(nextcost<dist[nextnode])
				{
					dist[nextnode]=nextcost;
					s.clear();
					removeroads(top.second,nextnode);
				}
				else if(nextcost==dist[nextnode])
					removeroads(top.second,nextnode);
			}
			else if(nextcost<dist[nextnode])
			{
				dist[nextnode]=nextcost;
				parent[nextnode]=top.second;
				pq.push(make_pair(-nextcost,nextnode));
			}
		}
	}
}

void dij2(ll start)
{
	dist[start]=0;
	priority_queue < pair <ll,ll> >pq;
	pq.push(make_pair(0,start));
	set <pair <ll,ll> >::iterator it;
	while(!pq.empty())
	{
		pair <ll,ll> top=pq.top();
		pq.pop();
		ll i,j;
		if(top.second==D)
		break;
		for(i=0;i<v[top.second].size();i++)
		{
			it=s.find(make_pair(top.second,v[top.second][i].second));
			if(it==s.end())//edge not found
			{
				ll nextnode=v[top.second][i].second;
				ll nextcost=dist[top.second]+v[top.second][i].first;
			 	if(nextcost<dist[nextnode])
				{
					dist[nextnode]=nextcost;
					pq.push(make_pair(-nextcost,nextnode));
				}
			}
		}
	}
}

int main()
{
	while(1)
	{
		ll i,j;
		scanf("%lld%lld",&N,&M);
		if(!(N|M))
			break;
		for(i=0;i<512;i++)
		{
			v[i].clear();
			dist[i]=1e18;
			parent[i]=-1;	
		}
		scanf("%lld%lld",&S,&D);
		while(M--)
		{
			ll X,Y,Z;
			scanf("%lld%lld%lld",&X,&Y,&Z);
			v[X].push_back(make_pair(Z,Y));	
		}
		dij1(S);
	//	cout<<dist[D]<<"<--dist of D"<<endl;
	//	cout<<"TO DELETE"<<endl;
	//	for(set<pair <ll,ll> >::iterator it=s.begin();it!=s.end();it++)
	//	cout<<(*it).first<<"to"<<(*it).second<<endl;
		for(i=0;i<512;i++)
			dist[i]=1e18;
		dij2(S);
		if(dist[D]==1e18)
		printf("-1\n");
		else
		printf("%lld\n",dist[D]);	
	}
	return 0;
}
