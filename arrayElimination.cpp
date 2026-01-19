#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>vec(n,0);
        for(auto&it:vec){
            cin>>it;
        }
        vector<int>freq(32,0);
        for(int i=0;i<32;i++){
            int temp = 1<<i;
            for(int j=0;j<n;j++){
                if(vec[j]&temp){
                    freq[i]++;
                }
            }
        }
        bool flag=true;
        for(int i=1;i<=n;i++){
            flag=true;
            for(int j=0;j<32;j++){
                if(freq[j]%i!=0){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}