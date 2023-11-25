/* 
* @file Sayi.cpp
* @description Bir sayıyı ve basamaklarını tutan iki tane tek yönlü bağlı listeyi birbirine bağlamak
* @course İkinci Öğretim B grubu
* @assignment 1.Ödev
* @date Kodu 25.11.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#include "Sayi.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

    Sayi::Sayi() : head(nullptr), elemansayisi(0), sayi(0) {}
Sayi::~Sayi() {
        Basamak* current = head;
        while (current) {
            Basamak* temp = current;
            current = current->Nextdugum;
            delete temp;
        }
    }
   int Sayi::Count() {
        return elemansayisi;
    }

   bool Sayi::bosmu() {
        return head == nullptr;
    }

  void  Sayi::basamakekle(int basamak) {
        Basamak* yeniBasamak = new Basamak(basamak);
        yeniBasamak->Nextdugum = head;
        head = yeniBasamak;
        elemansayisi++;
    }

    void Sayi::adresleriYazdir() {
            Basamak* current = head;
        stringstream stream;
        cout << "###########";
            for (int i = 0; i < elemansayisi; ++i) {
                std::cout << "  ******* ";
            }
            cout << endl;

        stream << "#" << this << "#" <<"  ";


        while (current) {
            stringstream stream1;
            stream1 << hex << reinterpret_cast<std::uintptr_t>(current);
            string sonuc = stream1.str();
            string sonUcKarakter = sonuc.substr(sonuc.length() - 3);

            stream << setw(1)<< "*"<< setw(4)<< sonUcKarakter << setw(3)<<"* " <<"  ";
            current = current->Nextdugum;
        }

        cout << stream.str() << endl;
        cout << "#---------#";
        for (int i = 0; i < elemansayisi; ++i) {
            std::cout << "  ******* ";
        }
        cout << endl;

        current = head;
        cout << "#" << setw(9) << sayi << "#";
        
cout <<"  ";
        while (current) {
           cout <<setw(1)<< "*"<< setw(4)<< current->Veri << setw(3)<<"* " <<"  ";
            current = current->Nextdugum;
        }
        cout << endl << "###########";
        for (int i = 0; i < elemansayisi; ++i) {
            std::cout << "  ******* ";
        }
        cout << endl<<endl<<endl;
        
    }

    void Sayi::sayiYazdir() {
      //   cout << "###########" <<endl;
        //cout << "#" <<this <<"#"<<endl;
        //cout << "#---------#" <<endl;
        //cout << "#" << setw(9) << sayi << "#"<< endl;
        //cout << "###########" <<endl;
        adresleriYazdir();
    }

    void Sayi::tekBasamaklariBasaAl() {
        Basamak* tekler = nullptr;
        Basamak* ciftler = nullptr;

        Basamak* current = head;

        while (current) {
            if (current->Veri % 2 == 1) {
                Basamak* temp = current;
                current = current->Nextdugum;

                temp->Nextdugum = tekler;
                tekler = temp;
            }
            else {
                Basamak* temp = current;
                current = current->Nextdugum;

                temp->Nextdugum = ciftler;
                ciftler = temp;
            }
        }

        // Tekler ile ciftleri birleştir
        if (tekler) {
            Basamak* temp = tekler;
            while (temp->Nextdugum) {
                temp = temp->Nextdugum;
            }
            temp->Nextdugum = ciftler;

            head = tekler;
        }
        else {
            head = ciftler;
        }

        // Sayının kendisine de aynı işlemi uygula
        long long yeniSayi = 0;
        int katsayi = 1;
        Basamak* temp = head;
        while (temp) {
            yeniSayi = yeniSayi * 10 + temp->Veri;
            temp = temp->Nextdugum;
        }
        sayi = yeniSayi;
    }

    void Sayi::tersCevir() {
        Basamak* prev = nullptr;
        Basamak* current = head;
        Basamak* next = nullptr;

        while (current) {
            next = current->Nextdugum;
            current->Nextdugum = prev;
            prev = current;
            current = next;
        }

        head = prev;

        // Sayının kendisine de aynı işlemi uygula
        long long yeniSayi = 0;
        int katsayi = 1;
        Basamak* temp = head;
        while (temp) {
            yeniSayi = yeniSayi * 10 + temp->Veri;
            temp = temp->Nextdugum;
        }
        sayi = yeniSayi;
    }