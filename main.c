#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcije.h"

int main() {
	int n = 0;

	do {
		printf("1.Dodaj glazbu.\n");
		printf("2.Ispisi svu glazbu.\n");
		printf("3.Uredi glazbu.\n");
		printf("4.Pretrazi po imenu pjesme.\n");
		printf("5.Pretrazi po imeni izvodaca.\n");
		printf("6.Pretrazi po imenu albuma.\n");
		printf("7.Izbrisi glazbu.\n");
		printf("8.Spremi i izadi.\n");

		do {
			printf("Unesite broj:");
			scanf("%d", &n);
		} while (!(n > 0 && n < 9));

		izbornik(n);

	} while (n != 8);




	return 0;
}