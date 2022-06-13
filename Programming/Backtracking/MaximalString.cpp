void rec(string s, int k, string *ans){
  if(k==0){
    if(*ans<s){
      *ans=s;
    }
  }
  for(int i=0; i<s.size(); i++){
    for(int j=i+1; j<s.size(); j++){
      swap(s[i],s[j]);
      rec(s,k-1,ans);
      swap(s[i],s[j]);
    }
  }
}

int Solution::solve(string s, int k){
  string ans;
  rec(s,k,&ans);
  return ans;
}
