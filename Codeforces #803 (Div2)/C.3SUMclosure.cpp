/*
There are very few cases for which the answer is yes.
Observations:
1. If number of positive number is array are equal to or more than 3 then we can add the greatest of them to any other two positive numbers and the result will not be in the array
2. If there are more than 2 negative number than we can add the lowest of them to two other negative numbers and the result will not be in the array
3. If a zero is present then we will need a minimum of 2 positive or negative numbers to satisfy above points
So now that leaves us with following conclusion:
1. if a zero is present then number of positive or negative number has to be one
2. if a zero is not present then number of positive or negative number has to be less than two
In the worst case scene of conclusion 2 the size of array will be 4 so we can do brute force.
*/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    // Here positive is the number of positive numbers
        // negative is the number of negative numbers
        // zero is the number of zeros
        int n,positive{0},negative{0},zero{0};
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 0){
                ++zero;
            } else{
                a[i] > 0 ? ++positive : ++negative;
            }
        }

        // Checks:
        if(positive == 0 && negative == 0){
            cout << "YES\n";
            return;
        }
        if(positive >= 3 || negative >= 3){
            cout << "NO\n";
            return;
        }
        if(zero && (positive > 1 || negative > 1)){
            cout << "NO\n";
            return;
        }

        // Sort the array so that all the positive numbers and negative numbers are on opposite side
        // It will help us in implementing our conclusions.
        sort(a.begin(),a.end());
        if(zero){
            // We sum the lowest number (posibly negative) and the larget number (posibly positive)
            long long sum = a[0]+a[n-1];

            // as we have only 3 kinds of numbers:
            // largest, lowest and zero
            // we can just check if the sum is equal to any of them
            if(sum == 0 || sum == a[0] || sum == a[n-1]){
                cout << "YES\n";
            } else{
                cout << "NO\n";
            }
        } else{
            // Here we can just apply brute force
            // There might be better ways to do this!
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    for(int k = j+1; k < n; k++){
                        // we find all posible sum and simply binary search them in the array
                        long long sum = a[i]+a[j]+a[k];
                        if(!binary_search(a.begin(),a.end(),sum)){
                            cout << "NO\n";
                            return;
                        }
                    }
                }
            }
            cout << "YES\n";
        }
}
int main()
{
    int total_test_cases;
    cin >> total_test_cases;
    for(int test_case_number = 1; test_case_number <= total_test_cases; test_case_number++){
        // It's easier this way!
        solve();
    }
    return 0;
}