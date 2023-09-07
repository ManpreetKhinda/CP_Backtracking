#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(vector<int>& arr, int x, vector<int>& current_combination, vector<vector<int>>& result, int start) {
    if (x == 0) {
        // Found a combination that sums up to x
        result.push_back(current_combination);
        return;
    }

    for (int i = start; i < arr.size(); i++) {
        if (arr[i] > x) {
            // Remaining elements are greater than remaining sum, so no need to continue
            break;
        }

        current_combination.push_back(arr[i]);
        findCombinations(arr, x - arr[i], current_combination, result, i);  // Recursive call
        current_combination.pop_back();
    }
}

vector<vector<int>> getCombinations(vector<int>& arr, int x) {
    sort(arr.begin(), arr.end());  // Sort the array in non-descending order
    vector<vector<int>> result;
    vector<int> current_combination;
    findCombinations(arr, x, current_combination, result, 0);
    return result;
}

int main() {
    vector<int> arr = {2, 4, 6, 8};
    int x = 8;

    vector<vector<int>> combinations = getCombinations(arr, x);

    if (combinations.empty()) {
        cout << "Empty" << endl;
    } else {
        for (const auto& combination : combinations) {
            for (int i : combination) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
