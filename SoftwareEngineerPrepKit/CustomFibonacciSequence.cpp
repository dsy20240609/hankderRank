
long getAutoSaveInterval(int n) {
   if(n==0) {return 1;}
   if(n==1) {return 2;}
   vector<long> v(n+1, 0);
   v[0]=1;
   v[1]=2;
   for(int i=2; i <n+1;++i) {
    v[i]=v[i-1]+v[i-2];
   }
   return v[n];
}
