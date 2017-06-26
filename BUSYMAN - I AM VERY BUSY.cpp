//BUSYMAN - I AM VERY BUSY
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		ll N;
		ll i,j;
		scanf("%lld",&N);
		pair <ll,ll> arr[N];
		for(i=0;i<N;i++)
		{
			ll X,Y;
			scanf("%lld%lld",&X,&Y);
			arr[i].first=Y;
			arr[i].second=X;		
		}
		sort(arr,arr+N);
		ll ans=0;
		ll prev=0;
		for(i=0;i<N;i++)
		{
			if(arr[i].second>=prev)
			{
				ans++;
				prev=arr[i].first;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
