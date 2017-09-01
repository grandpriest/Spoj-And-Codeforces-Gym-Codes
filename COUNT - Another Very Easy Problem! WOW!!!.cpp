//COUNT - Another Very Easy Problem! WOW!!!
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1988
# define  ll	     long long
# define  INF	     1e18
# define  fill(a,v)  memset(a, v, sizeof a)

ll dp[5123][5123];
ll fun(ll books_left,ll trucks)
{
	if(books_left==0)
		return 1;
	if(trucks==0)
		return 0;
	if(dp[books_left][trucks]!=-1)
		return dp[books_left][trucks];
	ll i,j;
	ll ans=0;
	for(i=books_left/trucks;i>=0;i--)
	{
		ans+=fun(books_left-(i*trucks),trucks-1);
		ans%=mod;
	}
	return dp[books_left][trucks]=ans;
}
int main()
{
ll i,j;
fill(dp,-1);
while(1)
{
	ll N,K;
	cin>>N>>K;
	if(!(N|K))
		return 0;
	if(N==K)
		cout<<1<<endl;
	else
	cout<<fun(N-K,K)<<endl;
}
return 0;
}

