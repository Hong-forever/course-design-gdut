#include "stdio.h"
#include "malloc.h"
#include "chapter5.h"


int main() 
{  
	BinTree p1;  
	int k=1,num;     
	while(k)  
	{   
		printf("\n&&&&&&&&&&&&&&输入序号执行相应操作&&&&&&&&&&&&&&&&&\n");   
		printf("            输入1，建立一个二叉树！  \n"); 
		printf("---------------------------------------------------\n");   
		printf("            输入2，查看建立的二叉树！\n");   
		printf("---------------------------------------------------\n"); 
		printf("            输入3，先根周游二叉树！\n");   
		printf("---------------------------------------------------\n");   
		printf("            输入4，中根周游二叉树！\n");   
		printf("---------------------------------------------------\n"); 
		printf("            输入5，后根周游二叉树！\n");  
		printf("---------------------------------------------------\n"); 
		printf("            输入其他，退出操作！\n");   
		printf("---------------------------------------------------\n");   
		scanf("%d",&num);         
		switch (num)   
		{   
			case 1 :    
				while(!(p1=consBinTree()))    
					printf("请按照先根顺序输入二叉树元素(大小写字母),.代表子树为空\n");    
				if(p1)     printf("二叉树建立成功！\n");     
				else     printf("二叉树建立失败！\n");       
				break;   
			case 2 :       
				printf("建立的二叉树形状为：\n\n");     
				if(isNull(p1))      show(p1,0);       
				break;    
			case 3 :     
				printf("先根周游序列为：\n");       
				preOrder(p1);      
				printf("\n");     
				break;    
			case 4 :     
				printf("中根周游序列为：\n");       
				inOrder(p1);      
				printf("\n");     
				break; 
			case 5 :     
				printf("后根周游序列为：\n");       
				postOrder(p1);      
				printf("\n");   
				break;   
			default :  
				printf("您未选定任何操作！请重新输入操作序号！\n")     ;
				k=0;    
				break;   
		}  
	} 
	return 0; 

} 