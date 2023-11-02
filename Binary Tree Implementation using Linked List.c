#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* createNode(int x) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

TreeNode* insertLeft(TreeNode* root, int x)
{
    root->left = createNode(x);
    return root->left;
}

TreeNode* insertRight(TreeNode* root, int x)
{
    root->right = createNode(x);
    return root->right;
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main()
{
    int parent, ch, n;
    printf("Enter root: ");
    scanf("%d", &parent);
    TreeNode *root = createNode(parent);
    while (1) {
        printf("1->INSERT LEFT\n");
        printf("2->INSERT RIGHT\n");
        printf("3->INORDER\n");
        printf("4->PREORDER\n");
        printf("5->POSTORDER\n");
        printf("6->EXIT\n");
        printf("ENTER CHOICE: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("ENTER NODE: ");
                scanf("%d", &n);
                insertLeft(root, n);
                break;
            case 2:
                printf("ENTER NODE: ");
                scanf("%d", &n);
                insertRight(root, n);
                break;
            case 3:
                printf("INORDER\n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("PREORDER\n");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("POSTORDER\n");
                postorder(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("\nINVALID CHOICE!\n");
        }
    }
}
