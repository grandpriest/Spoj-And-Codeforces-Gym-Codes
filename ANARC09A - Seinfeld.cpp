//ANARC09A - Seinfeld
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll t=0;
	while(1)
	{
		string str;
		cin>>str;
		if(str[0]=='-')
			break;
		ll ans=0;
		stack <char>s;
		ll i,j;
		for(i=0;i<str.size();i++)
		{
			if(str[i]=='{')
			s.push(str[i]);
			else
			{
				if(s.size()!=0)
					s.pop();
				else
				{
					ans++;
					s.push(str[i]);	
				}
			}
		}
		ans+=(ll)s.size()/2;
		t++;
		printf("%lld.%lld\n",t,ans);	
	}
	return 0;
}
