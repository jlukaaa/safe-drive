#ifndef ATM_H
#define ATM_H

#include <stdbool.h>

typedef enum {
    ATM_SUCCESS = 0,
    ATM_ERR_INVALID_CARD,
    ATM_ERR_INSUF_FUNDS,
    ATM_ERR_INVALID_AMOUNT,


} ATM_Result;

typedef struct 
{
    char card_number[14];
    double balance;
   
} ATM_Acc;

bool validate_card_number(const char *card_number);
ATM_Result with_cash(ATM_Acc *acc, double amount);

#endif

