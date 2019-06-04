// Dhara	
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll i,j;
	ll N;
	cin>> N;
	ll arr[N][N];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			cin>>arr[i][j];
	}
	ll ans=0;
	vector < pair<ll,ll> > final1;
	vector < pair<ll,ll> > temp;
	for(i=0;i<N/2;i++)
	{
		ll sum=0;
		temp.clear();
		ll k=i;
		for(ll j=N/2;j>=i;j--)
		{
			sum+=arr[k][j];
			temp.push_back({k,j});
			k++;
		}
		for(ll j=i+1;j<=N/2;j++)
		{
			sum+=arr[k][j];
			temp.push_back({k,j});
			k++;
		}
		k=i+1;
		for(ll j=(N/2)+1;j<N-i;j++)
		{
			sum+=arr[k][j];
			temp.push_back({k,j});
			k++;
		}
		for(ll j=N-i-2;j>N/2;j--)
		{
			sum+=arr[k][j];
			temp.push_back({k,j});
			k++;
		}
		if(ans<sum)
		{
			ans=sum;
			final1=temp;
		}	
	}
	sort(final1.begin(), final1.end());
	for(i=0;i<final1.size();i++)
		cout<<arr[final1[i].first][final1[i].second]<<" ";cout<<endl;
	cout<<ans<<endl;

	return 0;
}
//sample test
/*
5
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

*/