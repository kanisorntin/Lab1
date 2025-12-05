#include <stdio.h>

int GetSet(int data[] , int *num);

int main(){
    int *data, num;
    num = GetSet(data, &num);
    return 0;
    
}
int GetSet(int data[] ,int *num){

    if(scanf("%d", data) != 1){
        printf("Error!! not a number\n");
}
    for(int i = 0; i < *data; i++){
        printf("Number %d is : ", i+1);
    if(scanf("%d",&num[i]) != 1){
        printf("Error!! not a number\n");
    }
  }
    printf("\nYour number is:\n");
    for(int i = 0; i < *data; i++){
    printf("%d",num[i]);
    }
    return 0;
    
}
