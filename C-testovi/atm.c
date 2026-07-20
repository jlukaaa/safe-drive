#include "atm.h"
#include <stddef.h>

bool validate_card_number(const char *card_number) {
    if (card_number == NULL) return false;
    
    int length = 0;
    while (card_number[length] != '\0') {
        length++;
    }
    
    if (length != 13) return false;
    
    int sum = 0;
    for (int i = 0; i < 13; i++) {
        if (card_number[i] < '0' || card_number[i] > '9') {
            return false;
        }
        sum += card_number[i] - '0';
    }
    
    if (sum % 3 != 0) return false;
    
    return true;
}

ATM_Result with_cash(ATM_Acc *acc, double amount) {
    if (acc == NULL) return ATM_ERR_INVALID_CARD;
    
    if (!validate_card_number(acc->card_number)) {
        return ATM_ERR_INVALID_CARD;
    }
    
    if (amount <= 0) {
        return ATM_ERR_INVALID_AMOUNT;
    }
    
    if (!((int)amount % 50 == 0 || (int)amount % 20 == 0)) {
        return ATM_ERR_INVALID_AMOUNT;
    }
    
    if (amount > acc->balance) {
        return ATM_ERR_INSUF_FUNDS;
    }
    
    acc->balance -= amount;
    
    return ATM_SUCCESS;
}