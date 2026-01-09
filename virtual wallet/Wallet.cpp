#include "Wallet.h"
#include <iostream>
#include <thread>
#include <chrono>

Wallet::Wallet(unsigned int initial)
    : rupees(initial), virtual_rupees(initial) {}

void Wallet::credit(unsigned int val) {
    for (unsigned int i = 0; i < val; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(mtx_rupees);
        rupees++;
        std::cout << "+1 rupee (physical)" << std::endl;
    }
}

void Wallet::debit(unsigned int val) {
    for (unsigned int i = 0; i < val; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(mtx_rupees);
        if (rupees > 0) {
            rupees--;
            std::cout << "-1 rupee (physical)" << std::endl;
        }
    }
}

bool Wallet::virtual_credit(unsigned int val) {
    {
        std::lock_guard<std::mutex> lock(mtx_virtual);
        virtual_rupees += val;
    }

    std::thread(&Wallet::credit, this, val).detach();
    return true;
}

bool Wallet::virtual_debit(unsigned int val) {
    {
        std::lock_guard<std::mutex> lock(mtx_virtual);
        if (virtual_rupees < val)
            return false;

        virtual_rupees -= val;
    }

    std::thread(&Wallet::debit, this, val).detach();
    return true;
}

unsigned int Wallet::balance() {
    std::lock_guard<std::mutex> lock(mtx_virtual);
    return virtual_rupees;
}
