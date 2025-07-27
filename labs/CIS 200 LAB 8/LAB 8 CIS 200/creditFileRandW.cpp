#include "creditFileRandW.h"


void creditFileRandW::openCreditFile_read(void) {
	creditFile_read.open("credit.dat", ios::in | ios::binary);
	if (!creditFile_read.is_open()) {
		cout << "\nunable to open 'credit.dat' file.\n";
	}
	else { cout << "\n~Random Access File 'credit.dat' opened successfully~\n"; }

}

void creditFileRandW::openCreditFile_write(void) {

	creditFile_write.open("credit.dat", ios::out | ios::binary);  //NOTE:if no file exists, you may not be able to open in binary or using any other addtional modes 
												 //must open the uncreated file first using only the default constructor (no additional paramters other than ios::out and the file name),
												 // then close it and reopen (in binary for example) the newly created file. (idk if this is because of a c++ error but it worked as long as i didnt set the int mode (the last parameter)
	if (!creditFile_write.is_open()) {
		cout << "\nunable to open 'credit.dat' file.\n";
	}
	else { cout << "\n~Random Access File 'credit.dat' opened successfully~\n"; }

}
void creditFileRandW::clearAndClose_creditFile_read(void) {

	creditFile_read.clear();
	creditFile_read.close();
}
void creditFileRandW::clearAndClose_creditFile_write(void) {

	creditFile_write.clear();
	creditFile_write.close();
}

