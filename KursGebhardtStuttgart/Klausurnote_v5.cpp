#include <iostream>
//#include <math.h>

class Klausurnote
{
public:
    static int ctrAllObjects;
    static int ctrExstObjects;

    Klausurnote() { ctrAllObjects++; ctrExstObjects++; std::cout << "Objekt angelegt. Adresse: " << this << std::endl; } // default Konstruktor

    Klausurnote(double noteInputNum) //Konstruktor1
    {
        Klausurnote::set(noteInputNum);
        ctrAllObjects++; ctrExstObjects++;
        std::cout << "Objekt angelegt. Adresse: " << this << std::endl;
    }

    Klausurnote(const char* noteInput) //Konstruktor2
    {
        Klausurnote::set(noteInput);
        ctrAllObjects++; ctrExstObjects++;
        std::cout << "Objekt angelegt. Adresse: " << this << std::endl;
    }

    Klausurnote(int noteInput1, int noteInput2) //Konstruktor3
    {
        Klausurnote::set(noteInput1, noteInput2);
        ctrAllObjects++; ctrExstObjects++;
        std::cout << "Objekt angelegt. Adresse: " << this << std::endl;
    }

    Klausurnote(const Klausurnote& andereNote) //Copy Konstruktor
    {
        for (int i = 0; i < 3; i++)
            note[i] = andereNote.note[i];

        ctrAllObjects++; ctrExstObjects++; std::cout << "Objekt angelegt. Adresse: " << this << std::endl;
    }

    ~Klausurnote() { ctrExstObjects--; std::cout << "Objekt vernichetet. Adresse: " << this << std::endl; } //Dekonstruktor

    int set(const char* noteInput)
    {
        int n = -1;
        while (noteInput[++n] != '\0'); // Anzahl der Zeichen in noteInput
        if (n == 0 || n > 3 || (n > 1 && noteInput[1] != ','))
        {
            std::cout << "Ungültige Note\n";
            note[0] = '0'; note[1] = ','; note[2] = '0';
            return -1;
        }
        else if (noteInput[0] != '1' && noteInput[0] != '2' && noteInput[0] != '3' && noteInput[0] != '4' && noteInput[0] != '5')
        {
            std::cout << "Ungültige Note\n";
            note[0] = '0'; note[1] = ','; note[2] = '0';
            return -1;
        }
        else if ((noteInput[0] == '4' || noteInput[0] == '5') && (noteInput[2] != '0' && noteInput[1] != '\0' && noteInput[2] != '\0'))
        {
            std::cout << "Ungültige Note\n";
            note[0] = '0'; note[1] = ','; note[2] = '0';
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

    int set(double noteInput)
    {
        if (noteInput >= 1 && noteInput <= 5)
        {
            double noteInput1 = floor(noteInput);
            double noteInput2 = (noteInput - noteInput1) * 10;
            note[0] = noteInput1 + 48; note[1] = ','; note[2] = noteInput2 + 48;
            Klausurnote::set(note);
            return 0;
        }
        else
        {
            std::cout << "Ungültige Note\n";
            note[0] = '0'; note[1] = ','; note[2] = '0';
            return -1;
        }
    }

    int set(int noteInput1, int noteInput2)
    {
        if (noteInput1 >= 1 && noteInput1 <= 5)
        {
            note[0] = noteInput1 + 48; note[1] = ','; note[2] = noteInput2 + 48;
            Klausurnote::set(note);
            return 0;
        }
        else
        {
            std::cout << "Ungültige Note\n";
            note[0] = '0'; note[1] = ','; note[2] = '0';
            return -1;
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
        float noteNum = (float)note[0] - 48 + ((float)note[2] - 48) / 10;
        if (noteNum > 0.99 && noteNum < 1.6)
            noteVerbal = "sehr gut";
        else if (noteNum >= 1.6 && noteNum < 2.6)
            noteVerbal = "gut";
        else if (noteNum >= 2.6 && noteNum < 3.6)
            noteVerbal = "befriedigend";
        else if (noteNum >= 3.6 && noteNum < 4.9)
            noteVerbal = "ausreichend";
        else if (noteNum >= 4.9)
            noteVerbal = "nicht ausreichend";

        return noteVerbal;
    }
    void druckeVerbal()
    {
        std::cout << getVerbal() << "\n";
    }

    Klausurnote plus(const Klausurnote& andereNote)
    {
        float noteNum = (float)note[0] - 48 + ((float)note[2] - 48) / 10;
        float andereNoteNum = (float)andereNote.note[0] - 48 + ((float)andereNote.note[2] - 48) / 10;
        float mittelwert = (noteNum + andereNoteNum) / 2;

        float mittelwert1 = floor(mittelwert);
        float mittelwert2 = (mittelwert - mittelwert1) * 10;

        Klausurnote obj(1.0); // Initialisierung auf einen gültigen Wert
        obj.note[0] = mittelwert1 + 48; obj.note[1] = ','; obj.note[2] = mittelwert2 + 48; obj.note[3] = 0;
        return obj;
    }

    friend Klausurnote plusFr(const Klausurnote& eineNote, const Klausurnote& andereNote);

    Klausurnote plus2(const Klausurnote& eineNote, const Klausurnote& andereNote)
    {
        float noteNum = (float)eineNote.note[0] - 48 + ((float)eineNote.note[2] - 48) / 10;
        float andereNoteNum = (float)andereNote.note[0] - 48 + ((float)andereNote.note[2] - 48) / 10;
        float mittelwert = (noteNum + andereNoteNum) / 2;

        float mittelwert1 = floor(mittelwert);
        float mittelwert2 = (mittelwert - mittelwert1) * 10;

        note[0] = mittelwert1 + 48; note[1] = ','; note[2] = mittelwert2 + 48; note[3] = 0;
        return *this;
    }

    static void printCtr();

private:
    char note[4] = { '0',',','0',0 }; // Initialisierung auf eine ungültige Note
};


Klausurnote plusFr(const Klausurnote& eineNote, const Klausurnote& andereNote)
{
    float noteNum = (float)eineNote.note[0] - 48 + ((float)eineNote.note[2] - 48) / 10;
    float andereNoteNum = (float)andereNote.note[0] - 48 + ((float)andereNote.note[2] - 48) / 10;
    float mittelwert = (noteNum + andereNoteNum) / 2;

    float mittelwert1 = floor(mittelwert);
    float mittelwert2 = (mittelwert - mittelwert1) * 10;

    Klausurnote obj(1.0); // Initialisierung auf einen gültigen Wert
    obj.note[0] = mittelwert1 + 48; obj.note[1] = ','; obj.note[2] = mittelwert2 + 48; obj.note[3] = 0;
    return obj;
}

void Klausurnote::printCtr()
{
    std::cout << "All Object Number: " << ctrAllObjects << std::endl;
    std::cout << "Exstng Object Number: " << ctrExstObjects << std::endl << std::endl;
}

int Klausurnote::ctrAllObjects = 0;
int Klausurnote::ctrExstObjects = 0;

int main()
{
    Klausurnote::printCtr();

    Klausurnote bio(1.4);
    bio.druckeNumerisch();
    bio.druckeVerbal();

    bio.set(3.5);
    bio.druckeNumerisch();
    bio.druckeVerbal();

    Klausurnote::printCtr();

    {
        Klausurnote mat("1,4");
        mat.druckeNumerisch();
        mat.druckeVerbal();

        mat.set("3,5");
        mat.druckeNumerisch();
        mat.druckeVerbal();
    }

    Klausurnote::printCtr();

    Klausurnote phys(1,4);
    phys.druckeNumerisch();
    phys.druckeVerbal();

    phys.set(3,5);
    phys.druckeNumerisch();
    phys.druckeVerbal();

    Klausurnote::printCtr();


    std::cin.get();
}