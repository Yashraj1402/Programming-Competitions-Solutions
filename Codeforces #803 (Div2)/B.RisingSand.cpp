/*
1. If k > 1 then we cannot change anything, because even if we increase two or more numbers by 1, the difference between them will not change.
2. We can only make a difference if k = 1.
3. We can do infinite moves.
Idea: The maximum number of too tall piles can be achieved if we increase the size of every pile present at index 'i' such that 'i' is even and a[i] > a[i-1]+a[i+1] after total increment.
So, we just increase size of all the piles present at even indices such that given condition in satisfied.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int total_test_cases;
    cin >> total_test_cases;
    for(int test_case_number = 1; test_case_number <= total_test_cases; test_case_number++){
        // User Input
        long long n,k;
        cin >> n >> k;
        vector<long long> a(n);
        for(auto &i: a) cin >> i;

        // Count the initial number of too tall piles
        long long count{0};
        for(long long i = 1; i <= n-2; i++){
            if(a[i] > a[i-1]+a[i+1]){
                ++count;
            }
        }

        // If k > 1 then we cannot do any change
        if(k > 1){
            cout << count << '\n';
        } 

        // else, total even indices are n/2 but if n is even we cannot take the last index so we don't count it
        else{
            cout << (n%2 == 0 ? n/2 - 1 : n/2) << '\n';
        }
    }
    return 0;
}