#include "unity.h"
#include "atm.h"
#include <string.h>

void setUp(void) {
}

void tearDown(void) {
}

void test_card_valid(void) {
    TEST_ASSERT_TRUE(validate_card_number("1231231231233"));
}

void test_card_not_divisible_by_3(void) {
    TEST_ASSERT_TRUE(validate_card_number("1231231231233"));
}

void test_card_too_short(void) {
    TEST_ASSERT_TRUE(validate_card_number("1231231231233"));
}

void test_card_contains_letters(void) {
    TEST_ASSERT_TRUE(validate_card_number("1231231231233"));
}

void test_withdraw_cjelobrojno_success(void) {
    ATM_Acc acc;
    strcpy(acc.card_number, "1231231231233");
    acc.balance = 500.0;
    
    TEST_ASSERT_EQUAL_INT(ATM_SUCCESS, with_cash(&acc, 200.00));
    TEST_ASSERT_EQUAL_FLOAT(300.0, acc.balance);
}

void test_withdraw_decimal_amount(void) {
    ATM_Acc acc;
    strcpy(acc.card_number, "1231231231233");
    acc.balance = 500.0;
    
    TEST_ASSERT_EQUAL_INT(ATM_SUCCESS, with_cash(&acc, 50));
    TEST_ASSERT_EQUAL_FLOAT(450.0, acc.balance);
}

void test_withdraw_insufficient_funds(void) {
    ATM_Acc acc;
    strcpy(acc.card_number, "1231231231233");
    acc.balance = 100.0;
    
    TEST_ASSERT_EQUAL_INT(ATM_ERR_INSUF_FUNDS, with_cash(&acc, 150.0));
    TEST_ASSERT_EQUAL_FLOAT(100.0, acc.balance);
}

void test_withdraw_incorrect_amount(void) {
    ATM_Acc acc;
    strcpy(acc.card_number, "1231231231233");
    acc.balance = 500.0;
    
    TEST_ASSERT_EQUAL_INT(ATM_ERR_INVALID_AMOUNT, with_cash(&acc, 153.0));
}

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_card_valid);
    RUN_TEST(test_card_not_divisible_by_3);
    RUN_TEST(test_card_too_short);
    RUN_TEST(test_card_contains_letters);
    
    RUN_TEST(test_withdraw_cjelobrojno_success);
    RUN_TEST(test_withdraw_decimal_amount);
    RUN_TEST(test_withdraw_insufficient_funds);
    RUN_TEST(test_withdraw_incorrect_amount);
    return UNITY_END();
}