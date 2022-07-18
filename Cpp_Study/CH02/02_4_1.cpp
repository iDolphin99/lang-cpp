/*
char *str1 = "ABC 123";
>>> Error : C++ 형식의 값을 사용하여 형식의 엔터티를 초기화할 수 없습니다.
>>> Why? : VS2017부터 엄격하게 표준 문법에 따라 동작하는 permissive 옵션이 기본적으로 활성화되어 있다.
>>> Solution : 이전 버전에서 표준을 무시하던 방식을 따른다 -> 프로젝트 속성 -> 준수 모드 -> 아니오 
>>> Solution : 표준 기준의 문법을 따른다 -> const 키워드 추가 or string 변수 사용 
*/
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	const char *str1 = "ABC 123";
	const char *str2 = "EFG 456";
	char str3[50];

	// 문자열 길이 계산
	cout << "strlen: " << strlen(str1) << endl;
	// 문자열 복사
	strcpy_s(str3, str1);
	cout << "strcpy: " << str3 << endl;
	// 문자열 뒤에 덧붙이기
	strcat_s(str3, str2);
	cout << "strcat: " << str3 << endl;
	// 문자열 비교, 같으면 0 다르면 1 
	if (strcmp(str3, str1)) cout << "다른 문자열입니다" << endl;
	else					cout << "같은 문자열입니다" << endl;

	return 0;
}