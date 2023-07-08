// Problem Name: Salutes
// Problem Link: https://www.interviewbit.com/problems/salutes/

long Solution::countSalutes(string s){
    long long int l = 0, ans = 0, i = 0;
    while(i<size(s)){
        if(s[i]=='>') l++;
        if(s[i]=='<'){
            if(l>=1) ans+=l;
        }
        i++;
    }
    return ans;
}

