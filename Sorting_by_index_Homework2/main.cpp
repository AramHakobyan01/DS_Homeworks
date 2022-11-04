#include <iostream>
#include <vector>

std::vector<int> IndexSort(const std::vector<int> arr) {
    std::vector<int> temp = arr;
    for(int j = 0; j < temp.size(); j++) {
        int count = 0;
        for (int i = j + 1; i < temp.size(); i++) {
            if (temp[j] > temp[i]) {
                count = temp[i];
                temp[i] = temp[j];
                temp[j] = count;
            }
        }
    }
    for(int& j : temp) {
        for (int i = 0; i < arr.size(); i++) {
            if (j == arr[i]) {
                j = i;
            }
        }
    }
    return temp;
}

int main() {
    std::vector<int> arr;
    int size;
    std::cin >> size;
    for(int i = 0, j = 0; i < size; i++) {
        std::cin >> j;
        arr.push_back(j);
    }
    arr = IndexSort(arr);
    for(auto i : arr) {
        std::cout << i << " ";
    }
    return 0;
}
