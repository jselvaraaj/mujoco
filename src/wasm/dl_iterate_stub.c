/* src/wasm/dl_iterate_stub.c */
#ifdef __EMSCRIPTEN__
#include <link.h>
int dl_iterate_phdr(int (*)(struct dl_phdr_info*, size_t, void*), void*) {
  /* no shared libs on the web → nothing to iterate over */
  return 0;
}
#endif
