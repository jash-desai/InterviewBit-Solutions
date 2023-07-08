// Problem Name: Self Permutation
// Problem Link: https://www.interviewbit.com/problems/self-permutation/

int Solution::permuteStrings(string a, string b){
    sort(begin(a), end(a)); sort(begin(b), end(b));
    return (a==b);
}
