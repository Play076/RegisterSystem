#include <iostream>
#include <string.h>
#include <conio.h>
#include <exception>
#include <windows.h>

using namespace std;

//Constantes Globais Matrix of defineted of size data
#define rows 100
#define cols 45

//Database
int id[rows];
char username[rows][cols];
char usernick[rows][cols];
char usermail[rows][cols];
char userpswd[rows][cols];
char op;

//Software function
void registerclient(const char titleclient[40]);
void loginclient(const char titleclient[40]);
void recoverclient(const char titleclient[40]);
//Function systems
bool sessionclient(const char nameuser[cols], const char namepswd[cols]);
void homeclient(const char nameuser[cols], const char namepswd[cols]);
void updateclient(const char nameuser[cols], const char namepswd[cols]);
void viewclient(const char nameuser[cols], const char namepswd[cols]);
void deleteclient(const char nameuser[cols], const char namepswd[cols]);
//Main System
int main()
{
	try
	{
		//Home Menu
		system("COLOR 02");
		tryagain:
		system("CLS");
		system("TITLE Launcher XCyberTech Soft");
		cout << "\n\t[C] Create Account\t" << endl;
		cout << "\n\t[L] Log In Account\t" << endl;
		cout << "\n\t[R] Recover Account\t" << endl;
		//The user here selects one of the three options above
		op = getche();
		switch(op)
		{
			case 67:
			case 99:
				Beep(1400, 200);
				system("CLS");
				registerclient("\n\tRegister Client\t");//Register users	
			break;
			case 76:
			case 108:
				Beep(1400, 200);
				system("CLS");
				loginclient("\n\tLog In Client\t");//Log in area
			break;
			case 82:
			case 114:
				Beep(1400, 200);
				system("CLS");
				recoverclient("\n\tRecover Account\t");//Recover account of user
			break;
			case 27:
			system("CLS");
			exit(0);
			break;
			default:
				system("COLOR 04");
				Beep(1500, 200);
				cout << "\n\tInvalid Option\t" << endl;//Case option invalid
				system("PAUSE");
				system("COLOR 02");
				goto tryagain;
			break;
		}
	}catch(exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
	return 0;
}
void registerclient(const char titleclient[40])
{
	try
	{
		//Variables local for add timered of datas
		static int row;//row of id static
		char registeruser[cols];
		char registernick[cols];
		char registermail[cols];
		char registerpswd[cols];
		char passwordveri[cols];
		
		system("CLS");
		tryotheracc:
		cout << titleclient << endl;//The client insert your data here
		cout << "\n\tEnter your name of user: ";
		cin >> registeruser;
		cout << "\n\tEnter your name of nick: ";
		cin >> registernick;
		cout << "\n\tEnter your name of mail: ";
		cin >> registermail;
		cout << "\n\tEnter your password name: ";
		cin >> registerpswd;
		cout << "\n\tConfirm your password name: ";
		cin >> passwordveri;
		trypassword:
		system("CLS");
		if(strcmp(registerpswd, passwordveri)==0)//Verification if password have equals
		{
			for(int i = 0; i < rows; i++)
			{
				if(strcmp(username[i], registeruser) == 0 ||
				   strcmp(usernick[i], registernick) == 0 ||
				   strcmp(usermail[i], registermail) == 0 ||
				   strcmp(userpswd[i], registerpswd) == 0
				  )//Verification if data inserts allready exist
				{
					tryagainacc:
					system("CLS");
					system("COLOR 06");
					Beep(1300, 200);
					cout << "\n\tError this is account allready exists\n\tTry register other account: <Y/N>" << endl;
					op = getche();
					system("CLS");
					switch(op)
					{
						case 89:
						case 121:
							Beep(1300, 200);
							goto tryotheracc;
						break;
						case 78:
						case 110:
							system("COLOR 02");
							Beep(1300, 200);
							main();
						break;
						default:
							system("COLOR 04");
							Beep(1500, 200);
							cout << "\n\tInvalid Option\t" << endl;
							system("PAUSE");
							goto tryagainacc;
						break;
					}
				}
			}
			for(int i = 0; i < cols; i++)//Case not exist the datas, create new datas
			{
				id[row] = row + 1;
				username[row][i] = registeruser[i];
				usernick[row][i] = registernick[i];
				usermail[row][i] = registermail[i];
				userpswd[row][i] = registerpswd[i]; 
			}
		}else//Case the passwords not equals, the user trying again repet the insert the password
		{
			system("COLOR 06");
			Beep(1300, 200);
			cout << "\n\tError password name incorret\n\tTry again" << endl;
			cout << "\n\tEnter your password name: ";
			cin >> registerpswd;
			cout << "\n\tConfirm your password name: ";
			cin >> passwordveri;
			system("COLOR 02");
			goto trypassword;
		}
		row++;
		Beep(1500, 200);
		cout << "\n\tYour new account was registed with successfully" << endl;
		system("PAUSE");
		system("COLOR 02");
		main();//Turn back for main system
	}catch(exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}
void loginclient(const char titleclient[40])
{
	try
	{
		//Variables local for add data of comparasion with the data have on database
		char loginuser[cols];
		char loginpswd[cols];

		system("CLS");
		tryloginaccount:
		cout << titleclient << endl;
		cout << "\n\tEnter your name of user: ";
		cin >> loginuser;
		cout << "\n\tEnter your password name: ";
		cin >> loginpswd;

		for(int i = 0; i < rows; i++)
		{
			if(strcmp(username[i], loginuser) == 0 && strcmp(userpswd[i], loginpswd) == 0)
			{
				system("CLS");
				system("COLOR 01");
				Beep(1400, 200);
				cout << "\n\tWelcome " << usernick[i] << endl;
				system("PAUSE");
				system("CLS");
				system("COLOR 02");
				homeclient(loginuser, loginpswd);
			}
		}
		tryerrorlogin:
		system("CLS");
		Beep(1500, 200);
		system("COLOR 04");
		cout << "\n\tError user of name or password name was not exist or wrong\n\tTry again: <Y/N>" << endl;
		op = getche();
		system("CLS");
		switch(op)
		{
			case 89:
			case 121:
				Beep(1300, 200);
				system("COLOR 02");
				goto tryloginaccount;
			break;
			case 78:
			case 110:
				Beep(1300, 200);
				system("COLOR 02");
				system("CLS");
				main();
			break;
			default:
				system("COLOR 04");
				Beep(1500, 200);
				cout << "\n\tInvalid Option\t" << endl;
				system("PAUSE");
				goto tryerrorlogin;
			break;
		}
	}catch(exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}
void recoverclient(const char titleclient[40])
{
	try
	{
		char recovermail[cols];

		tryrecoveracc:
		system("CLS");
		cout << titleclient << endl;
		cout << "\n\tEnter your mail of name: ";
		cin >> recovermail;

		for(int i = 0; i < rows; i++)
		{
			if(strcmp(usermail[i], recovermail) == 0)
			{
				system("CLS");
				Beep(1600, 200);
				system("COLOR 01");
				cout << "\n\tYour was recover account with successfully" << endl;
				cout << "\n\tUser: " << username[i] << endl;
				cout << "\n\tNick: " << usernick[i] << endl;
				cout << "\n\tMail: " << usermail[i] << endl;
				cout << "\n\tPassword: " << userpswd[i] << endl;
				system("PAUSE");
				system("CLS");
				system("COLOR 02");
				main();
			}
		}
		tryinvalid:
		system("CLS");
		Beep(1500, 200);
		system("COLOR 04");
		cout << "\n\tError mail not exist or was wrong\n\tTry again: <Y/N>" << endl;
		op = getche();
		system("CLS");
		switch(op)
		{
			case 89:
			case 121:
				Beep(1300, 200);
				system("COLOR 02");
				goto tryrecoveracc;
			break;
			case 78:
			case 110:
				Beep(1300, 200);
				system("COLOR 02");
				system("CLS");
				main();
			break;
			default:
				system("COLOR 04");
				Beep(1500, 200);
				cout << "\n\tInvalid Option\t" << endl;
				system("PAUSE");
				goto tryinvalid;
			break;
		}
	}catch(exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}
bool sessionclient(const char nameuser[cols], const char namepswd[cols])
{
	for(int i = 0; i < rows; i++)
	{
		if(strcmp(username[i], nameuser) == 0 && strcmp(userpswd[i], namepswd) == 0)
		{
			return true;
		}
	}
	return false;
}
void homeclient(const char nameuser[cols], const char namepswd[cols])
{
	try
	{
		if(sessionclient(nameuser, namepswd))
		{
			for(int i = 0; i < rows; i++)
			{
				if(strcmp(username[i], nameuser) == 0 && strcmp(userpswd[i], namepswd) == 0)
				{
					trysessionclient:
					system("CLS");
					system("COLOR 01");
					cout << "\nClient: " << usernick[i] << "|" << "[E] Exit Session | [U] Update Profile | [V] View Profile | [D] Delete Account |"  << endl;
					op = getche();
					switch(op)
					{
						case 68:
						case 100:
							system("CLS");
							system("COLOR 01");
							Beep(1600, 200);
							deleteclient(nameuser, namepswd);
						break;
						case 86:
						case 118:
							system("CLS");
							system("COLOR 01");
							Beep(1600, 200);
							viewclient(nameuser, namepswd);
						break;
						case 85:
						case 117:
							system("CLS");
							system("COLOR 01");
							Beep(1600, 200);
							updateclient(nameuser, namepswd);
						break;
						case 69:
						case 101:
							system("CLS");
							system("COLOR 02");
							Beep(1600, 200);
							main();
							sessionclient(NULL, NULL);
						break;
						case 27:
							tryleaves:
							system("CLS");
							system("COLOR 06");
							Beep(1500, 200);
							cout << "\n\tDo you want to close the program before logging out: <Y/N>" << endl;
							op = getche();
							system("CLS");
							switch(op)
							{
								case 89:
								case 121:
									system("CLS");
									system("COLOR 02");
									Beep(1600, 200);
									exit(0);
								break;
								case 78:
								case 110:
									system("CLS");
									system("COLOR 02");
									Beep(1600, 200);
									exit(0);
									sessionclient(NULL, NULL);
								break;
								default:
									system("COLOR 04");
									Beep(1500, 200);
									cout << "\n\tInvalid Option\t" << endl;
									system("PAUSE");
									goto tryleaves;
								break;
							}
						default:
							system("COLOR 04");
							Beep(1500, 200);
							cout << "\n\tInvalid Option\t" << endl;
							system("PAUSE");
							system("CLS");
							system("COLOR 02");
							goto trysessionclient;
						break;
					}
				}
			}
		}else
		{
			Beep(1500, 200);
			system("COLOR 04");
			cout << "\n\tUnauthorized Error" << endl;
			system("PAUSE");
			system("CLS");
			main();
		}
	}catch(exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}
void updateclient(const char nameuser[cols], const char namepswd[cols])
{
	try
	{
		char updateuser[cols];
		char updatenick[cols];
		char updatemail[cols];
		char updatepswd[cols];
		if(sessionclient(nameuser, namepswd))
		{
			for(int i = 0; i < rows; i++)
			{
				if(strcmp(username[i], nameuser) == 0 && strcmp(userpswd[i], namepswd) == 0)
				{
					cout << "\n\tEnter your new name user: ";
					cin >> updateuser;
					cout << "\n\tEnter your new nick name: ";
					cin >> updatenick;
					cout << "\n\tEnter your new e-mail name: ";
					cin >> updatemail;
					cout << "\n\tEnter your new password name: ";
					cin >> updatepswd;

					for(int j = 0; j < cols; j++)
					{
						username[i][j] = updateuser[j];
						usernick[i][j] = updatenick[j];
						usermail[i][j] = updatemail[j];
						userpswd[i][j] = updatepswd[j];
					}

					system("CLS");
					system("COLOR 02");
					Beep(1400, 200);
					cout << "\n\tYour account was updated with successfully" << endl;
					cout << "\n\tYour new data" << endl;
					cout << "\n\tName: " << username[i] << endl;
					cout << "\n\tNick: " << usernick[i] << endl;
					cout << "\n\tE-mail: " << usermail[i] << endl;
					cout << "\n\tPassword: " << userpswd[i] << endl;
					system("PAUSE");
					system("CLS");
					system("COLOR 01");
					Beep(1600, 200);
					homeclient(updateuser, updatepswd);
				}
			}
		}else
		{
			Beep(1500, 200);
			system("COLOR 04");
			cout << "\n\tUnauthorized Error" << endl;
			system("PAUSE");
			system("CLS");
			main();
		}
	}catch(exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}
void viewclient(const char nameuser[cols], const char namepswd[cols])
{
	try
	{
		if(sessionclient(nameuser, namepswd))
		{
			for(int i = 0; i < rows; i++)
			{
				if(strcmp(username[i], nameuser) == 0 && strcmp(userpswd[i], namepswd) == 0)
				{
					cout << "\n\tYour data" << endl;
					cout << "\n\tName: " << username[i] << endl;
					cout << "\n\tNick: " << usernick[i] << endl;
					cout << "\n\tE-mail: " << usermail[i] << endl;
					cout << "\n\tPassword: " << userpswd[i] << endl;
					system("PAUSE");
					system("CLS");
					homeclient(nameuser, namepswd);
				}
			}
		}else
		{
			Beep(1500, 200);
			system("COLOR 04");
			cout << "\n\tUnauthorized Error" << endl;
			system("PAUSE");
			system("CLS");
			main();
		}
	}catch(exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}
void deleteclient(const char nameuser[cols], const char namepswd[cols])
{
	try
	{
		if(sessionclient(nameuser, namepswd))
		{
			for(int i = 0; i < rows; i++)
			{
				if(strcmp(username[i], nameuser) == 0 && strcmp(userpswd[i], namepswd) == 0)
				{
					trydelete:
					cout << "\n\tWish, delete your account: <Y/N>" << endl;
					op = getche();
					switch(op)
					{
						case 89:
						case 121:
							system("CLS");
							Beep(1600, 200);
							system("COLOR 06");
							for(int d = 0; d < 5; d++)
							{
								system("CLS");
								cout << "\n\tWarning the deleting account, loading" << endl;
								system("CLS");
								cout << "\n\tWarning the deleting account, loading." << endl;
								system("CLS");
								cout << "\n\tWarning the deleting account, loading.." << endl;
								system("CLS");
								cout << "\n\tWarning the deleting account, loading..." << endl;
							}
							id[i] = 0;
							for(int d = 0; d < 10; d++)
							{
								system("CLS");
								cout << "\n\tDeleting user name";
								system("CLS");
								cout << "\n\tDeleting user name.";
								system("CLS");
								cout << "\n\tDeleting user name..";
								system("CLS");
								cout << "\n\tDeleting user name...";
							}
							for(int j = 0; j < cols; j++)
							{
								username[i][j] = ' ';
							}
							for(int d = 0; d < 5; d++)
							{
								system("CLS");
								cout << "\n\tUser name deleted with successfully" << endl;
							}
							for(int d = 0; d < 10; d++)
							{
								system("CLS");
								cout << "\n\tDeleting nick name";
								system("CLS");
								cout << "\n\tDeleting nick name.";
								system("CLS");
								cout << "\n\tDeleting nick name..";
								system("CLS");
								cout << "\n\tDeleting nick name...";
							}
							for(int j = 0; j < cols; j++)
							{
								usernick[i][j] = ' ';
							}
							for(int d = 0; d < 5; d++)
							{
								system("CLS");
								cout << "\n\tNick name deleted with successfully" << endl;
							};
							for(int d = 0; d < 10; d++)
							{
								system("CLS");
								cout << "\n\tDeleting e-mail";
								system("CLS");
								cout << "\n\tDeleting e-mail.";
								system("CLS");
								cout << "\n\tDeleting e-mail..";
								system("CLS");
								cout << "\n\tDeleting e-mail...";
							}
							for(int j = 0; j < cols; j++)
							{
								usermail[i][j] = ' ';
							}
							for(int d = 0; d < 5; d++)
							{
								system("CLS");
								cout << "\n\tE-mail deleted with successfully" << endl;
							};
							for(int d = 0; d < 10; d++)
							{
								system("CLS");
								cout << "\n\tDeleting password";
								system("CLS");
								cout << "\n\tDeleting password.";
								system("CLS");
								cout << "\n\tDeleting password..";
								system("CLS");
								cout << "\n\tDeleting password...";
							}
							for(int j = 0; j < cols; j++)
							{
								userpswd[i][j] = ' ';
							}
							for(int d = 0; d < 5; d++)
							{
								system("CLS");
								cout << "\n\tPassword deleted with successfully" << endl;
							};
							system("CLS");
							system("COLOR 02");
							cout << "\n\tYour account was deleted with successfully" << endl;
							system("PAUSE");
							main();
						break;
						case 78:
						case 110:
							system("CLS");
							Beep(1600, 200);
							system("COLOR 01");
							homeclient(nameuser, namepswd);
						break;
						default:
							system("CLS");
							Beep(1500, 200);
							system("COLOR 04");
							cout << "\n\tError Option Invalid" << endl;
							system("PAUSE");
							system("CLS");
							Beep(1500, 200);
							system("COLOR 01");
							goto trydelete;
						break;
					}
				}
			}
		}else
		{
			Beep(1500, 200);
			system("COLOR 04");
			cout << "\n\tUnauthorized Error" << endl;
			system("PAUSE");
			system("CLS");
			main();
		}
	}catch(exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}