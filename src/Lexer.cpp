#include "Lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& source) : source(source) 
{

}

bool Lexer::IsAtEnd() const 
{
	return current >= source.length();
}

char Lexer::Peek() const
{
	if (IsAtEnd())
		return '\0';

	return source[current];
}

char Lexer::Advance()
{
	if (IsAtEnd())
		return '\0';

	return source[current++];
}

void Lexer::SkipWhitespace()
{
	while (!IsAtEnd())
	{
		char c = Peek();
		if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
			Advance();
		else
			break;
	}
}

Token Lexer::ReadIdentifier()
{
	std::string value;

	while (!IsAtEnd() && (std::isalnum(Peek()) || Peek() == '_'))
	{
		value += Advance();
	}

	if (value == "int" ||
		value == "float" ||
		value == "double" ||
		value == "char" ||
		value == "return")
	{
		return Token(TokenType::Keyword, value);
	}
	return Token(TokenType::Identifier, value);
}

Token Lexer::ReadNumber()
{
	std::string value;
	while (!IsAtEnd() && std::isdigit(Peek()))
	{
		value += Advance();
	}
	return Token(TokenType::Number, value);
}

std::vector<Token> Lexer::Tokenize()
{
	std::vector<Token> tokens;

	while (!IsAtEnd())
	{
		SkipWhitespace();

		if(IsAtEnd())
			break;

		char c = Peek();

		if(std::isalpha(c) || c == '_')
		{
			tokens.push_back(ReadIdentifier());
		}
		else if (std::isdigit(c))
		{
			tokens.push_back(ReadNumber());
		}
		else
		{
			switch (c)
			{
			case '=':
				tokens.emplace_back(TokenType::Assign, "=");
				Advance();
				break;

			case '+':
				tokens.emplace_back(TokenType::Plus, "+");
				Advance();
				break;

			case '-':
				tokens.emplace_back(TokenType::Minus, "-");
				Advance();
				break;

			case '*':
				tokens.emplace_back(TokenType::Star, "*");
				Advance();
				break;

			case '/':
				tokens.emplace_back(TokenType::Slash, "/");
				Advance();
				break;

			case ';':
				tokens.emplace_back(TokenType::Semicolon, ";");
				Advance();
				break;

			case '(':
				tokens.emplace_back(TokenType::LeftParen, "(");
				Advance();
				break;

			case ')':
				tokens.emplace_back(TokenType::RightParen, ")");
				Advance();
				break;

			case '{':
				tokens.emplace_back(TokenType::LeftBrace, "{");
				Advance();
				break;

			case '}':
				tokens.emplace_back(TokenType::RightBrace, "}");
				Advance();
				break;

			default:
				tokens.emplace_back(TokenType::Unknown, std::string(1, c));
				Advance();
				break;
			}
		}
	}

	tokens.emplace_back(TokenType::EndOfFile, "");

	return tokens;
}