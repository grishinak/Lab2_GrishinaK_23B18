#pragma once
#include <iostream>
#include <string>

void TestNPC() {
    NPC merchant("Merchant", 100, 10, "Trader");
    assert(merchant.GetName() == "Merchant");
    assert(merchant.GetRole() == "Trader");

    cout << " NPC test passed." << endl;
};
