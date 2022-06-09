#include <iostream>
#define I INT16_MAX

using namespace std;

int edges[3][9] = {
    {1,1,2,2,3,4,4,5,5},
    {2,6,3,7,4,5,7,6,7},
    {25,5,12,10,8,16,14,20,18}
};

int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int included[9] = {0};
int t[2][6];

void myUnion(int u, int v){
    if(set[u] < set[v]){
        set[u] += set[v];
        set[v] = u;
    }else{
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u){
    int x=u,v=0;
    while(set[x] > 0){
        x = set[x];
    }
    return x;
}

int main(){
    int i,j,k,u,v,min=I,n=7,e=9;
    i=0;
    while(i<n-1){ // n vertices, n-1 edges, i goes from 0 to <n-1 i.e until all edges are found for MST
        min=I; // min needs to be assigned each time to infinity before finding the new minimum edge in each while iteration
        for(j=0;j<e;j++){//finding minimum edge
            if(included[j]!=1 && edges[2][j] < min){
                min = edges[2][j];
                u=edges[0][j];
                v=edges[1][j];
                k=j; //k is selected vertex at the moment 
            }
        }

        if(find(u)!=find(v)){ //if they dont have same parent then we include in MST, if they have same parent and we join then it becomes a cycle which we are trying to avoid
            t[0][i]=u; //store in output array
            t[1][i]=v; //store in output array
            myUnion(find(u),find(v));
            i++; //i is incremented in if clause, since i tracks the output array and output array index should be incremented when we have found an edge for MST
        }
        included[k]=1;
    }

    for(i=0;i<n-1;i++){
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }

    return 0;
}