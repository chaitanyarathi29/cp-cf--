#include <iostream>
using namespace std;

int main(){
  
  int n;cin>>n;
  string temp;
  char ch = n + '0';
  while(n--){
    temp += ch;
  }
  cout<<temp<<endl;
  return 0;
}