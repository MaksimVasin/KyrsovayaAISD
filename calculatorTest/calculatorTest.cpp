#include "pch.h"
#include "CppUnitTest.h"
#include "../calculator/Calculator.cpp"
#include "../calculator/Calculator.h"
#include "../calculator/LinkedList.cpp"

#include <math.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace sortTest
{
	TEST_CLASS(sortTest)
	{
	public:
		calculator TestCalc;
		////////////////////////////////////////////////////////parsing characters
		TEST_METHOD(found_function)
		{
			bool A = TestCalc.reeding("cos(sin(tg(ctg(0))))|");
			Assert::AreEqual(A, true);
		}
		TEST_METHOD(Not_found_function)
		{
			bool A = TestCalc.reeding("cas(0)|");
			Assert::AreEqual(A, false);
		}
		////////////////////////////////////////////////////////correct_num
		TEST_METHOD(parsing_num_standart)
		{
			bool A = TestCalc.reeding("123|");
			Assert::AreEqual(A, true);
		}
		TEST_METHOD(parsing_num_standart_dot)
		{
			bool A = TestCalc.reeding("1.23|");
			Assert::AreEqual(A, true);
		}
		TEST_METHOD(parsing_num_double_dot)
		{
			bool A = TestCalc.reeding("1.2.3|");
			Assert::AreEqual(A, false);
		}
		TEST_METHOD(parsing_num_error_size)
		{
			bool A = TestCalc.reeding("12345678901234567890123|");
			Assert::AreEqual(A, false);
		}
		TEST_METHOD(parsing_num_bonus_symbols)
		{
			bool A = TestCalc.reeding("123ABC123|");
			Assert::AreEqual(A, false);
		}
		////////////////////////////////////////////////////////correct input // reeding+correct_reeding
		TEST_METHOD(second_close_bracket)
		{
			bool A = TestCalc.reeding("(1+1))|");
			Assert::AreEqual(A, false);
		}
		TEST_METHOD(double_operation)
		{
			bool A = TestCalc.reeding("1*+1|");
			Assert::AreEqual(A, false);
		}
		TEST_METHOD(unary_minus_close_bracket)
		{
			bool A = TestCalc.reeding("(1+2-)|");
			Assert::AreEqual(A, false);
		}
		TEST_METHOD(close_bracket_function)
		{
			bool A = TestCalc.reeding("(1+1)cos(0)|");
			Assert::AreEqual(A, false);
		}
		TEST_METHOD(Num_function)
		{
			bool A = TestCalc.reeding("3cos(0)|");
			TestCalc.inf_to_pref();
			Assert::AreEqual(A, false);
		}
		TEST_METHOD(empty_brackets)
		{
			bool A = TestCalc.reeding("cos()|");
			TestCalc.inf_to_pref();
			Assert::AreEqual(A, false);
		}
		////////////////////////////////////////////////////////operators
		TEST_METHOD(abs)
		{
			double A;
			TestCalc.reeding("abs(-4)|");
			TestCalc.inf_to_pref();
			A = TestCalc.calculations();
			Assert::AreEqual(A, (double)4);
		}
		TEST_METHOD(plus_minus)
		{
			double A;
			TestCalc.reeding("4+6-1|");
			TestCalc.inf_to_pref();
			A = TestCalc.calculations();
			Assert::AreEqual(A, (double)9);
		}
		TEST_METHOD(multipl_division)
		{
			double A;
			TestCalc.reeding("4*10/2|");
			TestCalc.inf_to_pref();
			A = TestCalc.calculations();
			Assert::AreEqual(A, (double)20);
		}
		TEST_METHOD(power)
		{
			double A;
			TestCalc.reeding("2^10|");
			TestCalc.inf_to_pref();
			A = TestCalc.calculations();
			Assert::AreEqual(A, (double)1024);
		}
		TEST_METHOD(cos_sin)
		{
			double A,B;
			TestCalc.reeding("cos(2.5*pi) + sin(100 * pi)|");
			B = cos(2.5* M_PI) + sin(100 * M_PI);
			TestCalc.inf_to_pref();
			A = TestCalc.calculations();
			Assert::AreEqual(A, B);
		}
		TEST_METHOD(tg_ctg_ln_log)
		{
			double A, B;
			TestCalc.reeding("ln(e) + tg(pi *0.25) + ctg(pi/4)+log5|");
			B = log(M_E) + tan(M_PI * 0.25) + 1/(tan(M_PI/4)) + log10(5);
			TestCalc.inf_to_pref();
			A = TestCalc.calculations();
			Assert::AreEqual(A, B);
		}
		////////////////////////////////////////////////////////priorityes
		TEST_METHOD(prior)
		{
			double A;
			TestCalc.reeding("2+2*2|");
			TestCalc.inf_to_pref();
			A = TestCalc.calculations();
			Assert::AreEqual(A, (double)6);
		}
		TEST_METHOD(prior2)
		{
			double A;
			TestCalc.reeding("(2+2)*2|");
			TestCalc.inf_to_pref();
			A = TestCalc.calculations();
			Assert::AreEqual(A, (double)8);
		}
	};
}