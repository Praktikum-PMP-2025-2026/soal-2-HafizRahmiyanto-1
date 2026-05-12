#include <stdio.h>
#include <math.h>

void print(int buff[], int N){
    int rep = log2(N+1);
    int count =0;
    for (int i = 0; i<rep; i++){
        if (i % 2 == 0){
            printf("LEVEL %d: ", i);
            for(int j =count ; j<pow(2,i)+count; j++){
                printf(" %d", buff[j]);
            }
            printf("\n");
        }
        else {
            printf("LEVEL %d: ", i);
            for(int j = pow(2,i)+count; j>pow(2,i)-1; j--){
                printf(" %d", buff[j-1]);
            }
            printf("\n");
        }
        count += pow(2,i);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    int buff[N];
    for(int i = 0; i<N; i++){
        scanf("%d", &buff[i]);
    }

    print(buff, N);
}
