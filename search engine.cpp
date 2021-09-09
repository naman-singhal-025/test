#include<bits/stdc++.h>
using namespace std;
struct trie{
    int weight;
    trie* arr[26];
};
void insert(trie* root,string s,int w)
{
    trie* it = root;
    for(int i=0;i<s.length();i++)
    {
        int pos = s[i]-'a';
        if(it->arr[pos]==NULL)
        {
            it->arr[pos] = new trie();
        }
        it = it->arr[pos];
        it->weight = max(it->weight,w);
    }
}
int query(trie* root,string s)
{
    trie* it = root;
    for(int i=0;i<s.length();i++)
    {
        int pos = s[i]-'a';
        if(it->arr[pos]!=NULL)
        it = it->arr[pos];
        else
        return -1;
    }
    return it->weight;
}
int main(){
    // write your code
    int n,q;
    cin>>n>>q;
    string s;
    int w;
    trie* root = new trie(); 
    for(int i=0;i<n;i++)
    {
        cin>>s>>w;
        insert(root,s,w);
    }
    while(q--)
    {
        cin>>s;
        cout<<query(root,s)<<endl;
    }
    return 0;
}