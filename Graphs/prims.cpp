#include <iostream>
#define I INT16_MAX

using namespace std;

int AM[][8] =  {{I,I,I,I,I,I,I,I},
                {I,I,25,I,I,I,5,I},
                {I,25,I,12,I,I,I,10},
                {I,I,12,I,8,I,I,I},
                {I,I,I,8,I,16,I,24},
                {I,I,I,I,16,I,20,18},
                {I,5,I,I,I,20,I,I},
                {I,I,10,I,14,18,I,I}};
    
int near[8] = {I,I,I,I,I,I,I,I};
int t[2][7];

int main(){
    int i,j,k,n=7,u,v;
    int min = I;

    //first finding minimum edge
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            if(AM[i][j] < min){
                min = AM[i][j]; 
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u]=near[v]=0;

    //initialization of near array
    for(i=1;i<=n;i++){
        if(near[i] != 0){
            if(AM[i][u] < AM[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    //repeating procedure to find min and connected edges
    for(i=1;i<n-1;i++){ //if n vertices, then n-1 edges, one edge is already decided on line 31
        min = I;
        for(j=1;j<=n;j++){
            if(near[j]!=0 && AM[j][near[j]] < min){
                k=j;
                min = AM[j][near[j]];
            }
        }
        t[0][i]=k; //setting result
        t[1][i]=near[k]; //setting result
        near[k]=0; //settings 0 , since vertex is already selected now

        //modify near array now for next iteration, checking if other vertices are nearer to k or not
        for(j=1;j<=n;j++){
            if(near[j]!=0 && AM[j][k] < AM[j][near[j]]){
                near[j]=k;
            }
        }
    }

    for(i=0;i<n-1;i++){
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }

    return 0;
}