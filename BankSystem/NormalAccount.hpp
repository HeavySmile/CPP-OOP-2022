#pragma once
#include "Account.hpp"
#include <stdexcept>

class NormalAccount : public Account
{
public:

    void display() const override;
};