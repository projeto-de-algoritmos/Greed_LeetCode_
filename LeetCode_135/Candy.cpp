#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        // Usamos uma pilha para armazenar pares (classificação, número de doces)
        std::stack<std::pair<int, int>> stk;
        // Variáveis para armazenar a classificação anterior e o número de doces
        int prev = -1;
        int val = -1;
        // Contador para o total de doces necessários
        int count = 0;
        
        // Percorremos cada classificação na lista de classificações
        for (int i : ratings) {
            // Se a pilha está vazia ou a classificação atual é menor ou igual à do topo da pilha
            if (stk.empty() || stk.top().first >= i) {
                // Damos pelo menos um doce à criança
                stk.push({i, 1});
            }
            // Se a classificação atual é maior do que a do topo da pilha
            else if (stk.top().first < i) {
                // Damos um doce a mais do que o número de doces da criança no topo da pilha
                stk.push({i, stk.top().second + 1});
            }
        }
        
        // Processamos a pilha para calcular o total de doces
        while (!stk.empty()) {
            // Se estamos no início ou a classificação atual é menor ou igual à anterior
            if (prev == -1 || stk.top().first <= prev) {
                // Removemos o elemento do topo da pilha e atualizamos `prev` e `val`
                auto temp = stk.top(); stk.pop();
                prev = temp.first;
                val = temp.second;
            } 
            // Se a classificação atual é maior do que a anterior
            else if (prev < stk.top().first) {
                // Se o número de doces atual é maior ou igual ao do topo da pilha
                if (val >= stk.top().second) {
                    // Atualizamos `prev` e incrementamos `val`
                    prev = stk.top().first;
                    stk.pop();
                    val = val + 1;
                } 
                // Se o número de doces atual é menor do que o do topo da pilha
                else {
                    // Removemos o elemento do topo da pilha e atualizamos `prev` e `val`
                    auto temp = stk.top(); stk.pop();
                    prev = temp.first;
                    val = temp.second;
                }
            }
            // Adicionamos o número de doces atual ao total
            count += val;
        }
        // Retornamos o total de doces necessários
        return count;
    }
};
