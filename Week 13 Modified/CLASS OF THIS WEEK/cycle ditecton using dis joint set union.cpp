// Cycle ditection using dis joint union
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int>par(N);
vector<int>sz(N);
void make_set(int v)
{
    par[v]=v;
    sz[v]=1;
}
int find_set(int n)
{
    if(par[n]==n)return n;
    return par[n]=find_set(par[n]);
}
void unioN(int u,int v)
{
    int a=find_set(u);
    int  b=find_set(v);
    if(a!=b)
    {
        if(sz[a]<sz[b])swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
    }
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>edge;
    for(int i=1; i<=n; i++)make_set(i);
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        edge.push_back({u,v});
    }
    bool cycle=false;
    for(auto i:edge)
    {
        int u=i.first;
        int v=i.second;
        if(find_set(u)==find_set(v))
        {
            cycle=true;
            cout<<"they made cycle >> "<<u<<" "<<v<<endl;
        }
        else unioN(u,v);
    }
    return 0;
}
