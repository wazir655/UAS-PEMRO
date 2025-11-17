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

// FILE *out = fopen("kosakata.txt", "a");
// if (!out){
//         printf("File kosakata tidak ditemukan\n");
//         free(buffer);
//         free(list);
//         return 0;
//}

    for(int i = 0; i < count; i++){
        for(int j = i + 1; j < count; j++){
            if(strcmp(list[i], list[j]) == 0){
                printf("%s=\n",list[i]);
                //fprintf(out, "%s\n", list[i]);
                break;
            }
        }
    }

    free(buffer);
    free(list);
    return 0;
}


int main(){
    login();
    return 0;
}
