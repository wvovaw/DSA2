#include "gtest/gtest.h"
#include "../list.hpp"
#include <iostream>
#include <vector>

TEST(ListTest, defaultConstructor) {
  ASSERT_NO_FATAL_FAILURE(list<char> listOfChars);
}
TEST(ListTest, rangeConstructor) {
  int arr[5] = {1,2,3,4,5};
  int& start = *arr;
  int& end = *(arr + 3);
  ASSERT_NO_FATAL_FAILURE(list<int> listOfInts(start, end));
}
TEST(ListTest, copyConstructors) {
  class car {
  public:
      explicit car(unsigned int ms) : max_speed(ms){}
      bool operator==(const car &rvl) const {
        return max_speed == rvl.max_speed;
      }
  private:
      unsigned int max_speed;
  };
  car c1(4482);
  car c2(3730);
  car c3(83);
  car cars[3] = {c1,c2,c3};
  size_t size = sizeof cars / sizeof cars[0];
  list<car> myCars(cars, size); // calls list<T>(const T &val) : head(val.front()), tail(val.back())
  list<car>& wifeCars(myCars); // calls list<T>(const list<T> &val)
  ASSERT_EQ(myCars.front(), wifeCars.front());
  ASSERT_EQ(myCars.back(), wifeCars.back());
}
TEST(ListTest, frontAndBackMethods) {
  list<int> listOfInts;
  listOfInts.push_front(1);
  listOfInts.push_front(2);
  listOfInts.push_front(3);
  listOfInts.push_front(4);

  auto f = listOfInts.front();
  auto b = listOfInts.back();
  EXPECT_EQ(f->getData(), 4);
  EXPECT_EQ(b->getData(), 1);
  f->setData(10002);
  b->setData(20001);
  EXPECT_EQ(listOfInts.front()->getData(), 10002);
  EXPECT_EQ(listOfInts.back()->getData(),  20001);
}
TEST(ListTest, popFrontMethod) {
  list<char> listOfChars;
  listOfChars.push_back('j');
  listOfChars.push_back('o');
  listOfChars.push_back('p');
  listOfChars.push_back('a');
  listOfChars.push_back('x');
  listOfChars.push_back('d');
  listOfChars.push_back('s');
  EXPECT_EQ(listOfChars.front()->getData(), 'j');
  listOfChars.pop_front();
  EXPECT_EQ(listOfChars.front()->getData(), 'o');
  listOfChars.pop_front();
  listOfChars.pop_front();
  EXPECT_EQ(listOfChars.front()->getData(), 'a');
}
TEST(ListTest, popBackMethod) {
  list<char> listOfChars;
  listOfChars.push_back('j');
  listOfChars.push_back('o');
  listOfChars.push_back('p');
  listOfChars.push_back('a');
  listOfChars.push_back('x');
  listOfChars.push_back('d');
  listOfChars.push_back('s');
  EXPECT_EQ(listOfChars.back()->getData(), 's');
  listOfChars.pop_back();
  EXPECT_EQ(listOfChars.back()->getData(), 'd');
  listOfChars.pop_back();
  listOfChars.pop_back();
  EXPECT_EQ(listOfChars.back()->getData(), 'a');
  listOfChars.pop_back();
  listOfChars.pop_back();
  EXPECT_EQ(listOfChars.back()->getData(), 'o');
}
TEST(ListTest, insertOneAtPositionMethod) {
  list<char> listOfChars;
  listOfChars.push_front(65);
  listOfChars.push_front(66);
  EXPECT_EQ(listOfChars.size(), 2);
  listOfChars.insert(2, '&'); // pos: 3 val: char(&)
  EXPECT_EQ(listOfChars.size(), 3);
  EXPECT_EQ(listOfChars.front()->getData(), '&');
  listOfChars.insert(0, '%'); // pos: 3 val: char(&)
  EXPECT_EQ(listOfChars.size(), 4);
  EXPECT_EQ(listOfChars.back()->getData(), '%');
  EXPECT_THROW(listOfChars.insert(100, ')'), std::out_of_range);
}
TEST(ListTest, insertSeveralAtPositionMethod) {
  list<char> listOfChars;
  listOfChars.push_back(65);
  listOfChars.push_back(66);
  listOfChars.insert(0, 2, ')');
  EXPECT_EQ(listOfChars.back()->getData(), ')');
  EXPECT_EQ(listOfChars.back()->next->getData(), ')');
  EXPECT_EQ(listOfChars.back()->next->next->getData(), 66);
  EXPECT_EQ(listOfChars.back()->next->next->next->getData(), 65);

  listOfChars.insert(4, 3, '(');
  EXPECT_EQ(listOfChars.front()->getData(), '(');
  EXPECT_EQ(listOfChars.front()->prev->getData(), '(');
  EXPECT_EQ(listOfChars.front()->prev->prev->getData(), '(');
  EXPECT_EQ(listOfChars.front()->prev->prev->prev->getData(), 65);

  listOfChars.insert(3, 2, '+');
  EXPECT_EQ(listOfChars.back()->next->next->next->next->getData(), '+');
}
TEST(ListTest, clearMethod) {
  list<char> listOfChars;
  listOfChars.insert(0, 10, ')');
  EXPECT_EQ(listOfChars.size(), 10);
  listOfChars.clear();
  EXPECT_EQ(listOfChars.size(), 0);

  list<int> listOfInts;
  listOfInts.insert(0, 228);
  EXPECT_EQ(listOfInts.size(), 1);
  listOfInts.clear();
  EXPECT_EQ(listOfInts.size(), 0);
  listOfInts.insert(0, 10, 228);
  EXPECT_EQ(listOfInts.size(), 10);
  listOfInts.clear();
  EXPECT_EQ(listOfInts.size(), 0);
}
TEST(ListTest, eraseSingleMethod) {
  list<char> listOfChars;
  char a = 20;
  listOfChars.push_front(a++);
  listOfChars.push_front(a++);
  listOfChars.push_front(a++);
  listOfChars.push_front(a++);
  listOfChars.push_front(a++);
  listOfChars.push_front(a++);
  EXPECT_EQ(listOfChars.size(), 6);
  listOfChars.erase(0);
  EXPECT_EQ(listOfChars.size(), 5);
  listOfChars.erase(3);
  EXPECT_EQ(listOfChars.size(), 4);
  listOfChars.erase(4);
  EXPECT_EQ(listOfChars.size(), 3);
  listOfChars.clear();
  EXPECT_THROW(listOfChars.erase(0), std::out_of_range);
}