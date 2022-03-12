// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

class Solution
{
public:
    int checkMirrorTree(int n, int e, int A[], int B[])
    {
        stack<int> s;
        queue<int> q;
        int root1 = A[0], root2 = B[0], prev1, prev2;
        for (int i = 0; i < 2 * e; i += 2)
        {
            root1 = A[i];
            root2 = B[i];
            if (root1 != prev1 && prev1 == prev2)
            {
                while (!s.empty())
                {
                    if (s.top() != q.front())
                        return 0;
                    s.pop();
                    q.pop();
                }
            }
            s.push(A[i + 1]);
            q.push(B[i + 1]);
            prev1 = root1;
            prev2 = root2;
        }
        while (!s.empty())
        {
            if (s.top() != q.front())
                return 0;
            s.pop();
            q.pop();
        }
        return 1;
    }
};