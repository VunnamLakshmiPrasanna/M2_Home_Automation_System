#include "../Unity_Test/unity.h"
#include "../Unity_Test/onlytesting.h"

void setUp()
{
}
void tearDown()
{
}

void test_map(void)
{
  TEST_ASSERT_EQUAL_INT(525, map(20, 492, 478, 20, 35));
  TEST_ASSERT_EQUAL_INT(520, map(25, 492, 478, 20, 35));
  TEST_ASSERT_EQUAL_INT(515, map(30, 492, 478, 20, 35));
  TEST_ASSERT_EQUAL_INT(509, map(35, 492, 478, 20, 35));
}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(test_map);

  return UNITY_END();
}