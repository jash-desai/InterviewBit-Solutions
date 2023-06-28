// Problem Name: Max Non Negative SubArray
// Problem Link: https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int> &v){
    vector<int> ans; int n = v.size();
    long long int currSum = 0, sum = 0;
    vector<int> temp;
    for(int i=0; i<n; i++){
        if(v[i]<0){
            if(sum < currSum){
                sum = currSum; ans = temp;
            }else if(sum==currSum and ans.size()<temp.size()){
                ans = temp;
            }
            currSum=0;
            temp.clear();
            continue;
        }else{
            currSum += v[i];
            temp.push_back(v[i]);
            if(i==n-1){
                if(sum < currSum){
                    sum = currSum; ans = temp;
                }else if(sum==currSum and ans.size()<temp.size()){
                    ans = temp;
                }
            }
        }
    }
    return ans;
}
