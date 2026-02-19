#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int>v(n,0);
    int sum=0;
    for(auto&it:v){
        cin>>it;
        sum+=it;
    }
    cout<<sum-n<<endl;
    
    return 0;
}