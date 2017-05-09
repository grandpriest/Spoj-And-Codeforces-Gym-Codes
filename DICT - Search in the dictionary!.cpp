//DICT - Search in the dictionary!
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <string> v;
struct trie
{
	bool word_ending_here;
	struct trie * Next[26];
	trie()
	{
		word_ending_here=0;
		ll k;
		for(k=0;k<26;k++)
			Next[k]=NULL;
	}
};

void add(struct trie * node,string word)
{
	//cout<<word<<"<--word now"<<endl;
	if(word=="")
		node->word_ending_here=true;
	else
	{
		ll ch=word[0]-'a';
		if(node->Next[ch]==NULL)
			node->Next[ch]=new trie();
		word.erase(word.begin());
		add(node->Next[ch],word);
	}
}

void query(struct trie * node,string word,string ans)
{
	ll i,j;
	if(word=="")
	{
		if(node->word_ending_here==true)
			v.push_back(ans);
		for(i=0;i<26;i++)
		{
			if(node->Next[i]!=NULL)
			{
				string temp=ans;
				char ch=i+'a';
				temp+=ch;
				query(node->Next[i],word,temp);
			}
		}
	}
	else
	{
		ll ch=word[0]-'a';
		if(node->Next[ch]==NULL)
			return;
		ans+=word[0];
		word.erase(word.begin());
		query(node->Next[ch],word,ans);
	}
}
int main()
{
	ll N;
	scanf("%lld",&N);
	ll i,j;
	struct trie * root=new trie();
	for(i=0;i<N;i++)
	{
		string str;
		cin>>str;
		add(root,str);
	}
	ll K;
	scanf("%lld",&K);
	string temp="";
	for(j=1;j<=K;j++)
	{
		string str;
		cin>>str;
		v.clear();
		query(root,str,temp);
		printf("Case #%lld:\n",j);
		if(v.size()==0)
			printf("No match.\n");
		else
		{
			for(i=0;i<v.size();i++)
			{
				if(v[i]!=str)
				cout<<v[i]<<endl;	
			}
		}
	}
	return 0;
}