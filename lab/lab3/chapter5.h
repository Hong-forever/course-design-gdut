// binarytree.cpp : Defines the entry point for the console application.
//
#ifndef _CHAPTER5_
#define _CHAPTER5_

typedef char DataType;

struct BinTreeNode;
typedef struct BinTreeNode * PBinTreeNode;
struct BinTreeNode
{ 
	DataType info; 
	PBinTreeNode llink; 
	PBinTreeNode rlink; 
}; 
typedef PBinTreeNode BinTree;

// 队列节点结构
typedef struct QueueNode {
    PBinTreeNode treeNode;
    struct QueueNode *next;
} QueueNode;

// 队列结构
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} LinkQueue;





BinTree createEmptyBinTree(void) ;
int isNull ( BinTree t ) ;
BinTree consBinTree();
PBinTreeNode root( BinTree t );
void visit(PBinTreeNode t)  ;
PBinTreeNode leftChild_link( PBinTreeNode t );
PBinTreeNode rightChild_link( PBinTreeNode t);
void preOrder( BinTree t);
void inOrder(BinTree t);
void postOrder(BinTree t);
void show(BinTree t,int len);
int getTreeDepth(BinTree root);
void printLevel(BinTree root, int level);
void levelOrder(BinTree root);




#endif
