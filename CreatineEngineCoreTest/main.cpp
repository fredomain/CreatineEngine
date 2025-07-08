// CreatineEngineCoreTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <print>
#include "CreatineEngineCore.h"

int main()
{
    CE::CreatineEngineCore::init();

    std::print("Hello World!\n");

    CE::CreatineEngineCore::quit();
}
