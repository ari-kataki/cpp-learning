#define EXAMPLE_1 0
#define EXAMPLE_2 1
#define EXERCISE EXAMPLE_2

#include <iostream>
#include <limits>

using namespace std;

int main() {
    #if EXERCISE == EXAMPLE_1
    
    cout << "Hello guys!" << endl;
    cout << "me no want!" << endl;
    
    #elif EXERCISE == EXAMPLE_2
        cout << "TABELLA TIPI\n";
        cout << "TIPO" << "BYTE" << "MIN" << "MAX" << endl;
        cout << "short int " << sizeof(short int) << numeric_limits<short int>::min() << numeric_limits<short int>::max() << endl;
        cout << "int " << sizeof(int) << numeric_limits<int>::min() << numeric_limits<int>::max() << endl;
        cout << "long int " << sizeof(long int) << numeric_limits<long int>::min() << numeric_limits<long int>::max() << endl;
        cout << "long long int " << sizeof(long long int) << numeric_limits<long long int>::min() << numeric_limits<long long int>::max() << endl;
        cout << "unsigned char " << sizeof(unsigned char) << numeric_limits<unsigned char>::min() << numeric_limits<unsigned char>::max() << endl;
        cout << "bool " << sizeof(bool) << numeric_limits<bool>::min() << numeric_limits<bool>::max() << endl;
        cout << "float " << sizeof(float) << numeric_limits<float>::min() << numeric_limits<float>::max() << endl;
        cout << "double " << sizeof(double) << numeric_limits<double>::min() << numeric_limits<double>::max() << endl;
        cout << "long double " << sizeof(long double) << numeric_limits<long double>::min() << numeric_limits<long double>::max() << endl;
    #endif
        return 0;
}