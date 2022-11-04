#include <iostream>

char FirstElement(char arr[], int size) {
    unsigned int x = 0;
    char temp[size];
    int count = size - 1;
    for(int i = 0; i < size; i++) {
        if(x & (1 << (arr[i] - 'a'))) {
            //return arr[i];
            temp[count] = arr[i];
            count--;
        }
        x |= (1 << (arr[i] - 'a'));
    }
    if(count != size) {
        for(int i = 0, j = count + 1; i < size; i++) {
            if(arr[i] != temp[j]) {
                return arr[i];
            }
            if(j == size - 1) {
                return arr[i + 1];
            }
            j++;
        }
    }
    return '_';
}

int main() {
    const int n = 100000;
    char arr[n];
    int size;
    std::cin >> size;
    for(int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    std::cout << FirstElement(arr, size);
    return 0;
}
