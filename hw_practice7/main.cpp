
#include <iostream>
#include <set>
#include <string>

void calculateSum(const int* arr, int size, int& sum) {
    sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
}

void countPositive(const int* arr, int size, int& count) {
    count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
}

void findArrayWithMaxPositive(const int* arrA, const int* arrB, int size) {
    int countA = 0, countB = 0;

    countPositive(arrA, size, countA);
    countPositive(arrB, size, countB);

    if (countA > countB) {
        std::cout << "Массив A имеет больше положительных элементов: ";
        for (int i = 0; i < size; i++) {
            std::cout << arrA[i] << " ";
        }
    } else {
        std::cout << "Массив B имеет больше положительных элементов: ";
        for (int i = 0; i < size; i++) {
            std::cout << arrB[i] << " ";
        }
    }
    std::cout << std::endl;
}

bool hasIdenticalDigits(int num) {
    std::string str = std::to_string(num);
    for (size_t i = 1; i < str.length(); i++) {
        if (str[i] != str[0]) {
            return false;
        }
    }
    return true;
}

void findCommonIdenticalDigitNumbers(const std::set<int>& setA, const std::set<int>& setB) {
    std::set<int> intersection;

    for (const int& num : setA) {
        if (setB.count(num) > 0 && hasIdenticalDigits(num)) {
            intersection.insert(num);
        }
    }

    std::cout << "Пересечение с одинаковыми цифрами: ";
    for (const int& num : intersection) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    int N;
    std::cout << "Введите размер массивов (N): ";
    std::cin >> N;

    int* A = new int[N];
    int* B = new int[N];

    std::cout << "Введите элементы для массива A:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cout << "Введите элементы для массива B:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    findArrayWithMaxPositive(A, B, N);

    // Задание для множеств
    std::set<int> setA, setB;
    std::cout << "Введите элементы множества A:" << std::endl;
    for (int i = 0; i < N; i++) {
        int value;
        std::cin >> value;
        setA.insert(value);
    }

    std::cout << "Введите элементы множества B:" << std::endl;
    for (int i = 0; i < N; i++) {
        int value;
        std::cin >> value;
        setB.insert(value);
    }

    findCommonIdenticalDigitNumbers(setA, setB);

    delete[] A;
    delete[] B;

    return 0;
}