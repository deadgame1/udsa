#include <stdio.h>
#include <stdlib.h>

struct Element{
    int i;
    int j;
    int x;
};
struct Sparse{
    int m;
    int n;
    int num;
    struct Element *ele;
};
void create(struct Sparse *s)
{
    printf("Enter Dimensions");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter number of non zero elements");
    scanf("%d",&s->num);
    s->ele = (struct Element *)malloc(s->num*sizeof(struct Element));
    printf("Enter the non zero elements");

    int i;
    for(i=0;i<s->num;i++)
    {
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }
}
void display(struct Sparse s){
    int i,j,k=0;
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++){
            if(i == s.ele[k].i && j == s.ele[k].j){
                printf("%d ",s.ele[k++].x);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
struct Sparse* add(struct Sparse s1, struct Sparse s2){
    struct Sparse *sum;
    sum=(struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc((s1.num+s2.num)*(sizeof(struct Sparse)));
    if(s1.m != s2.m || s1.n != s2.n){
        return sum;
    }
    int i,j,k;
    i=j=k=0;
    
    while(i<s1.num && j<s2.num){
        if(s1.ele[i].i < s2.ele[j].i){
            sum->ele[k].i = s1.ele[i].i;
            sum->ele[k].j = s1.ele[i].j;
            sum->ele[k++].x = s1.ele[i++].x;
        }else if(s2.ele[j].i < s1.ele[i].i){
            sum->ele[k].i = s2.ele[j].i;
            sum->ele[k].j = s2.ele[j].j;
            sum->ele[k++].x = s2.ele[j++].x;
        }else{
            if(s1.ele[i].j < s2.ele[j].j){
                sum->ele[k].i = s1.ele[i].i;
                sum->ele[k].j = s1.ele[i].j;
                sum->ele[k++].x = s1.ele[i++].x;
            }else if(s2.ele[j].j < s1.ele[i].j){
                sum->ele[k].i = s2.ele[j].i;
                sum->ele[k].j = s2.ele[j].j;
                sum->ele[k++].x = s2.ele[j++].x;
            }else{
                //add
                sum->ele[k].i = s1.ele[i].i;
                sum->ele[k].j = s1.ele[i].j;
                sum->ele[k++].x = s1.ele[i++].x + s2.ele[j++].x;
            }
        }
    }
    for(;i<s1.num;i++){
        sum->ele[k].i = s1.ele[i].i;
        sum->ele[k].j = s1.ele[i].j;
        sum->ele[k++].x = s1.ele[i].x;
    }
    for(;j<s2.num;j++){
        sum->ele[k].i = s2.ele[j].i;
        sum->ele[k].j = s2.ele[j].j;
        sum->ele[k++].x = s2.ele[j].x;
    }

    sum->m = s1.m;
    sum->n = s1.n;
    sum->num = k;
    return sum;
}
int main()
{
    struct Sparse usersSparse;
    create(&usersSparse);
    struct Sparse usersSparse2;
    create(&usersSparse2);

    printf("\n");
    printf("\n");

    struct Sparse *sum;
    sum = add(usersSparse,usersSparse2);
    if(sum->m == 0){
        printf("Matrix cannot be added");
    }else{
        display(*sum);
    }
    return 0;
}