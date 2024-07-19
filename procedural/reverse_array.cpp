#include <iostream>

void reverse_array(int* arr, int size);

int main() {
    int array[] = {1, 3, 5, 2};
    reverse_array(array, 4);

    for (int i = 0; i < 4; i ++){
        std::cout << array[i] << std::endl; 
    }
    return 0;
}

void reverse_array(int* arr, int size){
    for (int i = 0; i < size / 2; i++){
        int temp = *(arr + i);
        *(arr + i) = *(arr + (size - 1 - i));
        *(arr + (size - 1 - i)) = temp;
    }
}