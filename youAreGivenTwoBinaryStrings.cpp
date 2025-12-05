#include <iostream>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin >>s1 >> s2;
        int n1 = s1.size();
        int n2 = s2.size();
        int f1=0;
        int f2=0;
        for(int i=n1-1;i>=0; i--){
            if(s1[i]=='1'){
                f1=n1-i-1;
                break;
            }
        }
        for(int i=n2-1;i>=0; i--){
            if(s2[i]=='1'){
                f2=n2-i-1;
                break;
            }
        }
        if(f2>f1){
           for(int i=n1-1;i>=0; i--){
                if(s1[i]=='1' && n1-i-1>=f2){
                    f1=n1-i-1;
                }
                if(f1>=f2){
                    break;
                }
            } 
        }
        cout << f1-f2 <<endl;
    }
    
    return 0;
}