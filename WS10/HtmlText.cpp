/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 10
*/

#include <iostream>
#include "HtmlText.h"
#include "cstring.h"
#include "Text.h"
using namespace std;
namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title) :Text(filename){
		m_title = nullptr;
		if (filename != nullptr && title != nullptr){
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
			m_title[strLen(title)] = '\0';
			read();
		}
	}
	HtmlText::~HtmlText(){
		delete[] m_title;
		m_title = nullptr;
	}
	HtmlText::HtmlText(const HtmlText& text) :Text(text){
		if (text.m_title != nullptr){
			m_title = new char[strLen(text.m_title) + 1];
			strCpy(m_title, text.m_title);
		}
		else{
			m_title = nullptr;
		}
	}
	HtmlText& HtmlText::operator=(const HtmlText& text){
		if (this != &text && text.m_title != nullptr){
			Text::operator=(text);
			delete[] m_title;
			m_title = nullptr;
			m_title = new char[strLen(text.m_title) + 1];
			strCpy(m_title, text.m_title);
		}
		else if (this != &text && text.m_title == nullptr){
			m_title = nullptr;
		}
		return *this;
	}

	void HtmlText::write(std::ostream& ostr)const{
		bool ok = false;
		ostr << "<html><head><title>";
		if (m_title != nullptr) {
			ostr << m_title;
		}else{
			ostr << "NO Title";
		}
		ostr << "</title></head>\n<body>\n";
		if (m_title != nullptr)
			ostr << "<h1>" << m_title << "</h1>\n";

		for (int i = 0; (*this)[i] != '\0'; i++){
			switch ((*this)[i]){
			case ' ':
				if (ok == true){
					ostr << "&nbsp;";
				}
				else{
					ostr << (*this)[i];
					ok = true;
				}
				break;
			case '<':
				ostr << "&lt;";
				ok = false;
				break;

			case '>':
				ostr << "&gt;";
				ok = false;
				break;

			case '\n':
				ostr << "<br />\n";
				ok = false;
				break;
			default:
				ostr << (*this)[i];
				ok = false;
				break;
			}
		}
		ostr << "</body>\n</html>";
	}
}
