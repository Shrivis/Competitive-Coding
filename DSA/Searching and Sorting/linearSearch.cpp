#include<iostream>
#include<vector>

using namespace std;

int linearSearch(vector<int> &nums, int key) {
    for (int i=0; i<nums.size(); ++i) {
        if (nums[i] == key) return i;
    }
    cout<<"Value isn't present in given array";
    exit(0);
}

// driver code
int main() {
    vector<int> arr { 1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    int n = arr.size();
    int key=5, index;
    index = linearSearch(arr, key);
    cout<<"Value found at position: "<<index+1<<endl;
    return 0;
}

// O(n) time complexity
// O(1) space complexity