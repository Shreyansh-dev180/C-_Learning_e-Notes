#include<iostream>
using namespace std;

/*LCM is 
a*b = hcd(a,b) * lcm(a,b);
so lcm(a,b) = a*b / hcf(a,b)
*/

//hcf logic subtraction one for practice
int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    if(a == b) return a;

    while(a > 0 && b > 0){
        if(a == b) return a;

        if(a > b){
            a-= b;
        }
        else{
            b-= a; 
        }
    }
    return -1;
}


int lcm(int x, int y){
    int lcm1 = (x*y) / gcd(x,y);
    return lcm1;
}

int main(){
    cout<<lcm(5,3);


    return 0;
}