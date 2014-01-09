#include<stdio.h>
#include<stdlib.h>

#define SIZE 20
#define inf 0x7FFFFFFF
int v[SIZE],c[SIZE];
int A[SIZE][SIZE],n,m,p=1,u=1,t[SIZE],s[SIZE],C[SIZE][SIZE],v1[SIZE],v2[SIZE];
float a[SIZE][SIZE],d[SIZE],cmin;

void read_data(FILE *file,int x[SIZE][SIZE])
{
    int data;

    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            fscanf(file, "%d", &data);
            x[i][j] = data;
        }
    }
}
void display(int A[SIZE][SIZE])
{
    int i, j;
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void bfs( int A[SIZE][SIZE], int nod)
{
    int k;
    printf("%d ",nod);
    v[nod]=1;
    for(k=1;k<=n;k++)
        if( A[nod][k]==1 && v[k]==0 )
            bfs( A, k) ;
}
void dfs(int nod)
{
    int i,l1;
    p=u=1;
    c[p]=nod;
    v[nod]=1;
    while(p<=u)
    {
        l1=c[p];
        for(i=1;i<=n;i++)
            if(A[l1][i]&&(v[i]==0))
                {
                    v[i]=1;
                    u++;
                    c[u]=i;;
                }
        p++;
     }
}

void Dijkstra(int vf)
{
    int i,j,pmin;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(C[i][j])
                a[i][j]=C[i][j];
            else
                a[i][j]=inf;
    for(i=1;i<=n;i++)
        a[i][i]=0;

    for(i=1;i<=n;i++)
    {
        if(C[vf][i])
        {
            d[i]=C[vf][i];
            t[i]=vf;
        }
        else
            d[i]=inf;

        s[i]=0;
    }
    d[vf]=0;
    s[vf]=1;
    d[0]=inf;

    for(i=1;i<n;i++)
    {
        pmin=0;
        for(j=1;j<=n;j++)
            if(!s[j] && d[j]<d[pmin])
                pmin=j;
        s[pmin]=1;
        for(j=1;j<=n;j++)
            if(!s[j] && d[j]>d[pmin]+a[pmin][j])
            {

                d[j]=d[pmin]+a[pmin][j];
                t[j]=pmin;
            }
    }

}

void path_Dijkstra(int x,int y)
{
    if(x!=y)
        path_Dijkstra(x,t[y]);
    printf("%d ",y);
}
void Floyd()
{
    int i,j,k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(C[i][j])
                a[i][j]=C[i][j];
            else
                a[i][j]=inf;
    for(i=1;i<=n;i++)
        a[i][i]=0;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[j][i]=a[i][k]+a[k][j];
}

void path_Floyd(int x,int y)
{
    int k,gasit=0;
    for(k=1;k<=n;k++)
        if( a[x][y]==a[x][k]+a[k][y] && k!=x && k!=y )
        {
            gasit=1;
            path_Floyd(x,k);
            path_Floyd(k,y);
            break;
        }
    if(!gasit)
        printf("%d ",y);
}

void Prim(int vf)
{
    int i,pmin,j,k,j1;
    float min;
    for(i=1;i<=n;i++)
        s[i]=0;
    s[vf]=1;
    k=1;
    t[k]=vf;
    cmin=0;
    for(i=1;i<n;i++)
    {
        min=inf;
        pmin=0;
        for(j=1;j<=n;j++)
            if(!s[j])
                for(j1=1;j1<=k;j1++)
                    if(min>C[t[j1]][j] && C[t[j1]][j])
                    {
                        min=C[t[j1]][j];
                        pmin=j;
                    }
        t[++k]=pmin;
        if(pmin)
        {
            s[pmin]=1;
            cmin+=min;
        }
    }
}
void sort()
{
    int i,gasit,aux;
    do
    {
        gasit=0;
        for(i=1;i<m;i++)
            if(C[v1[i]][v2[i]]>C[v1[i+1]][v2[i+1]])
            {
                gasit=1;
                aux=v1[i];
                v1[i]=v1[i+1];
                v1[i+1]=aux;
                aux=v2[i];
                v2[i]=v2[i+1];
                v2[i+1]=aux;
            }
    }while(gasit);
}

int loop(int x,int y)
{
    int i,in,sf,tail[50],b[50];
    for(i=1;i<=n;i++)
        b[i]=0;
    in=sf=1;
    tail[1]=x;
    b[x]=1;
    while(in<=sf)
    {
        for(i=1;i<=m;i++)
            if(s[i])
            {
                if(v1[i]==tail[in])
                {
                    if(v2[i]==y)
                        return 1;
                    tail[++sf]=v2[i];
                    b[v2[i]]=1;
                }
                if(v2[i]==tail[in])
                {
                    if(v1[i]==y)
                        return 1;
                    tail[++sf]=v1[i];
                    b[v1[i]]=1;
                }
            }
        in++;
    }
    return 0;
}

void Kruskal()
{
    int i,j;
    for(i=2;i<=m;i++)
        s[i]=0;
    s[1]=0;
    cmin=0;
    for(i=1,j=1;i<=m,j<n;i++)
        if(!loop(v1[i],v2[i]))
        {
            s[i]=1;
            cmin=cmin+C[v1[i]][v2[i]];
            j++;
        }
    printf("\n");
}

int main()
{
    FILE *pFile;
    pFile=fopen("data.txt","r");
    fscanf(pFile,"%d %d",&n,&m);
    int i=1;
    do
    {
        printf("\t~\tMENU\t~\t\n\n");
        printf("\t1 -> Read data matrix\n");
        printf("\t2 -> DFS\n");
        printf("\t3 -> BFS\n");
        printf("\t4 -> Dijkstra\n");
        printf("\t5 -> Floyd\n");
        printf("\t6 -> Prim\n");
        printf("\t7 -> Kruskal\n\n\n");
        printf("\t10-> Exit\n");
        scanf("%d",&i);

        switch (i)
        {
            case 1:
                {
                    printf("Adjacency matrix\n");
                    read_data(pFile,A);
                    display(A);
                    printf("Cost matrix\n");
                    read_data(pFile,C);
                    display(C);
                    break;
                }
            case 2:
                {
                    printf("DFS:\n");
                    int j;
                    for(j=1;j<=n;j++)
                        v[j]=0;
                    printf("Starting node: ");
                    int nod;
                    scanf("%d",&nod);
                    bfs(A,nod);
                    printf("\n");
                    for(i=1;i<=n;i++)
                        printf("%d ",v[i]);
                        printf("\n");

                    break;
                }
            case 3:
                {
                    printf("BFS\n");
                    int j;
                    for(j=1;j<=n;j++)
                        v[j]=0;
                    printf("Starting node: ");
                    int nod;
                    scanf("%d",&nod);
                    dfs(nod);
                    for(j=1;j<=u;j++)
                        printf("%d ",c[j]);
                    printf("\n");
                    break;

                }
            case 4:
                {
                    int x,y,i;
                    printf("Strting node:");
                    scanf("%d",&x);
                    Dijkstra(x);
                    printf("Minimum cost from %d to all others is:\n",x);
                    for(i=1;i<=n;i++)
                        printf("%.2f ",d[i]);
                    printf("\n");
                    printf("Final node:");
                    scanf("%d",&y);
                    if(d[y]<inf)
                    {
                        printf("Minimum cost from %d to %d is:%.2f\n",x,y,d[y]);
                        printf("Minimum path cost is:");
                        path_Dijkstra(x,y);
                        printf("\n");
                    }
                    else
                        printf("There is no path from %d to %d\n",x,y);
                    break;
                }
            case 5:
                {
                    Floyd();
                    int x,y,i,j;
                    printf("Minimum cost matrix:\n");
                    for(i=1;i<=n;i++)
                    {
                        for(j=1;j<=n;j++)
                            printf("%.2f ",a[i][j]);
                        printf("\n");
                    }
                    printf("Give 2 nodes:");
                    scanf("%d %d",&x,&y);
                    if(a[x][y]<inf)
                        {
                            printf("Minimum cost between those 2 nodes is:%.2f\n",a[x][y]);
                            printf("Minimum cost path is:%d ",x);
                            path_Floyd(x,y);
                            printf("\n");
                        }
                    else
                        printf("There is no path from %d to %d\n",x,y);
                    break;
                }
           case 6:
                {
                    int x,i;
                    printf("Starting node:");
                    scanf("%d",&x);
                    Prim(x);
                    printf("\n:");
                    for(i=1;i<=n;i++)
                        if(t[i])
                            printf("%d ",t[i]);
                    printf("\nMinimum cost is:%.2f\n",cmin);
                    break;
                }
            case 7:
                {
                    int k=0,i,j;
                    for(i=1;i<=n;i++)
                        for(j=1;j<=i;j++)
                            if(C[i][j])
                            {
                                k++;
                                v1[k]=j;
                                v2[k]=i;
                            }
                    sort();
                    Kruskal();
                    printf("Minimum cost tree created by the given edges is:\n");
                    for(i=1;i<=m;i++)
                        if(s[i])
                            printf("<%d %d> ",v1[i],v2[i]);
                    printf("\nMinimum cost is:%.2f\n",cmin);
                    break;
                }
            default:
                i=0;
        }
    }while(i);
    fclose(pFile);
    return 0;
}
