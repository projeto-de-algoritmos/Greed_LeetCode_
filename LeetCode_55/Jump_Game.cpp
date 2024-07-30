#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        // O objetivo inicial é alcançar o último índice da matriz
        int goal = nums.size() - 1;
        
        // Vamos percorrer a matriz de trás para frente, começando do penúltimo índice
        for (int i = nums.size() - 2; i >= 0; --i) {
            // Se podemos pular do índice atual (i) para o objetivo atual ou além
            if (i + nums[i] >= goal) {
                // Então, redefinimos o objetivo para o índice atual
                goal = i;
            }
        }
        
        // No final, verificamos se conseguimos redefinir o objetivo para o início da matriz
        return goal == 0;
    }
};
