/*
E/15/211
CO322-Data STructures and Algorithm
Lab5-Transitive closure graph
*/


#include<stdio.h>

#define V 7 //V-no of vertex in the given graph

int i,j;
void transitiveClosure(int graph[V][V])
{
    int i, j, k;
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
          for (j = 0; j < V; j++)
            {
               if(i==j){
                 graph[i][j]=1;  //for diagonal         
               }
              graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
    printf ("Transitive closure of the given graph:-\n");
    for ( i = 0; i < V; i++)
    {
        for ( j = 0; j < V; j++)
            printf ("%d ", graph[i][j]);//print the output matrix
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = { {0,1,1,1,1,1,1},//given adjacency matrix
                        {0,0,0,0,1,0,1},
                        {0,1,0,1,1,1,1},
                        {0,1,0,0,1,0,1},
                        {0,1,0,0,0,0,1},
                        {0,1,0,1,1,0,1},
                        {0,1,0,0,1,0,0}
                      };
    transitiveClosure(graph);
    return 0;
}
