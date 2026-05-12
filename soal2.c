#include <stdio.h>

int choice(int N){
    if(N>0 && N<=1){
        return 1;
    }
    else if(N>1 && N<=3){
        return 2;
    }
    else if(N>3 && N<=7){
        return 3;
    }
    else if(N>7 && N<=15){
        return 4;
    }
}

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
    int rep = choice(N);
    int count =0;
    for (int i = 0; i<rep; i++){
        if (i < rep-1){
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
        }
        else {
            if (N < count + power(2,i)){
                if (i % 2 == 0){
                    printf("LEVEL %d:", i);
                    for(int j =count ; j<N; j++){
                        printf(" %d", buff[j]);
                    }
                    printf("\n");
                }
                else {
                    printf("LEVEL %d:", i);
                    for(int j = N; j>power(2,i)-1; j--){
                        printf(" %d", buff[j-1]);
                    }
                    printf("\n");
                }
            }
            else {
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
            }
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
