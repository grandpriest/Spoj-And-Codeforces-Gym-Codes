//COURIER - The Courier
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)

ll N,M,B;
ll dist[123][123];
ll dp[1<<12][100];
struct data
{
	ll start;
	ll end;
};
data parcels[12];
ll tot_parcels;

ll fun(ll mask,ll prev)
{
	//cout<<mask<<"<--mask "<<prev<<"<--prev now"<<endl;
	if(mask==((1<<tot_parcels)-1))
		return dp[mask][prev]=dist[prev][B];
	if(dp[mask][prev]!=-1)
		return dp[mask][prev];
	ll temp=INF;
	ll i,j;
	for(i=0;i<tot_parcels;i++)
	{
		if((mask&(1<<i))==0)
			temp=min(temp,dist[prev][parcels[i].start]+dist[parcels[i].start][parcels[i].end]+fun((mask|(1<<i)),parcels[i].end));
	}
	return dp[mask][prev]=temp;
}

int main()
{
ll i,j,k;
ll T;
scanf("%lld",&T);
while(T--)
{
	fill(dp,-1);
	scanf("%lld%lld%lld",&N,&M,&B);
	for(i=0;i<123;i++)
	{
		for(j=0;j<123;j++)
		{
			if(i!=j)
				dist[i][j]=INF;
			else
				dist[i][j]=0;
		}
	}
	while(M--)
	{
		ll X,Y,Z;
		scanf("%lld%lld%lld",&X,&Y,&Z);
		dist[X][Y]=Z;
		dist[Y][X]=Z;
	}
	//floyd warshal
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			for(k=1;k<=N;k++)
				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
		}
	}
	ll Q;
	scanf("%lld",&Q);
	tot_parcels=0;
	while(Q--)
	{
		ll S,E,times;
		scanf("%lld%lld%lld",&S,&E,&times);
		for(i=0;i<times;i++)
		{
			parcels[tot_parcels].start=S;
			parcels[tot_parcels].end=E;
			tot_parcels++;
		}
	}
	/*
	cout<<tot_parcels<<"<--tot_parcels"<<endl;
	for(i=0;i<tot_parcels;i++)
		cout<<parcels[i].start<<" to "<<parcels[i].end<<endl;
	*/printf("%lld\n",fun(0,B));
}
return 0;
}

