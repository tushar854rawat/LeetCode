class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s) {
        int l = 0, h = s.size() - 1;
        while(l < h) {
            if(isVowel(s[l]) && isVowel(s[h])) {
                swap(s[l], s[h]);
                l++;
                h--;
            }
            else if(!isVowel(s[l])) {
                l++;
            }
            else if(!isVowel(s[h])) {
                h--;
            }
        }
        return s;
    }
};
