//MFISH - Catch Fish
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000009
#define fill(a,v) memset(a,v,sizeof a)

ll pre[123456];
ll dp[123456];
ll N;
ll start[123456];
ll last[123456];
ll arr[123456];
vector < pair <ll,ll> > v;

ll fun(ll idx)
{
	if(idx>N)
	return 0;
	if(dp[idx]!=-1)
	return dp[idx];
	if(arr[idx]==-1)
	return dp[idx]=fun(idx+1);//pass
	ll len=v[arr[idx]].second;
	return dp[idx]=max(fun(idx+1),pre[idx+len-1]-pre[idx-1]+fun(idx+len));	
}

int main()
{
	ll i,j;
	fill(dp,-1);
	fill(pre,0);
	fill(arr,-1);
	cin>>N;
	for(i=1;i<=N;i++)
	{
		ll X;
		cin>>X;
		pre[i]=pre[i-1]+X;	
	}	
	ll M;
	cin>>M;
	while(M--)
	{
		ll A,B;
		cin>>A>>B;
		v.push_back({A,B});
	}
	sort(v.begin(),v.end());
	ll prev=0;
	for(i=0;i<v.size();i++)
	{
		ll A=v[i].first;
		ll B=v[i].second;
		start[i]=max(A-B+1,prev+1);
		last[i]=min(A,N-B+1);
		prev=last[i];
	}
	for(i=0;i<v.size();i++)
	{
		for(j=start[i];j<=last[i];j++)
			arr[j]=i;
	}
	cout<<fun(1);
	return 0;
}

