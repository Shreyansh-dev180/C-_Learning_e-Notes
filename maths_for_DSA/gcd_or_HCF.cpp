#include<iostream>
using namespace std;

/*We will discuss the brute force appraoch to find the hcf of two num
means the greatest num to divide both the numbers 
so lets say hcf of 20,24 so we know the loop will run till 
min(20,24) because it cant exceed the smallest num of both
now we will take var HCF = 0;  now we add condition if i divides both 
a and b completely then HCF  = i now we keep reassingning the value 
at last we get the highest number to divide both a and b
*/

int HCF(int a,int b){
    //some pre conditions if any one is 0 then other will be the hcf
    //because any number x 0 = 0 so any num can divide 0;
    //if a==b then a || b any can be the hcf 
    if(a == b){
        return a;
    }
    if(a == 0){
        return b;
    }
    else if(b == 0){
        return a;
    }

    int gcd{}; 
    for(int i = 1; i <= min(a,b); i++){
        if(a % i == 0 && b % i == 0){
            gcd = i;
        }
    }

    /*edge cases(hcf of: 0 and 8; 4 and 8)*/

    return gcd;
}

int main(){
    cout<<HCF(20,24);




    return 0;
}