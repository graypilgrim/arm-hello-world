volatile unsigned int * const UART0DR = (unsigned int *)0x101f1000;
volatile unsigned int * const FAKE_DEV = (unsigned int *)0x10030000;

void print_uart0(const char *s)
{
	while(*s != '\0') {
		*UART0DR = (unsigned int)(*s);
		s++;
	}
}

void test_fake_dev(long long val)
{
	*FAKE_DEV = val;
	*UART0DR = (unsigned int)(*FAKE_DEV);
}

typedef struct {
    unsigned int word0;
    unsigned int word1;
    unsigned int word2;
    unsigned int word3;
} SpWTransmitDescriptor;

SpWTransmitDescriptor desc;

void create_descriptor()
{
	desc.word0 = 13;
	desc.word1 = 2000000;
	desc.word2 = 0;
	desc.word3 = 0;
	unsigned long *ptr = &desc;
	*FAKE_DEV = ptr;
}

void c_entry() {
	//long long val = 'Y';
	//*UART0DR = (unsigned int)(val);
	//test_fake_dev(val);
	create_descriptor();
}
