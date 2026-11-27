// 字符范围为 'a' 到 'z'，同一个字符串可以插入多次。
struct Trie {
    struct Node {
        int son[26]{};
        int cnt = 0, pre = 0;  // 完整单词次数、前缀次数
    };

    vector<Node> tr;
    Trie() : tr(1) {}

    void insert(const string& s) {
        int p = 0;
        tr[p].pre++;
        for (char ch : s) {
            int c = ch - 'a';
            if (!tr[p].son[c]) {
                tr[p].son[c] = tr.size();
                tr.emplace_back();
            }
            p = tr[p].son[c];
            tr[p].pre++;
        }
        tr[p].cnt++;
    }

    int find(const string& s) const {
        int p = 0;
        for (char ch : s) {
            p = tr[p].son[ch - 'a'];
            if (!p) return -1;
        }
        return p;
    }

    int count(const string& s) const {
        int p = find(s);
        return p == -1 ? 0 : tr[p].cnt;
    }

    int count_prefix(const string& s) const {
        int p = find(s);
        return p == -1 ? 0 : tr[p].pre;
    }
};
