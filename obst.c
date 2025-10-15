#include<stdio.h>
#include<stdlib.h>
#define MAX 20


void optimalBST(double p[], double q[], int n){
    double e[MAX+2][MAX+1];ṇ
    double w[MAX+2][MAX+1];
    int root[MAX+1][MAX+1];
    int i,j,l,r;
    double t;


for(int i=1;i<=n+1;i++){
    e[i][i-1]=q[i-1];
    w[i][i-1]=q[i-1];
}
for(int l=1;l<=n;l++){
    for(i=1 ; i<=n-l+1 ; i++){
        j=i+l-1;
        e[i][j]=MAX;
        w[i][j]=w[i][j-1] + p[j] + q[j];
        for(r=i; r<=j ; r++){
            t = e[i][r-1] + e[r+1][j] + w[i][j];
            if(t<e[i][j]){
                e[i][j] = t;
                root[i][j] = r;
            }
        }
    }
}
        printf("Minimum cost: %.3f\n\n",e[1][n]);
        printf("Root Table: \n");
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                printf("%4d",root[i][j]);
            }
            printf("\n");
        }
    }


int main(){
    int n=4;
    double p[]={0, 0.1, 0.2, 0.4, 0.3};
    double q[]={0.05, 0.1, 0.05, 0.05, 0.1};
    optimalBST(p,q,n);
    return 0;
}
