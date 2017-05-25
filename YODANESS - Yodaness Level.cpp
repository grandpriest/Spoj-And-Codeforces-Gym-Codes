//YODANESS - Yodaness Level
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
ll tree[4*31234];
vector <ll> v[4*31234];
map <string,ll> map1;
ll arr[4*31234];

void merge(ll node,ll start,ll end)
{
	if(start==end)
	{
		v[node].push_back(arr[start]);
		tree[node]=0;
	}
	else
	{
		ll mid=(start+end)/2;
		merge(2*node,start,mid);
		merge(2*node+1,mid+1,end);
		tree[node]=tree[2*node]+tree[2*node+1];
		ll i=0,j=0;
		ll left=v[2*node].size();
		ll right=v[2*node+1].size();
		while(i<left||j<right)
		{
			if(i==left)
			{
				v[node].push_back(v[2*node+1][j]);
				j++;
			}
			else if(j==right)
			{
				v[node].push_back(v[2*node][i]);
				i++;
			}
			else if(v[2*node][i]<v[2*node+1][j])
			{
				v[node].push_back(v[2*node][i]);
				i++;
			}
			else
			{
				v[node].push_back(v[2*node+1][j]);
				j++;
				tree[node]+=left-i;
			}
		}
	}
}
int main()
{
	ll i,j;
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		map1.clear();
		memset(tree,0,sizeof tree);
		memset(arr,0,sizeof arr);
		for(i=0;i<4*31234;i++)
			v[i].clear();
		scanf("%lld",&N);
		for(i=1;i<=N;i++)
		{
			string temp;
			cin>>temp;
			map1[temp]=i;
		}
		for(i=1;i<=N;i++)
		{
			string temp;
			cin>>temp;
			arr[i]=map1[temp];	
		}	
		merge(1,1,N);
		printf("%lld\n",tree[1]);
	}	
	return 0;
}
