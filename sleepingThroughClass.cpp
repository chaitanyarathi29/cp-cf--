#include <iostream>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin >> s;
        int cnt=0;
        int mcnt=0;
        for(int i=0; i<s.size();i++){
            if(s[i]=='0'){
                if(mcnt==0){
                    cnt++;
                }else{
                    mcnt--;
                }
            }else{
                mcnt=k;
            }
        }
        cout << cnt <<endl;
    }
    
    return 0;
}