#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){

    int t;
    cin >>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> vec(n);
        for(auto&it: vec) cin>>it;
        for(int i=1; i<=61; i++){
            set<long long>st;
            long long num = (1LL<<i);
            for(int j=0; j<n; j++){
                st.insert(vec[j]%num);
            }
            if(st.size()==2){
                cout <<num<<endl;
                break;
            }
        }
    }

    return 0;
}
