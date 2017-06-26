//HISTOGRA - Largest Rectangle in a Histogram
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll N;
	while(1)
	{
		scanf("%lld",&N);
		if(N==0)
		break;
		ll arr[N];
		ll i,j;
		for(i=0;i<N;i++)
		scanf("%lld",&arr[i]);
		stack <ll> st;
		ll ans=0;
		i=0;
		while(i<N)
		{
			if(st.empty()||arr[st.top()]<=arr[i])
			{
				st.push(i);
				i++;
			}
			else
			{
				
			 	 ll t=st.top();
				 st.pop();
				 if(st.empty())
				 ans=max(ans,arr[t]*i);	
				 else
				 ans=max(ans,arr[t]*(i-t-1));
			}
		
		}
		while(!st.empty())
		{
			ll t=st.top();
			 st.pop();
			 ans=max(ans,arr[t]*(i-t-1));
			 if(st.empty())
			 ans=max(ans,arr[t]*i);	
		}
		printf("%lld\n",ans);
	}
	return 0;
}
