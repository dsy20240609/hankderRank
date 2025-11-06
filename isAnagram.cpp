int isAnagram(string s, string t) {
    map<char,int> count;
    if(s.length() != t.length()) return 0;
    for(size_t i = 0; i < s.length();++i) {
        if(count.find(s[i]) != count.end()) {
            count[s[i]] = count[s[i]]+1;
        } else {
            count[s[i]] =1;
        }
    }
    for(size_t i = 0 ; i < t.length();++i) {
        if(count.find(t[i]) != count.end()) {
            count[t[i]] = count[t[i]]-1;
        } else {
            return 0;
        }
    }
    map<char,int>::const_iterator iter;
    for(iter = count.begin(); iter != count.end(); ++iter) {
        if(iter.second != 0) {
            return 0;
        }
    }
    return 1;
}