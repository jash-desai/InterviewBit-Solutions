// Problem Name: Repeat and Missing Number Array
// Problem Link: https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &v) {
    long long k = 0, kk = 0; long long temp; int n = v.size();
    for (int i = 0; i < n; i++) {
        temp = v[i];
        k += temp;
        kk += (temp*temp);
        temp = i + 1;
        k -= (temp);
        kk -= (temp*temp);
    }
    kk = kk/k;
    int x = (int)((k + kk)/2);
    int y = (int)(kk-x);
    return {x, y};
}
