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
float GetMidleSalary(struct EMPLOYEE* X)
{
	int k = 0, i = 0;
	struct EMPLOYEE* p;
	for (p = X; p != NULL; p = p->next)
	{
		k = k + p->salary;
		i++;
	}
	return (float)k / i;
}