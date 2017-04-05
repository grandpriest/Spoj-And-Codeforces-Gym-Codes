//INVCNT - Inversion Count
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)


ll tree_val[2*4*123456];
vector <ll> tree_merged[2*4*123456];
ll arr[2*4*123456];
ll N;
void build(ll node,ll start,ll end)
{
	if(start!=end)
	{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree_val[node]=tree_val[2*node]+tree_val[2*node+1];
		ll i=0,j=0;
		ll left_ele=mid-start+1;
		ll right_ele=end-(mid+1)+1;
		while(i!=left_ele || j!=right_ele)
		{
			if(i==left_ele)
			{
				tree_merged[node].push_back(tree_merged[2*node+1][j]);
					j++;
			}
			else if(j==right_ele)
			{
				tree_merged[node].push_back(tree_merged[2*node][i]);
					i++;
			}
			else if(tree_merged[2*node][i]<=tree_merged[2*node+1][j])
			{
				tree_merged[node].push_back(tree_merged[2*node][i]);
					i++;
			}

			else if(tree_merged[2*node][i]>tree_merged[2*node+1][j])
			{
				/*cout<<start<<":"<<end<<"<--talking about the node"<<endl;
				cout<<"here:";
				cout<<tree_merged[2*node+1][j]<<"<--number added"<<endl;
				cout<<left_ele-i<<"<--value added for this number"<<endl;
				*/tree_merged[node].push_back(tree_merged[2*node+1][j]);
				j++;
				tree_val[node]+=left_ele-i;
			}
		}
	}
	else
	{
		tree_val[node]=0;
		tree_merged[node].push_back(arr[start]);
	}/*
	cout<<endl;
	cout<<start<<":"<<end<<endl;
	cout<<tree_val[node]<<endl;
	for(ll k=0;k<tree_merged[node].size();k++)
		cout<<tree_merged[node][k]<<" ";cout<<endl;*/
}

int main()
{
ll i,j;
ll T;
scanf("%lld",&T);
while(T--)
{
	fill(tree_val,0);
	for(i=0;i<2*4*123456;i++)
		tree_merged[i].clear();
	scanf("%lld",&N);
	for(i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	build(1,1,N);
	printf("%lld\n",tree_val[1]);
}
return 0;
}

