int Solution::solve(vector<int> &A, int B) {
  // size of array
  int n=A.size();
  // suffix sum array --> suff[i] = sum(A[i] to A[n-1]);
  int suff[n + 1];
  // initializing last element of suffix sum as 0
  suff[n] = 0;
  // 2nd last element will be A[n-1]
  suff[n - 1] = A[n - 1];
  //loop from (n-2) --> 0
  for (int i = n - 2; i >= 0; i--){
    //{ curr suff sum = curr element in A + prev suff sum }
    suff[i] = A[i] + suff[i + 1]; 
  }
  // prefix sum --> prefix[i] = sum (A[0] tp A[i]);
  // initializing with 0
  int prefSum = 0;
  // making ans variable initializing with suff[n-B];
  int ans = suff[n - B];
  // running loop from 0-->B, comparing total of B elements and storing in ans
  for (int i = 0; i < B; i++) {
    prefSum = prefSum + A[i];
    int suffSum = suff[n - B + (i + 1)];
    ans = max(ans, prefSum + suffSum);
  }
  //
  return ans;
}
