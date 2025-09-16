#include <bits/stdc++.h>

int main()
{
    char again = 'y';
    while ( again == 'y')
    {
        int a , b ;
        cout << "Number 1:";
        cin >> a;
        cout << "Number 2:";
        cin >> b;
        if ( a > b )
        {
            cout << "Error!! Number 1 > Number 2\n";
            continue;
        }
        int sum = 0;
        for ( int i = a; i <= b; i++)
        {
            sum += i;
        }
        cout << "Sum = " << sum << endl;
        cout << "Again? (Y/N):";
        cin >> again;
        if ( again >= 'A' && again <= 'Z' )
            again += 'a' - 'A';
    }

    system("pause");
    return 0;
}