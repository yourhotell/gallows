#include <iostream>
#include <string>
#include <ctime>

using namespace std;

inline int GenerateIDWith(int count_with)
{
    return rand() % count_with;
}

void PrintField(char mas_with[], int N, int hp)
{
    cout << "У Вас осталось: " << hp << " жизней" << endl;
    for(int i = 0; i < N; i++)
    {
        cout << mas_with[i] << " ";
    }
    cout << "\n";
}

void SetNewLetter (char* letter) {
    cout << "Введите букву: ";
    cin >> *letter;
}

void SetFiledNull(char mas_with[], int N) {
    for (int i = 0; i < N; i++)
    {
        mas_with[i] = '_';
    }
}

int main()
{
    srand(time(NULL));

    setlocale(LC_ALL,"rus");

    const int count_with = 5;
    char letter = '\0';
    int hp = 5;
    bool status = false;
    int ug = 0;

    string mas[count_with] = { "Privet", "Poka", "Transkription", "Test", "Tank" };
    int index_with = 0;

    index_with = GenerateIDWith(count_with);

    char *mas_with = new char [mas[index_with].length()];


    SetFiledNull(mas_with, mas[index_with].length());

    cout << "Приветсвуем Вас в игре \"Виселица\"!\nВ этой игре Вы должны вводить по одной букве, пытаясь угадать слово.\nУ Вас всего " << hp << " жизней, с каждой неугаданной буквой - отнимается 1 жизнь." << endl;

    system("pause");
    system("cls");

    PrintField(mas_with, mas[index_with].length() , hp);

    while(hp != 0)
    {
        SetNewLetter(&letter);

        status = false;

        for(int i = 0; i < mas[index_with].length(); i++)
        {
            if(mas[index_with][i] != toupper(letter) && mas[index_with][i] != tolower(letter))
                continue;
            else
            {
                status = true;

                for(int j = 0; j < mas[index_with].length(); j++)
                {
                    if(mas[index_with][i] == toupper(letter) || mas[index_with][i] == tolower(letter))
                        mas_with[i] = letter;
                }
                break;
            }

        }

        if(status) {
            ug++;
            system("cls");
            cout << "Буква найдена!" << endl;
            PrintField(mas_with, mas[index_with].length(), hp);
        }
        else
        {
            system("cls");
            cout << "Буква не найдена!" << endl;
            hp--;
            PrintField(mas_with, mas[index_with].length(), hp);
        }

        if(hp == 0)
        {
            system("cls");
            cout << "Вы проиграли!";
            return 1;
        }

        if(ug == mas[index_with].length())
        {
            system("cls");
            cout << "Вы угадали слово - " << mas[index_with];
            break;
        }
    }

    delete [] mas_with;

    return 0;
}
