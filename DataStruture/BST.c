#include "BST.h"
#include <stdlib.h>
#include "fatal.h"
#include <stdbool.h>
struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

bool IsEmpty(SearchTree T)
{
    return T == NULL;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    //Create and return a one-node tree
    if(T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
            FatalError("Out of space!!");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else
        if(X < T->Element)
            T->Left = Insert(X, T->Left);
    else 
        if(X > T-> Element)
            T->Right = Insert(X, T->Right);
        
    

    return T; 
}
Position Find(ElementType X, SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(X < T->Element)
        return Find(X,T->Left);
    else
        if(X > T->Element)
            return Find(X, T->Right);
    else
        return T;
}


ElementType Retrieve(Position P)
{
    return P->Element;
}

Position FindMin(SearchTree T)
{
    if(T == NULL)
        return NULL;
    else
        if(T->Left == NULL)
            return T;
    else
        return FindMin(T->Left);
}
Position FindMax(SearchTree T)
{
    if(T == NULL)
        return NULL;
    else
        if(T->Right == NULL)
            return T;
    else
        return FindMax(T->Right);
}
void PrintInOrder( SearchTree T)
{
    if(T == NULL)
    {
        return;
    }

        
    //printf(T->Left);
    //printf(T->Right);
    //printf("%d", T->Element);
        
    
}

int main()
{
    SearchTree T;
    Position P;
    
    T = MakeEmpty(NULL);
    T = Insert(4,T);
    T = Insert(5, T);
    T = Insert(6, T);
    T = Insert(10, T);
    T = Insert(7, T);
    
   



    printf("Min is %d, Max is %d\n", Retrieve(FindMin(T)),
            Retrieve(FindMax(T)));


    if(IsEmpty(T))
    {
        printf("Yes \n");
    }else 
    {
        printf("No \n");
    }

    return 0;
}






