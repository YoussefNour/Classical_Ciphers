#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iomanip>

std::map<char, int> lettersmap = { {'a',0}, {'b',1},
                                                    {'c',2}, {'d',3},
                                                    {'e',4}, {'f',5},
                                                    {'g',6}, {'h',7},
                                                    {'i',8}, {'j',9},
                                                    {'k',10}, {'l',11},
                                                    {'m',12}, {'n',13},
                                                    {'o',14}, {'p',15},
                                                    {'q',16}, {'r',17},
                                                    {'s',18}, {'t',19},
                                                    {'u',20}, {'v',21},
                                                    {'w',22}, {'x',23},
                                                    {'y',24}, {'z',25},
                                                    {'A',0}, {'B',1},
                                                    {'C',2}, {'D',3},
                                                    {'E',4}, {'F',5},
                                                    {'G',6}, {'H',7},
                                                    {'I',8}, {'J',9},
                                                    {'K',10}, {'L',11},
                                                    {'M',12}, {'N',13},
                                                    {'O',14}, {'P',15},
                                                    {'Q',16}, {'R',17},
                                                    {'S',18}, {'T',19},
                                                    {'U',20}, {'V',21},
                                                    {'W',22}, {'X',23},
                                                    {'Y',24}, {'Z',25}
};

char findKey(std::map<char, int> someMap, int someValue) {
    for (auto it = someMap.begin(); it != someMap.end(); ++it)
        if (it->second == someValue) {
            return it->first;
        }
    return someValue;
}

void printVector(std::vector<char> letters,
    std::string title) {
    std::cout << "\n----------------------------\n\t" << title << "\n";
    for (unsigned int i = 0; i < letters.size(); i++)
    {
        std::cout << std::setw(2) << letters[i];
    }
    std::cout << "\n----------------------------\n";
}

void writeVector(std::vector<char> arr,std::string filename) {
    std::ofstream myfile;
    myfile.open(filename);
    myfile << "Encryption result\n";
    for (int j = 0; j < arr.size(); j++)
    {
        myfile << std::setw(4) << arr[j];
    }
    myfile.close();
}

void writeString(std::string arr, std::string filename) {
    std::ofstream myfile;
    myfile.open(filename);
    myfile << "Encryption result\n";
    for (int j = 0; j < arr.size(); j++)
    {
        myfile << arr[j];
    }
    myfile.close();
}

void printPlayfairMatrix(char arr[5][5]) {
    std::cout << "playfair matrix\n";
    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            std::cout << std::setw(4) << arr[j][k];
            if (k == 5 - 1)
                printf("\n");
        }
    }
    printf("\n");
}


std::string vectorTostring(std::vector<char> input) {
    std::string message;
    for (int i = 0; i < input.size(); i++)
    {
        message += input[i];
    }
    return message;
}

std::vector<char> stringTovector(std::string  input) {
    std::vector<char> message;
    for (int i = 0; i < input.size(); i++)
    {
        message.push_back(input[i]);
    }
    return message;
}

bool inString(std::string str, char c) {
    for (unsigned int i = 0; i < str.size(); i++)
    {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}

std::string remove_space(std::string s) {
    int i, j;
    int len = s.size();
    char* k = new char[len + 1];
    for (i = 0, j = 0; i < len; i++)
    {
        if (s[i] != ' ') {
            k[j] = s[i];
            j++;
        }
    }
    k[j] = '\0';
    return k;
}

std::string uniqueChars(
    std::string str) {

    std::string unique = "";
    for (unsigned int i = 0; i < str.size(); i++)
    {
        if (!inString(unique, str[i]) && str[i] != ' ') {
            unique += str[i];
        }
    }
    return unique;
}

int** findInPlayfairmatrix(char matrix[5][5], char ch1, char ch2) {
    int** indexes = new int* [2];
    indexes[0] = new int[2];
    indexes[1] = new int[2];
    if (ch1 == 'i' || ch1 == 'j') {
        ch1 = '/';
    }
    if (ch2 == 'i' || ch2 == 'j') {
        ch2 = '/';
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch1) {
                indexes[0][0] = i;
                indexes[0][1] = j;
            }
            if (matrix[i][j] == ch2) {
                indexes[1][0] = i;
                indexes[1][1] = j;
            }
        }
    }
    return indexes;
}

std::vector<char> caesarCypher(std::vector<char> letters, int key) {
    std::vector<char> Ciphter_text;
    key = key % 26;
    for (unsigned int i = 0; i < letters.size(); i++)
    {
        if (letters[i] != '\n') {
            Ciphter_text.push_back(findKey(lettersmap, (lettersmap[letters[i]] + key) % 26));
        }
        else
        {
            Ciphter_text.push_back(letters[i]);
        }
    }
    return Ciphter_text;
}

std::vector<char> playFair(std::vector<char> message, std::string key) {
    char matrix[5][5];
    unsigned int c1 = 0, c2 = 0;
    key = remove_space(key);
    key = uniqueChars(key);
    bool ijset = false;
    for (unsigned int i = 0; i < message.size() - 1; i++)
    {
        if (message[i] == message[i + 1]) {
            if (message[i] != 'x') {
                message.insert(message.begin() + i + 1, 'x');
            }
            else
            {
                i++;
            }
        }
    }
    if (message.size() % 2 != 0) {
        message.push_back('x');
    }
    printVector(message, "processed plain text");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) {
            if (c1 < key.size()) {
                if (key.at(c1) == 'i' || key.at(c1) == 'j' && !ijset) {
                    matrix[i][j] = '/';
                    ijset = true;
                }
                else if (!(key.at(c1) == 'i' || key.at(c1) == 'j'))
                {
                    matrix[i][j] = key.at(c1);
                }
                c1++;
            }
            else {
                while (inString(key, findKey(lettersmap, c2++))) {}
                if (findKey(lettersmap, c2 - 1) == 'i' || findKey(lettersmap, c2 - 1) == 'j' && !ijset) {
                    matrix[i][j] = '/';
                    c2++;
                    ijset = true;
                }
                else if (!(findKey(lettersmap, c2 - 1) == 'i' || findKey(lettersmap, c2 - 1) == 'j'))
                {
                    matrix[i][j] = findKey(lettersmap, c2 - 1);
                }
                else
                {
                    c2++;
                    matrix[i][j] = findKey(lettersmap, c2 - 1);
                }

            }
        }
    }
    printPlayfairMatrix(matrix);
    int** indexes;
    int j;
    for (int i = 0; i < message.size(); i += 2)
    {
        while (message.at(i) == '\n' || message.at(i) == ' ') {
            i++;
        }
        j = i + 1;
        while (message.at(j) == '\n' || message.at(j) == ' ') {
            j++;
        }

        indexes = findInPlayfairmatrix(matrix, message.at(i), message.at(j));
        //same row
        if (indexes[0][0] == indexes[1][0]) {
            message.at(i) = matrix[indexes[0][0]][(indexes[0][1] + 1) % 5];
            message.at(i + 1) = matrix[indexes[1][0]][(indexes[1][1] + 1) % 5];
        }
        //same column
        else if (indexes[0][1] == indexes[1][1]) {
            message.at(i) = matrix[(indexes[0][0] + 1) % 5][indexes[0][1]];
            message.at(i + 1) = matrix[(indexes[1][0] + 1) % 5][indexes[1][1]];
        }
        //opposite
        else {
            message.at(i) = matrix[indexes[0][0]][indexes[1][1]];
            message.at(i + 1) = matrix[indexes[1][0]][indexes[0][1]];
        }
    }
    return message;
}

std::vector<char> hillCipher2x2(std::vector<char> plain_text, int** matrix) {
    int det = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    char c1, c2;
    if (plain_text.size() % 2 != 0) { plain_text.push_back('x'); }
    std::vector<char> Cipher_text;
    if (det == 0) {
        std::cout << "Matrix doesn't have an inverse \n";
    }
    int j;
    for (int i = 0; i < plain_text.size()-1; i+=2)
    {
        while (plain_text.at(i) == '\n' || plain_text.at(i) == ' ') {
            Cipher_text.push_back(plain_text.at(i));
            i++;
        } 
        j = i + 1;
        while (plain_text.at(j) == '\n' || plain_text.at(j) == ' ') {
            Cipher_text.push_back(plain_text.at(j));
            j++;
        }
        c1 = lettersmap[plain_text[i]];
        c2 = lettersmap[plain_text[j]];
        Cipher_text.push_back((findKey(lettersmap, (matrix[0][0] * c1 + matrix[1][0] * c2) % 26)));
        Cipher_text.push_back((findKey(lettersmap, (matrix[0][1] * c1 + matrix[1][1] * c2) % 26)));
    }
    return Cipher_text;
}

std::vector<char> hillCipher3x3(std::vector<char> plain_text, int** matrix) {
    std::vector<char> Cipher_text;
    char c1, c2, c3;
    int det1 = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
    int det2 = matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
    int det3 = matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
    int det = det1 - det2 + det3;
    if (det == 0) {
        std::cout << "Matrix doesn't have an inverse \n";
    }
    if (plain_text.size() % 3 != 0) {
        if (plain_text.size() % 3 == 1) {
            plain_text.push_back('X');
        }
        if (plain_text.size() % 3 == 2) {
            plain_text.push_back('X');
            plain_text.push_back('X');
        }
    }
    int j,k;
    for (int i = 0; i < plain_text.size()-3; i+=3)
    {
        while (plain_text.at(i) == '\n' || plain_text.at(i) == ' ') {
            Cipher_text.push_back(plain_text.at(i));
            i++;
        }
        j = i + 1;
        while ((plain_text.at(j) == '\n' || plain_text.at(j) == ' ')) {
            Cipher_text.push_back(plain_text.at(j));
            j++;
        }
        k = j + 1;
        while ((plain_text.at(k) == '\n' || plain_text.at(k) == ' ')) {
            Cipher_text.push_back(plain_text.at(k));
            k++;
        }

        c1 = lettersmap[plain_text[i]];
        c2 = lettersmap[plain_text[j]];
        c3 = lettersmap[plain_text[k]];

        Cipher_text.push_back((findKey(lettersmap, (matrix[0][0] * c1 + matrix[1][0] * c1 + matrix[2][0] * c3) % 26)));
        Cipher_text.push_back((findKey(lettersmap, (matrix[0][1] * c1 + matrix[1][1] * c1 + matrix[2][1] * c3) % 26)));
        Cipher_text.push_back((findKey(lettersmap, (matrix[0][2] * c1 + matrix[1][2] * c1 + matrix[2][2] * c3) % 26)));
    }
    return Cipher_text;
}


std::vector<char> vigenere(std::vector<char> plain_text,std::string key, bool mode) {
    std::vector<char> Cipher_text;
    std::string keyfinal;
    int len = plain_text.size();
    if (!mode) {
        int keylen = key.size();
        int mult = len / keylen + (len % keylen > 0);
        for (int i = 0; i < mult; i++)
            keyfinal += key;
        keyfinal = keyfinal.substr(0, len);
        for (int i = 0; i < len-1; i++) {
            if (plain_text.at(i) == '\n' || plain_text.at(i) == ' ') {
                Cipher_text.push_back(plain_text.at(i));
                i++;
            }
            Cipher_text.push_back(findKey(lettersmap, (lettersmap[keyfinal[i]] + lettersmap[plain_text[i]]) % 26));
        }
        return Cipher_text;
    }
    else {
        keyfinal += key;
        for (int i = 0; i < plain_text.size(); i++)
        {
            keyfinal += plain_text[i];
        }
        keyfinal = keyfinal.substr(0, len);
        for (int i = 0; i < len; i++) {
            while (plain_text.at(i) == '\n' || plain_text.at(i) == ' ') {
                Cipher_text.push_back(plain_text.at(i));
                i++;
            }
            Cipher_text.push_back(findKey(lettersmap, (lettersmap[keyfinal[i]] + lettersmap[plain_text[i]]) % 26));
        }
        return Cipher_text;
    }
}


std::vector<char> vernam(std::vector<char> plain_text,std::string key) {
    std::vector<char> Cipher_text;
    key = remove_space(key);
    if (key.size() < plain_text.size()) {
        std::cout << "Key size is smaller than the plaintext\n";
    }
    for (int i = 0; i < plain_text.size(); i++) {
        Cipher_text.push_back(findKey(lettersmap, (lettersmap[key[i]] ^ lettersmap[plain_text[i]]) % 26));
    }
    return Cipher_text;
}

int main()
{
    std::string filename;
    std::vector<char> plain_text;
    std::vector<char> Cipher_text;
    std::string plain_text_str;
    std::string cipher_text_str;
    std::string key_str;
    std::string word;
    std::ifstream  file;
    bool filenotfound = true;
    int mode = 0,Caesarkey=-1;
    int** keymatrix = new int* [2];
    keymatrix[0] = new int[2];
    keymatrix[1] = new int[2];
    int** keymatrix3x3 = new int* [3];
    keymatrix3x3[0] = new int[3];
    keymatrix3x3[1] = new int[3];
    keymatrix3x3[2] = new int[3];
    char ch;

    while (true)
    {
        std::cout << "------------cryptography library-------------\n-----1.Ceasar Cipher\n-----2.Playfair Cipher\n-----3.Hill Cipher\n-----4.Vigenere Cipher\n-----5.Vernam Cipher\nchoose mode:";
        std::cin >> mode;
        switch (mode)
        {
            //Caesar
        case 1:
            std::cout << "Caesar Cipher\n";
            while (filenotfound)
            {
                //getting file name from user
                std::cout << "enter file name: ";
                getline(std::cin, filename);

                file.open(filename, std::ios::in);

                //checking if file was found a opened 
                if (!file.is_open()) {
                    std::cout << "file not found!!\n";
                }
                else
                {
                    filenotfound = false;
                }
            }
            //reading file to vector
            while (file >> std::noskipws >> ch) {
                plain_text.push_back(ch);
            }
            void close(); //closeing the file
            printVector(plain_text, "plain text");
            std::cout << "enter and integer key:";
            std::cin >> Caesarkey;
            if(Caesarkey <=0)
            {
                while (Caesarkey<=0)
                {
                    std::cout << "enter a key greater than or equal 0: ";
                    std::cin >> Caesarkey;
                }
            }
            Cipher_text = caesarCypher(plain_text, Caesarkey);
            printVector(Cipher_text,"ceasar result");
            writeVector(Cipher_text,"CaesarCipher_result.txt");
            break;
            //Playfair
        case 2:
            std::cout << "Play Fair\n";
            while (filenotfound)
            {
                //getting file name from user
                std::cout << "enter file name: ";
                getline(std::cin, filename);

                file.open(filename, std::ios::in);

                //checking if file was found a opened 
                if (!file.is_open()) {
                    std::cout << "file not found!!\n";
                }
                else
                {
                    filenotfound = false;
                }
            }
            //reading file to vector
            while (file >> std::noskipws >> ch) {
                plain_text.push_back(ch);
            }
            void close(); //closeing the file
            printVector(plain_text, "plain text");
            //inputting key
            std::cout << "enter a string Key: ";
            getline(std::cin, key_str);
            Cipher_text = playFair(plain_text, key_str);
            printVector(Cipher_text, "Playfair Result");
            writeVector(Cipher_text, "Playfair_result.txt");
            break;
            //HillCipher
        case 3:
            std::cout << "Hill Cipher\n";
            while (filenotfound)
            {
                //getting file name from user
                std::cout << "enter file name: ";
                getline(std::cin, filename);
                getline(std::cin, filename);

                file.open(filename, std::ios::in);

                //checking if file was found a opened 
                if (!file.is_open()) {
                    std::cout << "file not found!!\n";
                }
                else
                {
                    filenotfound = false;
                }
            }
            //reading file to vector
            while (file >> std::noskipws >> ch) {
                plain_text.push_back(ch);
            }
            void close(); //closeing the file
            printVector(plain_text, "plain text");
            std::cout << "choose mode\n-2 2x2hillcipher\n-3 3x3hillcipher\nmode: ";
            std::cin >> mode;
            if (mode == 2) {
                std::cout << "enter 2x2 Key matrix\n0,0 : ";
                std::cin >> keymatrix[0][0];
                std::cout << "0,1 : ";
                std::cin >> keymatrix[0][1];
                std::cout << "1,0 : ";
                std::cin >> keymatrix[1][0];
                std::cout << "1,1 : ";
                std::cin >> keymatrix[1][1];
                Cipher_text = hillCipher2x2(plain_text, keymatrix);
                printVector(Cipher_text, "hillcipher encrypted");
                writeVector(Cipher_text,"hillCipher_result.txt");
            }
            else if(mode==3)
            {
                std::cout << "enter 3x3 Key matrix\n0,0 : ";
                std::cin >> keymatrix3x3[0][0];
                std::cout << "0,1 : ";
                std::cin >> keymatrix3x3[0][1];
                std::cout << "0,2 : ";
                std::cin >> keymatrix3x3[0][2];
                std::cout << "1,0 : ";
                std::cin >> keymatrix3x3[1][0];
                std::cout << "1,1 : ";
                std::cin >> keymatrix3x3[1][1];
                std::cout << "1,2 : ";
                std::cin >> keymatrix3x3[1][2];
                std::cout << "2,0 : ";
                std::cin >> keymatrix3x3[2][0];
                std::cout << "2,1 : ";
                std::cin >> keymatrix3x3[2][1];
                std::cout << "2,2 : ";
                std::cin >> keymatrix3x3[2][2];
                /*keymatrix3x3[0][0] = 2;
                keymatrix3x3[0][1] = 4;
                keymatrix3x3[0][2] = 12;
                keymatrix3x3[1][0] = 9;
                keymatrix3x3[1][1] = 1;
                keymatrix3x3[1][2] = 6;
                keymatrix3x3[2][0] = 7;
                keymatrix3x3[2][1] = 5;
                keymatrix3x3[2][2] = 3;*/
                Cipher_text = hillCipher3x3(plain_text, keymatrix3x3);
                printVector(Cipher_text, "hillcipher encrypted");
                writeVector(Cipher_text, "hillCipher_result.txt");
            }
            else
            {
                std::cout << "wrong input!!\n";
            }
            break;
        case 4:
            std::cout << "Vigenere\n";
            while (filenotfound)
            {
                //getting file name from user
                std::cout << "enter file name: ";
                getline(std::cin, filename);
                getline(std::cin, filename);

                file.open(filename, std::ios::in);

                //checking if file was found a opened 
                if (!file.is_open()) {
                    std::cout << "file not found!!\n";
                }
                else
                {
                    filenotfound = false;
                }
            }
            //reading file to vector
            while (file >> std::noskipws >> ch) {
                plain_text.push_back(ch);
            }
            void close(); //closeing the file
            printVector(plain_text, "plain text");
            std::cout << "choose mode\n-0 Repeating mode\n-1 Auto mode\nmode: ";
            std::cin >> mode;
            std::cout << "Enter Key: ";
            std::cin >> key_str;
            Cipher_text = vigenere(plain_text, key_str, mode);
            printVector(Cipher_text, "Vignere Cipher text");
            writeVector(Cipher_text, "VignereCipher_result.txt");
            break;
        case 5:
            std::cout << "Vernam\n";
            //while (filenotfound)
            //{
                //getting file name from user
            //    std::cout << "enter file name: ";
            //    getline(std::cin, filename);
            //    getline(std::cin, filename);

            //    file.open(filename, std::ios::in);

            //    //checking if file was found a opened 
            //    if (!file.is_open()) {
            //        std::cout << "file not found!!\n";
            //    }
            //    else
            //    {
            //        filenotfound = false;
            //    }
            //}
            ////reading file to vector
            //while (file >> std::noskipws >> ch) {
            //    plain_text.push_back(ch);
            //}
            //void close(); //closeing the file
            //printVector(plain_text, "plain text");
            std::cout << "Enter plaintext:";
            std::cin >> plain_text_str;
            plain_text = stringTovector(plain_text_str);
            std::cout << "Enter Key(key must be the same lenght as plaintext): \n"<<plain_text_str<<"\n";
            std::cin >> key_str;
            Cipher_text = vernam(plain_text, key_str);
            printVector(Cipher_text, "Vernam Cipher text");
            writeVector(Cipher_text, "VernamCipher_result.txt");
            break;
        default:
            std::cout << "wrong input\n";
            break;
        }
    }
   
    ////inputting key
    //std::cout << "enter Key: ";
    //getline(std::cin, key_str);
    //key_str = remove_space(key_str);
    //std::cout << key_str << "\n";

    /*Cipher_text = playFair("archangle", plain_text);
    printVector(Cipher_text, "Cipher text");
    writeVector(Cipher_text);*/
    /*
    plain_text_str = vectorTostring(plain_text);
    cipher_text_str = hillCipher2x2(plain_text_str,key);
    std:: cout << cipher_text_str;*/
}