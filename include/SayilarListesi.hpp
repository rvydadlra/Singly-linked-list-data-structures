/* 
* @file SayilarListesi.hpp
* @description Bir sayıyı ve basamaklarını tutan iki tane tek yönlü bağlı listeyi birbirine bağlamak
* @course İkinci Öğretim B grubu
* @assignment 1.Ödev
* @date Kodu 25.11.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#ifndef SayilarListesi_HPP
#define SayilarListesi_HPP
#include "Sayi.hpp"
#include "Dugum.hpp"
class SayilarListesi {
public:
    Dugum* head;
    int elemansayisi;

    SayilarListesi();

    int Count();

    bool bosmu();

    void sayiEkle(Sayi* sayi);

    void yazdir();

    void tekleriBasaAl();

    void tersCevir();

    void silEnBuyugu();

    ~SayilarListesi();
    
};


#endif