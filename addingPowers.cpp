#include<iostream>
#include <vector>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){

        long long n,k;
        cin>>n>>k;
        vector<long long>vec(n,0);
        for(auto&it:vec) cin>>it;
        vector<long long>v(64,0);
        bool flag = true; 
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<v.size();j++){
                if(vec[i]==0){
                    break;
                }
                v[j]+=vec[i]%k;
                vec[i] /= k;
                if(v[j]>1){
                    flag=false;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            cout << "YES" <<endl;
        }else{
            cout << "NO" <<endl;
        }

    }
    
    return 0;
}
