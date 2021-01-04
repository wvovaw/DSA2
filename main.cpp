#include <iostream>
#include <array>
#include "array.h"
using std::cout; using std::endl;

int main() {
  // 1. using default constructor
  array<int, 10> a;
  // 2. using array<T, N>(const T& arr) constructor
  int arr[5] = {1,2,3,4,5};
  array<int, 5> b(arr);
  // 3. using [] operator
  cout << b[0] << endl;
  //  cout << "b[-1] " << b[-1] << endl; // Segmentation fault
  cout << b[2] << endl;
  //  cout << b[6] << endl; // Segmentation fault
  // 4. using data method to get T arr[]
  auto _b = b.data();
  for (int i = 0; i < 5; ++i)
    cout << _b[i] << ' ';
  b[2] = 10; // reassign value using [] operator
  cout << b[2] << endl;
  // 5. using front at and back methonds
  cout << b.front() << endl;
  cout << b.at(3) << endl;
  cout << b.back() << endl;
  // 6. using empty method and size method
  array<char, 0> c;
  cout << c.empty() << endl;
  cout << b.empty() << endl;
  cout << c.size() << endl;

  return 0;
}
