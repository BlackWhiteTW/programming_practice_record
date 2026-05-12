#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    cin.ignore();

    for (int i = 0; i < k; i++)
    {
        string line;
        getline(cin, line);

        vector<string> cards;
        stringstream ss(line);
        string card;
        while (ss >> card)
        {
            cards.push_back(card);
        }

        // 排序：花色優先（S > H > D > C），然後數字由大到小
        sort(cards.begin(), cards.end(), [](const string &a, const string &b)
             {
            // 花色優先
            map<char, int> suitOrder = {{'S', 0}, {'H', 1}, {'D', 2}, {'C', 3}};
            map<char, int> rankOrder = {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
                                        {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'0', 10},
                                        {'J', 11}, {'Q', 12}, {'K', 13}};
            
            int aSuit = suitOrder[a[0]];
            int bSuit = suitOrder[b[0]];
            
            if (aSuit != bSuit) return aSuit < bSuit;
            
            // 花色相同，比較數字
            char aRank = a[1];
            char bRank = b[1];
            int aRankVal = (aRank == '0') ? 10 : rankOrder[aRank];
            int bRankVal = (bRank == '0') ? 10 : rankOrder[bRank];
            
            return aRankVal > bRankVal; });

        // 輸出排序結果
        for (int j = 0; j < cards.size(); j++)
        {
            if (j > 0)
                cout << " ";
            cout << cards[j];
        }
        cout << endl;
    }

    return 0;
}
