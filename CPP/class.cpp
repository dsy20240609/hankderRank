#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student {

    private:
    int age;
    string firstName;
    string lastName;
    int standard;

    public:
    //Student();
    int get_age() {return age;}
    void set_age(int age_in) {age=age_in;}

    string get_first_name() {return firstName;}
    void set_first_name( string firstName_in) {firstName = firstName_in;}

    string get_last_name() {return lastName;}
    void set_last_name (string lastName_in) {lastName = lastName_in;}

    int get_standard() {return standard;}
    void set_standard(int standard_in) {standard = standard_in;}
    string to_string() {
        string res = std::to_string(age)  + "," + firstName + "," + lastName + "," + std::to_string(standard);
        return res;
    }

};
// here if you uncomment the Student() constructor, there will be an error. so by default the compiler
// has generated the constructor for you.

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}