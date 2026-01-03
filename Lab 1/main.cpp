#include <iostream>
#include <string>
using namespace std;

// Caesar Encrypt / Decrypt
string caesar(string text, int key, bool enc, bool digits) {
    string out = "";
    key = key % 26;

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            char base = (ch >= 'A' && ch <= 'Z') ? 'A' : 'a';
            ch = enc ? base + (ch - base + key) % 26
                     : base + (ch - base - key + 26) % 26;
        }
        else if (digits && ch >= '0' && ch <= '9') {
            ch = enc ? (ch - '0' + 5) % 10 + '0'
                     : (ch - '0' - 5 + 10) % 10 + '0';
        }

        out += ch;
    }
    return out;
}

int main() {
    string plain;
    int k1, k2;

    cout << "Enter plain text: ";
    getline(cin, plain);

    cout << "Enter key 1: ";
    cin >> k1;
    cout << "Enter key 2: ";
    cin >> k2;

    // Double Encryption
    string c1 = caesar(plain, k1, true, true);
    string c2 = caesar(c1, k2, true, false);

    cout << "After Encryption 1: " << c1 << endl;
    cout << "After Encryption 2: " << c2 << endl;

    // Double Decryption (reverse order)
    string d1 = caesar(c2, k2, false, false);
    string d2 = caesar(d1, k1, false, true);

    cout << "After Decryption 1: " << d1 << endl;
    cout << "After Decryption 2: " << d2 << endl;

    return 0;
}
