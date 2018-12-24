#include <string.h>
#include <iostream>
#include "md5.h" 
#define WASM_EXPORT __attribute__((visibility("default")))

using namespace std;

static string MDPrint (MD5_CTX *mdContext)
{
  int i;
  string res;

  for (i = 0; i < 16; i++) {
    char *bla;
    asprintf(&bla, "%02x", mdContext->digest[i]);
    res += bla;
    free(bla);
  }

  return res;
}

WASM_EXPORT
string MDString(const char *inString)
{
  MD5_CTX mdContext;
  unsigned int len = strlen (inString);

  MD5Init (&mdContext);
  MD5Update (&mdContext, (unsigned char *)inString, len);
  MD5Final (&mdContext);

  return MDPrint (&mdContext);
}

WASM_EXPORT
int main(){ return 1; }