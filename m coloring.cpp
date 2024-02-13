#include<bits/stdc++.h>
using namespace std;
#define V 4
void print(int color[])
{
    cout<<"solution is exists: "<<"Following are the assigned colors"<<"\n";
    for(int i=0;i<V;i++)
    {
        cout<<" "<<color[i]<<" ";
    }
    cout<<"\n";
}
bool isSafe(int v,bool graph[V][V],int color[],int c)
{
    for(int i=0;i<V;i++)
    {
        if(graph[V][i] &&c==color[i])
        {
            return false;
        }
    }
    return true;
}
bool graphcoloringutil(bool graph[V][V],int m,int color[],int v)
{
    if(v==V)
    {
        return true;
    }
    for(int c=0;c<V;c++)
    {
        if(isSafe(v,graph,color,c))
        {
            color[v]=c;
            if(graphcoloringutil(graph,m,color,v+1)==true)
            {
                return true;
            }
            color[v]=0;
        }
    }
    return false;
}
bool graphcoloring(bool graph[V][V],int m)
{
    int color[V];
    for(int i=0;i<V;i++)
    {
        color[i]=0;
    }
    if(graphcoloringutil(graph,m,color,0)==false)
    {
        cout<<"solution does not exist";
        return false;
    }
    print(color);
    return true;
}
int main()
{
     bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };

    // Number of colors
    int m = 3;

    // Function call
    graphcoloring(graph, m);
    return 0;
}
