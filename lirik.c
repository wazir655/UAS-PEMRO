#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 5000
#define MAX_LEN 100

// Fungsi untuk membersihkan kata dari tanda baca (selain apostrof)
void bersihkanKata(char *word) {
    char temp[MAX_LEN];
    int j = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (isalnum(word[i]) || word[i] == '\'') {
            temp[j++] = tolower(word[i]);  // lowercase
        }
    }
    temp[j] = '\0';
    strcpy(word, temp);
}

// Mengecek apakah kata sudah ada sebelumnya
int sudahAda(char arr[][MAX_LEN], int count, char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(arr[i], word) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *in = fopen("lirik.txt", "r");
    FILE *out = fopen("kosa-kata.word", "w");

    if (!in || !out) {
        printf("Gagal membuka file!\n");
        return 1;
    }

    char judul[200];
    fgets(judul, sizeof(judul), in);   // baca judul

    fprintf(out, "%s", judul);         // tulis judul ke output

    char kata[MAX_WORDS][MAX_LEN];
    int jumlahKata = 0;

    char buffer[MAX_LEN];

    // Membaca semua kata dalam file
    while (fscanf(in, "%s", buffer) != EOF) {
        bersihkanKata(buffer);

        if (strlen(buffer) == 0)
            continue;

        if (!sudahAda(kata, jumlahKata, buffer)) {
            strcpy(kata[jumlahKata++], buffer);
        }
    }

    // Tulis semua kosa kata ke file output
    for (int i = 0; i < jumlahKata; i++) {
        fprintf(out, "%s=\n", kata[i]);
    }

    fclose(in);
    fclose(out);

    printf("File 'kosa-kata.word' berhasil dibuat!\n");
    return 0;
}
