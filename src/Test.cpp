/* 
* @file Test.cpp
* @description Bir sayıyı ve basamaklarını tutan iki tane tek yönlü bağlı listeyi birbirine bağlamak
* @course İkinci Öğretim B grubu
* @assignment 1.Ödev
* @date Kodu 25.11.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "SayilarListesi.hpp"
#include "Sayi.hpp"
#include "Basamak.hpp"
using namespace std;
int main() {
ifstream dosyaOku("Sayilar.txt");
SayilarListesi* liste = new SayilarListesi();

    if (!dosyaOku.is_open()) {
        std::cout << "Dosya acilamadi.";
        return 1;
    }

    long long sayi;
    while (dosyaOku >> sayi) {
        Sayi* yeniSayi = new Sayi();
        yeniSayi->sayi = sayi;
        while (sayi > 0) {
            int basamak = sayi % 10;
            yeniSayi->basamakekle(basamak);
            sayi /= 10;
        }
        liste->sayiEkle(yeniSayi);
    }

    dosyaOku.close();
    liste->yazdir();

    int secim;
    while (true) {
        cout << "1. Tek Sayilari Basa Al" << endl;
        cout << "2. Basamaklari Tersle" << endl;
        cout << "3. En Buyuk Cikar" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim == 1) {
            liste->tekleriBasaAl();
	        liste->yazdir();

        }
        else if (secim == 2) {
            liste->tersCevir();
			liste->yazdir();
        }
        else if (secim == 3) {
            liste->silEnBuyugu();
        }
        else if (secim == 4) {
		   break;
		   system("pause");
        }
        else {
            cout << "Gecersiz secenek. Tekrar deneyin." << endl;
        }
    }

    delete liste;
return 0;
}