#pragma once
#include <string>
#include <vector>
#include "Token.h"

class Lexer
{
public:
	Lexer(const std::string& source);
	std::vector<Token> Tokenize();

private:
	std::string source;
	size_t current = 0;
	char Peek() const;
	char Advance();
	bool IsAtEnd() const;
	void SkipWhitespace();
	Token ReadIdentifier();
	Token ReadNumber();
};