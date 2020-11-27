#include <stdio.h>

struct pasien{
    int tgl;
    char bulan[20];
    int tahun;
    char name[255];
};

struct node{
    pasien n;
    node *next, *prev;
}*head, *tail, *curr; 