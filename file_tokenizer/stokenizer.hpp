//
//  stokenizer.hpp
//  cs8_string_tokenizer
//
//  Created by Calvin Huang on 2/27/18.
//
//	Header for the STokenizer (String Tokenizer) class.
//

#ifndef stokenizer_hpp
#define stokenizer_hpp

#include <stdio.h>
#include <string>
#include "token.hpp"
using namespace std;

const size_t MAX_COLUMNS = 256; //!< One column for each of the 256 ANSI characters
const size_t MAX_ROWS = 12;		//!< Total number of states across all state machines
const size_t MAX_BUFFER = 1000;	//!< Max c-string size (including terminating null character)

const int NUMBER_START = 0;			//!< Starting row for the number token state machine
const int ALPHA_START = 4;			//!< Starting row for the word token state machine
const int SPACE_START = 6;			//!< Starting row for the whitespace token state machine
const int PUNCTUATION_START = 8;	//!< Starting row for the punctuation token state machine
const int UNKNOWN_START = 10;		//!< Starting row for the unknown token state machine


/** String tokenizer
 *	Accepts c-strings and outputs Token objects
 */
class STokenizer
{
public:
	/** Default constructor
	 *	Initializes tokenizer with an empty string.
	 *	@see set_string()
	 */
	STokenizer();
	
	/** Initializes tokenizer with a given string.
	 *	@param str A null-terminated c-string.
	 */
	STokenizer(char str[]);
	
	/** Determines if tokenizer has reached the end of the string.
	 *	@return True if there are no more tokens
	 */
	bool done();
	
	/** Determines if there is more of the string left to parse.
	 * @return True if there are more tokens
	 */
	bool more();
	//-- big three --
	
	/** Extract one token.
	 *	Very similar to the way cin >> works.
	 */
	friend STokenizer& operator >> (STokenizer& s, Token& t);
	
	/** Set input string.
	 *	@param str A null-terminated c-string.
	 */
	void set_string(const char str[]);
	
private:
	/** Create table for all the tokens we will recognize.
	 *	This includes decimal numbers, words (including those containing numbers),
	 *	whitespaces, punctuation characters and unknown tokens.
	 *	@param _table A two-dimension int array to store state machine definitions.
	 */
	void make_table(int _table[][MAX_COLUMNS]);
	
	/** Initialize state machine definition table with {{-1}}.
	 *	Sets all items in the array to -1 to signify transition to invalid state by default.
	 *	@param _table A two-dimension int array to store state machine definitions.
	 */
	void init_table(int _table[][MAX_COLUMNS]);
	
	/** Set a row in the state machine definition table to a particular value.
	 *	@param _table A two-dimension int array to store state machine definitions.
	 *	@param state Row index (which state to modify).
	 *	@param col_start Column index marking the first cell to modify (corresponds to ASCII/ANSI code).
	 *	@param col_stop Column index marking the end of the row (corresponds to ASCII/ANSI code).
	 *	@param next_state Row index specifying which state to transition to.
	 */
	void set_table_row(int _table[][MAX_COLUMNS], int state, int col_start, int col_stop, int next_state);
	
	/** Set a cell in the state machine definition table to a particular value.
	 *	@param _table A two-dimension int array to store state machine definitions.
	 *	@param state Row index (which state to modify).
	 *	@param col Column index (which ASCII/ANSI character's state-transition to modify).
	 *	@param next_state Row index (state transition for that particular ASCII/ANSI character).
	 */
	void set_table_cell(int _table[][MAX_COLUMNS], int state, int col, int next_state);
	/** Specify whether a state is a success state.
	 *	@param _table A two-dimension int array to store state machine definitions.
	 *	@param state Row index (which state to modify).
	 *	@param success True to mark the state as a success state, false otherwise.
	 */
	void set_table_success(int _table[][MAX_COLUMNS], int state, bool success=true);
	
	/** Try to extract a new token from the input string.
	 *	@param start_state Specify which state machine to use via the row index of the starting state of that machine.
	 *	@return True if a valid token was found (state machine passed through at least one success state).
	 */
	bool get_token(int start_state, string& token);
	
	char _buffer[MAX_BUFFER];       //!< Buffer for the null-terminated input string.
	int _pos;                       //!< Tokenizer's current position in the input string.
	static int _table[MAX_ROWS][MAX_COLUMNS];	//!< Defines individual state machines for each token type.
												//!< Each row defines a single state in a particular state machine.
												//!< First column is 1 for success states and 0 otherwise.
												//!< Subsequent columns specify the state transition for
												//!< each ANSI code.
	
};

/** Prints state machine name corresponding to a particular state.
 *	@param state Row index of a machine state
 *	@return String identifying which state machine / token type the state belongs to.
 */
string machine_name(int state);

#endif /* stokenizer_hpp */
