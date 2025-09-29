#include <algorithm> // This is for binary search (like bisect in python)
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int numbers[n];
    unordered_map<int, vector<int>> number_to_its_indecis;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers[i] = num;
        number_to_its_indecis[num].push_back(i + 1);
    }

    // random index generatation
    random_device rd;
    mt19937 gen(rd());
    // Mersenne Twister (mt19937) is an excellent choice for random number generation
    // due to its high-quality randomness and fast performance.

    for (int i = 0; i < q; i++) {
        bool find = false;
        int l, r;
        cin >> l >> r;
        int half_len = (r - l + 1) / 2;
        uniform_int_distribution<> dis(l - 1, r - 1);
        // Uniform distribution(uniform_int_distribution<>) ensures that
        // each number between l and r has an equal probability of being selected.

        for (int j = 0; j < 17; j++) {
            int index = dis(gen);
            int number = numbers[index];
            vector<int> &indices = number_to_its_indecis[number];

            // Equivalent to bisect_left: Find the first position where index >= l
            auto left_it = lower_bound(indices.begin(), indices.end(), l);
            int left_index = left_it - indices.begin(); // Convert iterator to index

            // Equivalent to bisect_right: Find the first position where index < r
            auto right_it = upper_bound(indices.begin(), indices.end(), r);
            int right_index = right_it - indices.begin(); // Convert iterator to index

            if (half_len < right_index - left_index) {
                cout << number << "\n";
                find = true;
                break;
            }
        }
        if (!find) cout << 0 << "\n";
    }
}
