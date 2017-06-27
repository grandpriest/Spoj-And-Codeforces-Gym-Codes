//ONEZERO - Ones and zeros
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		ll K;
		scanf("%lld",&K);
		queue < pair <ll,ll> > q;
		q.push(make_pair(1,1));
		ll ans=0;
		while(!q.empty())
		{
			pair<ll,ll> f=q.front();
			q.pop();
			if(f.second%K==0)
			{
				ans=f.first;
				break;
			}
			q.push(make_pair(2*f.first,((f.second)%K)*10));
			q.push(make_pair(2*f.first+1,(((f.second)%K)*10)+1));	
		}
		bool f=0;
		for(ll i=60;i>=0;i--)
		{
			ll temp=1LL<<i;
			if((temp&ans)==0 && f==1)
			printf("0");
			if((temp&ans)!=0)
			{
				printf("1");
				f=1;
			}
		}
		printf("\n");
	}
	return 0;
}
