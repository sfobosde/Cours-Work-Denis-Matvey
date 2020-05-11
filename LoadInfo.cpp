#include "LoadInfo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct EMPLOYEE
{
	char name[20];
	char bd[4];
	char male;
	char exp[2];
	char salary[6];
	struct EMPLOYEE* next;
};
void EditInfo(char* wi, char* info)
{
	int i = 0, j = 0;
	for (; wi[i] != ' '; info[i] = wi[i], i++);
	info[i] = '\0';
	for (; wi[i] == ' '; i++);
	for (; wi[j + i] != '\0'; wi[j] = wi[j + i], j++);
}
void LoadWorkersList(struct EMPLOYEE** X, char* FileName)
{
	FILE* Workers;
	*X = NULL;
	char WI[37];
	if (fopen_s(&Workers, FileName, "r") != 0)
		printf("\nWorkers file didn`t exists");
	else
	{
		while (fgets(WI, 37, Workers) != NULL)
		{
			struct EMPLOYEE* pt, *k, *j = NULL;
			pt = (struct EMPLOYEE*) malloc(sizeof(struct EMPLOYEE));
			printf(WI);
			EditInfo(WI, pt->name);
			printf(WI);
			printf(pt->name);
			EditInfo(WI, pt->bd);
			printf(WI);
			printf(pt->bd);
			pt->male = WI[0];
			printf("%c", pt->male);
			for (int i = 1; WI[i] != '\0'; WI[i] = WI[i + 1], i++);
			printf(WI);
			EditInfo(WI, pt->exp);
			EditInfo(WI, pt->salary);
			if (*X == NULL || strcmp(pt->name, (*X)->name) < 0)
			{
				pt->next = *X;
				*X = pt;
			}
			else
			{
				k = *X;
				while (k != NULL && strcmp(pt->name, k->name) >= 0)
				{
					j = k;
					k = k->next;
				}
				j->next = pt;
				pt->next = k;
			}
		}
	}
	fclose(Workers);
}