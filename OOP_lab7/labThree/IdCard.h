#pragma once

#include <iostream>
using namespace std;

template <class T, class U>
class IdCard
{
private:
	T number;
	U dateExpire;
public:
	IdCard();
	
	void setNumber(T number);
	T getNumber();

	void setDateExpire(U date);
	U geetDateExpire();
};