//ALIEN - Aliens at the train
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll T;
	cin>>T;
	while(T--)
	{
		ll  i,j;
		ll ans1=1e18,ans2=0;
		ll N,K;
		cin>>N>>K;
		ll arr[N];
		for(i=0;i<N;i++)
		cin>>arr[i];
		ll start=0;
		ll sum=0;
		for(i=0;i<N;i++)
		{
			sum+=arr[i];
			while(sum>K)
			{
				sum-=arr[start];
				start++;
			}
			if(i-start+1>ans2)
			{
				ans2=i-start+1;
				ans1=sum;
			}
			else if(i-start+1==ans2)
			{
				ans2=i-start+1;
				ans1=min(ans1,sum);
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
