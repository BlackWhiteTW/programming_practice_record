#include <bits/stdc++.h>

using namespace std;

int tap=0;

void hanoi(int n, char A, char B, char C)
{
    if(n == 1)
    {
        cout << A << " -> " << C << endl;
        tap++;
    }
    else
    {
        hanoi(n-1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n-1, B, A, C);
    }
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    cout << tap << endl;
}