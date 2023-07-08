// Problem Name: Palindrome String
// Problem Link: https://www.interviewbit.com/problems/palindrome-string/

int Solution::isPalindrome(string s){
    string t; int n = size(s);
    for(int i=0; i<n; i++){
        char c = s[i];
        bool fn = (c>= '0' and c<='9');
        bool fa = ((c>= 'a' and c<='z'));
        bool faa = (c>= 'A' and c<='Z');
        if(fn or fa) t.push_back(c);
        if(faa) t.push_back(c+32);
    }
    return (t==string(rbegin(t), rend(t)));
}
