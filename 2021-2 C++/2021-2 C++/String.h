#ifndef _STRING
#define _STRING

class String
{
public:
	String() { std::cout << "����Ʈ ������() - ���� : " << num << ", �ּ� : " << static_cast<void*>(p) << std::endl; };
	String(const char* str);
	~String();
public:
	String(const String& other);				// ���������
	String& operator=(const String& other);		// ���� �Ҵ翬����

	String(String&& other) noexcept;			// �̵�������, &&�� �ڿ��� �̵����� �ǹ�
	String& operator=(String&& other) noexcept;	// �̵� �Ҵ翬����
public:
	void show();
public:
	size_t size() const { return num; }
public:
	String operator+(const String& rhs) const;
	friend std::ostream& operator<<(std::ostream& os, const String& s);

private:
	size_t num{};	// ������ ���� ��
	char* p{};		// ���ڰ� �ִ� �޸�
};

#endif // !_STRING