#include<bits/stdc++.h>
using namespace std;
int main()
{
          string s1="bdcaba";
          string s2="abcbda";
          int len1=s1.length();
          int len2=s2.length();
          vector<vector<int>> arr(len1+1,vector<int>(len2+1,0));
          for(int i=1;i<len1+1;i++)
          {
                    for(int j=1;j<len2+1;j++)
                    {
                              if(s2[i-1]==s1[j-1])
                              {
                              
                                        arr[i][j]=max(arr[i-1][j-1]+1,arr[i-1][j]);
                              }
                              else
                              {
                                        arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
                              }
                    }
          }
          for(int i=0;i<len1+1;i++)
          {
                    for(int j=0;j<len2+1;j++)
                    {
                              cout<<arr[i][j]<<" ";
                    }
                    cout<<endl;
          }
          int i=len1,j=len2;
          string ans="";
          while(i>=0&&j>=0)
          {
                    if(arr[i][j]!=arr[i][j-1])
                    {
                              ans=ans+s1[j-1];
                              --i;
                              --j;
                    }
                    else
                    {
                              --j;
                    }
                    if(arr[i][j]==0)
                    break;
          }
          reverse(ans.begin(),ans.end());
          cout<<ans<<endl;
}
