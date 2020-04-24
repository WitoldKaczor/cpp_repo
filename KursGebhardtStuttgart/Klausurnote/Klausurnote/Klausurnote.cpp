#include <iostream>

class Klausurnote
{
    // Noten zwischen 1,0 und 5,0, mit der Dezimalstelle 0, 3 oder 7 möglich
public:

    int set(const char* noteInput)
    {
        int n = -1;
        while (noteInput[++n] != '\0'); // Anzahl der Zeichen in noteInput
        if (n == 0 || n > 3 || (n > 1 && noteInput[1] != ','))
        {
            std::cout << "Ungültige Note\n";
            note[0] = '0';
            note[1] = ',';
            note[2] = '0';
            return -1;
        }
        else if (noteInput[0] != '1' && noteInput[0] != '2' && noteInput[0] != '3' && noteInput[0] != '4' && noteInput[0] != '5')
        {
            std::cout << "Ungültige Note\n";
            note[0] = '0';
            note[1] = ',';
            note[2] = '0';
            return -1;
        }
        else if (noteInput[2] != '0' && noteInput[2] != '3' && noteInput[2] != '7' && noteInput[1] != '\0' && noteInput[2] != '\0')
        {
            std::cout << "Ungültige Note\n";
            note[0] = '0';
            note[1] = ',';
            note[2] = '0';
            return -1;
        }
        else if ((noteInput[0] == '4' || noteInput[0] == '5') && (noteInput[2] != '0' && noteInput[1] != '\0' && noteInput[2] != '\0'))
        {
            std::cout << "Ungültige Note\n";
            note[0] = '0';
            note[1] = ',';
            note[2] = '0';
            return -1;
        }
        else
        {
            note[0] = noteInput[0];
            note[1] = ',';
            if (n != 3)
                note[2] = '0';
            else
                note[2] = noteInput[2];
            return 0;
        }
    }

    char* getNumerisch()
    {
        return note;
    }
    void druckeNumerisch()
    {
        if ((int)note[0] == 48)
            std::cout << "Ungültige Note\n";
        else
            std::cout << getNumerisch() << "\n";
    }

    const char* getVerbal()
    {
        const char* noteVerbal = "Ungültige Note";
        /*if ((int)note[0] == 48)
            noteVerbal = "Ungültige Note";
        else
        {*/
        float noteNum = (float)note[0] - 48 + ((float)note[2] - 48) / 10;
        if (noteNum > 0.9 && noteNum < 1.4)
            noteVerbal = "sehr gut";
        else if (noteNum > 1.6 && noteNum < 2.4)
            noteVerbal = "gut";
        else if (noteNum > 2.6 && noteNum < 3.4)
            noteVerbal = "befriedigend";
        else if (noteNum > 3.6 && noteNum < 4.1)
            noteVerbal = "ausreichend";
        else if (noteNum > 4.9)
            noteVerbal = "nicht ausreichend";
        //}
        return noteVerbal;
    }
    void druckeVerbal()
    {
        std::cout << getVerbal() << "\n";
    }

private:
    char note[4] = { '0',',','0',0 }; // Initialisierung auf eine ungültige Note
};

int main()
{
    Klausurnote bio;
    /* bio.set("1,0");
     bio.druckeNumerisch();
     bio.druckeVerbal();

     bio.set("1,7");
     bio.druckeNumerisch();
     bio.druckeVerbal();

     bio.set("3,3");
     bio.druckeNumerisch();
     bio.druckeVerbal();

     bio.set("4,");
     bio.druckeNumerisch();
     bio.druckeVerbal();

     bio.set("5");
     bio.druckeNumerisch();
     bio.druckeVerbal();*/

    char buf[10];
    while (1)
    {
        std::cout << "Bitte Note eingeben: "; std::cin >> buf;
        bio.set(buf);
        bio.druckeNumerisch();
        bio.druckeVerbal();
    }
}