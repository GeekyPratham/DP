#include <iostream>
#include <vector>
using namespace std;
// top down solution
vector<vector<int> > dp;
string ans = "";
int f(string& s1,string& s2,int i,int j,string output){
    if(ans.size()<output.size()){
        ans=output;
    }
    
    if(i>=s1.size() || j>=s2.size()){
            return 0;
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]=1 + f(s1,s2,i+1,j+1,output+s1[i]);
    }
    else
        return dp[i][j]=max(f(s1,s2,i+1,j,output),f(s1,s2,i,j+1,output));
}
        

int main(){
    string s1,s2;
    cin>>s1>>s2;
    dp.clear();
    dp.resize(1005,vector<int> (1005,-1));
    f(s1,s2,0,0,"");
    cout<<endl<<ans;
}
// it gives runtime error for some case due to formation of output string from top down

// so we use bottom up
