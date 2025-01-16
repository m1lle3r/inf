#include <iostream>

int main() {
    int a = 1234;
    int b = 0;

    while (a !=0){
        b += a % 10;
        a /= 10;
    }
    std::cout << "Sum of digits" << b << std::endl;
    return 0;
}
