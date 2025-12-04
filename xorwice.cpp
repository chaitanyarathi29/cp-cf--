#include <iostream>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int ans = (a&b);
        cout << ((a^ans)+(b^ans)) <<endl;
    }

    return 0;
}