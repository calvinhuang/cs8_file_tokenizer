//
//  token.hpp
//  cs8_string_tokenizer
//
//  Created by Calvin Huang on 3/1/18.
//
//	Header for Token class
//

#ifndef token_hpp
#define token_hpp

#include <stdio.h>
#include <string>
#include <iomanip>
using namespace std;

const int UNKNOWN_TYPE = -1;	//!< Catch-all for all unrecognized characters
const int ALPHA_TYPE = 0;		//!< Alpha-numeric words
const int NUMBER_TYPE = 1;		//!< Decimal numbers
const int PUNCTUATION_TYPE = 2;	//!< English punctuation
const int SPACE_TYPE = 3;		//!< Whitespace characters


/**
 *	Simple class representing Tokens.
 */
class Token
{
public:
	/**	Default Token contructor.
	 *	Initializes object with empty string and unknown type.
	 */
	Token() : _token(""), _type(UNKNOWN_TYPE) {};

	/** Explicitly initialize token with specific string and type.
	 *	@param str Token string
	 *	@param type Token type, e.g.
	 *		- UNKNOWN_TYPE
	 *		- ALPHA_TYPE
	 *		- NUMBER_TYPE
	 *		- PUNCTUATION_TYPE
	 *		- SPACE_TYPE
	 */
	Token(string str, int type) : _type(type), _token(str) {};

	/**
	 *	Insertion operator for outputting token string.
	 */
	friend ostream& operator <<(ostream& outs, const Token& t);

	/**
	 *	Token type getter.
	 *	@return Token type
	 *	@see type_str()
	 */
	int type() const;

	/**
	 *	Return token type as human-readable string.
	 *	@return String represention of token type.
	 *	@see type()
	 */
	string type_string() const;

	/**
	 *	Token string getter.
	 *	@return Token string
	 */
	string token_str() const;
private:
	string _token;
	int _type;
};

string token_type_to_string(int type);

#endif /* token_hpp */
