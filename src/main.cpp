#include <iostream>
#include <fstream>
#include <sstream>
#include <Lexer.h>

std::string ReadFile(const std::string& filename)
{
	std::ifstream file(filename);
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

int main()
{
	std::string source = ReadFile("test.nx");

	std::cout << "Source code:\n" << source << "\n\nTokens:\n";

	Lexer lexer(source);
	auto tokens = lexer.Tokenize();

	for (const auto& token : tokens)
	{
		std::cout << static_cast<int>(token.type) << ": " << token.value << std::endl;
	}

	return 0;
}