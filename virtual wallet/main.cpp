#include "Wallet.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    Wallet wallet(10);

    wallet.virtual_debit(3);
    wallet.virtual_debit(4);
    wallet.virtual_credit(2);

    std::cout << "Virtual balance: " << wallet.balance() << " rupees" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 0;
}
