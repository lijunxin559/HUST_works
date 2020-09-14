/* ���ڶ�������ṹ�Ķ�����ʵ�� */
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
//�������״̬����

typedef int status;

typedef struct {
	char name[20];//����
	char id[20];//ѧ��
}ElemType; //����Ԫ�����Ͷ���

typedef struct BiTNode{
	ElemType data;//����Ԫ��
	struct BiTNode *lchild;
	struct BiTNode *rchild;//���Һ���ָ��
}BiTNode;//�������ڵ�

typedef struct {
	char name[20];//����������
	struct BiTNode * bnext;//���������ڵ�ָ��
}HeadNode;//ͷ���

typedef struct ChainNode{
	struct ChainNode *next;//Ϊ������������ĸ�������ṹ
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
  HeadNode *headnode = NULL;//������ͷ���
  HeadNode *c = NULL;//InsertChild������Ҫ��ʱ�����Ķ�����ͷ���
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
	printf("    ��ѡ����Ĳ���[0~20]:");
	scanf("%d",&op);
    switch(op){
	case 1:
	{
	    k = seat(TREES,10);
	    if(k == -1){
            printf("�ռ��������޷��洢���������");
	    }
	    else
	    {
		    if (InitBiTree(&(TREES[k]))){
                printf("����ն�����T�ɹ���\n");
                number++;
		    }
		    else printf("����ն�����Tʧ�ܣ�\n");
	    }
		getchar(); getchar();
		break;
	}
	case 2:
	{
		if (DestroyBiTree(&TREES[k]))printf("���ٶ������ɹ���\n");
		else printf("���ٶ�����ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 3:
	{
		if (TREES[k]== NULL)
		{
			printf("��������δ��ʼ�����޷���ɴ��죡\n");
			getchar(); getchar();
			break;
		}
		else if (TREES[k]->bnext != NULL)
		{
			printf("���������Ѿ���������һ���ڵ㣡\n�޷���ɴ��죡\n");
			getchar(); getchar();
			break;
		}
		printf("�������ʾ�������������˳�������������\n");
		TREES[k]->bnext = (BiTNode *)malloc(sizeof(BiTNode));
		if ((TREES[k]->bnext=CreateBiTree(TREES[k]->bnext))!=NULL)printf("����������ɹ���\n");
		else printf("����������ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 4:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if ((TREES[k]->bnext = ClearBiTree(TREES[k]->bnext)) == NULL) printf("��ն������ɹ���\n");
		else printf("��ն�����ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 5:
	{
		if (BiTreeEmpty(TREES[k]))printf("�ж��ɹ���\n");
		else printf("�ж�ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 6:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("�ö�����������ǣ�%d", BiTreeDepth(TREES[k]->bnext));
		getchar(); getchar();
		break;
	}
	case 7:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if (Root(TREES[k]) != NULL){
            printf("����ڵ�ɹ���\n");
            printf("���ڵ������Ϊ��%s\n",Root(TREES[k])->data.name);
            printf("���ڵ��ѧ��Ϊ��%s\n",Root(TREES[k])->data.id);
		}
		else printf("����ڵ�ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 8:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("��������ϣ����ѯ��ѧ�ţ�\n");
		scanf("%s", id);
		if (Value(TREES[k]->bnext, id) != NULL)
		{
			printf("��ýڵ�ɹ���\n");
			strcpy(name, Value(TREES[k]->bnext, id));
			printf("%s", name);
		}
		else printf("��ýڵ�ʧ�ܣ�\n");
		getchar();getchar();
		break;
	}
	case 9:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("��������ϣ����ѯ��ѧ�ţ�\n");
		scanf("%s", id);
		printf("��������ϣ����ֵ��������\n");
		scanf("%s", name);
		if (Assign(TREES[k]->bnext,id,name))  printf("��ֵ�ɹ���\n");
		else printf("��ֵʧ�ܣ�\n");
		getchar();getchar();
		break;
	}
	case 10:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("��������ϣ����ȡ˫�׽ڵ�Ľڵ��ѧ�ţ�\n");
		scanf("%s", id);
		if (Parent(TREES[k]->bnext,id)!=NULL)
		{
			printf("��ȡ˫�׽ڵ�ɹ���\n");
			Visit(Parent(TREES[k]->bnext, id));
		}
		else printf("���˫�׽ڵ�ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 11:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("��������ϣ����ȡ���ӵĽڵ��ѧ�ţ�\n");
		scanf("%s", id);
		if (LeftChild(TREES[k]->bnext, id) != NULL)
		{
			printf("��ȡ���ӳɹ���\n");
			Visit(LeftChild(TREES[k]->bnext, id));
		}
		else printf("�������ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 12:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("��������ϣ����ȡ�Һ��ӵĽڵ��ѧ�ţ�\n");
		scanf("%s", id);
		if (RightChild(TREES[k]->bnext, id) != NULL)
		{
			printf("��ȡ�Һ��ӳɹ���\n");
			Visit(RightChild(TREES[k]->bnext, id));
		}
		else printf("����Һ���ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 13:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("��������ϣ����ȡ���ֵܵĽڵ��ѧ�ţ�\n");
		scanf("%s", id);
		if (LeftSibling(TREES[k]->bnext, id) != NULL)
		{
			printf("��ȡ���ֵܳɹ���\n");
			Visit(LeftSibling(TREES[k]->bnext, id));
		}
		else printf("������ֵ�ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 14:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("��������ϣ����ȡ���ֵܵĽڵ��ѧ�ţ�\n");
		scanf("%s", id);
		if (RightSibling(TREES[k]->bnext, id) != NULL)
		{
			printf("��ȡ���ֵܳɹ���\n");
			Visit(RightSibling(TREES[k]->bnext, id));
		}
		else printf("������ֵ�ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 15:
	{
		if (check(TREES[k]) == FALSE)
			break;
		DestroyBiTree(&c);
		InitBiTree(&c);
		printf("�������ʾ�������������˳�������������Ϊ������\n");
		c->bnext = (BiTNode *)malloc(sizeof(BiTNode));
		if ((c->bnext = CreateBiTree(c->bnext)) != NULL)printf("����������ɹ���\n");
		else printf("����������ʧ�ܣ�\n");
		printf("��������ϣ������Ľڵ��ѧ�ţ�\n");
		scanf("%s", id);
		printf("0���������������1�������������\n�����������������������������");
		scanf("%d", &LR);
		if (InsertChild(TREES[k]->bnext, id, LR, c->bnext) == OK) printf("����ɹ���\n");
		else printf("����ʧ�ܣ�\n");
		getchar();getchar();
		break;
	}
	case 16:
	{
		if (check(TREES[k]) == FALSE)
			break;
		printf("��������ϣ����ʼɾ�������Ľڵ��ѧ�ţ�\n");
		scanf("%s", id);
		printf("0Ϊɾ��������������Ϊɾ��������\n��ѡ��ɾ��������������������\n");
		scanf("%d", &LR);
		if (DeleteChild(TREES[k]->bnext, id, LR) == OK)printf("ɾ���ɹ���\n");
		else printf("ɾ��ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 17:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if (PreOrderTraverse(TREES[k]->bnext,Visit)) printf("��������ɹ���\n");
		else printf("�������ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 18:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if (InOrderTraverse(TREES[k]->bnext, Visit)) printf("��������ɹ���\n");
		else printf("�������ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 19:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if (PostOrderTraverse(TREES[k]->bnext, Visit)) printf("��������ɹ���\n");
		else printf("�������ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 20:
	{
		if (check(TREES[k]) == FALSE)
			break;
		if (LevelOrderTraverse(TREES[k]->bnext, Visit)) printf("��������ɹ���\n");
		else printf("�������ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 21:
	{
        printf("��������Ҫ������ļ�����\n");
        scanf("%s",Name);
		if (Save(TREES[k],Name)==OK)	printf("����ɹ���\n");
		else printf("����ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 22:
    {
        printf("����������������������֣�\n");
        scanf("%s",Name);
        for(e = 0;e < 10;e++){
            if(!strcmp(Name,TREES[e]->name)){
                k = e;
                break;
            }
        }
        if(e == 10)
            printf("û�и��������飡");
        getchar();getchar();
        break;
    }
    case 23:
    {
        i = 0;
        for(e = 0;e < 10;e++)
        {   if(TREES[e]!=NULL)
                printf("������%s\n",TREES[e]->name);
            else
                i++;
        }
        printf("һ��%d�÷ǿ���",10-i);
        getchar();getchar();
        break;

    }
    case 24:
	{
        printf("��������Ҫ���ص��ļ�����\n");
        scanf("%s",Name);
		if (Load_File(&TREES[k],Name)==OK)	printf("���سɹ���\n");
		else printf("����ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}

	case 0:
         break;

	}//end of switch
  }//end of while
  printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");

  return 0;
}//end of main()

 /*
 *�������ƣ�InitBiTree
 *���������������ͷ���ָ���ַ T
 *����ֵ��Status
 *�������ܣ���ʼ��������
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
		printf("ͷ���ָ��λ�÷ǿգ�\n�����������Ѿ����ڣ�\n");
		return FALSE;
	}
	else
	{
		*T = (HeadNode *)malloc(sizeof(HeadNode));
		printf("��Ϊ�ö�����������");
		scanf("%s", ((*T)->name));
		(*T)->bnext = NULL;
		return TRUE;
	}
}
/*
*�������ƣ�DestroyBiTree
*���������������ͷ���ָ���ַ T
*����ֵ��Status
*�������ܣ����ٶ�����
*/
status DestroyBiTree(HeadNode ** T)
{
	if (*T == NULL)
	{//��������δ��ʼ������ʾ������Ϣ
		printf("��������δ��ʼ����\n");
		return FALSE;
	}
	else
	{
		if ((*T)->bnext != NULL)
		{//���������Ѿ�����
			if (ClearBiTree((*T)->bnext) != NULL)
			{//��ն�������ʧ��ʱ��ʾ
				printf("��ն�����ʧ�ܣ�\n");
				return FALSE;
			}
		}
		free(*T);//�ͷ�ͷ���
		*T = NULL;
		return OK;
	}
}
/*
*�������ƣ�CreateBiTree
*������������������ָ�� T
*����ֵ���������ڵ�ָ�� BiTNode *
*�������ܣ��ݹ鴴��������
*/
struct BiTNode * CreateBiTree(BiTNode *T)
{
	ElemType temp;
	printf("�������ʾ���룬��Ϊ�սڵ㣬�����������ԡ�0����ʾ\n");
	printf("������������");
	scanf("%s", temp.name);
	if (temp.name[0] == '0')
	{//���ýڵ�Ϊ�սڵ㣬�򷵻�NULL
		printf("�ýڵ�Ϊ�սڵ㣬�����������\n");
		getchar(); getchar();
		T = NULL;
		return T;
	}
	else T = (BiTNode *)malloc(sizeof(BiTNode));//ΪT�����ڴ�ռ�
	printf("������ѧ�ţ�");
	scanf("%s", temp.id);

	T->data = temp;
	T->lchild=CreateBiTree(T->lchild);//�ݹ鴴��T��������
	printf("�ýڵ������Ϊ %s\n", T->data.name);
	if (T->lchild == NULL)
		printf("�ýڵ��������Ϊ��\n");
	else printf("�ýڵ���������ǿ�\n");//��ʾ��Ϣ
	T->rchild = CreateBiTree(T->rchild);//�ݹ鴴��T��������
	printf("�ýڵ������Ϊ %s\n", T->data.name);
	if (T->rchild == NULL)
		printf("�ýڵ��������Ϊ��\n");
	else printf("�ýڵ���������ǿ�\n");//��ʾ��Ϣ
	return T;
}
/*
*�������ƣ�ClearBiTree
*������������������ָ�� T
*����ֵ���������ڵ�ָ�� BiTNode *
*�������ܣ���ն�����
*/
struct BiTNode * ClearBiTree(BiTNode *T)
{
	if (T->lchild != NULL)
		T->lchild = ClearBiTree(T->lchild);//�ݹ����T��������
	if (T->rchild != NULL)
		T->rchild = ClearBiTree(T->rchild);//�ݹ����T��������
	free(T);//�ͷ�T�ڵ�ռ�
	T = NULL;
	return T;
}
/*
*�������ƣ�BiTreeEmpty
*���������������ͷ���ָ�� T
*����ֵ��status
*�������ܣ��ж϶������Ƿ�Ϊ��
*/
status BiTreeEmpty(HeadNode *T)
{
	if (T == NULL)
	{
		printf("��������δ��ʼ����\n");
		return FALSE;
	}
	else if (T->bnext == NULL)
	{
		printf("�ö������ǿն�������\n");
		return OK;
	}
	else
	{
		printf("�ö������ǿգ�\n");
		return OK;
	}
}
/*
*�������ƣ�BiTreeDepth
*������������������ָ�� T
*����ֵ��int
*�������ܣ�����������
*/
int BiTreeDepth(BiTNode *T)
{
	int depth = 0;
	int leftdepth = 0;
	int rightdepth = 0;
	if (T != NULL)
	{
		leftdepth = BiTreeDepth(T->lchild);//�ݹ���ȡT�����������
		rightdepth = BiTreeDepth(T->rchild);//�ݹ���ȡT�����������
		depth = leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;//��ȡT�����
	}
	return depth;//����T�����
}
/*
*�������ƣ�Root
*���������������ͷ���ָ�� T
*����ֵ���������ڵ�ָ�� BiTNode *
*�������ܣ�����������ڵ�
*/
struct BiTNode *Root(HeadNode *T)
{
	return (T->bnext);
}
/*
*�������ƣ�Value
*������������������ָ�� T���ַ����� id
*����ֵ���ַ�ָ��
*�������ܣ����ָ���ڵ��ֵ
*/
char * Value(BiTNode *T, char id[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *pnext;
	ChainNode *tail = head;
	head->next = NULL;
	head->tnext = T;
	//��������ģ����У���ͷ������
	while (p != NULL)
	{//�Ӳ�Ϊ��
		if (strcmp(id, p->tnext->data.id) == 0)
		{//�ҵ�����Ҫ��Ľڵ㣬����ֵ
			return p->tnext->data.name;
		}
		if (p->tnext->lchild != NULL)
		{//��ͷ�ڵ���������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//��ͷ�����Һ������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;//ָ�����
	}
	printf("�ýڵ㲻�ڶ������ڣ����飡\n");//����������δ����ָ���ڵ㣬��ʾ������Ϣ
	for (p = head;p != NULL;p = pnext)
	{//��ն���
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*�������ƣ�Assign
*������������������ָ�� T���ַ����� id���ַ����� name
*����ֵ��status
*�������ܣ���ָ���ڵ㸳ֵ
*/
status Assign(BiTNode *T, char id[], char name[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *pnext;
	ChainNode *tail = head;
	head->next = NULL;
	head->tnext = T;
	//��������ģ����У���ͷ������
	while (p != NULL)
	{//�Ӳ�Ϊ��
		if (strcmp(id, p->tnext->data.id) == 0)
		{//�ҵ�����Ҫ��Ľڵ㣬�Ըýڵ㸳ֵ
			strcpy(p->tnext->data.name, name);
			return OK;
		}
		if (p->tnext->lchild != NULL)
		{//��ͷ�ڵ���������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//��ͷ�����Һ������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next; // ָ�����
	}
	printf("�ýڵ㲻�ڶ������ڣ����飡\n");//����������δ����ָ���ڵ㣬��ʾ������Ϣ
	for (p = head;p != NULL;p = pnext)
	{//��ն���
		pnext = p->next;
		free(p);
	}
	return FALSE;
}
/*
*�������ƣ�PreOrderTraverse
*������������������ָ�� T������ָ�� Visit
*����ֵ��status
*�������ܣ�ǰ�����������
*/
status PreOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1))
{
	if (T == NULL)
	{//���ýڵ�Ϊ�գ������ʾ��Ϣ
		printf("�ýڵ��ǿսڵ㣡\n\n");
		return FALSE;
	}
	Visit(T);//���ʸýڵ�
	PreOrderTraverse(T->lchild,Visit);//�ݹ������������
	PreOrderTraverse(T->rchild,Visit);//�ݹ������������
	return OK;
}
/*
*�������ƣ�InOrderTraverse
*������������������ָ�� T������ָ�� Visit
*����ֵ��status
*�������ܣ��������������
*/
status InOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1))
{
	if (T == NULL)
	{//���ýڵ�Ϊ�գ������ʾ��Ϣ
		printf("�ýڵ��ǿսڵ㣡\n\n");
		return FALSE;
	}
	InOrderTraverse(T->lchild, Visit);//�ݹ������������
	Visit(T);//���ʸýڵ�
	InOrderTraverse(T->rchild, Visit);//�ݹ������������
	return OK;
}
/*
*�������ƣ�PostOrderTraverse
*������������������ָ�� T������ָ�� Visit
*����ֵ��status
*�������ܣ��������������
*/
status PostOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1))
{
	if (T == NULL)
	{//���ýڵ�Ϊ�գ������ʾ��Ϣ
		printf("�ýڵ��ǿսڵ㣡\n\n");
		return FALSE;
	}
	PostOrderTraverse(T->lchild, Visit);//�ݹ������������
	PostOrderTraverse(T->rchild, Visit);//�ݹ������������
	Visit(T);//���ʸýڵ�
	return OK;
}
/*
*�������ƣ�LevelOrderTraverse
*������������������ָ�� T������ָ�� Visit
*����ֵ��status
*�������ܣ��������������
*/
status LevelOrderTraverse(BiTNode *T, status(*Visit)(BiTNode *T1))
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;
	//��������ģ����У���ͷ������
	while (p != NULL)
	{//�Ӳ�Ϊ��
		Visit(p->tnext);//���ʸýڵ�
		if (p->tnext->lchild != NULL)
		{//��ͷ�ڵ���������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//��ͷ�����Һ������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;//ָ�����
	}
	for (p = head;p != NULL;p = pnext)
	{//��ն���
		pnext = p->next;
		free(p);
	}
	return OK;
}
/*
*�������ƣ�Visit
*������������������ָ�� T
*����ֵ��status
*�������ܣ����ʽڵ�
*/
status Visit(BiTNode *T)
{
	if (T != NULL)
	{
		printf("�����ڱ����Ľڵ��ǣ�\n");
		printf("ѧ��������%s\n", T->data.name);
		printf("ѧ��ѧ�ţ�%s\n\n", T->data.id);
		return OK;
	}
	else
	{
		printf("�ýڵ�Ϊ�սڵ㣡\n");
		return FALSE;
	}
}
/*
*�������ƣ�check
*���������ͷ���ָ�� T
*����ֵ��status
*�������ܣ����������Ƿ��ʼ�����Ƿ񴴽�
*/
status check(HeadNode *T)
{
	if (T == NULL)
	{
		printf("��������δ��ʼ�����޷���ɲ�����\n");
		getchar(); getchar();
		return FALSE;
	}
	else if (T->bnext == NULL)
	{
		printf("��������δ�������޷���ɲ�����\n");
		getchar(); getchar();
		return FALSE;
	}
	else return TRUE;
}
/*
*�������ƣ�Parent
*������������������ָ�� T���ַ����� id
*����ֵ���������ڵ�ָ�� BiTNode *
*�������ܣ���ָ���ڵ��˫�׽ڵ�
*/
struct BiTNode *Parent(BiTNode *T, char id[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;
	//��������ģ����У���ͷ������
	while (p != NULL)
	{//�Ӳ�Ϊ��
		if (p->tnext->lchild != NULL)
		{//�ҵ�����Ҫ��Ľڵ㣬����ֵ
			if (strcmp(id, p->tnext->lchild->data.id) == 0
			&&p->tnext!=T)
			return p->tnext;
		}
		if (p->tnext->rchild != NULL)
		{//�ҵ�����Ҫ��Ľڵ㣬����ֵ
			if (strcmp(id, p->tnext->rchild->data.id) == 0
				&& p->tnext != T)
				return p->tnext;
		}
		if (p->tnext->lchild != NULL)
		{//��ͷ�ڵ���������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//��ͷ�����Һ������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;//ָ�����
	}
	printf("�ýڵ㲻�ڶ������ڻ���˫�׽ڵ�Ϊ���ڵ㣡���飡\n");//����������δ����ָ���ڵ㣬��ʾ������Ϣ
	for (p = head; p != NULL; p = pnext)
	{//��ն���
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*�������ƣ�LeftChild
*������������������ָ�� T���ַ����� id
*����ֵ���������ڵ�ָ�� BiTNode *
*�������ܣ���ָ���ڵ������
*/
struct BiTNode *LeftChild(BiTNode *T, char id[])
{
	ChainNode *head = (ChainNode *)malloc(sizeof(ChainNode));
	ChainNode *p = head;
	ChainNode *tail = head;
	ChainNode *pnext;
	head->next = NULL;
	head->tnext = T;
	//��������ģ����У���ͷ������
	while (p != NULL)
	{//�ҵ�����Ҫ��Ľڵ㣬����ֵ
		if (strcmp(p->tnext->data.id, id) == 0)
			if (p->tnext->lchild != NULL)
				return p->tnext->lchild;
		if (p->tnext->lchild != NULL)
		{//��ͷ�ڵ���������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//��ͷ�����Һ������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;//ָ�����
	}
	printf("�ýڵ㲻�ڶ������ڻ���û�����ӣ����飡\n");//����������δ����ָ���ڵ㣬��ʾ������Ϣ
	for (p = head; p != NULL; p = pnext)
	{//��ն���
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*�������ƣ�RightChild
*������������������ָ�� T���ַ����� id
*����ֵ���������ڵ�ָ�� BiTNode *
*�������ܣ���ָ���ڵ���Һ���
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
	printf("�ýڵ㲻�ڶ������ڻ���û���Һ��ӣ����飡\n");
	for (p = head; p != NULL; p = pnext)
	{
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*�������ƣ�LeftSibling
*������������������ָ�� T���ַ����� id
*����ֵ���������ڵ�ָ�� BiTNode *
*�������ܣ���ָ���ڵ�����ֵ�
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
	printf("�ýڵ㲻�ڶ������ڻ���û�����ֵܣ����飡\n");
	for (p = head; p != NULL; p = pnext)
	{
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*�������ƣ�RightSibling
*������������������ָ�� T���ַ����� id
*����ֵ���������ڵ�ָ�� BiTNode *
*�������ܣ���ָ���ڵ�����ֵ�
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
	printf("�ýڵ㲻�ڶ������ڻ���û�����ֵܣ����飡\n");
	for (p = head; p != NULL; p = pnext)
	{
		pnext = p->next;
		free(p);
	}
	return NULL;
}
/*
*�������ƣ�InsertChild
*������������������ָ�� T���ַ����� id���������� LR�����������ָ�� c
*����ֵ��status
*�������ܣ���������
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
	//��������ģ����У���ͷ������
	while (p != NULL)
	{//�Ӳ�Ϊ��
		if (strcmp(id, p->tnext->data.id) == 0)
		{//�ҵ�����Ҫ��Ľڵ㣬��T��¼��ֵ
			T = p->tnext;
			break;
		}
		if (p->tnext->lchild != NULL)
		{//��ͷ�ڵ���������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->lchild;
		}
		if (p->tnext->rchild != NULL)
		{//��ͷ�����Һ������
			tail->next = (ChainNode *)malloc(sizeof(ChainNode));
			tail = tail->next;
			tail->next = NULL;
			tail->tnext = p->tnext->rchild;
		}
		p = p->next;
	}

	for (p = head; p != NULL; p = pnext)
	{//��ն���
		pnext = p->next;
		free(p);
	}
	if (T == NULL)
	{//����������δ����ָ���ڵ㣬��ʾ������Ϣ
		printf("�ýڵ㲻�ڶ�������,���飡\n");
		return FALSE;
	}
	if(LR)
	{//��LRΪ1����c����T����������Tԭ�ȵ���������Ϊc��������
		if (c->rchild != NULL)
		{
			printf("c���������ǿգ�\n");
			return FALSE;
		}
		c->rchild = T->rchild;
		T->rchild = c;
		return OK;
	}
	else
	{//��LRΪ0����c����T����������Tԭ�ȵ���������Ϊc��������
		if (c->lchild != NULL)
		{
			printf("c���������ǿգ�\n");
			return FALSE;
		}
		c->rchild = T->lchild;
		T->lchild = c;
		return OK;
	}
}
/*
*�������ƣ�DeleteChild
*������������������ָ�� T���ַ����� id���������� LR
*����ֵ��status
*�������ܣ�ɾ������
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
		printf("�ýڵ���ܲ��ڶ������ڣ����飡\n");
		return FALSE;
	}
	if (LR)
		T->rchild = ClearBiTree(T->rchild);//��LRΪ1��ɾ��T��������
	else
		T->lchild = ClearBiTree(T->lchild);//��LRΪ0��ɾ��T��������
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
        printf("File open error��\n");
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
       printf("û���ҵ����ļ���\n");
       return ERROR;
    }
    fread((*T)->name,20,1,fp);
    Preorderread((&(*T)->bnext),fp);
    fclose(fp);
    return OK;
}

