#ifndef WALLET_H
#define WALLET_H

#include <mutex>

class Wallet {
private:
    unsigned int rupees;
    unsigned int virtual_rupees;

    std::mutex mtx_rupees;
    std::mutex mtx_virtual;

public:
    Wallet(unsigned int initial = 0);

    void credit(unsigned int val);
    void debit(unsigned int val);

    bool virtual_credit(unsigned int val);
    bool virtual_debit(unsigned int val);

    unsigned int balance();
};

#endif
