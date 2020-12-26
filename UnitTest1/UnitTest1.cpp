#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Dkvit\source\repos\Курсовая_АлгСтр\Курсовая_АлгСтр\queue.h"
#include "C:\Users\Dkvit\source\repos\Курсовая_АлгСтр\Курсовая_АлгСтр\reverse.h"
#include "C:\Users\Dkvit\source\repos\Курсовая_АлгСтр\Курсовая_АлгСтр\queue.h"
#include "C:\Users\Dkvit\source\repos\Курсовая_АлгСтр\Курсовая_АлгСтр\function.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Test1)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "45.44+6.56";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 52);
		}
		TEST_METHOD(Test2)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "45.4-6.5";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 38.9);
		}
		TEST_METHOD(Test3)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "45.44/2";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 22.72);
		}
		TEST_METHOD(Test4)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "45.44*2";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 90.88);
		}
		TEST_METHOD(Test5)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "2^3";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 8);
		}
		TEST_METHOD(Test6)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "4!";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 24);
		}
		TEST_METHOD(Test7)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "log(100)";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 2);
		}
		TEST_METHOD(Test8)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "ln(e^3)";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 3);
		}
		TEST_METHOD(Test9)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "cos(pi)";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == -1);
		}
		TEST_METHOD(Test10)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "sin(0)";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 0);
		}
		TEST_METHOD(Test11)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "tg(pi/4)";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == tan(acos(-1.0)/4));
		}
		TEST_METHOD(Test12)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "ctg(pi/4)";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 1/tan(acos(-1.0) / 4));//acos(-1.0)=pi
		}
		TEST_METHOD(Test13)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "sqrt(36)";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 6);
		}
		TEST_METHOD(Test14)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "(((log(10)+ln(e)+cos(0)+sin(pi)-6)*3)+3^3)/0.5";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->postfix_string == "10  log  e ln  +  0  cos  +  pi sin  + 6  - 3  * 3 3  ^  + 0.5 /" );
		}
		TEST_METHOD(Test15)
		{
			reverse_Polish_notation* ship = new reverse_Polish_notation;
			std::string str = "(((log(10)+ln(e)+cos(0)+sin(pi)-3!)*3)+3^3)/3";
			ship->infix_string = str;
			ship->invert();
			Assert::IsTrue(ship->result() == 6);
		}
	};
}
