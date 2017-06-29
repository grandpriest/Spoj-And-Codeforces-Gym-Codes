//DSUBSEQ - Distinct Subsequences
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007 
ll dp[123456];
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		string str;
		cin>>str;
		memset(dp,0,sizeof dp);
		ll ans=1;
		for(ll i=1;i<=str.size();i++)
		{
			ll subs_ending_here=(ans-dp[str[i-1]]+mod)%mod;
			ans=((ans)%mod+(subs_ending_here)%mod)%mod;
			dp[str[i-1]]=((dp[str[i-1]])%mod+(subs_ending_here)%mod)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
