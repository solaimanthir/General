/*Author: Solai*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count_letters[26] = {0};

        for(char ch : magazine)
        {
            ++count_letters[ch - 'a'];
        }

        for(char ch : ransomNote)
        {
            if(0 == count_letters[ch - 'a'])
            {
                return false;
            }

            --count_letters[ch - 'a'];
        }

        return true;
    }
};
