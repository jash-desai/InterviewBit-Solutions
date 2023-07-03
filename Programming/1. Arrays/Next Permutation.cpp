// Problem Name: Next Permutation
// Problem Link: https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::nextPermutation(vector<int> &v){
    int n = size(v), l = -1, r = -1;
    for(int i=n-1; i>0; i--){
        if(v[i]>v[i-1]){
            l = i-1; break;
        }
    }
    for(int i=n-1; i>l; i--){
        if(v[i]>v[l]){
            r = i; break;
        }
    }
    if(l!=-1 and r!=-1){
        swap(v[l], v[r]);
        sort(v.begin()+l+1, v.end());
        return v;
    }
    sort(begin(v), end(v)); return v;
}
