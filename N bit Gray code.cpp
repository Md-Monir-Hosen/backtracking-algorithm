#include<bits/stdc++.h>
using namespace std;
void Graycodeutil(vector<int>&res,int n,int& num)
{
    if(n==0)
    {
        res.push_back(num);
        return;
    }
    Graycodeutil(res,n-1,num);
    num=num^(1<<(n-1));
    Graycodeutil(res,n-1,num);
}
vector<int>Graycode(int n)
{
    vector<int>res;
    int num=0;
    Graycodeutil(res,n,num);
    return res;
}
int main()
{
    int n = 3;
    vector<int> code = Graycode(n);
    for (int i = 0; i < code.size(); i++)
        cout << code[i] << endl;
    return 0;
}
