#include "Wallet.h"
#include <iostream>
#include <thread>

int main() {
    Wallet wallet(10);

    std::thread t1(&Wallet::credit, &wallet, 10);
    std::thread t2(&Wallet::debit, &wallet, 5);

    t1.join();
    t2.join();

    std::cout << "Final balance: " << wallet.balance() << " rupees" << std::endl;
    return 0;
}
