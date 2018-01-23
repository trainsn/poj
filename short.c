#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define INFINITY 32767
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG()
{
	int i,j;
	int l;
	int r;
	int cost;
	MGraph Graph;
	scanf("%d%d",&Graph->Nv,&Graph->Ne);
	for (i=0;i<Graph->Nv;i++)
		for (j=0;j<Graph->Nv;j++)
		{
			Graph->G[i][j]=INFINITY;
		}
	for (i=0;i<Graph->Ne;i++)
	{
		scanf("%d",&l);
		scanf("%d",&r);
		scanf("%d",&cost);
		Graph->G[l][r]=cost;
	}
	return Graph;
}
	/* details omitted */

void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S )
{
	int st=0,en=1,i,ver;
	int queue[10000];
	for (i=0;i<Graph->Nv;i++)
	{
		dist[i]=INFINITY;
		count[i]=0;
	}
	queue[en++]=S;
	dist[S]=0;
	count[S]=1;
	while (st<en)
	{
		ver=queue[st++];
		for (i=0;i<Graph->Nv;i++)
			if (Graph->G[ver][i]<INFINITY)
			{
				if (dist[ver]+Graph->G[ver][i]<dist[i])
				{
					queue[++en]=i;
					dist[i]=dist[ver]+Graph->G[ver][i];
					count[i]=1;
				}
				else if (dist[ver]+Graph->G[ver][i]==dist[i])
					count[i]++;
			}
	}
}

int main()
{

   int dist[MaxVertexNum], count[MaxVertexNum];
    Vertex S, V;
	MGraph G;
	freopen("n4.in","r",stdin);
	freopen("n4.out","w",stdout);


    G = ReadG();
	scanf("%d", &S);
    ShortestDist( G, dist, count, S );

    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);
    printf("\n");
    for ( V=0; V<G->Nv; V++ )
        printf("%d ", count[V]);
    printf("\n");

    return 0;
}
