class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int left=0;
        int right=s.size()-1;
        while(left<=right){
            int leftc=int(s[left]);
            int rightc=int(s[right]);
            if(!((leftc>=97 && leftc<=122)||(leftc>=48 && leftc<=57))){
                left++;
                continue;
            }
            if(!((rightc>=97 && rightc<=122)||(rightc>=48 && rightc<=57))){
                right--;
                continue;
            }
            if(rightc==leftc){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
