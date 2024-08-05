#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	cout << "Input number is " << num << endl;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
		// Writing output to STDOUT
		for(int i=0;i<num;i++){
			for(int j=1;j<=arr[i];j++){
          if(j%3==0){
			cout<<"Fizz"<<endl;
		  }
		  else if(j%5==0){
			cout<<"Buzz"<<endl;
		  }
		  else if(j%3==0 && j%5==0){
			cout<<"FizzBuzz"<<endl;
		  }
		  else{
			cout<<j<<endl;
		  }
		}
		}
	
}