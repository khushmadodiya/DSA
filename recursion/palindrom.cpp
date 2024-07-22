#include <bits/stdc++.h>
using namespace std;



bool reverse(string& str, int i, int j ) {

    cout << "call recieved for " << str << endl;
    if(str[i]!= str[j]){
        return false;
    }

    if(i>j)
        return true;

    swap(str[i], str[j]);
    i++;
    j--;

    reverse(str,i,j);

}

int main(){
    string s;
    cout<<"Enter String :";
    cin>>s;

    bool ans = reverse(s,0,s.length()-1);
    if(ans){
        cout<<"palindrom";
    }
    else{
        cout<<"not palindrom";
    }


}