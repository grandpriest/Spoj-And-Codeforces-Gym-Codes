//SCUBADIV - Scuba diver
#include<bits/stdc++.h>
using namespace std;
#define ll int
struct vessels
{
	ll oxy;
	ll nitro;
	ll weight;
};
vessels arr[1001];
ll dp[1001][22][80];
ll N;
ll fun(ll idx,ll Oxy,ll Nitro)
{
	if(Oxy==0 && Nitro==0)
	return 0;
	if(idx==N)
	return 1e9;
	if(dp[idx][Oxy][Nitro]!=-1)
	return dp[idx][Oxy][Nitro];
	ll temp=arr[idx].weight+fun(idx+1,max(0,Oxy-arr[idx].oxy),max(0,Nitro-arr[idx].nitro));
	temp=min(temp,fun(idx+1,Oxy,Nitro));
	return dp[idx][Oxy][Nitro]=temp;
}
int main()
{
	ll T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,-1,sizeof dp);
		ll Oxy,Nitro;
			scanf("%d%d",&Oxy,&Nitro);;
			scanf("%d",&N);
			for(ll i=0;i<N;i++)
			scanf("%d%d%d",&arr[i].oxy,&arr[i].nitro,&arr[i].weight);
			printf("%d\n",fun(0,Oxy,Nitro));		
	}
	return 0;
}
