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
	ALBUM* temp=NULL;

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
			return ;
		}else{
			rewind(fp);
			fread(&brojGlazbe,sizeof(int),1,fp);
			brojGlazbe++;
			rewind(fp);
			fwrite(&brojGlazbe,sizeof(int),1,fp);
			rewind(fp);
			fwrite(temp,sizeof(ALBUM),1,fp);
			fclose(fp);
		}
	}
	
	fclose(fp);
	free(temp);

	return;
}

void ispisGlazbe() {
	int n = 0;
	int i = 0;
	FILE* fp = NULL;
	ALBUM* temp = NULL;

	fp = fopen("album.bin", "rb");
	if (fp == NULL) {
		printf("Album je prazan.");
		return;
	}

	fread(&n, sizeof(int), 1, fp);
	if (n == 0) {
		printf("Album je prazan.");
		return;
	}

	temp = (ALBUM*)malloc(n * sizeof(ALBUM));
	if (temp == NULL) {
		printf("Greska.");
		return 1;
	}

	fread(temp, sizeof(ALBUM), 1, fp);

	printf("Postoje %d. spremljene glazbe.",n);

	for (i = 0;i < n;i++) {
		printf("\n\nArtist:%s", (temp + i)->izvodac);
		printf("\nAlbum:%s", (temp + i)->pjesma);
		printf("\nGenre:%s", (temp + i)->album);
	}

	fclose(fp);
	free(temp);

	return;
}

void urediGlazbu() {
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

