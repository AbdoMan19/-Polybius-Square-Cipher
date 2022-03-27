#include <bits/stdc++.h>
using namespace std;
//function that check if input is valid
static string key;
bool validate(){
    cout<<"enter a key:";
    cin>>key;
    if (key.size()<6){
        return true;
    }
    cout<<"not valid"<<endl;
    return validate();


}//function of cipher and decipher

void cipher_or_decipher(bool is_cipher) {
    if (validate()) {
        string statement;
        cout << "enter a statement:";
        cin.ignore();
        getline(cin, statement);
        transform(statement.begin(), statement.end(), statement.begin(), ::tolower);
        string modified_string;
        string alphabet{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                        't', 'u', 'v', 'w', 'x', 'y', 'z'};
        vector<string> index{};

        for (int i = 0; i < key.size(); i++) {
            for (int j = 0; j < key.size(); ++j) {
                string value{};
                value.push_back(key[i]);
                value.push_back(key[j]);
                index.push_back(value);


            }
        }
        index[10]=index[9];
        //to cipher
        if(is_cipher) {
            for (int i = 0; i < statement.size(); i++) {
                if (!isspace(statement[i])) {
                    modified_string += index[alphabet.find(statement[i])];
                } else{
                    modified_string+=" ";
                }
            }
            cout << modified_string << endl;

        } else{
            string container;
            int i;
            i=0;
            while (i < statement.size()) {
                if(!isspace(statement[i])){
                    container+=statement[i];
                    container+=statement[i + 1];

                    for (int i=0;i<index.size();i++) {
                        if(index[i]==container){
                            modified_string+=alphabet[i];
                        }
                    }
                    i+=2;
                    container="";
                } else{
                    modified_string+=" ";
                    i+=1;

                }
            }
            cout<<container;
            cout<<modified_string<<endl;
        }
    }
}

int main() {
bool exit = false;
//looping for massage
while (!exit) {
    int answer;
    cout << "1-cipher" << endl << "2-decipher" << endl << "3-exit" << endl << "->";
    cin >> answer;
    if (answer == 1) {
        cipher_or_decipher(true);
    } else if (answer == 2) {
        cipher_or_decipher(false);
    } else if (answer == 3) {
        exit = true;
    }
}
return 0;
}