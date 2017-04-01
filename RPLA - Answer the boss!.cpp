//RPLA - Answer the boss!
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)

ll N,M;
vector <ll> adj[1234];
bool vis[1234];
ll in_deg[1234];
vector <pair <ll,ll> > order;

void toposort()
{
	priority_queue < pair <ll,ll> > pq;
	ll i,j;
	for(i=0;i<N;i++)
	{
		if(in_deg[i]==0)
		{
			pq.push(mp(-i,1));
			vis[i]=1;
		}
	}
	while(!pq.empty())
	{
		pair <ll,ll> f=pq.top();
		pq.pop();
		f.first*=-1;

	//	cout<<f.first<<","<<f.second<<endl;
		order.push_back(mp(f.second,f.first));
		for(i=0;i<adj[f.first].size();i++)
		{
			if(vis[adj[f.first][i]]==0)
			{
			//	cout<<adj[f.first][i]<<"<-- ele considered now for push"<<endl;
				in_deg[adj[f.first][i]]--;
				if(in_deg[adj[f.first][i]]==0)
				{
					vis[adj[f.first][i]]=1;
					pq.push(mp(-1*adj[f.first][i],f.second+1));
				}
			}
		}
	}
}

int main()
{
ll i,j;
ll T;
scanf("%lld",&T);
for(ll test=1;test<=T;test++)
{
//	cout<<test<<"<--test now"<<endl;
	order.clear();
	fill(in_deg,0);
	fill(vis,0);
	for(i=0;i<=1000;i++)
		adj[i].clear();
	scanf("%lld%lld",&N,&M);
	while(M--)
	{
		ll X,Y;
		scanf("%lld%lld",&X,&Y);
		adj[Y].push_back(X);
		in_deg[X]++;
	}
	toposort();
	printf("Scenario #%lld:\n",test);
	sort(order.begin(),order.end());
	for(i=0;i<order.size();i++)
		printf("%lld %lld\n",order[i].first,order[i].second);
}
return 0;
}

