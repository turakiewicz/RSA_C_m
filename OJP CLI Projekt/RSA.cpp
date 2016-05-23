#include "RSA.h"

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>

using namespace std;



RSA::RSA()
{
	srand(time(NULL));
}


void RSA::charToBin(char ch, bool bin[8])
{
	int asc = ch; // Convert char to ascii
	
	for (int i = 7; i >= 0; i--)
	{
		bin[i] = asc % 2;
		asc /= 2;
	}
}


void RSA::binToChar(bool bin[8], char& ch)
{
	long long int asc = 0;

	for (int i = 0; i < 8; i++)
		if (bin[i] == 1)
			asc += pow(2, 7 - i);

	ch = asc;
}


long long int RSA::potegaModulo(long long int a, long long int n, long long int b)
{
	long long int x = 1;
	long long int y = a;

	while (n > 0)
	{
		if (n % 2 == 1)
			x = (x * y) % b;
		y = (y * y) % b;
		n /= 2;
	}

	return x % b;
}


long long int RSA::NWD(long long int a, long long int b) {
	//Rozszerzony algorytm Euklidesa zwraca najwiekszy wspolny dzielnik

#define dlugoscTablic 100

	long long int r[dlugoscTablic], q[dlugoscTablic], x[dlugoscTablic], y[dlugoscTablic];
	long long int i;

	if (a < b) {
		long long int zamiana = a;
		a = b;
		b = zamiana;
	}
	else if (a == b) {
		printf("\n>>>NWD(): Liczba a nie moze byc rowna b!\n");
	}

	r[1] = a % b;
	q[1] = a / b;
	x[1] = 1;
	y[1] = -q[1];

	if (r[1] != 0) // Nie wiem, czy to dobre rozwi¹zanie, ale przynajmnie nie bêdzie wywalaæ przy dzieleniu przez 0
	{
		r[2] = b % r[1];
		q[2] = b / r[1];
	}
	else
		cout << "DZIELENIE PRZEZ ZERO" << endl;
	x[2] = -q[2] * x[1];
	y[2] = 1 - q[2] * y[1];

	i = 3;
	while (r[i - 1] != 0) {

		r[i] = r[i - 2] % r[i - 1];
		q[i] = r[i - 2] / r[i - 1];
		x[i] = x[i - 2] - x[i - 1] * q[i];
		y[i] = y[i - 2] - y[i - 1] * q[i];

		//printf("x[%lli] = %lli\ny[%lli] = %lli\n\n", i, x[i], i, y[i]);

		if (i > dlugoscTablic - 2) {
			printf("\n>>>NWD(): Liczba dlugoscTablic jest zbyt mala!\n");
			return 0;
		}
		i++;
	}

	returned_x = y[i - 2];
	return r[i - 2];
}


void RSA::createKeys(long long int P, long long int Q)
{
	long long int fiOdN;

	N = P * Q;
	fiOdN = (P - 1) * (Q - 1);

	do {
		E = (rand() % fiOdN) + 1;
	} while (NWD(fiOdN, E) != 1);

	D = returned_x;
	if (D < 0) {
		D += fiOdN;
	}
}


void RSA::encryptHalfChar(bool binChar[4], long long int &binCharEncrypted)
{
	// Convert bool array to long long int
	long long int m = 0;
	for (int i = 0; i < 4; i++)
		m += pow(10, i) * binChar[3 - i];

	// Encryption
	binCharEncrypted = potegaModulo(m, E, N);
}


void RSA::decryptHalfChar(long long int binCharEncrypted, bool binChar[4])
{
	// Decryption
	long long int dm = potegaModulo(binCharEncrypted, D, N);
	
	int i = 0;
	while (dm < pow(10, 3 - i))
	{
		binChar[i] = 0;
		i++;
		if (i > 3)
			break;
	}
	while (i <= 3)
	{
		binChar[i] = (dm / (int)pow(10, 3 - i)) % 2;
		i++;
	}
}


string RSA::lliToString(long long int lli)
{
	ostringstream ss;
	ss << lli;
	return ss.str();
}




string RSA::encrypt(string message)
{
	vector<vector<long long int>> encryptedMessage;

	for (int i = 0; i < message.length(); i++)
	{
		bool bin[8];
		charToBin(message[i], bin);
		//v
		cout << "bin = ";
		for (int i = 0; i < 8; i++)
			cout << bin[i];
		cout << endl;
		//^
		// Divide bin into two blocks
		bool bin_b1[4], bin_b2[4];
		for (int i = 0; i < 4; i++)
		{
			bin_b1[i] = bin[i];
			bin_b2[i] = bin[i + 4];
		}
		//v
		printf("b1:\tb2:\n");
		for (int i = 0; i < 4; i++)
			cout << bin_b1[i];
		printf("\t");
		for (int i = 0; i < 4; i++)
			cout << bin_b2[i];
		cout << endl;
		//^
		// Encrypt blocks and push them into encryptedMessage vector
		long long int temp;
		vector<long long int> oneChar;
		encryptHalfChar(bin_b1, temp);
		oneChar.push_back(temp);
		encryptHalfChar(bin_b2, temp);
		oneChar.push_back(temp);
		encryptedMessage.push_back(oneChar);

		//v
		cout << "Enc b1: ";
		for (int i = 0; i < encryptedMessage.size(); i++)
		{
			cout << encryptedMessage[i][0] << ", " << encryptedMessage[i][0] << endl;
		}
		cout << endl;
		//^
	}

	string eM = "";
	for (int i = 0; i < encryptedMessage.size(); i++)
	{
		eM += lliToString(encryptedMessage[i][0]) + " ";
		eM += lliToString(encryptedMessage[i][1]) + " ";
	}
	cout << "eM = " << eM << endl;

	return eM;
}


string RSA::decrypt(string cryptogram)
{
	cout << endl << "DECRYPTION:" << endl;
	string decryptedMessage = "";

	// Divide whole message into words
	vector<string> decryptedMessageString;
	int i = 0;
	stringstream ssin(cryptogram);
	while (ssin.good() && i < cryptogram.size()){
		string temp;
		ssin >> temp;
		decryptedMessageString.push_back(temp);
		++i;
	}

	//DDDDDDDDDDDDDDDDDD
	cout << endl << endl;
	for (i = 0; i < decryptedMessageString.size(); i++){
		cout << decryptedMessageString[i] << endl;
	}
	cout << endl << endl;
	//******************



	// Decryption
	for (int i = 0; i < decryptedMessageString.size() - 1; i += 2)
	{
		bool bin_b1[4], bin_b2[4], bin[8];
		decryptHalfChar(stoll(decryptedMessageString[i], 0), bin_b1);
		decryptHalfChar(stoll(decryptedMessageString[i + 1], 0), bin_b2);

		// Merge blocks
		for (int i = 0; i < 4; i++)
		{
			bin[i] = bin_b1[i];
			bin[i + 4] = bin_b2[i];
		}

		char ch;
		binToChar(bin, ch);
		decryptedMessage += ch;
	}
	
	return decryptedMessage;
}



string RSA::sitoEratostenesa(long long int b, long long int a) {
	long long int i, j;
	int iloscZnalezionychLiczb = 0;

	//Stworzenie listy wypelnionej liczbami od 2 do a
	long long int *lista = (long long int*)malloc((a - 1) * sizeof(long long int));
	if (lista == NULL) {
		fprintf(stderr, "\n\nWymagana pamiec nie zostala przydzielona!\a\n\n");
	}
	for (i = 0; i <= a - 2; i++) {
		*(lista + i) = i + 2;
		//printf("%i\n", *(lista + i));
	}

	//Przesiewanie
	long long int pozycjaPierwszegoElementu = 0;
	long long int pierwszyElement = 2;
	long long int pozycjaOstatniegoElementu = a - 2;
	long long int ostatniElement = *(lista + a - 2);


	while (pierwszyElement * pierwszyElement <= ostatniElement) {

		//Zerowanie elementow nie bedacych liczbami pierwszymi
		for (i = pozycjaPierwszegoElementu + 1; i <= a - 2; i++) {
			if (*(lista + i) % pierwszyElement == 0) {
				*(lista + i) = 0;
			}
		}

		//Szukanie pozycji i wartosci ostatniego niezerowego elementu listy
		for (i = a - 2; i > pozycjaPierwszegoElementu; i--) {
			if (*(lista + i) != 0) {
				pozycjaOstatniegoElementu = i;
				ostatniElement = *(lista + i);
				break;
			}
		}

			//Szukanie pozycji i wartosci nastepnego "pierwszego" elementu
			for (i = pozycjaPierwszegoElementu + 1; i < pozycjaOstatniegoElementu; i++) {
				if (*(lista + i) != 0) {
					pozycjaPierwszegoElementu = i;
					pierwszyElement = *(lista + i);
					break;
				}
			}

		printf(".");
	}

	//Zapisanie liczb pierwszych do nowej listy
	iloscZnalezionychLiczb = 0;
	long long int *liczbyPierwsze;

	for (i = 0; i <= a - 2; i++) {
		if (*(lista + i) != 0) {
			iloscZnalezionychLiczb++;
		}
	}

	liczbyPierwsze = (long long int*)malloc(iloscZnalezionychLiczb * sizeof(long long int));
	if (liczbyPierwsze == NULL) {
		fprintf(stderr, "\n\nWymagana pamiec nie zostala przydzielona!\a\n\n");
	}

	j = 0;
	for (i = 0; i <= a - 2; i++) {
		if (*(lista + i) != 0) {
			*(liczbyPierwsze + j) = *(lista + i);
			j++;
		}
	}
	free(lista);

	string sE = "";

	for (int i = 0; i < iloscZnalezionychLiczb; i++)
		sE += lliToString(*(liczbyPierwsze + i)) + '\t';

	return sE;
}



// Setters
void RSA::set_n(long long int _n) { N = _n; }
void RSA::set_e(long long int _e) { E = _e; };
void RSA::set_d(long long int _d) { D = _d; };


// Getters
long long int RSA::get_n() { return N; };
long long int RSA::get_e() { return E; };
long long int RSA::get_d() { return D; };