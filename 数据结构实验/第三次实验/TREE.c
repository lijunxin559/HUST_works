/* 基于二叉链表结构的二叉树实现 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
//函数结果状态常量

typedef int status;

typedef struct {
	char name[20];//姓名
	char id[20];//学号
}ElemType; //数据元素类型定义

typedef struct BiTNode{
	ElemType data;//数据元素
	struct BiTNode *lchild;
	struct BiTNode *rchild;//左右孩子指针
}BiTNode;//二叉树节点

typedef struct {
	char name[20];//二叉树名字
	struct BiTNode * bnext;//二叉树根节点指针
}HeadNode;//头结点

typedef struct ChainNode{
	struct ChainNode *next;//为层序遍历创建的辅助链表结构
	struct BiTNode *tnext;
}ChainNode;

status seat(HeadNode *TREES[],int n);
status InitBiTree(HeadNode ** T);
status DestroyBiTree(HeadNode **T);
struct BiTNode * CreateBiTree(BiTNode *T);
struct BiTNode * ClearBiTree(BiTNode *T);
status BiTreeEmpty(HeadNode * T);
int BiTreeDepth(BiTNode *T);
struct BiTNode *Root(HeadNode *T);
char * Value(BiTNode *T, char id[]);
status Assign(BiTNode *T, char name[],char id[]);
struct BiTNode *Parent(BiTNode *T, char id[]);
struct BiTNode *LeftChild(BiTNode *T, char id[]);
struct BiTNode *RightChild(BiTNode *T, char id[]);
struct BiTNode *LeftSibling(BiTNode *T, char id[]);
struct BiTNode *RightSibling(BiTNode *T, char id[]);
status InsertChild(BiTNode *T, char id[], int LR, BiTNode *c);
status DeleteChild(BiTNode *T, char id[], int LR);
status PreOrderTraverse(BiTNode *T, status (*Visit)(BiTNode *T1));
status InOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1));
status PostOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1));
status LevelOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1));
status Preserve(BiTNode *T);
status Visit(BiTNode *T);
status check(HeadNode *T);
status Load_File(HeadNode **T,char *filename);
status Preorderread(BiTNode** T,FILE *fp);
status PreOrderwrite(BiTNode* T, FILE *fp);
status Save(HeadNode *T, char *filename);
int main(void){
  HeadNode *headnode = NULL;//二叉树头结点
  HeadNode *c = NULL;//InsertChild函数需要临时构建的二叉树头结点
  HeadNode *TREES[10]={NULL};
  int LR,number = 0,e,i;
  char id[20];
  char name[20];
  char Name[20];
  int op = 1;
  int k = 0;
  while(op){
	system("cls");
	printf("\n\n");
	printf("      Menu for BiTree Table On Chain Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. InitBiTree       12.RightChild\n");
	printf("    	  2. DestroyBiTree    13.LeftSibling\n");
	printf("    	  3. CreateBiTree     14.RightSibling\n");
	printf("    	  4. ClearBiTree      15.InsertChild\n");
	printf("    	  5. BiTreeEmpty      16.DeleteChild\n");
	printf("    	  6. BiTreeDepth      17.PreOrderTraverse\n");
	printf("    	  7. Root             18.InOrderTraverse\n");
	printf("    	  8. Value            19.PostOrderTraverse\n");
	printf("    	  9. Assign           20.LevelOrderTraverse\n");
	printf("          10.Parent           21.Save\n");
	printf("          11.LeftChild        22.Change\n"     );
	printf("          23.TraverseTREES    24.Load\n");
	printf("          0.exit                        ");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~20]:");
	scanf("%d",&op);
    switch(op){
	case 1:
	{
	    k = seat(TREES,10);
	    if(k == -1){
            printf("空间已满，无法存储多余的树！");
	    }
	    else
	    {
		    if (InitBiTree(&(TREES[k]))){
                printf("构造空二叉树T成功！\n");
                number++;
		    }
		    else printf("构造空二叉树T失败！\n");
	    }
		getchar(); getchar();
		break;
	}
	case 2:
	{
		if (DestroyBiTree(&TREES[k]))printf("销毁二叉树成功！\n");
		else printf("销毁二叉树失败！\n");
		getchar(); getchar();
		break;
	}
	case 3:
	{
		if (TREES[k]== NULL)
		{
			printf("二叉树尚未初始化！无法完成创造！\n");
			getchar(); getchar();
			break;
		}
		else if (TREES[k]->bnext != NULL)
		{
			printf("二叉树中已经存在至少一个节点！\n无法完成创造！\n");
			getchar(); getchar();
			break;
		}
		printf("请根据提示，按照先序遍历顺序输入二叉树！\n");
		TREES[k]->bnext = (BiTNode *)malloc(sizeof(BiTNode));
		if ((TREES[k]->bnext=CreateBiTree(TREES[k]->bnext))!=NULL)printf("二叉树创造成功！\n");
		else printf("二叉树创造失败！\n");
		getchar(); getchar();
		break;
	}
	case 4:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if ((TREES[k]->bnext = ClearBiTree(TREES[k]->bnext)) == NULL) printf("清空二叉树成功！\n");
		else printf("清空二叉树失败！\n");
		getchar(); getchar();
		break;
	}
	case 5:
	{
		if (BiTreeEmpty(TREES[k]))printf("判定成功！\n");
		else printf("判定失败！\n");
		getchar(); getchar();
		break;
	}
	case 6:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("该二叉树的深度是：%d", BiTreeDepth(TREES[k]->bnext));
		getchar(); getchar();
		break;
	}
	case 7:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if (Root(TREES[k]) != NULL){
            printf("求根节点成功！\n");
            printf("根节点的姓名为：%s\n",Root(TREES[k])->data.name);
            printf("根节点的学号为：%s\n",Root(TREES[k])->data.id);
		}
		else printf("求根节点失败！\n");
		getchar(); getchar();
		break;
	}
	case 8:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("请输入您希望查询的学号：\n");
		scanf("%s", id);
		if (Value(TREES[k]->bnext, id) != NULL)
		{
			printf("获得节点成功！\n");
			strcpy(name, Value(TREES[k]->bnext, id));
			printf("%s", name);
		}
		else printf("获得节点失败！\n");
		getchar();getchar();
		break;
	}
	case 9:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("请输入您希望查询的学号：\n");
		scanf("%s", id);
		printf("请输入您希望赋值的姓名：\n");
		scanf("%s", name);
		if (Assign(TREES[k]->bnext,id,name))  printf("赋值成功！\n");
		else printf("赋值失败！\n");
		getchar();getchar();
		break;
	}
	case 10:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("请输入您希望获取双亲节点的节点的学号：\n");
		scanf("%s", id);
		if (Parent(TREES[k]->bnext,id)!=NULL)
		{
			printf("获取双亲节点成功！\n");
			Visit(Parent(TREES[k]->bnext, id));
		}
		else printf("获得双亲节点失败！\n");
		getchar(); getchar();
		break;
	}
	case 11:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("请输入您希望获取左孩子的节点的学号：\n");
		scanf("%s", id);
		if (LeftChild(TREES[k]->bnext, id) != NULL)
		{
			printf("获取左孩子成功！\n");
			Visit(LeftChild(TREES[k]->bnext, id));
		}
		else printf("获得左孩子失败！\n");
		getchar(); getchar();
		break;
	}
	case 12:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("请输入您希望获取右孩子的节点的学号：\n");
		scanf("%s", id);
		if (RightChild(TREES[k]->bnext, id) != NULL)
		{
			printf("获取右孩子成功！\n");
			Visit(RightChild(TREES[k]->bnext, id));
		}
		else printf("获得右孩子失败！\n");
		getchar(); getchar();
		break;
	}
	case 13:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("请输入您希望获取左兄弟的节点的学号：\n");
		scanf("%s", id);
		if (LeftSibling(TREES[k]->bnext, id) != NULL)
		{
			printf("获取左兄弟成功！\n");
			Visit(LeftSibling(TREES[k]->bnext, id));
		}
		else printf("获得左兄弟失败！\n");
		getchar(); getchar();
		break;
	}
	case 14:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("请输入您希望获取右兄弟的节点的学号：\n");
		scanf("%s", id);
		if (RightSibling(TREES[k]->bnext, id) != NULL)
		{
			printf("获取右兄弟成功！\n");
			Visit(RightSibling(TREES[k]->bnext, id));
		}
		else printf("获得右兄弟失败！\n");
		getchar(); getchar();
		break;
	}
	case 15:
	{
		if (check(TREES[k]) == FALSE)
			break;
		DestroyBiTree(&c);
		InitBiTree(&c);
		printf("请根据提示，按照先序遍历顺序输入二叉树作为子树！\n");
		c->bnext = (BiTNode *)malloc(sizeof(BiTNode));
		if ((c->bnext = CreateBiTree(c->bnext)) != NULL)printf("二叉树创造成功！\n");
		else printf("二叉树创造失败！\n");
		printf("请输入您希望插入的节点的学号：\n");
		scanf("%s", id);
		printf("0代表插入左子树，1代表插入右子树\n请您输入插入左子树或者右子树：");
		scanf("%d", &LR);
		if (InsertChild(TREES[k]->bnext, id, LR, c->bnext) == OK) printf("插入成功！\n");
		else printf("插入失败！\n");
		getchar();getchar();
		break;
	}
	case 16:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("请输入您希望开始删除子树的节点的学号：\n");
		scanf("%s", id);
		printf("0为删除左子树，其余为删除右子树\n请选择删除左子树或者右子树：\n");
		scanf("%d", &LR);
		if (DeleteChild(TREES[k]->bnext, id, LR) == OK)printf("删除成功！\n");
		else printf("删除失败！\n");
		getchar(); getchar();
		break;
	}
	case 17:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if (PreOrderTraverse(TREES[k]->bnext,Visit)) printf("先序遍历成功！\n");
		else printf("先序遍历失败！\n");
		getchar(); getchar();
		break;
	}
	case 18:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if (InOrderTraverse(TREES[k]->bnext, Visit)) printf("中序遍历成功！\n");
		else printf("中序遍历失败！\n");
		getchar(); getchar();
		break;
	}
	case 19:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if (PostOrderTraverse(TREES[k]->bnext, Visit)) printf("后序遍历成功！\n");
		else printf("后序遍历失败！\n");
		getchar(); getchar();
		break;
	}
	case 20:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if (LevelOrderTraverse(TREES[k]->bnext, Visit)) printf("层序遍历成功！\n");
		else printf("层序遍历失败！\n");
		getchar(); getchar();
		break;
	}
	case 21:
	{
        printf("请输入想要保存的文件名：\n");
        scanf("%s",Name);
		if (Save(TREES[k],Name)==OK)	printf("保存成功！\n");
		else printf("保存失败！\n");
		getchar(); getchar();
		break;
	}
	case 22:
    {
        printf("请输入你想操作的树的名字：\n");
        scanf("%s",Name);
        for(e = 0;e < 10;e++){
            if(!strcmp(Name,TREES[e]->name)){
                k = e;
                break;
            }
        }
        if(e == 10)
            printf("没有该树，请检查！");
        getchar();getchar();
        break;
    }
    case 23:
    {
        i = 0;
        for(e = 0;e < 10;e++)
        {   if(TREES[e]!=NULL)
                printf("树名：%s\n",TREES[e]->name);
            else
                i++;
        }
        printf("一共%d棵非空树",10-i);
        getchar();getchar();
        break;

    }
    case 24:
	{
        printf("请输入想要加载的文件名：\n");
        scanf("%s",Name);
		if (Load_File(&TREES[k],Name)==OK)	printf("加载成功！\n");
		else printf("加载失败！\n");
		getchar(); getchar();
		break;
	}

	case 0:
         break;

	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");

  return 0;
}//end of main()

 /*
 *函数名称：InitBiTree
 *输入参数：二叉树头结点指针地址 T
 *返回值：Status
 *函数功能：初始化二叉树
 */
status seat(HeadNode *TREES[],int n)
 {
     int i = 0;
     for(;i < n;i++){
        if(TREES[i] == NULL)
        return i;
     }
     return -1;
 }

status InitBiTree(HeadNode ** T)
{
	if ((*T) != NULL)
	{
		printf("头结点指向位置非空！\n二叉树可能已经存在！\n");
		return FALSE;
	}
	else
	{
		*T = (HeadNode *)malloc(sizeof(HeadNode));
		printf("请为该二叉树命名：");
		scanf("%s", ((*T)->name));
		(*T)->bnext = NULL;
		return TRUE;
	}
}
/*
*函数名称：DestroyBiTree
*输入参数：二叉树头结点指针地址 T
*返回值：Status
*函数功能：销毁二叉树
*/
status DestroyBiTree(HeadNode ** T)
{
	if (*T == NULL)
	{//二叉树尚未初始化，提示错误信息
		printf("二叉树尚未初始化！\n");
		return FALSE;
	}
	else
	{
		if ((*T)->bnext != NULL)
		{//若二叉树已经创建
			if (ClearBiTree((*T)->bnext) != NULL)
			{//清空二叉树，失败时提示
				printf("清空二叉树失败！\n");
				return FALSE;
			}
		}
		free(*T);//释放头结点
		*T = NULL;
		return OK;
	}
}
/*
*函数名称：CreateBiTree
*输入参数：二叉树结点指针 T
*返回值：二叉树节点指针 BiTNode *
*函数功能：递归创建二叉树
*/
struct BiTNode * CreateBiTree(BiTNode *T)
{
	ElemType temp;
	printf("请根据提示输入，若为空节点，则在姓名处以‘0’表示\n");
	printf("请输入姓名：");
	scanf("%s", temp.name);
	if (temp.name[0] == '0')
	{//若该节点为空节点，则返回NULL
		printf("该节点为空节点，按任意键继续\n");
		getchar(); getchar();
		T = NULL;
		return T;
	}
	else T = (BiTNode *)malloc(sizeof(BiTNode));//为T申请内存空间
	printf("请输入学号：");
	scanf("%s", temp.id);

	T->data = temp;
	T->lchild=CreateBiTree(T->lchild);//递归创建T的左子树
	printf("该节点的姓名为 %s\n", T->data.name);
	if (T->lchild == NULL)
		printf("该节点的左子树为空\n");
	else printf("该节点的左子树非空\n");//提示信息
	T->rchild = CreateBiTree(T->rchild);//递归创建T的右子树
	printf("该节点的姓名为 %s\n", T->data.name);
	if (T->rchild == NULL)
		printf("该节点的右子树为空\n");
	else printf("该节点的右子树非空\n");//提示信息
	return T;
}
/*
*函数名称：ClearBiTree
*输入参数：二叉树结点指针 T
*返回值：二叉树节点指针 BiTNode *
*函数功能：清空二叉树
*/
struct BiTNode * ClearBiTree(BiTNode *T)
{
	if (T->lchild != NULL)
		T->lchild = ClearBiTree(T->lchild);//递归清空T的左子树
	if (T->rchild != NULL)
		T->rchild = ClearBiTree(T->rchild);//递归清空T的右子树
	free(T);//释放T节点空间
	T = NULL;
	return T;
}
/*
*函数名称：BiTreeEmpty
*输入参数：二叉树头结点指针 T
*返回值：status
*函数功能：判断二叉树是否为空
*/
status BiTreeEmpty(HeadNode *T)
{
	if (T == NULL)
	{
		printf("二叉树尚未初始化！\n");
		return FALSE;
	}
	else if (T->bnext == NULL)
	{
		printf("该二叉树是空二叉树！\n");
		return OK;
	}
	else
	{
		printf("该二叉树非空！\n");
		return OK;
	}
}
/*
*函数名称：BiTreeDepth
*输入参数：二叉树结点指针 T
*返回值：int
*函数功能：求二叉树深度
*/
int BiTreeDepth(BiTNode *T)
{
	int depth = 0;
	int leftdepth = 0;
	int rightdepth = 0;
	if (T != NULL)
	{
		leftdepth = BiTreeDepth(T->lchild);//递归求取T的左子树深度
		rightdepth = BiTreeDepth(T->rchild);//递归求取T的右子树深度
		depth = leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;//求取T的深度
	}
	return depth;//返回T的深度
}
/*
*函数名称：Root
*输入参数：二叉树头结点指针 T
*返回值：二叉树节点指针 BiTNode *
*函数功能：求二叉树根节点
*/
struct BiTNode *Root(HeadNode *T)
{
	return (T->bnext);
}
/*
*函数名称：Value
*输入参数：二叉树结点指针 T，字符数组 id
*返回值：字符指针
*函数功能：获得指定节点的值
*/
char * Value(BiTNode *T, char id[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *pnext;
	ChainNode *tail = head;
	head->next = NULL;
	head->tnext = T;
	//构建链表模拟队列，将头结点入队
	while (p != NULL)
	{//队不为空
		if (strcmp(id, p->tnext->data.id) == 0)
		{//找到符合要求的节点，返回值
			return p->tnext->data.name;
		}
		if (p->tnext->lchild != NULL)
		{//队头节点的左孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//队头结点的右孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;//指针后移
	}
	printf("该节点不在二叉树内！请检查！\n");//遍历二叉树未发现指定节点，提示错误信息
	for (p = head;p != NULL;p = pnext)
	{//清空队列
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*函数名称：Assign
*输入参数：二叉树结点指针 T，字符数组 id，字符数组 name
*返回值：status
*函数功能：对指定节点赋值
*/
status Assign(BiTNode *T, char id[], char name[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *pnext;
	ChainNode *tail = head;
	head->next = NULL;
	head->tnext = T;
	//构建链表模拟队列，将头结点入队
	while (p != NULL)
	{//队不为空
		if (strcmp(id, p->tnext->data.id) == 0)
		{//找到符合要求的节点，对该节点赋值
			strcpy(p->tnext->data.name, name);
			return OK;
		}
		if (p->tnext->lchild != NULL)
		{//队头节点的左孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//队头结点的右孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next; // 指针后移
	}
	printf("该节点不在二叉树内！请检查！\n");//遍历二叉树未发现指定节点，提示错误信息
	for (p = head;p != NULL;p = pnext)
	{//清空队列
		pnext = p->next;
		free(p);
	}
	return FALSE;
}
/*
*函数名称：PreOrderTraverse
*输入参数：二叉树结点指针 T，函数指针 Visit
*返回值：status
*函数功能：前序遍历二叉树
*/
status PreOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1))
{
	if (T == NULL)
	{//若该节点为空，输出提示信息
		printf("该节点是空节点！\n\n");
		return FALSE;
	}
	Visit(T);//访问该节点
	PreOrderTraverse(T->lchild,Visit);//递归遍历其左子树
	PreOrderTraverse(T->rchild,Visit);//递归遍历其右子树
	return OK;
}
/*
*函数名称：InOrderTraverse
*输入参数：二叉树结点指针 T，函数指针 Visit
*返回值：status
*函数功能：中序遍历二叉树
*/
status InOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1))
{
	if (T == NULL)
	{//若该节点为空，输出提示信息
		printf("该节点是空节点！\n\n");
		return FALSE;
	}
	InOrderTraverse(T->lchild, Visit);//递归遍历其左子树
	Visit(T);//访问该节点
	InOrderTraverse(T->rchild, Visit);//递归遍历其右子树
	return OK;
}
/*
*函数名称：PostOrderTraverse
*输入参数：二叉树结点指针 T，函数指针 Visit
*返回值：status
*函数功能：后序遍历二叉树
*/
status PostOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1))
{
	if (T == NULL)
	{//若该节点为空，输出提示信息
		printf("该节点是空节点！\n\n");
		return FALSE;
	}
	PostOrderTraverse(T->lchild, Visit);//递归遍历其左子树
	PostOrderTraverse(T->rchild, Visit);//递归遍历其右子树
	Visit(T);//访问该节点
	return OK;
}
/*
*函数名称：LevelOrderTraverse
*输入参数：二叉树结点指针 T，函数指针 Visit
*返回值：status
*函数功能：层序遍历二叉树
*/
status LevelOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1))
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;
	//构建链表模拟队列，将头结点入队
	while (p != NULL)
	{//队不为空
		Visit(p->tnext);//访问该节点
		if (p->tnext->lchild != NULL)
		{//队头节点的左孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//队头结点的右孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;//指针后移
	}
	for (p = head;p != NULL;p = pnext)
	{//清空队列
		pnext = p->next;
		free(p);
	}
	return OK;
}
/*
*函数名称：Visit
*输入参数：二叉树结点指针 T
*返回值：status
*函数功能：访问节点
*/
status Visit(BiTNode *T)
{
	if (T != NULL)
	{
		printf("您正在遍历的节点是：\n");
		printf("学生姓名：%s\n", T->data.name);
		printf("学生学号：%s\n\n", T->data.id);
		return OK;
	}
	else
	{
		printf("该节点为空节点！\n");
		return FALSE;
	}
}
/*
*函数名称：check
*输入参数：头结点指针 T
*返回值：status
*函数功能：检查二叉树是否初始化、是否创建
*/
status check(HeadNode *T)
{
	if (T == NULL)
	{
		printf("二叉树尚未初始化！无法完成操作！\n");
		getchar(); getchar();
		return FALSE;
	}
	else if (T->bnext == NULL)
	{
		printf("二叉树尚未创建！无法完成操作！\n");
		getchar(); getchar();
		return FALSE;
	}
	else return TRUE;
}
/*
*函数名称：Parent
*输入参数：二叉树结点指针 T，字符数组 id
*返回值：二叉树节点指针 BiTNode *
*函数功能：求指定节点的双亲节点
*/
struct BiTNode *Parent(BiTNode *T, char id[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;
	//构建链表模拟队列，将头结点入队
	while (p != NULL)
	{//队不为空
		if (p->tnext->lchild != NULL)
		{//找到符合要求的节点，返回值
			if (strcmp(id, p->tnext->lchild->data.id) == 0
			&&p->tnext!=T)
			return p->tnext;
		}
		if (p->tnext->rchild != NULL)
		{//找到符合要求的节点，返回值
			if (strcmp(id, p->tnext->rchild->data.id) == 0
				&& p->tnext != T)
				return p->tnext;
		}
		if (p->tnext->lchild != NULL)
		{//队头节点的左孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//队头结点的右孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;//指针后移
	}
	printf("该节点不在二叉树内或者双亲节点为根节点！请检查！\n");//遍历二叉树未发现指定节点，提示错误信息
	for (p = head; p != NULL; p = pnext)
	{//清空队列
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*函数名称：LeftChild
*输入参数：二叉树结点指针 T，字符数组 id
*返回值：二叉树节点指针 BiTNode *
*函数功能：求指定节点的左孩子
*/
struct BiTNode *LeftChild(BiTNode *T, char id[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;
	//构建链表模拟队列，将头结点入队
	while (p != NULL)
	{//找到符合要求的节点，返回值
		if (strcmp(p->tnext->data.id, id) == 0)
			if (p->tnext->lchild != NULL)
				return p->tnext->lchild;
		if (p->tnext->lchild != NULL)
		{//队头节点的左孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//队头结点的右孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;//指针后移
	}
	printf("该节点不在二叉树内或者没有左孩子！请检查！\n");//遍历二叉树未发现指定节点，提示错误信息
	for (p = head; p != NULL; p = pnext)
	{//清空队列
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*函数名称：RightChild
*输入参数：二叉树结点指针 T，字符数组 id
*返回值：二叉树节点指针 BiTNode *
*函数功能：求指定节点的右孩子
*/
struct BiTNode *RightChild(BiTNode *T, char id[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;

	while (p != NULL)
	{
		if (strcmp(p->tnext->data.id, id) == 0)
			if (p->tnext->rchild != NULL)
				return p->tnext->rchild;
		if (p->tnext->lchild != NULL)
		{
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;
	}
	printf("该节点不在二叉树内或者没有右孩子！请检查！\n");
	for (p = head; p != NULL; p = pnext)
	{
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*函数名称：LeftSibling
*输入参数：二叉树结点指针 T，字符数组 id
*返回值：二叉树节点指针 BiTNode *
*函数功能：求指定节点的左兄弟
*/
struct BiTNode *LeftSibling(BiTNode *T, char id[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;
	while (p != NULL)
	{
		if (p->tnext->rchild!=NULL
			&&strcmp(id, p->tnext->rchild->data.id) == 0)
			if (p->tnext->lchild != NULL)
				return p->tnext->lchild;
		if (p->tnext->lchild != NULL)
		{
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;
	}
	printf("该节点不在二叉树内或者没有左兄弟！请检查！\n");
	for (p = head; p != NULL; p = pnext)
	{
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*函数名称：RightSibling
*输入参数：二叉树结点指针 T，字符数组 id
*返回值：二叉树节点指针 BiTNode *
*函数功能：求指定节点的右兄弟
*/
struct BiTNode *RightSibling(BiTNode *T, char id[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;
	while (p != NULL)
	{
		if (p->tnext->lchild != NULL
			&&strcmp(id, p->tnext->lchild->data.id) == 0)
			if (p->tnext->rchild != NULL)
				return p->tnext->rchild;
		if (p->tnext->lchild != NULL)
		{
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;
	}
	printf("该节点不在二叉树内或者没有右兄弟！请检查！\n");
	for (p = head; p != NULL; p = pnext)
	{
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*函数名称：InsertChild
*输入参数：二叉树结点指针 T，字符数组 id，整型数字 LR，二叉树结点指针 c
*返回值：status
*函数功能：插入子树
*/
status InsertChild(BiTNode *T, char id[], int LR, BiTNode *c)
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;
	T = NULL;
	//构建链表模拟队列，将头结点入队
	while (p != NULL)
	{//队不为空
		if (strcmp(id, p->tnext->data.id) == 0)
		{//找到符合要求的节点，用T记录其值
			T = p->tnext;
			break;
		}
		if (p->tnext->lchild != NULL)
		{//队头节点的左孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//队头结点的右孩子入队
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;
	}

	for (p = head; p != NULL; p = pnext)
	{//清空队列
		pnext = p->next;
		free(p);
	}
	if (T == NULL)
	{//遍历二叉树未发现指定节点，提示错误信息
		printf("该节点不在二叉树内,请检查！\n");
		return FALSE;
	}
	if(LR)
	{//若LR为1，则将c插入T的右子树，T原先的右子树作为c的右子树
		if (c->rchild != NULL)
		{
			printf("c的右子树非空！\n");
			return FALSE;
		}
		c->rchild = T->rchild;
		T->rchild = c;
		return OK;
	}
	else
	{//若LR为0，则将c插入T的左子树，T原先的左子树作为c的左子树
		if (c->lchild != NULL)
		{
			printf("c的左子树非空！\n");
			return FALSE;
		}
		c->rchild = T->lchild;
		T->lchild = c;
		return OK;
	}
}
/*
*函数名称：DeleteChild
*输入参数：二叉树结点指针 T，字符数组 id，整型数字 LR
*返回值：status
*函数功能：删除子树
*/
status DeleteChild(BiTNode *T, char id[], int LR)
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;
	T = NULL;
	while (p != NULL)
	{
		if (strcmp(id, p->tnext->data.id) == 0)
		{
			T = p->tnext;
		}
		if (p->tnext->lchild != NULL)
		{
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;
	}

	for (p = head; p != NULL; p = pnext)
	{
		pnext = p->next;
		free(p);
	}

	if (T == NULL)
	{
		printf("该节点可能不在二叉树内，请检查！\n");
		return FALSE;
	}
	if (LR)
		T->rchild = ClearBiTree(T->rchild);//若LR为1，删除T的右子树
	else
		T->lchild = ClearBiTree(T->lchild);//若LR为0，删除T的左子树
		return OK;
}

status PreOrderwrite(BiTNode* T, FILE *fp)
{
    ElemType a;
    strcpy(a.id,"0000");
    strcpy(a.name,"0000");
    if(T!=NULL){
       fwrite(&(T->data),sizeof(ElemType),1,fp);
       PreOrderwrite(T->lchild,fp);
       PreOrderwrite(T->rchild,fp);
    }
    else
       fwrite(&a,sizeof(ElemType),1,fp);
}
status Save(HeadNode *T, char *filename)
{
    FILE *fp;
    if((fp = fopen(filename,"wb")) == NULL){
        printf("File open error！\n");
        getchar();
        return ERROR;
    }
    fwrite(T->name,20,1,fp);
    PreOrderwrite(T->bnext,fp);
    fclose(fp);
    return OK;

}

status Preorderread(BiTNode ** T,FILE *fp)
{
    ElemType m;
    BiTNode* K;
    fread(&m,sizeof(ElemType),1,fp);
    if(!strcmp(m.id,"0000")&&!strcmp(m.name,"0000")){
        *T = NULL;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = m;
        Preorderread(&((*T)->lchild),fp);
        Preorderread(&((*T)->rchild),fp);
    }
}
status Load_File(HeadNode **T,char *filename)
{
    FILE *fp;
    if((fp = fopen(filename,"rb")) == NULL){
       printf("没有找到该文件！\n");
       return ERROR;
    }
    fread((*T)->name,20,1,fp);
    Preorderread((&(*T)->bnext),fp);
    fclose(fp);
    return OK;
}

