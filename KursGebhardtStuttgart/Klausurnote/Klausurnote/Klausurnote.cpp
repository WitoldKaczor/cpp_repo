#include <iostream>

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
        
        return Klausurnote((int)mittelwert1, (int)mittelwert2);
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

    Klausurnote operator + (const Klausurnote& andereNote)
    {
        return this->plus(andereNote);
    }

    void operator = (const Klausurnote& andereNote)
    {
        this->note[0] = andereNote.note[0];
        this->note[2] = andereNote.note[2];
    }

    void operator += (const Klausurnote& andereNote)
    {
        *this = this->plus(andereNote);
    }

    double operator * (double factor)
    {
        double noteNum = (double)note[0] - 48 + ((double)note[2] - 48) / 10;
        noteNum *= factor;
        return noteNum;
    }

    operator double() const //castoperator nach double 
    {
        double noteNum = (double)note[0] - 48 + ((double)note[2] - 48) / 10;
        return noteNum;
    }

    void operator () (int x, int y=0)
    {
        this->set(x, y);
    }

    bool operator == (const Klausurnote& andereNote)
    {
        return (double)*this == (double)andereNote;
    }

    bool operator < (const Klausurnote& andereNote)
    {
        return (double)*this < (double)andereNote;
    }

    bool operator > (const Klausurnote& andereNote)
    {
        return (double)*this > (double)andereNote;
    }

    bool operator <= (const Klausurnote& andereNote)
    {
        return (double)*this <= (double)andereNote;
    }

    bool operator >= (const Klausurnote& andereNote)
    {
        return (double)*this >= (double)andereNote;
    }

    void* operator new (size_t s)
    {
        std::cout << "Ueberladenes new fuer die Klasse Klausurnote !" << std::endl;
        return ::operator new (s);
    }

    void operator delete (void* p)
    {
        std::cout << "Ueberladenes delete fuer die Klasse Klausurnote !" << std::endl;
        return ::operator delete (p);
    }

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

    return Klausurnote((int)mittelwert1, (int)mittelwert2);
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
    Klausurnote bio(1.4);
    bio.druckeNumerisch();

    Klausurnote mat(5);
    mat.druckeNumerisch();
    
    (bio + mat).druckeNumerisch();

    bio += mat;
    bio.druckeNumerisch();

    bio = mat;
    bio.druckeNumerisch();
    
    Klausurnote mus(2, 0);
    mus.druckeNumerisch();
    mus = mus * (double)1;
    mus = 1.7 * mus;
    std::cout << (double)mus << std::endl;
    

    std::cout << "======================================" << std::endl;
    bio(3, 4);
    std::cout << "bio:  "; bio.druckeNumerisch();
    std::cout << "mat:  "; mat.druckeNumerisch();
    std::cout << "mus:  "; mus.druckeNumerisch();

    std::cout << "bio == mus  " << (bio == mus) << std::endl;
    std::cout << "mat == mus  " << (mat == mus) << std::endl;
    std::cout << "bio < mus  " << (bio < mus) << std::endl;
    std::cout << "mat < mus  " << (mat < mus) << std::endl;
    std::cout << "bio > mus  " << (bio > mus) << std::endl;
    std::cout << "mat > mus  " << (mat > mus) << std::endl;
    std::cout << "bio <= mus  " << (bio <= mus) << std::endl;
    std::cout << "mat <= mus  " << (mat <= mus) << std::endl;
    std::cout << "bio >= mus  " << (bio >= mus) << std::endl;
    std::cout << "mat >= mus  " << (mat >= mus) << std::endl;


    Klausurnote* phys = new Klausurnote;
    delete phys;


    std::cin.get();
}