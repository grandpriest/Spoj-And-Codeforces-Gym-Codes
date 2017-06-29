//DSUBSEQ - Distinct Subsequences
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007 
ll dp[123456];
ll ans[123456];
ll pre[200];
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		string str;
		memset(dp,0,sizeof dp);
		memset(ans,0,sizeof ans);
		memset(pre,0,sizeof pre);	
		cin>>str;
		ll i,j;
		ans[0]=1;
		dp[0]=1;
		for(i=1;i<=str.size();i++)
		{
			if(pre[str[i-1]]!=-1)
			dp[i]=(ans[i-1]-pre[str[i-1]]+mod)%mod;
			else
			dp[i]=ans[i-1];
			ans[i]=ans[i-1]+dp[i];
			ans[i]%=mod;
			pre[str[i-1]]+=dp[i];
			pre[str[i-1]]%=mod;	
		
		}
		ans[str.size()]%=mod;
		cout<<ans[str.size()]<<endl;
	}
	return 0;
}
