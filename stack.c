#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * link;
};
typedef struct node Node;

void printNode(Node * top){
    printf("[t]");
    while(top!=NULL) {
        printf("%d", top->value);
        top=top->link;
    }
    printf("[b]\n");
}

Node * push(Node * top){
    int num;
    Node * temp = (Node *)malloc(sizeof(Node));
    scanf("%d", &num);
    temp->value = num;
    temp->link = top;
    return temp;
}

Node * pop(Node * top){
    Node * nextLink=top->link;
    printf("pop : %d\n", top->value);
    free(top);
    return nextLink;  
}

int main(void) {
    Node * top = NULL;
    int num;
    
    while(1) {
        printf("0-종료, 1-입력, 2-삭제, 3-출력 : ");
        scanf("%d", &num);
        if(num==0)
            break;
        else if(num==1)
            top = push(top);
        else if(num==2 && top!=NULL)
            top = pop(top);
        else if(num==3)
            printNode(top);
    }
    return 0;
}