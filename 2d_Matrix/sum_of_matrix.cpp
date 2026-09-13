#include<iostream>
using namespace std;
/*passing row num is optional but it is important to 
pass the coloum num so that compiler can correctly identify the 
each cell and matrix.*/

int sum(int mat[][2], int col, int row){
    int sum = 0;
    for(int i=0; i<row; i++){
        for(int j = 0; j<col; j++){
            sum+= mat[i][j];
        }
    }
    return sum;

}

int main(){
    int mat[3][2] = {{1,2},{3,4},{5,6}};
    int row = 3;
    int col = 2;

    cout<<sum(mat, col, row)<<"\n";


    return 0;
}