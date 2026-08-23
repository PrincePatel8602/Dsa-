class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead;
        for (string s : deadends)
            dead.insert(s);

        if (dead.count("0000"))
            return -1;

        queue<string> q;
        unordered_set<string> vis;

        q.push("0000");
        vis.insert("0000");

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                string cur = q.front();
                q.pop();

                if (cur == target)
                    return steps;

                for (int i = 0; i < 4; i++) {

                  
                    string next = cur;
                    next[i] = (next[i] - '0' + 1) % 10 + '0';

                    if (!dead.count(next) && !vis.count(next)) {
                        vis.insert(next);
                        q.push(next);
                    }

                   
                    next = cur;
                    next[i] = (next[i] - '0' + 9) % 10 + '0';

                    if (!dead.count(next) && !vis.count(next)) {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};