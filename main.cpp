#include <iostream>
#include <list>
#include <map>
#include <string>

int main() {

	//UG图书管理系统（文字版）
	//1.登录账号
	//提示输入账号，密码
	std::cout << "请输入账号：";
	std::string account;
	std::cin >> account;
	std::cout << "请输入密码：";
	std::string password;
	std::cin >> password;
	
	if (account._Equal("admin") && password._Equal("admin")) {
		std::cout << "账号或密码正确" << std::endl;
	}else {
		std::cout << "账号或密码错误" << std::endl;
		return 0;
	}

	//装图书的容器
	std::map<int, std::list<std::string>> myMap;
	myMap.emplace(1, std::list<std::string>{"1", "Java", "Python", "444", "555"});
	myMap.emplace(2, std::list<std::string>{"2", "Java", "Python", "444", "666"});

	//2.图书管理
	std::cout << "========欢迎来到UG的图书管理系统========" << std::endl;
	std::cout << "1.查询图书" << std::endl;
	std::cout << "2.添加图书" << std::endl;
	std::cout << "3.修改图书" << std::endl;
	std::cout << "4.删除图书" << std::endl;
	std::cout << "5.退出UG图书管理系统" << std::endl;
	std::cout << "请选择：";
	int choose;
	std::cin >> choose;

	int bookId;
	std::string bookName;
	std::string bookAuthor;
	double bookPrice;
	int bookCount;

	std::string newBookId;
	std::string newBookName;
	std::string newBookAuthor;
	double newBookPrice;
	int newBookCount;

	while (true) {
		if (choose < 1 || choose > 5) {
			std::cout << "========您的输入有误！！========" << std::endl;
			std::cout << "请重新输入：";
			std::cin >> choose;
		}
		else {
			switch (choose) {
			case 1:
				std::cout << "========查询图书========" << std::endl;
				std::cout << "图书编号\t图书名称\t图书作者\t图书价格\t图书数量" << std::endl;
				for (auto it = myMap.begin(); it != myMap.end(); it++) {
					for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
						std::cout << *it2 << "\t\t";
					}
					std::cout << std::endl;
				}
				break;
			case 2:
				std::cout << "========添加图书========" << std::endl;
				std::cout << "请输入图书编号：";
				std::cin >> bookId;
				std::cout << "请输入图书名称：";
				std::cin >> bookName;
				std::cout << "请输入图书作者：";
				std::cin >> bookAuthor;
				std::cout << "请输入图书价格：";
				std::cin >> bookPrice;
				std::cout << "请输入图书数量：";
				std::cin >> bookCount;
				myMap.emplace(bookId, std::list<std::string>{std::to_string(bookId), bookName, bookAuthor, std::to_string(bookPrice), std::to_string(bookCount)});
				std::cout << "添加成功" << std::endl;
				break;
			case 3:
				std::cout << "========修改图书========" << std::endl;
				std::cout << "请输入要修改的图书编号：";
				std::cin >> bookId;
				std::cout << "请输入新的图书编号：";
				std::cin >> newBookId;
				std::cout << "请输入新的图书名称：";
				std::cin >> newBookName;
				std::cout << "请输入新的图书作者：";
				std::cin >> newBookAuthor;
				std::cout << "请输入新的图书价格：";
				std::cin >> newBookPrice;
				std::cout << "请输入新的图书数量：";
				std::cin >> newBookCount;
				myMap[bookId] = std::list<std::string>{ newBookId, newBookName, newBookAuthor, std::to_string(newBookPrice), std::to_string(newBookCount) };
				std::cout << "修改成功" << std::endl;
				break;
			case 4:
				std::cout << "========删除图书========" << std::endl;
				std::cout << "请输入要删除的图书编号：";
				std::cin >> bookId;
				myMap.erase(bookId);
				std::cout << "删除成功" << std::endl;
				break;
			case 5:
				std::cout << "========退出系统========" << std::endl;
				return 0;
				break;
			}
			std::cout << "1.查询图书" << std::endl;
			std::cout << "2.添加图书" << std::endl;
			std::cout << "3.修改图书" << std::endl;
			std::cout << "4.删除图书" << std::endl;
			std::cout << "5.退出UG图书管理系统" << std::endl;
			std::cout << "请选择：";
			std::cin >> choose;
		}
	}

	return 0;
}
