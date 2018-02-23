#include <stdio.h>
#include <stdlib.h>



typedef struct node_r *linkR;
typedef struct node_c *linkC;

struct node_r{
    linkR next;
    linkC headC;
};

struct node_c{
    int val;
    linkC next;

};

linkR newNodeR(linkR next);
linkC newNodeC(int val, linkC next);
int main()
{

    int i, j;
    linkR head=NULL;

    for(i=0; i<5; i++){
            head=newNodeR(head);
        for(j=0; j<5; j++){
            head->headC=newNodeC(i+j, head->headC);
        }

    }

    linkR r;
    linkC c;

    for(r=head; r!=NULL; r=r->next){
        for(c=r->headC; c!=NULL; c=c->next){
            printf("%d ", c->val);
        }
        printf("\n");
    }




    return 0;
}

linkC newNodeC(int val, linkC next){

    linkC node;
    node=malloc(sizeof(*node));
    node->val=val;
    node->next=next;

    return node;

}

linkR newNodeR(linkR next){

    linkR node;
    node=malloc(sizeof(*node));
    node->headC=NULL;
    node->next=next;

    return node;


}
