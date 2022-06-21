//
// Created by martin on 10/01/2022.
//

#ifndef _CODE_H_
#define _CODE_H_

struct Code {
		inline static constexpr char DECLARE = 'L';
		inline static constexpr char CONSTANT = 'C';
		inline static constexpr char QUIT = 'Q';
		inline static constexpr char PRINT = ';';
		inline static constexpr char NUMBER = '8';
		inline static constexpr char NAME = 'a';
		inline static constexpr char SQRT = 's';
		inline static constexpr char POWER = 'p';
		inline static constexpr char ASSIGN = 'A';
		inline static constexpr char PARENTHESIS = '(';
		inline static constexpr char MINUS = '-';
		inline static constexpr char HELP = 'h';
		inline static constexpr char LIST = 'P';
	};

//enum class Code : char {
//	DECLARE = 'L',
//	QUIT = 'Q',
//	PRINT = ';',
//	NUMBER = '8',
//	NAME = 'a',
//	SQRT = 's',
//	POWER = 'p',
//	ASSIGN = 'A',
//};

#endif //_CODE_H_
