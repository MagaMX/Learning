
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <cctype>
#include <algorithm>
using namespace std;

struct Morze
{
    char letter;
    string code;
};

void letterToMorze(const char letter,vector<Morze> alphabet)
{
    for (const auto element : alphabet)
    {
        if (element.letter == letter)
        {
            cout << element.code;
        }
    }
}

void textToLetter(string &text, vector<Morze> alphabet)
{
    for (const auto& element : text)
    {
        if (element == ' ') 
            cout << "   ";
        else
            letterToMorze(element, alphabet);
    }
}

bool again()
{
    cout << "\nХотите перевести еще одно сообщение(да/нет): ";
    char answer;
    cin >> answer;
    if (answer == 'да')
        return true;
    else
        return false;
}

int main()
{
    setlocale(LC_ALL, "ru-RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    cout << "Введите сообщение: ";
    getline(cin, text);
    transform(text.begin(), text.end(), text.begin(), toupper);

    vector<Morze>alphabet {
        {'А', "._ "},
        {'Б', "_... "},
        {'В', ".__ "},
        {'Г', "__. "},
        {'Д', "_.. "},
        {'Е', ". "},
        {'Ж', "...- "},
        {'З', "--.. "},
        {'И', ".. "},
        {'Й', ".___ "},
        {'К', "_._ "},
        {'Л', "._.. "},
        {'М', "__ "},
        {'Н', "_. "},
        {'О', "___ "},
        {'П', ".__. "},
        {'Р', "._. "},
        {'С', "... "},
        {'Т', "_ "},
        {'У', ".._ "},
        {'Ф', ".._. "},
        {'Х', ".... "},
        {'Ц', "._._ "},
        {'Ч', "___. "},
        {'Ш', "____ "},
        {'Щ', "__._ "},
        {'Ъ', ".__._. "},
        {'Ы', "_.__ "},
        {'Ь', "_.._ "},
        {'Э', ".._.. "},
        {'Ю', "..__ "},
        {'Я', "._._ "},
    };
    
    do
    {
        textToLetter(text, alphabet);
    } while (again());
    
    return 0;
}
