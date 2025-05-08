#include<iostream>
#include<string.h>
using namespace std;

class node{
public:
    int noMhs;
    node *next;
};

class list{
    node *start;
    
    
    public:
    list(){
        start = NULL;
    }
    
    void addnode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;
        node *nodebaru = new node;
        nodebaru->noMhs = nim;
    
        if (start == NULL || nim <= start->noMhs){
            if ((start != NULL) && (nim == start->noMhs)){
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodebaru->next = start;
            start = nodebaru;
            return;
        }

        node *previous = start;
        node *current = start;

        while ((current != NULL) && (nim >= current->noMhs)){
            if (nim == current->noMhs){
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }
    }
    };