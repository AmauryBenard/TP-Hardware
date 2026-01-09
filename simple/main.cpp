#include "Wallet.h"
#include <iostream>

int main() {
    Wallet wallet(10);

    wallet.credit(5);
    wallet.debit(10);

    std::cout << "Final balance: " << wallet.balance() << " rupees" << std::endl;
    return 0;
}
