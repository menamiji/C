#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * link;
};
typedef struct node Node;

void printNode(Node * front){
    printf("[f]");
    while(front!=NULL) {
        printf("%d", front->value);
        front=front->link;
    }
    printf("[r]\n");
}

Node * push(Node * rear){
    int num;
    Node * temp = (Node *)malloc(sizeof(Node));
    scanf("%d", &num);
    temp->value = num;
    if(rear!=NULL) rear->link = temp; //첫노드리리
    return temp;
}

Node * pop(Node * front){
    Node * nextLink=front->link;
    printf("pop : %d\n", front->value);
    free(front);
    return nextLink;  
}

int main(void) {
    Node * front = NULL, * rear = NULL;
    int num;
    
    while(1) {
        printf("0-종료, 1-입력, 2-삭제, 3-출력 : ");
        scanf("%d", &num);
        if(num==0)
            break;
        else if(num==1){
            rear = push(rear);
            if(front==NULL) front = rear; //첫노드처리
        }
        else if(num==2 && front!=NULL){
            front = pop(front);
            if(front==NULL) rear = NULL; //마지막노드처리
        }
        else if(num==3)
            printNode(front);
    }
    return 0;
}