/*
 * Complete the 'isNonTrivialRotation' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

bool isNonTrivialRotation(string s1, string s2) {
   if (s1 == s2) return false;
   if(s1.length() == 1 && s2.length() ==1 && s1 != s2) return false;
   if (s1.length() != s2.length()) return false;
   for(size_t i =1 ; i <= s1.length()-1;++i) {
    string temp1= s1.substr(0,i);
    string temp2 = s1.substr(i,s1.length()-i);
    //std::reverse(temp1.begin(), temp1.end()); don't need to reverse, move left and move right is the same
    string s3= temp2+temp1;
    if (s3 == s2) return true;
   }
   return false;
}