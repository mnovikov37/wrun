#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <fstream>
#include <ctime>
#include "Speaker.h"
#include "domain/h/Word.h"
#include "service/h/WordRepo.h"

#define ENDL '\n'

using namespace std;

int main() {
    WordRepo wr("dictionary.txt");
    cout << wr.size() << ENDL;
    cout << wr.getForeign(33) << ENDL;
    cout << wr.getTranscription(33) << ENDL;
    cout << wr.getTranslate(33) << ENDL;
    cout << wr.getLastUsing(33) << ENDL;
    cout << wr.getWasErrors(33) << ENDL;
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