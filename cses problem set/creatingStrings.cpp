#include <iostream>
#include <vector>
using namespace std;
vector<string>allStrings;
void backtrack(int n,vector<int>&freq,string curr){

    if(n==0){
        allStrings.push_back(curr);
        return;
    }

    for(int i=0;i<26;i++){
        if(freq[i]){
            freq[i]--;
            backtrack(n-1,freq,curr+char('a'+i));
            freq[i]++;
        }
    }
}

int main(){

    string s;cin>>s;
    vector<int>freq(26,0);
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }
    string curr="";
    backtrack(s.size(),freq,curr);

    cout<<allStrings.size()<<endl;
    for(auto&it:allStrings){
        cout<<it<<endl;
    }

    return 0;
}