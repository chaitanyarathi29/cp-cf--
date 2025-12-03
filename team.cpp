#include <iostream>
using namespace std;

int main(){

    int t;
    cin >> t;
    int cnt = 0;
    while(t--){
        
        int count = 0;
        int arr[3];
        for(int i=0; i<3; i++){
            cin >> arr[i];
            if(arr[i] == 1){
                count++;
            }
        }
        if(count > 1){
            cnt++;
        }

    }

    cout << cnt << endl;

    return 0;
}