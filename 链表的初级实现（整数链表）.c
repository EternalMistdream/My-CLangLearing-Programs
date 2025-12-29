#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define sizeofIntList 10

typedef struct IntList
{
    int num;                //32bits
    struct IntList* nextNode;   //8bits
}IntList;

IntList* createIntList(int num, IntList* nextNode)
{
    IntList* newNode = NULL;
    if ((newNode = malloc((unsigned int)sizeof(IntList))) == NULL)
    {
        printf("Failed to malloc RAM!\n");
        return NULL;
    }
    newNode->num = num;
    newNode->nextNode = nextNode;
    return newNode;
}

int getIntList(int index, IntList* node)
{
    if (node == NULL)
    {
        printf("The node is NULL\n");
        return -1;
    }
    else if (index == 1)
        return node->num;
    else
        return getIntList(index - 1, node->nextNode);
}

int sizeIntList(IntList* node)
{
    if (node == NULL)
    {
        printf("The node is NULL!\n");
        return -1;
    }
    else if (node->nextNode == NULL)
        return 1;
    else
        return (sizeIntList(node->nextNode) + 1);

}

void freeIntList(IntList* list)
{
    if (list == NULL) return;
    else if (list->nextNode == NULL)
    {
        free(list);
        printf("IntList has been cleared!\n");
        return;
    }
    else
    {
        IntList* tmp = list->nextNode;
        free(list);
        freeIntList(tmp);
    }
}

IntList* addNumBehandithIntList(int index, int num, IntList* const list)
{
    IntList* temp = list;
    while (true)
    {
        if (temp == NULL)
            return NULL;
        else if (index == 1)
            break;
        else
        {
            temp = temp->nextNode;
            index--;
        }
    }
    IntList* nextPtr = temp->nextNode;
    temp->nextNode = createIntList(num, nextPtr);
    return temp;
}

int main()
{
    unsigned int a = 1;
    IntList* Temp = createIntList(a, NULL);

    for (unsigned int i = 0; i < (sizeofIntList - 1); i++)
    {
        if ((Temp = createIntList(++a, Temp)) == NULL)
        {
            printf("Error to Create,pls try again!\n");
            return -1;
        }
    }

    IntList* Test01 = Temp;
    Temp = NULL;

    printf("链表的大小为%d,\n第6个数为%d\n",
        sizeIntList(Test01),
        getIntList(6, Test01));
    addNumBehandithIntList(5, 100, Test01);
    printf("第6个数为%d,\n新的链表大小为%d\n",
        getIntList(6, Test01),
        sizeIntList(Test01));

    freeIntList(Test01);
    return 0;

}