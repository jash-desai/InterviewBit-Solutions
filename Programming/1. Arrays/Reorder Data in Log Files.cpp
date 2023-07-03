// Problem Name: Reorder Data in Log Files
// Problem Link: https://www.interviewbit.com/problems/reorder-data-in-log-files/

#define pss pair<string,string>
vector<string> Solution::reorderLogs(vector<string> &logs) {
    vector<string> digit, ans; vector<pss> letter;
    for(string log : logs){
        if(log.back()>='a' and log.back()<='z'){
            int i = log.find('-');
            string id = log.substr(0,i);
            string data = log.substr(i);
            letter.push_back({data,id});
        }else{
            digit.push_back(log);
        }
    }
    sort(letter.begin(), letter.end(), [](pss&a, pss&b){
        return (a.first!=b.first) ? a.first < b.first : a.second < b.second;
    });
    for(auto [data, id] : letter) ans.push_back(id+data);
    for(string data : digit) ans.push_back(data);
    return ans;
}
