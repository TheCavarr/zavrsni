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
void pretrazivanjePjesme();
void pretrazivanjeIzvodaca();
void pretrazivanjeAlbuma();
void brisanjeGlazbe();
void brisanjeDatoteke();
void izlaz();
void sortiranje(ALBUM*);
int comparePjesma(const void* a, const void* b);

extern char odgovor;

/*
void pretrazivanje();
int cmp_ALBUM(const void* a, const void* b);
int cmp_pjesma(const void* a, const void* b);
int cmp_album(const void* a, const void* b);
int cmp_izvodac(const void* a, const void* b);
*/


