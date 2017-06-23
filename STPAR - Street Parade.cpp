//STPAR - Street Parade
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll N;
	
	while(cin>>N)
	{
		if(N==0)
		break;
		ll arr[1234];
		ll i,j;
		for(i=0;i<N;i++)
		cin>>arr[i];
		ll req=1;
		stack<ll>s;
		for(i=0;i<N;i++)
		{
		//	cout<<req<<"<--req now "<<endl;
			if(arr[i]==req)
			{
				req++;	
				continue;
			}
			while(!s.empty())
			{
				if(s.top()==req)
				{
					s.pop();
					req++;
				}
				else
				break;
			}
			s.push(arr[i]);
		}
	//	cout<<req<<"<---req now "<<endl;
		while(!s.empty())
		{
			if(s.top()==req)
			{
				s.pop();
				req++;
			}
			else
			break;
		}
		if(req==N+1)
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0;
}
