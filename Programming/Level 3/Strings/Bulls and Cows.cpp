// Problem Name: Bulls and Cows
// Problem Link: https://www.interviewbit.com/problems/bulls-and-cows/

string Solution::solve(string secret, string guess){
    int bull = 0, cow = 0;
    int sarr[10]={0}, garr[10]={0};
    for(int i = 0; i < secret.size(); i++){
		if(secret[i]!= guess[i]){
			sarr[secret[i]-'0']++;
			garr[guess[i]-'0']++;
		}
		else bull++;
	}
    for(int i = 0; i <= 9; i++) cow += min(sarr[i], garr[i]);
	return (to_string(bull) + "A" + to_string(cow) + "B");
}
