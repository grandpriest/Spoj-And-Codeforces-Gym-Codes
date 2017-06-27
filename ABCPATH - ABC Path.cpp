//ABCPATH - ABC Path
#include<bits/stdc++.h>
using namespace std;
#define ll long long
char arr[55][55];
ll H,W;
ll dp[55][55];
vector <pair<ll,ll> > start;
ll fun(ll x,ll y)
{
	//cout<<x<<","<<y<<"<--pos now "<<arr[x][y]<<"<--ele now "<<endl;
	if(dp[x][y]!=-1)
	return dp[x][y];
	ll temp=0;
	
	if(arr[x-1][y]==arr[x][y]+1)
	temp=max(temp,1+fun(x-1,y));
	
	if(arr[x+1][y]==arr[x][y]+1)
	temp=max(temp,1+fun(x+1,y));
	
	if(arr[x][y+1]==arr[x][y]+1)
	temp=max(temp,1+fun(x,y+1));
	
	if(arr[x][y-1]==arr[x][y]+1)
	temp=max(temp,1+fun(x,y-1));
	
	if(arr[x+1][y+1]==arr[x][y]+1)
	temp=max(temp,1+fun(x+1,y+1));

	if(arr[x+1][y-1]==arr[x][y]+1)
	temp=max(temp,1+fun(x+1,y-1));

	if(arr[x-1][y-1]==arr[x][y]+1)
	temp=max(temp,1+fun(x-1,y-1));

	if(arr[x-1][y+1]==arr[x][y]+1)
	temp=max(temp,1+fun(x-1,y+1));
	
	return dp[x][y]=temp;
}
int main()
{
	ll test=0;
	while(1)
	{
		scanf("%lld%lld",&H,&W);
		if(H==0)
		break;
		memset(dp,-1,sizeof dp);
		memset(arr,0,sizeof arr);
		start.clear();
		ll i,j;
		for(i=1;i<=H;i++)
		{
			string str;
			cin>>str;
			for(j=1;j<=W;j++)
			{
				arr[i][j]=str[j-1];
				if(str[j-1]=='A')
				start.push_back(make_pair(i,j));
			}
		}
	//	cout<<start.size()<<"<--statr"<<endl;
		ll ans=0;
		for(i=0;i<start.size();i++)
		ans=max(ans,1+fun(start[i].first,start[i].second));
		test++;
		printf("Case %lld: %lld\n",test,ans);
	}
	return 0;
}
