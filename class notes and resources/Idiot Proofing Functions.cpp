#include <iostream>
#include <string>

using namespace std;

/***************************************
		  FUNCTION PROTOTYPES
****************************************/

int getInt( string message = "Please enter an integer: ");
bool getInt(int& userVal, const int maxAttempts,  string message = "Please enter an integer: ");
int getInt(bool minOrMax, int minMaxVal, string message = "Please input an integer in range: ");
int getInt(bool inside, int minVal, int maxVal, string message = "Please input an integer for range: ");
bool getInt(bool minOrMax, int minMaxVal, int & userVal, int maxAttempts, string message = "Please input an integer for range : ");
bool getInt(bool inside, int minVal, int maxVal, int& userVal, int maxAttempts, string message = "Please input an integer for range : ");


long getLong(string message = "Please enter a long: ");
bool getLong(long & userVal, const int maxAttempts, string message = "Please enter a long: ");
long getLong(bool minOrMax, long minMaxVal, string message = "Please input a long in range: ");
long getLong(bool inside, long minVal, long maxVal, string message = "Please input a long for range: ");
bool getLong(bool minOrMax, long minMaxVal, long & userVal, int maxAttempts, string message = "Please input a long for range : ");
bool getLong(bool inside, long minVal, long maxVal, long & userVal, int maxAttempts, string message = "Please input a long for range : ");


float getFloat(string message = "Please enter a float: ");
bool getFloat(float & userVal, const int maxAttempts, string message = "Please enter n float: ");
float getFloat(bool minOrMax, float minMaxVal, string message = "Please input a float in range: ");
float getFloat(bool inside, float minVal, float maxVal, string message = "Please input a float for range: ");
bool getFloat(bool minOrMax, float minMaxVal, float & userVal, int maxAttempts, string message = "Please input a float for range : ");
bool getFloat(bool inside, float minVal, float maxVal, float& userVal, int maxAttempts, string message = "Please input a float for range : ");


double getDouble(string message = "Please enter a double: ");
bool getDouble(double & userVal, const int maxAttempts, string message = "Please enter n double: ");
double getDouble(bool minOrMax, double minMaxVal, string message = "Please input a double in range: ");
double getDouble(bool inside, double minVal, double maxVal, string message = "Please input a double for range: ");
bool getDouble(bool minOrMax, double minMaxVal, double & userVal, int maxAttempts, string message = "Please input a double for range : ");
bool getDouble(bool inside, double minVal, double maxVal, double & userVal, int maxAttempts, string message = "Please input a double for range : ");


char getChar(string message = "Please enter an alpha character: ");
bool getChar(char & userVal, const int maxAttempts, string message = "Please enter an alpha character: ");
char getChar(bool minOrMax, char minMaxVal, string message = "Please input a char in range: ");
char getChar(bool inside, char minVal, char maxVal, string message = "Please input a char for range: ");
bool getChar(bool minOrMax, char minMaxVal, char & userVal, int maxAttempts, string message = "Please input a char for range : ");
bool getChar(bool inside, char minVal, char maxVal, char & userVal, int maxAttempts, string message = "Please input a char for range : ");


/***************************************
				MAIN
****************************************/

int main() {
	int intVar = -12;
	float floatVar = -23.456f;
	double doubleVar = -17.981;
	char charVar = 'G';

	cout << "Testing first float function\n";
	
	cout << "default message\n";
	cout << getFloat() << endl;
	cout << "overriding default message";
	cout << getFloat("testing float: ") << endl;
	
	// we want to succeed on 3rd try
	cout << "\n\nTesting second float function\n want to succeed on 3rd try\n";
	if (getFloat(floatVar, 3))
		cout << "float value: " << floatVar << endl;
	else
		cout << "Too many attempts\n";
	cout << "\nagain, overriding default message\n";
	if (getFloat(floatVar, 3, "testing: enter float "))
		cout << "float value: " << floatVar;
	else
		cout << "Too many attempts float\n";

	// we want to fail in 3 attempts
	cout << "\n\nTesting third float function\n  want to fail in 3rd try\n";
	if (getFloat(floatVar, 3))
		cout << "float value: " << floatVar << endl;
	else
		cout << "Too many attempts for float\n";
	
	cout << "\n\nagain, overriding message\n";
	if (getFloat(floatVar, 3, "testing- enter a float: "))
		cout << "float value: " << 	floatVar;
	else
		cout << "Too many attempts failed float\n";
		

	cout << "\n\n\n\ntesting range\n";
	cout << "inside range\n";
	cout << getFloat(true, -200, 128);

	cout << getFloat(true, -200, 128, "-200 128");
	
	cout << "outside range\n";
	cout << getFloat(false, -200, 128);

	cout << getFloat(false, -200, 128, "-200 128");
	
	cout << "\n\ntesting 5th float function\nabove 0\n\n";
	if (getFloat(true, 0, floatVar, 3))
		cout << "float value: " << floatVar << endl;
	else
		cout << "Too many attempts for float\n";
	
	cout << "\n\nagain, overriding message\n";
	if (getFloat(true, 0, floatVar, 3, "testing- enter a float: "))
		cout << "float value: " << floatVar;
	else
		cout << "Too many attempts failed float\n";

	cout << "\n\nnow below 0\n";
	if (getFloat(false, 0, floatVar, 3))
		cout << "float value: " << floatVar << endl;
	else
		cout << "Too many attempts for float\n";

	cout << "\n\nagain, overriding message\n";
	if (getFloat(false, 0, floatVar, 3, "testing- enter an float: "))
		cout << "float value: " << floatVar;
	else
		cout << "Too many attempts failed float\n";


	cout << "\n\ntesting ends\n\n";


	system("pause");

	return 0;
}


/***************************************
		  INT FUNCTIONS
****************************************/

// keep asking for a int until one is returned
int getInt(string message) {
	int userVal;

	cout << message;

	while (!(cin >> userVal)) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << "Invalid input\n" << message;
	}

	return userVal;
}


// ask for a int n times, returning input by parameter. Return true if within n attempts else return false
bool getInt(int & userVal, const int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	while ((!(cin >> userVal)) && numAttempts < maxAttempts) {
		++numAttempts;
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << "Invalid input\n" << message;
	}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}

	return retVal;
}


// keep asking for Int until one is returned that is above or below minMaxVal.  minOrMax is true then it's minimum value else maximum value
int getInt(bool minOrMax, int minMaxVal, string message) {
	int userVal;

	cout << message;

	if (minOrMax)	// greater than minimum
		while ((!(cin >> userVal)) || userVal < minMaxVal) {
			cin.clear();	//must be before ignore
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
			cout << "Invalid input\n" << message;
		}
	else			// less than maximum
		while ((!(cin >> userVal)) || userVal > minMaxVal) {
			cin.clear();	//must be before ignore
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
			cout << "Invalid input\n" << message;
		}

	return userVal;
}


//Keep asking for int until one is returned.  Within is true if between min & max, false if outside min & max
int getInt(bool within, int minVal, int maxVal, string message) {
	int userVal;

	cout << message;

	if (within) {//between min, max values
		while ((!(cin >> userVal)) || userVal < minVal || userVal > maxVal) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}
	}
	else	// outside min, max value
		while ((!(cin >> userVal)) || (userVal > minVal && userVal < maxVal)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}

	return userVal;
}


//keep asking for int until one is returned that is above or below minMaxVal, within n attempts.  minOrMax is true then it's minimum value else maximum value
bool getInt(bool minOrMax, int minMaxVal, int & userVal, int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	if (minOrMax) //greater than or equal min value
		while (((!(cin >> userVal)) || userVal < minMaxVal) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}
	else	// less than or equal max value
		while (((!(cin >> userVal)) || userVal > minMaxVal) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}
	//check final read for incorrect range
	else if (minOrMax && userVal < minMaxVal)
		retVal = false;
	else if ((!minOrMax) && userVal > minMaxVal)
		retVal = false;

	return retVal;
}


// keep asking for int, up to n times, and either not between two values or not outside two values. Return input in parameter
bool getInt(bool inside, int minVal, int maxVal, int & userVal, int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	if (inside) //within range
		while (((!(cin >> userVal)) || (userVal < minVal || userVal > maxVal)) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "not within range\n" << message;
		}
	else	// outside range
		while (((!(cin >> userVal)) || (userVal > minVal && userVal < maxVal)) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "not outside range\n" << message;
		}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}
	// check final read for incorrect range
	else if (inside && (userVal < minVal || userVal > maxVal))
		retVal = false;
	else if ((!inside) && userVal > minVal && userVal < maxVal)
		retVal = false;

	return retVal;
}



/***************************************
		  LONG FUNCTIONS
****************************************/

// keep asking for a long until one is returned
long getLong(string message) {
	long userVal;

	cout << message;

	while (!(cin >> userVal)) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << "Invalid input\n" << message;
	}

	return userVal;
}


// ask for a long n times, returning input by parameter. Return true if within n attempts else return false
bool getLong(long & userVal, const int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	while ((!(cin >> userVal)) && numAttempts < maxAttempts) {
		++numAttempts;
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << "Invalid input\n" << message;
	}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}

	return retVal;
}


// keep asking for long until one is returned that is above or below minMaxVal.  minOrMax is true then it's minimum value else maximum value
long getLong(bool minOrMax, long minMaxVal, string message) {
	long userVal;

	cout << message;

	if (minOrMax)	// greater than minimum
		while ((!(cin >> userVal)) || userVal < minMaxVal) {
			cin.clear();	//must be before ignore
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
			cout << "Invalid input\n" << message;
		}
	else			// less than maximum
		while ((!(cin >> userVal)) || userVal > minMaxVal) {
			cin.clear();	//must be before ignore
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
			cout << "Invalid input\n" << message;
		}

	return userVal;
}


//Keep asking for long until one is returned.  Within is true if between min & max, false if outside min & max
long getLong(bool within, long minVal, long maxVal, string message) {
	long userVal;

	cout << message;

	if (within) {//between min, max values
		while ((!(cin >> userVal)) || userVal < minVal || userVal > maxVal) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}
	}
	else	// outside min, max value
		while ((!(cin >> userVal)) || (userVal > minVal && userVal < maxVal)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}

	return userVal;
}


// keep asking for long until one is returned that is above or below minMaxVal, within n attempts.  minOrMax is true then it's minimum value else maximum value
// return answer in parameter
bool getLong(bool minOrMax, long minMaxVal, long & userVal, int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	if (minOrMax) //greater than or equal min value
		while (((!(cin >> userVal)) || userVal < minMaxVal) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}
	else	// less than or equal max value
		while (((!(cin >> userVal)) || userVal > minMaxVal) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}
	//check final read for incorrect range
	else if (minOrMax && userVal < minMaxVal)
		retVal = false;
	else if ((!minOrMax) && userVal > minMaxVal)
		retVal = false;

	return retVal;
}


// keep asking for long until one is returned that is either between min & max or outside min&max, within n attempts. 
// inside is true then it's betwen else it's outside
bool getLong(bool inside, long minVal, long maxVal, long & userVal, int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	if (inside) //within range
		while (((!(cin >> userVal)) || (userVal < minVal || userVal > maxVal)) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "not within range\n" << message;
		}
	else	// outside range
		while (((!(cin >> userVal)) || (userVal > minVal && userVal < maxVal)) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "not outside range\n" << message;
		}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}
	// check final read for incorrect range
	else if (inside && (userVal < minVal || userVal > maxVal))
		retVal = false;
	else if ((!inside) && userVal > minVal && userVal < maxVal)
		retVal = false;

	return retVal;
}



/***************************************
		  FLOAT FUNCTIONS
****************************************/

// keep asking for a float until one is returned
float getFloat(string message) {
	float userVal;

	cout << message;

	while (!(cin >> userVal)) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << "Invalid input\n" << message;
	}

	return userVal;
}


// ask for a float n times, returning input by parameter. Return true if within n attempts else return false
bool getFloat(float& userVal, const int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	while ((!(cin >> userVal)) && numAttempts < maxAttempts) {
		++numAttempts;
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << "Invalid input\n" << message;
	}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}

	return retVal;
}


// keep asking for float until one is returned that is above or below minMaxVal.  minOrMax is true then it's minimum value else maximum value
float getFloat(bool minOrMax, float minMaxVal, string message) {
	float userVal;

	cout << message;

	if (minOrMax)	// greater than minimum
		while ((!(cin >> userVal)) || userVal < minMaxVal) {
			cin.clear();	//must be before ignore
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
			cout << "Invalid input\n" << message;
		}
	else			// less than maximum
		while ((!(cin >> userVal)) || userVal > minMaxVal) {
			cin.clear();	//must be before ignore
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
			cout << "Invalid input\n" << message;
		}

	return userVal;
}


//Keep asking for float until one is returned.  Within is true if between min & max, false if outside min & max
float getFloat(bool within, float minVal, float maxVal, string message) {
	float userVal;

	cout << message;

	if (within) {//between min, max values
		while ((!(cin >> userVal)) || userVal < minVal || userVal > maxVal) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}
	}
	else	// outside min, max value
		while ((!(cin >> userVal)) || (userVal > minVal && userVal < maxVal)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}

	return userVal;
}


//keep asking for float until one is returned that is above or below minMaxVal, within n attempts.  minOrMax is true then it's minimum value else maximum value
bool getFloat(bool minOrMax, float minMaxVal, float & userVal, int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	if (minOrMax) //greater than or equal min value
		while (((!(cin >> userVal)) || userVal < minMaxVal) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}
	else	// less than or equal max value
		while (((!(cin >> userVal)) || userVal > minMaxVal) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}
	//check final read for incorrect range
	else if (minOrMax && userVal < minMaxVal)
		retVal = false;
	else if ((!minOrMax) && userVal > minMaxVal)
		retVal = false;

	return retVal;
}


// keep asking for float until one is returned that is either between min & max or outside min&max, within n attempts. 
// inside is true then it's betwen else it's outside
bool getFloat(bool inside, float minVal, float maxVal, float & userVal, int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	if (inside) //within range
		while (((!(cin >> userVal)) || (userVal < minVal || userVal > maxVal)) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "not within range\n" << message;
		}
	else	// outside range
		while (((!(cin >> userVal)) || (userVal > minVal && userVal < maxVal)) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "not outside range\n" << message;
		}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}
	// check final read for incorrect range
	else if (inside && (userVal < minVal || userVal > maxVal))
		retVal = false;
	else if ((!inside) && userVal > minVal && userVal < maxVal)
		retVal = false;

	return retVal;
}



/***************************************
		  DOUBLE FUNCTIONS
****************************************/

// keep asking for a double until one is returned
double getDouble(string message) {
	double userVal;

	cout << message;

	while (!(cin >> userVal)) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << "Invalid input\n" << message;
	}

	return userVal;
}


// ask for a double n times, returning input by parameter. Return true if within n attempts else return false
bool getDouble(double & userVal, const int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	while ((!(cin >> userVal)) && numAttempts < maxAttempts) {
		++numAttempts;
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << "Invalid input\n" << message;
	}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}

	return retVal;
}


// keep asking for double until one is returned that is above or below minMaxVal.  minOrMax is true then it's minimum value else maximum value
double getDouble(bool minOrMax, double minMaxVal, string message) {
	double userVal;

	cout << message;

	if (minOrMax)	// greater than minimum
		while ((!(cin >> userVal)) || userVal < minMaxVal) {
			cin.clear();	//must be before ignore
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
			cout << "Invalid input\n" << message;
		}
	else			// less than maximum
		while ((!(cin >> userVal)) || userVal > minMaxVal) {
			cin.clear();	//must be before ignore
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
			cout << "Invalid input\n" << message;
		}

	return userVal;
}


//Keep asking for double until one is returned.  Within is true if between min & max, false if outside min & max
double getDouble(bool within, double minVal, double maxVal, string message) {
	double userVal;

	cout << message;

	if (within) {//between min, max values
		while ((!(cin >> userVal)) || userVal < minVal || userVal > maxVal) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}
	}
	else	// outside min, max value
		while ((!(cin >> userVal)) || (userVal > minVal && userVal < maxVal)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}

	return userVal;
}


//keep asking for double until one is returned that is above or below minMaxVal, within n attempts.  minOrMax is true then it's minimum value else maximum value
bool getDouble(bool minOrMax, double minMaxVal, double & userVal, int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	if (minOrMax) //greater than or equal min value
		while (((!(cin >> userVal)) || userVal < minMaxVal) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}
	else	// less than or equal max value
		while (((!(cin >> userVal)) || userVal > minMaxVal) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}
	//check final read for incorrect range
	else if (minOrMax && userVal < minMaxVal)
		retVal = false;
	else if ((!minOrMax) && userVal > minMaxVal)
		retVal = false;

	return retVal;
}


// keep asking for double until one is returned that is either between min & max or outside min&max, within n attempts. 
// inside is true then it's betwen else it's outside
bool getDouble(bool inside, double minVal, double maxVal, double & userVal, int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	if (inside) //within range
		while (((!(cin >> userVal)) || (userVal < minVal || userVal > maxVal)) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "not within range\n" << message;
		}
	else	// outside range
		while (((!(cin >> userVal)) || (userVal > minVal && userVal < maxVal)) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "not outside range\n" << message;
		}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}
	// check final read for incorrect range
	else if (inside && (userVal < minVal || userVal > maxVal))
		retVal = false;
	else if ((!inside) && userVal > minVal && userVal < maxVal)
		retVal = false;

	return retVal;
}



/***************************************
		  CHAR FUNCTIONS
****************************************/

// ask for char until alphabetic is entered
char getChar(string message ) {
	char userVal;

	cout << message;

	while ( !( cin >> userVal || isalpha(userVal) ) ) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << message;
	}

	return userVal;
}

// ask for a char (which is alphabetic) up to n times, returning input by parameter. Return true if within n attempts else return false
bool getChar(char & userVal, const int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	while (!(cin >> userVal || isalpha(userVal)) && numAttempts < maxAttempts) {
		++numAttempts;
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
		cout << message;
	}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (cin.fail()) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}

	return retVal;
}



// keep asking for char until one is returned that is above or below minMaxVal.  minOrMax is true then it's minimum value else maximum value
char getChar(bool minOrMax, char minMaxVal, string message) {
	char userVal;

	cout << message;

	if (minOrMax)	// greater than minimum
		while ((!(cin >> userVal)) || userVal < minMaxVal) {
			cin.clear();	//must be before ignore
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
			cout << "Invalid input\n" << message;
		}
	else			// less than maximum
		while ((!(cin >> userVal)) || userVal > minMaxVal) {
			cin.clear();	//must be before ignore
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
			cout << "Invalid input\n" << message;
		}

	return userVal;
}


//Keep asking for double until one is returned.  Within is true if between min & max, false if outside min & max
char getChar(bool within, char minVal, char maxVal, string message) {
	char userVal;

	cout << message;

	if (within) {//between min, max values
		while ((!(cin >> userVal)) || userVal < minVal || userVal > maxVal) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}
	}
	else	// outside min, max value
		while ((!(cin >> userVal)) || (userVal > minVal && userVal < maxVal)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}

	return userVal;
}


//keep asking for char until one is returned that is above or below minMaxVal, within n attempts.  minOrMax is true then it's minimum value else maximum value
bool getChar(bool minOrMax, char minMaxVal, char & userVal, int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	if (minOrMax) //greater than or equal min value
		while (((!(cin >> userVal)) || userVal < minMaxVal) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}
	else	// less than or equal max value
		while (((!(cin >> userVal)) || userVal > minMaxVal) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input\n" << message;
		}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}
	//check final read for incorrect range
	else if (minOrMax && userVal < minMaxVal)
		retVal = false;
	else if ((!minOrMax) && userVal > minMaxVal)
		retVal = false;

	return retVal;
}


// keep asking for char until one is returned that is either between min & max or outside min&max, within n attempts. 
// inside is true then it's betwen else it's outside
bool getChar(bool inside, char minVal, char maxVal, char & userVal, int maxAttempts, string message) {
	int numAttempts = 1;

	cout << message;

	if (inside) //within range
		while (((!(cin >> userVal)) || (userVal < minVal || userVal > maxVal)) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "not within range\n" << message;
		}
	else	// outside range
		while (((!(cin >> userVal)) || (userVal > minVal && userVal < maxVal)) && numAttempts < maxAttempts) {
			++numAttempts;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "not outside range\n" << message;
		}

	// in case status is error, use variable and clean up
	bool retVal = cin.good();
	if (!retVal) {
		cin.clear();	//must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//clear buffer
	}
	// check final read for incorrect range
	else if (inside && (userVal < minVal || userVal > maxVal))
		retVal = false;
	else if ((!inside) && userVal > minVal && userVal < maxVal)
		retVal = false;

	return retVal;
}
