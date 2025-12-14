#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n,0);
        for(auto&it:v)cin>>it;
        vector<int>ans;
        int op=0;
        int orr=0;
        for(int i=0;i<v.size();i++){
            orr |= v[i];
        }
        int max=0;
        int ins=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if((op|v[j])>max){
                    max=op|v[j];
                    ins=v[j];
                }
            }
            for(int k=0;k<v.size();k++){
                if(ins==v[k]){
                    v[k]=-20;
                    break;
                }
            }
            ans.push_back(ins);
            op=max;
            if(op==orr){
                break;
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]>0){
                ans.push_back(v[i]);
            }
        }
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout <<endl;
    }

    return 0;
}