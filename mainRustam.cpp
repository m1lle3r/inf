#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    float x, y;
    cout << "Введите значения x и y: ";
    cin >> x >> y;
    
    float R = x * tan(M_PI / 2); 
    float S = sqrt(pow(x, 2) + pow(y, 2)) / pow(2, log2(x));
    
    cout << "R = " << R << endl;
    cout << "S = " << S << endl;
    
    float C = max(R, S);
    
    cout << "Максимальное значение C = " << C << endl;
    
    return 0;
}
