 /*#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define IN 99
#define N 9
//int dijkstra(int cost[][N], int source, int target);
int dijsktra(int cost[][N],int source,int target)
{
    int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
    char path[N];
    for(i=0;i< N;i++)
    {
        dist[i] = IN;	
        prev[i] = -1;	
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=0;i< N;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;//hold current node
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1)
    {
        path[j++] = start+65;
        start = prev[start];
    }
    path[j]='\0';
    strrev(path);
    int k=0;
    while(path[k]!=NULL){
    printf("%c -->", path[k]);
	k++;
	}
    return dist[target];
}
int main()
{
    int cost[N][N],i,j,w,ch,co,choice;
    int source, target,x,y,Source ,Target,sh;
    int Cost[9][9] = { 	{0   , 10   ,87,   110   ,10,    20    ,49 ,  75 ,  85},
                    	{10    ,0    ,77 ,  120  , 20 ,   30    ,59  , 85  , 95},
						{87  ,77 ,   0   ,197 ,98  ,107, 136 , 162 , 172  },
						{110  , 120   ,197  ,0    ,120  , 130 ,  159 , 185  ,195},
						{10    ,20    ,98   ,120  , 0   , 13, 45   ,71   ,81},
						{20    ,30   , 107  ,130 ,  13 ,0   , 42  , 61  , 71},
						{49  ,59  ,  136  ,159 ,45  ,42 , 0   ,  84,   94},
						{75  ,85  , 162  ,185 ,71 , 61 ,84 ,  0   ,  10},
						{85  ,95 ,  172  ,195, 81  ,71  ,94,   10   , 0 }};
    printf("\t The Shortest Path Algorithm ( DIJKSTRA'S ALGORITHM in C) \n\n");
    printf("\t\t\t Data Structure\n\n");
    printf("\t\t\t    Final Lab\n\n");
    printf("How You Want To calculate :\n");
    printf("1) Use BuiltIn Graph\n");
    printf("2)Create Your Own\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1:
    	 
				 printf("\nEnter the source:");
    			scanf("%d", &Source);
    			printf("\nEnter the target:");
    			scanf("%d", &Target);
				 sh = dijsktra(Cost,Source,Target);
    			printf(" END");
    			printf("\nThe Shortest Path: %d",sh);
    		
    		break;
    	case 2:
    		for(i=0;i< N;i++)
    for(j=0;j< N;j++)
    cost[i][j] = IN;
    for(x=0;x< N;x++)
    {
        for(y=x+1;y< N;y++)
        {
            printf("Enter weight between nodes %d and %d: ",x,y);
            scanf("%d",&w);
            cost [x][y] = cost[y][x] = w;
        }
        printf("\n");
    }
    printf("\nEnter the source:");
    scanf("%d", &source);
    printf("\nEnter the target");
    scanf("%d", &target);
    co = dijsktra(cost,source,target);
    printf(" END");
    printf("\nThe Shortest Path: %d",co);

    		break;
    	default:
    		printf("Wrong Selection\n");
}	
}
	
*/
/*
 #include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define IN 99
#define N 9
//int dijkstra(int cost[][N], int source, int target);
int dijsktra(int cost[][N],int source,int target)
{
    int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
    char path[N];
    for(i=1;i< N;i++)
    {
        dist[i] = IN;	
        prev[i] = -1;	
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1;i< N;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;//hold current node
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1)
    {
        path[j++] = start+65;
        start = prev[start];
    }
    path[j]='\0';
    strrev(path);
    int k=0;
    while(path[k]!=NULL){
    printf("%c -->", path[k]);
	k++;
	}
    return dist[target];
}
int main()
{
    int cost[N][N],i,j,w,ch,co,choice;
    int source, target,x,y,Source ,Target,sh;
    int Cost[9][9] = { { 0, 20, 30, 99, 50, 99, 40, 99, 99 },
					 { 20, 0, 30, 99, 70, 99, 99, 50, 99 },
					 { 30, 30,0, 99, 99, 99, 90, 20, 60 },
					 { 99, 99, 99, 0, 60, 99, 10, 99, 99 },
					 { 50, 70, 99, 60, 0, 99, 40, 99, 99 },
					 { 99, 99, 99, 99, 99, 0, 99, 10, 40 },
					 { 40, 99, 90, 10, 40, 99, 0, 99, 99 },
					 { 99, 50, 20, 99, 99, 10, 99, 0, 40 },
					 { 99, 99, 60, 99, 99, 40, 99, 40, 0 }};
    printf("\t The Shortest Path Algorithm ( DIJKSTRA'S ALGORITHM in C) \n\n");
    printf("\t\t\t Data Structure\n\n");
    printf("\t\t\t    Final Lab\n\n");
    printf("How You Want To calculate :\n");
    printf("1) Use BuiltIn Graph\n");
    printf("2)Create Your Own\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1:
    	 
				 printf("\nEnter the source:");
    			scanf("%d", &Source);
    			printf("\nEnter the target");
    			scanf("%d", &Target);
				 sh = dijsktra(Cost,Source,Target);
    			printf(" END");
    			printf("\nThe Shortest Path: %d",sh);
    		
    		break;
    	case 2:
    		for(i=1;i< N;i++)
    for(j=1;j< N;j++)
    cost[i][j] = IN;
    for(x=1;x< N;x++)
    {
        for(y=x+1;y< N;y++)
        {
            printf("Enter weight between nodes %d and %d: ",x,y);
            scanf("%d",&w);
            cost [x][y] = cost[y][x] = w;
        }
        printf("\n");
    }
    printf("\nEnter the source:");
    scanf("%d", &source);
    printf("\nEnter the target");
    scanf("%d", &target);
    co = dijsktra(cost,source,target);
    printf(" END");
    printf("\nThe Shortest Path: %d",co);

    		break;
    	default:
    		printf("Wrong Selection\n");
}	
}
	
*/
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define INFINITE 99

/*int dijsktra(int matrix[][10],int source,int dest){
	int dist[10],prev[10],selected[10]={0};
	int start,m,min,j;        //i,m,min,start,d,j
	char path[10];
	for(int i=0;i<10;i++)
    {
        dist[i] = IN;	
        prev[i] = -1;	
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[dest] ==0)
    {
        min = IN;
        m = 0;
        for(int i=0;i<10;i++){
        	int d = dist[start] +matrix[start][i];
        	if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;//hold current node
            }
        }
        start = m;
        selected[start] = 1;
	}
    start = dest;
    j = 0;
    while(start != -1)
    {
        path[j++] = start+65;
        start = prev[start];
    }
    path[j]='\0';
    strrev(path);
    int k=0;
    while(path[k]!=NULL){
    printf("%c -->", path[k]);
	k++;
	}
    return dist[dest];
}*/
/*
void dijkstra(int G[][10], int dest, int source) {
    int V = 10, startnode;
    int cost[10][10], distance[V], pred[V];
    int visited[V], count, mindistance, nextnode, i, j;
    
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (G[i][j] == 0)
                cost[i][j] = INFINITE;
            else
                cost[i][j] = G[i][j];
        }
    }

    for (i = 0; i < 10; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < 9) {
        mindistance = INFINITE;
        for (i = 0; i < 10; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for (i = 0; i < 10; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    printf("Shortest Path from %d to %d: ", source, dest);
    printf("Distance: %d\n", distance[dest]);
    printf("Path: ");
    j = dest;
    printf("%d", j);
    while (j != source) {
        j = pred[j];
        printf(" <- %d", j);
    }
}

int main(){
	//int mat[10][10];
	int source,dest,sh;
	int mat[10][10]={{0,10,0,110,12,0,0,0,0,86},
	{10,0,77,0,0,0,0,0,0,0},
	{77,0,0,0,0,0,0,0,0,0},
	{110,0,0,0,0,0,0,0,0,0},
	{12,0,0,0,0,13,39,0,0,0},
	{0,0,0,0,13,0,42,67,0,0},
	{0,0,0,0,39,42,0,83,0,0},
	{0,0,0,0,0,67,83,0,10,6},
	{0,0,0,0,0,0,0,1,0,0},
	{86,0,0,0,0,0,0,6,0,0}
	};
/*	int mat[10][10]= { 	{0   , 10   ,87,   110   ,10,    20    ,49 ,  75 ,  85,86},
                    	{10    ,0    ,77 ,  120  , 20 ,   30    ,59  , 85  , 95,96},
						{87  ,77 ,   0   ,197 ,98  ,107, 136 , 162 , 172 ,173 },
						{110  , 120   ,197  ,0    ,120  , 130 ,  159 , 185  ,195,196},
						{10    ,20    ,98   ,120  , 0   , 13, 45   ,71   ,81,77},
						{20    ,30   , 107  ,130 ,  13 ,0   , 42  , 61  , 71,73},
						{49  ,59  ,  136  ,159 ,45  ,42 , 0   ,  84,   94,90},
						{75  ,85  , 162  ,185 ,71 , 61 ,84 ,  0   ,  10,6},
						{85  ,95 ,  172  ,195, 81  ,71  ,94,   10   , 0 ,16},
						{86,96,173,196,77,73,9,6,16,0}};
	printf("\t The Shortest Path Algorithm ( DIJKSTRA'S ALGORITHM in C) \n\n");
	printf("Enter the source: ");
	scanf("%d",&source);
	printf("Enter the destination: ");
	scanf("%d",&dest);
	dijkstra(mat,dest,source);
	printf(" END");
 
	return 0;	
}
*/
#include<stdio.h>
int main(){
 	int matrix_1[3][3]={{1,2,3}, {4,5,6}, {7,8,9}};
 	int matrix_2[3][3]={{1,0,0}, {0,1,0}, {0,0,1}};
 	int matrix_3[3][3]={{0,0,0}, {0,0,0}, {0,0,0}};
 	printf("The matrix addition of a and b is :\n");
 	int k[3][3];
 	for(int i=0;i<3;i++){
 		for(int j=0;j<3;j++){
 			k[i][j]=matrix_1[i][j] + matrix_2[i][j];
 			printf("%d ",k[i][j]);
		 }
		 printf("\n");
	 }
 return 0;
 } 
 /*The matrix addition of a and b is :
2 2 3
4 6 6
7 8 10/*
  
  

