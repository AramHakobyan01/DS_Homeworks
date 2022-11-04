#include <iostream>
#include <vector>

std::vector<int>::iterator Pivot(std::vector<int>::iterator start, std::vector<int>::iterator end){
    auto pivot = start;
    for (auto i = start; i != end; i++) {
        if (*i <= *end) {
            std::iter_swap(i, pivot);
            pivot++;
        }
    }
    std::iter_swap(pivot, end);
    return pivot;
}

void QuickSort(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    int size = std::distance(start, end);
    if (size <= 1) {
        return;
    }
    auto pivot = Pivot(start, end);
    QuickSort(start, pivot - 1);
    QuickSort(pivot, end);
}

void QuickSort(std::vector<int>& v) {
    QuickSort(v.begin(), v.end() - 1);
}

int main() {
    std::vector<int> v { 72, 23, 65, 53, 36, 90, 76, 50, 1, 20, 64, 82 };
    QuickSort(v);
    for (auto &i:v) {
        std::cout << i << " ";
    }
    return 0;
}
