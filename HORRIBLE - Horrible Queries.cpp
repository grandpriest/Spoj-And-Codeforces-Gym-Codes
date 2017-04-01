//HORRIBLE - Horrible Queries
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)


ll lazy[4*123456];
ll N,Q;
ll L,R,value;
ll tree[4*123456];

void update(ll node,ll start,ll end)
{
	if(lazy[node]!=0)
	{
		tree[node]+=(lazy[node]*(end-start+1));
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(L>end || R<start)
		return;
	else if(L<=start && R>=end)
	{
		tree[node]+=(value*(end-start+1));
		if(start!=end)
		{
			lazy[2*node]+=value;
			lazy[2*node+1]+=value;
		}
	}
	else
	{
		ll mid=(start+end)/2;
		update(2*node,start,mid);
		update(2*node+1,mid+1,end);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
//	cout<<tree[node]<<"<--tree val for "<<start<<":"<<end<<endl;
}
ll query(ll node,ll start,ll end)
{
	if(lazy[node]!=0)
	{
		tree[node]+=(lazy[node]*(end-start+1));
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(L>end || R<start)
		return 0;
	else if(L<=start && R>=end)
		return tree[node];
	else
	{
		ll mid=(start+end)/2;
		ll left=query(2*node,start,mid);
		ll right=query(2*node+1,mid+1,end);
		return left+right;
	}
}
int main()
{
ll i,j;
ll T;
scanf("%lld",&T);
while(T--)
{
	scanf("%lld%lld",&N,&Q);
	fill(lazy,0);
	fill(tree,0);
	while(Q--)
	{
		ll ch;
		scanf("%lld%lld%lld",&ch,&L,&R);
		if(ch==1)
			printf("%lld\n",query(1,1,N));
		else
			{
				scanf("%lld",&value);
				update(1,1,N);
			}	
	}
}
return 0;
}

