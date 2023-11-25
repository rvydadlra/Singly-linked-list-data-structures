/* 
* @file Basamak.hpp
* @description Bir sayıyı ve basamaklarını tutan iki tane tek yönlü bağlı listeyi birbirine bağlamak
* @course İkinci Öğretim B grubu
* @assignment 1.Ödev
* @date Kodu 25.11.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#ifndef Basamak_HPP
#define Basamak_HPP


class Basamak {
public:
    int Veri;
    Basamak* Nextdugum;

    Basamak(const int veri);
};
#endif