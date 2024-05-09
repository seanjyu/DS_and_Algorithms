#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to perform binary search on a sorted vector
int binarySearch(const std::vector<int>& sortedArray, int searchVal) {
    int left = 0;
    int right = sortedArray.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the searchVal is present at mid
        if (sortedArray[mid] == searchVal) {
            return mid;
        }
        if (sortedArray[mid] < searchVal) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // searchVal not found
    return -1;
}

int main() {
    std::vector<int> sortedArray = {1, 2, 3, 4, 5};

    int searchVal;
    std::cout << "Enter the number to search for: ";
    std::cin >> searchVal;

    // Perform binary search
    int index = binarySearch(sortedArray, searchVal);
    // bool found = true;

    if (index == -1) {
        std::cout << "Element found not found in the Array." << std::endl;
    } else {
        string indexString = std::to_string(index);
        std::cout << "Element found in the array at index ";
        std::cout << indexString << std::endl;
    }

    return 0;
}
