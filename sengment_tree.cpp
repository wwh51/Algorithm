/*
 * Problem: 售票系统
 * Author: Guo Jiabao
 * Time: 2009.3.20 20:51
 * State: Solved
 * Memo: 线段树修改区间 优化
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
const int MAXN=60001;
using namespace std;
struct sgt_node
{
    sgt_node *left,*right;
    int a,b,m,v,add;
};
int N,LIM,Q,SS=-1;
sgt_node *sgt_root,SE[MAXN*2];
inline sgt_node* sgt_new(int a,int b)
{
    SE[++SS].m=(a+b)/2;
    SE[SS].a=a;SE[SS].b=b;
    SE[SS].add=SE[SS].v=0;
    SE[SS].left=SE[SS].right=0;
    return &SE[SS];
}
void sgt_create(sgt_node *&p,int a,int b)
{
    p=sgt_new(a,b);
    if (a!=b)
    {
        sgt_create(p->left,a,p->m);
        sgt_create(p->right,p->m+1,b);
    }
}
void sgt_movedown(sgt_node *p)
{
    p->v+=p->add;
    if (p->a!=p->b)
    {
        p->left->add+=p->add;
        p->right->add+=p->add;
    }
    p->add=0;
}
void sgt_edit(sgt_node *p,int a,int b,int delta)
{
    if (p->a==a && p->b==b)
    {
        p->add+=delta;
        sgt_movedown(p);
    }
    else
    {
        sgt_movedown(p->left);
        sgt_movedown(p->right);
        if (b<=p->m)
            sgt_edit(p->left,a,b,delta);
        else if (a>=p->m+1)
            sgt_edit(p->right,a,b,delta);
        else
        {
            sgt_edit(p->left,a,p->m,delta);
            sgt_edit(p->right,p->m+1,b,delta);
        }
        p->v=(p->left->v > p->right->v)?p->left->v:p->right->v;
    }
}
bool sgt_find(sgt_node *p,int a,int b,int delta)
{
    if (p->add)
        sgt_movedown(p);
    if (p->a==a && p->b==b)
        return p->v+delta<=LIM;
    if (b<=p->m)
        return sgt_find(p->left,a,b,delta);
    if (a>=p->m+1)
        return sgt_find(p->right,a,b,delta);
    if (!sgt_find(p->left,a,p->m,delta))
        return false;
    else
        return sgt_find(p->right,p->m+1,b,delta);
}
void init()
{
    freopen("railway.in","r",stdin);
    freopen("railway.out","w",stdout);
    scanf("%d%d%d",&N,&LIM,&Q);
    sgt_create(sgt_root,1,N);
}
void solve()
{
    int i,a,b,c;
    for (i=1;i<=Q;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        b--;
        if (sgt_find(sgt_root,a,b,c))
        {
            sgt_edit(sgt_root,a,b,c);
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
}
int main()
{
    init();
    solve();
    return 0;
}
