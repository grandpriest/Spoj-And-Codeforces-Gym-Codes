//NHAY - A Needle in the Haystack
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll Z[5*1234567];
int main()
{
	ll N;
	string needle;
	string hay;
	while(cin>>N)
	{
		cin>>needle;
		cin>>hay;
		string str=needle+"$"+hay;
		Z[0]=0;
		ll i,j;
		ll L=0,R=0;
		bool f=0;
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
			if(Z[i]==N)
			{
				printf("%lld\n",i-N-1);
				f=1;
			}
		}
		if(f==0)
		printf("\n");
	}
	return 0;
}

