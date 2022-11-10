/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 10
*/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
namespace sdds {
    class Text {
        char* m_filename;
        char* m_content;
        int getFileLength()const;
    protected:
        const char& operator[](int index)const;
    public:
        Text(const char* filename = nullptr);
        ~Text();
        Text(const Text& text);
        Text& operator=(const Text& text);
        void read();
        virtual void write(std::ostream& os)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Text& text);
}
#endif // !SDDS_PERSON_H__
