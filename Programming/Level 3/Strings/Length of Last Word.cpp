// Problem Name: Length of Last Word
// Problem Link: https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string s){
    int i = size(s) - 1, curr = 0;
    while(s[i]==' ') i--;
    while(s[i]!=' ' and i>=0){
        curr++;
        i--;
    }
    return curr;
}
