#include <iostream>
#include <vector>

bool is_non_decreasing(const std::vector<int> &v, int start, int end) {
    for (int i = start; i < end; ++i) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}

bool is_non_increasing(const std::vector<int> &v, int start, int end) {
    for (int i = start; i < end; ++i) {
        if (v[i] < v[i + 1]) {
            return false;
        }
    }
    return true;
}

bool is_bitonic(const std::vector<int> &v) {
    int n = v.size();
    if (n < 3) {
        return true; // Less than 3 elements are always bitonic
    }

    // Find the peak
    int peak = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i] > v[peak]) {
            peak = i;
        }
    }

    // Check if the sequence is bitonic by splitting at the peak
    if (is_non_decreasing(v, 0, peak) && is_non_increasing(v, peak, n - 1)) {
        return true;
    }

    // Check for circular shift
    // This requires checking if the array can be split into a bitonic sequence
    // with a single rotation point
    for (int shift = 1; shift < n; ++shift) {
        if (is_non_decreasing(v, shift, (shift + peak) % n) && 
            is_non_increasing(v, (shift + peak) % n, (shift - 1 + n) % n)) {
            return true;
        }
    }

    return false;
}

int main() {
    // std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    // std::vector<int> myvec = {1, 1, 1, 1, 1};  // Yes
    // std::vector<int> myvec = {3, 4, 5, 2, 2};  // Yes
    std::vector<int> myvec = {3, 4, 5, 2, 4};  // No
    // std::vector<int> myvec = {1, 2, 3, 4, 5};  // Yes
    // std::vector<int> myvec = {1, 2, 3, 1, 2};  // No
    // std::vector<int> myvec = {5, 4, 6, 2, 6};  // No
    // std::vector<int> myvec = {5, 4, 3, 2, 1};  // Yes
    // std::vector<int> myvec = {5, 4, 3, 2, 6};  // Yes
    // std::vector<int> myvec = {5, 4, 6, 5, 4};  // No
    // std::vector<int> myvec = {5, 4, 6, 5, 5};  // Yes

    std::cout << (is_bitonic(myvec) ? "Yes, it is bitonic." : "No, it is not bitonic.");
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
