#include<iostream>
using namespace std;



int main(){
    int mat[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int row = 4;
    int col = 4;
     
    //access elements;
    cout<<mat[0][0]<<'\n'; //first cell element; row 0 and col 0;

    // accessing all ele with loop
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}