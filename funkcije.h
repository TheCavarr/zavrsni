#pragma once

typedef struct {
	char izvodac[20];
	char pjesma[20];
	char album[20];
}ALBUM;

void izbornik(int);
void dodajGlazbu();
void urediGlazbu();
void ispisGlazbe();
void pretrazivanjePjesma();
void pretrazivanjeIzvodac();
void pretrazivanjeAlbum();
void brisanjeGlazbe();
void izlaz();