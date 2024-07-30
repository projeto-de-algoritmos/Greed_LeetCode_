#include <vector>

class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
        int correcaoMin = 0, i = 0, comprimento = nums.size(); // declaração de variáveis
        long valorMaxAtual = 0;

        for (; valorMaxAtual < n;) { // loop para percorrer até que valorMaxAtual seja maior ou igual a n
            if (i < comprimento && valorMaxAtual + 1 >= nums[i]) { // verifica se ainda há números em nums e se o próximo número é necessário
                valorMaxAtual += nums[i]; // adiciona o valor atual de nums[i] a valorMaxAtual
                ++i; // incrementa o índice i
            } else {
                valorMaxAtual += (valorMaxAtual + 1); // adiciona um número fictício para cobrir o intervalo
                ++correcaoMin; // incrementa o contador de correções
            }
        }
        return correcaoMin; // retorna o número mínimo de correções necessárias
    }
};
