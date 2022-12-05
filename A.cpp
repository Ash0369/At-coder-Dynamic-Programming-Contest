#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
int mod=1e9+7;
ll int cost(vector<ll int>&vec,vector<ll int>&dp,ll int index)
{
    if(index==0)
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    ll int one=INT_MAX;
    ll int two=INT_MAX;
    one=abs(vec[index]-vec[index-1])+cost(vec,dp,index-1);
    if(index>1)
    {
        two=abs(vec[index]-vec[index-2])+cost(vec,dp,index-2);
    }

    return dp[index]=min(one,two);
}
int main()
{
    fast;
    ll int n;
    cin>>n;
    vector<ll int>vec(n);
    vector<ll int>dp(n,-1);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    cout<<cost(vec,dp,n-1);
    
    return 0;
}
