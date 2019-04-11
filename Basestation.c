#include<stdio.h>


int x[2][6]={{0,1,1,1,0,-1},{0,-1,-1,-1,0,1}};
int y[2][6]={{-1,-1,0,1,1,0},{-1,-1,0,1,1,0}};





int n,m;
int arr[100][100];
int visited[100][100];
int max_ans=0;


void dfs(int curr_x,int curr_y,int count,int ans)
{
    if(count==4)
    {
       // printf("go back\n");
        if(max_ans<ans){
         //   printf("yaha aaya max\n");
         max_ans=ans;
        }
         return;
    } 
    int z;
    if(curr_y%2==0)
        z=1;
    else
        z=0;
    visited[curr_x][curr_y]=1;   
    for(int i=0;i<6;i++)
    {
      if(visited[curr_x+x[z][i]][curr_y+y[z][i]]==0 && curr_x+x[z][i]>=0 && curr_x+x[z][i]<n && curr_y+y[z][i]>=0 && curr_y+y[z][i]<m)
      {
          dfs(curr_x,curr_y,count+1,ans+arr[curr_x+x[z][i]][curr_y+y[z][i]]);
          dfs(curr_x+x[z][i],curr_y+y[z][i],count+1,ans+arr[curr_x+x[z][i]][curr_y+y[z][i]]);
          visited[curr_x+x[z][i]][curr_y+y[z][i]]=0;
      }
    }
    
}


int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&m);
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         scanf("%d",&arr[i][j]);

        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++){
             visited[i][j]=0;
           //  printf("started at :%d %d\n",i,j);
            dfs(i,j,1,arr[i][j]);
         }
         printf("%d\n",max_ans);
    }

    return 0;
    
}