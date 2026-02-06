#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n,0);
        vector<int>freq(101,0);
        for(auto&it:v){
            cin>>it;
            freq[it]++;
        }
        if(freq[0]>0){
            if(freq[0]>1){
                if(freq[1]==0){
                    cout<<"NO"<<endl;
                    continue;
                }
            }
        }else{
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }

    return 0;
}