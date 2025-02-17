#include <iostream>			//包含cout和cin
#include <windows.h>		//包含Sleep()
#include <conio.h>			//包含_getch()
using namespace std;

char ab;					//输入缓存，用来实现按任意键继续
char ys = 'N';				//是否包含重复号码
char n;						//是否开始抽奖
char conti;					//在快速生成结束后是否继续按上一次的数量重新生成

int a = 1;					//中奖序号
int delays = 0;				//延迟时间
int maxx, minx;				//单值模式的上限值和下限值
int Rapid_mode_Max = 100;	//快速生成模式的最大值
int Rapid_mode_Min = 1;		//快速生成模式的最小值

bool memory[1000];			//内存数组，用来存储已经生成的随机数

string inr;					//设置中输入的命令前缀
string username = "admin";	//用户名

void clearScreen() {		//清屏函数

	#ifdef _WIN32			//Windows
		system("cls");		//调用系统命令行清屏

	#else					//Linux
		system("clear");	//调用系统命令行清屏

	#endif					//结束条件编译

}

int main() {

	//进程序第一次时的跳转流

	char b;
	goto Replay;	//前往功能选择界面

Settings://设置界面

	clearScreen();

	//设置界面顶部的提示词

	cout << "设置 Settings ： \n\n【这里是设置界面，您可以对一些参数进行一定的修改，但不包"
		"含硬编码和程序库内容】\n\n命令前缀\t\t\t简介\n-----------------------------------"
		"---------------------------------------------\n"
		"rewrite::setTimerLength()\t更改输出随机生成结果的延迟(Delay)，1000 = 1s\nrewrite::userName()"
		"\t\t更改用户名(Name), 可能只支持ASCII字符集内的字符\n";
	cout << "\n请指定命令(输入 “e” 退出)：\n";
	cout << "\n::settings@" << username << ">";

	//输入命令前缀

	cin >> inr;
	if (inr == "rewrite::setTimerLength()") {
		//修改延迟时间
		cout << "\n\n请指定形参数据 Delay: \n\n";
		cout << "\n::settings@" << username << ">";
		cin >> delays;
		cout << "\n\nPatching Successfully!\n\n";
		Sleep(1000);
		goto Settings;
	}
	else if (inr == "rewrite::userName()") {
		//修改用户名
		cout << "\n\n请指定形参数据 Name: \n\n";
		cout << "\n::settings@" << username << ">";
		cin >> username;
		cout << "\n\nPatching Successfully!\n\n";
		Sleep(1000);
		goto Settings;
	}
	else if (inr == "e" or inr == "E") {
		//返回主界面
		goto Replay;
	}
	else {
		//未找到相关实例
		cout << "\n\n未找到相关实例！\n\n";
		goto Settings;
	}

Code://算法显示界面

	clearScreen();
	cout << ""
		"这里是本程序的内部算法：\n\n"
		"Calling srand() Function to build a basic rand-seed, and then, Calling rand()"
		" Function to build the ramdom number(s). If you match the Desplay Mode, and then"
		", The program will push all numbers have been built into your window(s) unless they"
		" beyond the max limit you have set. If you match the Only-first Mode, and then"
		", The program will push the numbers haven't been appeared into your window(s) unless"
		" they have been emerged before. It's so easy, right? \n\n";

	cout << "\n按任意键以退出";
	ab = _getch();

	//返回主界面

	goto Replay;

Exitr://退出界面

	clearScreen();
	cout << "------------------------------------------"
		"\n感谢使用 < Ramdom Number Builder > 2025\n"
		"您现在可以关闭此窗口，期待我们的重逢!\n"
		"------------------------------------------";

	//退出程序

	exit(0);

Replay://功能选择界面（主界面）

	clearScreen();
	printf("欢迎使用 < Ramdom Number Builder > 2025 (version: 1.6 - InDev) 这是一"
		"款用来生成随机数的轻量级软件，并基于 Windows cmd (控制台终端) 生成，以下是几个功"
		"能板块:\n\n\\h\t查看帮助和注解\n\\c\t查看算法\n\\r\t抽奖功能\n\\e\t退出程序\n"
		"\\s\t设置\n\n\\1\t快速随机数\n\n请输入功能板块前"
		"的字母来访问对应板块的功能:\n");
	cout << "\n::Main_menu@" << username << ">";

	//输入功能板块前的字母

	b = _getch();
	cout << b;
	while (b != 'R' and b != 'r' and b != 'H' and b != 'h' and b != 'c' and b != 'C' 
		and b != 'e' and b != 'E' and b != 's' and b != 'S' and b != '1') {

		//输入错误时的提示

		cout << "\n请输入 h(Help) / c(Code) / r(Ramdom) / e(Exit) / s(Settings) / 1(RapidPress1)， 而不是其他字符: ";
		b = _getch();
		cout << b;
	}
	if (b == 'R' or b == 'r') goto Ramdomr;		//跳转到抽奖界面

	if (b == 'H' or b == 'h') goto Help;		//跳转到帮助界面

	if (b == 'E' or b == 'e') goto Exitr;		//跳转到退出界面

	if (b == 'C' or b == 'c') goto Code;		//跳转到算法显示界面

	if (b == 'S' or b == 's') goto Settings;	//跳转到设置界面

	if (b == '1') goto Rapid_step1;				//跳转到快速生成界面

Help://帮助界面

	clearScreen();
	printf("\n欢迎使用 < RNB Helper > (version: 0.1) 您可以在这里看到一些帮助和提示：\n\n"
		"1. 若您在输入随机量时输入了一个较大值（目前未明确具体上限值），有可能会陷入死循环，关闭控制台退出重进即可。"
		"\n\n2. 当前随机生成有两种模式，重复模式和单值模式，重复模式下每个数据都可能会出现多次，且可以自定义取值"
		"范围，单值模式下每个数据只有一次出现的可能，但无法指定权重，所以有的数据可能权重过高，导致不公平，如想要重新生"
		"成,在确认界面输入“Y”或者“y”即可。\n");

	cout << "\n按任意键以退出";
	ab = _getch();

	//返回主界面

	goto Replay;

Ramdomr://抽奖界面

	clearScreen();

	//抽奖界面的主要循环结构

	while (true) {
		cout << "\n是否开始抽奖？(Y/N): ";
		n = _getch();
		cout << n;
		while (n != 'Y' and n != 'y' and n != 'N' and n != 'n') {

			//输入错误时的提示

			cout << "\n请输入Y(Yes)/N(No)， 而不是其他字符: ";
			n = _getch();
			cout << n;
		}
		if (n == 'N' or n == 'n') {
			goto Replay;//返回主界面
		}

	Rapid_step1://快速生成界面的第一部分（跳转流）

		//初始化所有的随机生成变量，归零

		clearScreen();
		memset(memory, 0, sizeof(memory));
		a = 1;

		//输入随机量

		int t;
		cout << "\n请填写随机量（最大为 500）: ";
		cin >> t;

		int times = int(t);			//随机量初始化，times用来存储输入的随机量以应对随机量自身的增减
		Rapid_mode_Max = times;		//快速生成模式的最大值默认就是随机量

		while (t <= 0 or t > 500) {

			//输入错误时的提示

			cout << "\n请输入一个不超过500的正整数: ";
			cin >> t;
		}

		int maxn;					//重复模式的最大值初始化
		maxn = times;

		if (b == '1')	goto Rapid_step2;	//跳转到快速生成界面的第二部分，只适用于快速生成模式

		//是否包含重复号码

		cout << "\n是否包含重复号码？(Y/N)：";
		ys = _getch();
		cout << ys;

		while (ys != 'Y' and ys != 'y' and ys != 'N' and ys != 'n') {

			//输入错误时的提示

			cout << "\n请输入Y(Yes)/N(No)， 而不是其他字符: ";
			ys = _getch();
			cout << ys;
		}

		//单值模式下自定义的上下限设置

		if (ys == 'N' or ys == 'n') {
			while (maxx - minx + 1 < times) {
				clearScreen();

				cout << "\n请输入中奖号码的上限值（输入 “0” 上限默认为随机量）: ";
				cin >> maxx;
				if (maxx == 0) maxx = times;

				cout << "\n请输入中奖号码的下限值（输入 “0” 下限默认为1）: ";
				cin >> minx;
				if (minx == 0) minx = 1;

				//处理错误的输入

				if (maxx < 0 or minx < 0) {
					cout << "\n请重新输入，上限值和下限值必须大于等于0！\n";
					Sleep(1000);
					clearScreen();
					continue;
				}
				if (maxx - minx + 1 < times) {
					cout << "\n请重新输入，上限值减去下限值必须大于等于随机量！\n";
					Sleep(1000);
					clearScreen();
					continue;
				}
			}
		}

		//重复模式下的上限值设置

		else if (ys == 'Y' or ys == 'y') {
			cout << "\n请输入中奖号码的上限值（输入 “0” 默认为随机值的最上限）: ";
			cin >> maxn;

			if (maxn == 0) maxn = 0x3f3f3f;
		}
		cout << "\n";

		srand(time(0));//随机种子

	Rapid_step2://快速生成界面的第二部分（跳转流）

		//初始化所有的随机生成变量，归零

		clearScreen();
		memset(memory, 0, sizeof(memory));
		a = 1;
		t = times;

		//开始生成随机数

		cout << "中奖序号\t随机值\n-----------------------\n";
		while (t) {

			int randomNumber;

			if ((ys == 'N' or ys == 'n') and b == '1') {		
				//快速生成模式
				randomNumber = rand() % Rapid_mode_Max + Rapid_mode_Min;
			}
			else if (ys == 'y' or ys == 'Y') {					
				//重复模式
				randomNumber = rand() % maxn + 1;
			}
			else {												
				//单值模式
				randomNumber = rand() % maxx + minx; 
			}
			
			//重复模式下的生成

			if (ys == 'y' or ys == 'Y') {
				
				if (randomNumber > maxn)	continue;
				Sleep(delays);
				cout << "#" << a << ":\t\t" << randomNumber << endl;
				a++, t--;
				continue;
			}

			//处理不符合规定的随机数

			if ((randomNumber > maxx or randomNumber < minx) and b != '1')	continue;

			//单值模式和快速生成模式下的生成，并处理不符合规定的随机数

			if (!memory[randomNumber]) {
				memory[randomNumber] = 1;
				Sleep(delays);
				cout << "#" << a << ":\t\t" << randomNumber << endl;
				a++, t--;
			}
		}

		//生成结束后的提示

		if (b == '1') {
			Sleep(200);
			cout << "\n\n" << "快速生成成功！本次一共生成了" << times <<
				"个名额，不包含重复数据，按任意键返回上一界面，按 “c” 以重置生成，按 “r” 以再次设置随机量\n\n\n" << endl;
			conti = _getch();

			if (conti == 'c' or conti == 'C') goto Rapid_step2;	//重置生成
			if (conti == 'r' or conti == 'R') goto Rapid_step1;	//再次设置随机量
			goto Replay;										//返回主界面
		}
		if (ys == 'y' or ys == 'Y') {
			Sleep(500);
			cout << "\n\n" << "生成成功！本次一共生成了" << times <<
				"个名额，包含重复数据，若想再次加载进程请在对话框中回答：\n\n\n" << endl;

			//开启新的一轮生成
			continue;
		}
		Sleep(500);
		cout << "\n\n" << "生成成功！本次一共生成了" << times <<
			"个名额，不含重复数据，若想再次加载进程请在对话框中回答：\n\n\n" << endl;

		//开启新的一轮生成
		continue;
	}

	return 0;
}