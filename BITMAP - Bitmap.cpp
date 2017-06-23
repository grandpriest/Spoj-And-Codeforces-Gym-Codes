//BITMAP - Bitmap
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N,M;
ll arr[200][200];
ll dist[200][200];
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&N,&M);
		memset(dist,-1,sizeof dist);
		memset(arr,-1,sizeof arr);
		queue <pair <ll,ll> > q;
		ll i,j;
		for(i=1;i<=N;i++)
		{
			string str;
			cin>>str;
			for(j=1;j<=str.size();j++)
			{
				arr[i][j]=str[j-1]-'0';
				if(arr[i][j]==1)
				{
					q.push(make_pair(i,j));
					dist[i][j]=0;
				}
			}
		}
		while(!q.empty())
		{
			pair <ll,ll> pos=q.front();
			q.pop();
			if(dist[pos.first+1][pos.second]==-1 && arr[pos.first+1][pos.second]!=-1)
			{
				dist[pos.first+1][pos.second]=dist[pos.first][pos.second]+1;
				q.push(make_pair(pos.first+1,pos.second));
			}
			
			if(dist[pos.first-1][pos.second]==-1 && arr[pos.first-1][pos.second]!=-1)
			{
				dist[pos.first-1][pos.second]=dist[pos.first][pos.second]+1;
				q.push(make_pair(pos.first-1,pos.second));
			}
			
			if(dist[pos.first][pos.second+1]==-1 && arr[pos.first][pos.second+1]!=-1)
			{
				dist[pos.first][pos.second+1]=dist[pos.first][pos.second]+1;
				q.push(make_pair(pos.first,pos.second+1));
			}
			
			if(dist[pos.first][pos.second-1]==-1 && arr[pos.first][pos.second-1]!=-1)
			{
				dist[pos.first][pos.second-1]=dist[pos.first][pos.second]+1;
				q.push(make_pair(pos.first,pos.second-1));
			}
		}
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			printf("%lld ",dist[i][j]);
			printf("\n");
		}
	}
	return 0;
}
