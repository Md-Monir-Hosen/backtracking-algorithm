#include<bits/stdc++.h>
using namespace std;
bool flag=0;
void printsubsetsum(int i,int n,int s[],int targetsum,vector<int>& subset)
{
if(targetsum==0)
{
      cout<<"[";
  for(int i=0;i<subset.size();i++)
  {
      cout<<subset[i]<<" ";
  }
  cout<<"]";
  return;
}
if(i==n)
{
    return ;
}
printsubsetsum(i+1,n,s,targetsum,subset);
if(s[i]<=targetsum)
{
  subset.push_back(s[i]);
  printsubsetsum(i+1,n,s,targetsum-s[i],subset);
  subset.pop_back();
}
}
int main()
{
        int set2[] = { 3, 34, 4, 12, 5, 2 };
    int sum2 = 30;
    int n2 = sizeof(set2) / sizeof(set2[0]);
    vector<int> subset2;
    cout << "Output 2:" << endl;
    printsubsetsum(0, n2, set2, sum2, subset2);
    if (!flag) {
        cout << "There is no such subset";
    }

    return 0;
}
