#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
int mod=1e9+7;
ll int knapsack(vector<ll int>&weight,vector<ll int>&value,  vector<vector<ll int>>&dp,ll int index,ll int left)
{
    //Order of this 2 base condition is important if we use 2nd one first then wrong answer.
    if(left<=0)
    {
        return 0;
    }
    if(index==weight.size())
    {
        return INT_MAX;
    }
    
    if(dp[index][left]!=-1)
    {
        return dp[index][left];
    }
    ll int choose=INT_MAX;
    if(left-value[index]>=0)
    {
        choose=weight[index]+knapsack(weight,value,dp,index+1,left-value[index]);
    }
    
    ll int not_choose=knapsack(weight,value,dp,index+1,left);
    return dp[index][left]=min(choose,not_choose);
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
    vector<vector<ll int>>dp(n+10,vector<ll int>(1e5+5,-1));
    
    for(int i=1e5;i>=0;i--)
    {
        if(knapsack(weight,value,dp,0,i)<=w)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
