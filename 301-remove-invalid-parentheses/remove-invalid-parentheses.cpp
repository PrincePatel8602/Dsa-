class Solution {
public:
    set<string> sp;
    int maxp = 0;

    void fun(string &b, string &s, int i, int balance) {

        if(balance < 0)
            return;

        if(i == s.size()) {
            if(balance == 0) {

                if(b.size() > maxp) {
                    sp.clear();
                    maxp = b.size();
                }

                if(b.size() == maxp) {
                    sp.insert(b);
                }
            }
            return;
        }

       
        if(s[i] == '(' || s[i] == ')') {
            fun(b, s, i + 1, balance);
        }

       
        b.push_back(s[i]);

        if(s[i] == '(')
            fun(b, s, i + 1, balance + 1);
        else if(s[i] == ')')
            fun(b, s, i + 1, balance - 1);
        else
            fun(b, s, i + 1, balance);

        b.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {

        sp.clear();
        maxp = 0;

        string b = "";

        fun(b, s, 0, 0);

        return vector<string>(sp.begin(), sp.end());
    }
};