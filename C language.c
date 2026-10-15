#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>


int radacina(int v, int* parinte)
{
	int u = v;
	while (parinte[u] >= 0)
		u = parinte[u];
	return u;
}

int kruskall(int tabel[][3], int muchii, int varfuri)
{
	int parinte[50];
	int v1, v2, rad1, rad2, cost_total = 0;

	for (int i = 0;i < varfuri;i++)
	{
		parinte[i] = -1;
	}

	int nrm = 0;
	int j = 0;
	aleg n-1 muchii
	while (nrm < varfuri - 1) {
		v1 = tabel[j][0];
		v2 = tabel[j][1];
		rad1 = radacina(v2, parinte);
		rad2 = radacina(v1, parinte);
		if (rad1 != rad2)
		{
			cost_total += tabel[j][2];
			printf("%i -> %i cost %i\n", v1 + 1, v2 + 1, tabel[j][2]);
			nrm++;
			if (parinte[rad1] < parinte[rad2])
			{
				parinte[rad1] += parinte[rad2];
				parinte[rad2] = rad1;
			}
			else
			{
				parinte[rad2] += parinte[rad1];
				parinte[rad1] = rad2;
			}
		}
		j++;
	}

	return cost_total;
}

void main()
{
	int cost, i, j, nv, nm, a[100][3];
	printf("Numarul de varfuri:");scanf("%i", &nv);
	printf("Numarul de muchii:");scanf("%i", &nm);
	printf("Matricea de reprezentare\n");
	for (i = 0;i < nm;i++)
	{
		printf("Muchia %i si ponderea:", i + 1);
		for (j = 0;j < 3;j++)
			scanf("%i", &a[i][j]);
	}

	for (i = 0;i < nm;i++)
		for (j = 0;j < 2;j++)
			a[i][j]--;


	printf("Arborele de cost minim: \n");
	cost = kruskall(a, nm, nv);
	printf("\ncu costul %i", cost);
}
