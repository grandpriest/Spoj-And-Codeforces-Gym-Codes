// Periodic Strings
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll Z[123456];
int main()
{
	ll T;
	
	while(1)
	{
		string str;
		cin>>str;
		if(str=="*")
		break;
		ll L=0;
		ll R=0;
		ll i,j;
		ll maxval=0;
		ll pos=-1;
		Z[0]=0;
		for(i=1;i<str.size();i++)
		{
			Z[i]=0;
			if(i<=R)
			Z[i]=min(Z[i-L],R-i+1);
			while(i+Z[i]<str.size())
			{
				if(str[Z[i]]==str[i+Z[i]])
				Z[i]++;
				else
				break;	
			}
			if(i+Z[i]-1>R)
			{
				L=i;
				R=i+Z[i]-1;	
			}	
			if(Z[i]==str.size()-i && Z[i]%i==0)
			maxval=max(maxval,Z[i]);
		}
		
		cout<<maxval<<"<--max val"<<endl;	
		maxval=str.size()-maxval;
		printf("%lld\n",str.size()/maxval);
	}
	return 0;
}
