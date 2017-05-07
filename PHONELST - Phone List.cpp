//PHONELST - Phone List
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct trie
{
	ll words_ending_here;
	ll prefix_here;
	struct trie * Next[10];
	trie()
	{
		words_ending_here=0;
		prefix_here=0;
		ll k;
		for(k=0;k<10;k++)
			Next[k]=NULL;
	}
}*root;

void add(struct trie * node, string word)
{
	if(word=="")
		node->words_ending_here++;
	else
	{
		node->prefix_here++;
		ll ch=word[0]-'0';
		if(node->Next[ch]==NULL)
			node->Next[ch]=new trie();
		word.erase(word.begin());
		add(node->Next[ch],word);
	}
}

bool find(struct trie * node,string word)
{
	if(word=="")
	{
		if(node->prefix_here==0)
			return 1;
		else
			return 0;
	}
	else
	{
		ll ch=word[0]-'0';
		if(node->Next[ch]==NULL)
			node->Next[ch]=new trie();
		word.erase(word.begin());
		return find(node->Next[ch],word);
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
		root=new trie();
		string arr[N];
		for(i=0;i<N;i++)
		{
			string str;
			cin>>str;
			arr[i]=str;
			add(root,str);
		}
		bool ans=1;
		for(i=0;i<N;i++)
		ans&=find(root,arr[i]);
		if(ans==true)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}