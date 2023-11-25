/* 
* @file Sayi.hpp
* @description Bir sayıyı ve basamaklarını tutan iki tane tek yönlü bağlı listeyi birbirine bağlamak
* @course İkinci Öğretim B grubu
* @assignment 1.Ödev
* @date Kodu 25.11.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#ifndef Sayi_HPP
#define Sayi_HPP
#include "Basamak.hpp"
class Sayi {
public:
    Basamak* head;
    int elemansayisi;
    long long sayi;
	~Sayi();

    Sayi();

    int Count();
    bool bosmu();

    void basamakekle(int basamak);
    void adresleriYazdir();

    void sayiYazdir();

    void tekBasamaklariBasaAl();
    void tersCevir();
};




#endif