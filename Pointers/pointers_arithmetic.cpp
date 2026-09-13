#include<iostream>
using namespace std;



int main(){
    int arr[5] = {1,2,3,4,5};

    int* ptr1 = arr; //small address 0th index
    int* ptr2 = &(arr[1]); //this is greater adress in memory 1st index

    /*1. - subtraction if we have two operands of int type
    if ptr1 = 104 and ptr2 = 100 in memory then 104-100 is 4 means 4/4 is 1 int means 
    from arr[0]'s adress next to it there is arr[1] which have occupied this 4byte and are int type
    if there would have been &arr[2] - &array[0] then it will be 2 one 4 bytes occupied by
    the arr[2] itself and there is also a 1 int element of array between them 
    or we can say that from &arr[0] move 8 bytes forward then you will reach the end of 
    &[arr[2]] */

    cout<<ptr1 - ptr2 << '\n'; 
    //smaller - greater address so result -1 means -4 byte space between them
    //means no space left;
    //correct order ptr2 - ptr1 == 1 means 4 byte space between them one int variable
    // can be stored between them just for better understanding;
    cout<<ptr2 - ptr1 <<'\n';


    return 0;
}