//
//  ftokenizer.hpp
//  file_tokenizer
//
//  Created by Calvin Huang on 3/6/18.
//

#ifndef ftokenizer_hpp
#define ftokenizer_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "stokenizer.hpp"

class FTokenizer
{
public:
	const int MAX_BLOCK = MAX_BUFFER;
	FTokenizer(const char* fname);
	Token next_token();
	bool more();        //returns the current value of _more
	int pos();          //returns the value of _pos
	int block_pos();     //returns the value of _blockPos
	friend FTokenizer& operator >> (FTokenizer& f, Token& t);
private:
	bool get_new_block(); //gets the new block from the file
	std::ifstream _f;   //file being tokenized
	STokenizer _stk;     //The STokenizer object to tokenize current block
	int _pos;           //Current position in the file
	int _blockPos;      //Current position in the current block
	bool _more;         //false if last token of the last block
	//  has been processed and now we are at
	//  the end of the last block.
};

#endif /* ftokenizer_hpp */
