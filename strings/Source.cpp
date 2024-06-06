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
	void names2console(std::ifstream& in, std::ofstream& out)
	{	
		out.flush();
		in.seekg(0);
		/*int cursorPos = in.tellg();
		char test = in.get();*/

		for (char c = in.get(); c > 64 && c < 123; c = in.get())
		{
			_putch(c);
		}
	}
	/*bool findValue(std::ifstream& in)
	{

	}*/
}
int main()
{
	using namespace chili;

	std::ofstream out("ppl1.txt", std::ios::binary);
	std::ifstream in("ppl1.txt", std::ios::binary);



	print("\nPress Enter to start input - (l)oad (s)ave (a)dd (q)uit or (p)rint?\n");
	while (_getch() != 'q')
	{
		if (_getch() == 'a')
		{
			print("\nEnter a name.\n");
			for (char c = _getch(); c != 13; c = _getch())
			{
				_putch(c);
				out.put(c);
			}
			out.put('\n');
			output2file("Value: ", out);
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
			print("\nPress Enter to start input - (l)oad (s)ave (a)dd (q)uit or (p)rint?\n");
		}
		if (_getch() == 'p')
		{
			names2console(in,out);
		}
	}
	return 0;
}