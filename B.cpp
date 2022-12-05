#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
int mod=1e9+7;
ll int cost(vector<ll int>&vec,vector<ll int>&dp,ll int index,ll int k)
{
    if(index==vec.size()-1)
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    ll int ans=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(index+i>=vec.size())
        {
            continue;
        }
        ans=min(ans,abs(vec[index]-vec[index+i])+cost(vec,dp,index+i,k));
    }
    return dp[index]=ans;
}
int main()
{
    fast;
    ll int n,k;
    cin>>n>>k;
    vector<ll int>vec(n);
    vector<ll int>dp(n,-1);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    cout<<cost(vec,dp,0,k);
    
    return 0;
}
