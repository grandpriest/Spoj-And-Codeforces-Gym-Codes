//BRCKTS - Brackets
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)

struct nodes
{
	ll left;
	ll right;
};
nodes tree[4*31234];
string str;
ll pos,N;

void build(ll node,ll start,ll end)
{
	if(start!=end)
	{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		ll temp=min(tree[2*node].right,tree[2*node+1].left);
		tree[node].left=tree[2*node].left+tree[2*node+1].left-temp;
		tree[node].right=tree[2*node].right+tree[2*node+1].right-temp;
	}
	else
	{
		if(str[start-1]=='(')
			tree[node].right++;
		else
			tree[node].left++;
	}
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
		ll temp=min(tree[2*node].right,tree[2*node+1].left);
		tree[node].left=tree[2*node].left+tree[2*node+1].left-temp;
		tree[node].right=tree[2*node].right+tree[2*node+1].right-temp;
	}
	else
		swap(tree[node].left,tree[node].right);
}
int main()
{
ll i,j;
for(ll test=1;test<=10;test++)
{
	scanf("%lld",&N);
	cin>>str;
	for(i=0;i<4*31234;i++)
		tree[i].left=tree[i].right=0;
	build(1,1,N);
	ll Q;
	scanf("%lld",&Q);
	printf("Test %lld:\n",test);
	while(Q--)
	{
		scanf("%lld",&pos);
		if(pos==0)
		{
			if(tree[1].left==0 && tree[1].right==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			update(1,1,N);
	}
}
return 0;
}

