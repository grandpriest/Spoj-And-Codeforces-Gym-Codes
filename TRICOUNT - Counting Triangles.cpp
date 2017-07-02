#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	
	ll T;
	cin>>T;
	while(T--)
	{
		ll N;
		cin>>N;
		if(N%2==1)
		{
			ll k=(N+1)/2;
			cout<<((k*((2*k)+1)*((2*k)-1))/3)+((k*(k+1)*((4*k)-1))/6)-(k*k)<<endl;
		}	
		else
		{
			ll k=N/2;
			cout<<((k*(k+1)*((4*k)-1))/6)-((k+1)*(1+(2*((k+1)-1))))+(((k+1)*((2*(k+1))+1)*((2*(k+1))-1))/3)<<endl;
		}
	}
	return 0;
}
