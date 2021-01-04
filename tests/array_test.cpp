#include "gtest/gtest.h"
#include "../array.h"

TEST(ArrayTests, SizeOfArray) {

  array<int, 0> emptyIntArray;
  EXPECT_EQ(sizeof emptyIntArray, 0); // 4byte * 0

  array<char, 8> arrayFor8Chars;
  EXPECT_EQ(sizeof arrayFor8Chars, 8); // 1byte * 8

  array<long long int, 4> arrayFor4LLInts;
  EXPECT_EQ(sizeof  arrayFor4LLInts, 32); // 8byte * 4

  array<int, 10> arrayFor10Ints;
  EXPECT_EQ(sizeof arrayFor10Ints, 40); // 4byte * 10

// Each field in struct uses 8bytes
// long modifier adds 8 bytes
// 8 + 8 + (2 * 8) = 32
  typedef struct {
      char *name;
      double avg;
      long double ldVar;
  } TestType;

  array<TestType, 25> arrayFor25TestTypes;
  TestType person;
  EXPECT_EQ(sizeof arrayFor25TestTypes, 32 * 25); // 32byte * 25
}

TEST(ArrayTests, TakeAddressOperator) {
  double a[] = {0.1251, 0.4212};
  array<double, 7> arr(a);

  EXPECT_EQ(arr.size(), 7);
  EXPECT_EQ(arr[0], 0.1251);
  EXPECT_EQ(arr[1], 0.4212);

  // Assign arr[2] with PI
  arr[2] = 3.14159;
  arr[4] = arr[3] = arr[2];
  EXPECT_EQ(arr[3], 3.14159);
  EXPECT_EQ(arr[4], arr[2]);
  EXPECT_EQ(arr[2], arr[3]);

  // OutOfRange exceptions
  EXPECT_THROW(arr[7], std::out_of_range);
  EXPECT_THROW(arr[-1], std::out_of_range);
}

TEST(ArrayTests, FrontMethod) {
  // Empty array throws out_of_range on front method
  array<int, 0> emptyArray;
  EXPECT_THROW(emptyArray.front(), std::out_of_range);

  // Creating array of 3 strings
  char str1[] = "blablabla";
  char str2[] = "sdjfhasdlkj";
  char str3[]= "sldhgwe a'wihj akl";
  char *strings[3] = { str1, str2, str3 };
  array<char*, 3> arrayFor3Strings(strings);

  // Reassign front and check it
  EXPECT_EQ(arrayFor3Strings.front(), str1);
  arrayFor3Strings.front() = "HowHowHow";
  EXPECT_EQ(arrayFor3Strings.front(), "HowHowHow");

  // In array with 1 element front and back is the same element
  array<int, 1> arrayFor1Int;
  EXPECT_EQ(arrayFor1Int.front(), arrayFor1Int.back());
}
TEST(ArrayTests, AtMethod) {
  array<int, 0> emptyArray;
  EXPECT_THROW(emptyArray.at(0), std::out_of_range);
  EXPECT_THROW(emptyArray.at(1), std::out_of_range);

  // Creating array of 3 doubles
  double arr[] = { 0.123, 1.234, 5.678 };
  array<double, 3> arrayFor3Doubles(arr);

  EXPECT_EQ(arrayFor3Doubles.at(0), 0.123);
  EXPECT_EQ(arrayFor3Doubles.at(1), 1.234);
  EXPECT_EQ(arrayFor3Doubles.at(2), 5.678);
}
TEST(ArrayTests, BackMethod) {
  // Empty array throws out_of_range on front method
  array<int, 0> emptyArray;
  EXPECT_THROW(emptyArray.back(), std::out_of_range);

  // Creating array of 3 strings
  char str1[] = "blablabla";
  char str2[] = "sdjfhasdlkj";
  char str3[]= "sldhgwe a'wihj akl";
  char *strings[3] = { str1, str2, str3 };
  array<char*, 3> arrayFor3Strings(strings);

  EXPECT_EQ(arrayFor3Strings.back(), str3);

  // Reassign front and check it
  arrayFor3Strings.back() = "aslkdjasldk lj";
  EXPECT_EQ(arrayFor3Strings.back(), "aslkdjasldk lj");

  // In array with 1 element front and back is the same element
  array<int, 1> arrayFor1Int;
  EXPECT_EQ(arrayFor1Int.back(), arrayFor1Int.front());
}

TEST(ArrayTests, EmptyMethod) {
  array<int, 2> notEmptyArray;
  EXPECT_NE(notEmptyArray.empty(), true);
  array<int, 0> emptyArray;
  EXPECT_EQ(emptyArray.empty(), true);
}

TEST(ArrayTests, SizeMethod) {
  array<int, 2> arrayFor2Ints;
  EXPECT_EQ(arrayFor2Ints.size(), 2);
  EXPECT_NE(arrayFor2Ints.empty(), true);
  array<int, 522> arrayFor525Ints;
  EXPECT_EQ(arrayFor525Ints.size(), 522);
  EXPECT_NE(arrayFor525Ints.empty(), true);
}
