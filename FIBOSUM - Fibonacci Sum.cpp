//FIBOSUM - Fibonacci Sum
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000007
# define  ll	     long long
# define  INF	     1e18
# define  fill(a,v)  memset(a, v, sizeof a)

ll matrix[3][3]={{1,1,1},{0,1,1},{0,1,0}};;
ll F[3][1]={{1},{1},{0}};
ll temp[3][3];
void mul(ll a[3][3],ll b[3][3])
{
	ll i,j,k;
	ll c[3][3];
	fill(c,0);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			ll val=0;
			for(k=0;k<3;k++)
			{
				val+=(a[i][k]*b[k][j]);
				val%=mod;
			}
			c[i][j]=val%mod;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			a[i][j]=c[i][j];
	}
}

void power(ll num)
{
	ll i,j;
	if(num==0)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
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
	ll i,j;
	ll ans=0;
	for(i=0;i<3;i++)
	{
		ans+=(temp[0][i]*F[i][0]);
		ans%=mod;
	}
	return ans;
}
int main()
{
 //matrix[3][3]={{1,1,1},{0,1,1},{0,1,0}};
 //F[3][1]={{1},{1},{0}};
ll i,j;
ll T;
scanf("%lld",&T);
while(T--)
{
	ll N,M;
	scanf("%lld%lld",&N,&M);
	N--;
	ll low;
	ll high;
	if(N<2)
	{
		if(N==1)
			low=1;
		else
			low=0;
	}
	else
	{
		fill(temp,0);
		power(N-1);
		low=calc();
	}
	if(M<2)
	{
		if(M==1)
			high=1;
		else
			high=0;
	}
	else
	{	
		fill(temp,0);
		power(M-1);
		high=calc();
	}
	printf("%lld\n",(high-low+mod)%mod);
}
return 0;
}

