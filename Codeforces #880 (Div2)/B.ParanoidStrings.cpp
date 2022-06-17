/*
Notice that any string that ends with "01" or "10" can become paranoid
So we dont need strings that end with "00" or "11"
So any index that has 1 on it an 0 immediately before it (or vice versa) is an index at which a paranoid string ends and all the indexes before it also contribute to that paranoid string.
Hence we can conclude that if we find such an index we should add the number of elements present before it in our answer.
Also, we must add the length of string in our answer because every character is a paranoid string.
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
        long long length_of_string;
        cin >> length_of_string;
        string s;
        cin >> s;

        // Initialise answer with length of string
        long long ans = length_of_string;
        for (int i = 1; i < length_of_string; i++)
        {
            // Adding the number of elements before the desired index, when we find any such index
            if (s[i] != s[i - 1])
            {
                ans += i;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}