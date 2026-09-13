#include<iostream>
using namespace std;



int main(){
    int arr[5] = {1,2,3,4,5};
    
    //An array's name is also a constant pointer
    //which points to the value stored at adress 0th index of that arr;

    /*An array pointer is constant becasue it always point to the 0th index of array
    and we cannot store any other address to it because lets say we have an array with
    5 values and the array pointer is pointing at 0th index value then if just in case 
    we store another adress in it then it will forget the 0th index address means now the 
    5 values which were in the array earlier are lost in memory now and 
    the address of arr is not modifable after its creation thats the reason if 
    we try to assign any other adress to array pointer then it will give error.
    array pointer is the name of the array*/

    // verification that array pointer points at the 0th index of itself;
    //stored value of arr not the address of arr itself because it will be different not constant;
    cout<<"value of array pointer: "<<arr<<"\n";
    cout<<"Address of array[0]: "<<&(arr[0])<<"\n"; //both are same;




    return 0;
}