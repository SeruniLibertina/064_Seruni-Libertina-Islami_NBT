#include <stdio.h>
#include <stdlib.h>
#include "nonBinaryTrees.h"

static void PreOrderRec(Isi_Tree P, address idx) {
    if (idx != NIL) {
        printf("%c ", P[idx].info);
        PreOrderRec(P, P[idx].ps_fs);
        PreOrderRec(P, P[idx].ps_nb);
    }
}

static void InOrderRec(Isi_Tree P, address idx) {
    if (idx != NIL) {
        InOrderRec(P, P[idx].ps_fs);
        printf("%c ", P[idx].info);
        InOrderRec(P, P[idx].ps_nb);
    }
}

static void PostOrderRec(Isi_Tree P, address idx) {
    if (idx != NIL) {
        PostOrderRec(P, P[idx].ps_fs);
        PostOrderRec(P, P[idx].ps_nb);
        printf("%c ", P[idx].info);
    }
}

void Create_tree(Isi_Tree X, int Jml_Node) {
    for (int i = 1; i <= JML_MAKS; i++) {
        X[i].info = '\0';
        X[i].ps_fs = X[i].ps_nb = X[i].ps_pr = NIL;
    }
    printf("Masukkan data dan indeks parent setiap node (0 jika akar):\n");
    for (int i = 1; i <= Jml_Node; i++) {
        char ch;
        int parent;
        printf("Node %d - Info (char): ", i);
        scanf(" %c", &ch);
        X[i].info = ch;
        printf("Node %d - Parent index: ", i);
        scanf("%d", &parent);
        if (parent != NIL) {
            if (X[parent].ps_fs == NIL)
                X[parent].ps_fs = i;
            else {
                int sib = X[parent].ps_fs;
                while (X[sib].ps_nb != NIL) sib = X[sib].ps_nb;
                X[sib].ps_nb = i;
            }
            X[i].ps_pr = parent;
        }
    }
}

boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == '\0');
}

void PreOrder(Isi_Tree P) {
    printf("PreOrder: "); PreOrderRec(P, 1); printf("\n");
}
void InOrder(Isi_Tree P) {
    printf("InOrder: "); InOrderRec(P, 1); printf("\n");
}
void PostOrder(Isi_Tree P) {
    printf("PostOrder: "); PostOrderRec(P, 1); printf("\n");
}
void Level_order(Isi_Tree X, int Maks_node) {
    printf("Level Order: ");
    int queue[JML_MAKS], head = 0, tail = 0;
    if (X[1].info != '\0') queue[tail++] = 1;
    while (head < tail) {
        int idx = queue[head++];
        printf("%c ", X[idx].info);
        if (X[idx].ps_fs != NIL) queue[tail++] = X[idx].ps_fs;
        if (X[idx].ps_nb != NIL) queue[tail++] = X[idx].ps_nb;
    }
    printf("\n");
}
void PrintTree(Isi_Tree P) { Level_order(P, JML_MAKS); }
boolean Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= JML_MAKS; i++) if (P[i].info == X) return true;
    return false;
}
int nbElmt(Isi_Tree P) {
    int cnt = 0;
    for (int i = 1; i <= JML_MAKS; i++) if (P[i].info != '\0') cnt++;
    return cnt;
}
int nbDaun(Isi_Tree P) {
    int cnt = 0;
    for (int i = 1; i <= JML_MAKS; i++) if (P[i].info != '\0' && P[i].ps_fs == NIL) cnt++;
    return cnt;
}
int LevelNode(Isi_Tree P, infotype X) {
    int idx = 1;
    while (idx <= JML_MAKS && P[idx].info != X) idx++;
    if (idx > JML_MAKS) return -1;
    int lvl = 0;
    while (P[idx].ps_pr != NIL) {
        lvl++;
        idx = P[idx].ps_pr;
    }
    return lvl;
}
int Depth(Isi_Tree P) {
    int max = 0;
    for (int i = 1; i <= JML_MAKS; i++) {
        if (P[i].info != '\0') {
            int lvl = 0, cur = i;
            while (P[cur].ps_pr != NIL) {
                lvl++;
                cur = P[cur].ps_pr;
            }
            if (lvl > max) max = lvl;
        }
    }
    return max;
}
int Max(int a, int b) { return (a > b) ? a : b; }

void PrintArrayTree(Isi_Tree P, int N) {
    for (int i = 1; i <= N; i++) {
        printf("--> Indeks ke-%d\n", i);
        printf("-----------------------------\n");
        printf("info array ke %d    : %c\n", i, P[i].info);
        printf("first son array ke %d: %d\n", i, P[i].ps_fs);
        printf("next brother array ke %d: %d\n", i, P[i].ps_nb);
        printf("parent array ke %d   : %d\n", i, P[i].ps_pr);
        printf("-----------------------------\n\n");
    }
    printf("Klik apapun untuk melanjutkan!\n");
    getchar(); getchar(); // tunggu
}

