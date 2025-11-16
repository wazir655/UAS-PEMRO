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
    keluar("I got my driver's license last week\n",70);
        Sleep(200);
    keluar("just like we always talked about\n",65);
        Sleep(800);
    keluar("'cause you we're so excited for me\n", 55);
        Sleep(600);
    keluar("To finally drive up to your house\n", 50);\
        Sleep(600);
    keluar("But today i drove through the surbubs\n", 50);\
        Sleep(700);
    keluar("Cryin 'cause you weren't around\n", 65);\
        Sleep(4000);
    
    keluar("And you're probably with that blonde girl\n",90);
        Sleep(1500);
    keluar("Who always made me doubt\n",40);
        Sleep(3000);
    keluar("She's so much older than me\n", 20);\
        Sleep(2000);
    keluar("She's everything I'm insecure about\n", 20);\
        Sleep(2000);
    keluar("Yeah, today I drove through the suburbs\n", 20);\
        Sleep(2000);
    keluar("'Cause how could I ever love someone else?\n", 20);\
        Sleep(2000);
    
    keluar("And I know we weren't perfect but I've never felt this way for no one\n",20);
        Sleep(2000);
    keluar("And I just can't imagine how you could be so okay now that I'm gone\n",20);
        Sleep(2000);
    keluar("Guess you didn't mean what you wrote in that song about me", 20);\
        Sleep(2000);
    keluar("Cause you said forever, now I drive alone past your street\n", 20);\
        Sleep(2000);

    keluar("And all my friends\n", 75);
        Sleep(1400);
    keluar("of hearing how much I miss you, but\n", 70);
        Sleep(1500);
    keluar("I kinda feel sorry for them\n", 70);
        Sleep(1400);
    keluar("Cause they'll never know you the way that I do, yeah\n", 65);
        Sleep(2000);
    keluar("Today I drove thrugh the suburbs\n,", 70);
        Sleep(1700);
    keluar("And pictured I was driving home to you\n", 75);
        Sleep(3000);
return 0;

}










