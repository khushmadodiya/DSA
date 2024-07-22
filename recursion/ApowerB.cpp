#include <iostream>
using namespace std;

int apowerb(int a, int b)
{
   
     if(b==0){
        return 1;
     }

     return a*apowerb(a,b-1);
}
// optimal

int power(int a ,int b){
    if(b==0){
        return 1;
    }
    if(b==1)
    return a;

    int ans = power(a,b/2);

    if(b%2==0){
       return ans*ans;
    }
    else{
        return a*ans*ans;
    }

}
int main(){
    int a,b;
    cin>>a>>b;
    cout <<apowerb(a,b);
    cout <<power(a,b);

}