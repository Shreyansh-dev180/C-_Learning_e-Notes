#include<iostream>
using namespace std;

int max_col_sum(int m[][3], int row, int col){
    int max_sum = 0;
    for(int i = 0; i<col; i++){
        int sum = 0;
        for(int j = 0 ; j<row; j++){
            sum+= m[j][i];
        }
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

int main(){
    int mat[2][3] = {{1,2,3},{3,4,5}};
    int row = 2;
    int col = 3;

    cout<<max_col_sum(mat,row,col);

}