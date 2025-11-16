#include <stdio.h>
#include <windows.h>

void keluar(const char *teks, int delay){
    for (int i = 0; teks[i] != '\0'; i++){
        printf("%c", teks[i]);
        fflush(stdout);
        Sleep(delay);
    }
}

int main(){
    keluar("I got my driver's license last week\n",120);
        Sleep(4000);
    keluar("just like we always talked about\n",40);
        Sleep(3000);
    keluar("'cause you to excited for me\n", 20);
return 0;
}