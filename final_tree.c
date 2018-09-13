#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

struct response
{
    int stars;
    char title[20];
    int rating;
    char response[100];
    struct response *left, *right;
};

void print2DUtil(struct response *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->stars);

    // Process left child
    print2DUtil(root->left, space);
}

void print2D(struct response *root)
{
   print2DUtil(root, 0);
}

void inorder(struct response *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d  ", root->stars);
        inorder(root->right);
    }
}

void preorder(struct response *root)
{
    if(root!=NULL)
    {
        printf("%d  ",root->stars);
        preorder(root->left);
        preorder(root->right);
    }
}

struct response *create(){
    struct response *p;
    int x;
    printf("Enter stars (1-100) (-1 for no data):");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    p=(struct response *)malloc(sizeof(struct response));
    p->stars=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}

int main(){
    int ch;
    struct response *root = create();
    while(1){
        printf("\n1.Display TREE\n2.Show INORDER\n3.Show PREORDER\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: print2D(root);
                    break;
            case 2: inorder(root);
                    break;
            case 3: preorder(root);
                    break;
            case 4: exit(0);
            default:    printf("\nWrong choice!!\n");
        }
    }
    return 0;
}
