//LCA - Lowest Common Ancestor
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll height[1234];
ll parent[1234];
ll lca(ll nodeA,ll nodeB)
{
	while(height[nodeA]!=height[nodeB])
	{
		if(height[nodeA]>height[nodeB])
		nodeA=parent[nodeA];
		else
		nodeB=parent[nodeB];
	}
	if(nodeA==nodeB)
	return nodeA;
	while(parent[nodeA]!=parent[nodeB])
	{
		nodeA=parent[nodeA];
		nodeB=parent[nodeB];
	}
	if(parent[nodeA]==0)
	return nodeA;
	else
	return parent[nodeA];
}
int main()
{
	ll T;
	scanf("%lld",&T);
	ll test=0;
	while(T--)
	{
		ll N;
		ll i,j;
		scanf("%lld",&N);
		memset(height,0,sizeof height);
		memset(parent,0,sizeof parent);
		parent[1]=0;
		height[1]=1;
		for(i=1;i<=N;i++)
		{
			ll K;
			scanf("%lld",&K);
			while(K--)
			{
				ll X;
				scanf("%lld",&X);
				height[X]=height[i]+1;
				parent[X]=i;
			}
		}
		test++;
		ll Q;
		scanf("%lld",&Q);
		printf("Case %lld:\n",test);
		while(Q--)
		{
			ll A,B;
			scanf("%lld%lld",&A,&B);
			printf("%lld\n",lca(A,B));	
		}	
	}
	return 0;
}

