#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> h; // height;
int k;
vector<int> dp; // cpr do like this
 

//  // top down solution
// int f(int i){
//     if(i>=h.size()){
//         return INT_MAX;
//     }
//     if(i==h.size()-1){
//         // last stone
//         return 0;
//     }
//     if(dp[i]!=-1) return dp[i];
//     int ans= INT_MAX;
//     for(int j=1;j<=k;j++){
//         if((i+j)>= h.size()) break;
//         ans = min(ans,abs(h[i]-h[i+j])+f(i+j));
//     }
//     return dp[i] = ans; // storing ans in dp[i];
// }

//bottom up solution
int fbu(){
    int n = h.size();
    dp.resize(100005,INT_MAX);
    
    dp[n-1] = 0;// base case
    for(int i=n-2 ;i>=0;i--){
        for(int j=1;j<=k;j++){
            if((i+j)>= h.size()) break;
            dp[i] = min(dp[i],abs(h[i]-h[i+j])+dp[i+j]);
        }
    }
    return dp[0];
}

int main(){
    int n;
    cin>>n>>k;
    h.resize(n);
    // dp.resize(n,-1);// -1 denotes that dp [i] yet not computed;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    // cout<<f(0)<<endl;

    cout<<fbu()<<endl;
    return 0;
}