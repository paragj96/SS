#include<stdio.h>
typedef struct Xodel
{
    int no_rc;
    int no_rm;
    int no_rb;
    int sell_price;
}Xodel;
Xodel model[9];
int c,m,b,pc,pm;
int max_ans=0;
int possible(int m,int rc,int rm,int rb)
{
    if(model[m].no_rc>rc)
     return 0;
    if(model[m].no_rm>rm)
     return 0; 
    if(model[m].no_rb>rb)
     return 0;
    return 1;  
}
void dfs(int m1,int m2,int m3,int ans,int index,int rc,int rm,int rb)
{
    if(index==3)
    {
        ans+=rc*pc+rm*pm;
        if(ans>max_ans)max_ans=ans;
        return;
    }   
    int r,j;
    if(index==0)r=m1;
    if(index==1)r=m2;
    if(index==2)r=m3; 
    if(possible(r,rc,rm,rb))
        dfs(m1,m2,m3,ans+model[r].sell_price,index,rc-model[r].no_rc,rm-model[r].no_rm,rb-model[r].no_rb);///waha hai aur kha liye
    dfs(m1,m2,m3,ans,index+1,rc,rm,rb);                       ///bina khaye aage badh gaye
 return;
}
void dfs2(int m1,int m2,int ans,int index,int rc,int rm,int rb)
{
    if(index==2)
    {
        ans+=rc*pc+rm*pm;
        if(ans>max_ans)max_ans=ans;
        return;
    }   
    int r,j;
    if(index==0)r=m1;
    if(index==1)r=m2;
    //if(index==2)r=m3; 
    if(possible(r,rc,rm,rb))
        dfs2(m1,m2,ans+model[r].sell_price,index,rc-model[r].no_rc,rm-model[r].no_rm,rb-model[r].no_rb);///waha hai aur kha liye
    dfs2(m1,m2,ans,index+1,rc,rm,rb);                       ///bina khaye aage badh gaye
 return;
}

void dfs1(int m1,int ans,int index,int rc,int rm,int rb)
{
    if(index==1)
    {
        ans+=rc*pc+rm*pm;
        if(ans>max_ans)max_ans=ans;
        return;
    }   
    int r,j;
    if(index==0)r=m1;
    //if(index==1)r=m2;
    //if(index==2)r=m3; 
    if(possible(r,rc,rm,rb))
        dfs1(m1,ans+model[r].sell_price,index,rc-model[r].no_rc,rm-model[r].no_rm,rb-model[r].no_rb);///waha hai aur kha liye
    dfs1(m1,ans,index+1,rc,rm,rb);                       ///bina khaye aage badh gaye
 return;
}





int main(void)
{ 
    int t;
    scanf("%d",&t);
    while(t--){
        int n,s;
        max_ans=0;
        scanf("%d",&c);
        scanf("%d",&m);
        scanf("%d",&b);
        scanf("%d",&pc);
        scanf("%d",&pm);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s);model[i].no_rc=s;
            scanf("%d",&s);model[i].no_rm=s;
            scanf("%d",&s);model[i].no_rb=s;
            scanf("%d",&s);model[i].sell_price=s;        
        }
        if(n>2){
            for(int i=0;i<n-2;i++)
               for(int j=i+1;j<n-1;j++)
                  for(int k=j+1;k<n;k++)
                   dfs(i,j,k,0,0,c,m,b);
        }
        if(n==2){
            dfs2(0,1,0,0,c,m,b);
        }
        if(n==1){
            dfs1(0,0,0,c,m,b);
        }
        if(n==0){
            max_ans=c*pc+m*pm;
        }


        printf("%d\n",max_ans);
    }
    return 0;
}