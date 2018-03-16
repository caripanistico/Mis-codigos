#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int var[30];   //se crea una variable global de enteros, que se utilizara para guardar los valores booleanos

bool proc(string str) {
  for (int i = 0; i < 30; i++) var[i] = -1;    //el problema tiene una funcion que analiza los strings
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '&') continue;            
    if (str[i] == '~') {
      i++;
      if (var[str[i]-'a'] == -1) var[str[i]-'a'] = 0;  //si el caracter tiene el valor inisial, se inicializa en '0'
      else if (var[str[i]-'a'] == 1) return false;     //si ya tiene valor 1, se devuelve falso
    } else {
      if (var[str[i]-'a'] == -1) var[str[i]-'a'] = 1; //de otra forma, se inicializa en valor '1'
      else if (var[str[i]-'a'] == 0) return false;  //si ya tiene valor 0, se devuelve falso
    }
  }
  return true; //si ninguna de los if devuelve falso, se termina devolviendo true
}

int main() {
  int T;
  string form;
  cin >> T;
  while (T--){
    cin >> form;
    bool ok = false;          //se leen los datos...
    int last;
    for (int i = 0; i < form.length() && !ok; i++) {
      if (form[i] == '(') last = i;
      else if (form[i] == ')') ok = ok || proc(form.substr(last+1, i-last-1)); //se revisa la operacion... y se cambia el valor de 'ok'
    }
    if (ok) printf("YES\n");
    else printf("NO\n");          //dependiendo de 'ok', se imprime el 'yes' o 'no'
  }
  return 0;
}