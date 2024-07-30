#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int st = 0, pt = 0, match = 0, star_idx = -1;
        
        while (st < s.size()) {
            // Caso 1: o caractere do padrão corresponde ao caractere da string ou é um '?'
            if (pt < p.size() && (p[pt] == '?' || p[pt] == s[st])) {
                st++;
                pt++;
            }
            // Caso 2: o caractere do padrão é '*'
            else if (pt < p.size() && p[pt] == '*') {
                star_idx = pt;
                match = st;
                pt++;
            }
            // Caso 3: se houve um '*' antes, tentamos corresponder o próximo caractere da string
            else if (star_idx != -1) {
                pt = star_idx + 1;
                match++;
                st = match;
            }
            // Caso 4: não há correspondência
            else {
                return false;
            }
        }
        
        // Verificar se há caracteres '*' restantes no padrão
        while (pt < p.size() && p[pt] == '*') {
            pt++;
        }
        
        return pt == p.size();
    }
};
