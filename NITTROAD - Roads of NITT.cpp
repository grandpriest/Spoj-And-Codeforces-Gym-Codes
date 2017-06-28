//NITTROAD - Roads of NITT
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll parent[21234];
ll Rank[21234];
vector <ll> ans;
vector <pair<char,ll> > query;
vector < pair<ll,ll> > paths;
bool vis[21234];
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
		memset(vis,0,sizeof vis);
		ans.clear();
		query.clear();
		paths.clear();
		ll i,j;
		for(i=0;i<21234;i++)
		{
			parent[i]=i;
			Rank[i]=1;
		}
		ll N;
		scanf("%lld",&N);
		for(i=1;i<N;i++)
		{
			ll X,Y;
			scanf("%lld%lld",&X,&Y);
			paths.push_back(make_pair(X,Y));	
		}	
		ll Q;
		scanf("%lld",&Q);
		while(Q--)
		{
			char ch;
			cin>>ch;
			if(ch=='R')
			{
				ll num;
				scanf("%lld",&num);
				num--;
				vis[num]=1;
				query.push_back(make_pair(ch,num));
			}
			else
				query.push_back(make_pair(ch,0));
		}
		ll count=(N*(N-1))/2;
		for(i=0;i<paths.size();i++)
		{
			if(!vis[i])
			{
				ll A=paths[i].first;
				ll B=paths[i].second;
				ll rA=root(A);
				ll rB=root(B);
				ll temp1=(Rank[rA]*(Rank[rA]-1))/2;
				temp1+=(Rank[rB]*(Rank[rB]-1))/2;
				if(Rank[rA]>=Rank[rB])
				{
					Rank[rA]+=Rank[rB];
					Rank[rB]=0;
					parent[rB]=parent[rA];
					count+=temp1;
					temp1=(Rank[rA]*(Rank[rA]-1))/2;
					count-=temp1;
				}
				else
				{
					Rank[rB]+=Rank[rA];
					Rank[rA]=0;
					parent[rA]=parent[rB];
					count+=temp1;
					temp1=(Rank[rB]*(Rank[rB]-1))/2;
					count-=temp1;
				}
			}
		}
	//	cout<<count<<"<--count final "<<endl;
		for(i=query.size()-1;i>=0;i--)
		{
			if(query[i].first=='Q')
			ans.push_back(count);
			else
			{
				ll A=paths[query[i].second].first;
				ll B=paths[query[i].second].second;
				ll rA=root(A);
				ll rB=root(B);
				ll temp1=(Rank[rA]*(Rank[rA]-1))/2;
				temp1+=(Rank[rB]*(Rank[rB]-1))/2;
				if(Rank[rA]>=Rank[rB])
				{
					Rank[rA]+=Rank[rB];
					Rank[rB]=0;
					parent[rB]=parent[rA];
					count+=temp1;
					temp1=(Rank[rA]*(Rank[rA]-1))/2;
					count-=temp1;
				}
				else
				{
					Rank[rB]+=Rank[rA];
					Rank[rA]=0;
					parent[rA]=parent[rB];
					count+=temp1;
					temp1=(Rank[rB]*(Rank[rB]-1))/2;
					count-=temp1;
				}
			}
		}
		for(i=ans.size()-1;i>=0;i--)
			printf("%lld\n",ans[i]);
		printf("\n");
	}
	return 0;
}
