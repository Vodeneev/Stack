#include "pch.h"
#include "gtest/gtest.h"
#include "../Stacknew/Stack.h"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> v(5));
}

TEST(Stack, can_create_stack_with_standart_length)
{
	ASSERT_NO_THROW(Stack<int> v());
}

TEST(Stack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> v(-5));
}

TEST(Stack, can_create_copied_stack)
{
	Stack<int> v(10);

	ASSERT_NO_THROW(Stack<int> v1(v));
}

TEST(Stack, copied_stack_is_equal_to_source_one)
{
	Stack<int> v(10);
	Stack<int> s(v);
	EXPECT_TRUE(v == s);
}
TEST(Stack, copied_stack_has_its_own_memory)
{
	Stack<int> s(5), v(s);
	s.Push(2);
	EXPECT_TRUE(!(s.top() == 3));
}
TEST(Stack, can_get_size)
{
	Stack<int> v(4);

	EXPECT_EQ(4, v.Size());
}
TEST(Stack, can_push_element)
{
	Stack<int> v(4);
	v.Push(4);
	EXPECT_EQ(v.top(), 4);
}
TEST(Stack, can_push_element_with_full_stack)
{
	Stack<int> v(1);
	v.Push(4);
	v.Push(2);
	EXPECT_EQ(v.top(), 2);
}
TEST(Stack, can_set_last_element)
{
	Stack<int> v(4);
	v.Push(4);
	EXPECT_EQ(4, v.top());
}
TEST(Stack, throws_when_set_element_from_empty_stack)
{
	Stack<int> v(10);
	ASSERT_ANY_THROW(v.top());
}
TEST(Stack, can_delete_last_element)
{
	Stack<int> v(4);
	v.Push(4);
	v.Push(3);
	v.pop();
	EXPECT_EQ(4, v.top());
}
TEST(Stack, throws_when_delete_element_from_empty_stack)
{
	Stack<int> v(10);
	ASSERT_ANY_THROW(v.pop());
}
TEST(Stack, can_say_empty_stack) {
	Stack<int> s(10);
	EXPECT_TRUE(s.empty());
}