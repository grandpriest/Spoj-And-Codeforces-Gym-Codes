//CSTREET - Cobbled streets
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[1234];
vector < pair<ll,ll> > v[1234];
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		ll P,N,M;
		ll i,j;
		for(i=0;i<1234;i++)
		{
			v[i].clear();
			vis[i]=0;	
		}
		scanf("%lld%lld%lld",&P,&N,&M);
		while(M--)
		{
			ll X,Y,Z;
			scanf("%lld%lld%lld",&X,&Y,&Z);
			v[X].push_back(make_pair(Z,Y));
			v[Y].push_back(make_pair(Z,X));	
		}	
		vis[1]=1;
		ll ans=0;
		priority_queue <pair<ll,ll> > pq;
		for(i=0;i<v[1].size();i++)
		pq.push(make_pair(-v[1][i].first,v[1][i].second));
		while(!pq.empty())
		{
			pair<ll,ll> t=pq.top();
			pq.pop();
			t.first*=-1;
			if(!vis[t.second])
			{
				vis[t.second]=1;
				ans+=t.first;
				for(i=0;i<v[t.second].size();i++)
				pq.push(make_pair(-v[t.second][i].first,v[t.second][i].second));
			}
		}
		printf("%lld\n",ans*P);
	}	
	return 0;
}

