#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Speaker.h"
#include "domain/h/Word.h"
#include "service/h/WordRepo.h"
#include "service/h/WordRoulette.h"
#include "service/h/Game.h"
#include "interface/h/Frame.h"

#define ENDL '\n'
#define LIM 1000

using namespace std;

int main() {
    WordRepo wr("dictionary.txt");
    // cout << wr.size() << ENDL;
    WordRoulette wordRoulette(wr, 20);
    // Game game(wordRoulette, true);
    Frame frame(0, 0, 6, 3);

    // bool s;
    // do {
    //     s = rand() % 2;
    //     cout << wordRoulette.m_readyWords[wordRoulette.m_currentWordIndex] << ':';
    //     cout << wordRoulette.getForeign() << " | " << wordRoulette.getTranscription() << " | " << wordRoulette.getTranslate();
    //     if (s) {
    //         cout << " + ";
    //     } else {
    //         cout << " - ";
    //     }
    //     cout << '\n';
    // } while (wordRoulette.pass(s));
    // cout << wr.getForeign(33) << ENDL;
    // cout << wr.getTranscription(33) << ENDL;
    // cout << wr.getTranslate(33) << ENDL;
    // cout << wr.getLastUsing(33) << ENDL;
    // cout << wr.wasErrors(33) << ENDL;

    // srand(time(NULL));
    // int a[100];
    // for (int i = 0; i < 100; i++) {
    //     a[i] = 0;
    //     cout << ' ';
    // }
    // cout << '|' << ENDL;
    // int step = LIM / 100;
    // for (int i = 0; i < LIM; i++) {
    //     int n = rand() % 100;
    //     a[n]++;
    //     if(i % step == 0) {
    //         cout << '#' << flush;
    //     }
    // }
    // cout << ENDL;
    // for (int i = 0; i < 100; i++) {
    //     int p = (a[i]* 1000)/LIM;
    //     cout << i << ':';
    //     for (int j = 0; j < p; j++) {
    //         cout << '*';
    //     }
    //     cout << ENDL;
    // }

    // time_t sec = time(NULL);
    // cout << sec << '\n';
    // Speaker speaker;
    // cout << "Hello, World!\n";
    // speaker.speak();
    // cout << "┌─────────┐┌─────────┐\n";
    // cout << "│         │├─────────┤\n";
    // cout << "│         ││         │\n";
    // cout << "└─────────┘└─────────┘\n";
    // ifstream in("dictionary.txt");
    // if (in.is_open()) {
    //     string foreign;
    //     string transcription;
    //     string translate;
    //     getline(in, foreign, '|');
    //     getline(in, transcription, '|');
    //     getline(in, translate, '|');
    //     Word *w = new Word(foreign, transcription, translate);
    //     cout << w->getForeign() << '|' << w->getTranscription() << '|' << w->getTranslate() << '\n';
    //     delete(w);
    //     in.close();
    // } else {
    //     cout << "no input file\n";
    // }
    // ofstream out("out.txt");
    // if (out.is_open()) {
    //     bool bool_var1 = true;
    //     bool bool_var2 = false;
    //     out << bool_var1 << '\n' << bool_var2 << '\n';
    //     out.close();
    // } else {
    //     cout << "no input file\n";
    // }
    // string s = u8"├";
    // wchar_t c2 = L'├';
    // s += c2;
    // setlocale(LC_ALL, "");
    // cout << "s1" << s << '\n';
    // wchar_t c = L'┌';
    // wchar_t cc = '\u0444';
    // cout << cc << '\n';
    // wcout << "Y " << c << '\n';
    // s += c;
    // cout << "s2" << s;
    // s += '\n';
    // cout << "s3" << s;
    // string s2 = "┌─────────┐┌─────────┐";
    // printf("%d\n", c);
    // cout << "s-2" << s2 << '\n';
    // string s3 = "Превед медвед!";
    // s3.resize(5);
    // cout << "s3.length() = " << s3.length() << '\n';
    // s2 += s3;
    // cout << "s-2" << s2 << '\n';
    // cout << sizeof(s2[1]) << '\n';
    // char uc = s2[1];
    // printf("%d %c\n", uc, uc);
    // string s4 = "\u9484";
    // cout << "s4: " << s4 << '\n';
    // cout << "⏲" << '\n';
    return 0;
}