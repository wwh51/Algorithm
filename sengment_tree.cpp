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

/*
strong>【问题描述】</strong>
某次列车途经C个城市，城市编号依次为1到C，列车上共有S个座位，铁路局规定售出的车票只能是坐票， 即车上所有的旅客都有座。售票系统是由计算机执行的，每一个售票申请包含三个参数，分别用O、D、N表示，O为起始站，D为目的地站，N为车票张数。售票 系统对该售票申请作出受理或不受理的决定，只有在从O到D的区段内列车上都有N个或N个以上的空座位时该售票申请才被受理。请你写一个程序，实现这个自动 售票系统。
<p align="left">【输入格式】
第一行包含三个用空格隔开的整数C、S和R，其中1≤C≤60000， l≤S≤60000，1≤R≤60000。C为城市个数，S为列车上的座位数，R为所有售票申请总数。接下来的R行每行为一个售票申请，用三个由空格隔开 的整数O，D和N表示，O为起始站，D 为目的地站，N为车票站数，其中1≤D≤C，1≤O≤C，所有的售票申请按申请的时间从早到晚给出。

【输出格式】
输出共有R行，每行输出一个“YES”或“NO”，表示当前的售票申请被受理或不被受理。

【输入输出样例】
<strong>
</strong>输入:
4 6 4
1 4 2
1 3        2
2 4 3
1 2  3

输出:
YES
YES
NO
NO</div>

*/
