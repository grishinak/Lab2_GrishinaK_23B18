#pragma once
#include <iostream>
#include "pet.h"

void Pet::SetHasOwner(bool valueHasOwner)
{
    hasOwner = valueHasOwner;
}

bool Pet::GetHasOwner()
{
    return hasOwner;
}
