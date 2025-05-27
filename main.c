#include <stdio.h>
#include <stdlib.h>
#include "nonBinaryTrees.h"

int main() {
    Isi_Tree tree;
    int N, pilihan;
    printf("Jumlah node: "); scanf("%d", &N);
    Create_tree(tree, N);
    if (IsEmpty(tree)) { printf("Tree kosong.\n"); return 0; }

    do {
        system("clear || cls");
        printf("Menu Program Operasi Non Binary Tree:\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree (Level Order)\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: "); scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: PreOrder(tree); break;
            case 2: InOrder(tree); break;
            case 3: PostOrder(tree); break;
            case 4: Level_order(tree, N); break;
            case 5: PrintArrayTree(tree, N); break;
            case 6: {
                char key;
                printf("Cari node (char): "); scanf(" %c", &key);
                printf("Node %c %s ditemukan\n", key,
                       Search(tree, key) ? "" : "tidak ");
                break;
            }
            case 7: printf("Jumlah daun: %d\n", nbDaun(tree)); break;
            case 8: {
                char key;
                printf("Cari level node (char): "); scanf(" %c", &key);
                printf("Level node %c: %d\n", key, LevelNode(tree, key));
                break;
            }
            case 9: printf("Kedalaman tree: %d\n", Depth(tree)); break;
            case 10: {
                char a, b;
                printf("Node pertama (char): "); scanf(" %c", &a);
                printf("Node kedua (char): "); scanf(" %c", &b);
                int l1 = LevelNode(tree, a);
                int l2 = LevelNode(tree, b);
                if (l1 < 0 || l2 < 0) {
                    printf("Salah satu node tidak ditemukan\n");
                } else if (l1 < l2) {
                    printf("Node %c lebih dekat ke root daripada %c\n", a, b);
                } else if (l1 > l2) {
                    printf("Node %c lebih jauh dari root daripada %c\n", a, b);
                } else {
                    printf("Node %c dan %c berada pada level yang sama\n", a, b);
                }
                break;
            }
            case 11: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak valid\n");
        }
        if (pilihan != 11) {
            printf("Tekan Enter untuk kembali ke menu...");
            getchar(); getchar();
        }
    } while (pilihan != 11);

    return 0;
}

