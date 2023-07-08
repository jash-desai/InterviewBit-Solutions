// Problem Name: ARRAY_BUG
// Problem Link: https://www.interviewbit.com/problems/arraybug/

vector<int> Solution::rotateArray(vector<int>&v, int k) {
	vector<int> ret; int n = v.size();
	k = k%n;
	for(int i = k; i<v.size(); i++){
		ret.push_back(v[i]);
	}
	for(int i=0; i<k; i++) ret.push_back(v[i]);
	return ret; 
}