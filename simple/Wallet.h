#ifndef WALLET_H
#define WALLET_H

class Wallet {
private:
    unsigned int rupees;

public:
    Wallet(unsigned int initial = 0);
    void credit(unsigned int val);
    void debit(unsigned int val);
    unsigned int balance() const;
};

#endif
