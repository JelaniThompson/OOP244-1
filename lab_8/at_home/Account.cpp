#include <iostream>
#include "Account.h"
using namespace std;

namespace sict {
    Account::Account(double initBalance) {
        (initBalance) ? m_Balance = initBalance : m_Balance = 0;
    }

    bool Account::credit(double amountToAdd) {
        if (amountToAdd > 0) {
            m_Balance += amountToAdd;
            return true;
        } else {
            return false;
        }
    }

    bool Account::debit(double amountToSubtract) {
        if (amountToSubtract > 0) {
            m_Balance -= amountToSubtract;
            return true;
        } else {
            return false;
        }
    }

    double Account::balance() const {
        return m_Balance;
    }
}
