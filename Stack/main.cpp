#include <iostream>
#include <cstdio>
#include "Stack.h"

//Checking if two words are exactly the same
bool Same(const char* a, const char* b)
{
	int i = 0;

	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
		{
			return false;
		}
		i++;
	}

	//Both words must end at the same place
	if (a[i] == '\0' && b[i] == '\0')
	{
		return true;
	}

	return false;
}

//Checking if the character is a space, tab or line change
bool IsSpace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
	{
		return true;
	}

	return false;
}

//Checking if the element is a void element 
bool IsVoidElement(const char* name)
{
	const char* voids[13] = { "br", "hr", "img", "input", "meta", "link",
		"area", "base", "col", "embed", "source", "track", "wbr" };

	for (int i = 0; i < 13; i++)
	{
		if (Same(name, voids[i]))
		{
			return true;
		}
	}

	return false;
}

//Make a new copy of the word, so it can be saved in the stack
char* CopyName(const char* source)
{
	// Count the letters
	int length = 0;
	while (source[length] != '\0')
	{
		length++;
	}

	//Make room for the letters and the '\0' at the end
	char* copy = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		copy[i] = source[i];
	}
	copy[length] = '\0';

	return copy;
}

int main(int argc, char** argv)
{
	//Checking the arguments
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " file.html" << std::endl;
		return 1;
	}

	//Opening the file
	std::FILE* fp = nullptr;
	fopen_s(&fp, argv[1], "r");

	if (fp == nullptr)
	{
		std::cout << "Error opening file: " << argv[1] << std::endl;
		return 1;
	}

	Stack<char*> S;
	int errors = 0;

	//Reading the file one character at a time
	int c = std::fgetc(fp);

	while (c != EOF)
	{
		//A tag starts with '<'
		if (c == '<')
		{
			c = std::fgetc(fp);

			//Skipping spaces after '<'
			while (IsSpace(c))
			{
				c = std::fgetc(fp);
			}

			//If there is a '/', this is an end tag
			bool isEndTag = false;
			if (c == '/')
			{
				isEndTag = true;
				c = std::fgetc(fp);

				while (IsSpace(c))
				{
					c = std::fgetc(fp);
				}
			}

			//Reading the tag name, stop at space, '/' or '>'
			char name[32];
			int length = 0;

			while (c != EOF && c != '>' && c != '/' && !IsSpace(c))
			{
				//Changing big letters to small letters
				if (c >= 'A' && c <= 'Z')
				{
					c = c + 32;
				}

				if (length < 31)
				{
					name[length] = c;
					length++;
				}

				c = std::fgetc(fp);
			}
			name[length] = '\0';

			//Skiping the rest of the tag and remember the last character before '>'
			int last = 0;
			while (c != EOF && c != '>')
			{
				last = c;
				c = std::fgetc(fp);
			}

			//Skipping empty tags, <!DOCTYPE> and <!-- comments -->
			if (length > 0 && name[0] != '!')
			{
				if (isEndTag)
				{
					//End tag: take the newest start tag from the stack
					if (S.IsEmpty())
					{
						std::cout << "Error: </" << name << "> has no start tag" << std::endl;
						errors++;
					}
					else
					{
						char* top = S.Pop();

						if (!Same(top, name))
						{
							std::cout << "Error: expected </" << top << "> but found </" << name << ">" << std::endl;
							errors++;
						}

						delete[] top;
					}
				}
				else
				{
					//Void elements and tags like <br/> are not pushed
					if (!IsVoidElement(name) && last != '/')
					{
						S.Push(CopyName(name));
					}
				}
			}
		}

		//Reading the next character
		c = std::fgetc(fp);
	}

	//Closing the file
	std::fclose(fp);

	//Tags left in the stack were never closed
	while (!S.IsEmpty())
	{
		char* top = S.Pop();
		std::cout << "Error: <" << top << "> was never closed" << std::endl;
		delete[] top;
		errors++;
	}

	//Printing the result
	if (errors == 0)
	{
		std::cout << "OK: all tags are properly closed." << std::endl;
	}
	else
	{
		std::cout << errors << " error(s) found." << std::endl;
	}

	return 0;
}