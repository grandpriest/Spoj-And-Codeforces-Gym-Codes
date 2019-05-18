//Dhara
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll arr[1234567];

int main()
{
	ll i, j;	
	ll T;
	memset(arr,0,sizeof arr);
	for(i=1;i<1234567;i++)
		arr[i]=i;
	for(i=2;i<1234567;i++)
	{
		if(arr[i]==i)
		{
			arr[i]=i-1;
			for(j=2*i;j<1234567;j+=i)//seive
				arr[j]=(arr[j]/i) *(i-1);
		}
	}
	// for(i=1;i<=20;i++)
	// 	cout<<i<<"-->"<<arr[i]<<endl;
	for(i=2;i<1234567;i++)
		arr[i]+=arr[i-1];
	cin>>T;
	while(T--)
	{
		ll N;
		cin>> N;
		cout<<2*arr[N]-1<<endl;
	}
	return 0;
}