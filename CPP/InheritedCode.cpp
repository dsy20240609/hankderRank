#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class BadLenthException : public exception {
private:
    string message;
public:
    BadLenthException(int nameLength) {
        stringstream ss;
        ss << "Too short:"  << std::to_string(nameLength);
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

/* Define the exception here */
  int n;
  cin>>n;
  for (int i =0;i <n;++i) {
    string username;
    cin>>username;
    try {
        checkUsername(username);    
    } catch(exception& messages) {
        
    }
}

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
// this problem actually i just need to override the exception class and write a user defiend
//exception, all other try catch block has been handled by the provided code.

/* Define the exception here */
 class BadLengthException : public exception {
private:
    string message;
public:
    BadLengthException(int nameLength) {
        stringstream ss;
        ss <<std::to_string(nameLength);
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};
