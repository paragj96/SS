#include<stdio.h>


int x=1,n;
int arr[5];
int visited[5];

void print()
{
    printf("%d))",x++);
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
}
void dfs(int index)
{
    if(index>=n)
    {
        print();
        return;
    }
    for(int j=1;j<=n;j++)
    {
        if(visited[j]==0){
            arr[index]=j;
            visited[j]=1;
            dfs(index+1);
            visited[j]=0;
        }
    }
    return ;
}

int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        visited[i]=1;
        arr[0]=i;
        dfs(1);
        visited[i]=0;
    }
}