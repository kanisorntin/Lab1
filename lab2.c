#include <stdio.h>

void GetSet( int data[], int *num );

int main(){
    int data[50], num;
    GetSet(data, &num);
    return 0;
}

void GetSet(int data[],int *num){
    printf("How many number ? : ");
        if(scanf("%d", num) != 1){
            printf("No have number!\n");
            return;
    }

    for(int i = 0; i < *num; i++){
        printf("Enter Number %d: ", i+1);
        if(scanf("%d",&data[i]) != 1){
            printf("No have number!\n");
        }
    }

    printf("\nYour number is:\n");
    for(int i = 0; i < *num; i++){
        printf("%d",data[i]);
    }
}