#include <iostream>
#include <string>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        
        string str;
        cin >> str;
        int n = str.size();

        string s;
        if(n > 10){
            s = str[0] + to_string(n - 2) + str[n-1];
            cout << s <<endl;
        }
        else{
            cout << str << endl;
        }


    }


    return 0;
}