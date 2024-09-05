#include "../MacAddrChanger/MacChange.h"

int main(int argc, char const *argv[])
{

    (void)argc;
    (void)argv;

    MacAddr_t MacAddr = GenerateRandomAddr();
    printf("%016llx\n" , MacAddr.addr);
    return 0;
}
