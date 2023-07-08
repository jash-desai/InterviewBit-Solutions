// Problem Name: N/3 Repeat Number
// Problem Link: https://www.interviewbit.com/problems/n3-repeat-number/

int Solution::repeatedNumber(const vector<int> &v) {
    int n = size(v), ele1{0}, ele2{0}, cnt1{0}, cnt2{0};
    for(int x : v){
        if(cnt1==0 and x!=ele2){
            cnt1++; ele1 = x;
        }else if(cnt2==0 and x!=ele1){
            cnt2++; ele2 = x;
        }else if(ele1 == x) cnt1++;
        else if(ele2 == x) cnt2++;
        else cnt1--, cnt2--;
    }
    cnt1=0; cnt2=0;
    for(int i=0; i<n; i++){
        if(ele1 == v[i]) cnt1++;
        if(ele2 == v[i]) cnt2++;
    }
    if(cnt1 > n/3) return ele1;
    if(cnt2 > n/3) return ele2;
    return -1;
}
