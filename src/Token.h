#pragma once
#include <string>

enum class TokenType
{
	Keyword,
	Identifier,
	Number,

	Assign,
	Plus,
	Minus,
	Star,
	Slash,

	Semicolon,
	LeftParen,
	RightParen,
	LeftBrace,
	RightBrace,

	EndOfFile,

	Unknown
};

struct Token
{
	TokenType type;
	std::string value;

	Token(TokenType type, const std::string& value) : type(type), value(value) 
	{
	}
};