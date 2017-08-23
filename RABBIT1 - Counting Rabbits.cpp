//RABBIT1 - Counting Rabbits
# include <bits/stdc++.h>
using namespace std;

# define  ll	     long long
# define  INF	     1e18
# define  fill(a,v)  memset(a, v, sizeof a)

ll mod;
ll matrix[2][2]={{1,1},{1,0}};
ll F[2]={1,0};
ll temp[2][2];
void mul(ll a[2][2],ll b[2][2])
{
	ll i,j,k;
	ll c[2][2];
	fill(c,0);
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			ll val=0;
			for(k=0;k<2;k++)
			{
				val+=(a[i][k]*b[k][j]);
				val%=mod;
			}
			c[i][j]=val;
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			a[i][j]=c[i][j];
	}
}
ll power(ll num)
{
	if(num==0)
	{
		ll i,j;
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
				temp[i][j]=0;
			temp[i][i]=1;
		}
	}
	else if(num%2==1)
	{
		power(num-1);
		mul(temp,matrix);
	}
	else
	{
		power(num/2);
		mul(temp,temp);
	}
}
ll calc()
{
	ll ans=0;
	ll i,j;
	for(i=0;i<2;i++)
	{
		ans+=(temp[0][i]*F[i]);
		ans%=mod;
	}
	return ans;
}
int main()
{
ll i,j;
ll T;
scanf("%lld",&T);
while(T--)
{
	ll N,M;
	scanf("%lld%lld",&N,&M);
	mod=pow(2,M);
	fill(temp,0);
	power(N);
	ll ans=calc();
	cout<<ans<<endl;
}
return 0;
}

