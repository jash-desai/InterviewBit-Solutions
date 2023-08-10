// Problem Name: Remove Duplicates from Sorted Array
// Problem Link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &v){
    int n = v.size(); int i=1;
    for(int j=1; j<n; j++){
        if(v[j]!=v[j-1]){
            v[i++] = v[j];
        }
    }
    return i;
}

