#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n,ans=1;
    char tmp = ' ';
    cin>>n;
    
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if (s[0]==tmp) ans++;
        tmp=s[1];
    }
    
    cout<<ans;

    return 0;
}

