#include <iostream>
using namespace std;

int main(){

    int n;cin>>n;
    while(n>0){
        if(n==1){
            cout<<n;
            break;    
        }
        cout<<n<<",";
        n--;
    }
    
    return 0;
}