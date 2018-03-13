//
//  ftokenizer.hpp
//  file_tokenizer
//
//  Created by Calvin Huang on 3/6/18.
//
//	File tokenizer class (FTokenizer) header file
//

#ifndef ftokenizer_hpp
#define ftokenizer_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "stokenizer.hpp"

/** File tokenizer.
 *	Accepts a file and outputs Token objects.
 */
class FTokenizer
{
public:
	const int MAX_BLOCK = MAX_BUFFER;	//!< Make block read length the same as STokenizer's buffer size
	
	/** Opens a file to be tokenized.
	 *	@param fname Filepath of the file to tokenize.
	 *	@see set_string()
	 */
	FTokenizer(const char* fname);
	
	~FTokenizer();						//!< Destructor closes the file
	
	/** Fetch the next token from string tokenizer.
	 *	If STokenizer has no more tokens, try to fetch another block from the file.
	 *	@return Next token
	 *	@see operator>>()
	 */
	Token next_token();
	
	/** Whether there are more tokens in the file.
	 *	@return True if more tokens can be read.
	 */
	bool more();
	
	/** Extract token object.
	 *	Very similar to the way cin >> works.
	 */
	friend FTokenizer& operator >> (FTokenizer& f, Token& t);
private:
	/** Reads a new block from input file.
	 *	@return True if successful; false if end-of-file has already been reached.
	 */
	bool get_new_block(); //gets the new block from the file
	std::ifstream _f;   //file being tokenized
	STokenizer _stk;     //The STokenizer object to tokenize current block
	bool _more;         //false if last token of the last block
	//  has been processed and now we are at
	//  the end of the last block.
};

#endif /* ftokenizer_hpp */
