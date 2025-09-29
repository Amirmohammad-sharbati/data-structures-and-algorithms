#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int q, n;
    cin >> q;
    long long int sum_p_in_stack = 0;

    for (int k = 0; k < q; k++) {
        cin >> n;
        vector<long long int> h(n), p(n), s(n);
        vector<long long int> x(n, 0); // x is the sum of power of people who can attack soldier.
        for (int i = 0; i < n; i++)
            cin >> h[i] >> s[i] >> p[i];

        vector<int> stack; // this is the stack of soldiers which are higher than their previous soldiers.
        for (int i = 0; i < n; i++) { // iteration from right to left => we need another iteration from left
            x[i] += sum_p_in_stack;  // All soldiers in stack attack this soldier which adds to stack
            while (!stack.empty() && h[stack.back()] < h[i]) {
                sum_p_in_stack -= p[stack.back()];
                stack.pop_back();
            }
            stack.push_back(i);
            sum_p_in_stack += p[i];
        }
        stack.clear();
        sum_p_in_stack = 0;

        for (int i = n-1; i >=0 ; i--) {
            x[i] += sum_p_in_stack;
            while (!stack.empty() && h[stack.back()] < h[i]) {
                sum_p_in_stack -= p[stack.back()];
                stack.pop_back();
            }
            stack.push_back(i);
            sum_p_in_stack += p[i];
        }
        stack.clear();
        sum_p_in_stack = 0;

        for (int i = 0; i < n; i++) {
            double result = ceil((double) (s[i]) / (double) (x[i]));
            cout << (long)result << " ";
        }
        cout << "\n";
    }

    return 0;
}