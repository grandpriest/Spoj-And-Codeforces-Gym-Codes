//PARTPALI - Particular Palindromes
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  fill(a,v)  memset(a, v, sizeof a)

ll dp[25][1234];
ll S,M;
ll power[20];
//meet in the middle+digit dp
ll fun(ll idx,ll val)
{

	if(dp[idx][val]!=-1)
		return dp[idx][val];
	if(idx==S/2)
	{
		if(S%2==0)
		{
			ll ans=0;
			if(val%M==0)
				ans= 1;
			return dp[idx][val]=ans;
		}
		else
		{
			ll ans=0;
			ll i,j;
			for(i=0;i<=9;i++)
			{
				if (i==0 && idx==0)
				continue;
				ll val1=(i*power[idx])%M;
				val1+=val;
				val1%=M;
				if(val1==0)
					ans++;
			}
			return dp[idx][val]=ans;
		}	
	}
	else
	{
		ll ans=0,i;
		for(i=0;i<=9;i++)
		{
			if (i==0 && idx==0)
				continue;
			ll val1=(((i*power[idx])%M)+((i*power[S-idx-1])%M))%M;
			val1+=val;
			val1%=M;
			ans+=fun(idx+1,val1);
		}
		return dp[idx][val]=ans;
	}
}

int main()
{
	ll i,j;
	ll T;
	cin>>T;
	power[0]=1;
	while(T--)
	{
		fill(dp,-1);
		cin>>M>>S;
		for(i=1;i<19;i++)
		power[i]=(power[i-1]*10)%M;
		cout<<fun(0,0)<<endl;
	}
	return 0;
}

