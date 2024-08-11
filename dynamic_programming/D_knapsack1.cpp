#include <iostream>
#include <vector>
#include <climits>

#define ll long long int
using namespace std;

vector<vector<ll> > dp;
ll f(vector<int> &wts,vector<int> &val,int idx,int W) {
    if(idx == val.size()){
        return 0;
    }
    ll ans = INT_MIN;
    if(dp[idx][W] != -1) return dp[idx][W];
    // if not pick
    ans = max(ans,f(wts,val,idx+1,W));

    // if pick
    if(wts[idx] <= W){
        ans = max(ans,val[idx] + f(wts,val,idx+1,W-wts[idx]));
    }

    return dp[idx][W] = ans;

}

ll fbu(vector<int> &wts,vector<int> &val,int W){
    dp.clear();
    dp.resize(105,vector<ll> (100005,0));
    int n = wts.size();
    for(int idx=n-1;idx>=0;idx--){
        for(int j=0;j<=W;j++){
            ll ans = INT_MIN;
            // not pick
            ans = max(ans,dp[idx+1][j]);
            //pick the item;
            if(wts[idx]<=j){
                ans = max(ans,val[idx]+dp[idx+1][j-wts[idx]]);
            } 
            dp[idx][j]=ans;      
        }
        
    }
    return dp[0][W];
}
int main(){
    int n,W;
    cin>>n>>W;
    dp.clear();
    dp.resize(105,vector<ll> (100005,-1));
    vector<int> wts;
    vector<int> val;
    for(int i=0;i<n;i++){
        int w,v;
        cin>>w>>v;
        wts.push_back(w);
        val.push_back(v);
    }
  

    cout<<f(wts,val,0,W);
}