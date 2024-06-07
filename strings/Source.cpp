#include "Source.h"
#include <conio.h>
#include <fstream>
#include "Person.h"

namespace chili
{
	void print(const char* s)
	{
		for (; *s != 0; s++)
		{
			_putch(*s);
		}
	}

	void read(char* buf, int maxSize)
	{
		const char* const pEnd = buf + maxSize;
		for (char c = _getch(); c != 13 && (buf + 1 < pEnd); c = _getch(), buf++)
		{
			_putch(c);
			*buf = c;
		}
		*buf = 0;
	}

	int str2int(const char* s)
	{
		// scan to start point
		const char* p = s;
		for (; *p >= '0' && *p <= '9'; p++);
		p--;

		int val = 0;
		int place = 1;
		// convert place values and accumulate
		for (; p >= s; p--)
		{
			val += (*p - '0') * place;
			place *= 10;
		}

		return val;
	}

	int fib(int n)
	{
		if (n < 2)
		{
			return n;
		}
		return fib(n - 1) + fib(n - 2);
	}

	void strrev(char* pl)
	{
		// scan to start point
		char* pr = pl;
		for (; *pr != 0; pr++);
		pr--;

		for (; pl < pr; pl++, pr--)
		{
			const char temp = *pl;
			*pl = *pr;
			*pr = temp;
		}
	}

	void int2str(int val, char* buf, int size)
	{
		char* const pStart = buf;
		char* const pEnd = buf + size;
		for (; val > 0 && (buf + 1 < pEnd); val /= 10, buf++)
		{
			*buf = '0' + val % 10;
		}
		*buf = 0;
		strrev(pStart);
	}

	void output2file(const char* string, std::ofstream& out)
	{
		for (; *string != 0; string++)
		{
			char c = *string;
			out.put(c);
		}
	}
	
	//takes number input from user and prints that amount in '='
	void printInt2Equal(int n)
	{
		for (int i = 0; i < n; i++)
		{
			_putch('=');
		}
	}

	void printGraph(std::ifstream& in, std::ofstream& out)
	{	
		const int digitMax = 8;
		char intString[digitMax];
		bool intAlert = false;

		// i fills up intString array in loop below
		int i = 0;
		out.flush();

		for (char c = in.get(); in.good(); c = in.get())
		{
			_putch(c);
			//checks if in.get() returns a digit char, then fills up intString with chars
			for (char digit = c; digit > 47 && digit < 58; digit = in.get())
			{
				intString[i] = digit;
				intAlert = true;
				i++;
			}
			if (intAlert)
			{
				int strInt = str2int(reinterpret_cast<const char*>(&intString));
				print(" | ");
				printInt2Equal(strInt);
				intAlert = false;
				//Resets array and "i" variable in prepartion for the next value input
				for (int i = 0; i < digitMax; i++)
				{
					intString[i] = 0;
				}
				i = 0;
			}

		}
	}
	
}
int main()
{
	using namespace chili;

	std::ofstream out("ppl1.txt", std::ios::binary);
	std::ifstream in("ppl1.txt", std::ios::binary);

	print("\n(l)oad (s)ave (a)dd (q)uit or (p)rint?\n");
	
	char input = _getch();
	while (input != 'q')
	{
		//Checks to see if one of the given options were chosen
		while ((input != 'l') && (input != 's') && (input != 'a') && (input != 'q') && (input != 'p'))
		{
			input = _getch();
		}
		switch (input)
		{
		case 'a':
			print("\nEnter a name.\n");
			for (char c = _getch(); c != 13; c = _getch())
			{
				_putch(c);
				out.put(c);
			}
			print("\n");
			print("\nEnter a integer value associated with this name.\n");
			for (char c = _getch(); c != 13; c = _getch())
			{
				_putch(c);
				out.put(c);
			}
			out.put('\n');
			out.put('\n');
			print("\n\n");
			print("\n(l)oad (s)ave (a)dd (q)uit or (p)rint?\n");
			input = _getch();
			break;
		case 'p':
			printGraph(in, out);
			print("\n(l)oad (s)ave (a)dd (q)uit or (p)rint?\n");
			input = _getch();
			break;
		case'q':
			break;
		}
	}

	
	return 0;
}