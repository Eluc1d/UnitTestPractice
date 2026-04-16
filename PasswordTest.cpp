/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// ──────────────────────────────────────────────
// count_leading_characters tests
// ──────────────────────────────────────────────

// Provided baseline test
TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

// Edge case: empty string should return 0 (was crashing due to size_t underflow)
TEST(PasswordTest, count_leading_empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

// All identical characters — entire string is leading repetition
TEST(PasswordTest, count_leading_all_same)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaa");
	ASSERT_EQ(4, actual);
}

// Leading characters stop before the end
TEST(PasswordTest, count_leading_some_repeated)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaabbb");
	ASSERT_EQ(3, actual);
}

// No repetition at all — first two chars differ
TEST(PasswordTest, count_leading_no_repetition)
{
	Password my_password;
	int actual = my_password.count_leading_characters("abcd");
	ASSERT_EQ(1, actual);
}

// Case-sensitivity: 'A' != 'a'
TEST(PasswordTest, count_leading_case_sensitive)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAaaa");
	ASSERT_EQ(2, actual);
}

// Two-character string, both same
TEST(PasswordTest, count_leading_two_same)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zz");
	ASSERT_EQ(2, actual);
}

// Two-character string, both different
TEST(PasswordTest, count_leading_two_different)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ab");
	ASSERT_EQ(1, actual);
}

// Non-alpha characters
TEST(PasswordTest, count_leading_special_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("!!!abc");
	ASSERT_EQ(3, actual);
}

// Digit characters
TEST(PasswordTest, count_leading_digits)
{
	Password my_password;
	int actual = my_password.count_leading_characters("111xyz");
	ASSERT_EQ(3, actual);
}

// ──────────────────────────────────────────────
// has_mixed_case tests
// ──────────────────────────────────────────────

// All lower-case → false
TEST(PasswordTest, mixed_case_all_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("alllower");
	ASSERT_FALSE(actual);
}

// All upper-case → false
TEST(PasswordTest, mixed_case_all_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ALLUPPER");
	ASSERT_FALSE(actual);
}

// Has both upper and lower → true
TEST(PasswordTest, mixed_case_has_both)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Password");
	ASSERT_TRUE(actual);
}

// Single upper-case letter only → false
TEST(PasswordTest, mixed_case_single_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("A");
	ASSERT_FALSE(actual);
}

// Single lower-case letter only → false
TEST(PasswordTest, mixed_case_single_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("a");
	ASSERT_FALSE(actual);
}

// Empty string → false
TEST(PasswordTest, mixed_case_empty_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}

// Only digits/symbols (no letters) → false
TEST(PasswordTest, mixed_case_no_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("12345!@#");
	ASSERT_FALSE(actual);
}

// Digits plus one upper, one lower → true
TEST(PasswordTest, mixed_case_digits_and_mixed_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aB3!");
	ASSERT_TRUE(actual);
}

// Lower with upper only at the very end → true
TEST(PasswordTest, mixed_case_upper_at_end)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("passwordA");
	ASSERT_TRUE(actual);
}

// Upper with lower only at the very end → true
TEST(PasswordTest, mixed_case_lower_at_end)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("PASSWORDa");
	ASSERT_TRUE(actual);
}