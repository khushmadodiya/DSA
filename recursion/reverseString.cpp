#include <bits/stdc++.h>
using namespace std;

void Reverse(string s,int size){
   cout<<s[size];
    if(size == 0){
        return ;
    }
    Reverse( s,size-1);
    


}

void reverse(string& str, int i, int j ) {

    cout << "call recieved for " << str << endl;
    if(i>j)
        return ;

    swap(str[i], str[j]);
    i++;
    j--;


    reverse(str,i,j);

}

int main(){
    string s;
    cout<<"Enter Strig :";
    cin>>s;

    Reverse(s,s.length()-1);
    reverse(s,0,s.length()-1);


}