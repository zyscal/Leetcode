#include <iostream>
using namespace std;
typedef struct coap_string_t {
	size_t length;    /**< length of string */
	uint8_t *s;       /**< string data */
} coap_string_t;

int
check_segment(const uint8_t *s, size_t length) {

	int n = 0;

	while (length) {
		if (*s == '%') {
			if (length < 2 || !(isxdigit(s[1]) && isxdigit(s[2])))
				return -1;

			s += 2;
			length -= 2;
		}

		++s; ++n; --length;
	}
	return n;
}
int cmdline_input(char *text, coap_string_t *buf) {
	int len;
	printf("size of test : %d\n", strlen(text));
	len = check_segment((unsigned char *)text, strlen(text));
	if (len < 0)
		return 0;
	buf->s = (unsigned char *)coap_malloc(len);
	if (!buf->s)
	{
		return 0;
	}
	buf->length = len;
	printf("buf->length : %d\n", len);
	decode_segment((unsigned char *)text, strlen(text), buf->s);
	return 1;
}
int test(char *a) {
	cout << "func test : " << sizeof(a) << endl;
	return 0;
}
int main() {
	char a[] = "1234";
	cout << sizeof(a) << endl;
	test(a);
}
