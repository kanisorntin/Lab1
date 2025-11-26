#include <stdio.h>

int main(){
    int n = 0 ;
    int i = 0 ;

    scanf("%d", &n);

    for( i = 0 ; i < n ; i++){
        printf("[%d] Hello World\n", i + 1);
    }
    return 0 ;
}