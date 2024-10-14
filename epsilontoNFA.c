#include<stdio.h>

int et[100][100];
int visited[100];


void dfs(int v,int n);
void reset_visited(int n);

int main()
{
int nt,ns;

printf("Enter the number of states : ");
scanf("%d",&ns);
printf("Enter the number of transitions : ");
scanf("%d",&nt);

printf("Enter transitions (format:i symbol j.use e for epsilon: \n");
int m,n;
char sym;

for(int i=0;i<nt;i++)
{
scanf("%d%c%d",&m,&sym,&n);
if(sym=='e')
et[m][n]=1;
}


for(int i=1;i<ns;i++)
{
printf("Epsilon closure of state %d : ",i);
reset_visited(ns);
dfs(i,ns);


for(int j=1;j<=ns;j++)
if(visited[j]==1)
printf("%d",j);
printf("\n");
}
return 0;
}



void dfs(int v,int n)
{
visited[v]=1;
for(int i=1;i<=n;i++)
{
if(et[v][i]==1 && visited[i]==0)
{
dfs(i,n);
}
}
}

void reset_visited(int n)
{
for(int i=1;i<=n;i++)
{
visited[i]=0;
}
}

