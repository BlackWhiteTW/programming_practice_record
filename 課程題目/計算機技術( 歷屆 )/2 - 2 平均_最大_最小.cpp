#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Please input the number of integers:";
    cin >> n;
    int a[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cout << "Integer #" << i + 1 << ":";
        cin >> a[i];
    }
        int sum = 0 , max = a[0], min = a[0];
    for ( int i = 0 ; i < n ; i++ )
    {
        sum += a[i];
        if ( a[i] > max ) max = a[i];
        if ( a[i] < min ) min = a[i];
    }
    cout << "the average is " << sum / (float)n << endl;
    cout << "the maximum is " << max << endl;
    cout << "the minimum is " << min << endl;
    
    system("pause");
    return 0;
}