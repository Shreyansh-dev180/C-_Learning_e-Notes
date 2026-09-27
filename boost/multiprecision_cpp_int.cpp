#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

/*cpp_int is variable type like int and other but it can store
very long values without overflow or hexadecimal values*/

cpp_int factorial(cpp_int n){
    if(n == 0){
        return 1;
    }

    return n * factorial(n-1);
}

int main(){
    cpp_int num ;
    cout<<"Enter a number for its factorial: ";
    cin>>num;

    cout<<factorial(num)<<'\n';

    return 0;
}