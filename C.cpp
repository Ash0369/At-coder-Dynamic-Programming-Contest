#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
int mod=1e9+7;
ll int happy(vector<ll int>&a,vector<ll int>&b,vector<ll int>&c, vector<vector<int>>&dp,ll int day,ll int n,int prev)
{
    if(day==n)
    {
        return 0;
    }
    if(dp[day][prev]!=-1)
    {
        return dp[day][prev];
    }
    ll int swim=0;
    ll int mountain=0;
    ll int home=0;


    if(prev!=1)
    {
        swim=a[day]+happy(a,b,c,dp,day+1,n,1);
    }
    if(prev!=2)
    {
        mountain=b[day]+happy(a,b,c,dp,day+1,n,2);
    }
    if(prev!=3)
    {
        home=c[day]+happy(a,b,c,dp,day+1,n,3);
    }

    return dp[day][prev]=max(swim,max(mountain,home));
    
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    ll int n;
    cin>>n;
    vector<ll int>a(n);
    vector<ll int>b(n);
    vector<ll int>c(n);
    vector<vector<int>>dp(n,vector<int>(4,-1));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
    }
    cout<<happy(a,b,c,dp,0,n,0)<<endl;
    
    return 0;
}
