#include <stdio.h>

int *GetSet( int *data, int *num );

int main(){
    int *data, num;
    data = GetSet( &num ,data );
    return 0;
}

int *GetSet(int *data, int *num){
        if(scanf("%d", num) != 1){
            printf("Error!! not a number\n");
    }
    for(int i = 0; i < *num; i++){
        printf("Number %d is : ", i+1);
        if(scanf("%d",&data[i]) != 1){
            printf("Error!! not a number\n");
        }
    }
    printf("\nYour number is:\n");
    for(int i = 0; i < *num; i++){
    printf("%d",data[i]);
    }
    return 0;
}


    
