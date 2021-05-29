// Vigenere's cipher using a rotor instead of a look-up table.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Rotor {

    string rotorIn {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    vector<char> rotorOut, encVector, decVector;

public:

    void keyRotorOut(char key) {

        rotorOut.clear();
        int j = 0;
        for(int i = 0; i <= 25; i++) {
            if(key + i <= 90)
                rotorOut.push_back(key + i);
            else
                rotorOut.push_back(65 + j++);
        }
    }

    void displayEncVector() {
        for(char e : encVector)
            cout << e;
    }

    void displayDecVector() {
        for(char e : decVector)
            cout << e;
    }

    void encryptString(string plain, string key) {

        int j = 0;
        for(unsigned i = 0; i < plain.size(); i++) {
            if(key[j] == key[key.size()-1]) {
                keyRotorOut(key[j]);
                j = 0;
            }
            else
                keyRotorOut(key[j++]);

            for(int k = 0; k <= 25; k++) {
                if(plain[i] == rotorIn[k])
                    encVector.push_back(rotorOut[k]);
            }
        }
    }

    void decryptString(string key) {

        int j = 0;
        for(unsigned i = 0; i < encVector.size(); i++) {
            if(key[j] == key[key.size()-1]) {
                keyRotorOut(key[j]);
                j = 0;
            }
            else
                keyRotorOut(key[j++]);

            for(int k = 0; k <= 25; k++) {
                if(encVector[i] == rotorOut[k])
                    decVector.push_back(rotorIn[k]);
            }
        }
    }

};

int main() {

    string plain {"ATTACKATDAWN"};
    string key {"BEXTP"};

    Rotor r1;
    cout << plain << endl;
    r1.encryptString(plain, key);
    r1.displayEncVector();
    cout << endl;
    r1.decryptString(key);
    r1.displayDecVector();
    cout << endl;

    return 0;
}
