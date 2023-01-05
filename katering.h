#ifndef KATERING_H_INCLUDED
#define KATERING_H_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;

#define info(p) (p)->info
#define nextTanggal(p) (p)->nextTanggal
#define nextMenu(p) (p)->nextMenu
#define first(l) ((l).first)

typedef struct elm_tanggal *adr_tanggal;
typedef struct elm_menu *adr_menu;

struct elm_tanggal{
    int info;
    adr_menu nextMenu;
    adr_tanggal nextTanggal;
};

struct elm_menu{
    string info;
    adr_menu nextMenu;
};

struct list_tanggal{
    adr_tanggal first;
};

//Tanggal
bool isTanggalKosong(list_tanggal lt);
void createelm_tanggal(adr_tanggal &pt, int info);
void createlist_tanggal(list_tanggal &lt);
void insert_tanggal(list_tanggal &lt, adr_tanggal pt);
void showlist_tanggal(list_tanggal lt, int tanggal);

//Menu
bool isMenuExistinTanggal(list_tanggal lt, int tanggal, string menu);
void createelm_menu(adr_menu &pm, string info);
void insert_menu(list_tanggal &lt, int tanggal, adr_menu pm);
void showlist_menu(adr_menu pm);
void delete_menu(list_tanggal &lt, int tanggal, string menu);

#endif // KATERING_H_INCLUDED
