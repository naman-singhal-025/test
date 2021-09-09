#include<bits/stdc++.h>
using namespace std;
struct event{
    int l,r,val,qind;
};
bool compare(event &e1,event &e2)
{
    if(e1.val==e2.val)
        return e1.l>e2.l;
    return e1.val>e2.val;
}
int resp(int x)
{
    return (x&(-x));
}
void update(int idx,vector<int> &bit,int val,int n)
{
    for(;idx<=n;idx+=resp(idx))
    {
        bit[idx]+=val;
    }
}
int query(int idx,vector<int> &bit)
{
    int sum=0;
    for(;idx>0;idx-=resp(idx))
    {
        sum+=bit[idx];
    }
    return sum;
}
int main(){
    
    // write your code here
    int n;
    cin>>n;
    vector<event> vec(n);
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        vec[i].l=0;
        vec[i].r=i+1;
        vec[i].val=a;
        vec[i].qind=0;
    }
//     for(int i=0;i<vec.size();i++)
//         cout<<vec[i].val<<" ";
//     cout<<endl;
    int q;
    cin>>q;
    vec.resize(n+q);
    for(int i=0;i<q;i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        vec[n+i].l=l;
        vec[n+i].r=r;
        vec[n+i].val=k;
        vec[n+i].qind=i;
    }
    sort(vec.begin(),vec.end(),compare);
    vector<int> bit(n+1,0);
    vector<int> ans(q);
//     for(int i=0;i<vec.size();i++)
//         cout<<vec[i].l<<" "<<vec[i].r<<" "<<vec[i].val<<" "<<endl;
//     cout<<endl;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i].l==0)
        {
            update(vec[i].r,bit,1,n);
        }
        else
        {
            ans[vec[i].qind]=query(vec[i].r,bit)-query(vec[i].l-1,bit);
        }
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
    return 0;
}

