#include "chat.h"

using namespace std;

int main()
{
	SetConsoleCP(1251); // ����������� ������ � ������� ����� cin ��������
	SetConsoleOutputCP(1251);

	Chat chat;
	string userName, login, password, message;
	
	cout << "����� ���������� � ���.\n��������,��� �� ������ �������:" << endl;
	cout << "1.[������� �������] 2.[����� � �������] 3.[���������� ���� �������������] 4.[����� �� ����]" << endl;

	char open;
	cin >> open;
	clearCin();

	cout << endl;

	while (open != '4')
	{
		switch (open)
		{
		case '1':
		{
			cout << "������� ���: ";
			getline(cin, userName);
			while ((userName.empty()) || (userName[0] == ' ') || (userName[userName.size()-1] == ' '))
			{
				cout << "������ � ������ �� ������ ���� ������ � ��� �� ������ ��������� ��� ������������� ��������.\n����������, ������� ��� ��� ���: ";
				getline(cin, userName);
			}

			cout << "������� �����: ";
			getline(cin, login);
			while ((login.empty()) || (login[0] == ' ') || (login[login.size()-1] == ' '))
			{
				cout << "������ � ������� �� ������ ���� ������ � ����� �� ������ ��������� ��� ������������� ��������.\n����������, ������� ����� ��� ���: ";
				getline(cin, login);
			}
			while (chat.checkLoginExist(login) == true)
			{
				cout << "����� ����� ��� ����������. ����������, ���������� ������ �����: ";
				getline(cin, login);
				while (login.empty() || (login[0] == ' ') || (login[login.size() - 1] == ' '))
				{
					cout << "������ � ������� �� ������ ���� ������, ���������� � ������������� ��������.\n����������, ������� �����: ";
					getline(cin, login);
				}
			}
			cout << "������� ������: ";
			getline(cin, password);
			while (password.empty() || (password[0] == ' ') || (password[password.size() - 1] == ' '))
			{
				cout << "������ � ������� �� ������ ���� ������, ���������� � ������������� ��������.\n����������, ������� ������: ";
				getline(cin, password);
			}
			cout << endl;

			chat.registration(userName, login, password);
			
			cout << "������� ������� ������\n" << endl;

			break;
		}
		case '2':
		{
			cout << "������� �����: " ;
			getline(cin, login);
			cout << "������� ������: ";
			getline(cin, password);
			cout << endl;
			if (chat.checkUser(login, password) == true)
			{
				string nameOfCurrentUser = chat.GetNameByLogin(login);
				
				char choiceInsideCase2;
				cout << "�������� ��������:" << endl << "1.[�������� ���������] 2.[�������� ���������] 3.[������� ������] 4.[����� �� ��������]" << endl;
				cin >> choiceInsideCase2;
				clearCin();
				cout << endl;

				while (choiceInsideCase2 != '4')
				{
					switch (choiceInsideCase2)
					{
					case '1':
					{
						cout << "���� �� ������ �������� ���������:\n1.[������������� ������������] 2.[��������� ���������] 3.[�������� �����]" << endl;
						char choiceInsideCase2InsideCase1;
						cin >> choiceInsideCase2InsideCase1;
						cout << endl;
						clearCin();

						while (choiceInsideCase2InsideCase1 != '3')
						{
							switch (choiceInsideCase2InsideCase1)
							{
							case '1': // ��������� ������������
							{
								cout << "������������:" << endl;
								chat.printAllUsersExceptCurrentUser(chat.GetLoginByUserName(nameOfCurrentUser));

								cout << endl;
 
								cout << "������� ����� ������������ ���� ������ �������� ���������: ";
								getline(cin, login);
								if (chat.checkLoginExist(login) == true)
								{
									cout << "������� ���������: ";
									getline(cin, message);
									while (message.empty())
									{
										cout << "��������� �� ����������(���������� �����). ������� ���������: ";
										getline(cin, message);
									}
									message = "� ��� ��������� �� ������������ " + nameOfCurrentUser + " " + "(" + login + ")" + ": " + '\"' + message + '\"';
									chat.sendMessage(login, message);
									cout << "��������� ������� ����������!" << endl;
								}

								break;
							}
							case '2': // ��������� ���������
							{
								cout << "������� ���������: ";
								getline(cin, message);
								while (message.empty())
								{
									cout << "��������� �� ����������(���������� �����). ������� ���������: ";
									getline(cin, message);
								}
								message = "� ��� ��������� ��������� �� ������������ " + nameOfCurrentUser + " " + "(" + chat.GetLoginByUserName(nameOfCurrentUser) + ")" + ": " + '\"' + message + '\"';
								chat.sendMessageToAllUsersExceptCurrentUser(chat.GetLoginByUserName(nameOfCurrentUser), message);
								cout << "��������� ������� ����������!" << endl;

								break;
							}
							default:
							{
								cout << "�������� ��������\n" << endl;

								break;
							}
							}
							cout << endl;
							cout << "���� �� ������ �������� ���������:\n1.[������������� ������������] 2.[��������� ���������] 3.[�������� �����]" << endl;
							cin >> choiceInsideCase2InsideCase1;
							cout << endl;
							clearCin();
						};

						break;
					}
					case '2':
					{
						chat.print(login);
						system("pause>0"); // ������ ��������� �� �����, ����� ������������ �������� ���������

						break;
					}
					case '3': //����� ������ �� �����
					{
						string newpassword;
						cout << "������� ������ ������: ";
						getline(cin, password);
						while (chat.checkPassByName(nameOfCurrentUser, password) == false)
						{
							cout << "������ ��������\n������� ������ ������: ";
							getline(cin, password);
						}
						cout << "������� ����� ������: ";
						getline(cin, newpassword);
						while (newpassword.empty() || (newpassword[0] == ' ') || (newpassword[newpassword.size() - 1] == ' '))
						{
							cout << "������ � ������� �� ������ ���� ������, ���������� � ������������� ��������.\n����������, ������� ������: ";
							getline(cin, newpassword);
						}
						while (newpassword == password)
						{
							cout << "��� ��� ������ ������! ���������� ������ ������: ";
							getline(cin, newpassword);
							while (newpassword.empty() || (newpassword[0] == ' ') || (newpassword[newpassword.size() - 1] == ' '))
							{
								cout << "������ � ������� �� ������ ���� ������, ���������� � ������������� ��������.\n����������, ������� ������: ";
								getline(cin, newpassword);
							}
						}
						chat.SetNewPassByName(nameOfCurrentUser, newpassword);
						cout << "������ ������� �������!\n" << endl;

						break;
					}
					default:
					{
						cout << "�������� ��������\n" << endl;

						break;
					}
					}

					cout << "�������� ��������:\n1.[�������� ���������] 2.[�������� ���������] 3.[������� ������] 4.[����� �� ��������]" << endl;
					cin >> choiceInsideCase2;
					clearCin();

					cout << endl;
				};

				cout << endl;

				break;
			}
			else
			{
				cout << "�������� ����� ��� ������\n" << endl;
				break;
			}
			break;
		}
		case '3':
		{
			chat.showAllUsers();
			cout << endl;

			break;
		}
		default:
		{
			cout << "�������� ��������\n" << endl;

			break;
		};
		}
		cout << "1.[������� �������] 2.[����� � �������] 3.[���������� ���� �������������] 4.[����� �� ����]" << endl;

		cin >> open;
		clearCin();
		cout << endl;
	}

	return 0;
}