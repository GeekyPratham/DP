#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;
vector<vector<vector<ll> > > dp;
ll dp[2005][2005][8];
ll f(vector<int>& s1,vector<int>& s2,int i,int j,int k){
    if(i==s1.size() || j==s2.size()){
        return 0;
    }
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    ll res = 0;
    if(s1[i]==s2[j]){
        res = 1+f(s1,s2,i+1,j+1,k);
    }
    else{
        if(k>0){
            res =  1+f(s1,s2,i+1,i+1,k-1);
        }
        
        res =  max(res,f(s1,s2,i+1,j,k));
        res =  max(res,f(s1,s2,i,j+1,k));
        
    }
    dp[i][j][k] = res;
    return res;
}
int main(){
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    vector<int> first;
    vector<int> second;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        first.push_back(num);
    }
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        second.push_back(num);
    }
    
    cout<<f(first,second,0,0,k);
    return 0;
}