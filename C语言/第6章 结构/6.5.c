#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100
struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
void printTNode(struct tnode *node)
{
    if (!node)
        return;
    printTNode(node->left);
    printf("word:%s,count:%d\n", node->word, node->count);
    printTNode(node->right);
}
struct tnode *createNode()
{
    return malloc(sizeof(struct tnode));
}
struct tnode *addNode(struct tnode *node, char *word)
{
    if (!node)
    {
        struct tnode *newNode = createNode();
        newNode->word = word;
        newNode->count = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    int c = strcmp(node->word, word);
    if (c > 0)
        node->right = addNode(node->right, word);
    else if (c < 0)
        node->left = addNode(node->left, word);
    else
        node->count++;
    return node;
}
int main()
{
    char *test[] = {"auto", "void", "void", "while", "hello", "while", "break"};
    char *p = test;
    struct tnode *root;
    while (p)
    {
        addNode(root, p++);
    }
    printTNode(root);
    return 0;
}