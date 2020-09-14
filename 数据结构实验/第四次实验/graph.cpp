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
}VertexType;//����Ԫ��

typedef struct vr{
    int tail;
    int head;
}vr;

typedef struct ArcNode{
    int adjvex;//�û�ָ�򶥵��λ��
    struct ArcNode *nextarc;//ָ����һ������ָ��
}ArcNode;

typedef struct VNode{
    VertexType data;//������Ϣ
    ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;//���ͼ�еĽڵ�
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
    VertexType V[MAX_VERTEX_NUM];//�û�����ڵ�
    vr VR[MAX_PATH_NUM];//�û������ϵ
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
        printf("    ��ǰ�������Ǳ�%d\n",k+1);
	printf("    ��ѡ����Ĳ���[0~20]:");
	scanf("%d",&op);
    switch(op){
	case 1:
    {
        i = 0;
        printf("������ͼ�еĵ���Ϣ����Ĺؼ��� + �������\n���ؼ���Ϊ-1����Ϊ\"OVER\"ʱ����������룩\n");
        scanf("%d %s",&V[i].key,V[i].name);
        if(V[i].key!=-1||strcmp(V[i].name,"OVER")){
        for(i = 1;V[i-1].key!=-1||strcmp(V[i-1].name,"OVER");i++)
            scanf("%d %s",&V[i].key,V[i].name);
        }
        printf("������ͼ�е������ϵ������\"2 3\"����2->3��\n");
        i = 0;
        scanf("%d %d",&VR[i].tail,&VR[i].head);
        if(VR[i].head!=0||VR[i].tail!=0){
            for(i = 1;VR[i-1].head!=0||VR[i-1].tail!=0;i++)
               scanf("%d %d",&VR[i].tail,&VR[i].head);
        }
        if(CreateGraph(Graphs[Graph_NUM],V,VR)==1){
            printf("ͼ�����ɹ���\n");
            Graph_NUM++;
        }
        else
            printf("ͼ����ʧ�ܣ�\n");
		getchar(); getchar();
		break;
	}
	case 2:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ����ʧ�ܣ�\nͼ��δ���д�����\n");
        else{
            if(DestroyGraph(Graphs[k]))
                printf("ͼ���ٳɹ���\n");
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
            printf("ͼ��δ���д�����\n��ȡʧ�ܣ�\n");
        else{
            printf("������������ҵĽ��ؼ��֣�\n");
            scanf("%d",&m);
            i = LocateVex(Graphs[k],m);
            if(i == -1)
                printf("��ȡʧ��\nͼ��û���ҵ��˽�㣬����ؼ��֣�\n");
            else
                printf("��ȡ�ɹ���\n������ڽӱ��е�λ���������е�%d��\n",i+1);
        }
		getchar(); getchar();
		break;
	}
	case 4:
    {
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\n��ȡʧ�ܣ�\n");
        else{
            printf("������������ҵĽ��ؼ��֣�\n");
            scanf("%d",&m);
            i = GetVex(Graphs[k],m);
            if(i == -1)
                printf("����ʧ��\nͼ��û���ҵ��˽�㣬����ؼ��֣�\n");
            else
                printf("���ҳɹ���\n��������Ϊ%s\n",Graphs[k].vertices[i].data.name);
        }
		getchar(); getchar();
		break;
	}
	case 5:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\n��㸳ֵʧ�ܣ�\n");
        else{
            printf("���������븳ֵ�Ľ��ؼ��֣�\n");
            scanf("%d",&m);
            printf("���������븳ֵ�����ݣ�\n");
            scanf("%s",name);
            i = PutVex(Graphs[k],m,name);
            if(i == 0)
                printf("��ֵʧ�ܣ�\nͼ��û���ҵ��˽�㣬����ؼ��֣�\n");
            else
                printf("��㸳ֵ�ɹ���\n");
        }
		getchar(); getchar();
		break;
	}

	case 6:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\n����ʧ�ܣ�\n");
        else{
            printf("������������ҵ�һ�ڽӵ�Ľ��ؼ��֣�\n");
            scanf("%d",&m);
            i = FirstAdjVex(Graphs[k],m);
            if(i == -2)
                printf("����ʧ�ܣ�\nͼ��û���ҵ��˽�㣬����ؼ��֣�\n");
            if(i == -1)
                printf("����ʧ�ܣ�\n���%dû�е�һ�ڽӽ�㣡\n",m);
            else
                printf("���ҳɹ���\n���%d�ĵ�һ�ڽӽ��ؼ�����%d  ����Ϊ��%s\n",m,Graphs[k].vertices[i].data.key
                       ,Graphs[k].vertices[i].data.name);
        }
		getchar(); getchar();
		break;
	}
	case 7:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\n����ʧ�ܣ�\n");
        else{
            printf("������������ҵ���һ�ڽӵ�������Խ��Ĺؼ��֣�\n");
            scanf("%d %d",&m,&n);
            i = NextAdjVex(Graphs[k],m,n);
            if(i == -2)
                printf("����ʧ�ܣ�\nͼ�н����Ϣ��ƥ�䣬����ؼ��֣�\n");
            if(i == -1)
                printf("����ʧ�ܣ�\n���%dû����Խ��%d��һ�ڽӽ�㣡\n",m,n);
            else
                printf("���ҳɹ���\n���%d��Ի����%d�ڽӽ��Ĺؼ�����%d����Ϊ��%s\n",m,n,Graphs[k].vertices[i].data.key,
                       Graphs[k].vertices[i].data.name);
        }
		getchar(); getchar();
		break;
	}
	case 8:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\n����ʧ�ܣ�\n");
        else{
            printf("�������������ĵ�Ĺؼ��ֺ����֣�\n");
            scanf("%d %s",&new_node.key,new_node.name);
            i = InserVex(Graphs[k],new_node);
            if(i == 1)
                printf("����ɹ���\n");
            else
                printf("����ʧ�ܣ�\n");
        }
		getchar();getchar();
		break;
	}
	case 9:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\nɾ��ʧ�ܣ�\n");
        else{
            printf("����������ɾ���ĵ�Ĺؼ��֣�\n");
            scanf("%d",&new_node.key);
            i = DelectVex(Graphs[k],new_node.key);
            if(i == 1)
                printf("ɾ���ɹ���\n");
            else
                printf("ɾ��ʧ�ܣ�\n��㲻��ͼ��!\n");
        }
		getchar();getchar();
		break;
	}
	case 10:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\n����ʧ�ܣ�\n");
        else{
            printf("�������������Ļ��Ļ�β�ͻ�ͷ��\n");
            scanf("%d %d",&m,&n);
            i = InsertArc(Graphs[k],m,n);
            if(i == 1)
                printf("����ɹ���\n");
            if(i == -1)
               printf("����ʧ�ܣ�\n�û��Ѵ��ڣ�\n");
            if(i == 0)
                printf("����ʧ�ܣ�\n�����Ϣƥ������!\n");
        }
		getchar(); getchar();
		break;
	}
	case 11:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\nɾ��ʧ�ܣ�\n");
        else{
            printf("����������ɾ���Ļ��Ļ�β�ͻ�ͷ��\n");
            scanf("%d %d",&m,&n);
            i = DelectArc(Graphs[k],m,n);
            if(i == 1)
                printf("ɾ���ɹ���\n");
            else
                printf("ɾ��ʧ�ܣ�\n�����Ϣƥ������\n");
        }
		getchar(); getchar();
		break;
	}
	case 12:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\n��ȱ���ʧ�ܣ�\n");
        else
            if(BFSTraverse(Graphs[k]))
                printf("��ȱ����ɹ���\n");
		getchar(); getchar();
		break;
	}
	case 13:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\n��ȱ���ʧ�ܣ�\n");
        else
            if(DFSTraverse(Graphs[k]))
                printf("��ȱ����ɹ���\n");
		getchar(); getchar();
		break;
	}
    case 14:
	{
        if(k > (Graph_NUM-1))
            printf("ͼ��δ���д�����\nͼ������ʾʧ�ܣ�\n");
        else{
                printf("ͼ�еĵ��У�\n");
                for(i = 0;i < Graphs[k].vexnum;i++){
                    m = 0;
                    printf("�ؼ��ʣ�%d  ���֣�%s\n",Graphs[k].vertices[i].data.key,Graphs[k].vertices[i].data.name);
                    printf("��ָ�����¹ؼ��ֵĵ�������ϵ��\n");
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
            printf("ͼ��δ���д�����\n����ʧ�ܣ�\n");
        else
            SaveGraph(Graphs[k]);
		getchar(); getchar();
		break;
	}
	case 16:
	{
	    if(Graphs[k].vexnum != 0)
            printf("����ʧ��!\n��ǰͼ��Ϊ�գ����������ټ��أ�\n");
        else{
            LoadGraph(Graphs[k]);
            Graph_NUM++;
        }
        getchar(); getchar();
		break;
	}
	case 17:
	{
         printf("����������Ҫ�����ڼ���ͼ��\n");
         scanf("%d",&i);
         if(i > Graph_NUM)
            printf("��ͼ��δ������\n");
         else
            k = i-1;
		getchar(); getchar();
		break;
	}
	case 18:
	{
        printf("�����ѽ�����%d��ͼ��",Graph_NUM);
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



/*����ͼ
  ��ʼ���������㼯����ϵ��
  �������������*/
status CreateGraph(ALGraph &G,VertexType V[],vr VR[])
{
    int i,j,k,vexnum,arcum;
    ArcNode *new_arc;
    //�ڵ�
    for(i = 0;strcmp(V[i].name,"OVER") != 0||V[i].key!=-1;i++){
        G.vertices[i].data.key = V[i].key;
        strcpy(G.vertices[i].data.name,V[i].name);
        G.vertices[i].firstarc = NULL;
    }
    G.vexnum = i;
    //��ϵ���ڽӱ�
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

//���ض����������е����
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
               return FALSE;//�������ڽӽڵ�
        }
    }
    return -2;//û��v����ڵ�
}

//�����ڽӶ�������
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
        return FALSE;//�޸û�
    }
    return ERROR;//�㲻��ͼ��
}


status visit(VNode v)
{
    printf("����ؼ��֣�%d\n",v.data.key);
    printf("�������֣�%s\n\n",v.data.name);
    return OK;
}

status BFSTraverse(ALGraph G)
{
    int i,j = 1,m,k;
    ArcNode *p;
    //�õ������ж��Ƿ񱻷��ʹ�
    for(i = 0;i < G.vexnum;i++)
        Visit[i] = 0;
    int Queue[G.vexnum];//���������
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
        //��ǰ�ڵ��г��ȣ�һ������������
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
    printf("����������Ҫ������ļ�����\n");
    scanf("%s",filename);
    if((fp = fopen(filename,"wb")) == NULL){
        printf("File open error\n");
        getchar();
        return ERROR;
    }
    //����
    fwrite(&G.vexnum,sizeof(int),1,fp);
    fwrite(&G.arcum,sizeof(int),1,fp);
    for(i = 0;i < G.vexnum;i++){
        fwrite(&G.vertices[i].data,sizeof(VertexType),1,fp);
    }
    //����
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
    printf("ͼ����ɹ���");
    return OK;
}

status LoadGraph(ALGraph &G)
{
    FILE *fp;
    int i,node_number,arc_number;
    char filename[20];
    VertexType V[MAX_VERTEX_NUM];
    vr VR[MAX_PATH_NUM];
    printf("�������ļ���:\n");
    scanf("%s",filename);
    if((fp = fopen(filename,"rb")) == NULL){
        printf("û���ҵ����ļ���\n");
        return ERROR;
    }
    fread(&node_number,sizeof(int),1,fp);
    fread(&arc_number,sizeof(int),1,fp);
    G.vexnum = node_number;
    G.arcum = arc_number;
    //�����
    for(i = 0;i < node_number;i++){
        fread(&V[i],sizeof(VertexType),1,fp);
    }
    V[i].key = -1;
    strcpy(V[i].name,"OVER");
    //����
    for(i = 0;i < arc_number;i++){
        fread(&VR[i],sizeof(vr),1,fp);
    }
    VR[i].head = VR[i].tail = 0;
    if(CreateGraph(G,V,VR))
        printf("ͼ���سɹ���\n");
    fclose(fp);
    return OK;


}




