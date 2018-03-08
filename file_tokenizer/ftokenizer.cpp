//
//  ftokenizer.cpp
//  file_tokenizer
//
//  Created by Calvin Huang on 3/6/18.
//

#include "ftokenizer.hpp"

FTokenizer::FTokenizer(const char* fname)
{
	_f.open(fname, std::ifstream::in);
	if (_f.fail())
		_more = false;
	else
		_more = true;
	if (more())
		get_new_block();
}

bool FTokenizer::get_new_block()
{
	if (_more)
	{
		char buffer[MAX_BUFFER];
		_f.read(buffer, MAX_BUFFER - 1);
		buffer[_f.gcount()] = (char) 0;
		if (_f.gcount() < 1)
		{
			_more = false;
			return false;
		}
		else if (_f.gcount() < MAX_BUFFER - 1)
		{
			_more = false;
		}
		_stk.set_string(buffer);
		return true;
	}
	return false;
}

bool FTokenizer::more()
{
	return _stk.more() || _more;
}

int FTokenizer::pos()
{
	return _pos;
}

int FTokenizer::block_pos()
{
	return _blockPos;
}

Token FTokenizer::next_token()
{
	Token token;
	if (_stk.more()) {
		_stk >> token;
	}
	if (!_stk.more() && more())
	{
		get_new_block();
	}
	return token;
}

FTokenizer& operator >> (FTokenizer& f, Token& t)
{
	t = f.next_token();
	return f;
}
