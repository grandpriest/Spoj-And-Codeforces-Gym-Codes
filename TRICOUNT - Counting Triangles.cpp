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
//			ll temp1=(k*((2*k)+1)*((2*k)-1))/3;
//			temp1+=(k*(k+1)*((4*k)-1))/6;
//			temp1-=k*k;
//			cout<<temp1<<endl;	
			cout<<((k*((2*k)+1)*((2*k)-1))/3)+((k*(k+1)*((4*k)-1))/6)-(k*k)<<endl;
		}	
		else
		{
			ll k=N/2;
//			ll temp1=(k*(k+1)*((4*k)-1))/6;
//			k++;
//			temp1-=k*(1+(2*(k-1)));
//			temp1+=(k*((2*k)+1)*((2*k)-1))/3;
//			cout<<temp1<<endl;
			cout<<((k*(k+1)*((4*k)-1))/6)-((k+1)*(1+(2*((k+1)-1))))+(((k+1)*((2*(k+1))+1)*((2*(k+1))-1))/3)<<endl;
		}
	}
	return 0;
}
