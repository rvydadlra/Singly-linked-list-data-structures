/* 
* @file SayilarListesi.cpp
* @description Bir sayıyı ve basamaklarını tutan iki tane tek yönlü bağlı listeyi birbirine bağlamak
* @course İkinci Öğretim B grubu
* @assignment 1.Ödev
* @date Kodu 25.11.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#include "SayilarListesi.hpp"
#include <iostream>
#include <limits>

using namespace std;

    SayilarListesi::SayilarListesi() : head(nullptr), elemansayisi(0) {}

    int SayilarListesi::Count() {
        return elemansayisi;
    }

    bool SayilarListesi:: bosmu() {
        return head == nullptr;
    }

    void SayilarListesi::sayiEkle(Sayi* sayi) {
        Dugum* yenibasamak = new Dugum();
        yenibasamak->headsayiListesi = sayi;
        yenibasamak->headsayiListesi->sayi = stoll(to_string(sayi->sayi));
        if (bosmu()) {
            head = yenibasamak;
        }
        else {
            Dugum* temp = head;
            while (temp->Nextdugum) {
                temp = temp->Nextdugum;
            }
            temp->Nextdugum = yenibasamak;
        }
        elemansayisi++;
    }

    void SayilarListesi::yazdir() {
        Dugum* current = head;
        while (current) {
            current->headsayiListesi->sayiYazdir();
            current = current->Nextdugum;
        }
    }

    void SayilarListesi::tekleriBasaAl() {
        Dugum* current = head;
        while (current) {
            current->headsayiListesi->tekBasamaklariBasaAl();
            current = current->Nextdugum;
        }
        cout << "Tek sayilar basa alindi." << endl;
    }

    void SayilarListesi::tersCevir() {
        Dugum* current = head;
        while (current) {
            current->headsayiListesi->tersCevir();
            current = current->Nextdugum;
        }
        cout << "Sayilar ters cevirildi." << endl;
    }

    void SayilarListesi::silEnBuyugu() {
        Dugum* enBuyuk = nullptr;
        Dugum* onceki = nullptr;
        Dugum* oncekiEnBuyuk = nullptr;

        Dugum* current = head;
        long long maxSayi = numeric_limits<long long>::min();

        while (current) {
            if (current->headsayiListesi->sayi > maxSayi) {
                maxSayi = current->headsayiListesi->sayi;
                enBuyuk = current;
                oncekiEnBuyuk = onceki;
            }
            onceki = current;
            current = current->Nextdugum;
        }

        if (enBuyuk) {
            if (oncekiEnBuyuk) {
                oncekiEnBuyuk->Nextdugum = enBuyuk->Nextdugum;
            }
            else {
                head = enBuyuk->Nextdugum;
            }
            delete enBuyuk;
        }

        yazdir();
    }

    SayilarListesi::~SayilarListesi() {
        Dugum* current = head;
        while (current) {
            Dugum* temp = current;
            current = current->Nextdugum;
            delete temp;
        }
    }