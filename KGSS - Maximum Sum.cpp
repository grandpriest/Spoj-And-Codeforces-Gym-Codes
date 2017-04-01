//KGSS - Maximum Sum
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)

ll N;
ll arr[4*123456];
ll L,R,pos,newval;
struct nodes
{
	ll sum;
	ll maxvalue;
};
nodes tree[4*123456];

void build(ll node,ll start,ll end)
{
	if(start!=end)
	{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].sum=max(tree[2*node].sum,max(tree[2*node+1].sum,tree[2*node].maxvalue+tree[2*node+1].maxvalue));
		tree[node].maxvalue=max(tree[2*node].maxvalue,tree[2*node+1].maxvalue);	
	}	
	else
	{
		tree[node].sum=arr[start];
		tree[node].maxvalue=arr[start];
	}/*
	cout<<endl<<start<<":"<<end<<endl;
	cout<<"	sum:"<<tree[node].sum<<endl;
	cout<<"	maxvalue:"<<tree[node].maxvalue<<endl;*/
}
void update(ll node,ll start,ll end)
{
	if(pos<start || pos>end)
		return;

	if(start!=end)
	{
		ll mid=(start+end)/2;
		update(2*node,start,mid);
		update(2*node+1,mid+1,end);
		tree[node].sum=max(tree[2*node].sum,max(tree[2*node+1].sum,tree[2*node].maxvalue+tree[2*node+1].maxvalue));
		tree[node].maxvalue=max(tree[2*node].maxvalue,tree[2*node+1].maxvalue);
	}	
	else
		tree[node].sum=tree[node].maxvalue=newval;
}
nodes query(ll node,ll start,ll end)
{
	nodes temp;
	if(R<start || L>end)
	{
		temp.sum=-INF;
		temp.maxvalue=-INF;
		return temp;
	}
	if(L<=start && R>=end)
		return tree[node];
	ll mid=(start+end)/2;
	nodes lchild=query(2*node,start,mid);
	nodes rchild=query(2*node+1,mid+1,end);
	temp.sum=max(lchild.sum,max(rchild.sum,lchild.maxvalue+rchild.maxvalue));
	temp.maxvalue=max(lchild.maxvalue,rchild.maxvalue);
	return temp;
}
int main()
{
ll i,j;
	scanf("%lld",&N);
	for(i=0;i<4*123456;i++)
		tree[i].sum=tree[i].maxvalue=0;
	for(i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	build(1,1,N);
	ll Q;
	scanf("%lld",&Q);
	while(Q--)
	{
		char ch;
		cin>>ch;
		if(ch=='Q')
		{
			scanf("%lld%lld",&L,&R);
			printf("%lld\n",query(1,1,N).sum);
		}
		else
		{
			scanf("%lld%lld",&pos,&newval);
			update(1,1,N);
		}	
	}
return 0;
}

