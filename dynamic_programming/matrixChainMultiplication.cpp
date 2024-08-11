// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// int steps=0;

// int mcm(vector<int> &arr,int start,int end,vector<vector<int> > &dp){
//     if(start == end) return 0;

//     if(dp[start][end]!=-1) return dp[start][end];
//     int mn = INT_MAX;   


//     for(int k = start;k<end;k++){
//         steps = (arr[start-1]*arr[k]*arr[end])+mcm(arr,start,k,dp)+mcm(arr,k+1,end,dp);
//         mn = min(mn,steps);
//     }

//     return dp[start][end] = steps;
// }
// int main(){
//     vector<int> arr;
//     int n;
//     cout<<"No of Matrices : ";
//     cin>>n;

//     for(int i=0;i<n;i++){
//         int num;
//         cin>>num;
//         arr.push_back(num);
//     }
//     cout<<endl;

//     for(int i=0;i<arr.size();i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<n<<endl;
//     vector<vector<int> > dp(n,vector<int> (n,-1));
//     cout<<"Minimum No of operations : "<<mcm(arr,1,n-1,dp);
      
// }

// bottom up approach

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int steps=0;

int main(){
    vector<int> arr;
    int n;
    cout<<"No of Matrices : ";
    cin>>n;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    cout<<endl;

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<n<<endl;
    vector<vector<int> > dp(n,vector<int> (n,0));
    // cout<<"Minimum No of operations : "<<mcm(arr,1,n-1,dp);

    // for(int i=1;i<n;i++){ // copying the base case but it is not necessary to write as i initialize the 2d dp with 0
    //     dp[i][i]=0;
    // }

    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n-1;j++){
            int mn = INT_MAX;  

            for(int k = i;k<j;k++){
                steps = (arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                mn = min(mn,steps);
            }

            dp[i][j] = mn;
        }
    }

    cout<<"Minimum No of operations : "<<dp[1][n-1];
      
}