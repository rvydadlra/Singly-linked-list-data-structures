/* 
* @file Dugum.cpp
* @description Bir sayıyı ve basamaklarını tutan iki tane tek yönlü bağlı listeyi birbirine bağlamak
* @course İkinci Öğretim B grubu
* @assignment 1.Ödev
* @date Kodu 25.11.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

    Dugum::Dugum() : headsayiListesi(new Sayi()), Nextdugum(nullptr) {}

    Dugum::~Dugum() {
        delete headsayiListesi;
    }