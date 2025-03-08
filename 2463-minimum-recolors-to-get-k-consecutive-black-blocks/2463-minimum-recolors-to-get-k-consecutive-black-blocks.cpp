class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w = 0; 
        for(int i = 0; i < k; i++) {
            if(blocks[i] == 'W') {
                w++;
            }
        }

        int minW = w;
        int n = blocks.size();

        for(int i = k; i < n; i++) {
            if(blocks[i] == 'W') w++;           
            if(blocks[i - k] == 'W') w--;       
            
            minW = min(minW, w); 
        }

        return minW;
    }
};
