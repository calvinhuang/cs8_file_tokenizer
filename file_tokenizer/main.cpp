//
//  main.cpp
//  cs8_string_tokenizer
//
//  Created by Calvin Huang on 2/27/18.
//
//	This is a test of the FTokenizer class using Gabriel Garcia Marquez's
//	1000 Years of Solitude. It counts andoutputs only the alphanumeric tokens
//	and ignores non-ANSI characters (including multibyte Unicode characters).
//

#include <iostream>
#include "stokenizer.hpp"
#include "ftokenizer.hpp"
#include <string>
#include <iomanip>
using namespace std;


/**	Format and output tokens.
 *	Used by print_test() for STokenizer test.
 *	@see print_test(const char* s)
 *	@see test_s_tokenizer()
 */
void print_tokens(STokenizer stk)
{
	Token t;
	t = Token();
	stk>>t;
	while (stk.more()) {
		cout << setw(10) << t.type_string() << setw(10) << "|" << t << "|" << endl;
		stk>>t;
	}
}

/**	Print c-string in quotes.
 *	Convenience function for testing.
 *	@param s String to print.
 */
void print_string(const char* s)
{
	cout << '\"' << s << '"' << "\n\n";
}

/** Print single STokenizer test run.
 *	@param s C-string to tokenize.
 *	@param stk STokenizer stance to use for test.
 */
void print_test(const char*s, STokenizer &stk)
{
	print_string(s);
	stk.set_string(s);
	print_tokens(stk);
	cout << "\n   =======\n\n";
}

/** FTokenizer test.
 *	Test file tokenizer against a hard-coded file.
 */
void test_f_tokenize_simple(){
	Token t;
	const char* path = "solitude.txt";
	FTokenizer ftk(path);
	ftk >> t;
	int token_count = 0;
	while (ftk.more()){
		if (t.type_string() == "ALPHA" ){
			token_count++;
			cout << setw(10) << right << token_count
			<<setw(3) << left << ":" << setw(25) << left << t.token_str()
			<<t.type_string()<< setw(20) << right << t.token_str().length() << endl;
		}
		ftk >> t;
	}
	cout << "Tokens Found: " << token_count << endl;
}

/** STokenizer test suite.
 *	Test STokenizer against a variety of test cases:
 *		- Lowercase sentence containing numbers.
 *		- Capitalized sentence containing whitespace characters.
 *		- Empty string.
 *		- String ending in a number.
 *		- Another string ending in a number with punctuation.
 *		- String ending in whitespaces.
 *		- Lots of weird characters.
 *		- Words, numbers, punctuation, whitespaces and unknowns.
 *		- Just whitespaces.
 */
void test_s_tokenizer()
{
	STokenizer stk;
	
	char s[] = "it was the night of october 17th. pi was still 3.14.";
	print_test(s, stk);
	
	char s2[] = "This is another test.\n\tIt has a line-break and tab.";
	print_test(s2, stk);
	
	char s3[] = "";
	print_test(s3, stk);
	
	char s4[] = "This ends with a number: 3.46.77";
	print_test(s4, stk);
	
	char s5[] = "This also ends with a number: 3333.3334,77.57";
	print_test(s5, stk);
	
	char s6[] = "What if we end on some spaces?			\n\t";
	print_test(s6, stk);
	
	char s7[] = ",+(,-)+:;\nWhat's going on!?\t###$#%$%";
	print_test(s7, stk);
	
	char s8[] = "alpha, 8.88, 01, 32, r2d2, 666666, alpha ! . +";
	print_test(s8, stk);
	
	char s9[] = " \t\n \t\n \t\n \t\n";
	print_test(s9, stk);
}

int main(int argc, const char * argv[]) {
	test_f_tokenize_simple();
    return 0;
}
