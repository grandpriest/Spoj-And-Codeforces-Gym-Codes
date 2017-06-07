//FILRTEST - File Recover Testing
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lps[1234567];
int main()
{
	ll K;
	string str;
	while(1)
	{
		scanf("%lld",&K);
		cin>>str;
		if(K==-1)
		break;
		ll N=str.size();
		ll i,j;
		lps[0]=0;
		i=1;
		j=0;
		while(i<N)
		{
			if(str[i]==str[j])
			{
				lps[i]=j+1;
				j++;
				i++;
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
		ll reqd=N-lps[N-1];
		if(K<N)
		printf("0\n");
		else
		printf("%lld\n",((K-N)/reqd)+1);
	}	
	return 0;
}
