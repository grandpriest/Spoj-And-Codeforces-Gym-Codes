//EPALIN - Extend to Palindrome
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lps[123456];
int main()
{
	string str;
	while(cin>>str)
	{
		string ans=str;
		string temp=str;
		reverse(temp.begin(),temp.end());
		str=temp+"#"+str;
		ll i,j;
		lps[0]=0;
		i=1;
		j=0;
		ll N=str.size();
		ll M=temp.size();
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
		i=N-lps[N-1]-1;
		while(i>temp.size())
		{
			ans+=str[i];
			i--;
		}
		cout<<ans<<endl;
	}	
	return 0;
}
