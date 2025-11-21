#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_LEN 200


int sudahAda(char daftar[][MAX_LEN], int jumlah, char *kata) {
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(daftar[i], kata) == 0)
            return 1;
    }
    return 0;
}

void bersihkanKata(char *kata) {
    char temp[MAX_LEN];
    int idx = 0;

    for (int i = 0; kata[i] != '\0'; i++) {
        if (isalnum(kata[i]) || kata[i] == '\'') {
            temp[idx++] = tolower(kata[i]);
        }
    }

    temp[idx] = '\0';
    strcpy(kata, temp);
}

int main() {
    FILE *fpIn = fopen("lirik.txt", "r");
    FILE *fpOut = fopen("kosa-kata.word", "w");

    if (!fpIn || !fpOut) {
        printf("Gagal membuka file!\n");
        return 1;
    }

    char baris[MAX_LEN];
    char daftarKata[MAX_WORDS][MAX_LEN];
    int jumlahKata = 0;

    
    fgets(baris, sizeof(baris), fpIn);
    fprintf(fpOut, "%s", baris);  

    
    while (fgets(baris, sizeof(baris), fpIn)) {
        char *token = strtok(baris, " \n");

        while (token != NULL) {
            char kata[MAX_LEN];
            strcpy(kata, token);

            bersihkanKata(kata);

            if (strlen(kata) > 0 && !sudahAda(daftarKata, jumlahKata, kata)) {
                strcpy(daftarKata[jumlahKata++], kata);
            }

            token = strtok(NULL, " \n");
        }
    }

    
    for (int i = 0; i < jumlahKata; i++) {
        fprintf(fpOut, "%s=\n", daftarKata[i]);
    }

    fclose(fpIn);
    fclose(fpOut);

    printf("File kosa-kata.word berhasil dibuat!\n");
    return 0;
}

