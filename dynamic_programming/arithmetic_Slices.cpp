#include <iostream>
#include <vector>
using namespace std;
int f(int i){
        int sum = 0;
        for(int k=3;k<=i;k++){
            int rem = i%k;
            int quo = i/k;
            sum+=rem+quo;
        }
        return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
    }
    vector<int> ans;
    int count = 2;
    if(nums.size()<=2) return 0;
    for(int i=1;i<nums.size()-1;i++){
        if(nums[i]-nums[i-1]==nums[i+1]-nums[i]){
            count++;
        }
        else{
            if(count!=2){
                cout<<count<<endl;
                ans.push_back(count);
                
            }
            count = 2;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
        int result = 0;
        for(int i=0;i<ans.size();i++){
            result+=f(ans[i]);
        }
        cout<<result<<endl;

}