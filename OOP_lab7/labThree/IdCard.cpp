#include "IdCard.h"

template<typename T, typename U>
inline IdCard<T, U>::IdCard()
{
	this->number = 56389647;
	this->dateExpire = "14.04.2022";
}

template<typename T, typename U>
void IdCard<T, U>::setNumber(T number)
{
	this->number = number;
}

template<typename T, typename U>
T IdCard<T, U>::getNumber()
{
	return T(this->number);
}

template<typename T, typename U>
void IdCard<T, U>::setDateExpire(U date)
{
	this->dateExpire = date;
}

template<typename T, typename U>
U IdCard<T, U>::geetDateExpire()
{
	return U(this->dateExpire);
}
