/*
If we want to comeback from where we started then definitely steps move forward = steps moved backwards
Total steps moves done from a index (forward or backward) can be found out from the array value at that index
Following observations help in making a conclusion:
1. We only need to analyse the array till the last index which has value non zero
2. Sum of prefixes at any index less than last index should be greater than zero, because equal to zero means your backward and forward movements have been equal that is you are back to index 1 before reaching last index, and less than zero means you have moved more backwards than forwards which is impossible.
3. Sum of prefixes at last index should be equal to zero becuase we want number of moves forward = number of moves backward at last index.
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
        long long n;
        cin >> n;
        vector<long long> a(n);

        // We first find the last index, we inital our variable with -1 so that if all the values of array are 0 then we dont need to perform any moves.
        long long last_ind = -1;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] != 0)
                last_ind = i;
        }
        if (last_ind == -1)
        {
            cout << "Yes\n";
            return 0;
        }

        // Iterate through array till last index while tracking prefix sum
        long long sum{0};
        bool ok = true;
        for(int i = 0; i <= last_ind; i++)
        {
            sum += a[i];

            // Check if sum <= 0 before last index
            if (i != last_ind && sum <= 0)
                ok = false;

            // Check if sum = 0 at last index
            if (i == last_ind && sum != 0)
                ok = false;
        }

        // If everything is ok then yes else no
        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}