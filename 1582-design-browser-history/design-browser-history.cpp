class BrowserHistory {
public:
   stack<string>backs;
   stack<string>forwards;
    BrowserHistory(string homepage) {
      backs.push(homepage);
    }
    
    void visit(string url) {
        backs.push(url);
        forwards=stack<string>();

    }
    
    string back(int steps) {
        while(backs.size()>1 && steps>0){
            forwards.push(backs.top());
            backs.pop();
            steps--;
        }
        return backs.top();
    }
    
    string forward(int steps) {
        while(!forwards.empty() && steps>0){
            backs.push(forwards.top());
            forwards.pop();
            steps--;
        }
        return backs.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */