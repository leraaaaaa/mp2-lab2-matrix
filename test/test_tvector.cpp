#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> first(3,0);
  first[2] = 7;
  TVector<int> second = first;
  EXPECT_EQ(first, second);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> first(5);
  TVector<int> second = first;
  EXPECT_NE(&first[0], &second[0]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  TVector<char> v(5);
  ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<double> v(5);
  ASSERT_ANY_THROW(v[5]);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> v(3);
  for (int i = 0; i < v.GetSize(); i++)
	  v[i] = i+1;
  v = v;
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<double> first(2),second(2);
  first[0] = 2.0;
  first[1] = 1.5;
  second = first;
  EXPECT_EQ(first, second);
}

TEST(TVector, assign_operator_change_vector_size)
{
  TVector<int> first(1), second(5);
  first[0] = 1;
  second = first;
  EXPECT_EQ(1, second.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> first(1), second(5);
  first[0] = 1;
  second = first;
  EXPECT_EQ(first, second);
}

TEST(TVector, compare_equal_vectors_return_true)
{ 
  TVector<int> first(3), second(3);
  for (int i = 0; i < first.GetSize(); i++)
  {
	  first[i] = 7 * i;
	  second[i] = 7 * i;
  }
  EXPECT_EQ(first, second);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<char> v(3);
  EXPECT_EQ(v, v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<char> first(3),second(4);
  EXPECT_NE(first, second);
}

TEST(TVector, can_add_scalar_to_vector)
{
  TVector<int> first(5), second(5);
  for (int i = 0; i < first.GetSize(); i++)
	  first[i] = 3 - i;
  for (int i = 0; i < second.GetSize(); i++)
	  second[i] = 3 - i + 7;
  first = first + 7;
  EXPECT_EQ(first,second);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> first(5), second(5);
  for (int i = 0; i < first.GetSize(); i++)
	  first[i] = 3 - i;
  for (int i = 0; i < second.GetSize(); i++)
	  second[i] = 3 - i - 7;
  first = first - 7;
  EXPECT_EQ(first, second);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
   TVector<int> first(5), second(5);
  for (int i = 0; i < first.GetSize(); i++)
	  first[i] = 3 - i;
  for (int i = 0; i < second.GetSize(); i++)
	  second[i] = (3 - i) * 7;
  first = first * 7;
  EXPECT_EQ(first, second);
}

TEST(TVector, can_add_vectors_with_equal_size)
{ 
  TVector<int> first(3), second(3), third(3);
  for (int i = 0; i < first.GetSize(); i++)
	  first[i] = 3 - i;
  //first = (3 2 1)
  for (int i = 0; i < second.GetSize(); i++)
	  second[i] = 1+i*3;
  //second = (1 4 7)
  for (int i = 0; i < third.GetSize(); i++)
	  third[i] = 4 + i * 2;
  //third = first + second = (4 6 8)
  EXPECT_EQ(first + second, third);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  TVector<int> first(3), second(6);
  ASSERT_ANY_THROW(first + second);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  TVector<int> first(3), second(3), third(3);
	for (int i = 0; i < first.GetSize(); i++)
		first[i] = 3 - i;
	//first = (3 2 1)
	for (int i = 0; i < second.GetSize(); i++)
		second[i] = 1 + i * 3;
	//second = (1 4 7)
	for (int i = 0; i < third.GetSize(); i++)
		third[i] = 2 - i * 4;
	//third = first - second = (2 -2 -6)
	EXPECT_EQ(first - second, third);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
 	TVector<int> first(3), second(6);
	ASSERT_ANY_THROW(first - second);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  TVector<int> first(3), second(3);
	for (int i = 0; i < first.GetSize(); i++)
		first[i] = 3 - i;
	//first = (3 2 1)
	for (int i = 0; i < second.GetSize(); i++)
		second[i] = 1 + i * 3;
	//second = (1 4 7)
	EXPECT_EQ(first*second, 18);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> first(3), second(6);
	ASSERT_ANY_THROW(first * second);
}

