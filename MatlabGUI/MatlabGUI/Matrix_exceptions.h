#include <exception>

using std::exception;

class file_error: public exception
{

};

class matrix_is_not_square: public exception
{

};

class matrix_is_not_invertible: public exception
{

};

class incorrect_size: public exception
{

};