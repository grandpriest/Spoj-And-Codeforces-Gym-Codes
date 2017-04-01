//Triangle Formation
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  mp         make_pair
# define  pb         push_back
# define  fill(a,v)  memset(a, v, sizeof a)

ll N;
ll arr[15];
ll dp[1<<15];

ll fun(ll mask)
{
	//cout<<mask<<"<--mask now"<<endl;
	if(mask==(1<<N)-1)
		return 0;
	if(dp[mask]!=-1)
		return dp[mask];
	ll temp=0;
	ll i,j,k;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i!=j)
			{
				for(k=0;k<N;k++)
				{
					if(k!=i && k!=j)
					{
						//cout<<i<<","<<j<<","<<k<<"<--taken values"<<endl;
						if(((mask&(1<<i))==0) && ((mask&(1<<j))==0) && ((mask&(1<<k))==0))
						{
							ll sum1=arr[i]+arr[j];
							ll sum2=arr[j]+arr[k];
							ll sum3=arr[i]+arr[k];
						//	cout<<sum1<<","<<sum2<<","<<sum3<<"<--sums"<<endl;
							if(sum1>arr[k] && sum2>arr[i] && sum3>arr[j])
								temp=max(temp,1+fun(mask|(1<<i)|(1<<j)|(1<<k)));
						}
					}
				}
			}
		}
	}
	return dp[mask]=temp;
}

int main()
{
ll i,j;
fill(dp,-1);
scanf("%lld",&N);
for(i=0;i<N;i++)
	scanf("%lld",&arr[i]);
printf("%lld\n",fun(0));
return 0;
}

