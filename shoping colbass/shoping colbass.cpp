#include<iostream>
#include<Windows.h>
#include<string>
#include<limits>
#include <iomanip>

#if defined(max)
#undef max
#endif


//Учетные записи
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "Admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "Admin", "user" };
//******************************************

// База данных товаров
int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];
//*****************************************

// Касса
double cash = 10000;
double eMoney = 0;
double cashMoney = 0;
/*******************************************/


//Функция
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void RefillStorage();
bool isStringDigit(std::string string);
void RemoveFromStorage();
void CheakPrice();

void ChangeStaff();
void AddEmloyer();
void StaffRedact();
void RemoveEmployee();

void StorageRedacters();
void StorageReduct();

void AddProduct();
void RenameProduct();
void DeleteProduct();
void Selling();
void AddCheckItem();
void PrintCheck(double totalSum);
void Income();


template <typename ArrType>
void FillStorage(ArrType staticArr[], ArrType dynaminArr[], int size);

template<typename ArrType1>
void PrintStorage(ArrType1 dynaminArr[]);
void ShowStorage();

//Чек
int sizeCheck = 1;
int* countCheckArr = new int[sizeCheck];
double* priceCheckArr = new double[sizeCheck];
double* totalPriceCheckArr = new double[sizeCheck];
std::string* nameCheakArr = new std::string[sizeCheck];




/****************************************/

int main()
{
	Start();





	delete[] loginArr;
	delete[] passwordArr;
	delete[] idArr;
	delete[] nameArr;
	delete[] countArr;
	delete[] priceArr;
	delete[] countCheckArr;
	delete[]priceCheckArr;
	delete[] totalPriceCheckArr;

	return 0;
}
void ShopUserMenu();

//Названия
void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\tКолбасная лавочка\t\n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		{
			std::string choose;
			do
			{
				std::cout << "1- Использовать готовый склад\n2 - или создать свой?\n";
				std::cout << "Ввод: ";
				std::getline(std::cin, choose, '\n');

			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				//Dinamic cklad
			}

			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}


}

//Логинирования, вход
bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, pass, '\n');

		if (login == loginArr[0] && pass == passwordArr[0])
		{
			std::cout << "Добро пожаловать " << loginArr[0] << '\n';
			isAdmin = true;
			return true;
		}

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << " Добро пожаловать " << loginArr[i] << '\n';
				isAdmin = false;
				return  true;
			}
		}
		system("cls");
		std::cout << "Неверно введен логин или пароль!\n\n";

	}
}

void ShopUserMenu()
{
	std::string choose;
	while (true)
	{
		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать скдаж\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Отчет от прибыли\n\n";
			std::cout << "0. Закрыть смену\n\n\n";

			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			system("cls");

		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 53);


		if (choose == "1")
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillStorage();
		}
		else if (choose == "4")
		{
			RemoveFromStorage();
		}
		else if (choose == "5")
		{
			Income();
		}
		else if (choose == "0")
		{
			system("cls");
			while (true)
			{
				std::cout << "1 - Закрыть смену\n2 - Отмена\n\nВвод: ";
				std::getline(std::cin, choose, '\n');
				if (isStringDigit(choose))
				{
					break;
				}
				else
				{
					std::cout << "\n\nНекорректный ввод\n\n";
				}
			}
			if (std::stoi(choose) == 1)
			{
				Income();
				std::cout << "\n\t\t\tСмена закрыта. Успехов\n\n";
				break;
			}
		}
		else
		{

		}


	}
}

// изменения акций
void ShopAdminMenu()
{
	//изменения акций
	std::string choose;
	while (true)
	{
		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать скдад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Изменить цену\n";
			std::cout << "6. Изменить склад\n";
			std::cout << "7. Изменить персонал\n";
			std::cout << "8. Отчет от прибыли\n\n";
			std::cout << "0. Закрыть смену\n\n\n";

			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			system("cls");

		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);


		if (choose == "1")
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillStorage();
		}
		else if (choose == "4")
		{
			RemoveFromStorage();
		}
		else if (choose == "5")
		{
			CheakPrice();
		}
		else if (choose == "6")
		{
			StorageReduct();
		}
		else if (choose == "7")
		{
			ChangeStaff();
		}
		else if (choose == "8")
		{
			Income();
		}
		else if (choose == "0")
		{
			system("cls");
			while (true)
			{
				std::cout << "1 - Закрыть смену\n2 - Отмена\n\nВвод: ";
				std::getline(std::cin, choose, '\n');
				if (isStringDigit(choose))
				{
					break;
				}
				else
				{
					std::cout << "\n\nНекорректный ввод\n\n";
				}
			}
			if (std::stoi(choose) == 1)
			{
				Income();
				std::cout << "\n\t\t\tСмена закрыта. Успехов\n\n";
				break;
			}
		}

		else
		{
			std::cerr << "Admin MenuErr";
		}

	}
}
void CreateStaticStorage()
{
	const int staticSize = 10;

	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };

	std::string nameStaticArr[staticSize]
	{
		"Сырокопченая колбаса", "Варено-копченые", "Полукопченые", "Доктораская",
			"Сыровяленые колбасы", "Ливерные колбасы", "Немецкие колбаски", "Русские сосиски",
			"Говяжьи сосиски", "Cардельки"
	};

	int countStaticArr[staticSize]{ 1, 3, 5, 7, 9, 11,13, 6, 11, 12 };
	double priceStaticArr[staticSize]{ 1804.99, 719.99, 479.0, 480.0, 500.0, 417.0, 1500.0, 150.0, 180.0,  407.0 };

	FillStorage(idStaticArr, idArr, staticSize);
	FillStorage(nameStaticArr, nameArr, staticSize);
	FillStorage(countStaticArr, countArr, staticSize);
	FillStorage(priceStaticArr, priceArr, staticSize);

}

void RefillStorage()
{
	std::string idStr, addStr, choose;
	int id{}, add;
	bool exit = false;
	while (!exit)
	{
		while (true)
		{
			std::cout << "Пополнения склада\nВведите id товара : ";
			std::getline(std::cin, idStr, '\n');
			if (std::isdigit(idStr[0]) && idStr.size() == 1)
			{
				id = std::stoi(idStr);
			}
			else if (std::isdigit(idStr[0]) &&
				std::isdigit(idStr[1]) && idStr.size() == 2)
			{
				id = std::stoi(idStr);
			}
			else
			{
				std::cout << "Ошибка ввода\n";
			}

			if (id > 0 && id <= size)
			{

				system("cls");
				break;
			}
			else
			{
				std::cout << "Неверный ID\n";
			}
		}


		std::cout << "\n\n" << idArr[id - 1] << " " << nameArr[id - 1] << "\n\n";

		while (true)
		{
			std::cout << "Введите кол-во товаров на пополнения: ";
			std::getline(std::cin, addStr, '\n');

			if (isStringDigit(addStr))
			{
				add = std::stoi(addStr);

				if (add >= 0 && add < 500)
				{
					break;
				}

				else
				{
					std::cout << "Некорекктное кол-во\n\n";
				}

			}
		}

		while (true)
		{
			std::cout << "Добавить " << add << " товара(ов) " << nameArr[id - 1] << "?";
			std::cout << "1 - Да\t2 - Нет\t3 - Отмена\n\n";
			std::getline(std::cin, choose, '\n');
			if (choose == "1")
			{
				countArr[id - 1] += add;
				std::cout << "Товар успешно пополнен\n\n";
				exit = true;
				break;
			}
			else if (choose == "2")
			{
				break;
			}
			else if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cout << "Ошибка ввода\n\n";
			}
		}




	}



}

bool isStringDigit(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
		return true;
	}
}

void ShowStorage()
{
	std::cout << "ID\tНазвание\t\tКол-во\tЦена\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t"
			<< countArr[i] << "\t" << priceArr[i] << "\n";
	}
}

template<typename ArrType>
void FillStorage(ArrType staticArr[], ArrType dynamincArr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		dynamincArr[i] = staticArr[i];
	}
}

template<typename ArrType1>
void PrintStorage(ArrType1 dynamicArr[])
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}

void RemoveFromStorage()
{
	std::string idStr, removeStr, choose;
	int id{}, remove{};
	bool exit = false;
	while (!exit)
	{
		while (true)
		{
			std::cout << "Пополнения склада\nВведите id товара : ";
			std::getline(std::cin, idStr, '\n');
			if (std::isdigit(idStr[0]) && idStr.size() == 1)
			{
				id = std::stoi(idStr);
			}
			else if (std::isdigit(idStr[0]) &&
				std::isdigit(idStr[1]) && idStr.size() == 2)
			{
				id = std::stoi(idStr);
			}
			else
			{
				std::cout << "Ошибка ввода\n";
			}

			if (id > 0 && id <= size)
			{

				system("cls");
				break;
			}
			else
			{
				std::cout << "Неверный ID\n";
			}
		}


		std::cout << "\n\n" << idArr[id - 1] << " " << nameArr[id - 1] << "\n\n";

		while (true)
		{
			std::cout << "Введите кол-во товаров на пополнения: ";
			std::getline(std::cin, removeStr, '\n');

			if (isStringDigit(removeStr))
			{
				removeStr = std::stoi(removeStr);

				if (remove >= 0 && remove < 500)
				{
					break;
				}

				else
				{
					std::cout << "Некорекктное кол-во\n\n";
				}

			}
		}

		while (true)
		{
			std::cout << "Пополнить " << remove << " товара(ов) " << nameArr[id - 1] << "?";
			std::cout << "1 - Да\t2 - Нет\t3 - Отмена\n\n";
			std::getline(std::cin, choose, '\n');
			if (choose == "1")
			{
				countArr[id - 1] -= remove;
				std::cout << "Товар успешно списан\n\n";
				exit = true;
				break;
			}
			else if (choose == "2")
			{
				break;
			}
			else if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cout << "Ошибка ввода\n\n";
			}
		}

	}
}



void CheakPrice()
{
	std::string idStr, newPriceStr, choose;
	int id{}, price{};
	double newPrice{};
	bool exit = false;

	while (!exit)
	{
		while (true)
		{
			std::cout << "Изменить цену\nВведите id товара : ";
			std::getline(std::cin, idStr, '\n');

			if (std::isdigit(idStr[0]) && idStr.size() == 1)
			{
				id = std::stoi(idStr);
			}
			else if (std::isdigit(idStr[0]) &&
				std::isdigit(idStr[1]) && idStr.size() == 2)
			{
				id = std::stoi(idStr);
			}
			else
			{
				std::cout << "Ошибка ввода\n";
			}

			if (id > 0 && id <= size)
			{

				system("cls");
				break;
			}
			else
			{
				std::cout << "Неверный ID\n";
			}
		}


		std::cout << "\n\n" << idArr[id - 1] << " " << nameArr[id - 1] << "\t Текущая цена" << priceArr[id - 1] << "\n\n";

		while (true)
		{
			std::cout << "Введите новую цену: ";
			std::getline(std::cin, newPriceStr, '\n');

			if (isStringDigit(newPriceStr))
			{
				price = std::stod(newPriceStr);

				if (newPrice >= 0 && newPrice <= 10000)
				{
					break;
				}

				else
				{
					std::cout << "Некорекктное кол-во\n\n";
				}

			}
			else
			{
				std::cout << "Ошибка ввода\n\n";
			}
		}

		while (true)
		{
			std::cout << "Назначит " << nameArr[id - 1] << " новую цену " << newPrice;
			std::cout << "\n1 - Да\t2 - Нет\t3 - Отмена\n\n";
			std::getline(std::cin, choose, '\n');
			if (choose == "1")
			{
				countArr[id - 1] = newPrice;
				std::cout << "\nЦена товара успешно изменена\n";
				exit = true;
				break;
			}
			else if (choose == "2")
			{
				break;
			}
			else if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cout << "Ошибка ввода\n\n";
			}
		}

	}
}

void ChangeStaff()
{
	std::string choose;

	while (true)
	{
		std::cout << "\n\n1. Добавить нового сотрудника\n2. Отредактировать сотрудника\n3. Удалить сотрудника\n0. Выход\n\nВвод:";
		std::getline(std::cin, choose, '\n');

		if (choose == "1")
		{
			AddEmloyer();
		}
		if (choose == "2")
		{
			StaffRedact();
		}
		if (choose == "3")
		{
			RemoveEmployee();
		}
		if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nuser Добавлен\n";
		}
	}

	for (int i = 0; i < userCount; i++)
	{
		std::cout << loginArr[i] << " " << passwordArr[i] << "\n";
	}

}

void AddEmloyer()
{
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}
	delete[]loginArr;
	delete[]passwordArr;

	userCount++;

	loginArr = new std::string[userCount];
	passwordArr = new std::string[userCount];

	for (int i = 0; i < userCount - 1; i++)
	{
		loginArr[i] = tempLogin[i];
		passwordArr[i] = tempPass[i];
	}


	std::string newLogin, newPass;
	std::cout << "Введите логин нового сотрудника: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "Введите пароль нового сотрудника: ";
	std::getline(std::cin, newPass, '\n');


	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;

	delete[]tempLogin;
	delete[]tempPass;
}

void StaffRedact()
{
	std::string chooseID, newlogin, newPass;
	int empId;
	while (true)
	{
		std::cout << "ID\tЛогин\tПароль\n";
		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << "\n";
		}
		std::cout << "Введите ID сотрудника\t 0 - выход\nввод: ";
		std::getline(std::cin, chooseID, '\n');

		if (chooseID == "0")
		{
			break;
		}
		else if (isStringDigit(chooseID) && chooseID != "1")
		{
			empId = std::stoi(chooseID);
			for (int i = 0; i < userCount; i++)
			{
				if (i == empId - 1)
				{
					std::cout << "Введите новый логин сотрудника: ";
					std::getline(std::cin, newlogin, '\n');
					std::cout << "Введите новый пароль сотрудника: ";
					std::getline(std::cin, newPass, '\n');

					loginArr[i] = newlogin;
					passwordArr[i] = newPass;
					break;
				}
			}

		}
		else
		{
			std::cout << "\n\nОшибка ввода!\n\n";
		}
	}

}

void RemoveEmployee()
{
	std::string chooseId;
	int empId{};
	while (true)
	{
		std::cout << "Введите ID сотрудника для удаления: ";
		std::getline(std::cin, chooseId, '\n');
		if (chooseId == "0")
		{
			break;
		}
		else if (isStringDigit(chooseId))
		{
			empId = std::stoi(chooseId);

			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];
			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passwordArr[i];
			}

			delete[]loginArr;
			delete[]passwordArr;
			userCount--;
			loginArr = new std::string[userCount];
			passwordArr = new std::string[userCount];

			for (int i = 0, j = 0; i < userCount, j < userCount; i++, j++)
			{
				if (i == empId - 1)
				{
					i++;
					loginArr[i] = tempLogin[i];
					passwordArr[i] = tempPass[i];
				}
				else
				{
					loginArr[j] = tempLogin[i];
					passwordArr[j] = tempPass[i];
				}
			}

			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}

	}


}

void StorageRedacters()
{
	std::string choose;
	std::cout << "Изменения склада магазина\n\n";

	while (true)
	{
		std::cout << "1 - Добавить новый товар\n2 - Изменить названия товара\n3 - Удаления товара\n0 - Выход\n\nВвод: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			AddProduct();
			break;
		}
		else if (choose == "2")
		{
			RenameProduct();
			break;
		}
		else if (choose == "3")
		{
			DeleteProduct();
			break;
		}
		else
		{

			std::cout << "\n\nНекорректный ввод\n\n";
		}
	}



}

void AddProduct()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Добаивть новый товар\t0 - Выход\n\nВвод: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];
			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[] idArr;
			delete[] countArr;
			delete[] priceArr;
			delete[] nameArr;

			size++;

			int* countCheckArr = new int[sizeCheck];
			double* priceCheckArr = new double[sizeCheck];
			double* totalpriceCheckArr = new double[sizeCheck];
			std::string* nameCheckArr = new std::string[sizeCheck];

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			for (int i = 0; i < size - 1; i++)
			{
				idArr[i] = tempId[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}

			std::string newName, newCountStr, newPriceStr;

			while (true)
			{
				std::cout << "Введите названия нового товара: ";
				std::getline(std::cin, newName, '\n');
				if (newName.size() <= 30)
				{
					nameArr[size - 1] = newName;
					break;
				}
				else
				{
					std::cout << "\n\nСлишком длинное названия\n\n";
				}
			}

			while (true)
			{
				std::cout << "Введите кол-во нового товара: ";
				std::getline(std::cin, newCountStr, '\n');
				if (isStringDigit(newCountStr))
				{
					if (std::stoi(newCountStr) >= 0 && std::stoi(newCountStr) < 1000)
					{
						countArr[size - 1] = std::stoi(newCountStr);
						break;
					}
				}
				else
				{
					std::cout << "\n\nНекоректоный ввод\n\n";
				}

				while (true)
				{
					std::cout << "Введите цену нового товара: ";
					std::getline(std::cin, newPriceStr, '\n');
					if (isStringDigit(newPriceStr))
					{
						if (std::stod(newPriceStr) >= 0 && std::stod(newPriceStr) < 1000)
						{
							priceArr[size - 1] = std::stod(newPriceStr);
							break;
						}
					}
					else
					{
						std::cout << "\n\nНекорректный ввод\n\n";
					}
				}
				idArr[size - 1] = size;

				std::cout << "\n\tНазвания\tкол-во\tцена";
				std::cout << "\n\n" << idArr[size - 1] << "\t" << std::left << std::setw(10)
					<< nameArr[size - 1] << "\t" << countArr[size - 1] << "\t"
					<< priceArr[size - 1] << "\n\nНовый товар успешно пополнен на склад\n\n";
			}
			delete[] tempId;
			delete[] tempCount;
			delete[] tempPrice;
			delete[] tempName;
		}
		else
		{
			std::cout << "\n\nНекорретный ввод\n\n";
		}
	}
}

void StorageReduct()
{
	std::string choose;
	std::cout << "Изменение склада магазина\n\n";

	while (true)
	{
		std::cout << "1. Добавить новый товар\t2. Изменить название товара\t3. Удаление товара\n 0 - Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			AddProduct();
		}
		else if (choose == "2")
		{
			RenameProduct();
		}
		else if (choose == "3")
		{
			DeleteProduct();
		}
		else
		{
			std::cout << "Некорретный ввод\n\n";
		}
	}
}




void RenameProduct()
{
	std::string choose;
	std::string idStr, newName;
	int id{};
	while (true)
	{
		std::cout << "1 - Изменить название\t0 - Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');

		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			while (true)
			{
				std::cout << "Введите ID: ";
				std::getline(std::cin, idStr, '\n');

				if (isStringDigit(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "Некорректный ID!!\n\n";
					}
				}
			}
			while (true)
			{
				std::cout << "\n\n" << idArr[id - 1] << "\t" << std::left << std::setw(30) << nameArr[id - 1] << "\n\n";
				std::cout << "Введите новое название товара: ";
				std::getline(std::cin, newName, '\n');
				if (newName.size() <= 30)
				{
					nameArr[id - 1] = newName;
					break;
				}
				else
				{
					std::cout << "Максимальная длина названия 30 исмволов\n\n";
				}
			}

			std::cout << "\n\n" << idArr[id - 1] << "\t" << std::left << std::setw(30) << nameArr[id - 1] << "\t" <<
				countArr[id - 1] << "\t" << priceArr[id - 1] << "\n" << "Название товара изменено\n\n";

		}
		else
		{
			std::cout << "Некорректный ввод!!\n\n";
		}
	}


}

void DeleteProduct()
{
	std::string choose;
	while (true)
	{
		std::cout << "1. Удалить товар\t0 - Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			std::string idStr, newName;
			int id{};

			while (true)
			{
				std::cout << "Введите ID товара: ";
				std::getline(std::cin, idStr, '\n');

				if (isStringDigit(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "Некорректный ID!!\n\n";
					}
				}
				else
				{
					std::cout << "\nНекорректный ввод\n\n";
				}
			}



			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];
			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}


			delete[]idArr;
			delete[]countArr;
			delete[]priceArr;
			delete[]nameArr;

			size--;
			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];


			for (int i = 0, j = 0; i < size, j < size; i++, j++)
			{
				if (i == id - 1)
				{
					i++;
					idArr[j] = tempId[j];
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
				}
				else
				{
					idArr[j] = tempId[j];
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
				}
			}


			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;

			break;
		}
	}
}

void Selling()
{
	std::string chooseId, chooseCount, choosePayPal, userCash;
	int id{}, count{};
	bool isFirst = true;
	int sizeCheck = 1;
	double totalSum = 0;
	sizeCheck = 1;


	delete[]priceCheckArr;
	delete[]countCheckArr;
	delete[]totalPriceCheckArr;
	delete[]nameCheakArr;

	priceCheckArr = new double[sizeCheck];
	countCheckArr = new int[sizeCheck];
	totalPriceCheckArr = new double[sizeCheck];
	nameCheakArr = new std::string[sizeCheck];

	while (true)
	{
		system("cls");
		ShowStorage();
		std::cout << "Введите ID товара для покупки\n0 для выхода: ";
		std::getline(std::cin, chooseId, '\n');
		if (!isStringDigit(chooseId))
		{
			std::cout << "\nНеверный ID\n";
			continue;
		}
		else if (isStringDigit(chooseId))
		{
			id = std::stoi(chooseId);
			if (id == 0)
			{
				if (!isFirst)
				{
					PrintCheck(totalSum);
					while (true)
					{

						std::cout << "Выберите способ оплаты:\n1 - Наличные\n2 - Картой\nВвод: ";
						std::getline(std::cin, choosePayPal, '\n');
						if (!isStringDigit(choosePayPal))
						{
							std::cout << "Некорректный ввод\n\n";
						}
						else
						{
							if (std::stoi(choosePayPal) == 1)
							{
								while (true)
								{
									std::cout << "Введите сумму наличных: ";
									std::getline(std::cin, userCash, '\n');
									if (!isStringDigit(userCash))

									{
										std::cout << "Некорректный ввод\n\n";


									}
									else
									{
										if (std::stod(userCash) < totalSum)
										{
											std::cout << "Недостаточно средств\n\n";
										}
										else if (cash >= std::stod(userCash) - totalSum)
										{
											std::cout << "\n\nВаши: " << std::stod(userCash)
												<< "\n\nОплата прошла успешно\n" << "Сдача: "
												<< std::stod(userCash) - totalSum << " руб\n\n";
											cashMoney = totalSum;
											cash += std::stod(userCash);
											cash -= std::stod(userCash) - totalSum;
											break;

										}
									}
								}

							}
							else if (std::stoi(choosePayPal) == 2)
							{
								std::cout << "Оплата прошла успешно\n";
								eMoney += totalSum;
								break;
							}
							else
							{
								std::cout << "Некорректный ввод!!\n\n";
							}
						}
					}
					break;
				}
				else
				{
					break;
				}
			}
			else if (id > 0 && id <= size)
			{
				while (true)
				{
					std::cout << "Введите количество товара " << nameArr[id - 1] << ": ";
					std::getline(std::cin, chooseCount, '\n');
					if (!isStringDigit(chooseCount))
					{
						std::cout << "\n\nНекорректный ввод\n\n";
						continue;
					}
					else if (isStringDigit(chooseCount))
					{
						count = std::stoi(chooseCount);
						if (count > 0 && count <= countArr[id - 1])
						{
							std::cout << std::left << std::setw(30) << nameArr[id - 1] << " " << count << " добавлен в чек\n\n";
							if (isFirst)
							{
								priceCheckArr[sizeCheck - 1] = priceArr[id - 1];
								nameCheakArr[sizeCheck - 1] = nameArr[id - 1];
								totalPriceCheckArr[sizeCheck - 1] = priceArr[id - 1] * count;
								countCheckArr[sizeCheck - 1] = count;
								totalSum += totalPriceCheckArr[sizeCheck - 1];
								isFirst = false;
								countArr[id - 1] -= count;
							}
							else
							{
								AddCheckItem();
								priceCheckArr[sizeCheck - 1] = priceArr[id - 1];
								nameCheakArr[sizeCheck - 1] = nameArr[id - 1];
								totalPriceCheckArr[sizeCheck - 1] = priceArr[id - 1] * count;
								countCheckArr[sizeCheck - 1] = count;
								totalSum += totalPriceCheckArr[sizeCheck - 1];
								countArr[id - 1] -= count;
							}
							break;
						}
						else
						{
							std::cout << "\n\nНекорректное кол-во\n\n";
							break;
						}
					}
					else
					{
						std::cout << "\n\nНекорректный ввод\n\n";
						break;
					}
				}
			}
			else
			{
				std::cout << "\n\nНекорректный ввод\n\n";
				break;
			}
		}
	}
}

void AddCheckItem
()
{

	double* tempPriceCheck = new double[sizeCheck];
	int* tempCountCheck = new int[sizeCheck];
	double* tempTotalPriceCheck = new double[sizeCheck];
	std::string* tempNameCheck = new std::string[sizeCheck];
	for (int i = 0; i < sizeCheck; i++)
	{
		tempPriceCheck[i] = priceCheckArr[i];
		tempCountCheck[i] = countCheckArr[i];
		tempTotalPriceCheck[i] = totalPriceCheckArr[i];
		tempNameCheck[i] = nameCheakArr[i];
	}


	delete[]priceCheckArr;
	delete[]countCheckArr;
	delete[]totalPriceCheckArr;
	delete[]nameCheakArr;

	sizeCheck++;
	countCheckArr = new int[sizeCheck];
	priceCheckArr = new double[sizeCheck];
	totalPriceCheckArr = new double[sizeCheck];
	nameCheakArr = new std::string[sizeCheck];


	for (int i = 0; i < sizeCheck - 1; i++)
	{
		priceCheckArr[i] = tempPriceCheck[i];
		countCheckArr[i] = tempCountCheck[i];
		totalPriceCheckArr[i] = tempTotalPriceCheck[i];
		nameCheakArr[i] = tempNameCheck[i];
	}

	delete[]tempPriceCheck;
	delete[]tempCountCheck;
	delete[]tempTotalPriceCheck;
	delete[]tempNameCheck;

}

void PrintCheck(double totalSum)
{
	int sizeCheck = 1;
	std::cout << "№\tНазвание\t\t\tКоличество\tЦена за ед\tИтого\n";
	for (int i = 0; i < sizeCheck; i++)
	{
		std::cout << i + 1 << "\t" << std::left << std::setw(30) << nameCheakArr[i] << "\t\t" << countCheckArr[i] << "\t" << priceCheckArr[i] << "\t\t" << totalPriceCheckArr[i] << "\n\n";
	}
	std::cout << "\n\n\tИтоговая сумма: " << totalSum << " рублей\n\n\n";
}

void Income()
{
	std::cout << "\t\tОтчет о прибыли\n\n";
	std::cout << "Прибыль за наличный рассчет:\t\t" << cashMoney << "\n";
	std::cout << "Прибыль за безналичный расчет: \t\t" << eMoney << "\n";
	std::cout << "Наличные в кассе:\t\t\t" << cash << "\n\n";
	std::cout << "Итоговая выручка:\t\t\t" << cashMoney + eMoney << "\n";
}


