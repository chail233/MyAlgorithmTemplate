string s1,s2;
vector<int> get_next() {
    int m = s2.length();
    vector<int> next(m, 0);
    for (int i=1;i<m;i++) {
        int j=next[i-1];
        while (j>0 && s2[i]!=s2[j]) j = next[j-1];
        if (s2[i]==s2[j]) next[i] = j+1;
    }
    return next;
}
vector<int> kmp(const vector<int>& next) {
    vector<int> res;
    int i=0;
    int j=0;
    while (i<s1.length()) {
        if (s1[i]==s2[j]) {
            i++;
            j++;
            if (j==s2.length()) {
                res.push_back(i-j);
                j = next[j-1];
            }
            continue;
        }
        if (j) j = next[j-1];
        else i++;
    }
    return res;
}
