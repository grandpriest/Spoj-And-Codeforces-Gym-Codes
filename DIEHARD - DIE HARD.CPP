//DIEHARD - DIE HARD
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[3][2123][2123];
ll arr[3][2];
ll fun(ll idx,ll A,ll B)
{
	if(dp[idx][A][B]!=-1)
	return dp[idx][A][B];
	ll temp=0;
	ll i,j;
	for(i=0;i<3;i++)
	{
		if(i!=idx)
		{
			if(A+arr[i][0]>0 && B+arr[i][1]>0)
			temp=max(temp,1+fun(i,A+arr[i][0],B+arr[i][1]));	
		}
	}
	return dp[idx][A][B]=temp;
}
int main()
{
	ll T;
	arr[0][0]=3;
	arr[0][1]=2;
	arr[1][0]=-5;
	arr[1][1]=-10;
	arr[2][0]=-20;
	arr[2][1]=5;
	scanf("%lld",&T);
	while(T--)
	{
		ll H,B;
		memset(dp,-1,sizeof dp);
		scanf("%lld%lld",&H,&B);
		ll ans=0;
		ll i,j;
		for(i=0;i<3;i++)
		{
			if(H+arr[i][0]>0 && B+arr[i][1]>0)
			ans=max(ans,1+fun(i,H+arr[i][0],B+arr[i][1]));	
		}	
		printf("%lld\n",ans);
	}
	return 0;
}
