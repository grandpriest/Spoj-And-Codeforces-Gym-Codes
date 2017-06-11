//ADFRUITS - Advanced Fruits
#include<bits/stdc++.h>
using namespace std;
#define ll long long
string str1,str2,lcs;
ll dp[123][123];
ll fun(ll idx1,ll idx2)
{
	if(idx1==str1.size()|| idx2==str2.size())
	return 0;
	if(dp[idx1][idx2]!=-1)
	return dp[idx1][idx2];
	if(str1[idx1]==str2[idx2])
	return dp[idx1][idx2]=1+fun(idx1+1,idx2+1);
	return dp[idx1][idx2]=max(fun(idx1+1,idx2),fun(idx1,idx2+1));
}
void generate(ll idx1,ll idx2)
{
	
	if(idx1==str1.size()|| idx2==str2.size())
	return ;
	if(str1[idx1]==str2[idx2])
	{
		lcs+=str1[idx1];
		generate(idx1+1,idx2+1);
	}
	else
	{
		if(dp[idx1+1][idx2]>=dp[idx1][idx2+1])
		generate(idx1+1,idx2);
		else
		generate(idx1,idx2+1);
	}
}
int main()
{
	while(cin>>str1)
	{
		cin>>str2;
		memset(dp,-1,sizeof dp);
		lcs="";
		fun(0,0);
		generate(0,0);
	//	cout<<lcs<<"<--lcs"<<endl;
		ll i,j,k;
		i=0;j=0;k=0;
		string ans="";
		while(i<str1.size())
		{
			if(k==lcs.size())
			break;
			if(j==str2.size())
			{
				ans+=str1[i];
				i++;
				continue;
			}
			if(str2[j]!=lcs[k])
			{
				ans+=str2[j];
				j++;
			}
			else
			{
				while(str2[j]!=str1[i] && i<str1.size())
				{
					ans+=str1[i];
					i++;
				}
				ans+=str2[j];
				j++;
				i++;
				k++;
			}
		}
		if(i!=str1.size())
		{
			while(i<str1.size())
			{
				ans+=str1[i];
				i++;
			}
		}
		
		if(j!=str2.size())
		{
			while(j<str2.size())
			{
				ans+=str2[j];
				j++;
			}
		}
		cout<<ans<<endl;
	}
	return  0;
}
