// binarytree.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "malloc.h"
#include "chapter5.h"


BinTree createEmptyBinTree(void) //创建一棵空的二叉树。
{ 
	BinTree p; 
	p=(BinTree)malloc(sizeof(struct BinTreeNode)); 
	return p; 
} 

int isNull( BinTree t ) //判断二叉树t是否为空。 
{  
	if(t==NULL)  
	{   
		printf("此二叉树为空！\n");   
		return 0;  
	}  
	else    return 1; 
}  

BinTree consBinTree()//建立一棵二叉树，其根结点是root，左右二叉树分别为left和right 
{  
	BinTree root;     
	char ch;      
	scanf("%c",&ch);   
	if ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))    
	{       
		root=createEmptyBinTree();      
		root->info=ch;       
		root->llink=consBinTree();     
		root->rlink=consBinTree();   
	}     
    else if (ch == '.')
    {
        root = NULL; // 明确以点号作为空子树标志
    }
    else
    {
        // 可以忽略其他非点号、非字母的字符（如空格、换行），或给出提示
        // 此处选择直接忽略，继续递归调用以读取下一个有效字符
        root = consBinTree();
    }
	return root; 
} 

PBinTreeNode root( BinTree t )//返回二叉树t的根结点。若为空二叉树，则返回一特殊值。 
{  
	if(t==NULL)   return NULL;  
	else   return t; 
}  

void visit(PBinTreeNode t) 
{  
	printf("%c  ",t->info); 
}  

PBinTreeNode leftChild_link( PBinTreeNode t )//返回t结点的左子树，当指定结点没有左子树时，返回一个特殊值。 
{  
	if(t ==NULL)  return NULL;  
	else  return t->llink; 
}  

PBinTreeNode rightChild_link( PBinTreeNode t)//返回p结点的右子树，当指定结点没有右子树时，返回一个特殊值。 
{  
	if(t ==NULL)   return NULL;  
	else  return t->rlink; 
} 


void preOrder( BinTree t)//显示先根周游序列 
{   
	if(t!=NULL)  
	{   
		visit(root(t));   
		preOrder(leftChild_link(t));   
		preOrder(rightChild_link(t));  
	} 
}


void inOrder(BinTree t)//显示中根周游序列 
{  
	if (t!=NULL)  
	{    
		inOrder(leftChild_link(t));   
		visit(root(t));   
		inOrder(rightChild_link(t));  
	} 
}  

void postOrder(BinTree t)//显示后根周游序列 
{ 
	if (t!=NULL)  
	{  
		postOrder(leftChild_link(t));  
		postOrder(rightChild_link(t));  
		visit(root(t)); 
	} 
}  


void show(BinTree t,int len)//数的形状 
{     
	if (t!=NULL)    
	{      
		show(t->rlink,len+1);       
		for (int i=1;i<=len;i++)  printf("   ");           
		printf("%c\n",t->info);      
		show(t->llink,len+1);  
	} 
}   

