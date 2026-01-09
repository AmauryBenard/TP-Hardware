#ifndef WALLET_H
#define WALLET_H

#include <mutex>

class Wallet {
private:
    unsigned int rupees;
    std::mutex mtx;

public:
    Wallet(unsigned int initial = 0);
    void credit(unsigned int val);
    void debit(unsigned int val);
    unsigned int balance();
};

#endif
