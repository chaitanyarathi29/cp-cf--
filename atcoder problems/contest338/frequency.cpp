#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    string s;cin>>s;
    vector<int>mp(26,0);
    for(int i=0;i<s.size();i++){
        mp[s[i]-'a']++;
    }
    int maxi=-1;
    for(int i=0;i<26;i++){
        maxi = max(maxi,mp[i]);
    }
    for(int i=0;i<26;i++){
        if(mp[i]==maxi){
            char ch = i+'a';
            cout<<ch<<endl;
            break;
        }
    }
    return 0;
}