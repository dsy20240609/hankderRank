int debounceTimestamps(vector<int> timestamps, int K) {
   if(timestamps.size() <=1) {return timestamps.size();}
   if(K<0) {return 1;}
   int slow =1;
   int fast =2;
   while(fast<timestamps.size()) {
       if(timestamps[fast] - timestamps[slow] <= K) { // within the distance ,fast move
        fast++;
       } else {
       timestamps[slow] =timestamps[fast];
       fast++;
       slow++; 
       }
   } 
   return slow;
}
// fast pointer points to next timestamp that nees to be examine, slow pointer points to the last element that
// should b kept. the first element should always be kept. the non decreasing element means that you only needs to
// check the distance between current element and its previous element, since the distance between current element 
// and element before the previous element is larger than the distance between current element and previous element.