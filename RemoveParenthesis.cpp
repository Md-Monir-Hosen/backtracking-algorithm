#include<bits/stdc++.h>
using namespace std;
bool isParenthesis(char c)
{
   return ((c=='(')||(c==')'));
}
bool isValidString(string s)
{
    int cnt;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            cnt++;
        }
        else if(s[i]==')')
        {
            cnt--;
        }
        if(cnt<0)
        {
            return false;
        }
    }
    return (cnt==0);
}
void validRemoveParenthesis(string s)
{
    if(s.empty())
    {
        return;
    }
    unordered_set<string>visit;
    queue<string>q;
    string temp;
    bool label;
    q.push(s);
    visit.insert(s);
    while(!q.empty())
    {
     s = q.front();
     q.pop();
     if(isValidString(s))
     {
        cout<<s<<"\n";
        label=true;
     }
     if(label)
     {
         continue;
     }
     for(int i=0;i<s.length();i++)
     {
         if(isParenthesis(s[i]))
         {
           continue;
         }
         temp=s.subset(0,i)+s.subset(i+1);
         if(visit.find(temp)==visit.end())
         {
           q.push(temp);
           visit.insert(temp);
         }
     }
    }
}
int main()
{
     string expression = "()())()";
    validRemoveParenthesis(expression);

    expression = "()v)";
    validRemoveParenthesis(expression);

    return 0;
}
