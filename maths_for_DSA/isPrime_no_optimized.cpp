#include<iostream>
using namespace std;

/*for checking if a number is prime or not
let say we have to check if 10 is prime or not 
IMPORTANT PATTERN-> we dont need to loop till that 10 times
actually factors of 25 are
1 x 24;
2 x 12;
3 x 8;
4 x 6;
now magic its reverse;
6 x 4;
8 x 3;
12 x 2;
24 x 1;

so if 2 x 12 is factor of 24 then its sure that 24 is divisible by both 
2 and 12 and its multiple of them and we know that after underoot n the 
factors value get reverse so we dont need to check after root n because if 
any divisible number before root say 2 x 12 here 2 divides 24 means non 
prime and after root 12 x 2 here 12 will also divide it.
*/

string isPrime(int n){
    string ans = "PRIME";
    for(int i = 2; i*i<=n ; i++){ //i = root n -> i^2 = n
        if(n % i == 0){
            ans = "NON PRIME";
            break;
        }
    }
    return ans;

}

int main(){
    int num = 2;
    cout<<isPrime(num)<<'\n';



    return 0;
}