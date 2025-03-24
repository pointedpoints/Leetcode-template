class Trie{
    private:
    class Node{
        public:
        Node* child[26];
        int endWith;

        Node() :endWith(0) {
            for(int i=0; i<26; i++)
                child[i] = nullptr;
        }

        bool is_empty() const{
            for(int i=0; i<26; i++)
                if(child[i] != nullptr)
                    return false;

            return true;
        }
    };

    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(const string& s){
        Node* now = root;
        for(char ch : s){
            int next = ch-'a';
            if(now->child[next] == nullptr)
                now->child[next] = new Node();
            now = now->child[next];
        }
        now->endWith++;
    }

    void erase(const string &s){
        stack< pair<Node*, int> > route;
        Node* now = root;
        
        for(char ch : s){
            int next = ch-'a';
            if(now->child[next]==nullptr)
                return;
            route.push({now, next});
            now = now->child[next];
        }

        now -> endWith--;
        if(now->endWith != 0)
            return;

        while(!route.empty()){
            Node* prt = route.top().first;
            int idx = route.top().second;
            route.pop();
            now = prt->child[idx];
            if(now->is_empty() && now->endWith == 0){
                prt->child[idx] = nullptr;
                delete now;
            }
            else break;
        }
    }

    int query(const string &s){
        Node* now = root;
        int ret = 0;
        for(char ch : s){
            int next = ch-'a';
            if(now->child[next] == nullptr)
                return ret;
            now = now->child[next];
            ret += now->endWith;
        }
        return ret;
    }

};