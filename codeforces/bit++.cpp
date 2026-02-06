#include <iostream>
using namespace std;

int main(){

    int t;
    cin >> t;
    int cnt = 0;
    while(t--){
        string str;
        cin >> str;
        int x = 0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '+'){
                x++;
            }
            if(str[i] == '-'){
                x--;
            }
        }
        cnt += x;
    }
    
    cout << cnt <<endl;
    return 0;
}