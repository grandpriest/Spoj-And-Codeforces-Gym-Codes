//MARTIAN - Martian Mining
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000009
#define fill(a,v) memset(a,v,sizeof a)

ll dp[512][512];
ll N,M;
ll y[512][512],Y[512][512];
ll b[512][512],B[512][512];


ll fun(ll idx,ll height)
{
	
	if(idx==M+1)
		return 0;
	if(dp[idx][height]!=-1)
		return dp[idx][height];
	ll temp=0;
	ll pos=-1;
	for(ll i=height;i<=N;i++)
	{
		ll val=B[i][idx]+Y[N][idx]-Y[i][idx]+fun(idx+1,i);
		if(val>temp)
		{
			temp=val;
			pos=i;
		}
	}
//	cout<<endl;
//	cout<<temp<<"<--dp val for "<<idx<<","<<height<<endl;
//	cout<<pos<<"<--pos found for "<<idx<<","<<height<<endl;
	return dp[idx][height]=temp;
}

int main()
{
	ll i,j;
	while(1)
	{
		fill(dp,-1);
		fill(y,0);	
		fill(Y,0);	
		fill(b,0);	
		fill(B,0);	
		cin>>N>>M;
		if(!(N|M))
			return 0;
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
				cin>>y[i][j];
		}
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
				cin>>b[i][j];
		}
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			{
				Y[i][j]=Y[i-1][j]+y[i][j];
				B[i][j]=B[i-1][j]+b[i][j];
			}
		}
		cout<<fun(1,0)<<endl;
	}
	return 0;
}

