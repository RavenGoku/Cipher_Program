//Copyright 2023, Kamil Mikołajewski. All Rights Reserved.

//Cipher Program
//Kryptograf
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
//----------------------------------------------------------
using namespace std;

int main()
{
	//Alphabet - Unicode
	string alphabet{
		"ABCDEFGHIJKLMNOPRSTUQWYZabcdefghijklmnoprstuqwyz1234567890!@#$%^&*_+-=()[]{};':\",.<>/?| "
	};

	//Key - Using Cesar Cipher for making key
	string key{
		"EfGhIjKlMnOpRsTuQwYzAbCdeFgHiJkLmNoPrStUqWyZaBcD=()[]{};':\",.<>/?| 1234567890!@#$-^&*_+%"
	};

	string encrypt_message{};          // coded message
	string decrypt_message{};          // decoded message
	string secret_message{};
	vector<string> vec_encryption{};                      // for storing encrypted messages
	size_t position{};                                                 // position of first find letter of the word
	char choice{};                                                     //choice char for do.while loop in "Language MENU"

	//===========================================================================================================
	if (vec_encryption.size() != 0)
	{
		for (size_t i = 0; i < vec_encryption.size(); i++)
		{
			for (size_t j = 0; j < vec_encryption.at(i).size(); j++)
			{
				position = alphabet.find(vec_encryption.at(i).at(j));
				if (position != string::npos)
				{
					encrypt_message.push_back(key.at(position));
				}
			}
			vec_encryption.at(i).swap(encrypt_message);
			encrypt_message.clear();
		}
	}

	//===========================================================================================================
	cout << " *******************************" << endl;                  // Welcome message
	cout << "*|*   By Kamil Mikolajewski   *|*" << endl;
	cout << " *******************************" << endl;                  // Welcome message
	cout << "*|*         LANGUAGE          *|*" << endl;
	cout << "*********************************" << endl;
	cout << "*|* E - English               *|*" << endl;
	cout << "*|* P - Polski                *|*" << endl;
	cout << "*|* Q - Quit                  *|*" << endl;
	cout << " *******************************" << endl;

	do
	{
		cout << "===Choose Language===: ";
		cin >> choice;

		switch (choice)
		{
		case'E':
		case'e':
		{
			char choice{};													 //In SCOPE 'choice' char for do.while loop in "English MENU"
			//English Menu
			system("cls");
			cout << "**************************************************" << endl;
			cout << "*|*         Welcome to Cipher Program          *|*" << endl;
			cout << "**************************************************" << endl;
			cout << "*|* M - Display MENU                           *|*" << endl;
			cout << "*|* P - Print all encrypted message            *|*" << endl;
			cout << "*|* A - Add encrypted message                  *|*" << endl;
			cout << "*|* D - Decrypt message                        *|*" << endl;
			cout << "*|* C - Clear messages                         *|*" << endl;
			cout << "*|* Q - Quit(Go to Language)                   *|*" << endl;
			cout << "**************************************************" << endl;
			do
			{
				cout << "==Enter your choice==: ";
				cin >> choice;
				switch (choice)
				{
				case 'M':
				case 'm':
					system("cls");
					cout << "**************************************************" << endl;
					cout << "*|*         Welcome to Cipher Program          *|*" << endl;
					cout << "**************************************************" << endl;
					cout << "*|* M - Display MENU                           *|*" << endl;
					cout << "*|* P - Print all encrypted message            *|*" << endl;
					cout << "*|* A - Add encrypted message                  *|*" << endl;
					cout << "*|* D - Decrypt message                        *|*" << endl;
					cout << "*|* C - Clear messages                         *|*" << endl;
					cout << "*|* Q - Quit(Go to Language)                   *|*" << endl;
					cout << "**************************************************" << endl;
					break;
				case 'P':
				case 'p':

					if (vec_encryption.size() != 0)
					{
						int i = 1; // number of secret message , use to display number of a message that has been stored
						for (auto &encrypt : vec_encryption)
						{
							cout << "[" << i << "]- " << encrypt << endl;
							i++;
						}
						cout << endl;
					}
					else
					{
						cout << "[] - list is empty" << endl;
					}
					break;
				case 'A':
				case 'a':
				{
					char choice{};                                                        //char name working Only on that scope
					do
					{
						cout << "Enter secret message: ";
						cin >> ws;                                                        //clear input stream (#include<iomanip> to use ws(white space clear) )
																							//when using getline is best option to clear stream before use
						getline(cin, secret_message, '\n');                               //input secret message

						for (size_t i = 0; i < secret_message.length(); i++)                 //for loop to encrypt message
						{
							position = alphabet.find(secret_message.at(i));
							if (position != string::npos)
							{
								encrypt_message.push_back(key.at(position));
							}
						}
						vec_encryption.push_back(encrypt_message);                        // store message in vector
						encrypt_message.clear();                                          // clear string to reuse if user wish to put another message

						cout << "Add another secret message(Y/N)? ";
						cin >> choice;
					} while (choice != 'N' && choice != 'n');
					break;
				}
				case 'D':
				case 'd':
				{
					if (vec_encryption.size() != 0)
					{
						unsigned int message_num{};
						cout << "You've got -" << vec_encryption.size() << "- messages." << endl;
						int i = 1; // number of secret message
						for (auto &encrypt : vec_encryption)
						{
							cout << "[" << i << "]- " << encrypt << endl;
							i++;
						}
						cout << endl;
						cout << "Which message you would like to decrypt? ";
						while (!(cin >> message_num))		// if cin if different that int throw out an error!
						{
							cin.clear(); //clear out error flag
							cin.ignore();// clear out cin stream(if there is some garbage)
							cout << "Enter integer number! - Try again...\n";
							cout << "Which message you would like to decrypt? ";
						}

						if (message_num == 0)
						{
							cout << "You can't choose 0! - try again! " << endl;
						}
						else if (message_num <= vec_encryption.size())
						{
							// choosing number of message, we need extract 1 from it to go to index zero in vector
							for (size_t i = 0; i < vec_encryption.at(message_num - 1).size(); i++)
							{
								//looking for first position of message at number of index and first letter then change key word to alphabet word
								position = key.find(vec_encryption.at(message_num - 1).at(i));
								if (position != string::npos)
								{
									decrypt_message.push_back(alphabet.at(position));
								}
							}
							for (auto &m : decrypt_message)
							{
								cout << m;
								if (m == ';' || m == '.')
									cout << endl;
							}
							decrypt_message.clear();
							cout << endl;
						}
						else
						{
							cout << "number too big!" << endl;
							cout << "there is only " << vec_encryption.size() << " messages! - Try again..." << endl;
						}
					}
					else
					{
						cout << "No Secret Messages! - []list is empty" << endl;
					}

					break;
				}
				case 'C':
				case 'c':
					if (vec_encryption.size() != 0)
					{
						vec_encryption.clear();
						cout << "Messages has been cleared!" << endl;
					}
					else
					{
						cout << "List is already empty!" << endl;
					}
					break;
				case 'Q':
				case 'q':
					break;
				default:
					cout << "Unknown selection, please try again..." << endl;
					break;
				}
			} while (choice != 'q' && choice != 'Q');
			system("cls");
			cout << "*********************************" << endl;                  //Language message
			cout << "*|*         LANGUAGE          *|*" << endl;
			cout << "*********************************" << endl;
			cout << "*|* E - English               *|*" << endl;
			cout << "*|* P - Polski                *|*" << endl;
			cout << "*|* Q - Quit                  *|*" << endl;
			cout << "*********************************" << endl;
			break;
		}
		case'P':
		case'p':
		{
			char choice{};													 //choice char for do.while loop in "English MENU"
			//Polskie Menu
			system("cls");
			cout << "*****************************************************" << endl;
			cout << "*|*            Witaj w Kryptografie               *|*" << endl;
			cout << "*****************************************************" << endl;
			cout << "*|* M - Wyswietl MENU                             *|*" << endl;
			cout << "*|* P - Wyswietl wszystkie zakodowane wiadomosci  *|*" << endl;
			cout << "*|* A - Dodaj wiadomosc do zakodowania            *|*" << endl;
			cout << "*|* D - Odkoduj wiadomosc                         *|*" << endl;
			cout << "*|* C - Wyczysc liste                             *|*" << endl;
			cout << "*|* Q - Wyjdz( Do wyboru jezykow)                 *|*" << endl;
			cout << "*****************************************************" << endl;
			do
			{
				cout << "==Wprowadz opcje==: ";
				cin >> choice;
				switch (choice)
				{
				case 'M':
				case 'm':
					system("cls");
					cout << "*****************************************************" << endl;
					cout << "*|*            Witaj w Kryptografie               *|*" << endl;
					cout << "*****************************************************" << endl;
					cout << "*|* M - Wyswietl MENU                             *|*" << endl;
					cout << "*|* P - Wyswietl wszystkie zakodowane wiadomosci  *|*" << endl;
					cout << "*|* A - Dodaj wiadomosc do zakodowania            *|*" << endl;
					cout << "*|* D - Odkoduj wiadomosc                         *|*" << endl;
					cout << "*|* C - Wyczysc liste                             *|*" << endl;
					cout << "*|* Q - Wyjdz( Do wyboru jezykow)                 *|*" << endl;
					cout << "*****************************************************" << endl;
					break;
				case 'P':
				case 'p':

					if (vec_encryption.size() != 0)
					{
						int i = 1; // number of secret message
						for (auto &encrypt : vec_encryption)
						{
							cout << "[" << i << "]- " << encrypt << endl;
							i++;
						}
						cout << endl;
					}
					else
					{
						cout << "[] - list jest pusta" << endl;
					}
					break;
				case 'A':
				case 'a':
				{
					char choice{};                                                        //char name working Only on that scope
					do
					{
						cout << "Wprowadz wiadomosc do zakodowania: ";
						cin >> ws;                                                        //clear input stream (#include<iomanip> to use ws(white space clear) )
																																							//when using getline is best option to clear stream before use
						getline(cin, secret_message, '\n');                               //input secret message

						for (size_t i = 0; i < secret_message.length(); i++)                 //for loop to encrypt message
						{
							position = alphabet.find(secret_message.at(i));
							if (position != string::npos)
							{
								encrypt_message.push_back(key.at(position));
							}
						}
						vec_encryption.push_back(encrypt_message);                        // store message in vector
						encrypt_message.clear();                                          // clear string to reuse if user wish to put another message

						cout << "Czy chcesz dodac kolejna wiadomosc(T/N)? ";
						cin >> choice;
					} while (choice != 'N' && choice != 'n');
					break;
				}
				case 'D':
				case 'd':
				{
					if (vec_encryption.size() != 0)
					{
						unsigned int message_num{};
						cout << "Masz -" << vec_encryption.size() << "- wiadomosci." << endl;
						int i = 1; // number of secret message
						for (auto &encrypt : vec_encryption)
						{
							cout << "[" << i << "]- " << encrypt << endl;
							i++;
						}
						cout << endl;
						cout << "Ktora wiadomosc chcialbys odkodowac? ";
						while (!(cin >> message_num))		// if cin if different that int throw out an error!
						{
							cin.clear();
							cin.ignore();
							cout << "Wprowadz numer! - Sprobuj ponownie...\n";
							cout << "Ktora wiadomosc chcialbys odkodowac? ";
						}

						if (message_num == 0)
						{
							cout << "Nie mozesz wybrac 0! - Sprobuj ponownie! " << endl;
						}
						else if (message_num <= vec_encryption.size())
						{
							// choosing number of message, we need extract 1 from it to go to index zero in vector
							for (size_t i = 0; i < vec_encryption.at(message_num - 1).size(); i++)
							{
								//looking for first position of message at number of index and first letter then change key word to alphabet word
								position = key.find(vec_encryption.at(message_num - 1).at(i));
								if (position != string::npos)
								{
									decrypt_message.push_back(alphabet.at(position));
								}
							}
							for (auto &m : decrypt_message)
							{
								cout << m;
								if (m == ';' || m == '.')
									cout << endl;
							}
							decrypt_message.clear();
							cout << endl;
						}
						else
						{
							cout << "Nie ma tylu wiadomosci!" << endl;
							cout << "Jest tylko " << vec_encryption.size() << " wiadomosci! - Sprobuj ponownie..." << endl;
						}
					}
					else
					{
						cout << "Nie ma zadnych sekretnych wiadomosci! - []lista jest pusta" << endl;
					}

					break;
				}
				case 'C':
				case 'c':
					if (vec_encryption.size() != 0)
					{
						vec_encryption.clear();
						cout << "Lista zostala wyczyszczona!" << endl;
					}
					else
					{
						cout << "Lista juz jest pusta!" << endl;
					}
					break;
				case 'Q':
				case 'q':
					break;
				default:
					cout << "Blad wyboru!, sprobuj jeszcze raz..." << endl;
					break;
				}
			} while (choice != 'q' && choice != 'Q');
			system("cls");
			cout << "*********************************" << endl;                  // Language message
			cout << "*|*         LANGUAGE          *|*" << endl;
			cout << "*********************************" << endl;
			cout << "*|* E - English               *|*" << endl;
			cout << "*|* P - Polski                *|*" << endl;
			cout << "*|* Q - Quit                  *|*" << endl;
			cout << "*********************************" << endl;
			break;
		}
		case'Q':
		case'q':
			break;

		default:
			cout << "Unknown selection, please try again..." << endl;
			break;
		}
	} while (choice != 'q' && choice != 'Q');

	system("pause");
	cout << endl;
	return 0;
}