//orient graph

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR 0
#define OVERFLOW -3
#define MAX_VERTEX_NUM 100
#define MAX_GRAPH_NUM 10
#define MAX_PATH_NUM  50

int Visit[MAX_VERTEX_NUM];
typedef int status;

typedef struct VertexType{
    int key;
    char name[20];
}VertexType;//数据元素

typedef struct vr{
    int tail;
    int head;
}vr;

typedef struct ArcNode{
    int adjvex;//该弧指向顶点的位置
    struct ArcNode *nextarc;//指向下一条弧的指针
}ArcNode;

typedef struct VNode{
    VertexType data;//顶点信息
    ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;//存放图中的节点
    int vexnum,arcum;
}ALGraph;

status CreateGraph(ALGraph &G,VertexType V[],vr VR[]);
status DestroyGraph(ALGraph &G);
status LocateVex(ALGraph G,int u);
status GetVex(ALGraph G,int v);
status PutVex(ALGraph &G,int v,char *new_name);
status FirstAdjVex(ALGraph G,int v);
status NextAdjVex(ALGraph G,int v,int w);
status InserVex(ALGraph &G,VertexType v);
status DelectVex(ALGraph &G,int v);
status InsertArc(ALGraph &G,int v,int w);
status DelectArc(ALGraph &G,int v,int w);
status BFSTraverse(ALGraph G);
status visit(VNode v);
status BFSTraverse(ALGraph G);
void DFS(ALGraph G,int i);
status DFSTraverse(ALGraph G);
status SaveGraph(ALGraph G);
status LoadGraph(ALGraph &G);

int main()
{
    int op = 1,k = 0,i = 0,m = 0,n,Graph_NUM = 0;
    VertexType V[MAX_VERTEX_NUM];//用户输入节点
    vr VR[MAX_PATH_NUM];//用户输入关系
    ALGraph Graphs[MAX_GRAPH_NUM];
    VertexType new_node;
    ArcNode *p;
    char name[20];
    while(op){
	system("cls");
	printf("\n\n");
	printf("-------------------------------------------------\n");
	printf("              Menu for oriented graph \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. CreateGraph       10.InsertArc\n");
	printf("    	  2. DestroyGraph      11.DelectArc\n");
	printf("    	  3. LocateVex         12.BFSTraverse\n");
	printf("    	  4. GetVex            13.DFSTraverse\n");
	printf("    	  5. PutVex            14.ShowGraph\n");
	printf("    	  6. FirstAdjVex       15.SaveGraph\n");
	printf("          7. NextAdjVex        16.LoadGraph\n");
    printf("    	  8. InsertVex         17.Change\n");
    printf("    	  9. DelectVex         18.Showtotal\n");
    printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
	if(Graph_NUM!=0)
        printf("    当前操作的是表%d\n",k+1);
	printf("    请选择你的操作[0~20]:");
	scanf("%d",&op);
    switch(op){
	case 1:
    {
        i = 0;
        printf("请输入图中的点信息：点的关键字 + 点的名字\n（关键字为-1，名为\"OVER\"时代表结束输入）\n");
        scanf("%d %s",&V[i].key,V[i].name);
        if(V[i].key!=-1||strcmp(V[i].name,"OVER")){
        for(i = 1;V[i-1].key!=-1||strcmp(V[i-1].name,"OVER");i++)
            scanf("%d %s",&V[i].key,V[i].name);
        }
        printf("请输入图中的有向关系：（例\"2 3\"代表2->3）\n");
        i = 0;
        scanf("%d %d",&VR[i].tail,&VR[i].head);
        if(VR[i].head!=0||VR[i].tail!=0){
            for(i = 1;VR[i-1].head!=0||VR[i-1].tail!=0;i++)
               scanf("%d %d",&VR[i].tail,&VR[i].head);
        }
        if(CreateGraph(Graphs[Graph_NUM],V,VR)==1){
            printf("图创建成功！\n");
            Graph_NUM++;
        }
        else
            printf("图创建失败！\n");
		getchar(); getchar();
		break;
	}
	case 2:
	{
        if(k > (Graph_NUM-1))
            printf("图销毁失败！\n图还未进行创建！\n");
        else{
            if(DestroyGraph(Graphs[k]))
                printf("图销毁成功！\n");
            m = k;
            for(i = k+1;i < Graph_NUM;i++){
                Graphs[m] = Graphs[i];
                m++;
                i++;
            }
            Graph_NUM--;
        }
		getchar(); getchar();
		break;
	}
	case 3:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n获取失败！\n");
        else{
            printf("请输入你想查找的结点关键字：\n");
            scanf("%d",&m);
            i = LocateVex(Graphs[k],m);
            if(i == -1)
                printf("获取失败\n图中没有找到此结点，请检查关键字！\n");
            else
                printf("获取成功！\n结点在邻接表中的位置是数组中第%d个\n",i+1);
        }
		getchar(); getchar();
		break;
	}
	case 4:
    {
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n获取失败！\n");
        else{
            printf("请输入你想查找的结点关键字：\n");
            scanf("%d",&m);
            i = GetVex(Graphs[k],m);
            if(i == -1)
                printf("查找失败\n图中没有找到此结点，请检查关键字！\n");
            else
                printf("查找成功！\n结点的名字为%s\n",Graphs[k].vertices[i].data.name);
        }
		getchar(); getchar();
		break;
	}
	case 5:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n结点赋值失败！\n");
        else{
            printf("请输入你想赋值的结点关键字：\n");
            scanf("%d",&m);
            printf("请输入你想赋值的内容：\n");
            scanf("%s",name);
            i = PutVex(Graphs[k],m,name);
            if(i == 0)
                printf("赋值失败！\n图中没有找到此结点，请检查关键字！\n");
            else
                printf("结点赋值成功！\n");
        }
		getchar(); getchar();
		break;
	}

	case 6:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n查找失败！\n");
        else{
            printf("请输入你想查找第一邻接点的结点关键字：\n");
            scanf("%d",&m);
            i = FirstAdjVex(Graphs[k],m);
            if(i == -2)
                printf("查找失败！\n图中没有找到此结点，请检查关键字！\n");
            if(i == -1)
                printf("查找失败！\n结点%d没有第一邻接结点！\n",m);
            else
                printf("查找成功！\n结点%d的第一邻接结点关键字是%d  名字为：%s\n",m,Graphs[k].vertices[i].data.key
                       ,Graphs[k].vertices[i].data.name);
        }
		getchar(); getchar();
		break;
	}
	case 7:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n查找失败！\n");
        else{
            printf("请输入你想查找的下一邻接点结点与相对结点的关键字：\n");
            scanf("%d %d",&m,&n);
            i = NextAdjVex(Graphs[k],m,n);
            if(i == -2)
                printf("查找失败！\n图中结点信息不匹配，请检查关键字！\n");
            if(i == -1)
                printf("查找失败！\n结点%d没有相对结点%d下一邻接结点！\n",m,n);
            else
                printf("查找成功！\n结点%d相对机结点%d邻接结点的关键字是%d名字为：%s\n",m,n,Graphs[k].vertices[i].data.key,
                       Graphs[k].vertices[i].data.name);
        }
		getchar(); getchar();
		break;
	}
	case 8:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n插入失败！\n");
        else{
            printf("请输入你想插入的点的关键字和名字：\n");
            scanf("%d %s",&new_node.key,new_node.name);
            i = InserVex(Graphs[k],new_node);
            if(i == 1)
                printf("插入成功！\n");
            else
                printf("插入失败！\n");
        }
		getchar();getchar();
		break;
	}
	case 9:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n删除失败！\n");
        else{
            printf("请输入你想删除的点的关键字：\n");
            scanf("%d",&new_node.key);
            i = DelectVex(Graphs[k],new_node.key);
            if(i == 1)
                printf("删除成功！\n");
            else
                printf("删除失败！\n结点不在图中!\n");
        }
		getchar();getchar();
		break;
	}
	case 10:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n插入失败！\n");
        else{
            printf("请输入你想插入的弧的弧尾和弧头：\n");
            scanf("%d %d",&m,&n);
            i = InsertArc(Graphs[k],m,n);
            if(i == 1)
                printf("插入成功！\n");
            if(i == -1)
               printf("插入失败！\n该弧已存在！\n");
            if(i == 0)
                printf("插入失败！\n结点信息匹配有误!\n");
        }
		getchar(); getchar();
		break;
	}
	case 11:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n删除失败！\n");
        else{
            printf("请输入你想删除的弧的弧尾和弧头：\n");
            scanf("%d %d",&m,&n);
            i = DelectArc(Graphs[k],m,n);
            if(i == 1)
                printf("删除成功！\n");
            else
                printf("删除失败！\n结点信息匹配有误！\n");
        }
		getchar(); getchar();
		break;
	}
	case 12:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n广度遍历失败！\n");
        else
            if(BFSTraverse(Graphs[k]))
                printf("广度遍历成功！\n");
		getchar(); getchar();
		break;
	}
	case 13:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n深度遍历失败！\n");
        else
            if(DFSTraverse(Graphs[k]))
                printf("深度遍历成功！\n");
		getchar(); getchar();
		break;
	}
    case 14:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n图数据显示失败！\n");
        else{
                printf("图中的点有：\n");
                for(i = 0;i < Graphs[k].vexnum;i++){
                    m = 0;
                    printf("关键词：%d  名字：%s\n",Graphs[k].vertices[i].data.key,Graphs[k].vertices[i].data.name);
                    printf("有指向以下关键字的点的有向关系：\n");
                    p = Graphs[k].vertices[i].firstarc;
                    while(p){
                        printf("%d ",Graphs[k].vertices[p->adjvex].data.key);
                        p = p->nextarc;
                        m++;
                    }
                    if(m == 0)
                        printf("NULL");
                    printf("\n\n");
                }

        }
		getchar(); getchar();
		break;
	}
	case 15:
	{
        if(k > (Graph_NUM-1))
            printf("图还未进行创建！\n保存失败！\n");
        else
            SaveGraph(Graphs[k]);
		getchar(); getchar();
		break;
	}
	case 16:
	{
	    if(Graphs[k].vexnum != 0)
            printf("加载失败!\n当前图不为空，请先销毁再加载！\n");
        else{
            LoadGraph(Graphs[k]);
            Graph_NUM++;
        }
        getchar(); getchar();
		break;
	}
	case 17:
	{
         printf("请输入您想要操作第几个图：\n");
         scanf("%d",&i);
         if(i > Graph_NUM)
            printf("该图还未建立！\n");
         else
            k = i-1;
		getchar(); getchar();
		break;
	}
	case 18:
	{
        printf("现在已建立了%d个图！",Graph_NUM);
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



/*创建图
  初始条件：顶点集、关系集
  结果：生成有向*/
status CreateGraph(ALGraph &G,VertexType V[],vr VR[])
{
    int i,j,k,vexnum,arcum;
    ArcNode *new_arc;
    //节点
    for(i = 0;strcmp(V[i].name,"OVER") != 0||V[i].key!=-1;i++){
        G.vertices[i].data.key = V[i].key;
        strcpy(G.vertices[i].data.name,V[i].name);
        G.vertices[i].firstarc = NULL;
    }
    G.vexnum = i;
    //关系成邻接表
    for(i = 0;VR[i].head != 0||VR[i].tail != 0;i++){
        for(j = 0;j < G.vexnum&&G.vertices[j].data.key != VR[i].tail;j++ );
        for(k = 0;k < G.vexnum&&G.vertices[k].data.key !=VR[i].head;k++);
        if(j < G.vexnum&&k < G.vexnum){
                   new_arc = (ArcNode *)malloc(sizeof(ArcNode));
                   if(!new_arc) exit(OVERFLOW);
                   new_arc->adjvex = k;
                   new_arc->nextarc = G.vertices[j].firstarc;
                   G.vertices[j].firstarc = new_arc;
              }
            }
    G.arcum = i;
    return OK;
}

status DestroyGraph(ALGraph &G)
{
    int i,j;
    ArcNode *p;
    ArcNode *q;
    for(i = 0;i < G.vexnum;i++){
            p = G.vertices[i].firstarc;
            while(p != NULL){
                q = p->nextarc;
                free(p);
                p = q;
            }
    }
    G.arcum = G.vexnum = 0;
    return OK;
}

status LocateVex(ALGraph G,int u)
{

    int i;
    for(i = 0;i < G.vexnum;i++){
        if(G.vertices[i].data.key == u)
           return i;
    }
    return FALSE;

}

//返回顶点在数组中的序号
status GetVex(ALGraph G,int v)
{
    int i;
    for(i = 0;i < G.vexnum;i++){
        if(G.vertices[i].data.key == v)
            return i;
    }
    return FALSE;
}


status PutVex(ALGraph &G,int v,char *new_name)
{
    int i;
    for(i = 0;i < G.vexnum;i++){
            if(G.vertices[i].data.key == v){
               strcpy(G.vertices[i].data.name,new_name);
               return OK;
            }
    }
    return ERROR;
}

status FirstAdjVex(ALGraph G,int v)
{
    int i;
    for(i = 0;i < G.vexnum;i++){
        if(G.vertices[i].data.key == v){
            if(G.vertices[i].firstarc!=NULL)
               return G.vertices[i].firstarc->adjvex;
            else
               return FALSE;//不存在邻接节点
        }
    }
    return -2;//没有v这个节点
}

//返回邻接顶点的序号
status NextAdjVex(ALGraph G,int v,int w)
{
    int i,j;
    ArcNode *p;
    for(i = 0;i < G.vexnum&&G.vertices[i].data.key!=v;i++);
    for(j = 0;j < G.vexnum&&G.vertices[j].data.key!=w;j++);
    if(i < G.vexnum && j < G.vexnum){
        for(p = G.vertices[i].firstarc;p!=NULL;p = p->nextarc)
            if(p->adjvex == j&&p->nextarc != NULL)
                  return p->nextarc->adjvex;
    return FALSE;
    }
    return -2;
}

status InserVex(ALGraph &G,VertexType v)
{
    int m;
    if(G.vexnum <= MAX_VERTEX_NUM){
        m = G.vexnum;
        G.vertices[m].data = v;
        G.vertices[m].firstarc = NULL;
        G.vexnum++;
        return OK;
    }
    else
        return FALSE;
}

status DelectVex(ALGraph &G,int v)
{
    int i,j;
    ArcNode *p;
    ArcNode *q;
    for(i = 0;i < G.vexnum;i++){
        if(G.vertices[i].data.key == v){
           p = G.vertices[i].firstarc;
           while(p!=NULL){
                q = p->nextarc;
                free(p);
                p = q;
                G.arcum--;
           }
           j = i+1;
           while(j < G.vexnum){
             G.vertices[i] = G.vertices[j];
             j++;
             i++;
        }
        G.vexnum--;
        return OK;
        }
    }
    return ERROR;
}

status InsertArc(ALGraph &G,int v,int w)
{
    int i,j;
    ArcNode *p;
    ArcNode *new_arc;
    for(i = 0;i < G.vexnum&&G.vertices[i].data.key!=v;i++);
    for(j = 0;j < G.vexnum&&G.vertices[j].data.key!=w;j++);
    if(i < G.vexnum&&j < G.vexnum){
        p = G.vertices[i].firstarc;
        while(p){
            if(p->adjvex == j)
                return FALSE;
            p = p->nextarc;
        }
        new_arc = (ArcNode *)malloc(sizeof(ArcNode));
        new_arc->adjvex = j;
        new_arc->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = new_arc;
        G.arcum++;
        return OK;
    }
    return ERROR;
}

status DelectArc(ALGraph &G,int v,int w)
{
    int i,j;
    ArcNode *p;
    ArcNode *q;
    for(i = 0;i < G.vexnum&&G.vertices[i].data.key!=v;i++);
    for(j = 0;j < G.vexnum&&G.vertices[j].data.key!=w;j++);
    if(i < G.vexnum&&j < G.vexnum ){
        p = G.vertices[i].firstarc;
        if(p == NULL)
            return FALSE;
        if(p->adjvex == j){
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
            free(p);
            G.arcum--;
            return OK;
        }
        q = p;
        p = p->nextarc;
        while(p!=NULL){
                if(p->adjvex == j){
                    q->nextarc = p->nextarc;
                    free(p);
                    G.arcum--;
                    return OK;
                }
                q = p;
                p = p->nextarc;
        }
        return FALSE;//无该弧
    }
    return ERROR;//点不在图中
}


status visit(VNode v)
{
    printf("顶点关键字：%d\n",v.data.key);
    printf("顶点名字：%s\n\n",v.data.name);
    return OK;
}

status BFSTraverse(ALGraph G)
{
    int i,j = 1,m,k;
    ArcNode *p;
    //用点的序号判断是否被访问过
    for(i = 0;i < G.vexnum;i++)
        Visit[i] = 0;
    int Queue[G.vexnum];//点的序号入队
    Queue[0] = 0;
    Visit[0] = 1;
    for(i = 0;i < G.vexnum;i++){
        if(G.vertices[Queue[i]].firstarc == NULL){
            for(k = 0;k < G.vexnum&&Visit[k] != 0;k++);
            if(k == G.vexnum)
               i = G.vexnum;
            else{
                Queue[j] = k;
                j++;
            }
        }
        //当前节点有出度，一个个加入序列
        else{
        p = G.vertices[Queue[i]].firstarc;
        while(p!=NULL){
            if(Visit[p->adjvex] == 0){
                Queue[j] = p->adjvex;
                j++;
                Visit[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
        }
    }
    for(i = 0;i < G.vexnum;i++)
        visit(G.vertices[Queue[i]]);
    return OK;
}

void DFS(ALGraph G,int i)
{
    int w;
    Visit[i] = 1;
    visit(G.vertices[i]);
    for(w = FirstAdjVex(G,G.vertices[i].data.key);w >= 0; w = NextAdjVex(G,G.vertices[i].data.key,G.vertices[w].data.key))
        if(!Visit[w]) DFS(G,w);
}
status DFSTraverse(ALGraph G)
{
    int i;
    for(i = 0;i < G.vexnum;i++)  Visit[i] = 0;
    for(i = 0;i < G.vexnum;i++)
       if(!Visit[i])  DFS(G,i);
    return OK;

}
status SaveGraph(ALGraph G)
{
    FILE *fp;
    int i;
    char filename[20];
    vr new_vr;
    ArcNode *p;
    printf("请输入你想要保存的文件名：\n");
    scanf("%s",filename);
    if((fp = fopen(filename,"wb")) == NULL){
        printf("File open error\n");
        getchar();
        return ERROR;
    }
    //读点
    fwrite(&G.vexnum,sizeof(int),1,fp);
    fwrite(&G.arcum,sizeof(int),1,fp);
    for(i = 0;i < G.vexnum;i++){
        fwrite(&G.vertices[i].data,sizeof(VertexType),1,fp);
    }
    //读弧
    for(i = 0;i < G.vexnum;i++){
        p = G.vertices[i].firstarc;
        while(p){
            new_vr.tail = G.vertices[i].data.key;
            new_vr.head = G.vertices[p->adjvex].data.key;
            fwrite(&new_vr,sizeof(vr),1,fp);
            p = p->nextarc;
        }
    }
    fclose(fp);
    printf("图保存成功！");
    return OK;
}

status LoadGraph(ALGraph &G)
{
    FILE *fp;
    int i,node_number,arc_number;
    char filename[20];
    VertexType V[MAX_VERTEX_NUM];
    vr VR[MAX_PATH_NUM];
    printf("请输入文件名:\n");
    scanf("%s",filename);
    if((fp = fopen(filename,"rb")) == NULL){
        printf("没有找到该文件！\n");
        return ERROR;
    }
    fread(&node_number,sizeof(int),1,fp);
    fread(&arc_number,sizeof(int),1,fp);
    G.vexnum = node_number;
    G.arcum = arc_number;
    //处理点
    for(i = 0;i < node_number;i++){
        fread(&V[i],sizeof(VertexType),1,fp);
    }
    V[i].key = -1;
    strcpy(V[i].name,"OVER");
    //处理弧
    for(i = 0;i < arc_number;i++){
        fread(&VR[i],sizeof(vr),1,fp);
    }
    VR[i].head = VR[i].tail = 0;
    if(CreateGraph(G,V,VR))
        printf("图加载成功！\n");
    fclose(fp);
    return OK;


}




