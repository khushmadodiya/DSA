#include <iostream>
using namespace std;

 bool isPowerOfTwo(int n) {
        if(n==1)
        return true;
        if(n%2!=0)
        return false;
        isPowerOfTwo(n/2);
    }
int main(){
    int a;
    cin>>a;
   bool ans= isPowerOfTwo(a);
    if(ans)
    {cout<<"true";}
    else{
        cout<<"false";
    }

}