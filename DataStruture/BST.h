
//Martin Chibwe
typedef int ElementType;

#ifndef _BST_h
#define _BST_h

#define false 0
#define true 1
typedef int bool;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
ElementType Retreve(Position P);
Position FindMax(SearchTree T);
void PrintInOrder(SearchTree T);
//bool IsEmpty(SearchTree T);
#endif 
