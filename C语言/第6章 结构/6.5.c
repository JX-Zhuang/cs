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
    if (node == NULL)
        return;
    printTNode(node->left);
    printf("word:%s,count:%d\n", node->word, node->count);
    printTNode(node->right);
}
struct tnode *createNode()
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *addNode(struct tnode *node, char *word)
{
    int cond;
    if (node == NULL)
    {
        node = createNode();
        node->word = word;
        node->count = 1;
        node->left = node->right = NULL;
    }
    else if ((cond = strcmp(word, node->word)) == 0)
        node->count++;
    else if (cond > 0)
        node->right = addNode(node->right, word);
    else
        node->left = addNode(node->left, word);
    return node;
}
int main()
{
    char *test[] = {"auto", "void", "void", "while", "hello", "while", "break"};
    struct tnode *root = NULL;
    for (int i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        root = addNode(root, test[i]);
    }
    printTNode(root);
    return 0;
}