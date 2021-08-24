#pragma once

class tabD
{
	int n;
	char* a;

	void init(int n);
	void fill(char ch = 0, const char* tab = nullptr);

public:
	// constructors
	tabD() : n(0), a(nullptr) {}
	explicit tabD(int n, char ch = 0) { init(n); fill(ch); }
	tabD(int n, const char* tab) { init(n); fill(0, tab); }
	tabD(char ch) { init(1); fill(ch); }
	tabD(const tabD& t) { init(t.n); fill(0, t.a); }

	//useful garbage
	void print();
	int size() const { return n; }
	tabD& operator=(const tabD& t);
	char& operator[](int i) const { return a[i]; }

	friend bool operator==(const tabD& t1, const tabD& t2);
	friend bool operator!=(const tabD& t1, const tabD& t2);

	friend tabD operator+(const tabD& t1, const tabD& t2);
	tabD& operator+=(const tabD& t1);

	friend std::ostream& operator<<(std::ostream& out, const tabD& t);
	friend std::istream& operator>>(std::istream& in, tabD& t);

	~tabD() { delete[] a; }
};