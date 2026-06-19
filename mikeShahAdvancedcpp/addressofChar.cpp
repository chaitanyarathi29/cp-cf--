#include <iostream>
using namespace std;

void foo(){

}

int main(){

    int x = 12;
    double y = 34;
    char a = 'a';

    cout<<"x : "<<&(x)<<endl;
    cout<<"y : "<<&(y)<<endl;

    //cout rule to print char here a it treats a* as a string 
    //therefore if used only &(a) gives answer somewhat like a string tile /0 comes
    //in order to tell this that what i mean by this a* is address of a we provide (void*)&(a)
    //similiarly in case of function it treats it as a boolean whether function exists or not and gives either 0 or 1  
    
    cout<<"a : "<<&(a)<<endl;
    cout<<"a : "<<(void*)&(a)<<endl;
    cout<<"foo : "<<(void*)&(foo)<<endl;
    return 0;
}