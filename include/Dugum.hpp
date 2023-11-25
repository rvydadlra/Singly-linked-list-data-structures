/* 
* @file Dugum.hpp
* @description Bir sayıyı ve basamaklarını tutan iki tane tek yönlü bağlı listeyi birbirine bağlamak
* @course İkinci Öğretim B grubu
* @assignment 1.Ödev
* @date Kodu 25.11.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#ifndef Dugum_HPP
#define Dugum_HPP_HPP
#include "Sayi.hpp"

class Dugum {
public:
    Sayi* headsayiListesi;
    Dugum* Nextdugum;
	Dugum();
    ~Dugum();
};









#endif