#include <iostream>

void print(int* arr, std::size_t size);

int* apply_all(int* arr1, std::size_t size1, int* arr2, std::size_t size2);

int main(){
    const std::size_t array1_size {5};
    const std::size_t array2_size {3};

    int array1[] {1, 2, 3, 4, 5};
    int array2[] {10, 20, 30};

    std::cout << "Array 1: ";
    print(array1, array1_size);

    std::cout << "Array 2: ";
    print(array2, array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr std::size_t results_size {array1_size * array2_size};

    std::cout << "Result: ";
    print(results, results_size);

    std::cout << std::endl;

    return 0;
}

void print(int* arr, std::size_t size){
    std::cout << "[ ";
    for (std::size_t i = 0; i < size; i++){
        std::cout << *(arr + i) << " ";
    }
    std::cout << "]" << std::endl;
}

int* apply_all(int* arr1, std::size_t size1, int* arr2, std::size_t size2){
    int* result_arr = new int[size1 * size2];
    int count = 0;
    for (std::size_t i = 0; i < size1; i++){
        for (std::size_t j = 0; j < size2; j++){
            *(result_arr + count++) = *(arr1 + i) * *(arr2 + j);
        }
    }
    return result_arr;
}
