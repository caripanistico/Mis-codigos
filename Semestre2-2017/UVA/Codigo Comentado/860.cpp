#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <ctype.h>
using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        if(s.substr(0, 20) == "****END_OF_INPUT****")
            return 0;
        map<string, int> r;
        int lambda = 0;
        do {
            if(s == "****END_OF_TEXT****")                          //este programa calcula la "entropia" de un texto
                break;                                              //es simple, lo que hace es simplemente calcular la cantidad de palabras que hay en un texto
            int i, len = s.length();                                
            for(i = 0; i < len; i++) {
                if(!isalpha(s[i]))
                    continue;
                string word = "";
                int j(i);                                           //luego, dependiendo de la cantidad de palabras distintas, se calcula la 'entropia' como esta definida
                while(j < len) {                                    //y se imprime el resultado, como la cantidad de palabras, la entropia, y la entropia relativa
                    bool flag = false;
                    switch(s[j]) {
                        case ',':break;
                        case '.':break;
                        case ':':break;
                        case ';':break;
                        case '!':break;
                        case '?':break;
                        case '\"':break;
                        case '\t':break;
                        case '(':break;
                        case ')':break;
                        case ' ':break;
                        case '\n':break;
                        case EOF:break;
                        case '\0':break;
                        default:
                            if(isupper(s[j]))
                                s[j] += 32;
                            word += s[j];
                            flag = true;
                    }
                    if(!flag)
                        break;
                    j++;
                }
                i = j;
                lambda++;
                r[word]++;
            }
        } while(getline(cin, s));
        double Et = 0, Emax = log10(lambda);
        for(map<string, int>::iterator it = r.begin(); it != r.end(); it++) {
            Et += it->second*(log10(lambda)-log10(it->second));
        }
        Et /= lambda;
        if(lambda == 0)
            puts("0 0.0 0");
        else
            printf("%d %.1lf %.0lf\n", lambda, Et, Et*100/Emax);
    }
    return 0;
}
