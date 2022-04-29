#include <iostream>
#include "BigNumber.hpp"

int main()
{
    BigNumber number(2123213);
    BigNumber number1(12464);
    // std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") > BigNumber("4767846784647856547476")) << std::endl;
    // std::cout << std::boolalpha << (BigNumber("4767846784647856547476") < BigNumber("7643276342876783246893247")) << std::endl;
    // std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") != BigNumber("4767846784647856547476")) << std::endl;
    // std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") == BigNumber("7643276342876783246893247")) << std::endl;

    // std::cout << std::boolalpha << ((BigNumber("12345678901234567890") + BigNumber("4354678097643135")) == BigNumber("12350033579332211025")) << std::endl;
    // std::cout << std::boolalpha << ((BigNumber("12345678901234567890") - BigNumber("4354678097643135")) == BigNumber("12341324223136924755")) << std::endl;
    // std::cout << std::boolalpha << ((BigNumber("12345678901234567890") * BigNumber("4354678097643135")) == BigNumber("53761457511741137249987999149935150")) << std::endl;
    // std::cout << std::boolalpha << ((BigNumber("12345678901234567890") / BigNumber("4354678097643135")) == BigNumber("2835")) << std::endl;
    // std::cout << std::boolalpha << ((BigNumber("12345678901234567890") % BigNumber("4354678097643135")) == BigNumber("166494416280165")) << std::endl;

    // std::cout << std::boolalpha << ((BigNumber("-12345678901234567890") + BigNumber("4354678097643135")) == BigNumber("-12341324223136924755")) << std::endl;
    // std::cout << std::boolalpha << ((BigNumber("-12345678901234567890") * BigNumber("4354678097643135")) == BigNumber("-53761457511741137249987999149935150")) << std::endl;// cout << (BigNumber(12330) > BigNumber(13000)) << endl;
    
    cout << (BigNumber(-1000) + BigNumber(-100))<< endl;
    // cout << (BigNumber(120) - BigNumber(12309))<< endl;
    // cout << (BigNumber(1324) - BigNumber(54))<< endl;
    // cout << (BigNumber(12) - BigNumber(1230))<< endl;
    // cout << (BigNumber(4210) - BigNumber(2003))<< endl;
    // cout << (BigNumber(1) - BigNumber(12309))<< endl;
    // cout << (BigNumber(12031) - BigNumber(10001))<< endl;
    // cout << (BigNumber(74606099) - BigNumber(69743214))<< endl;
    // cout << (BigNumber(69743214) - BigNumber(74606099))<< endl;
    // cout << (BigNumber(1300) - BigNumber(1217))<< endl;
    // return 0;
}