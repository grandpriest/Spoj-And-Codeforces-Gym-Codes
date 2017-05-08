//XOR Sum
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct trie
{
	ll count;
	struct trie * Next[2];
	trie()
	{
		count=0;
		Next[0]=NULL;
		Next[1]=NULL;
	}
};

void add(struct trie * node,ll num,ll pos)
{
	if(pos==-1)
		return ;
	if((num&(1<<pos))==0)
	{
		if(node->Next[0]==NULL)
			node->Next[0]=new trie();
		add(node->Next[0],num,pos-1);
	}
	else
	{
		if(node->Next[1]==NULL)
		node->Next[1]=new trie();
		add(node->Next[1],num,pos-1);
	}
}

ll query(struct trie *node,ll num,ll pos,ll ans)
{
	if(pos==-1)
		return ans;
	if((num&(1<<pos))==0)//go for 1
	{
		if(node->Next[1]==NULL)
			return query(node->Next[0],num,pos-1,ans);
		else
		{
			ans+=pow(2,pos);
			return query(node->Next[1],num,pos-1,ans);
		}
	}
	else//go for 0
	{
		if(node->Next[0]==NULL)
			return query(node->Next[1],num,pos-1,ans);
		else
		{
			ans+=pow(2,pos);
			return query(node->Next[0],num,pos-1,ans);
		}
	}
}

int main()
{
	ll T;
	ll i,j;
	scanf("%lld",&T);
	while(T--)
	{
		ll N;
		scanf("%lld",&N);
		ll arr[N];
		struct trie * root=new trie();
		ll ans=0;
		ll now=0;
		for(i=0;i<N;i++)
		{
			scanf("%lld",&arr[i]);
			now^=arr[i];
			ans=max(ans,arr[i]);
			add(root,now,31);
			ans=max(query(root,now,31,0LL),ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}