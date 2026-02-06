#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        long long n,x,y;
        cin>>n>>x>>y;
        vector<long long>v(n);
        for(auto&it:v) cin>>it;
        for(int i=0; i<n; i++){
            x=x^v[i];
        }
        if(y&1){
            if(x&1){
                cout << "Alice" <<endl;
            }else{
                cout << "Bob" <<endl;
            }
        }else{
            if(x&1){
                cout << "Bob" <<endl;
            }else{
                cout << "Alice" <<endl;
            }
        }
    }
    return 0;
}