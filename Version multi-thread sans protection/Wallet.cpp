#include "Wallet.h"
#include <iostream>
#include <thread>
#include <chrono>

Wallet::Wallet(unsigned int initial) : rupees(initial) {}

void Wallet::credit(unsigned int val) {
    for (unsigned int i = 0; i < val; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        rupees++;
        std::cout << "+1 rupee" << std::endl;
    }
}

void Wallet::debit(unsigned int val) {
    for (unsigned int i = 0; i < val; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        rupees--;
        std::cout << "-1 rupee" << std::endl;
    }
}

unsigned int Wallet::balance() const {
    return rupees;
}
