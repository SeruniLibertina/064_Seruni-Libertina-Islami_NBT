#ifndef NONBINARYTREES_H
#define NONBINARYTREES_H

#include "boolean.h"

#define JML_MAKS 20    // Maksimal jumlah simpul
#define NIL 0          // Penanda indeks kosong

typedef char infotype;  // Tipe data simpul
typedef int address;    // Indeks sebagai alamat simpul

// Struktur simpul non-biner
typedef struct {
    infotype info;     // Data simpul
    address ps_fs;     // Indeks anak pertama
    address ps_nb;     // Indeks saudara berikutnya
    address ps_pr;     // Indeks parent
} nbtree;

typedef nbtree Isi_Tree[JML_MAKS+1];

/* Prototipe fungsi ADT */
void Create_tree(Isi_Tree X, int Jml_Node);
boolean IsEmpty(Isi_Tree P);
void PreOrder(Isi_Tree P);
void InOrder(Isi_Tree P);
void PostOrder(Isi_Tree P);
void Level_order(Isi_Tree X, int Maks_node);
void PrintTree(Isi_Tree P);
boolean Search(Isi_Tree P, infotype X);
int nbElmt(Isi_Tree P);
int nbDaun(Isi_Tree P);
int LevelNode(Isi_Tree P, infotype X);
int Depth(Isi_Tree P);
int Max(int a, int b);

// Utility tambahan untuk tugas lanjutan
void PrintArrayTree(Isi_Tree P, int N);

#endif 
