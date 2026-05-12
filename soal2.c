#include <stdio.h>
#include <math.h>

int power(int x, int pangkat){
    int imitx=x;
    if(pangkat==0){
        return 1;
    }
    else if(pangkat==1){
        return x;
    }
    else{
        for(int i=2; i<=pangkat; i++){
            x=x*imitx;
        }
        return x;
    }
}

void print(int buff[], int N){
    int rep = log2(N+1);
    int count =0;
    for (int i = 0; i<rep; i++){
        if (i % 2 == 0){
            printf("LEVEL %d:", i);
            for(int j =count ; j<power(2,i)+count; j++){
                printf(" %d", buff[j]);
            }
            printf("\n");
        }
        else {
            printf("LEVEL %d:", i);
            for(int j = power(2,i)+count; j>power(2,i)-1; j--){
                printf(" %d", buff[j-1]);
            }
            printf("\n");
        }
        count += power(2,i);
    }
    return;
}

int main(){
    int N;
    scanf("%d", &N);
    int buff[N];
    for(int i = 0; i<N; i++){
        scanf("%d", &buff[i]);
    }
    print(buff, N);
    return 0;
}
