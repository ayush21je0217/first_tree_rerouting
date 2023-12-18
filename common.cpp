#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
#define ninf -1e18
#define p_b push_back
#define frl(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i>=b;i--)
#define min_pq priority_queue<int,vi ,greater<int>>
#define min_pq_of_pair priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
#define max_pq priority_queue<int>
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>
#define vvvvi vector<vector<vector<vector<int> >>>
#define print(x) cout<<x<<"\n";
void output(vi &v,int n,int a,int b)
{
for(int i=a;i<=b;i++)cout<<v[i]<<" ";
cout<<"\n";
}


void pre_cal(int node,vi g[],int par,vi &cost,vi &sum,vi &val)
{
    sum[node]=val[node];
    for(auto it:g[node])
    {
        if(it==node)continue;
        pre_cal(it,g,node,cost,sum,val);
        sum[node]+=sum[it];
        cost[node]+=sum[it]+cost[it];
    }
}
void dfs(int node,vi g[],int par,vi &cost,vi &sum,vi &val,int &ans)
{
    ans=max(ans,cost[node]);
    for(auto it:g[node])
    {
        if(it==par)continue;
        int newcost=cost[node]-cost[it]-sum[it];
        cost[it]+=newcost+sum[node]-sum[it];
        sum[it]=sum[node];
        dfs(it,g,node,cost,sum,val,ans);
    }
}
void s()
{
    int n;
    cin>>n;
    vi val(n+1);
    frl(i,1,n+1)cin>>val[i];
    vi g[n+1];
    frl(i,0,n-1)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi cost(n+1,0),sum(n+1,0);
    int ans=0;
    pre_cal(1,g,0,cost,sum,val);
    dfs(1,g,0,cost,sum,val,ans);
    print(ans);
}
int32_t main()
{
int t=1;
// cin>>t;
while(t--)s();
}


