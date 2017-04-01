//Topological Sort
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)
vector <ll> order;
ll N,M;
bool vis[123456];
ll in_degree[123456];
bool connect[123][123];

void Topological_sort()
{
	ll i,j;
	fill(vis,0);
	priority_queue <ll> pq;
	for(i=1;i<=N;i++)
	{
		if(in_degree[i]==0)
		{
			pq.push(-i);
			vis[i]=1;
		}
	}
	while(!pq.empty())
	{
		ll f=pq.top();
		f*=-1;
		order.push_back(f);
		pq.pop();
		for(i=1;i<=N;i++)
		{
			if(!vis[i] && connect[f][i]==1)
			{
				in_degree[i]--;
				if(in_degree[i]==0)
				{
					vis[i]=1;
					pq.push(-i);
				}
			}
		}
	}
}

int main()
{
ll i,j;
fill(in_degree,0);
scanf("%lld%lld",&N,&M);
fill(connect,0);
while(M--)
{
	ll X,Y;
	scanf("%lld%lld",&X,&Y);
	connect[X][Y]=1;
	in_degree[Y]++;
}
Topological_sort();
for(i=0;i<order.size();i++)
	printf("%lld ",order[i]);
return 0;
}

