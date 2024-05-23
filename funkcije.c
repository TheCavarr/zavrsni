#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcije.h"

static int brojGlazbe = 0;

void izbornik(int n) {

	switch (n) {
	case 1:
		dodajGlazbu();
		break;

	case 2:
		ispisGlazbe();
		break;

	case 3:
		urediGlazbu();
		break;

	case 4:
		pretrazivanjePjesme();
		break;

	case 5:
		pretrazivanjeIzvodaca();
		break;

	case 6:
		pretrazivanjeAlbuma();
		break;

	case 7:
		brisanjeGlazbe();
		break;

	case 8:
		brisanjeDatoteke();
		break;

	case 9:
		izlaz();
		break;

	}
}

void dodajGlazbu() {
	FILE* fp = NULL;
	ALBUM* temp = NULL;

	temp = (ALBUM*)malloc(sizeof(ALBUM));
	if (temp == NULL) {
		printf("Greska.");
		return 1;
	}

	printf("Unesite ime izvodaca:");
	scanf(" %19[^\n]", temp->izvodac);
	printf("Unesite ime pjesme:");
	scanf(" %19[^\n]", temp->pjesma);
	printf("Unesite ime albuma:");
	scanf(" %19[^\n]", temp->album);

	fp = fopen("album.bin", "rb");

	if (fp == NULL) {
		fp = fopen("album.bin", "wb");
		brojGlazbe++;
		fwrite(&brojGlazbe, sizeof(int), 1, fp);
		fwrite(temp, sizeof(ALBUM), 1, fp);
		fclose(fp);
	}
	else {
		fclose(fp);
		fp = fopen("album.bin", "rb+");
		if (fp == NULL) {
			printf("Greska.");
			return;
		}
		else {
			rewind(fp);
			fread(&brojGlazbe, sizeof(int), 1, fp);
			brojGlazbe++;
			rewind(fp);
			fwrite(&brojGlazbe, sizeof(int), 1, fp);
			fseek(fp, 0, SEEK_END);
			fwrite(temp, sizeof(ALBUM), 1, fp);
			fclose(fp);
		}
	}

	fclose(fp);
	free(temp);

	return;
}

void ispisGlazbe() {
	int i = 0;
	FILE* fp = NULL;
	ALBUM* temp;

	fp = fopen("album.bin", "rb");
	if (fp == NULL) {
		printf("\nAlbum je prazan.\n");
		return;
	}

	fread(&brojGlazbe, sizeof(int), 1, fp);
	if (brojGlazbe == 0) {
		printf("\nAlbum je prazan.\n");
		return;
	}

	//printf("%d\n", brojGlazbe);

	temp = (ALBUM*)malloc(brojGlazbe * sizeof(ALBUM));
	if (temp == NULL) {
		printf("\nGreska.\n");
		return 1;
	}

	fread(temp, sizeof(ALBUM), brojGlazbe, fp);

	printf("Postoji %d. spremljena pjesma.", brojGlazbe);

	for (i = 0; i < brojGlazbe; i++) {
		printf("\n\nPjesma:%s", (temp + i)->pjesma);
		printf("\nIzvodac:%s", (temp + i)->izvodac);
		printf("\nAlbum:%s", (temp + i)->album);
	}

	printf("\n");

	fclose(fp);
	free(temp);

	return;
}

void urediGlazbu() {
	FILE* fp = NULL;
	ALBUM* temp = NULL;
	int index = 0;
	int nadeno = 0;
	char trazeno[20];

	fp = fopen("album.bin", "rb");
	if (fp == NULL) {
		printf("Greska.\n");
		return 1;
	}
		fread(&brojGlazbe, sizeof(int), 1, fp);

		temp = (ALBUM*)malloc(brojGlazbe * sizeof(ALBUM));
		if (temp == NULL) {
			printf("Greska.\n");
			return 1;
		}

		fread(temp, sizeof(ALBUM), brojGlazbe, fp);
		fclose(fp);
		printf("Unesi ime pjesme za uredivanje:");
		scanf(" %19[^\n]", trazeno);
			
		for (int i = 0; i < brojGlazbe; i++) {
			if (strcmp((temp + i)->pjesma, trazeno)==0) {
				index=i;
				nadeno=1;
				break;
			}
		}

		if (nadeno == 0) {
			printf("Pjesma nije nadena.\n");
		}
		else if(nadeno==1){
			printf("Pjesma je nadena.\n");
			fp = fopen("album.bin", "rb+");
			if (fp == NULL) {
				printf("Greska.\n");
				return 1;
			}

			fread(&brojGlazbe, sizeof(int), 1, fp);
			
			for (int i = 0; i < brojGlazbe; i++) {
				if (i = index) {
					printf("Unesite novo ime izvodaca:");
					scanf(" %19[^\n]", (temp+i)->izvodac);
					printf("Unesite novo ime pjesme:");
					scanf(" %19[^\n]", (temp+i)->pjesma);
					printf("Unesite novo ime albuma:");
					scanf(" %19[^\n]", (temp+i)->album);

					fwrite((temp+i), sizeof(ALBUM), 1, fp);
					break;
				}
			}
		}

		fclose(fp);
		free(temp);

	return;
}

void pretrazivanjePjesme() {
	FILE* fp = NULL;
	ALBUM* temp = NULL;
	int index = 0;
	int nadeno = 0;
	int br = 0;
	char trazeno[20];

	fp = fopen("album.bin", "rb");
	if (fp == NULL) {
		printf("Greska.");
		return 1;
	}

	fread(&brojGlazbe, sizeof(int), 1, fp);

	temp = (ALBUM*)malloc(brojGlazbe * sizeof(ALBUM));
	if (temp == NULL) {
		printf("Greska.");
		return 1;
	}

	printf("Unesite ime pjesme:");
	scanf(" %19[^\n]", trazeno);
	fread(temp, sizeof(ALBUM), brojGlazbe, fp);

	for (int i = 0; i < brojGlazbe; i++) {
		if (strcmp((temp + i)->pjesma, trazeno) == 0) {
			br++;
			printf("\nPjesma je %d. nadena!\n",br);
			printf("\nPjesma:%s", (temp + i)->pjesma);
			printf("\nIzvodac:%s", (temp + i)->izvodac);
			printf("\nAlbum:%s\n", (temp + i)->album);

			nadeno = 1;
		}
	}

	printf("\n");

	if (nadeno == 0) {
		printf("Pjesma nije nadena.\n");
	}

	fclose(fp);
	free(temp);
	
	return;
}

void pretrazivanjeIzvodaca() {
	FILE* fp = NULL;
	ALBUM* temp = NULL;
	int index = 0;
	int nadeno = 0;
	int br = 0;
	char trazeno[20];

	fp = fopen("album.bin", "rb");
	if (fp == NULL) {
		printf("Greska.");
		return 1;
	}

	fread(&brojGlazbe, sizeof(int), 1, fp);

	temp = (ALBUM*)malloc(brojGlazbe * sizeof(ALBUM));
	if (temp == NULL) {
		printf("Greska.");
		return 1;
	}

	printf("Unesite ime izvodaca:");
	scanf(" %19[^\n]", trazeno);
	fread(temp, sizeof(ALBUM), brojGlazbe, fp);

	for (int i = 0; i < brojGlazbe; i++) {
		if (strcmp((temp + i)->izvodac, trazeno) == 0) {
			br++;
			printf("\nIzvodac je %d. naden!\n",br);
			printf("\nIzvodac:%s", (temp + i)->izvodac);
			printf("\nPjesma:%s", (temp + i)->pjesma);
			printf("\nAlbum:%s\n", (temp + i)->album);

			nadeno = 1;
		}
	}

	printf("\n");

	if (nadeno == 0) {
		printf("Izvodac nije nadena.\n");
	}

	fclose(fp);
	free(temp);

	return;
}

void pretrazivanjeAlbuma() {
	FILE* fp = NULL;
	ALBUM* temp = NULL;
	int index = 0;
	int nadeno = 0;
	int br = 0;
	char trazeno[20];

	fp = fopen("album.bin", "rb");
	if (fp == NULL) {
		printf("Greska.");
		return 1;
	}

	fread(&brojGlazbe, sizeof(int), 1, fp);

	temp = (ALBUM*)malloc(brojGlazbe * sizeof(ALBUM));
	if (temp == NULL) {
		printf("Greska.");
		return 1;
	}

	printf("Unesite ime albuma:");
	scanf(" %19[^\n]", trazeno);
	fread(temp, sizeof(ALBUM), brojGlazbe, fp);

	for (int i = 0; i < brojGlazbe; i++) {
		if (strcmp((temp + i)->album, trazeno) == 0) {
			br++;
			printf("\nAlbum je %d. naden!\n", br);
			printf("\nAlbum:%s\n", (temp + i)->album);
			printf("\nPjesma:%s", (temp + i)->pjesma);
			printf("\nIzvodac:%s", (temp + i)->izvodac);

			nadeno = 1;
		}
	}

	printf("\n");

	if (nadeno == 0) {
		printf("Album nije nadena.\n");
	}

	fclose(fp);
	free(temp);

	return;
}

void brisanjeGlazbe() {

	return;
}

void brisanjeDatoteke() {
	char odgovor;
	int x;
	char fp[] = "album.bin";
	printf("Jeste li sigurni da zelite obrisati datoteku (Y/N):");
	getchar();

	while (1) {
		scanf("%c", &odgovor);
		if ((odgovor == 'Y') || (odgovor == 'N')) {
			break;
		}
		printf("Krivi unos:");
		scanf("%c", &odgovor);
	}

	if (odgovor == 'Y') {
		x = remove(fp);
		if (x == 0) {
			printf("Datoteka uspjesno obrisana.");
			return;
		}
		else {
			printf("Datoteka ne uspjesno obrisana.");
			return;
		}
	}

	if (odgovor == 'N') {
		return 0;
	}

	return;
}

void izlaz() {
	char odgovor;
	printf("Jeste li sigurni da zelite izaci iz programa (Y/N):");
	getchar();

	while (1) {
		scanf("%c", &odgovor);
		if ((odgovor == 'Y') || (odgovor == 'N')) {
			break;
		}
		printf("Krivi unos:");
		scanf("%c", &odgovor);
	}

	if (odgovor == 'Y') {
		exit(0);
	}
	else {
		return 0;
	}
}

