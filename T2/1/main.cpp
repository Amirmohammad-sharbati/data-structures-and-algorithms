#include <iostream>
#include <vector>

using namespace std;

void insert_maxHeap(int a, vector<int> &heap) {
    heap.push_back(a);
    int index = heap.size() - 1;
    while (heap[(index-1) / 2] < heap[index]) {
        swap(heap[(index-1) / 2], heap[index]);
        index = (index-1) / 2;
    }
}

void insert_minHeap(int a, vector<int> &heap) {
    heap.push_back(a);
    int index = heap.size() - 1;
    while (heap[(index-1) / 2] > heap[index]) {
        swap(heap[(index-1) / 2], heap[index]);
        index = (index-1) / 2;
    }
}

void delete_root_minHeap(vector<int> &heap) {
    int i = 0;
    int n = heap.size();
    heap[0] = heap[n - 1];
    heap.pop_back();
    n--;
    while (2 * i + 1 < n && (heap[i] > heap[2 * i + 1] || heap[i] > heap[2 * i + 2])) {
        if (2 * i + 2 == n || heap[2 * i + 1] < heap[2 * i + 2]) {
            swap(heap[i], heap[2 * i + 1]);
            i = 2 * i + 1;
        } else {
            swap(heap[i], heap[2 * i + 2]);
            i = 2 * i + 2;
        }
    }
}

void delete_root_maxHeap(vector<int> &heap) {
    int i = 0;
    int n = heap.size();
    heap[0] = heap[n - 1];
    heap.pop_back();
    n--;
    while (2 * i + 1 < n && (heap[i] < heap[2 * i + 1] || heap[i] < heap[2 * i + 2])) {
        if (2 * i + 2 == n || heap[2 * i + 1] > heap[2 * i + 2]) {
            swap(heap[i], heap[2 * i + 1]);
            i = 2 * i + 1;
        } else {
            swap(heap[i], heap[2 * i + 2]);
            i = 2 * i + 2;
        }
    }
}

int main() {
    int q;
    cin >> q;
    long long int sum_b = 0;
    long long int sum_a = 0;
    int input_type;
    int a, b, len_a = 0;

    int prev_median = 0, median_a = 0;
    // We have two kinds of heaps: max heap for left half of median and min heap for right half.
    vector<int> left_heap;
    vector<int> right_heap;
    int ls = 0, rs = 0; // left heap size and right heap size

    for (int i = 0; i < q; i++) {
        cin >> input_type;
        if (input_type == 1) {
            cin >> a >> b;
            sum_b += b;
            len_a++;

            if (a <= median_a) {
                insert_maxHeap(a, left_heap);
                ls++;
            } else {
                insert_minHeap(a, right_heap);
                rs++;
            }

            if (ls - rs == 2) { // we should delete the root of left heap and add it to right one
                insert_minHeap(left_heap[0], right_heap);
                delete_root_maxHeap(left_heap);
                rs++;
                ls--;
            } else if (rs - ls == 2) {
                insert_maxHeap(right_heap[0], left_heap);
                delete_root_minHeap(right_heap);
                rs--;
                ls++;
            }

            prev_median = median_a;
            if (ls == rs || ls - rs == 1)
                median_a = left_heap[0];
            else if (rs - ls == 1)
                median_a = right_heap[0];

            if (len_a > 1) {
                if (len_a % 2 == 1) {
                    if (a <= prev_median) sum_a += median_a - a;
                    else sum_a += a - median_a;
                } else {
                    if (a >= prev_median) sum_a += a - median_a;
                    else sum_a += prev_median - a;
                }
            }
        } else cout << median_a << " " << sum_a + sum_b << "\n";
    }

    return 0;
}
