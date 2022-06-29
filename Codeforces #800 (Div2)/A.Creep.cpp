/*
Since the number of zero's and one's cancel each other we can come on to a conclusion that pairs like "00" and "11" will increase the answer as creepiness of these two strings in 2 while strings like "01" and "10" will decrease the answer as one and zero cancel each other so creepiness of these strings is 1.
So we can make our answer string in such a fashion that it has maximum number of "01" (or "10") type of pairs.
We can do this by alternating insertion of 0 and 1 from the total number of zeros and ones that we have and then we will insert whatever is left from either of them.
To decrease runtime you dont need to make an answer string, just print them in the desired fashion.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int all_test_cases;
    cin >> all_test_cases;
    for (int each_test_case = 1; each_test_case <= all_test_cases; each_test_case++)
    {

        // User input
        int a, b;
        cin >> a >> b;

        // Inserting 0 and 1 alternatively starting from 1
        for (int i = 1; a > 0 && b > 0; i++)
        {

            // if we have odd index insert 1
            if (i % 2 == 1)
            {
                cout << 1;
                --b;
            }

            // at even index insert 0
            else
            {
                cout << 0;
                --a;
            }
        }

        // if zeros are left we insert them at the end
        while (a > 0)
        {
            cout << 0;
            --a;
        }
        // if ones are left we insert them at the end
        while (b > 0)
        {
            cout << 1;
            --b;
        }
        cout << '\n';
    }

    return 0;
}