int main() {
   
    map<int,string> numMap={
        {1,"one"},
        {2,"two"},
        {3,"three"},
        {4,"four"},
        {5,"five"},
        {6,"six"},
        {7,"seven"},
        {8,"eight"},
        {9,"nine"}
    };
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;++i) {
        if(i<=9) {
            printf("%s\n",numMap[i].c_str());
        } else if (i%2==0) {
            printf("even\n");
        } else {
            printf("odd\n");
        }
    }
    return 0;
}