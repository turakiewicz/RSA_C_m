#pragma once

#include <string>
#include <vector>

using namespace std;



class RSA
{
	//vector<vector<long long int>> encryptedMessage;

	long long int N, E, D; // (n, e) - klucz publiczny, (n, d) - klucz prywatny

	long long int iloscZnalezionychLiczb, returned_x;
	void charToBin(char ch, bool bin[8]);
	void binToChar(bool bin[8], char& ch);
	long long int potegaModulo(long long int a, long long int n, long long int b);
	long long int NWD(long long int a, long long int b);

	void encryptHalfChar(bool binChar[4], long long int &binCharEncrypted);
	void decryptHalfChar(long long int binCharEncrypted, bool binChar[4]);

	string lliToString(long long int lli);

	

public:
	RSA();
	void createKeys(long long int P, long long int Q);

	string encrypt(string message);
	string decrypt(string cryptogram);

	string RSA::sitoEratostenesa(long long int b, long long int a);

	void set_n(long long int _n);
	void set_e(long long int _e);
	void set_d(long long int _d);

	long long int get_n();
	long long int get_e();
	long long int get_d();
};

