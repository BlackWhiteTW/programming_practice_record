# 我的Python過不了 最後還是用C++了 C++還是有被優化才過的 不喜歡這題目

def generate(n, left=0, right=0, s=""):
    if left == n and right == n:
        yield s
    if left < n:
        yield from generate(n, left + 1, right, s + '(')
    if right < left:
        yield from generate(n, left, right + 1, s + ')')

while True:
    try:
        n = int(input())
        print('\n'.join(generate(n)))
        print()
    except EOFError:
        break


"""
#include <cstdio>
#include <string>

void generate(int n, int left, int right, std::string &s)
{
    if (left == n && right == n)
    {
        printf("%s\n", s.c_str());
        return;
    }

    if (left < n)
    {
        s.push_back('(');
        generate(n, left + 1, right, s);
        s.pop_back();
    }

    if (right < left)
    {
        s.push_back(')');
        generate(n, left, right + 1, s);
        s.pop_back();
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        std::string s;
        generate(n, 0, 0, s);
        printf("\n");
    }

    return 0;
}
"""