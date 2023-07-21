#include "MyVector2.h"

MyVector2 operator+(const MyVector2& obj1, const MyVector2& obj2) {
	MyVector2 tmp = {};
	tmp.x = obj1.x + obj2.x;
	tmp.y = obj1.y + obj2.y;
	return tmp;
}

MyVector2 operator-(const MyVector2& obj1, const MyVector2& obj2) {
	MyVector2 tmp = {};
	tmp.x = obj1.x - obj2.x;
	tmp.y = obj1.y - obj2.y;
	return tmp;
}

MyVector2 operator*(const MyVector2& obj, float a) {
	MyVector2 tmp = {};

	tmp.x = obj.x * a;
	tmp.y = obj.y * a;
	return tmp;
}

MyVector2 operator*(float a, const MyVector2& obj) {
	return obj * a;
}


MyVector2 operator/(const MyVector2& obj, float a) {
	MyVector2 tmp = {};

	tmp.x = obj.x / a;
	tmp.y = obj.y / a;
	return tmp;
}