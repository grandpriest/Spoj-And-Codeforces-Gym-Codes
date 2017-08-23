//TETRASUM - Sum of Tetranacci numbers (easy)
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  fill(a,v)  memset(a, v, sizeof a)

ll matrix[5][5]={{1,1,1,1,1},{0,1,1,1,1},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0}};
ll F[5]={1,1,0,0,0};
ll temp[5][5];
void mul(ll a[5][5],ll b[5][5])
{
	ll c[5][5];
	fill(c,0);
	ll i,j,k;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			ll val=0;
			for(k=0;k<5;k++)
			{
				val+=(a[i][k]*b[k][j]);
				val%=mod;
			}
			c[i][j]=val%mod;
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			a[i][j]=c[i][j];
	}
}
void  power(ll num)
{
	if(num==0)
	{
		ll i,j;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
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
	for(i=0;i<5;i++)
	{
		ans+=temp[0][i]*F[i];
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
	ll M,N;
	scanf("%lld%lld",&M,&N);
	ll low,high;
	if(M<=4)
	{	
		if(M<=3)
			low=0;
		if(M==4)
			low=1;
	}
	else
	{
		M--;
		fill(temp,0);
		power(M-3);
		low=calc();
	}
	if(N<=3)
	{	
		if(M<3)
			high=0;
		if(N==3)
			high=1;
	}
	else
	{
		fill(temp,0);
		power(N-3);
		high=calc();
	}
	printf("%lld\n",(high-low+mod)%mod);
}
return 0;
}

