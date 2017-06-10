//ACODE - Alphacode
# include <bits/stdc++.h>
using namespace std;
# define  ll	     long long
ll dp[5123];
string str;
ll N;
 
ll fun(ll idx)
{
	if(idx<=0)
		return 1;
	if(dp[idx]!=-1)
		return dp[idx];
	if(str[idx]=='0')
		return dp[idx]=fun(idx-2);
		if(str[idx-1]=='0')
		return dp[idx]=fun(idx-1);
	if(str[idx-1]>'2')
		return dp[idx]=fun(idx-1);
	if(str[idx-1]=='1')
		return dp[idx]=fun(idx-1)+fun(idx-2);
	if(str[idx-1]=='2')
	{
		if(str[idx]<='6')
		return dp[idx]=fun(idx-1)+fun(idx-2);
		else
		return dp[idx]=fun(idx-1);	
	}
}
int main()
{
ll i,j;
while(1)
{
	cin>>str;
	if(str=="0")
		break;
		memset(dp,-1,sizeof dp);
	bool f=0;
	N=str.size();
	for(i=1;i<str.size();i++)
	{
		if(str[i]=='0' && str[i-1]!='2' && str[i-1]!='1')
		f=1;
	}
	if(f==1)
		printf("0\n");
	else
		printf("%lld\n",fun(N-1));
}
return 0;
}
