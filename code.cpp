#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 10              //V=No of vertex
#include "time.cpp"
#include "dist.cpp"

int main() {
    int graph[V][V] = {
        {0, 1000, 0, 11000, 1200, 0, 0, 0, 0, 8600},
        {1000, 0, 7700, 0, 0, 0, 0, 0, 0, 0},
        {0, 7700, 0, 0, 0, 0, 0, 0, 0, 0},
        {11000, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1200, 0, 0, 0, 0, 1300, 3900, 0, 0, 0},
        {0, 0, 0, 0, 1300, 0, 4200, 6700, 0, 0},
        {0, 0, 0, 0, 3900, 4200, 0, 8300, 0, 0},
        {0, 0, 0, 0, 0, 6700, 8300, 0, 1000, 600},
        {0, 0, 0, 0, 0, 0, 0, 1000, 0, 0},
        {8600, 0, 0, 0, 0, 0, 0, 600, 0, 0}

    };
    
    int time[V][V] = {
        {0, 6, 0, 28, 3, 0, 0, 0, 0, 17},
        {6, 0, 7700, 0, 0, 0, 0, 0, 0, 0},
        {17, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {28, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 4, 12, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 13, 20, 0, 0},
        {0, 0, 0, 0, 37, 12, 0, 20, 21, 23},
        {0, 0, 0, 0, 0, 20, 20, 0, 4, 17},
        {0, 0, 0, 0, 0, 0, 0, 4, 0, 0},
        {17, 0, 0, 0, 0, 0, 0, 17, 0, 0}
    };
   /* int time[V][V] = {
        {0, 6, 17, 28, 3, 5, 15, 19, 20, 17},
        {6, 0, 18, 25, 6, 7, 15, 21, 22, 18},
        {17, 18, 0, 22, 19, 21, 28, 35, 35, 33},
        {28, 25, 22, 0, 28, 29, 37, 43, 43, 42},
        {3, 6, 19, 28, 0, 4, 12, 18, 19, 17},
        {5, 7, 21, 29, 4, 0, 13, 20, 21, 18},
        {15, 15, 28, 37, 12, 13, 0, 20, 21, 23},
        {19, 21, 35, 43, 18, 20, 20, 0, 4, 17},
        {20, 22, 35, 43, 19, 21, 21, 4, 0, 16},
        {17, 18, 33, 42, 17, 18, 23, 17, 16, 0}
    };*/
	
	printf("                                          COLLEGE NAVIGATOR                                       \n");

    printf("------------------------------------------------------------------------------------------------\n");
	printf("\n                                     (2)(AIT)                                                    ");
	printf("\n                                        |                                                       ");
	printf("\n                                        |                                                       ");
	printf("\n                                        |(7.7KM)                                                      ");
	printf("\n                                        |                                                       ");
	printf("\n                                        |                                                       ");
	printf("\n                                     (1)(AISSMS)                                                 ");
	printf("\n                                        |                                                       ");
	printf("\n                                        |__(1.0KM)                      (9)(PICT)                             ");
	printf("\n                       (3)(DPU)____         |                              /  |                    ");
	printf("\n                                (11KM)         |                          /   |                    ");
	printf("\n                                   |______(0)(COEP)______(8.6KM)________ /    |                    ");                                
	printf("\n                                            |                          (0.6KM)                 ");
	printf("\n                                         (1.2KM)                           |                    ");
	printf("\n                                            |                              |                    ");
	printf("\n                                     (4)(MODERN)                  _____(7)(SCOE)                   ");
	printf("\n                                   (       |                     /   /     |                    ");
	printf("\n                                 (       (1.3KM)    (6.7KM)_____/   /      |                    ");
	printf("\n                                (          |              /   _____/       | (1KM)                   ");
	printf("\n                               (         (5)(FC)_________/   /             |                    ");
	printf("\n                            (3.9KM)        |                /              |                    ");     
	printf("\n                              (            |            (8.3KM)         (8)(IIIT)                  ");
	printf("\n                                (        (4.2KM)       /                                         ");
	printf("\n                                  (          |        /                                         ");                                                                                      
	printf("\n                                     (   (6)(MIT)____/                                        \n");
    printf("--------------------------------------------------------------------------------------------------\n");

    int src, dest;
    while(1){
    printf("Enter the index of the source vertex (0-9): ");
    scanf("%d", &src);
    printf("Enter the index of the destination vertex (0-9): ");
    scanf("%d", &dest);

    if (src < 0 || src >= V || dest < 0 || dest >= V) {
        printf("Invalid source or destination vertex!\n");
        return 1;
 	}
    dijkstra(graph, src, dest);
	dijkstra_time(time, src, dest);
	switch(dest){
		case 0:
			FILE *f0;
	        f0=fopen("COEP.txt","r");
	        char a[1000];
	        while(!feof(f0)){
	        	fgets(a,1000,f0);
	        	puts(a);
			}
	        fclose(f0);
	        break;
	        
	    case 1:
			FILE *f1;
	        f1=fopen("AISSMS.txt","r");
	        char b[1000];
	        while(!feof(f1)){
	        	fgets(b,1000,f1);
	        	puts(b);
			}
	        fclose(f1);
	        break;
	        
	    case 2:
			FILE *f2;
	        f2=fopen("AIT.txt","r");
	        char c[1000];
	        while(!feof(f2)){
	        	fgets(c,1000,f2);
	        	puts(c);
			}
	        fclose(f2);
	        break;
	        
	    case 3:
			FILE *f3;
	        f3=fopen("DPU.txt","r");
	        char d[1000];
	        while(!feof(f3)){
	        	fgets(d,1000,f3);
	        	puts(d);
			}
	        fclose(f3);
	        break;
		
		case 4:
			FILE *f4;
	        f4=fopen("MODERN.txt","r");
	        char e[1000];
	        while(!feof(f4)){
	        	fgets(e,1000,f4);
	        	puts(e);
			}
	        fclose(f4);
	        break;
	    
	    case 5:
			FILE *f5;
	        f5=fopen("FC.txt","r");
	        char f[1000];
	        while(!feof(f5)){
	        	fgets(f,1000,f5);
	        	puts(f);
			}
	        fclose(f5);
	        break;
	        
		case 6:
			FILE *f6;
	        f6=fopen("MIT.txt","r");
	        char g[1000];
	        while(!feof(f6)){
	        	fgets(g,1000,f6);
	        	puts(g);
			}
	        fclose(f6);
	        break;    
	    
	    case 7:
			FILE *f7;
	        f7=fopen("SCOE.txt","r");
	        char h[1000];
	        while(!feof(f7)){
	        	fgets(h,1000,f7);
	        	puts(h);
			}
	        fclose(f7);
	        break;
	        
		case 8:
			FILE *f8;
	        f8=fopen("IIIT.txt","r");
	        char i[1000];
	        while(!feof(f8)){
	        	fgets(i,1000,f8);
	        	puts(i);
			}
	        fclose(f8);
	        break;    
	        
	    case 9:
			FILE *f9;
	        f9=fopen("PICT.txt","r");
	        char j[1000];
	        while(!feof(f9)){
	        	fgets(j,1000,f9);
	        	puts(j);
			}
	        fclose(f9);
	        break;    
	}
    printf("----------------------------------------------------------------------------\n");
    }

    return 0;
}
