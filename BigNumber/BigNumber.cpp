#include "BigNumber.hpp"
#include <cstring>
using namespace std;

BigNumber::BigNumber()
{
    number = new char[2];
    number[0] = '0';
    number[1] = '\0';
}
BigNumber::BigNumber(const char* number)
{
    int length = strlen(number);
    this->number = new char[length + 1];
    
    for (int i = 0; i < length + 1; i++)
    {
        this->number[i] = number[i];
    }
}
BigNumber::BigNumber(long long int number)
{
    int length;
    if(number < 0)
    {
        length = getNumberSize(number) + 1;
        this->number = new char[length + 1];
    
        this->number[0] = '-';
        for (int i = length - 1; i >= 1 ; i--)
        {
            this->number[i] = (-number%10) + '0';
            number /= 10;
        }
    }
    else
    {
        length = getNumberSize(number);
        this->number = new char[length + 1];
    
        for (int i = length - 1; i >= 0 ; i--)
        {
            this->number[i] = number%10 + '0';
            number /= 10;
        }
    }
    this->number[length] = '\0';     
}
BigNumber::BigNumber(const BigNumber& number)
{
    this->number = new char[strlen(number.number) + 1];
    strcpy(this->number, number.number);
}
BigNumber::~BigNumber()
{
    delete[] number;
}

BigNumber& BigNumber::operator=(const BigNumber& number)
{
    if(this != &number)
    {
        delete[] this->number;
        this->number = new char[strlen(number.number) + 1];
        strcpy(this->number, number.number);
    }

    return *this;
}
BigNumber& BigNumber::operator=(const char* number)
{
    delete[] this->number;
    this->number = new char[strlen(number) + 1];
    strcpy(this->number, number);

    return *this;
}
BigNumber& BigNumber::operator=(long long int number)
{
    int length = getNumberSize(number);
    this->number = new char[length + 1];
    
    for (int i = length - 1; i >= 0 ; i--)
    {
        this->number[i] = number%10 + '0';
        number /= 10;
    }
    this->number[length] = '\0';
    
    return *this;
}
BigNumber BigNumber::operator+(const BigNumber& number) const
{
    if(this->number[0] == '-' && number.number[0] != '-')
    {
        char* this_cpy = new char[strlen(this->number)];
        for (int i = 0; i < strlen(this->number); i++)
        {
            this_cpy[i] = this->number[i + 1];
        }
        
        return number - BigNumber(this_cpy);
    }
    if(number.number[0] == '-' && this->number[0] != '-')
    {
        char* number_cpy = new char[strlen(number.number)];
        for (int i = 0; i < strlen(number.number); i++)
        {
            number_cpy[i] = number.number[i + 1];
        }
        
        return *this - BigNumber(number_cpy);
    }
    if(this->number[0] == '-' && number.number[0] == '-')
    {
        char* number_cpy = new char[strlen(number.number)];
        char* this_cpy = new char[strlen(this->number)];
        for (int i = 0; i < strlen(number.number); i++)
        {
            number_cpy[i] = number.number[i + 1];
            this_cpy[i] = this->number[i + 1];
        }   
        BigNumber sum(BigNumber(this_cpy) + BigNumber(number_cpy));
        char* sum_cpy = new char[strlen(sum.number) + 2];
        sum_cpy[0] = '-';
        for (int i = 1; i < strlen(sum.number) + 2; i++)
        {
            sum_cpy[i] = sum.number[i - 1];
        }
        delete[] sum.number;
        sum.number = sum_cpy;
        return sum;
    }

    char* zeroed_num;
    char* other_num;
    int this_length = strlen(this->number);
    int num_length = strlen(number.number);
    int un_length;

    if(this_length >= num_length)
    {
        zeroed_num = addZeros(number.number, this_length);
        other_num = this->number;
        un_length = this_length;
    } 
    else
    {
        zeroed_num = addZeros(this->number, num_length);
        other_num = number.number;
        un_length = num_length;
    }

    char* result = new char[un_length + 1]; 
    char* result_cpy;
    int ten = 0;
    for (int i = 0; i < un_length; ++i)
    {
        char sum = zeroed_num[un_length - 1 - i] + other_num[un_length - 1 - i] - '0';
        
        if(sum + ten > '9')
        {
            result[i] = (sum - '0' + ten) % 10 + '0'; 
            ten = 1;
        }
        else 
        {
            result[i] = sum + ten;
            ten = 0;
        }
    
        if(i == un_length - 1 && sum + ten > '9')
        {
            result_cpy = new char[un_length + 2];
            strcpy(result_cpy, result);
            delete[] result;
            result = result_cpy;
            result[un_length] = ten + '0';
        }
    }
    
    for (int i = 0; i < strlen(result)/2; ++i)
    {
        swap(result[i], result[strlen(result) - i - 1]);
    }
    
    return BigNumber(result);
}
BigNumber BigNumber::operator-(const BigNumber& number) const
{
    char* num1;
    char* num2;
    int this_length = strlen(this->number);
    int num_length = strlen(number.number);
    int un_length;

    if(*this > number)
    {
        num2 = addZeros(number.number, this_length);
        num1 = this->number;
        un_length = this_length;
    } 
    else
    {
        num2 = addZeros(this->number, num_length);
        num1 = number.number;
        un_length = num_length;
    }
    
    char* result = new char[un_length + 1]; 
    char* result_cpy;
    int ten = 0;

    for (int i = 0; i < un_length; ++i)
    {
        
        char sum = num1[un_length - 1 - i] - '0' - (num2[un_length - 1 - i] - '0');
        if(sum - ten < 0)
        {
            result[i] = '0' + (10 + sum - ten) ; 
            ten = 1;
        }
        else 
        {
            result[i] = sum - ten + '0';
            ten = 0;
        }
    }
   
    if(result[un_length - 1] == '0')
    {
        int count = un_length - 1;
        for (int i = un_length - 2; i >= 0; --i)
        {
            if(result[i] == '0') --count;
            else break;
        }
        char* result_cpy = new char[count + 1];
        int i;
        for (i = 0; i < count; i++)
        {
            result_cpy[i] = result[i];
        }
        result_cpy[i] = '\0';
        delete[] result;
        result = result_cpy;
    }

    for (int i = 0; i < strlen(result)/2; i++)
    {
        swap(result[i], result[strlen(result) - i - 1]);
    }
    
    if(*this < number)
    {
        char* result_cpy = new char[strlen(result) + 2];
        
        result_cpy[0] = '-';
        int i;
        for (i = 1; i < strlen(result) + 2; i++)
        {
            result_cpy[i] = result[i - 1];
        }
        delete[] result;
        result = result_cpy;
    }

    return BigNumber(result);
}
BigNumber BigNumber::operator*(const BigNumber& number)
{
    int ten = 0;
    int multiplier = 1;
    BigNumber sum;
    for (int i = 0; i < strlen(this->number); i++)
    {
    
    }
    
}

bool BigNumber::operator==(const BigNumber& number) const
{
    return !strcmp(this->number, number.number);
}
bool BigNumber::operator!=(const BigNumber& number) const
{
    return strcmp(this->number, number.number);
}
bool BigNumber::operator<(const BigNumber& number) const
{
    if(this->number[0] == '-' && number.number[0] != '-') return true;
    if(number.number[0] == '-' && this->number[0] != '-') return false;

    if(this->number[0] == '-' && number.number[0] == '-')
    {
        if(strlen(this->number) > strlen((number.number))) 
        {
            return true;
        }
        else if(strlen(this->number) < strlen((number.number))) 
        {
            return false;
        }
        else
        {
            for (int i = 1; i < strlen(this->number); i++)
            {
                if(this->number[i] < number.number[i] && this->number[i - 1] == number.number[i - 1] && i != 1) 
                {
                    return false;
                }
            }
        }
    }
    else
    {
        if(strlen(this->number) > strlen((number.number))) 
        {
            return false;
        }
        else if(strlen(this->number) < strlen((number.number))) 
        {
            return true;
        }
        else
        {
            for (int i = 0; i < strlen(this->number); i++)
            {
                if(this->number[i] > number.number[i] && this->number[i - 1] == number.number[i - 1]) 
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}
bool BigNumber::operator>(const BigNumber& number) const
{
    if(this->number[0] == '-' && number.number[0] != '-') return true;
    if(number.number[0] == '-' && this->number[0] != '-') return false;

    if(this->number[0] == '-' && number.number[0] == '-')
    {
        if(strlen(this->number) > strlen((number.number))) 
        {
            return false;
        }
        else if(strlen(this->number) < strlen((number.number))) 
        {
            return true;
        }
        else
        {
            for (int i = 1; i < strlen(this->number); i++)
            {
                if(this->number[i] > number.number[i] && this->number[i - 1] == number.number[i - 1] && i != 1) 
                {
                    return false;
                }
            }
        }
    }
    else
    {
        if(strlen(this->number) > strlen((number.number))) 
        {
            return true;
        }
        else if(strlen(this->number) < strlen((number.number))) 
        {
            return false;
        }
        else
        {
            for (int i = 0; i < strlen(this->number); i++)
            {
                if(this->number[i] < number.number[i] && this->number[i - 1] == number.number[i - 1]) 
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int getNumberSize(long long int number)
{
    int count = 1;
    while(number / 10 != 0)
    {
        count++;
        number /= 10;
    }

    return count;
}
ostream& operator<<(ostream& os, const BigNumber& number)
{
    os << number.number;
    return os;
}

char* addZeros(const char* source, int futureSize)
{
    
    char* cpy = new char[futureSize + 1];
    int i, k;
    for (i = 0, k = 0; i < futureSize + 1; i++)
    {
        if(i >= futureSize - strlen(source))
        {
            cpy[i] = source[k];
            ++k;
        }
        else cpy[i] = '0';
    }
    cpy[i] = '\0';
    return cpy;
}