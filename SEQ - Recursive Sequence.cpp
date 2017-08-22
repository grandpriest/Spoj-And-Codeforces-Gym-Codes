//SEQ - Recursive Sequence
# include <bits/stdc++.h>
using namespace std;

# define  mod 	     1000000000
# define  ll	     long long
# define  INF	     1e18
# define  fill(a,v)  memset(a, v, sizeof a)

ll M[11][11];
ll F[11][1];
ll temp[11][11];
void print(ll arr1[11][11],ll size_mat)
{
	ll i,j;
	cout<<"M now "<<endl;
	for(i=0;i<size_mat;i++)
	{
		for(j=0;j<size_mat;j++)
			cout<<arr1[i][j]<<" ";
		cout<<endl;
	}

}

void mul(ll arr1[11][11],ll arr2[11][11],ll size_mat)
{
	ll arr3[11][11];
	fill(arr3,0);
	ll i,j,k;
	for(i=0;i<size_mat;i++)
	{
		for(j=0;j<size_mat;j++)
		{
			ll val=0;
			for(k=0;k<size_mat;k++)
			{
				val+=(arr1[i][k]*arr2[k][j]);
				val%=mod;
			}
			arr3[i][j]=val%mod;
		}
	}
	for(i=0;i<size_mat;i++)
	{
		for(j=0;j<size_mat;j++)
			arr1[i][j]=arr3[i][j];
	}
}
void power(ll power_remain,ll size_mat)
{
	//cout<<power_remain<<"<--power_remain nmow "<<size_mat<<"<---size_mat npw"<<endl;
	ll i,j;
	if(power_remain==0)
	{
		for(i=0;i<size_mat;i++)
		{
			for(j=0;j<size_mat;j++)
				temp[i][j]=0;
			temp[i][i]=1;
		}
	}
	else if(power_remain%2==1)
	{
		power(power_remain-1,size_mat);
		mul(temp,M,size_mat);
		//cout<<power_remain<<"<--when this is power_remain then M is"<<endl;
		//print(M,size_mat);
	}
	else
	{
		power(power_remain/2,size_mat);
		mul(temp,temp,size_mat);
		//cout<<power_remain<<"<--when this is power_remain then temp is"<<endl;
		//print(temp,size_mat);
	}
}
int main()
{
ll i,j;
ll T;
scanf("%lld",&T);
while(T--)
{
	fill(M,0);
	fill(F,0);
	ll K;
	scanf("%lld",&K);
	for(i=K-1;i>=0;i--)
		scanf("%lld",&F[i][0]);
	for(i=0;i<K;i++)
		scanf("%lld",&M[0][i]);
	
	for(i=1;i<K;i++)
	{
		for(j=0;j<K;j++)
		{
			if(i-1==j)
			M[i][j]=1;
		}
	}
	ll N;
	scanf("%lld",&N);
	if(N<=K)
		printf("%lld\n",F[K-N][0]%mod);
	else
	{
		power(N-K,K);
		ll ans=0;
		for(i=0;i<K;i++)
		{
			ans+=(temp[0][i]*F[i][0]);
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
}
return 0;
}

