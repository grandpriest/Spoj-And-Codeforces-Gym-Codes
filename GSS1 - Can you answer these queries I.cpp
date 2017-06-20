//GSS1 - Can you answer these queries I
#include<bits/stdc++.h>
using namespace std;
#define ll int
ll arr[4*51234];
ll L,R;
ll N;
struct segtree
{
	ll maxval;
	ll sum;
	ll pre;
	ll suf;
	segtree()
	{
		maxval=0;
		sum=0;
		pre=0;
		suf=0;
	}
};
segtree tree[4*51234];

void print(ll node,ll start,ll end)
{
	cout<<endl;
	cout<<start<<","<<end<<endl;
	cout<<tree[node].sum<<"<--sum"<<endl;
	cout<<tree[node].maxval<<"<--maxval"<<endl;
	cout<<tree[node].pre<<"<--pre "<<endl;
	cout<<tree[node].suf<<"<--suf  "<<endl;
}

void build(ll node,ll start,ll end)
{
	if(start==end)
	{
		tree[node].maxval=arr[start];
		tree[node].sum=arr[start];
		tree[node].pre=arr[start];
		tree[node].suf=arr[start];
	}
	else
	{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
		tree[node].maxval=tree[node].sum;
		ll temp=max(tree[2*node].maxval,max(tree[2*node+1].maxval,tree[2*node].suf+tree[2*node+1].pre));
		tree[node].maxval=max(tree[node].maxval,temp);
		tree[node].pre=max(tree[2*node].pre,tree[2*node].sum+tree[2*node+1].pre);
		tree[node].suf=max(tree[2*node+1].suf,tree[2*node+1].sum+tree[2*node].suf);
	}
//	print(node,start,end);
}

segtree  query(ll node,ll start,ll end)
{
	segtree  temp,left,right;
	if(L<=start && R>=end)
		return tree[node];
	if(L>end || R<start)
	{
		temp.maxval=-1e9;
		temp.sum=-1e9;
		temp.pre=-1e9;
		temp.suf=-1e9;
		return temp;
	}
	ll mid=(start+end)/2;
	if(L>mid)//only right
	{
		right=query(2*node+1,mid+1,end);
		return right;	
	}
	else if (R<mid+1)//only left
	{
		left=query(2*node,start,mid);
		return left;
	}
	left=query(2*node,start,mid);
	right=query(2*node+1,mid+1,end);
		temp.sum=left.sum+right.sum;
		temp.maxval=temp.sum;
		ll temp2=max(left.maxval,max(right.maxval,left.suf+right.pre));
		temp.maxval=max(temp.maxval,temp2);
		temp.pre=max(left.pre,left.sum+right.pre);
		temp.suf=max(right.suf,right.sum+left.suf);
	return temp;	
}

int main()
{
	scanf("%d",&N);
	ll i,j;
	for(i=1;i<=N;i++)
	scanf("%d",&arr[i]);
	build(1,1,N);
	ll Q;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&L,&R);
		segtree  ans=query(1,1,N);
		printf("%d\n",ans.maxval);
	}
	return 0;
}
