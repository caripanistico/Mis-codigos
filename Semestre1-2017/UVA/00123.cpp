#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <cctype>

using namespace std;
const int kMaxn(207);
const string kSign("::");

int main()
{
    /*
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    //*/

    set<string> ignore;         //se crea un set de strings, que son los strings a ignorar
    string t;                   //se lee la linea, mientras que la linea sea distinta de '::', se agregara al set 'ignore'
    while(getline(cin,t) && t!=kSign)
        ignore.insert(t);
    multimap<string,string> r;  //se crea un mapa multiple de un par de strings.
    while(getline(cin,t))
    {
        for(int i=0;i<t.size();i++)     //cambia las mayusculas por minusculas..
            t[i]=tolower(t[i]);
        for(int i=0;i<t.size();i++)
        {
            if(!isalpha(t[i]))          //si no es ninguna letra, continua el loop
                continue;
            int j(i);
            string t2;
            while(j<t.size() && isalpha(t[j]))
            {
                t2+=t[j];       //se agregan las letras del string a un string aparte
                j++;
            }
            if(!ignore.count(t2))
            {
                for(int k=0;k<t2.size();k++)    //vuelve mayusculas los strings que son destacados
                    t2[k]=toupper(t2[k]);
                string t3(t);
                t3.replace(i,t2.size(),t2); //reemplaza las letras y los inserta en el mapa
                r.insert(make_pair(t2,t3));
            }
            i=j;
        }
    }

    for(map<string,string>::iterator i=r.begin();i!=r.end();i++)
        cout<<i->second<<endl;      //revisa el mapa, e imprime las frases con los strings destacados.

    return 0;
}