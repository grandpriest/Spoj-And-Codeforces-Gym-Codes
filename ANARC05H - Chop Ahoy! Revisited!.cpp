//ANARC05H - Chop Ahoy! Revisited!
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
string str;
ll dp[31][305];
ll fun(ll idx,ll prev)
{
	if(idx==-1)
	return 1;
	if(dp[idx][prev]!=-1)
	return dp[idx][prev];
	ll sum=0;
	ll temp=0;
	ll i,j;
	for(i=idx;i>=0;i--)
	{
		sum+=str[i]-'0';
		if(sum<=prev)
		temp+=fun(i-1,sum);
	}
return dp[idx][prev]=temp;
}

int main()
{
	ll test=0;
	while(1)
	{
		cin>>str;
		if(str=="bye")
		break;
		memset(dp,-1,sizeof dp);
		test++;
		printf("%lld. %lld\n",test,fun(str.size()-1,300));	
	}
	return 0;
}
