#include<iostream>
using namespace std;

int max_sum(int mat[][4], int row, int col){
    int max_sum1 = 0;
    for(int i = 0; i<row; i++){
        int sum = 0;
        for(int j = 0; j<col; j++){
            sum+= mat[i][j];
        }
        max_sum1 = max(sum, max_sum1);
    }
    return max_sum1;
}

int main(){
    int mat[4][4] = {{1,2,3,4}, {5,6,7,8},{9,10,11,12}, {13,14,15,16}};
    int row = 4;
    int col = 4;

    cout<<max_sum(mat, row,col);



    return 0;
}