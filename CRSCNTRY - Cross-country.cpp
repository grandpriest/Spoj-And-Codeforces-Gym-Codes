//CRSCNTRY - Cross-country
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[2123][2123];
vector <ll> girl;
vector <ll> boy;
ll fun(ll idx1,ll idx2)
{
	if(idx1==boy.size()||idx2==girl.size())
	return 0;
	if(dp[idx1][idx2]!=-1)
	return dp[idx1][idx2];
	if(boy[idx1]==girl[idx2])
	return dp[idx1][idx2]=1+fun(idx1+1,idx2+1);
	return dp[idx1][idx2]=max(fun(idx1+1,idx2),fun(idx1,idx2+1));
}
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		girl.clear();
		while(1)
		{
			ll X;
			scanf("%lld",&X);
			if(X==0)
			break;
			girl.push_back(X);
		}	
		ll ans=0;
		while(1)
		{
			boy.clear();
			while(1)
			{
				ll X;
				scanf("%lld",&X);
				if(X==0)
				break;
				boy.push_back(X);
			}
			if(boy.size()==0)
			break;
			memset(dp,-1,sizeof dp);
			ans=max(ans,fun(0,0));
		}	
		printf("%lld\n",ans);
	}
	return 0;
}
