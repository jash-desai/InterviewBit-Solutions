// Problem Name: Remove Element from Array
// Problem Link: https://www.interviewbit.com/problems/remove-element-from-array/

int Solution::removeElement(vector<int> &v, int k){
    int n = v.size(), cnt = 0, i=0, j=0;
    while(i<n and j<n){
        if(v[j]!=k){
            cnt++;
            swap(v[j++], v[i++]);
        }else j++;
    }
    return (i);
}
