//Hunter Howell
//CIS 1202
//12/2/22


#include<iostream>
using namespace std;


class invalidCharacterExcpeption
{

};

class invalidRangeException
{

};

class caseConversionException
{

};



char character(char start, int offset)
{
   
    int AsciiVal = int(start);
    
    int character = AsciiVal + offset;


    try{
        
        if(AsciiVal < 65 || (AsciiVal > 90 && AsciiVal < 97) || AsciiVal > 122 )
        {
            throw invalidCharacterExcpeption();
        }

        
        else if(character < 65 || (character > 90 && character < 97) || character > 122 )
        {
            throw invalidRangeException();
        }

       
        else if((character >= 65 && character <= 90 && AsciiVal >= 95 && AsciiVal <= 122) || (character >= 95 && character <= 122 && AsciiVal >= 65 && AsciiVal <= 90) )
        {
            throw caseConversionException();
        }
    }

    
    catch (invalidCharacterExcpeption invalChar)
    {
        cout << " Invalid Character Exception "<<endl;
        return ' ';
    }
    catch(invalidRangeException invalRange)
    {
        cout << " Invalid Range Exception "<<endl;
        return ' ';
    }
    catch(caseConversionException caseConvert )
    {
        cout << " Invalid Case Exception; Cannot Change Lower to upper or vise versa "<<endl;
        return ' ';
    }

   
    return char(character);
}

int main()
{
    cout << character('a', 1)<<endl;
    cout << character('a', -1)<<endl;
    cout << character('Z', -1)<<endl;
    cout << character('?', 5)<<endl;
    cout << character('A', 32)<<endl;
}