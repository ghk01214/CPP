#ifndef _STRING
#define _STRING

class String
{
public:
	String() { std::cout << "디폴트 생성자() - 갯수 : " << num << ", 주소 : " << static_cast<void*>(p) << std::endl; };
	String(const char* str);
	~String();
public:
	String(const String& other);				// 복사생성자
	String& operator=(const String& other);		// 복사 할당연산자

	String(String&& other) noexcept;			// 이동생성자, &&는 자원이 이동됨을 의미
	String& operator=(String&& other) noexcept;	// 이동 할당연산자
public:
	void show();
public:
	size_t size() const { return num; }
public:
	String operator+(const String& rhs) const;
	friend std::ostream& operator<<(std::ostream& os, const String& s);

private:
	size_t num{};	// 저장한 글자 수
	char* p{};		// 글자가 있는 메모리
};

#endif // !_STRING