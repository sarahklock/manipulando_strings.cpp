/*
 1. Faça um algoritmo que leia uma frase (mais de uma palavra) do teclado e imprima na tela:
                  i. O número de caracteres dessa frase; ok
                  ii. O número de palavras da frase; ok
                  iii. O número de vezes que a letra “a” aparece na frase; ok
                  iv. A quantidade de palavras repetidas; ok
                  v. Troque a primeira palavra da frase pela última; ok
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    string frase, frase1, alfanumericos = "abcdefghijklmnopqrstuvwxyz1234567890.,!?";
    vector <string> palavras;
    int pos_espaco, ultima_posicao = -2, repetidas = 0, repeated, a, qtd_a = 0, qntd_palavras = 0;
    int substring = 0;

    cout << "Insira uma frase:\n";

    getline(cin, frase);

    cout << "\nA sua frase tem " << frase.length() << " caracteres.\n";

    for(int i = 0, j = 0; j < frase.length(); i++, j++){

        palavras.push_back("");

        while(frase[j] != ' ' &&  j < frase.length()){
            palavras[i] += frase[j];
            j++;
        }
    }

    cout << "A frase tem " << palavras.size() << " palavras.\n";

    frase1 = frase;

    do{

        a = frase1.find('a');

        if(a != -1){
            qtd_a++;
            frase1 = frase1.substr(a + 1);
            a = frase1.find('a');
        }
        else{
            frase1 = "";
        }



    }while(a != -1 || frase1.length() > 0);

    cout << "O caracter 'a' aparace " << qtd_a << " vezes na frase.\n";

    for(int i = 0; i < palavras.size() - 1; i++){

        substring += palavras[i].length() + 1;

        string subfrase = frase.substr(substring, frase.length() - substring);

        repeated = subfrase.find(palavras[i]);

        if(repeated != -1){
            repetidas++;
        }

    }

    cout << repetidas << " palavra(s) se repete(m) nessa frase.\n";

    string frase_replace = frase;

    frase_replace.replace(frase_replace.find(palavras[palavras.size() - 1]), palavras[palavras.size() - 1].length(), palavras[0]);

    frase_replace.replace(0, palavras[0].length(), palavras[palavras.size() - 1]);

    cout << "A frase com a primeira e a ultima palavras trocadas de lugar fica: " << frase_replace << "." << endl;

	return 0;
}
