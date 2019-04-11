#include<stdio.h>

typedef struct cordi
{
    int x; 
    int y;
    int jump;
}cordi;

int n, m;
int arr[100][100];
int vis[100][100];
int max_ans = 50000000;

cordi UP(int curr_x, int curr_y)
{
    cordi temp;
    temp.x = -1;
    temp.y = -1;
    temp.jump = -1;
    int count = 0;
    while(curr_x>=0)
    {
        curr_x--;
        count++;
        if(arr[curr_x][curr_y]!=0 && vis[curr_x][curr_y]==0)
        {
            
            temp.x = curr_x;
            temp.y = curr_y;
            temp.jump = count;
            return temp;
        }
        
    }
    return temp;
}

cordi DOWN(int curr_x, int curr_y)
{
    cordi temp;
    temp.x = -1;
    temp.y = -1;
    temp.jump = -1;
    int count = 0;
    while(curr_x<n)
    {
        curr_x++;
        count++;
        if(arr[curr_x][curr_y]!=0 && vis[curr_x][curr_y]==0)
        {
            
            temp.x = curr_x;
            temp.y = curr_y;
            temp.jump = count;
            return temp;
        }
        
    }
    return temp;
}

void dfs(int curr_x, int curr_y, int ans)
{
    if(arr[curr_x][curr_y]==3)
    {
        if(ans<max_ans) max_ans = ans;
        return;
    }
    vis[curr_x][curr_y] = 1;

    if(arr[curr_x][curr_y-1]!=0 && curr_y-1>=0 && vis[curr_x][curr_y-1]==0)  //Move Left
    {
        dfs(curr_x, curr_y-1, ans);
        vis[curr_x][curr_y-1]=0;
    }
    if(arr[curr_x][curr_y+1]!=0 && curr_y+1<m && vis[curr_x][curr_y+1]==0)  //Move Right
    {
        dfs(curr_x, curr_y+1, ans);
        vis[curr_x][curr_y-1]=0;
    }
    cordi temp = UP(curr_x,curr_y);
    if(temp.x != -1)
    {
        if(ans<temp.jump) ans = temp.jump;
        dfs(temp.x,temp.y,ans);
        vis[temp.x][temp.y]=0;
    }
    cordi temp1 = DOWN(curr_x,curr_y);
    if(temp1.x != -1)
    {
        if(ans<temp1.jump) ans = temp1.jump;
        dfs(temp1.x,temp1.y,ans);
        vis[temp1.x][temp1.y]=0;
    }
    return;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d", &n);
        scanf("%d", &m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&arr[i][j]);
                vis[i][j] = 0;
            }
        }

        dfs(n-1,0,0);
        printf("%d\n", max_ans);
    }
}