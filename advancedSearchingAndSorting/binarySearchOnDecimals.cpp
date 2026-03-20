#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    double x;
    cin>>x;
    double precision = 1e-12;
    double low=0,high=1e8;
    double ans=0;
    for(int i=0;i<100;i++){
        double mid = low + (high-low)/2;
        if(mid*mid<=x){
            ans=max(ans,mid);
            low = mid-precision;
        }else{
            high = mid+precision;
        }   
    }
    cout << setprecision(18) << fixed<<ans<<endl;

    return 0;
}

// in decimal binary search when using iteration if low and high converge very sharply the ans remains the initial value 
//because of which it gives wrong answer what we can do is change the low and the high to mid so that low and high never
//cross each other and it will help us give the correct answer
