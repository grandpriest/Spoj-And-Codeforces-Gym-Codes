//HOTELS - Hotels Along the Croatian Coast
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll N,M;
	cin>>N>>M;
	ll arr[N];
	ll i,j;
	for(i=0;i<N;i++)
	cin>>arr[i];
	ll start=0;
	ll sum=0;
	ll ans=0;
	for(i=0;i<N;i++)
	{
		sum+=arr[i];
		while(sum>M)
		{
			sum-=arr[start];
			start++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
