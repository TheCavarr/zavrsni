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
		urediGlazbu();
		break;

	case 3:
		ispisGlazbe();
		break;

	case 4:
		pretrazivanjePjesma();
		break;

	case 5:
		pretrazivanjeIzvodac();
		break;

	case 6:
		pretrazivanjeAlbum();
		break;

	case 7:
		brisanjeGlazbe();
		break;

	case 8:
		izlaz();
		break;

	}
}

void dodajGlazbu() {
	FILE* fp = NULL;
	ALBUM* temp;

	temp = (ALBUM*)malloc(sizeof(ALBUM));
	if (temp == NULL) {
		printf("Greska.");
		return 1;
	}

	printf("Unesite ime pjesme:");
	scanf(" %19[^\n]", temp->pjesma);
	printf("Unesite ime izvodaca:");
	scanf(" %19[^\n]", temp->izvodac);
	printf("Unesite ime albuma:");
	scanf(" %19[^\n]", temp->album);

	fp = fopen("album.bin","rb");

	if (fp == NULL) {
		fp = fopen("album.bin", "wb");
		fseek(fp, sizeof(ALBUM) * brojGlazbe, SEEK_CUR);
		fwrite(&temp, sizeof(ALBUM), 1, fp);
		rewind(fp);
		brojGlazbe++;
		fwrite(&brojGlazbe,sizeof(int),1,fp);
		fclose(fp);
	}else{
		fclose(fp);
		fp=fopen("album.bin","rb+");
		if(fp==NULL){
			printf("Greska.");
			return 1;
		}else{
			rewind(fp);
			fread(%brojGlazbe,sizeof(int),1,fp);
			brojGlazbe++;
			rewind(fp);
			fwrite(%brojGlazbe,sizeof(int),1,fp);
			rewind(fp);
			fwrite(temp,sizeof(ALBUM),1,fp);
			fclose(fp);
		}
	}
	
	fclose(fp);
	free(temp);

	return;
}

void urediGlazbu() {
	return;
}

void ispisGlazbe() {
	return;
}

void pretrazivanjePjesma() {
	return;
}

void pretrazivanjeIzvodac() {
	return;
}

void pretrazivanjeAlbum() {
	return;
}

void brisanjeGlazbe() {
	return;
}

void izlaz() {
	return;
}

