#include <stdio.h>

int toll_cost[22], toll_person[22];
int n;
int min_cost = 500000;

void dfs(int pos, int bp3, int bp2, int bp1, int ans)
{
    int total = bp3+bp2+bp1;
    if(ans>min_cost)
        return;

    if(pos==n-1) 
    {
        if(total<toll_person[pos]) ans+=toll_cost[pos];     // Can't Battle
        if(ans<min_cost) min_cost=ans;
        return;
    }
    dfs(pos+1,bp3,bp2,bp1,ans+toll_cost[pos]);   // Toll pay option
    dfs(pos+1,bp3+toll_person[pos],bp2,bp1,ans+(2*toll_cost[pos]));  //Toll Hire Option
    
    if(total>=toll_person[pos])  //Toll BAttle Option
    {
        if(toll_person[pos]<=bp1+bp2 && toll_person[pos]>bp1)
        {
            bp2=bp2-(toll_person[pos]-bp1);
        }
        else if(toll_person[pos]>bp1+bp2)
        {
            bp3=bp3-((toll_person[pos]-bp2)-bp1);      
            bp2=0;      
        }
        dfs(pos+1,0,bp3,bp2,ans);
    }
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        min_cost=500000;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            
            scanf("%d",&toll_person[i]);
            scanf("%d",&toll_cost[i]);
        }
        dfs(0,0,0,0,0);
        printf("%d\n",min_cost);
    }
    return 0;
}