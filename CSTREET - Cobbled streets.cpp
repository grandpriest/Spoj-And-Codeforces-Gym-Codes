//CSTREET - Cobbled streets
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll parent[1234];
ll Rank[1234];

pair <ll,pair<ll,ll> > arr[300005];
ll root(ll node)
{
	if(parent[node]!=node)
	parent[node]=root(parent[node]);
	return parent[node];
}
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		ll P,N,M;
		scanf("%lld%lld%lld",&P,&N,&M);
		ll i=0;
		while(M--)
		{
			ll X,Y,Z;
			scanf("%lld%lld%lld",&X,&Y,&Z);
			arr[i].first=Z;
			arr[i].second.first=X;
			arr[i].second.second=Y;	
			i++;
		}	
		sort(arr,arr+i);
		M=i;
		for(i=0;i<1234;i++)
		{
			parent[i]=i;
			Rank[i]=1;
		}
		ll ans=0;
		for(i=0;i<M;i++)
		{
			ll A=arr[i].second.first;
			ll B=arr[i].second.second;
			ll rA=root(A);
			ll rB=root(B);
			if(rA!=rB)
			{
				ans+=arr[i].first;
				if(Rank[rA]>=Rank[rB])
				{
					Rank[rA]+=Rank[rB];
					Rank[rB]=0;
					parent[rB]=parent[rA];
				}
				else 	
				{
					Rank[rB]+=Rank[rA];
					Rank[rA]=0;
					parent[rA]=parent[rB];
				}
			}
		}
		printf("%lld\n",ans*P);
	}
	return 0;
}
