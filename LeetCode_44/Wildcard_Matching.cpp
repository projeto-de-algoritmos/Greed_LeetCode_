#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        // Inicializamos os índices para percorrer a string (st) e o padrão (pt)
        int st = 0, pt = 0;
        // Armazenamos a posição do último '*' encontrado e a posição de correspondência na string
        int match = 0, star_idx = -1;
        
        // Percorremos a string até o final
        while (st < s.size()) {
            // Caso 1: o caractere do padrão é '?' ou corresponde ao caractere da string
            if (pt < p.size() && (p[pt] == '?' || p[pt] == s[st])) {
                st++;
                pt++;
            }
            // Caso 2: o caractere do padrão é '*'
            else if (pt < p.size() && p[pt] == '*') {
                // Armazenamos a posição do '*' e a posição atual da string
                star_idx = pt;
                match = st;
                pt++;
            }
            // Caso 3: se houve um '*' antes, tentamos corresponder o próximo caractere da string
            else if (star_idx != -1) {
                pt = star_idx + 1; // Voltamos ao caractere após o '*'
                match++;           // Avançamos na string
                st = match;        // Atualizamos a posição atual da string
            }
            // Caso 4: não há correspondência
            else {
                return false; // Não conseguimos corresponder
            }
        }
        
        // Verificar se há caracteres '*' restantes no padrão
        while (pt < p.size() && p[pt] == '*') {
            pt++;
        }
        
        // Se chegamos ao final do padrão, retornamos true
        return pt == p.size();
    }
};
