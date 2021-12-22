#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * link;
};
typedef struct node Node;

void printNode(Node * top){
    printf("[b]");
    while(top!=NULL) {
        printf("%d", top->value);
        top=top->link;
    }
    printf("[t]\n");
}

Node * push(Node * top, int num){
    Node * temp = (Node *)malloc(sizeof(Node));
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
        printf("입력값 : ");
        scanf("%d", &num);
        if(num!=0) {
            top = push(top, num);
            printNode(top);
        }
        else {
            top = pop(top);
            printNode(top);
        }
    }
    return 0;
}

