/*
Xor of equal numbers is zero.
Hence the xor of array containing element 'x' will be zero
So we know two things:
1. Xor of array containing 'x' will be zero.
2. Xor of array not containing 'x' is equal to x.
Also, let's say we have an array arr and the xor of array is XOR, so if we xor any element (say a[i]) of arr with XOR the result will be xor of elements of arr except for a[i].
Idea: if we xor element 'x' with the xor of whole array i.e. 0 then the answer will be 'x' only!
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int total_test_cases;
    cin >> total_test_cases;
    for(int test_case_number = 1; test_case_number <= total_test_cases; test_case_number++){

        int number_of_elements;
        cin >> number_of_elements;

        // Let XOR be the xor of each element with 0
        int XOR,answer;
        vector<int> arr(number_of_elements);
        for(int &element_of_array: arr){
            cin >> element_of_array;
            XOR = 0 ^ element_of_array;

            // if we find an element for which XOR = that element then that is our answer
            if(XOR == element_of_array){
                answer = element_of_array;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}