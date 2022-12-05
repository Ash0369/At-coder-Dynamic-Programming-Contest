#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
int mod=1e9+7;
ll int knapsack(vector<ll int>&weight,vector<ll int>&value,  vector<vector<ll int>>&dp,ll int index,ll int n,ll int curr,ll int w)
{
    if(index==n)
    {
        return 0;
    }
    if(dp[index][curr]!=-1)
    {
        return dp[index][curr];
    }
    ll int choose=0;
    ll int not_choose=knapsack(weight,value,dp,index+1,n,curr,w);

    if(curr+weight[index]<=w)
    {
        choose=value[index]+knapsack(weight,value,dp,index+1,n,curr+weight[index],w);
    }  

    return dp[index][curr]=max(choose,not_choose);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    ll int n,w;
    cin>>n>>w;
    vector<ll int>weight(n);
    vector<ll int>value(n);
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
        cin>>value[i];
    }
    int total=0;
    vector<vector<ll int>>dp(n+1,vector<ll int>(w+1,-1));
    cout<<knapsack(weight,value,dp,0,n,0,w);
    return 0;
}
