// Problem Name: Triplets with Sum between given range
// Problem Link: https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/

int Solution::solve(vector<string> &v){
    long double sum = 0; vector<long double> all;
    for(string a : v){
        long double curr = stold(a);
        if(size(all) < 3){
            sum += curr;
            all.push_back(curr);
        }else{
            if(1. < sum and sum < 2.) return true;
            
            for(int i=0; i<3; i++){
                long double tempSum = sum - all[i] + curr;
                if(1. < tempSum and tempSum < 2.) return true;
            }
            if(sum <= 1.){
                int idx = min_element(begin(all), end(all)) - begin(all);
                if(all[idx] < curr) {
                    sum = sum - all[idx] + curr;
                    all[idx] = curr;
                }
            }else if(sum >= 2.){
                int idx = max_element(begin(all), end(all)) - begin(all);
                if(all[idx] > curr){
                    sum = sum - all[idx] + curr;
                    all[idx] = curr;
                }
            }
            if(1. < sum and sum < 2.) return true;
        }
    }
    return 1. < sum and sum < 2.;
}
