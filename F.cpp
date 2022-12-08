//Refer to smaller version  https://github.com/Ash0369/Geeks_for_geeks/blob/main/Longest%20Common%20Subsequence.cpp
//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
int mod=1e9+7;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    string s1,s2;
    cin>>s1>>s2;
    int x=s1.size();
    int y=s2.size();
    //dp[i][j]--> Max length got when pointing i on s1 and j on s2
    vector<vector<int>>dp(x+1,vector<int>(y+1,0));
    vector<vector<int>>form(x+1,vector<int>(y+1,0));
    //form[i][j]=0 move to i-1
    //form[i][j]=1 move to j-1
    //form[i][j]=2 pick and move to i-1 ,j-1
    if(s1[0]==s2[0])
    {
        dp[0][0]=1;
        form[0][0]=2;
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(i>0)
            {
                dp[i][j]=dp[i-1][j];
                form[i][j]=0;
            }
            if(j>0)
            {
                if(dp[i][j]<dp[i][j-1])
                {
                    dp[i][j]=dp[i][j-1];
                    form[i][j]=1;
                }
            }
            if(s1[i]==s2[j] && i>0 && j>0)
            {
                form[i][j]=2;
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else if(s1[i]==s2[j])
            {
                form[i][j]=2;
                dp[i][j]=1;
            }
            
        }
    }

    int i=x-1;
    int j=y-1;
    string ans="";
    while(i>=0 && j>=0)
    {
        if(form[i][j]==2)
        {
            ans+=s1[i];
            i--;
            j--;
        }
        else if(form[i][j]==1)
        {
            j--;
        }
        else
        {
            i--;
        }

    }

    reverse(ans.begin(),ans.end());

    cout<<ans<<endl;
    return 0;
}
