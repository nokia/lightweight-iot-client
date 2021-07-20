file(REMOVE_RECURSE
  "examples/shared/tinydtls/tinydtls.h"
  "examples/shared/tinydtls/dtls.h"
  "examples/shared/tinydtls/dtls.c"
  "examples/shared/tinydtls/crypto.c"
  "examples/shared/tinydtls/ccm.c"
  "examples/shared/tinydtls/hmac.c"
  "examples/shared/tinydtls/dtls_debug.c"
  "examples/shared/tinydtls/netq.c"
  "examples/shared/tinydtls/peer.c"
  "examples/shared/tinydtls/dtls_time.c"
  "examples/shared/tinydtls/session.c"
  "examples/shared/tinydtls/aes/rijndael.c"
  "examples/shared/tinydtls/sha2/sha2.c"
  "examples/shared/tinydtls/ecc/ecc.c"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/submodule_update.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
