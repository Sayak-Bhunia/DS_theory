#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* createNode(int x)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

TreeNode* constarr(int arr[],int i,int size)
{
    TreeNode* newNode = NULL;
    if(i<size) {
        newNode = createNode(arr[i]);
        newNode->left = constarr(arr, 2*i+1, size);
        newNode->right = constarr(arr, 2*i+2,size);
    }

    return newNode;
}

TreeNode* insert_left(TreeNode* root,int x)
{
    root->left = createNode(x);
    return root->left;
}

TreeNode* insert_right(TreeNode* root,int x)
{
    root->right = createNode(x);
    return root->right;
}

void inorder(TreeNode* root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

void preorder(TreeNode* root)
{
    if(root == NULL) return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}

int main()
{
    int ch,size,i;
    printf("Enter number of nodes: ");
    scanf("%d",&size);
    int arr[size];
    printf("enter the elements: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    TreeNode *root = constarr(arr,0,size);

    while(1) {
        printf("1->INORDER\n");
        printf("2->PREORDER\n");
        printf("3->POSTORDER\n");;
        printf("4->EXIT\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: printf("INORDER\n");
                    inorder(root);
                    printf("\n");
                    break;
            case 2: printf("PREORDER\n");
                    preorder(root);
                    printf("\n");
                    break;
            case 3: printf("POSTORDER\n");
                    postorder(root);
                    printf("\n");
                    break;
            case 4: exit(0);
            default: printf("\nINVALID CHOICE!\n");
        }
    }
}