//AGGRCOW - Aggressive cows
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N,C;
ll arr[123456];
bool check(ll K)
{
	ll remain=C-1;
	ll i,j;
	i=1;
	ll prev=arr[0];
	while(i<N)
	{
		if(arr[i]-prev>=K)
		{
			prev=arr[i];
			remain--;
		}
		i++;
	}
	if(remain<=0)
	return true;
	return false;
}
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&N,&C);
		ll i,j;
		for(i=0;i<N;i++)
		scanf("%lld",&arr[i]);
		sort(arr,arr+N);
		ll L=0;
		ll R=1e10;
		ll ans=-1;
		while(L<=R)
		{
			ll mid=(L+R)/2;
			if(check(mid))
			{
				ans=mid;
				L=mid+1;
			}
			else
			R=mid-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
