#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

void lichessfnspuzzle(const string &dosyaadi){
    ifstream dosya(dosyaadi);
    ofstream dosyayaz("lichess.pgn", ios::out);

    if (dosya.is_open() && dosyayaz.is_open()) {
        string ilkSatir;
        while (getline(dosya, ilkSatir)) {
        int n = 1;

            size_t pozisyon = ilkSatir.find('[');

            if (pozisyon != string::npos) {
                string sonrakiSatir = ilkSatir.substr(pozisyon);
                cout << n << ". puzzle: " << sonrakiSatir << endl << endl;
                
                dosyayaz << sonrakiSatir << endl << endl << endl;
            } else {
                cout << "Unsupported syntax! Sorry." << endl << endl;
            }

            
            
        } 
       if (!dosya.is_open()){
            cout << "File could not be opened!" << endl;
        }
        dosya.close();
        dosyayaz.close();
        cout << "The output was saved in a file named lichess.pgn" << endl;
    }

}

void lucaschessfnspuzzle(const string &dosyaadi){
    size_t dosyaninadi = dosyaadi.find('.');
    string dosyaninadialtdize = dosyaadi.substr(0, dosyaninadi - 1);
    string dosyaninadiustdize = dosyaninadialtdize + ".pgn";
    ifstream dosyaoku(dosyaadi);
    ofstream dosyayaz(dosyaninadiustdize, ios::out);

    if (dosyaoku.is_open() && dosyayaz.is_open())
    {
        string ilksatir1;
        
        while (getline(dosyaoku, ilksatir1)) {
            size_t pozisyonbas = 0;
            int sayac1 = 0;
                size_t pozisyon1 = ilksatir1.find('|'); 
                size_t pozisyon2 = ilksatir1.find(">|"); 
                size_t pozisyon3 = ilksatir1.find("|[", pozisyon2); 
                string altdize1 = ilksatir1.substr(0, pozisyon1 - 1);
                string altdize2 = ilksatir1.substr(pozisyon2 + 2, pozisyon3 - pozisyon2 - 2);

            cout << "[FEN \"" << altdize1 << "\"]" << endl;
            dosyayaz << "[FEN \"" << altdize1 << "\"]" << endl;
            while ((pozisyonbas = ilksatir1.find("[", pozisyonbas)) != string::npos) {
                
                
                size_t sonrakiPozisyon = ilksatir1.find("]", pozisyonbas); 
                if (sonrakiPozisyon != string::npos) {
                    
                    string parantezdize = ilksatir1.substr(pozisyonbas, sonrakiPozisyon - pozisyonbas + 1);
                    cout << parantezdize << endl;
                    dosyayaz << parantezdize << endl;
                    pozisyonbas = sonrakiPozisyon + 1; 
                    sayac1++;
                        if(sayac1 == 10){
                        cout << altdize2;
                        dosyayaz << altdize2;
                        dosyayaz << endl << endl;
                        cout << endl << endl;

                        
                    }

                    
                } else {
                    
                    break;
                }
            }
        }
        



        dosyaoku.close();
        dosyayaz.close();

        cout << "The output was saved in a file named " << dosyaninadiustdize << endl;

        
    }
    else{
        cout << "Dosya acilamadi";
    }


}
int main(){
    int x;
    int x1;
    string yol;

    cout << "Language:\n\n" << "1 = Turkce\n" << "2 = English";
    cin >> x;

    switch (x)
    {
        case 1:
        cout << "Donusturulecek FNS dosyasinin turunu secin:\n1- Lichess bulmacalari\n2- Diger bulmacalar";
        cin >> x1;
        switch (x1)
        {
        case 1:
            cout << "Dosya adini giriniz: ";
            cin >> yol;
            cout << endl << endl;
            lichessfnspuzzle(yol);
            break;
        
        
        case 2:
            cout << "Dosya adini giriniz: ";
            cin >> yol;
            cout << endl << endl;
            lucaschessfnspuzzle(yol);
            break;
        
        default:
            break;
        }
        break;


    case 2:
        cout << "Select the type of FNS file to convert:\n1- Lichess puzzles\n2- Other puzzles";
        cin >> x1;
        switch (x1)
        {
        case 1:
            cout << "Enter the file name: ";
            cin >> yol;
            cout << endl << endl;
            lichessfnspuzzle(yol);
            break;
        
        
        case 2:
            cout << "Enter the file name: ";
            cin >> yol;
            cout << endl << endl;
            lucaschessfnspuzzle(yol);
            break;
        
        default:
            break;
        }
        break;
        break;
    
    default:
        break;
    }


getch();
return 0;
}