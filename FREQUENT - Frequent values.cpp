//FREQUENT - Frequent values
# include <bits/stdc++.h>
using namespace std;
 
# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)
 
ll N,Q;
ll arr[4*123456];
struct nodes
{
	ll maxval;
	ll startsum;
	ll endsum;
};
nodes tree[4*123456];
ll L,R;
 
void build(ll node,ll start,ll end)
{
	if(start!=end)
	{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		ll temp=0;
		if(arr[mid]==arr[mid+1])
			temp=tree[2*node].endsum+tree[2*node+1].startsum;
		
		tree[node].maxval=max(tree[2*node].maxval,max(tree[2*node+1].maxval,temp));
		tree[node].startsum=tree[2*node].startsum;
		tree[node].endsum=tree[2*node+1].endsum;
		
		if(arr[start]==arr[mid+1])
			tree[node].startsum+=tree[2*node+1].startsum;
		if(arr[end]==arr[mid])
			tree[node].endsum+=tree[2*node].endsum;
	}
	else
	{
		tree[node].maxval=1;
		tree[node].startsum=1;
		tree[node].endsum=1;	
	}
}
 
nodes query(ll node,ll start,ll end)
{
	nodes temp;
	if(L>end || R<start)
	{
		temp.maxval=0;
		temp.startsum=0;
		temp.endsum=0;
		return temp;
	}
	if(L<=start && R>=end)
		return tree[node];
	ll mid=(start+end)/2;
	nodes left=query(2*node,start,mid);
	nodes right=query(2*node+1,mid+1,end);
	ll val=0;
	if(arr[mid]==arr[mid+1])
			val=left.endsum+right.startsum;
		temp.maxval=max(left.maxval,max(right.maxval,val));
		temp.startsum=left.startsum;
		temp.endsum=right.endsum;
		if(arr[start]==arr[mid+1])
			temp.startsum+=right.startsum;
		if(arr[end]==arr[mid])
			temp.endsum+=left.endsum;
		return temp;
}
 
int main()
{
	ll i,j;
	while(1)
	{

		for(i=0;i<4*123456;i++)
		{
			tree[i].maxval=0;
			tree[i].startsum=0;
			tree[i].endsum=0;
		}
		scanf("%lld",&N);
		if(N==0)
			return 0;
		scanf("%lld",&Q);
		for(i=1;i<=N;i++)
			scanf("%lld",&arr[i]);
		build(1,1,N);
		while(Q--)
		{
			scanf("%lld%lld",&L,&R);
			printf("%lld\n",query(1,1,N).maxval);
		}
	}
}