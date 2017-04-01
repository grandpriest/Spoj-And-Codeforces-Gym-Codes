//SEGSQRSS - Sum of Squares with Segment Tree
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
	ll sqr;
	ll sum;
};
nodes tree[4*123456];
vector < pair <ll,ll> > lazy[4*123456];
ll L,R;
pair <ll,ll> updation_now;

void build(ll node,ll start,ll end)
{
	if(start!=end)
	{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
		tree[node].sqr=tree[2*node].sqr+tree[2*node+1].sqr;	
	}
	else
	{
		tree[node].sqr=arr[start]*arr[start];
		tree[node].sum=arr[start];
	}/*
	cout<<endl<<start<<":"<<end<<endl;
	cout<<"	"<<tree[node].sqr<<"<--the square"<<endl;
	cout<<"	"<<tree[node].sum<<"<--the sum"<<endl;*/
}
void update(ll node,ll start,ll end)
{
	ll i,j;
	if(lazy[node].size()!=0)
	{
		for(i=0;i<lazy[node].size();i++)
		{
			if(lazy[node][i].first==1)
			{
				tree[node].sqr+=(lazy[node][i].second*lazy[node][i].second*(end-start+1))+(2*lazy[node][i].second*tree[node].sum);
				tree[node].sum+=lazy[node][i].second*(end-start+1);	
			}
			else
			{	
				tree[node].sqr=(lazy[node][i].second*lazy[node][i].second*(end-start+1));
				tree[node].sum=lazy[node][i].second*(end-start+1);	
			}
			lazy[2*node].push_back(lazy[node][i]);
			lazy[2*node+1].push_back(lazy[node][i]);	
		}
		lazy[node].clear();
	}
	if(L>end || R<start)
		return;
	else if(L<=start && R>=end)
	{
		if(updation_now.first==1)
		{
				tree[node].sqr+=(updation_now.second*updation_now.second*(end-start+1))+(2*updation_now.second*tree[node].sum);
				tree[node].sum+=updation_now.second*(end-start+1);	
		}
		else
		{	

			tree[node].sqr=(updation_now.second*updation_now.second*(end-start+1));
			tree[node].sum=updation_now.second*(end-start+1);	
		}
			lazy[2*node].push_back(updation_now);
			lazy[2*node+1].push_back(updation_now);	
	}
	else
	{
		ll mid=(start+end)/2;
		update(2*node,start,mid);
		update(2*node+1,mid+1,end);
		tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
		tree[node].sqr=tree[2*node].sqr+tree[2*node+1].sqr;	
	}
/*
	cout<<endl<<start<<":"<<end<<endl;
	cout<<"	"<<tree[node].sqr<<"<--the square"<<endl;
	cout<<"	"<<tree[node].sum<<"<--the sum"<<endl;*/
}
nodes query(ll node,ll start,ll end)
{
	ll i,j;
	if(lazy[node].size()!=0)
	{
		for(i=0;i<lazy[node].size();i++)
		{
			if(lazy[node][i].first==0)
			{
				tree[node].sqr+=(lazy[node][i].second*lazy[node][i].second*(end-start+1))+(2*lazy[node][i].second*tree[node].sum);
				tree[node].sum+=lazy[node][i].second*(end-start+1);	
			}
			else
			{	
				tree[node].sqr=(lazy[node][i].second*lazy[node][i].second*(end-start+1));
				tree[node].sum=lazy[node][i].second*(end-start+1);	
			}
			lazy[2*node].push_back(lazy[node][i]);
			lazy[2*node+1].push_back(lazy[node][i]);	
		}
		lazy[node].clear();
	}
	nodes temp;
	if(L>end || R<start)
	{
		temp.sum=temp.sqr=0;
		return temp;
	}
	else if(L<=start && R>=end)
		return tree[node];
	else
	{
		ll mid=(start+end)/2;
		nodes left=query(2*node,start,mid);
		nodes right=query(2*node+1,mid+1,end);
		temp.sqr=left.sqr+right.sqr;
		temp.sum=left.sum+right.sum;
		return temp;
	}
}
int main()
{
ll i,j;
ll T;
scanf("%lld",&T);
for(ll test=1;test<=T;test++)
{
	scanf("%lld%lld",&N,&Q);
	for(i=0;i<4*123456;i++)
	{
		tree[i].sum=tree[i].sqr=0;
		lazy[i].clear();
	}
	for(i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	build(1,1,N);
	printf("Case %lld:\n",test);
	while(Q--)
	{
		ll ch;
		scanf("%lld",&ch);
		if(ch==2)
		{
			scanf("%lld%lld",&L,&R);
			printf("%lld\n",query(1,1,N).sqr);
		}
		else if(ch==1)
		{
			ll X;
			scanf("%lld%lld%lld",&L,&R,&X);
			updation_now.first=1;
			updation_now.second=X;
			update(1,1,N);
		}
		else
		{
			ll X;
			scanf("%lld%lld%lld",&L,&R,&X);
			updation_now.first=0;
			updation_now.second=X;
			update(1,1,N);
		}	
	}
}
return 0;
}

