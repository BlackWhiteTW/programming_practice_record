    #include <bits/stdc++.h>
    using namespace std;

    int main() 
    {
        int t;
        scanf("%d", &t);
        long long a, b, ans , k;
    
        while (t--) 
        {         
            scanf("%lld %lld", &a, &b);
    
            if ( a % 2 == 0 && b % 2 == 1 )
            {
                printf("-1\n");
                continue;
            }

            if ( b % 2 == 0 && ( a * b ) % 2 == 0 )
                ans = a *  b / 2  + 2 ;
            else if ( b % 2 == 1 && a % 2 == 1 )
                ans = a * b + 1 ;
            else
            {
                for ( k = 3 ; k <= sqrt(b); k += 2)
                {
                    if ( b % k != 0 )
                    {
                        ans = a * b / k  + k ;
                        break;
                    }
                }
            }
    
            if ( ans % 2 != 0 )
                ans = -1;
            printf("%lld\n", ans);
        }
        
        return 0;
    }