// Problem Name: Array Sum
// Problem Link: https://www.interviewbit.com/problems/array-sum/

vector<int> Solution::addArrays(vector<int> &a, vector<int> &b){
    int n = a.size(), m = b.size(); vector<int> ans;
    if(n<m){
        swap(n,m); swap(a,b);
    }
    int c = 0, i = n-1, j = m-1;
    while(j>=0){
        int t = a[i]+b[j]+c;
        if(t>9){
            ans.push_back(t%10);
            c = t/10;
        }else{
            ans.push_back(t);
            c = 0;
        }
        i--, j--;
    }
    while(i>=0){
        int t = a[i]+b[j]+c;
        if(t>9){
            ans.push_back(t%10);
            c = t/10;
        }else{
            ans.push_back(t);
            c = 0;
        }
        i--;
    }
    if(c) ans.push_back(c);
    return vector<int>(rbegin(ans), rend(ans));
}
