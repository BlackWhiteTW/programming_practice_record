#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;

    cout << "Please input a positive integer: ";
    cin >> i;

    if ( i < 1 )
        cout << i << " is not a positive integer!!" << endl;
    else if ( i < 10 )
        cout << i << " is a small integer." << endl;
    else if ( i < 100 )
    {
        cout << i << " 的十位數為 " << i / 10 << endl;
        cout << i << " 的個位數為 " << i % 10 << endl;
    }
    else
    {
        cout << i << " is a large integer." << endl;
        switch ( i % 5 )
        {
            case 0:
                cout << i << " is divisible by 5." << endl;
                break;
            case 1:
                cout << i << "+5=" << i + 5 << endl;
                break;
            case 2:
                cout << i << "-5=" << i - 5 << endl;
                break;
            case 3:
                cout << i << "*5=" << i * 5 << endl;
                break;
            case 4:
                cout << i << "/5=" << fixed << setprecision(2) << i / 5.0 << endl;
                break;
        }
    }

    system("pause");
    return 0; 
}