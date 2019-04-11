#include<stdio.h>

int n;
int min_dis = 5000000;
int visited[10];
int arr[10];


int check()
{
    for(int i=0;i<n;i++){
        if(visited[i]==0)
            return 0;
    }
    return 1;
}

void dfs(int pos, int dis, int rem_fuel,int fuel_type,int direction)
{
    if(check())
        if(dis<min_dis){
            min_dis=dis;
            return;
        }
    
    
    if(rem_fuel==0){
        dfs(0,dis+pos+2,2,1,0);
        dfs(n-1,dis+(n-pos)+1,2,2,1);
    }
    else{
        if(visited[pos]==0 && arr[pos]==fuel_type)
        {
            
            
                
                
                
                if(pos+1<n){visited[pos]=1;
                    dfs(pos+1,dis+1,rem_fuel-1,fuel_type,0);                            //Fuel tank and move forward
                    visited[pos]=0;}
                if(pos>=0){visited[pos]=1;
                    dfs(pos-1,dis+1,rem_fuel-1,fuel_type,1);                            //Fuel tank and move backward
                    visited[pos]=0;}
                if(pos+1<n){
                    dfs(pos+1,dis+1,rem_fuel,fuel_type,0);                            //Dont fuel and move forward
                }
                
            
            
        }
        else
        {
            if(direction==0)
                if(pos+1<n){
                    dfs(pos+1,dis+1,rem_fuel,fuel_type,0);}
            if(direction==1)
            {
                if(pos-1>=0)
                    dfs(pos-1,dis+1,rem_fuel,fuel_type,1);
            }
            
        }
    }
    return;
    
}

int main()
{
    min_dis = 5000000;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            visited[i]=0;
        }
        
        
        dfs(0,0,2,1,0);
        printf("%d\n",min_dis);
    }
    return 0;
    
}
