#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int login(){
    FILE *fp = fopen("lirik.txt", "r");
    if (!fp){
        printf("File lirik tidak ditemukan\n");
        return 0;
    }

    char *buffer = NULL;
    long size = 0;
    int ch;

    while((ch = fgetc(fp)) != EOF){
        buffer = realloc(buffer, size + 2);
        buffer[size] = ch;
        size++;
    }
    buffer[size] = '\0';
    fclose(fp);

    char **list = NULL;
    int count = 0;

    char *kata = strtok(buffer, " \n,");
    while(kata != NULL){
        list = realloc(list, (count + 1) * sizeof(char *));
        list[count] = kata;
        count++;
        kata = strtok(NULL, " \n,");
    }

    FILE *out = fopen("kosakata.txt", "a");
    if (!out){
        free(buffer);
        free(list);
        return 0;
    }

    char **sudah = NULL;
    int jumlahSudah = 0;

    for(int i = 0; i < count; i++){
        for(int j = i + 1; j < count; j++){
            if(strcmp(list[i], list[j]) == 0){
                int pernah = 0;
                for(int k = 0; k < jumlahSudah; k++){
                    if(strcmp(sudah[k], list[i]) == 0){
                        pernah = 1;
                        break;
                    }
                }
                if(!pernah){
                    fprintf(out, "%s=\n", list[i]);
                    sudah = realloc(sudah, (jumlahSudah + 1) * sizeof(char *));
                    sudah[jumlahSudah] = list[i];
                    jumlahSudah++;
                }
                break;
            }
        }
    }

    free(sudah);
    free(buffer);
    free(list);
    fclose(out);

    printf("Telah disalin ke kosakata tanpa duplikat\n");
    return 0;
}

int main(){
    login();
    return 0;
}
