//HIST2 - Histogram
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)

ll N;
ll dp[1<<15][15];
ll arr[16];
ll dp2[1<<15][15];

ll fun(ll mask,ll prev)
{
	if(mask==(1<<N)-1)
		return dp[mask][prev]=arr[prev];
	if(dp[mask][prev]!=-1)
		return dp[mask][prev];
	ll temp=0;
	ll i,j;
	for(i=0;i<N;i++)
	{
		if((mask&(1<<i))==0)
			temp=max(temp,abs(arr[i]-arr[prev])+fun((mask|(1<<i)),i));
	}
	return dp[mask][prev]=temp;
}

ll fun2(ll mask,ll prev)
{

	//cout<<mask<<","<<arr[prev]<<"<--state now"<<endl;
	if(mask==(1<<N)-1)
		return dp2[mask][prev]=1;
	if(dp2[mask][prev]!=-1)
		return dp2[mask][prev];
	ll temp=0;
	ll maxval=0;
	ll i,j;
	
	for(i=0;i<N;i++)
	{
		if((mask&(1<<i))==0)
		maxval=max(maxval,abs(arr[i]-arr[prev])+dp[mask|(1<<i)][i]);
	}
	
	for(i=0;i<N;i++)
	{
		if((abs(arr[i]-arr[prev])+dp[(mask|(1<<i))][i])==maxval && (mask&(1<<i))==0)
			temp+=fun2((mask|(1<<i)),i);
	}

	return  dp2[mask][prev]=temp;
}
int main()
{
ll i,j;
while(1)
{
	fill(dp,-1);
	fill(dp2,-1);
	scanf("%lld",&N);
	if(N==0)
		break;
	arr[0]=0;
	for(i=0;i<N;i++)
		scanf("%lld",&arr[i]);
	ll maxval=0;
	for(i=0;i<N;i++)
		maxval=max(maxval,arr[i]+fun((0|(1<<i)),i));
	printf("%lld ",maxval+(2*N));
	ll Count=0;
	for(i=0;i<N;i++)
	{
		if((dp[(0|(1<<i))][i]+arr[i])==maxval)
		{
		//	cout<<":::New start"<<endl;
			Count+=fun2(1<<i,i);
		}
	}
	printf("%lld\n",Count);
}
return 0;
}

