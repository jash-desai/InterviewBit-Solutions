// Problem Name: Sort by Color
// Problem Link: https://www.interviewbit.com/problems/sort-by-color/

void Solution::sortColors(vector<int> &v){
    int n = v.size();
    int i=0, j=0, k=n-1;
    while(j<=k){
        if(v[j]==0){
            swap(v[i++], v[j++]);
        }else if(v[j]==2){
            swap(v[k--], v[j]);
        }else{
            j++;
        }
    }
    return;
}
