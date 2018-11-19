#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
typedef int VertexType;
typedef int I_ten[10];
#define V_Type %d
#define VISITED 1
#define NOT_VISITED 0
#define MAXX 99999
const char * g_input = "g_input.txt";
/*
 *  
 *  数据结构 图的存储结构以及相关的操作
 *
 *
 */
//---------邻接矩阵

typedef struct{
    int Vex[MAXNUM];
    int Edge[MAXNUM][MAXNUM];
    int vexnum,edgenum;
}MGraph;

// ---------------------------

FILE * fin;
// ----邻接表------ 
typedef struct ArcNode{
    int adjvex; //vertices index
    int info; //  权值
    struct ArcNode * next;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode * first;
}VNode,AdjList[MAXNUM];

typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
// ----------------------------------------

typedef struct Queue{
    int data[MAXNUM];
    int front;
    int rear;
}Q;
    void init(Q **queue){
        (*queue)->front = 0;
        (*queue)->rear = 0;
    }

    void EnQueue(Q **queue,int _data){
        (*queue)->data[((*queue)->rear)++] = _data;
    }
    int DeQueue(Q **queue){
        //int f = queue->front;
        //printf("%d,%d\n",queue->front,queue->data[f]);
        //printf("->%d\n",queue->data[queue->front]);
        
        return (*queue)->data[(*queue)->front++];
    }
    int isEmpty(Q *queue){
        return queue->front-queue->rear;
    }

// 打印邻接表的结构
void printAlg(ALGraph * algraph){
    int i=0;
    printf("---------------邻接表的结构-----------------\n");
    printf("顶点 ---(权)--->adjvex-----(权)----->adjvex\n");
    for(i=0;i<algraph->vexnum;i++){
        printf("%d: %d ",i,algraph->vertices[i].data);
        ArcNode * p = algraph->vertices[i].first;
        while(p!=NULL){
            printf("---(权：%d)--->%d(%d)",p->info,p->adjvex,algraph->vertices[p->adjvex].data
                   );
            p = p->next;
        }
        printf("\n");
    }
    printf("----------------------------------------------\n");
}

void printArrary(int arr[],int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d ",arr[i] );
    }
    printf("\n");
}

void printDouArrary(int arr[100][100],int n,int m){
    int i=0;
    int j = 0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%7d",arr[i][j] );
        }
        printf("\n");
    }
    printf("\n");
}

void print(ALGraph * g){
    int i =0;
    for(i=0;i<g->vexnum;i++){
        printf("%4d",g->vertices[i].data);
    }
}

void printM(MGraph * mgraph){
    int i,j;

    printf(" V |");
    for(i=0;i<mgraph->vexnum;i++){
        printf(" v%d  |",i);
    }
    printf("\n");
    for(i=0;i<mgraph->vexnum;i++){
        printf("v%d |",i);
        for(j=0;j<mgraph->vexnum;j++){
            printf("%5d|",mgraph->Edge[i][j]);
        }
        printf("\n----");
        for(j=0;j<mgraph->vexnum;j++){
            printf("------");
        }
        printf("\n");
    }
}

// 旧的写法，尽量不要使用了
ALGraph * create_graph(){
    //int vexnum;
    ALGraph * algraph = (ALGraph*)malloc(sizeof(ALGraph));
    int i=0;
    printf("input vexnum and arcnum:");
    fscanf(fin,"%d%d",&algraph->vexnum,&algraph->arcnum);
    printf("---->%d %d\n",algraph->vexnum,algraph->arcnum);
    // printf("---->input all vex's data\n");
    //初始化定点表
    for(i=0;i<algraph->vexnum;i++){
        //printf("input vex%d\'s data:",i);
        fscanf(fin,"%d",&algraph->vertices[i].data);
        algraph->vertices[i].first = (ArcNode*)malloc(sizeof(ArcNode));
        algraph->vertices[i].first = NULL;
    }
    // 初始化边表
    printf("----> input arc\n");
    for(i=0;i<algraph->vexnum;i++){
        int arcnum = 0;
        int j=0;
        ArcNode * p = (ArcNode*)malloc(sizeof(ArcNode));
        p = algraph->vertices[i].first; 
        fscanf(fin,"%d",&arcnum);         
        for(j=0;j<arcnum;j++){
           ArcNode * newnode = (ArcNode*)malloc(sizeof(ArcNode));
           newnode->next = NULL;
            //printf("int arcnode data:\n");
            // 此处输入的顶点的编号，数组下表为0 ，编号为1，注意区别
            int num=0;    
            fscanf(fin,"%d",&num);
            //printf("v%d connect-->v%d\t",i+1,num);
            newnode->adjvex = num;
            if(p==NULL){
                algraph->vertices[i].first = newnode;
                p = algraph->vertices[i].first;
            } else {
                p->next = newnode;
                p = newnode;
            } 
        }
        printf("\n");
    }
    return  algraph;
}

// 创建有向图
ALGraph * createDAG(){
    ALGraph * algraph = (ALGraph*)malloc(sizeof(ALGraph));
    int i=0;
    printf("input vexnum and arcnum:");
    fscanf(fin,"%d%d",&algraph->vexnum,&algraph->arcnum);
    printf("---->%d %d\n",algraph->vexnum,algraph->arcnum);
    // printf("---->input all vex's data\n");
    //初始化定点表
    for(i=0;i<algraph->vexnum;i++){
        //printf("input vex%d\'s data:",i);
        fscanf(fin,"%d",&algraph->vertices[i].data);
        algraph->vertices[i].first = (ArcNode*)malloc(sizeof(ArcNode));
        algraph->vertices[i].first = NULL;
    }
    int v1,v2,info;
    for(i=0;i<algraph->arcnum;i++){
        fscanf(fin,"%d %d %d\n",&v1,&v2,&info);
        ArcNode * p = (ArcNode*)malloc(sizeof(ArcNode));
        ArcNode * t = (ArcNode*)malloc(sizeof(ArcNode));
        p->next = NULL;
        t->next = NULL;
        if(algraph->vertices[v1].first == NULL){
            //ArcNode * p = (ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex = v2;
            p->info = info;
            algraph->vertices[v1].first = p; 
        } else {
            p = algraph->vertices[v1].first;
            while(p->next!=NULL)
                p = p->next;
            t->adjvex = v2;
            t->info = info;
            p->next = t;
        }    
        p = (ArcNode*)malloc(sizeof(ArcNode));
        t = (ArcNode*)malloc(sizeof(ArcNode));
        p->next = NULL;
        t->next = NULL;
          
    }
    return algraph;
}



// 按照边创建邻接表
// 无向图
ALGraph * createAlgByArc(){
    ALGraph * algraph = (ALGraph*)malloc(sizeof(ALGraph));
    int i=0;
    printf("input vexnum and arcnum:");
    fscanf(fin,"%d %d",&algraph->vexnum,&algraph->arcnum);
    printf("---->%d %d\n",algraph->vexnum,algraph->arcnum);
    // printf("---->input all vex's data\n");
    //初始化定点表
    for(i=0;i<algraph->vexnum;i++){
        //printf("input vex%d\'s data:",i);
        int data;
        fscanf(fin,"%d",&data);
        //printf("%d ",data);
        algraph->vertices[i].data = data;
        algraph->vertices[i].first = (ArcNode*)malloc(sizeof(ArcNode));
        algraph->vertices[i].first = NULL;
    }
    printf("\n");
    int v1,v2,info;
    for(i=0;i<algraph->arcnum;i++){
        fscanf(fin,"%d %d %d\n",&v1,&v2,&info);
       // printf("%d %d %d\n",v1,v2,info);
        ArcNode * p = (ArcNode*)malloc(sizeof(ArcNode));
        ArcNode * t = (ArcNode*)malloc(sizeof(ArcNode));
        p->next = NULL;
        t->next = NULL;
        if(algraph->vertices[v1].first == NULL){
            //ArcNode * p = (ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex = v2;
            p->info = info;
            algraph->vertices[v1].first = p; 
        } else {
            p = algraph->vertices[v1].first;
            while(p->next!=NULL)
                p = p->next;
            t->adjvex = v2;
            t->info = info;
            p->next = t;
        }    
        p = (ArcNode*)malloc(sizeof(ArcNode));
        t = (ArcNode*)malloc(sizeof(ArcNode));
        p->next = NULL;
        t->next = NULL;
        if(algraph->vertices[v2].first == NULL) {
            //ArcNode * p = (ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex = v1;
            p->info = info;
            algraph->vertices[v2].first = p; 
        } else {
            p = algraph->vertices[v2].first;
            while(p->next!=NULL)
                p = p->next;
            t->adjvex = v1;
            t->info = info;
            p->next = t;
        }
        //printAlg(algraph);    
          
    }
    return algraph;
}


// 创建邻接举矩阵 带权 有向图
MGraph * create(){
    FILE * fin = fopen("mgraph.txt","r");
    MGraph * mgraph = (MGraph*)malloc(sizeof(mgraph));
    fscanf(fin,"%d %d\n",&mgraph->vexnum,&mgraph->edgenum);
    int i=0;
    int j=0;
    int l,r,info;
    printf("%d %d\n",mgraph->vexnum,mgraph->edgenum);
    for(i=0;i<mgraph->vexnum;i++){
       // printf("--->\n");
        fscanf(fin,"%d ",&mgraph->Vex[i]);
    }
    for(i=0;i<mgraph->vexnum;i++){
        for(j=0;j<mgraph->vexnum;j++){
           // printf("%d %d\n",i,j);
            mgraph->Edge[i][j] = MAXX;
            if(i==j)
                mgraph->Edge[i][j] = 0;
        }
    }
    for(i=0;i<mgraph->edgenum;i++){
        fscanf(fin,"%d %d %d\n",&l,&r,&info);
        
        //printf("%d,%d\n",l,r);
        // 编号从0开始
        mgraph->Edge[l][r] = info;
        //mgraph->Edge[r][l] = info;
    }
    return mgraph;
}





void testAlgraph(){
    fin = fopen("g_input.txt","r");
    ALGraph * algraph = (ALGraph*)malloc(sizeof(ALGraph)); 
    algraph = create_graph();
    printAlg(algraph);
    void BFSTraverse(ALGraph * a,int v);
    void bfstraverse(ALGraph * a);
    
    BFSTraverse(algraph,2);
    printf("\n----------bfs-------------\n");
    bfstraverse(algraph);
    printf("\n");
    void dfs_traverse(ALGraph * g);
    printf("\n---> dfs\n");
    dfs_traverse(algraph);
    void BFS_MIN_Distance(ALGraph * a,int v);
//    BFS_MIN_Distance(algraph,2);
//    printf("test\n");
//    printf("0 first is :%d\n",algraph->vertices[algraph->vertices[0].first->adjvex].data);
//    printf("%d",algraph->vertices[algraph->vertices[0].first->next->adjvex].data); 
//    printf("\n------\n"); 
   
}
void testMgraph(){
    MGraph * m = create();
    printM(m);
    void prim(MGraph * m,int p);
    prim(m,0);
}

typedef struct{
    VNode  v;
    int adjvex;
}Queue1;


// 广度优先
void BFSTraverse(ALGraph * algraph,int v)
{
    if(algraph == NULL || v>algraph->vexnum-1){
        return;
    }
    printf("form %d search\n",v);
    int i=0;
    int visited[MAXNUM];
    for(i=0;i<algraph->vexnum;i++){
        visited[i] = NOT_VISITED;
        printf("%5d",algraph->vertices[i].data);
    }
    printf("\n");
    //int adj = 0;
    Queue1 queue[MAXNUM];
    int front=-1,rear=-1;
    ++rear;
    queue[rear].v= algraph->vertices[v];
    queue[rear].adjvex = v;
    ArcNode * temp = NULL;
   
    while(front!=rear){
        ++front;
        VNode p = queue[front].v;
        temp = p.first;
        if(visited[queue[front].adjvex]==NOT_VISITED){
            printf("visit ---> %d\n",p.data);
            visited[queue[front].adjvex] = VISITED;
            while(temp != NULL){
                ++rear;
                queue[rear].v = algraph->vertices[temp->adjvex];
                queue[rear].adjvex = temp->adjvex;
                
                temp = temp->next;
            }
        }
    }   
}


void visit(ALGraph * algraph,int v){
    printf("visit ------> %d\n",algraph->vertices[v].data);
}
int visited[MAXNUM];
Q * q;

void initVisited(int n){
    int i=0;
    for(i=0;i<n;i++){
        visited[i] = 0;
    }
}

//  蔡写法 v 为编号
void bfs(ALGraph * algraph,int v){
    visit(algraph,v);
    visited[v] = VISITED;
    Q *_q = (Q*)malloc(sizeof(Q));
    init(&_q);
    EnQueue(&_q,v);
    while(isEmpty(_q)!=0){
        v = DeQueue(&_q);
        ArcNode * p = algraph->vertices[v].first;
//        printf("<------- v=%d,%d\n",v,p->adjvex);
        while(p!=NULL){
            if(!visited[p->adjvex]){
   //             printf("adj--->%d\n",p->adjvex);

                visit(algraph,p->adjvex);
               // if( vj == p->adjvex) 可用于判断是否存在路径
                visited[p->adjvex] = VISITED;
                EnQueue(&_q,p->adjvex);
            }
            p = p->next;
        }
    }
}

void bfstraverse(ALGraph * algraph){
    int i=0;
    q = (Q*)malloc(sizeof(Q));
    init(&q);
    for(i=0;i<algraph->vexnum;i++){
        visited[i] = NOT_VISITED;
    }
      //   有向图可能从某一 个顶点不能遍历完整个图
      //   所以for
//    for(i=0;i<algraph->vexnum;i++){

//        if(!visited[i]){
            bfs(algraph,2);
   //    }
    //}
    
}


void dfs(ALGraph * algraph,int v){
    visit(algraph,v);
    visited[v] = VISITED;
    // 取下邻接表
    ArcNode * f = algraph->vertices[v].first;
    while(f!=NULL){
        // 此处加上 arc++ 用于判断是否是棵树，即为n个顶点又n-1条边
        // void dfs(ALGraph * alg,int v ,int * arc)
        if(visited[f->adjvex]!=VISITED){
            dfs(algraph,f->adjvex);
        }
        f = f->next;
    }
}

typedef struct Stack_Node{
    int adjnum;
    ArcNode * next_arc;
}DFS_non_node;

typedef struct Stack{
    int data[MAXNUM];
    int top;
}DFS_Stack;

// 深度优先非递归写法
// 由于使用了栈 所以导致 由右边开始遍历，但是 任然是深度
void dfs_non(ALGraph * algraph,int v){
    if(algraph==NULL){
        return;
    }
    initVisited(algraph->vexnum);
    DFS_Stack * stack = (DFS_Stack*)malloc(sizeof(DFS_Stack));
    stack->top = -1;
    stack->data[++(stack->top)] = v;
    visited[v] = VISITED;
    //visit(algraph,v);
    //ArcNode * p = algraph->vertices[v].first;
    while(stack->top!=-1){
        int k = stack->data[stack->top--];
        visit(algraph,k);
        ArcNode * p = algraph->vertices[k].first;
        while(p!=NULL){
            if(visited[p->adjvex]==NOT_VISITED){
                stack->data[++(stack->top)] = p->adjvex;
                visited[p->adjvex] = VISITED; // 以免 再次 入栈
            }
            p = p->next;
        }
    }
}

void  getDegree(ALGraph * algraph,int degree[]){
    int i;
    ArcNode * p;
    for(i=0;i<algraph->vexnum;i++){
         p = algraph->vertices[i].first;
         while(p!=NULL){
            degree[p->adjvex] = degree[p->adjvex] + 1;
            p = p->next;
         }
    }
}

void dfs_traverse(ALGraph * algraph){
    int i=0;
    for(i=0;i<algraph->vexnum;i++){
        visited[i] = NOT_VISITED;
    }
    printf("-------- 递归深度优先-----\n");
    dfs(algraph,0);
    printf("\n------非递归 深度------\n");
    dfs_non(algraph,0);
}




void testQ(){
    Q *queue = (Q*)malloc(sizeof(Q));
    init(&queue);
    EnQueue(&queue,100);
 EnQueue(&queue,12);
    EnQueue(&queue,13);
//    EnQueue(&queue,14);
    int a =  DeQueue(&queue);   
    printf("dequeue : %d,%d\n",a,queue->data[0]);
    printf("%d% d\n",queue->front,queue->rear);
}

// bfs单源最短路径
void BFS_MIN_Distance(ALGraph * algraph,int u){
    int di[MAXNUM];
    int i=0;
    Q *queue = (Q*)malloc(sizeof(Q));
    init(&queue);
    for(i=0;i<algraph->vexnum;i++){
        di[i] = -1;
        visited[i] = NOT_VISITED;
    }
    visited[u] = VISITED;
    di[u] = 0;
    EnQueue(&queue,u);
    while(isEmpty(queue)!=0){
        u = DeQueue(&queue);
        ArcNode * p = algraph->vertices[u].first;
        while(p!=NULL){
            if(!visited[p->adjvex]){
                visited[p->adjvex] = VISITED;
                di[p->adjvex] = di[u] + 1;
                EnQueue(&queue,p->adjvex);
            
            }
            p = p->next;
        }
    }
    for(i=0;i<algraph->vexnum;i++){
        printf("%3d",di[i]);
    }
    printf("\n");
}


void printPath(int path[],int size){
    int i=0;
    printf("k=:%d  path:",size);
    for(i=0;i<=size;i++){
        printf(i==size?"%d":"%d--->",path[i]);
    }
    printf("\n");
}
// 可用于解2017最后一题即为找简单路径，没有回路
// uv:指定的两点 path用于存放路径的数组 d迭代的路径深度 k指定的长度
void FindPath(ALGraph * algraph,int u,int v,int path[],int d,int k){
    int w;
    ArcNode * p;
    d++;
    path[d] = u;
    visited[u] = VISITED;
    if(u==v){
        if(d==k){
            printPath(path,d);
        }
        visited[v] = NOT_VISITED;
        return;
    }
    p = algraph->vertices[u].first;
    while(p!=NULL){
        w = p->adjvex;
        if(visited[w] == NOT_VISITED){
            FindPath(algraph,w,v,path,d,k);
        }
        p = p->next;
    }
    visited[u] = NOT_VISITED;
}

int count=0;
void FindPath2(ALGraph * algraph,int u,int v,int path[],int d,int k){
    count++;
    //sprintf("current :%d ",u);
    int w;
    ArcNode * p;
    d++;
    path[d] = u;
    visited[u] = VISITED;
    if(u==v){
            printPath(path,d);
            //其实再往下找就没有意义了
    }
    p = algraph->vertices[u].first;
    while(p!=NULL){
        w = p->adjvex;
        if(visited[w] == NOT_VISITED){
            FindPath2(algraph,w,v,path,d,k);
        }
        p = p->next;
    }
    visited[u] = NOT_VISITED;
}
void clean(int data[],int n){
    int i = 0;
    for(i=0;i<n;i++){
        data[i] = 0;
    }
}
void testFindPath(){

    fin = fopen("g_input.txt","r");
    int path[MAXNUM] = {-1};
    ALGraph * algraph = (ALGraph *)malloc(sizeof(ALGraph));
    //algraph = create_graph();
    algraph = createAlgByArc();
    printAlg(algraph);
    //initVisited(algraph->vexnum); 
    //BFSTraverse(algraph,0);
    printf("---------------find simple path -----------\nfind 0<->3 \n");
    initVisited(algraph->vexnum);
    FindPath(algraph,0,4,path,-1,2);
    clean(path,10);
    printf("\n------\n");
    FindPath2(algraph,0,4,path,-1,2);
    printf("count : %d \n",count);
}
// 创建   代 权 的 图
ALGraph * testCreateByArc(){

    fin = fopen("arc_input.txt","r");
 //   int path[MAXNUM] = {-1};
    ALGraph * algraph = (ALGraph *)malloc(sizeof(ALGraph));
    //algraph = createAlgByArc();
    algraph = createDAG();
    printAlg(algraph);
    dfs_traverse(algraph);
    int degree[10] = {0};
    
    getDegree(algraph,degree);
    int i;
    for(i=0;i<algraph->vexnum;i++){
        printf("%5d",degree[i]);
    }
    printf("\n");
    return algraph;
}

// param : MGraph
void prim(MGraph * mgraph,int start){
    printf("最小生成树算法\n");
    int cost[MAXNUM][MAXNUM];
    int i,j,k,n,u;
    int min;
    int low[MAXNUM];
    int close_set[MAXNUM];
    int vexnum  = mgraph->vexnum;
    for(i=0;i<vexnum;i++){
        for(j=0;j<vexnum;j++){
            cost[i][j] = mgraph->Edge[i][j];
        }
    }
    // 初始化顶点的邻近的 边的代价 以及将其是顶点 并入 集合
    for(i=0;i<vexnum;i++){
        low[i] = cost[start][i];
        close_set[i] = start; //存储的与当前顶点边最小的前驱顶点
    }
    // 需要循环 vexnum-1 
    for(i=0;i<vexnum-1;i++){
        min = MAXX;
        for(j=0;j<vexnum;j++){
            if(low[j]!=0 && low[j] < min){
                min = low[j];
                k = j; //save the current close
            }
        }
        // 如第一个循环的时候，close_set[k]即为0，k即为0与其他顶点中，边最小的一个
        printf("{%d<-->%d\tinfo:%d}\n",close_set[k],k,cost[close_set[k]][k]);
        // 将这个顶点并入顶点集
        low[k] = 0;

        printf("\n");
        for(j=0;j<vexnum;j++){
            if(cost[k][i]!=0 && cost[k][j]<low[j]){
                low[j] = cost[k][j];
                // 如果通过当前顶点到达其他顶点的距离小于之前i直接到达j的距离，那么则修改，
                // 并且将j的最短距离的前驱设为k
                close_set[j] = k; //
            }
        }

    }
}


// 某个定点到其他顶点的最短距离
// n个顶点，v出发顶点
// pre 记录前驱节点的编号，既可找到完整的最短路径
void Dijkstra(int n,int v,int dist[],int pre[],MGraph * m){
    int s[MAXNUM],i,j,k,min;
    for(i=0;i<n;i++){
        dist[i] = m->Edge[v][i];
        s[i] = 0;
        if(dist[i]<MAXNUM) 
            pre[i] = v;
        else
            pre[i] = 0;
    }
    printArrary(dist,n);
    s[v] = 1;
    pre[v] = 0;
    for(i=0;i<n;i++){
        min = MAXNUM;
        k = 0;
        for(j=0;j<n;j++){
            if(s[j]==0){
                if(dist[j]!=0&&dist[j]<min){
                    min = dist[j];
                    k = j;//记录权最小的边依附的顶点
                }
            }
        }
        printArrary(dist,n);
        if (k==0)
        {
            continue;
        }
        printf("选择顶点 :%d\n",k+1);
        s[k] = 1; // 标记这个点已经并入了集合
        for(j=0;j<n;j++){
            // A通过vj到底其他点的距离，如果小于原始的距离则修改
            if(s[j]==0 && m->Edge[k][j]<MAXNUM){
                if(dist[k]+m->Edge[k][j] < dist[j]){
                    printf("修改 %d \n",j+1);
                    dist[j] = dist[k]+m->Edge[k][j];
                    pre[j] = k;
                }
            }
        }
        printArrary(pre,n);
        printf("--------------------\n");


    }
}

void Kruskal(){

}


int floydPath[100][100];
int floyddist[100][100];
//计算每对顶点之间的最短距离
// 每次增加一个中间点，判断通过这个中间点到达目标点的距离是否与直接到达更小
// 如果更小则修改距离与路径
void floyd(MGraph * mg,int n){
    //printf("最短路径算法");
    int i=0,j=0,k=0,m=0;
    for(i=0;i<mg->vexnum;i++){
        for(j=0;j<mg->vexnum;j++){
            floyddist[i][j] = mg->Edge[i][j];
            floydPath[i][j] = 0;
        }
    }
    for(k=0;k<n;k++){
    // k 为经过的中间点    
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(floyddist[i][k]+floyddist[k][j] < floyddist[i][j]){
                    floyddist[i][j] = floyddist[i][k]+floyddist[k][j];
                    floydPath[i][j] = k+1; //编号从1开始
                }
            
            }
        }
    }
}


// i j分别为顶点的编号，从1开始
void print_floydPath(i,j){

    int k;
    k = floydPath[i-1][j-1];
   
    if(k==0)
        return;
    print_floydPath(i,k);
    printf("%5d",k);
//    print_floydPath(k,j); // 是不是多余的了啊？？
}
void print_allFloyd(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
                printf("%d -->",i+1);
                print_floydPath(i+1,j+1);
                printf("-->%d",j+1);
                if(floyddist[i][j] == MAXX)
                    printf("NO path");
                printf("\n");
            }
        }
    }
}
void push(DFS_Stack * s,int data){
    s->data[++(s->top)] = data;
}
int pop(DFS_Stack * s){
    return s->data[(s->top)--];
}
// algraph : 邻接表
// 图的拓扑排序
int ToplogicalSort(ALGraph * algraph){
    DFS_Stack * s = (DFS_Stack*)malloc(sizeof(DFS_Stack));
    s->top = -1;
    int degree[MAXNUM] = {0};
    getDegree(algraph,degree);
    int i=0;
    for(i=0;i<algraph->vexnum;i++){
        if(degree[i]==0)
            push(s,i);
    }
    int element;
    int count = 0;
    ArcNode * p;
    while(s->top != -1){
        element = pop(s);
        count++;
        printf("index:%d data:%d\n ",element,algraph->vertices[element].data);
        p = algraph->vertices[element].first;
        while(p!=NULL){
            int v = p->adjvex;
            if(!(--degree[v]))
                push(s,v);
            p = p->next;
        }
    }
    if(count < algraph->vexnum)
        return 0;
    else 
        return 1;
}// 如果一个顶点有多个直接后继，那么排序的结果不唯一

void a(int b[]){
    b[0] = 1;
    b[1] = 2;
}

void testFloyd(){
    MGraph * m = (MGraph*)malloc(sizeof(MGraph));
    m = create();
    printM(m);
    floyd(m,m->vexnum);
    int i=0,j=0;
    // for(i=0;i<m->vexnum;i++){
    //     for(j=0;j<m->vexnum;j++){
    //         printf("%7d",floyddist[i][j] );
    //     }
    //     printf("\n");
    // }
    printDouArrary(floyddist,m->vexnum,m->vexnum);
    printDouArrary(floydPath,m->vexnum,m->vexnum);
    print_allFloyd(m->vexnum);
    //print_floydPath(1,2);
    printf("\n");
}

void testDijkstra(){
    MGraph * m = (MGraph*)malloc(sizeof(MGraph));
    m = create();
    printM(m);
    int dist[MAXNUM];
    int pre[MAXNUM];
    Dijkstra(m->vexnum,0,dist,pre,m);
    int i=0;
    printf("-------------------\n");
    for(i=0;i<m->vexnum;i++){
        printf("%d ",pre[i]);
    }
    // 例如 1号顶点到3号顶点之间的最短路径(编号对应下标减一)
    int start_index = 3;
    int next = start_index;
    printf("1号顶点到4号顶点之间的最短路径为\n");
    printf("4 ");
    while(next != 0){
        printf("%d ",pre[next]+1);
        next = pre[next];
    }
    printf("\n");
}

// 判断一个图是否是连通图
int judgeConnected(ALGraph * algraph,int startV){
    dfs(algraph,startV);
    int i= 0;
    for(i=0;i<algraph->vexnum;i++){
        // 如果存在没有访问到顶点，则一定是非连通图
        if(visited[i]==0)
            return 0;
    }
    return 1;
}
void justTest(){
    ALGraph * algraph = (ALGraph*)malloc(sizeof(ALGraph));
    fin = fopen(g_input,"r");
    algraph = createAlgByArc();
    printAlg(algraph);
    printf("%s\n",judgeConnected(algraph,0)==1?"yes":"no");
    //dfs(algraph,0);
    
}

int main( )
{
    justTest();
    //testFloyd();
    //testFindPath();
    //testDijkstra();
 //    fin = fopen("arc_input.txt","r");
 // //   int path[MAXNUM] = {-1};
 //    ALGraph * algraph = (ALGraph *)malloc(sizeof(ALGraph));
 //    //algraph = createAlgByArc();
 //    algraph = createDAG();
 //    printAlg(algraph);

   // ALGraph * algraph = testCreateByArc();
  //  printf("--->toplfo sort :%d\n",ToplogicalSort(algraph));
// testFindPath();
//bin    testQ();
    //testMgraph();
//   testAlgraph();
    return 0;
}

