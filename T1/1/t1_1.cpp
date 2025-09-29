#include <iostream>

using namespace std;

// output for 16 : 1 9 5 7 , 3 11 7 15 => this is first half => second half is ++ of this sequence.
// The order of program is n. 

int main() {
    int input;
    cin >> input;
    int t = 1; // This is the smallest exponent of 2 which is bigger than input(2^k>=t)
    while (t < input) t *= 2;

    int result[t];
    result[0] = 1;
    int k = t / 2; // The first half of the array is for odd numbers.

    for (int i = 1;i < k;i++) {
        if (i % 2 == 1)
            result[i] = result[i - 1] + k;
        else result[i] = (result[0] + result[i / 2]) / 2;
    }
    for (int i = k;i < t;i++)
        result[i] = result[i - t / 2] + 1;

    for (int i = 0;i < t;i++) {
        if (result[i] <= input)
            cout << result[i] << " ";
    }
    return 0;
}
