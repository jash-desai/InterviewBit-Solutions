// Problem Name: Merge Two Sorted Lists II
// Problem Link: https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &a, vector<int> &b){
    int n = a.size(), m = b.size();
    for(int i=0; i<m; i++) a.push_back(0);
    int i=n-1, j=m-1, k=n+m-1;
    while(i>=0 and j>=0){
        if(a[i]>b[j]){
            a[k--] = a[i--];
        }else{
            a[k--] = b[j--];
        }
    }
    while(j>=0){
        a[k--] = b[j--];
    }
    return;
}

