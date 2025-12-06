#include <stdio.h>

int *GetMatrix( int *row, int *col);

int main(){
    int *data, m, n;
    data = GetMatrix(&m, &n);
    return 0;
}

int *GetMatrix(int *row, int *col){
    int *a;
    printf("How many row, col ? : ");
    scanf("%d %d", row, col);
    a = new int[ *row * *col];
    for(int i = 0; i < *row; i++)
        for(int j = 0; j < *col; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[ i * * col + j]);
            return a;
        }
   
}