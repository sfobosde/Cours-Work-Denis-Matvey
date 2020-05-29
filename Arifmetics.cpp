#include "Arifmetics.h"
#include <stdio.h>
struct EMPLOYEE
{
	char name[20];
	int bd;
	char male[6];
	int exp;
	int salary;
	struct EMPLOYEE* next;
};
//function returnts midle arifmetic salary
float GetMidleSalary(struct EMPLOYEE* X)
{
	int k = 0, i = 0;// k - sum of salary i - employers quantity
	struct EMPLOYEE* p;//new link of list to switch element one by one
	for (p = X; p != NULL; p = p->next)//switch element one by one
	{
		k = k + p->salary;//summation salary
		i++;//summuation quantity
	}
	return (float)k / i;//return midle arifmetic salary
}