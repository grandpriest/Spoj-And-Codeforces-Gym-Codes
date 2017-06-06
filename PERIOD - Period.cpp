//PERIOD - Period
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lps[1234567];
vector< pair<ll,ll> > ans;
int main()
{
	ll T;
	scanf("%lld",&T);
	for(ll test=1;test<=T;test++)
	{
		ll N;
		scanf("%lld",&N);
		ans.clear();
		string str;
		cin>>str;
		lps[0]=0;
		ll i,j;
		i=1;
		j=0;
		while(i<N)
		{
			if(str[i]==str[j])
			{
				lps[i]=j+1;
				i++;
				j++;
			}
			else
			{
				if(j!=0)
				j=lps[j-1];
				else
				{
					lps[i]=0;
					i++;
				}
			}
		}
		
		printf("Test case #%lld\n",test);
		for(i=1;i<N;i++)
		{
			if(lps[i]==0)
			continue;
			ll temp=(i+1)-lps[i];
			if((i+1)%temp==0)
			printf("%lld %lld\n",i+1,(i+1)/temp);
		}
		printf("\n");
	}
	return 0;
}
