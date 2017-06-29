//TWOSQRS - Two squares or not two squares
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	vector <ll> v;
	for(ll  i=0;i<=1e6;i++)
	v.push_back(i*i);
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		ll N;
		scanf("%lld",&N);
		ll L=0;
		ll R=v.size()-1;
		bool f=0;
		while(L<=R)
		{
			if(v[L]+v[R]==N)
			{
				f=1;
				break;
			}
			else if(v[L]+v[R]>N)
				R--;
			else
				L++;	
		}
		if(f==1)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;	
	}
	return 0;
}

