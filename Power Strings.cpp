//Power Strings
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lps[1234567];
int main()
{
	while(1)
	{
		string str;
		cin>>str;
		if(str==".")
		break;
		lps[0]=0;
		ll i,j;
		j=0;
		i=1;
		ll N=str.size();
		while(i<N)
		{
			if(str[i]==str[j])
			{
				lps[i]=j+1;
				i++;
				j++;
			}
			else
			{
				if(j!=0)
					j=lps[j-1];
				else
				{
					lps[i]=0;
					i++;
				}
			}
		}
		ll ans=N-lps[N-1];
		if(N%ans==0)
		printf("%lld\n",N/ans);	
		else
		printf("1\n");
	}
	return 0;
}
