#include "LoadInfo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct EMPLOYEE
{
	char name[20];
	int bd;
	char male[6];
	int exp;
	int salary;
	struct EMPLOYEE* next;
};
void EditInfo(char wi[42], char* info)
{
	int i = 0, j = 0;
	for (; wi[i] != ' '; info[i] = wi[i], i++);
	info[i] = '\0';
	for (; wi[i] == ' '; i++);
	for (; wi[j + i] != '\0'; wi[j] = wi[j + i], j++);
	wi[j] = '\0';
}
int ConvetToInt(char* m)
{
	int buf = 0;
	for (int i = 0; m[i] >= '0' && m[i] <= '9'; buf = buf * 10 + (m[i] - 48), i++);
	return buf;
}
void LoadWorkersList(struct EMPLOYEE** X, char* FileName)
{
	FILE* Workers;
	*X = NULL;
	char WI[42];
	if (fopen_s(&Workers, FileName, "r") != 0)
		printf("\nWorkers file didn`t exists");
	else
	{
		while (fgets(WI, 42, Workers) != NULL)
		{
			struct EMPLOYEE* pt = NULL;
			char buf[6];
			pt = (struct EMPLOYEE*) malloc(sizeof(struct EMPLOYEE));
			EditInfo(WI, pt->name);
			EditInfo(WI, buf);
			pt->bd = ConvetToInt(buf);
			EditInfo(WI, pt->male);
			EditInfo(WI, buf);
			pt->exp = ConvetToInt(buf);
			pt->salary = ConvetToInt(WI);
			/*printf(pt->name);
			printf("%d", pt->bd);
			printf(pt->male);
			printf("%d", pt->exp);
			printf("%d\n", pt->salary);*/
			pt->next = *X;
			*X = pt;
		}
	}
	fclose(Workers);
}