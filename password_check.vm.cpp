#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "advapi32.lib")

static const char* __vm_xstr(const unsigned char* enc, unsigned n, unsigned key) {
  
  thread_local std::unordered_map<const unsigned char*, char*> tls_cache;
  auto it = tls_cache.find(enc);
  if (it != tls_cache.end()) return it->second;
  char* buf = (char*)std::malloc((size_t)n + 1);
  if (!buf) return "";
  for (unsigned p = 0; p <= n; ++p) {
    unsigned char k = (unsigned char)(key ^ (unsigned char)(p * 17u) ^ (unsigned char)(n * 131u));
    buf[p] = (char)(enc[p] ^ k);
  }
  tls_cache.emplace(enc, buf);
  return buf;
}

struct __vm_alloc_entry { void* ptr; void(*dtor)(void*); };
static thread_local std::vector<__vm_alloc_entry> __vm_alloc_list;
static void __vm_alloc_push(void* p, void(*d)(void*)) {
  __vm_alloc_list.push_back({p, d});
}
static void __vm_alloc_cleanup(size_t mark) {
  while (__vm_alloc_list.size() > mark) {
    auto& e = __vm_alloc_list.back();
    if (e.dtor) e.dtor(e.ptr);
    __vm_alloc_list.pop_back();
  }
}
static void __vm_alloc_detach(void* p) {
  if (!p) return;
  for (size_t i = 0; i < __vm_alloc_list.size(); ++i) {
    if (__vm_alloc_list[i].ptr == p) {
      __vm_alloc_list[i].dtor = nullptr;
      __vm_alloc_list[i].ptr = nullptr;
      __vm_alloc_list[i] = __vm_alloc_list.back();
      __vm_alloc_list.pop_back();
      return;
    }
  }
}
struct __vm_alloc_guard {
  size_t mark;
  explicit __vm_alloc_guard(size_t m) : mark(m) {}
  ~__vm_alloc_guard() { __vm_alloc_cleanup(mark); }
  __vm_alloc_guard(const __vm_alloc_guard&) = delete;
  __vm_alloc_guard& operator=(const __vm_alloc_guard&) = delete;
};




int main();

#include <windows.h>
#include <iostream>
#include <string>
#include <cstring>

/* VM-obfuscated function removed: main */




int main();

int main();

long long __vm_native_0(long long* args, unsigned argc);
long long __vm_native_1(long long* args, unsigned argc);
long long __vm_native_2(long long* args, unsigned argc);
long long __vm_native_3(long long* args, unsigned argc);
long long __vm_native_4(long long* args, unsigned argc);
long long __vm_native_5(long long* args, unsigned argc);
long long __vm_native_6(long long* args, unsigned argc);
long long __vm_native_7(long long* args, unsigned argc);
long long __vm_native_8(long long* args, unsigned argc);
long long __vm_native_9(long long* args, unsigned argc);
long long __vm_native_10(long long* args, unsigned argc);

namespace vm_main_int___a100e2bc_mod_code {
static const unsigned char enc[] = {
  0x47,0xa8,0xde,0x94,0xbf,0xb2,0x81,0xd9,0x04,0x22,0xb3,0xe3,0xfc,0x38,0xb3,0xb9,
  0x2a,0xdc,0xf8,0x4b,0x54,0xcf,0xe7,0x10,0x48,0xb3,0x77,0x1a,0x2a,0x39,0xa1,0x54,
  0x41,0x31,0x4b,0x58,0x2f,0x14,0xce,0x9f,0x88,0xd9,0xc1,0xb7,0x31,0xc4,0x75,0x34,
  0xfc,0xf1,0x2e,0xb9,0x7e,0xab,0x2d,0xd9,0x53,0x1f,0x91,0x51,0xd8,0x89,0x09,0x1c,
  0x4f,0x66,0x6c,0x6d,0xe6,0x31,0x46,0x2a,0xf0,0xc8,0x0f,0x96,0x8f,0x47,0xab,0xd2,
  0xc3,0x1c,0xa9,0x9a,0xef,0x8b,0x6b,0x18,0x21,0x99,0x24,0x8b,0x5e,0xf4,0xe4,0x0d,
  0x27,0x02,0xab,0x6b,0x19,0x8e,0xb0,0x7b,0xe8,0x32,0x4c,0xa0,0xa5,0x74,0x1e,0x84,
  0x3c,0xb8,0x6b,0x8f,0x56,0x5a,0xec,0x15,0xaf,0x05,0x18,0x15,0x5d,0xde,0x60,0xe2,
  0x0a,0x39,0xf8,0xf1,0x47,0x07,0xda,0xd3,0xc4,0x38,0xe3,0xb7,0xfe,0x07,0x6c,0xdb,
  0x35,0xf0,0x52,0xc1,0x63,0x16,0xec,0xf9,0x7b,0xc5,0xf5,0x1a,0xfd,0xc0,0x8f,0xc1,
  0xe0,0xad,0xbe,0x54,0x80,0x1f,0xb6,0x7e,0xb3,0x1a,0xce,0x8e,0x80,0x17,0xcf,0x76,
  0x1a,0xae,0xb5,0x8e,0xde,0xae,0x90,0x1c,0x71,0x41,0xfb,0x56,0x62,0x77,0xa7,0xa3,
  0x73,0x13,0xcf,0x0a,0xd9,0x2a,0x7c,0x52,0xb1,0x58,0x94,0x22,0x16,0x87,0x65,0xc4,
  0x53,0x35,0xd4,0xe4,0xe6,0x80,0xd9,0x33,0x86,0x51,0x30,0x33,0xd7,0x1c,0xd4,0x12,
  0xa8,0x14,0x31,0xe6,0x4c,0x54,0xb4,0x89,0x4b,0x43,0x91,0x0b
};
static const unsigned len = 236;
static const unsigned long long expect_sum = 4449501901441110250ULL;
}
namespace vm_main_int___a100e2bc_mod_keys {
static const unsigned char xorkey = 71;
static const unsigned char hx = 237;
static const unsigned long long ss = 9820601900338963259ULL;
static const unsigned long long rk = 4361248787970692374ULL;
static const unsigned long long fs = 3259810128995748293ULL;
static const unsigned long long dc = 11968695296621755762ULL;
}
namespace vm_main_int___a100e2bc_mod_map {
static const unsigned char dec[256] = {
  255,255,255,255,255,255,255,255,255,48,255,255,255,30,255,255,
  21,255,255,255,255,255,255,255,31,255,255,47,255,255,35,255,
  255,255,255,255,28,255,255,255,255,29,255,255,36,255,255,32,
  255,255,255,255,255,255,255,255,255,2,255,255,5,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,25,255,255,255,255,255,255,255,26,255,255,255,
  46,1,255,255,49,11,255,255,255,255,255,4,255,255,255,255,
  255,13,255,42,255,255,255,255,45,255,255,255,255,255,255,255,
  255,255,255,255,18,255,255,255,20,255,255,255,41,255,255,255,
  255,255,16,23,255,255,255,255,27,255,255,255,255,255,255,3,
  40,0,255,7,255,10,255,255,255,9,255,12,39,255,43,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,24,255,
  255,255,22,33,14,255,255,255,255,255,255,255,44,37,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,8,17,255,255,255,15,255,255,255,255,255,255,
  255,6,255,255,19,255,255,255,255,255,34,38,255,255,255,255
};
}
namespace vm_main_int___a100e2bc_mod_data {
static const long long iconst[] = {0LL,1LL};
static const double fconst[] = {0.0};
static const unsigned char s_0[] = {
  27,54,16,95,104,60,80,31,165,163,155,221,224,240,146,214,
  78
};
static const unsigned char s_1[] = {
  168,168,130,203,170,173,141,153,57,63,111
};
static const unsigned char* strs_enc[] = {s_0, s_1};
static const unsigned strs_len[] = {16, 10};
static const unsigned strs_count = 2;
static const unsigned char str_key = 71;
static const unsigned str_seed = 1308691993u;
}
static const char* vm_main_int___a100e2bc_str_get(unsigned idx) {
  
  thread_local std::vector<char*> cache;
  if (idx >= vm_main_int___a100e2bc_mod_data::strs_count) return "";
  if (cache.size() < vm_main_int___a100e2bc_mod_data::strs_count)
    cache.resize(vm_main_int___a100e2bc_mod_data::strs_count, nullptr);
  if (cache[idx]) return cache[idx];
  unsigned n = vm_main_int___a100e2bc_mod_data::strs_len[idx];
  char* buf = (char*)std::malloc(n + 1);
  if (!buf) return "";
  const unsigned char* enc = vm_main_int___a100e2bc_mod_data::strs_enc[idx];
  unsigned char sk = vm_main_int___a100e2bc_mod_data::str_key;
  unsigned seed = vm_main_int___a100e2bc_mod_data::str_seed;
  for (unsigned p = 0; p <= n; ++p) {
    unsigned char k = (unsigned char)(sk ^ (unsigned char)(idx * 131u) ^ (unsigned char)(p * 17u)
      ^ (unsigned char)(seed >> ((p & 3) * 8)));
    buf[p] = (char)(enc[p] ^ k);
  }
  cache[idx] = buf;
  return buf;
}

namespace vm_main_int___a100e2bc_mod_junk {
static volatile unsigned char blob[1388] = {
  23,119,142,65,203,234,75,89,138,209,193,157,222,179,3,20,
  129,198,194,16,131,178,4,59,149,201,242,117,157,191,38,0,
  83,249,98,237,151,137,179,155,39,192,24,89,239,148,141,1,
  185,16,240,140,24,133,233,221,76,49,100,115,118,255,147,116,
  176,156,199,63,177,57,221,162,223,184,165,38,190,108,178,243,
  227,74,0,39,177,169,40,243,52,96,181,255,228,232,17,90,
  107,167,106,190,224,123,75,147,110,134,27,228,233,84,85,6,
  92,169,99,118,52,206,228,205,48,33,222,190,72,100,85,27,
  94,66,69,191,105,157,118,95,37,56,171,125,77,155,155,80,
  146,37,175,202,237,34,224,107,10,206,224,143,83,25,225,146,
  49,172,79,118,77,109,63,232,152,225,54,172,26,217,168,221,
  251,246,57,166,193,157,150,68,7,48,248,100,2,133,161,224,
  124,61,160,79,237,104,2,239,129,164,9,113,100,186,62,244,
  132,107,173,28,207,34,38,113,43,105,189,194,113,2,191,186,
  163,66,6,125,221,213,105,124,253,141,130,181,29,114,34,140,
  252,6,18,217,55,40,139,168,27,203,231,85,49,69,194,12,
  220,152,146,206,247,43,161,107,196,64,191,36,177,247,110,200,
  243,213,240,98,66,156,135,104,230,84,22,232,202,102,209,157,
  26,217,230,48,109,69,6,121,17,202,29,142,190,156,37,50,
  62,150,64,200,225,30,62,171,163,207,235,51,16,0,107,53,
  69,175,232,26,243,7,215,101,173,148,141,1,17,74,188,156,
  142,110,120,51,101,133,187,193,131,157,80,176,61,69,66,174,
  74,184,70,182,171,10,130,151,205,205,229,80,192,69,159,39,
  207,250,190,196,239,70,107,171,211,160,102,172,254,59,165,143,
  70,17,78,67,201,190,182,61,11,126,255,87,87,167,115,147,
  0,19,249,124,221,105,4,192,95,14,99,27,189,214,59,10,
  101,59,230,231,251,175,152,187,226,54,28,5,8,132,41,218,
  253,201,13,27,163,224,34,140,128,25,182,67,182,31,10,38,
  77,250,252,101,246,168,231,225,77,6,146,4,192,163,113,10,
  78,233,251,61,85,234,63,2,17,165,26,63,253,122,228,231,
  11,50,192,212,253,104,116,98,55,182,72,179,168,206,147,11,
  198,145,226,162,65,80,116,119,152,245,68,222,12,155,68,43,
  125,244,105,223,93,202,145,99,185,15,230,78,229,3,97,202,
  5,191,63,195,15,171,121,53,114,29,104,252,153,49,87,187,
  90,241,114,78,60,194,47,136,49,247,133,229,143,180,39,245,
  27,76,179,83,99,51,204,165,103,15,56,188,101,185,94,119,
  244,75,12,207,149,5,250,178,6,207,138,154,10,145,183,9,
  249,182,244,233,129,181,1,209,64,131,16,45,49,101,173,114,
  170,219,31,159,53,232,108,12,41,137,11,163,73,13,116,39,
  247,82,135,45,118,25,172,232,138,70,93,207,172,183,16,83,
  137,205,83,20,238,250,173,4,253,198,116,21,242,57,152,210,
  234,105,252,190,191,0,35,44,58,75,80,114,221,72,225,169,
  42,195,231,110,28,84,250,122,90,151,85,105,213,195,48,134,
  107,37,36,26,52,51,71,78,205,34,2,244,114,45,157,86,
  14,101,5,191,196,223,210,0,176,115,137,162,3,216,138,16,
  76,240,126,67,96,212,79,201,160,218,156,33,26,89,168,206,
  249,239,35,234,136,82,70,223,179,203,225,82,188,232,96,26,
  119,4,162,110,203,245,193,202,11,49,247,243,213,110,70,112,
  162,242,54,175,20,25,238,39,175,249,85,208,70,217,19,196,
  1,54,46,12,207,13,8,33,196,190,178,216,33,35,111,86,
  21,67,141,211,215,208,246,142,111,36,212,109,103,76,40,213,
  239,93,79,162,71,64,213,54,171,180,27,50,231,202,181,60,
  232,33,56,154,59,28,126,207,3,62,24,233,117,183,128,206,
  238,93,111,221,174,84,115,89,233,5,226,131,228,17,152,84,
  121,217,87,18,121,169,71,5,101,233,176,122,102,183,86,178,
  158,140,207,129,194,72,86,5,40,119,157,162,52,186,241,206,
  200,79,26,238,78,234,200,210,123,1,252,182,109,27,54,85,
  20,145,88,156,20,139,193,20,168,90,32,227,135,51,137,241,
  123,234,205,176,31,149,192,18,113,82,234,166,129,146,58,43,
  255,106,248,77,73,10,168,130,254,32,202,72,31,60,27,137,
  51,45,43,172,119,245,153,110,78,178,37,115,2,219,254,91,
  26,211,203,206,138,0,104,242,224,169,101,182,28,110,198,103,
  181,180,176,176,150,115,50,234,151,216,2,118,18,5,202,104,
  211,13,46,14,138,243,142,47,154,5,66,96,92,74,19,18,
  221,100,29,53,27,91,255,1,60,15,143,180,11,202,57,215,
  15,3,177,30,148,29,69,33,23,214,118,91,83,167,221,239,
  173,61,3,215,162,17,181,50,58,172,141,117,117,150,56,214,
  251,51,251,192,133,194,78,155,119,150,183,192,8,144,61,153,
  51,45,223,230,163,11,226,179,234,142,167,61,142,25,252,115,
  123,99,144,180,229,26,236,98,217,199,193,208,170,226,4,218,
  206,155,27,38,199,61,97,233,184,225,159,209,81,92,99,71,
  136,23,45,104,131,3,68,156,28,182,198,158,218,62,216,182,
  235,7,246,18,216,83,133,186,105,236,129,108,199,184,4,2,
  56,163,252,95,139,230,248,232,44,22,209,99,192,172,218,158,
  201,78,67,219,110,74,228,65,103,136,96,78,55,84,189,153,
  156,199,24,214,94,65,96,137,239,132,252,249,41,200,32,242,
  109,217,100,132,186,110,115,122,202,229,150,230,13,105,217,244,
  24,22,175,199,164,141,173,33,163,3,162,160,16,95,207,137,
  162,253,36,240,22,184,131,196,20,244,140,126,122,26,51,146,
  247,118,31,131,161,218,99,67,104,122,106,45,211,156,230,170,
  121,190,135,58,99,50,118,52,67,115,62,125,81,246,212,49,
  21,253,101,73,162,100,162,147,197,160,194,0,189,42,238,70,
  13,111,20,229,160,219,168,121,159,162,187,49,194,179,249,207,
  153,191,67,194,180,38,92,188,83,253,162,187,10,195,24,245,
  135,155,205,121,39,221,234,22,137,159,90,209,155,15,86,180,
  241,75,38,55,226,143,185,61,32,45,18,192,123,219,145,150,
  106,178,95,42,225,233,82,100,24,194,46,117
};
static volatile unsigned long long opaque = 3989286123ULL;
}

static long long vm_main_int___a100e2bc_host(unsigned id, long long* args, unsigned argc);
static inline unsigned long long vm_main_int___a100e2bc_mix(unsigned long long x) {
  x ^= x >> 33; x *= 0xff51afd7ed558ccdULL; x ^= x >> 33;
  x *= 0xc4ceb9fe1a85ec53ULL; x ^= x >> 33; return x;
}
static inline unsigned char vm_main_int___a100e2bc_bc_ks(size_t pos) {
  auto x=vm_main_int___a100e2bc_mix(pos*0x9E3779B97F4A7C15ULL+vm_main_int___a100e2bc_mod_keys::ss);
  return (unsigned char)(x^(x>>8)^(x>>16)^(x>>24));
}
static inline unsigned char vm_main_int___a100e2bc_ks2(size_t pos, unsigned long long rt) {
  
  auto x=vm_main_int___a100e2bc_mix(pos*0xC2B2AE3D27D4EB4FULL^rt);
  return (unsigned char)(x^(x>>7)^(x>>21));
}
static inline unsigned long long vm_main_int___a100e2bc_regkey(int r, unsigned long long frame) {
  return vm_main_int___a100e2bc_mix((unsigned long long)r*0x9E3779B97F4A7C15ULL+vm_main_int___a100e2bc_mod_keys::rk^frame);
}
static inline unsigned long long vm_main_int___a100e2bc_ptr_enc(unsigned long long p, unsigned long long k) {
  return p ^ vm_main_int___a100e2bc_mix(k ^ 0x504E5452ULL) ^ (k << 3);
}
static inline unsigned long long vm_main_int___a100e2bc_ptr_dec(unsigned long long e, unsigned long long k) {
  return e ^ vm_main_int___a100e2bc_mix(k ^ 0x504E5452ULL) ^ (k << 3);
}
static inline int vm_main_int___a100e2bc_opq_t(unsigned long long x) {
  unsigned long long a=x^(x<<13); a^=a>>7; a^=a<<17; return (int)(a|1ULL);
}
static inline int vm_main_int___a100e2bc_opq_f(unsigned long long x) {
  unsigned long long a=x*0x9E3779B97F4A7C15ULL; return (int)(a^a);
}
static inline int vm_main_int___a100e2bc_opq_ctx_t(unsigned long long hist, unsigned long long cookie) {
  
  unsigned long long h2 = vm_main_int___a100e2bc_mix(hist ^ cookie);
  unsigned long long z = hist ^ vm_main_int___a100e2bc_mix(hist);
  return (int)((z == 0ULL) | ((h2 | 1ULL) != 0ULL));
}
static inline int vm_main_int___a100e2bc_opq_ctx_f(unsigned long long hist, unsigned long long cookie) {
  
  unsigned long long z = hist ^ vm_main_int___a100e2bc_mix(hist ^ (cookie & 0ULL));
  return (int)((z != 0ULL) & 0);
}
static unsigned long long vm_main_int___a100e2bc_nested_arith(int kind, unsigned long long a, unsigned long long b) {
  
  switch (kind & 3) {
  case 0: return (unsigned long long)((a)+(b));
  case 1: return (unsigned long long)((a)-(b));
  case 2: return (unsigned long long)(((a)|(b))-((a)&(b)));
  default: return a * b;
  }
}
static unsigned long long vm_main_int___a100e2bc_alu_mix(int kind, unsigned long long a, unsigned long long b, unsigned long long dyn) {
  
  unsigned sel = (unsigned)(dyn ^ (dyn >> 17) ^ (dyn >> 33)) & 3u;
  unsigned long long r0 = vm_main_int___a100e2bc_nested_arith(kind, a, b);
  if (sel == 0) return r0;
  if (sel == 1) return vm_main_int___a100e2bc_nested_arith(kind, a, b) ^ (dyn & 0ULL);
  if (sel == 2) {
    unsigned long long t = vm_main_int___a100e2bc_nested_arith(kind, a, b);
    return (t | (dyn & 0ULL)) + (dyn & 0ULL);
  }
  return r0 ^ ((vm_main_int___a100e2bc_mix(dyn) ^ vm_main_int___a100e2bc_mix(dyn)) & 0ULL);
}
namespace vm_main_int___a100e2bc_l2 {
static const unsigned char xorkey = 63;
static const unsigned long long stream = 2575040643ULL;
static const unsigned char dec[256] = {
  255,255,255,255,255,255,255,255,255,255,4,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,1,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,7,255,
  255,255,255,255,3,255,255,5,255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,255,2,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,0,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,6,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
};
static const unsigned char code[] = {
  0x60,0xde,0x4e,0xe9,0x9f,0xce,0xa9,0xc9,0xcc,0x1,0x29,0xa2
};
static const unsigned len = 12;
enum { OP_NOP=0, OP_KEY_ROT=1, OP_CTX_MIX=2, OP_ENTER_L1=3, OP_EXIT=4, OP_VR_IMM=5, OP_VR_XOR=6, OP_OPAQUE=7 };
}
static inline unsigned char vm_main_int___a100e2bc_l2_ks(unsigned pos, unsigned long long key) {
  return (unsigned char)((key >> ((pos * 7) & 63)) ^ (pos * 131u) ^ vm_main_int___a100e2bc_l2::xorkey);
}
static inline void vm_main_int___a100e2bc_l2_vr_scramble(unsigned long long* vr, int n, unsigned long long key) {
  for (int i = 0; i < n; ++i) vr[i] ^= vm_main_int___a100e2bc_mix(key + (unsigned long long)i * 0x9E3779B97F4A7C15ULL);
}
struct vm_main_int___a100e2bc_Ctx;
using vm_main_int___a100e2bc_Handler = void(*)(vm_main_int___a100e2bc_Ctx*);
struct vm_main_int___a100e2bc_Ctx {
  unsigned char* code; unsigned len; unsigned pc;
  unsigned char op; int state; long long retv; int done; int uncaught;
  unsigned long long* regs; unsigned long long* stack; int* sp;
  unsigned long long frame; unsigned long long cookie; unsigned long long rt_key;
  unsigned long long* stack_enc; 
  int steps; unsigned long long running_sum;
  unsigned long long hist;      
  unsigned long long dyn_salt;  
  unsigned win_seg;             
  unsigned seg_size;
  int call_depth;               
  unsigned long long stack_canary;
  unsigned long long mem_tag;   
  vm_main_int___a100e2bc_Handler* htab; int htab_n;
  long long (*host)(unsigned,long long*,unsigned);
};
#include <thread>
#include <atomic>
#include <chrono>
static void vm_main_int___a100e2bc_thread_decoy(std::atomic<unsigned long long>* lane, std::atomic<int>* run, unsigned long long seed) {
  unsigned long long st = seed; int phase = (int)(seed & 7ULL);
  while (run->load(std::memory_order_relaxed)) {
    switch (phase & 7) {
    case 0: st = vm_main_int___a100e2bc_mix(st + 0x9E37); phase = 1; break;
    case 1: st = vm_main_int___a100e2bc_mix(st ^ lane->load(std::memory_order_relaxed)); phase = 2; break;
    case 2: st = vm_main_int___a100e2bc_mix(st * 0xBF58 + 1); phase = 3; break;
    case 3: phase = 4; break;
    case 4: lane->store(st, std::memory_order_relaxed); phase = 5; break;
    case 5: phase = 6; break;
    case 6: phase = 0; break;
    default: phase = 0; break;
    }
    if ((st & 0xFFULL) == 0) std::this_thread::yield();
  }
  lane->store(vm_main_int___a100e2bc_mix(st), std::memory_order_relaxed);
}
static int vm_main_int___a100e2bc_anti_emu_tick() {
  using clock = std::chrono::high_resolution_clock;
  auto t0 = clock::now();
  volatile unsigned long long x = vm_main_int___a100e2bc_mod_keys::dc;
  for (int i=0;i<64;++i) x = vm_main_int___a100e2bc_mix(x+i);
  auto t1 = clock::now();
  auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count();
  
  return (int)((x & 1ULL) | (us >= 0 ? 1 : 0));
}
static inline unsigned char vm_main_int___a100e2bc_seg_key(unsigned seg, unsigned long long ss) {
  auto x = vm_main_int___a100e2bc_mix(ss ^ ((unsigned long long)seg * 0x9E3779B97F4A7C15ULL) ^ 0x5345474DULL);
  return (unsigned char)(x ^ (x >> 8) ^ (x >> 16));
}
static inline void vm_main_int___a100e2bc_seg_apply(vm_main_int___a100e2bc_Ctx* C, unsigned seg) {
  if (C->seg_size == 0) return;
  unsigned lo = seg * C->seg_size;
  if (lo >= C->len) return;
  unsigned hi = lo + C->seg_size; if (hi > C->len) hi = C->len;
  unsigned char k = vm_main_int___a100e2bc_seg_key(seg, vm_main_int___a100e2bc_mod_keys::ss);
  for (unsigned i = lo; i < hi; ++i) C->code[i] = (unsigned char)(C->code[i] ^ k);
}
static inline void vm_main_int___a100e2bc_seg_open_pair(vm_main_int___a100e2bc_Ctx* C, unsigned base, unsigned nseg) {
  if (base >= nseg) base = nseg - 1;
  C->win_seg = base;
  vm_main_int___a100e2bc_seg_apply(C, C->win_seg);
  if (C->win_seg + 1 < nseg) vm_main_int___a100e2bc_seg_apply(C, C->win_seg + 1);
}
static inline void vm_main_int___a100e2bc_seg_close_pair(vm_main_int___a100e2bc_Ctx* C, unsigned nseg) {
  vm_main_int___a100e2bc_seg_apply(C, C->win_seg);
  if (C->win_seg + 1 < nseg) vm_main_int___a100e2bc_seg_apply(C, C->win_seg + 1);
}
static inline int vm_main_int___a100e2bc_seg_covers(vm_main_int___a100e2bc_Ctx* C, unsigned seg) {
  return (seg == C->win_seg || seg == C->win_seg + 1);
}
static inline void vm_main_int___a100e2bc_seg_ensure_range(vm_main_int___a100e2bc_Ctx* C, unsigned pc_lo, unsigned pc_hi) {
  if (C->seg_size == 0 || C->len == 0) return;
  if (pc_hi >= C->len) pc_hi = C->len - 1;
  if (pc_lo > pc_hi) pc_lo = pc_hi;
  unsigned nseg = (C->len + C->seg_size - 1) / C->seg_size;
  unsigned s0 = pc_lo / C->seg_size;
  unsigned s1 = pc_hi / C->seg_size;
  if (s0 >= nseg) s0 = nseg - 1;
  if (s1 >= nseg) s1 = nseg - 1;
  
  if (s1 - s0 <= 1u && vm_main_int___a100e2bc_seg_covers(C, s0) && vm_main_int___a100e2bc_seg_covers(C, s1)) return;
  
  vm_main_int___a100e2bc_seg_close_pair(C, nseg);
  vm_main_int___a100e2bc_seg_open_pair(C, s0, nseg);
  
  if (!vm_main_int___a100e2bc_seg_covers(C, s1)) {
    vm_main_int___a100e2bc_seg_close_pair(C, nseg);
    vm_main_int___a100e2bc_seg_open_pair(C, s1 > 0 ? s1 - 1 : s1, nseg);
  }
}
static inline void vm_main_int___a100e2bc_seg_ensure(vm_main_int___a100e2bc_Ctx* C, unsigned pc) {
  vm_main_int___a100e2bc_seg_ensure_range(C, pc, pc);
}
static void vm_main_int___a100e2bc_H_nop(vm_main_int___a100e2bc_Ctx* C){ (void)C; }
static void vm_main_int___a100e2bc_H_fetch(vm_main_int___a100e2bc_Ctx* C){
  if (C->pc >= C->len) { C->state = 579700; return; }
  
  vm_main_int___a100e2bc_seg_ensure(C, C->pc);
  unsigned char w = C->code[C->pc];
  C->pc++;
  
  unsigned long long dyn = vm_main_int___a100e2bc_mix(C->rt_key ^ C->cookie ^ C->hist ^ (unsigned long long)C->pc ^ (unsigned long long)C->steps);
  C->dyn_salt = dyn;
  
  unsigned char wired = (unsigned char)(w ^ vm_main_int___a100e2bc_mod_keys::hx);
  
  unsigned char scrub = (unsigned char)(dyn ^ (dyn >> 8));
  unsigned char logical = vm_main_int___a100e2bc_mod_map::dec[(unsigned char)(wired ^ scrub ^ scrub)];
  
  if (((++C->steps) & 31) == 0) C->cookie = vm_main_int___a100e2bc_mix(C->cookie ^ (unsigned long long)C->steps ^ C->hist);
  C->op = logical;
  C->hist = vm_main_int___a100e2bc_mix(C->hist ^ (unsigned long long)logical ^ (unsigned long long)C->pc);
  C->state = 876360;
}
static long long vm_main_int___a100e2bc_run(long long* locals_plain, int nlocals) {
  using u64 = unsigned long long;
  size_t __vm_alloc_mark = __vm_alloc_list.size();
  __vm_alloc_guard __vm_ag(__vm_alloc_mark); 
  
  u64 frame = vm_main_int___a100e2bc_mod_keys::fs ^ vm_main_int___a100e2bc_mix((u64)(uintptr_t)locals_plain);
  u64 rt_key = vm_main_int___a100e2bc_mix(frame ^ vm_main_int___a100e2bc_mod_keys::ss ^ (u64)vm_main_int___a100e2bc_anti_emu_tick());
  unsigned char code[16384]; unsigned len = vm_main_int___a100e2bc_mod_code::len; if(len>16384){ /* bytecode truncated — refuse run */ return 0; }
  
  for (unsigned i=0;i<len;++i)
    code[i]=(unsigned char)(vm_main_int___a100e2bc_mod_code::enc[i] ^ vm_main_int___a100e2bc_bc_ks(i) ^ vm_main_int___a100e2bc_ks2(i, vm_main_int___a100e2bc_mod_keys::ss) ^ vm_main_int___a100e2bc_mod_keys::xorkey);
  
  u64 sum = vm_main_int___a100e2bc_mod_keys::dc;
  for (unsigned i=0;i<vm_main_int___a100e2bc_mod_code::len;++i)
    sum = vm_main_int___a100e2bc_mix(sum ^ vm_main_int___a100e2bc_mod_code::enc[i] ^ (u64)i);
  int attest_ok = (sum == vm_main_int___a100e2bc_mod_code::expect_sum);
  if (!attest_ok) { /* soft: still run but poison cookie */ frame ^= 0xBADC0DEULL; }
  
  u64 regs_a[256]={}, regs_b[256]={};
  u64 mem_tag = vm_main_int___a100e2bc_mix(frame ^ rt_key ^ 0x4D454D54ULL);
  auto reg_get=[&](int r)->u64{ int i=r&255; u64 v=(r&1)?regs_b[i]:regs_a[i]; return v^vm_main_int___a100e2bc_regkey(r,frame)^ (mem_tag & 0ULL); };
  auto reg_set=[&](int r,u64 v){ int i=r&255; u64 e=v^vm_main_int___a100e2bc_regkey(r,frame); if(r&1)regs_b[i]=e; else regs_a[i]=e; mem_tag=vm_main_int___a100e2bc_mix(mem_tag^(u64)r^v); };
  for (int i=0;i<nlocals && i<256;++i) reg_set(i,(u64)locals_plain[i]);
  
  u64 stack_raw[1024]; u64 stack_enc[1024]; int sp=0;
  u64 stack_canary = vm_main_int___a100e2bc_mix(frame ^ 0x43414E59ULL);
  auto page_key=[&](int s)->u64{ return vm_main_int___a100e2bc_mix(frame ^ mem_tag ^ ((u64)(s>>6)*0x9E3779B97F4A7C15ULL)); };
  auto spush=[&](u64 v){
    if (sp < 0 || sp >= 1023) { stack_canary ^= 0xBADULL; return; }
    u64 pk = page_key(sp);
    stack_raw[sp]=v^ (pk & 0ULL);
    stack_enc[sp]=vm_main_int___a100e2bc_ptr_enc(v, frame^(u64)sp^pk);
    ++sp;
  };
  auto spop=[&](){
    if (sp <= 0) { stack_canary ^= 0xDEADULL; return 0ULL; }
    --sp;
    u64 pk = page_key(sp);
    u64 e=stack_enc[sp]; u64 v=vm_main_int___a100e2bc_ptr_dec(e, frame^(u64)sp^pk);
    if (v != stack_raw[sp] && vm_main_int___a100e2bc_opq_f(v)==0) v = stack_raw[sp];
    return v;
  };
  
  
  struct Cell{int n; long long v[64]; unsigned long long tag;};
  Cell heap[256]; int htop=1;
  auto heap_alloc=[&](unsigned n)->int{
    if(n>64)n=64; if(htop>=256) return 0; int id=htop++;
    heap[id].n=(int)n; heap[id].tag=vm_main_int___a100e2bc_mix(mem_tag^(u64)id^(u64)n);
    for(int i=0;i<(int)n;++i) heap[id].v[i]=0;
    return id;
  };
  auto heap_get=[&](int obj, unsigned fi)->u64{
    if(obj<=0||obj>=256||(int)fi>=heap[obj].n) return 0;
    if(heap[obj].tag != vm_main_int___a100e2bc_mix(mem_tag^(u64)obj^(u64)heap[obj].n) && vm_main_int___a100e2bc_opq_ctx_f(mem_tag, frame)) return 0;
    return (u64)heap[obj].v[fi];
  };
  auto heap_set=[&](int obj, unsigned fi, long long val){
    if(obj<=0||obj>=256||(int)fi>=heap[obj].n) return;
    heap[obj].v[fi]=val;
    heap[obj].tag=vm_main_int___a100e2bc_mix(mem_tag^(u64)obj^(u64)heap[obj].n^(u64)val);
  };
  
  struct TryFrame { unsigned handler; int sp_mark; };
  TryFrame try_stk[32]; int try_sp = 0;
  long long exc_val = 0; int exc_type = 0;
  
  std::atomic<u64> lane{frame};
  {
    
    u64 st = frame ^ rt_key; int phase = (int)(st & 7ULL);
    for (int k = 0; k < 8; ++k) {
      switch (phase & 7) {
      case 0: st = vm_main_int___a100e2bc_mix(st + 0x9E37); phase = 1; break;
      case 1: st = vm_main_int___a100e2bc_mix(st ^ lane.load(std::memory_order_relaxed)); phase = 2; break;
      case 2: st = vm_main_int___a100e2bc_mix(st * 0xBF58 + 1); phase = 3; break;
      default: phase = 0; break;
      }
    }
    lane.store(st, std::memory_order_relaxed);
  }
  vm_main_int___a100e2bc_Ctx C{};
  C.code=code; C.len=len; C.pc=0; C.op=0; C.state=851465; C.retv=0; C.done=0; C.uncaught=0;
  C.frame=frame; C.cookie=vm_main_int___a100e2bc_mod_keys::dc; C.rt_key=rt_key; C.steps=0; C.running_sum=sum;
  C.hist = vm_main_int___a100e2bc_mix(frame ^ sum); C.dyn_salt = rt_key;
  C.seg_size = 32; C.win_seg = 0; C.call_depth = 0;
  C.stack_canary = stack_canary; C.mem_tag = mem_tag;
  C.host = &vm_main_int___a100e2bc_host;
  
  if (C.seg_size > 0 && len > 0) {
    unsigned nseg = (len + C.seg_size - 1) / C.seg_size;
    for (unsigned s = 0; s < nseg; ++s) vm_main_int___a100e2bc_seg_apply(&C, s);
    C.win_seg = 0;
    vm_main_int___a100e2bc_seg_apply(&C, 0);
    if (nseg > 1) vm_main_int___a100e2bc_seg_apply(&C, 1);
  }
  auto rd_u32=[&](){
    if (C.pc + 3 >= C.len) { C.done=1; return 0u; }
    vm_main_int___a100e2bc_seg_ensure_range(&C, C.pc, C.pc + 3);
    unsigned v=(unsigned)code[C.pc]|((unsigned)code[C.pc+1]<<8)|((unsigned)code[C.pc+2]<<16)|((unsigned)code[C.pc+3]<<24);
    C.pc+=4; return v;
  };
  auto rd_u16=[&](){
    if (C.pc + 1 >= C.len) { C.done=1; return 0u; }
    vm_main_int___a100e2bc_seg_ensure_range(&C, C.pc, C.pc + 1);
    unsigned v=(unsigned)code[C.pc]|((unsigned)code[C.pc+1]<<8);
    C.pc+=2; return v;
  };
  auto rd_i32=[&](){ return (int)rd_u32(); };
  
  int bcf = vm_main_int___a100e2bc_opq_ctx_t(C.hist, frame);
  
  unsigned long long L2_VR[8] = {};
  for (int i=0;i<8;++i) L2_VR[i] = vm_main_int___a100e2bc_mix(frame ^ rt_key ^ (u64)(i*0x10001));
  vm_main_int___a100e2bc_l2_vr_scramble(L2_VR, 8, frame ^ rt_key);
  unsigned L2_VIP = 0;
  unsigned long long L2_key = vm_main_int___a100e2bc_l2::stream ^ frame ^ rt_key;
  int L2_done = 0;
  int L1_entered = 0;
  unsigned long long L2_vsp_shadow = vm_main_int___a100e2bc_mix(C.cookie ^ 0x4C320000ULL);
  while (!L2_done) {
    
    
    if (L2_VIP >= vm_main_int___a100e2bc_l2::len) { L2_done = 1; break; }
    unsigned char L2_wired = (unsigned char)(vm_main_int___a100e2bc_l2::code[L2_VIP] ^ vm_main_int___a100e2bc_l2_ks(L2_VIP, vm_main_int___a100e2bc_l2::stream));
    L2_VIP++;
    
    unsigned long long L2_dyn = vm_main_int___a100e2bc_mix(L2_key ^ C.hist ^ (u64)L2_VIP);
    unsigned char L2_scrub = (unsigned char)(L2_dyn ^ (L2_dyn >> 9));
    unsigned char L2_logical = vm_main_int___a100e2bc_l2::dec[(unsigned char)(L2_wired ^ L2_scrub ^ L2_scrub)];
    
    vm_main_int___a100e2bc_l2_vr_scramble(L2_VR, 8, L2_key ^ (u64)L2_VIP);
    switch ((int)L2_logical) {
    case vm_main_int___a100e2bc_l2::OP_NOP:
      L2_vsp_shadow ^= L2_dyn;
      break;
    case vm_main_int___a100e2bc_l2::OP_KEY_ROT:
      
      L2_key = vm_main_int___a100e2bc_mix(L2_key ^ C.cookie ^ (u64)L2_VIP ^ L2_VR[0]);
      break;
    case vm_main_int___a100e2bc_l2::OP_CTX_MIX:
      
      C.cookie ^= vm_main_int___a100e2bc_mix(L2_VR[1] ^ L2_key);
      C.hist = vm_main_int___a100e2bc_mix(C.hist ^ L2_VR[2] ^ (u64)L2_VIP);
      L2_VR[3] ^= C.cookie;
      break;
    case vm_main_int___a100e2bc_l2::OP_VR_IMM: {
      unsigned char imm = 0;
      if (L2_VIP < vm_main_int___a100e2bc_l2::len) {
        imm = (unsigned char)(vm_main_int___a100e2bc_l2::code[L2_VIP] ^ vm_main_int___a100e2bc_l2_ks(L2_VIP, vm_main_int___a100e2bc_l2::stream));
        L2_VIP++;
      }
      L2_VR[imm & 7] ^= (u64)imm ^ L2_key;
      break;
    }
    case vm_main_int___a100e2bc_l2::OP_VR_XOR:
      L2_VR[0] ^= L2_VR[1]; L2_VR[2] ^= L2_VR[3];
      L2_VR[4] ^= L2_VR[5]; L2_VR[6] ^= L2_VR[7];
      break;
    case vm_main_int___a100e2bc_l2::OP_OPAQUE:
      
      if (vm_main_int___a100e2bc_opq_ctx_f(L2_VR[0], L2_key) != 0) L2_VIP = 0;
      else L2_vsp_shadow = vm_main_int___a100e2bc_mix(L2_vsp_shadow ^ L2_VR[4]);
      break;
    case vm_main_int___a100e2bc_l2::OP_EXIT:
      L2_done = 1;
      break;
    case vm_main_int___a100e2bc_l2::OP_ENTER_L1:
      
      if (L1_entered) break;
      L1_entered = 1;
      
      {
  unsigned long long dispatch_steps = 0;
  const unsigned long long dispatch_budget = (unsigned long long)len * 4096ULL + 100000ULL;
  while (!C.done) {
    if (++dispatch_steps > dispatch_budget) {
      C.retv = 0; C.done = 1; C.state = 579700;
      break;
    }
    
    
    
    
    
    C.hist = vm_main_int___a100e2bc_mix(C.hist ^ C.cookie ^ (u64)C.state);
    
    if (C.stack_canary != stack_canary) C.cookie ^= 0xC4A1ULL;
    switch (C.state) {
    case 851465:
      
      if (bcf) C.state = 915215; else C.state = 270496;
      break;
    case 915215:
      
      { volatile unsigned long long mh0_37604=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh0_37604; }
      { volatile unsigned long long mh1_57491=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1_57491; }
      C.cookie ^= vm_main_int___a100e2bc_mix(C.cookie+1);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2_38446=3543116045ULL; volatile unsigned long long mb3_52329=987749427ULL; volatile unsigned long long mc4_37924=ma2_38446^mb3_52329; mc4_37924=(((mc4_37924) & (mc4_37924)) | ((mc4_37924) & 0ULL)); (void)mc4_37924; } } C.state = 717386;
      break;
    case 270496:
      
      { volatile unsigned long long mh5_1427=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh5_1427; }
      C.cookie = vm_main_int___a100e2bc_mix(C.cookie ^ frame);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma6_32119=2408220509ULL; volatile unsigned long long mb7_33288=1804643441ULL; volatile unsigned long long mc8_4378=ma6_32119^mb7_33288; if((((mc8_4378 * 2ULL) & 1ULL) != 0ULL)) mc8_4378^=0xDEADULL; (void)mc8_4378; } } C.state = 717386;
      break;
    case 717386:
      
      if (attest_ok || vm_main_int___a100e2bc_opq_t(sum)) C.state = 16171;
      else C.state = 114126;
      break;
    case 16171:
      
      { volatile int t = vm_main_int___a100e2bc_anti_emu_tick(); C.cookie ^= (u64)t; }
      
      { volatile unsigned long long ma9_23530=3099004899ULL; volatile unsigned long long mb10_37015=2988664851ULL; volatile unsigned long long mc11_7230=ma9_23530^mb10_37015; mc11_7230=(((mc11_7230) ^ (mc11_7230)) + (mc11_7230)); (void)mc11_7230; }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 470319; } else { { volatile unsigned long long ma12_39268=2939126563ULL; volatile unsigned long long mb13_39867=2103457125ULL; volatile unsigned long long mc14_15952=ma12_39268^mb13_39867; mc14_15952=((mc14_15952) | 0ULL); (void)mc14_15952; } C.state = 470319; }
      break;
    case 413650:
      
      { volatile unsigned long long mh15_47398=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh15_47398; }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 851465; } else { { volatile unsigned long long ma16_3068=4049487529ULL; volatile unsigned long long mb17_2224=4018871049ULL; volatile unsigned long long mc18_42325=ma16_3068^mb17_2224; for(volatile int _i=0;_i<2;++_i) mc18_42325=vm_main_int___a100e2bc_mix(mc18_42325+_i); (void)mc18_42325; } C.state = 851465; }
      vm_main_int___a100e2bc_mod_junk::opaque ^= C.cookie;
      break;
    case 114126:
      
      { volatile unsigned long long mh19_25109=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh19_25109; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 470319; } else { { volatile unsigned long long ma21_780=101840257ULL; volatile unsigned long long mb22_17278=1444982023ULL; volatile unsigned long long mc23_51013=ma21_780^mb22_17278; mc23_51013=(((mc23_51013) & (mc23_51013)) | ((mc23_51013) & 0ULL)); (void)mc23_51013; } C.state = 470319; }
      break;
    case 201315:
      
      { volatile unsigned long long ma24_65527=3322549887ULL; volatile unsigned long long mb25_21123=3855595195ULL; volatile unsigned long long mc26_3072=ma24_65527^mb25_21123; mc26_3072=(ma24_65527^mb25_21123)+((ma24_65527&mb25_21123)<<1); (void)mc26_3072; }
      { { volatile unsigned long long ma30_3830=3903260825ULL; volatile unsigned long long mb31_47975=4034740203ULL; volatile unsigned long long mc32_26421=ma30_3830^mb31_47975; mc32_26421=(ma30_3830^mb31_47975)+((ma30_3830&mb31_47975)<<1); (void)mc32_26421; } C.state = 125221; }
      break;
    case 910728:
      
      
      { volatile unsigned long long ma33_20004=3698435143ULL; volatile unsigned long long mb34_58119=2687139475ULL; volatile unsigned long long mc35_8861=ma33_20004^mb34_58119; mc35_8861=((mc35_8861) + 0ULL); (void)mc35_8861; }
      { unsigned long long mt36_42429=C.cookie^1ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt36_42429) + 0ULL)); }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma37_51051=1795065595ULL; volatile unsigned long long mb38_34162=452130455ULL; volatile unsigned long long mc39_47653=ma37_51051^mb38_34162; if((((mc39_47653 + 0ULL) ^ (mc39_47653 + 0ULL)) == 1ULL)) mc39_47653^=0xDEADULL; (void)mc39_47653; } } C.state = 414885;
      break;
    case 99541:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long mt41_36302=C.cookie;mt41_36302^=2ULL;C.cookie=vm_main_int___a100e2bc_mix(mt41_36302); }
      { { volatile unsigned long long ma45_7850=2510000327ULL; volatile unsigned long long mb46_36602=3504012643ULL; volatile unsigned long long mc47_59912=ma45_7850^mb46_36602; mc47_59912=((mc47_59912) ^ 0ULL); (void)mc47_59912; } C.state = 551446; }
      break;
    case 657339:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long ma49_18164=352870789ULL; volatile unsigned long long mb50_28470=4082361711ULL; volatile unsigned long long mc51_52557=ma49_18164^mb50_28470; if((((mc51_52557 + 0ULL) ^ (mc51_52557 + 0ULL)) == 1ULL)) mc51_52557^=0xDEADULL; (void)mc51_52557; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^3ULL);
      { { volatile unsigned long long ma56_1550=2855481713ULL; volatile unsigned long long mb57_40655=3612881697ULL; volatile unsigned long long mc58_42043=ma56_1550^mb57_40655; if((((mc58_42043 | 0ULL) & 0ULL) != 0ULL)) mc58_42043^=0xDEADULL; (void)mc58_42043; } C.state = 111361; }
      break;
    case 55444:
      
      
      { volatile unsigned long long ma59_50806=266238823ULL; volatile unsigned long long mb60_30105=4216997715ULL; volatile unsigned long long mc61_33572=ma59_50806^mb60_30105; for(volatile int _i=0;_i<1;++_i) mc61_33572=vm_main_int___a100e2bc_mix(mc61_33572+_i); (void)mc61_33572; }
      { volatile unsigned long long mt62_57805=C.cookie;mt62_57805^=4ULL;C.cookie=vm_main_int___a100e2bc_mix(mt62_57805); }
      { { volatile unsigned long long ma66_14030=2948993791ULL; volatile unsigned long long mb67_34570=477887855ULL; volatile unsigned long long mc68_18705=ma66_14030^mb67_34570; mc68_18705=(ma66_14030^mb67_34570)+((ma66_14030&mb67_34570)<<1); (void)mc68_18705; } C.state = 707787; }
      break;
    case 174614:
      
      
      { volatile unsigned long long ma69_9645=532413377ULL; volatile unsigned long long mb70_40202=1121126667ULL; volatile unsigned long long mc71_28483=ma69_9645^mb70_40202; mc71_28483=(ma69_9645^mb70_40202)+((ma69_9645&mb70_40202)<<1); (void)mc71_28483; }
      { volatile unsigned long long mh72_65464=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh72_65464; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^5ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma74_32484=1322299439ULL; volatile unsigned long long mb75_63842=3113969137ULL; volatile unsigned long long mc76_36823=ma74_32484^mb75_63842; mc76_36823=(ma74_32484^mb75_63842)+((ma74_32484&mb75_63842)<<1); (void)mc76_36823; } } C.state = 553018;
      break;
    case 730174:
      
      
      { unsigned long long mt77_541=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt77_541) | 0ULL)); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^6ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma79_15556=1752163057ULL; volatile unsigned long long mb80_41944=1459303251ULL; volatile unsigned long long mc81_40606=ma79_15556^mb80_41944; mc81_40606=(ma79_15556^mb80_41944)+((ma79_15556&mb80_41944)<<1); (void)mc81_40606; } } C.state = 827821;
      break;
    case 606221:
      
      
      { volatile unsigned long long mh82_28657=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh82_28657; }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma83_649=2884524127ULL; volatile unsigned long long mb84_63106=1246221817ULL; volatile unsigned long long mc85_47243=ma83_649^mb84_63106; mc85_47243=(ma83_649^mb84_63106)+((ma83_649&mb84_63106)<<1); (void)mc85_47243; } }
      { volatile unsigned long long mt86_17833=C.cookie;mt86_17833^=7ULL;C.cookie=vm_main_int___a100e2bc_mix(mt86_17833); }
      { { volatile unsigned long long ma90_35241=1373999989ULL; volatile unsigned long long mb91_30372=696085339ULL; volatile unsigned long long mc92_25116=ma90_35241^mb91_30372; if(((mc92_25116 ^ mc92_25116) != 0ULL)) mc92_25116^=0xDEADULL; (void)mc92_25116; } C.state = 186096; }
      break;
    case 277375:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long ma94_42186=1680883535ULL; volatile unsigned long long mb95_389=2820955271ULL; volatile unsigned long long mc96_57659=ma94_42186^mb95_389; mc96_57659=(ma94_42186^mb95_389)+((ma94_42186&mb95_389)<<1); (void)mc96_57659; }
      { volatile unsigned long long mt97_60428=C.cookie;mt97_60428^=8ULL;C.cookie=vm_main_int___a100e2bc_mix(mt97_60428); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 558893; } else { { volatile unsigned long long ma98_10086=3319031953ULL; volatile unsigned long long mb99_55657=3889258421ULL; volatile unsigned long long mc100_63812=ma98_10086^mb99_55657; for(volatile int _i=0;_i<2;++_i) mc100_63812=vm_main_int___a100e2bc_mix(mc100_63812+_i); (void)mc100_63812; } C.state = 558893; }
      break;
    case 14258:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma101_3863=16008771ULL; volatile unsigned long long mb102_42050=4272103737ULL; volatile unsigned long long mc103_25774=ma101_3863^mb102_42050; if((((mc103_25774 | 0ULL) & 0ULL) != 0ULL)) mc103_25774^=0xDEADULL; (void)mc103_25774; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { unsigned long long mt105_14028=C.cookie^9ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt105_14028) ^ (mt105_14028)) + (mt105_14028))); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma106_60518=4153491529ULL; volatile unsigned long long mb107_17641=2402015417ULL; volatile unsigned long long mc108_60762=ma106_60518^mb107_17641; for(volatile int _i=0;_i<2;++_i) mc108_60762=vm_main_int___a100e2bc_mix(mc108_60762+_i); (void)mc108_60762; } } C.state = 196711;
      break;
    case 539878:
      
      
      { volatile unsigned long long ma109_55732=2324252617ULL; volatile unsigned long long mb110_5664=1756189489ULL; volatile unsigned long long mc111_8186=ma109_55732^mb110_5664; mc111_8186=((mc111_8186) ^ 0ULL); (void)mc111_8186; }
      { volatile unsigned long long mh112_5010=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh112_5010; }
      { volatile unsigned long long mt113_37125=C.cookie;mt113_37125^=10ULL;C.cookie=vm_main_int___a100e2bc_mix(mt113_37125); }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma114_24177=4031968415ULL; volatile unsigned long long mb115_8045=826989797ULL; volatile unsigned long long mc116_6237=ma114_24177^mb115_8045; mc116_6237=(ma114_24177^mb115_8045)+((ma114_24177&mb115_8045)<<1); (void)mc116_6237; } } C.state = 976608;
      break;
    case 469729:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long ma118_42951=1694716195ULL; volatile unsigned long long mb119_41665=2300533663ULL; volatile unsigned long long mc120_19251=ma118_42951^mb119_41665; for(volatile int _i=0;_i<1;++_i) mc120_19251=vm_main_int___a100e2bc_mix(mc120_19251+_i); (void)mc120_19251; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^11ULL);
      { { volatile unsigned long long ma125_45756=3712151563ULL; volatile unsigned long long mb126_37921=806466023ULL; volatile unsigned long long mc127_51235=ma125_45756^mb126_37921; if((((mc127_51235 + 0ULL) ^ (mc127_51235 + 0ULL)) == 1ULL)) mc127_51235^=0xDEADULL; (void)mc127_51235; } C.state = 371880; }
      break;
    case 31564:
      
      
      { volatile unsigned long long mt128_37573=C.cookie;mt128_37573^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt128_37573); }
      { volatile unsigned long long mt129_13260=C.cookie;mt129_13260^=12ULL;C.cookie=vm_main_int___a100e2bc_mix(mt129_13260); }
      { { volatile unsigned long long ma133_44964=1359923635ULL; volatile unsigned long long mb134_29382=1094449175ULL; volatile unsigned long long mc135_29031=ma133_44964^mb134_29382; if((((mc135_29031 | 0ULL) & 0ULL) != 0ULL)) mc135_29031^=0xDEADULL; (void)mc135_29031; } C.state = 707787; }
      break;
    case 90792:
      
      
      { volatile unsigned long long ma136_7647=3480091313ULL; volatile unsigned long long mb137_13767=3603485639ULL; volatile unsigned long long mc138_24192=ma136_7647^mb137_13767; mc138_24192=((mc138_24192) + 0ULL); (void)mc138_24192; }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma139_41039=808936079ULL; volatile unsigned long long mb140_21324=2742096413ULL; volatile unsigned long long mc141_35503=ma139_41039^mb140_21324; for(volatile int _i=0;_i<1;++_i) mc141_35503=vm_main_int___a100e2bc_mix(mc141_35503+_i); (void)mc141_35503; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^13ULL);
      { { volatile unsigned long long ma146_53003=2413644125ULL; volatile unsigned long long mb147_55199=910211443ULL; volatile unsigned long long mc148_37402=ma146_53003^mb147_55199; for(volatile int _i=0;_i<2;++_i) mc148_37402=vm_main_int___a100e2bc_mix(mc148_37402+_i); (void)mc148_37402; } C.state = 909881; }
      break;
    case 412273:
      
      
      { unsigned long long mt149_38582=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt149_38582) + 0ULL)); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma150_35498=780547697ULL; volatile unsigned long long mb151_10413=185672509ULL; volatile unsigned long long mc152_30273=ma150_35498^mb151_10413; mc152_30273=((mc152_30273) ^ 0ULL); (void)mc152_30273; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^14ULL);
      { { volatile unsigned long long ma157_42035=2405087613ULL; volatile unsigned long long mb158_20763=3376572161ULL; volatile unsigned long long mc159_58015=ma157_42035^mb158_20763; for(volatile int _i=0;_i<3;++_i) mc159_58015=vm_main_int___a100e2bc_mix(mc159_58015+_i); (void)mc159_58015; } C.state = 465655; }
      break;
    case 818718:
      
      
      { volatile unsigned long long mt160_6854=C.cookie;mt160_6854^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt160_6854); }
      { volatile unsigned long long ma161_11803=4005883603ULL; volatile unsigned long long mb162_3756=4081023227ULL; volatile unsigned long long mc163_42175=ma161_11803^mb162_3756; mc163_42175=(ma161_11803^mb162_3756)+((ma161_11803&mb162_3756)<<1); (void)mc163_42175; }
      { volatile unsigned long long mt164_38393=C.cookie;mt164_38393^=15ULL;C.cookie=vm_main_int___a100e2bc_mix(mt164_38393); }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma165_15833=3590695401ULL; volatile unsigned long long mb166_6530=719116773ULL; volatile unsigned long long mc167_49377=ma165_15833^mb166_6530; for(volatile int _i=0;_i<2;++_i) mc167_49377=vm_main_int___a100e2bc_mix(mc167_49377+_i); (void)mc167_49377; } } C.state = 718049;
      break;
    case 95976:
      
      
      { volatile unsigned long long mh168_26072=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh168_26072; }
      { volatile unsigned long long mh169_60219=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh169_60219; }
      { volatile unsigned long long mt170_49622=C.cookie;mt170_49622^=16ULL;C.cookie=vm_main_int___a100e2bc_mix(mt170_49622); }
      { { volatile unsigned long long ma174_43539=998853155ULL; volatile unsigned long long mb175_4601=1232838265ULL; volatile unsigned long long mc176_64572=ma174_43539^mb175_4601; mc176_64572=(ma174_43539^mb175_4601)+((ma174_43539&mb175_4601)<<1); (void)mc176_64572; } C.state = 583038; }
      break;
    case 486337:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^17ULL);
      { { volatile unsigned long long ma182_35012=1193828389ULL; volatile unsigned long long mb183_19620=3877176219ULL; volatile unsigned long long mc184_7995=ma182_35012^mb183_19620; mc184_7995=((mc184_7995) ^ 0ULL); (void)mc184_7995; } C.state = 296863; }
      break;
    case 616006:
      
      
      { volatile unsigned long long ma185_62165=4026893803ULL; volatile unsigned long long mb186_51221=620935201ULL; volatile unsigned long long mc187_30583=ma185_62165^mb186_51221; mc187_30583=(ma185_62165^mb186_51221)+((ma185_62165&mb186_51221)<<1); (void)mc187_30583; }
      { volatile unsigned long long ma188_2305=497588383ULL; volatile unsigned long long mb189_3576=2009309273ULL; volatile unsigned long long mc190_33990=ma188_2305^mb189_3576; mc190_33990=((mc190_33990) + 0ULL); (void)mc190_33990; }
      { volatile unsigned long long mt191_13144=C.cookie;mt191_13144^=18ULL;C.cookie=vm_main_int___a100e2bc_mix(mt191_13144); }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma192_40161=4143555643ULL; volatile unsigned long long mb193_25468=3457765645ULL; volatile unsigned long long mc194_58089=ma192_40161^mb193_25468; mc194_58089=(ma192_40161^mb193_25468)+((ma192_40161&mb193_25468)<<1); (void)mc194_58089; } } C.state = 411956;
      break;
    case 641054:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma195_65242=3368383743ULL; volatile unsigned long long mb196_24941=2075885309ULL; volatile unsigned long long mc197_55604=ma195_65242^mb196_24941; for(volatile int _i=0;_i<2;++_i) mc197_55604=vm_main_int___a100e2bc_mix(mc197_55604+_i); (void)mc197_55604; } }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma198_49599=629958513ULL; volatile unsigned long long mb199_8067=670470973ULL; volatile unsigned long long mc200_3117=ma198_49599^mb199_8067; for(volatile int _i=0;_i<3;++_i) mc200_3117=vm_main_int___a100e2bc_mix(mc200_3117+_i); (void)mc200_3117; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^19ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 277803; } else { { volatile unsigned long long ma202_52478=2843654745ULL; volatile unsigned long long mb203_32994=3977836287ULL; volatile unsigned long long mc204_45385=ma202_52478^mb203_32994; mc204_45385=((mc204_45385) + 0ULL); (void)mc204_45385; } C.state = 277803; }
      break;
    case 676008:
      
      
      { volatile unsigned long long mh205_30997=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh205_30997; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^20ULL);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 424444; } else { { volatile unsigned long long ma207_55496=2220562407ULL; volatile unsigned long long mb208_64180=2363545189ULL; volatile unsigned long long mc209_17357=ma207_55496^mb208_64180; mc209_17357=((mc209_17357) + 0ULL); (void)mc209_17357; } C.state = 424444; }
      break;
    case 49345:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma210_36864=230660277ULL; volatile unsigned long long mb211_15243=4240036467ULL; volatile unsigned long long mc212_25837=ma210_36864^mb211_15243; mc212_25837=((mc212_25837) ^ 0ULL); (void)mc212_25837; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^21ULL);
      { { volatile unsigned long long ma217_7488=3771783881ULL; volatile unsigned long long mb218_42406=2083978985ULL; volatile unsigned long long mc219_49376=ma217_7488^mb218_42406; mc219_49376=(((mc219_49376) ^ (mc219_49376)) + (mc219_49376)); (void)mc219_49376; } C.state = 263652; }
      break;
    case 60034:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma220_4660=189214451ULL; volatile unsigned long long mb221_52386=2497655431ULL; volatile unsigned long long mc222_5196=ma220_4660^mb221_52386; for(volatile int _i=0;_i<3;++_i) mc222_5196=vm_main_int___a100e2bc_mix(mc222_5196+_i); (void)mc222_5196; } }
      { volatile unsigned long long mt223_39331=C.cookie;mt223_39331^=22ULL;C.cookie=vm_main_int___a100e2bc_mix(mt223_39331); }
      { { volatile unsigned long long ma227_11318=449859745ULL; volatile unsigned long long mb228_55473=998325993ULL; volatile unsigned long long mc229_15975=ma227_11318^mb228_55473; mc229_15975=(((mc229_15975) & (mc229_15975)) | ((mc229_15975) & 0ULL)); (void)mc229_15975; } C.state = 65716; }
      break;
    case 111361:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma231_21768=609576501ULL; volatile unsigned long long mb232_61846=1343757753ULL; volatile unsigned long long mc233_50946=ma231_21768^mb232_61846; if(((mc233_50946 ^ mc233_50946) != 0ULL)) mc233_50946^=0xDEADULL; (void)mc233_50946; } }
      { unsigned long long mt234_60986=C.cookie^23ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt234_60986) ^ (mt234_60986)) + (mt234_60986))); }
      { { volatile unsigned long long ma238_18426=1609767877ULL; volatile unsigned long long mb239_35633=56240033ULL; volatile unsigned long long mc240_61626=ma238_18426^mb239_35633; if((((mc240_61626 | 0ULL) & 0ULL) != 0ULL)) mc240_61626^=0xDEADULL; (void)mc240_61626; } C.state = 393923; }
      break;
    case 951598:
      
      
      { volatile unsigned long long mh241_28181=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh241_28181; }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma242_48580=3115210997ULL; volatile unsigned long long mb243_58275=2190951109ULL; volatile unsigned long long mc244_7297=ma242_48580^mb243_58275; if((((mc244_7297 | 0ULL) & 0ULL) != 0ULL)) mc244_7297^=0xDEADULL; (void)mc244_7297; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^24ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 22423; } else { { volatile unsigned long long ma246_54685=3671253397ULL; volatile unsigned long long mb247_18958=2994432277ULL; volatile unsigned long long mc248_54492=ma246_54685^mb247_18958; mc248_54492=(ma246_54685^mb247_18958)+((ma246_54685&mb247_18958)<<1); (void)mc248_54492; } C.state = 22423; }
      break;
    case 136170:
      
      
      { volatile unsigned long long ma249_37925=2809455375ULL; volatile unsigned long long mb250_18870=2750754703ULL; volatile unsigned long long mc251_29778=ma249_37925^mb250_18870; if((((mc251_29778 * 2ULL) & 1ULL) != 0ULL)) mc251_29778^=0xDEADULL; (void)mc251_29778; }
      { volatile unsigned long long mh252_27177=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh252_27177; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^25ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 875420; } else { { volatile unsigned long long ma254_41246=3237154151ULL; volatile unsigned long long mb255_14620=537871167ULL; volatile unsigned long long mc256_29600=ma254_41246^mb255_14620; mc256_29600=(ma254_41246^mb255_14620)+((ma254_41246&mb255_14620)<<1); (void)mc256_29600; } C.state = 875420; }
      break;
    case 622549:
      
      
      { volatile unsigned long long ma257_55336=3645234965ULL; volatile unsigned long long mb258_9075=631958531ULL; volatile unsigned long long mc259_57916=ma257_55336^mb258_9075; mc259_57916=(((mc259_57916) ^ (mc259_57916)) + (mc259_57916)); (void)mc259_57916; }
      { unsigned long long mt260_34468=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt260_34468) ^ 0ULL)); }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^26ULL);
      { { volatile unsigned long long ma265_46112=2188277319ULL; volatile unsigned long long mb266_35005=801041521ULL; volatile unsigned long long mc267_6089=ma265_46112^mb266_35005; for(volatile int _i=0;_i<1;++_i) mc267_6089=vm_main_int___a100e2bc_mix(mc267_6089+_i); (void)mc267_6089; } C.state = 536734; }
      break;
    case 861006:
      
      
      { volatile unsigned long long ma268_52841=4198315291ULL; volatile unsigned long long mb269_946=840352625ULL; volatile unsigned long long mc270_40662=ma268_52841^mb269_946; mc270_40662=((mc270_40662) ^ 0ULL); (void)mc270_40662; }
      { volatile unsigned long long ma271_26483=373857621ULL; volatile unsigned long long mb272_23224=2941626049ULL; volatile unsigned long long mc273_35100=ma271_26483^mb272_23224; mc273_35100=(ma271_26483^mb272_23224)+((ma271_26483&mb272_23224)<<1); (void)mc273_35100; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^27ULL);
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma275_7897=828066195ULL; volatile unsigned long long mb276_14223=4202449807ULL; volatile unsigned long long mc277_51575=ma275_7897^mb276_14223; mc277_51575=((mc277_51575) | 0ULL); (void)mc277_51575; } } C.state = 998721;
      break;
    case 691193:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long mt279_41462=C.cookie;mt279_41462^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt279_41462); }
      { unsigned long long mt280_553=C.cookie^28ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt280_553) ^ (mt280_553)) + (mt280_553))); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma281_59329=2193929649ULL; volatile unsigned long long mb282_16254=3481461195ULL; volatile unsigned long long mc283_7409=ma281_59329^mb282_16254; if((((mc283_7409 + 0ULL) ^ (mc283_7409 + 0ULL)) == 1ULL)) mc283_7409^=0xDEADULL; (void)mc283_7409; } } C.state = 658939;
      break;
    case 837158:
      
      
      { volatile unsigned long long ma284_24876=1059106981ULL; volatile unsigned long long mb285_64981=1678553239ULL; volatile unsigned long long mc286_25307=ma284_24876^mb285_64981; mc286_25307=(ma284_24876^mb285_64981)+((ma284_24876&mb285_64981)<<1); (void)mc286_25307; }
      { volatile unsigned long long ma287_47457=1824587405ULL; volatile unsigned long long mb288_50395=2671651557ULL; volatile unsigned long long mc289_28207=ma287_47457^mb288_50395; mc289_28207=((mc289_28207) ^ 0ULL); (void)mc289_28207; }
      { volatile unsigned long long mt290_52516=C.cookie;mt290_52516^=29ULL;C.cookie=vm_main_int___a100e2bc_mix(mt290_52516); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma291_33399=1165201825ULL; volatile unsigned long long mb292_47369=10992751ULL; volatile unsigned long long mc293_54256=ma291_33399^mb292_47369; for(volatile int _i=0;_i<2;++_i) mc293_54256=vm_main_int___a100e2bc_mix(mc293_54256+_i); (void)mc293_54256; } } C.state = 909881;
      break;
    case 879837:
      
      
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma294_27719=2709724751ULL; volatile unsigned long long mb295_19074=3083124647ULL; volatile unsigned long long mc296_15220=ma294_27719^mb295_19074; mc296_15220=(ma294_27719^mb295_19074)+((ma294_27719&mb295_19074)<<1); (void)mc296_15220; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^30ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 78553; } else { { volatile unsigned long long ma298_27557=1363953959ULL; volatile unsigned long long mb299_30900=3240613471ULL; volatile unsigned long long mc300_15631=ma298_27557^mb299_30900; mc300_15631=(ma298_27557^mb299_30900)+((ma298_27557&mb299_30900)<<1); (void)mc300_15631; } C.state = 78553; }
      break;
    case 414885:
      
      
      { volatile unsigned long long mh301_48429=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh301_48429; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^31ULL);
      { { volatile unsigned long long ma306_19130=4177056457ULL; volatile unsigned long long mb307_4641=1185456297ULL; volatile unsigned long long mc308_62293=ma306_19130^mb307_4641; mc308_62293=(((mc308_62293) & (mc308_62293)) | ((mc308_62293) & 0ULL)); (void)mc308_62293; } C.state = 183177; }
      break;
    case 437207:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma310_59149=2448794851ULL; volatile unsigned long long mb311_37953=3017731741ULL; volatile unsigned long long mc312_19329=ma310_59149^mb311_37953; if((((mc312_19329 + 0ULL) ^ (mc312_19329 + 0ULL)) == 1ULL)) mc312_19329^=0xDEADULL; (void)mc312_19329; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^32ULL);
      { { volatile unsigned long long ma317_60115=4241248831ULL; volatile unsigned long long mb318_12677=1470982605ULL; volatile unsigned long long mc319_48116=ma317_60115^mb318_12677; mc319_48116=(ma317_60115^mb318_12677)+((ma317_60115&mb318_12677)<<1); (void)mc319_48116; } C.state = 650759; }
      break;
    case 977314:
      
      
      { unsigned long long mt320_6204=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt320_6204) + 0ULL)); }
      { unsigned long long mt321_53503=C.cookie^33ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt321_53503) ^ 0ULL)); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 26643; } else { { volatile unsigned long long ma322_19106=3268742379ULL; volatile unsigned long long mb323_31742=4002532053ULL; volatile unsigned long long mc324_20231=ma322_19106^mb323_31742; if((((mc324_20231 + 0ULL) ^ (mc324_20231 + 0ULL)) == 1ULL)) mc324_20231^=0xDEADULL; (void)mc324_20231; } C.state = 26643; }
      break;
    case 999253:
      
      
      { volatile unsigned long long ma325_29414=3067854571ULL; volatile unsigned long long mb326_2122=2157649967ULL; volatile unsigned long long mc327_50875=ma325_29414^mb326_2122; mc327_50875=(ma325_29414^mb326_2122)+((ma325_29414&mb326_2122)<<1); (void)mc327_50875; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^34ULL);
      { { volatile unsigned long long ma332_56933=3976283867ULL; volatile unsigned long long mb333_56256=4233364231ULL; volatile unsigned long long mc334_14823=ma332_56933^mb333_56256; mc334_14823=((mc334_14823) + 0ULL); (void)mc334_14823; } C.state = 11528; }
      break;
    case 497369:
      
      
      { volatile unsigned long long ma335_3798=1459534589ULL; volatile unsigned long long mb336_14889=2442543547ULL; volatile unsigned long long mc337_38918=ma335_3798^mb336_14889; mc337_38918=(ma335_3798^mb336_14889)+((ma335_3798&mb336_14889)<<1); (void)mc337_38918; }
      { unsigned long long mt338_61928=C.cookie^35ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt338_61928) ^ (mt338_61928)) + (mt338_61928))); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 410389; } else { { volatile unsigned long long ma339_39125=1815749397ULL; volatile unsigned long long mb340_42915=746391685ULL; volatile unsigned long long mc341_21449=ma339_39125^mb340_42915; for(volatile int _i=0;_i<2;++_i) mc341_21449=vm_main_int___a100e2bc_mix(mc341_21449+_i); (void)mc341_21449; } C.state = 410389; }
      break;
    case 78093:
      
      
      { volatile unsigned long long mh342_8007=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh342_8007; }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma343_37086=1567902295ULL; volatile unsigned long long mb344_13060=141427749ULL; volatile unsigned long long mc345_64855=ma343_37086^mb344_13060; mc345_64855=(ma343_37086^mb344_13060)+((ma343_37086&mb344_13060)<<1); (void)mc345_64855; } }
      { volatile unsigned long long mt346_31257=C.cookie;mt346_31257^=36ULL;C.cookie=vm_main_int___a100e2bc_mix(mt346_31257); }
      { { volatile unsigned long long ma350_24406=2889653895ULL; volatile unsigned long long mb351_29099=4061436199ULL; volatile unsigned long long mc352_51211=ma350_24406^mb351_29099; mc352_51211=(((mc352_51211) ^ (mc352_51211)) + (mc352_51211)); (void)mc352_51211; } C.state = 601577; }
      break;
    case 590921:
      
      
      { volatile unsigned long long mh353_61493=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh353_61493; }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma354_10311=754742237ULL; volatile unsigned long long mb355_45166=3500329507ULL; volatile unsigned long long mc356_54195=ma354_10311^mb355_45166; mc356_54195=(((mc356_54195) ^ (mc356_54195)) + (mc356_54195)); (void)mc356_54195; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^37ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 551446; } else { { volatile unsigned long long ma358_49981=3976257961ULL; volatile unsigned long long mb359_33158=1908603845ULL; volatile unsigned long long mc360_348=ma358_49981^mb359_33158; mc360_348=((mc360_348) + 0ULL); (void)mc360_348; } C.state = 551446; }
      break;
    case 186096:
      
      
      { volatile unsigned long long mh361_6472=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh361_6472; }
      { volatile unsigned long long mh362_38798=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh362_38798; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^38ULL);
      { { volatile unsigned long long ma367_11952=3239497577ULL; volatile unsigned long long mb368_5339=791694831ULL; volatile unsigned long long mc369_39231=ma367_11952^mb368_5339; mc369_39231=((mc369_39231) ^ 0ULL); (void)mc369_39231; } C.state = 250376; }
      break;
    case 852667:
      
      
      { volatile unsigned long long mh370_63031=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh370_63031; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^39ULL);
      { { volatile unsigned long long ma375_35747=2134050753ULL; volatile unsigned long long mb376_12541=3147248931ULL; volatile unsigned long long mc377_59994=ma375_35747^mb376_12541; mc377_59994=(ma375_35747^mb376_12541)+((ma375_35747&mb376_12541)<<1); (void)mc377_59994; } C.state = 952311; }
      break;
    case 317489:
      
      
      { volatile unsigned long long mt378_64427=C.cookie;mt378_64427^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt378_64427); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^40ULL);
      { { volatile unsigned long long ma383_13534=2144528875ULL; volatile unsigned long long mb384_37563=3093162553ULL; volatile unsigned long long mc385_11485=ma383_13534^mb384_37563; mc385_11485=(((mc385_11485) & (mc385_11485)) | ((mc385_11485) & 0ULL)); (void)mc385_11485; } C.state = 125221; }
      break;
    case 886449:
      
      
      { volatile unsigned long long mh386_3454=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh386_3454; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^41ULL);
      { { volatile unsigned long long ma392_20201=3113919463ULL; volatile unsigned long long mb393_14268=2299532913ULL; volatile unsigned long long mc394_54008=ma392_20201^mb393_14268; mc394_54008=(ma392_20201^mb393_14268)+((ma392_20201&mb393_14268)<<1); (void)mc394_54008; } C.state = 120691; }
      break;
    case 179381:
      
      
      { volatile unsigned long long mh395_39564=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh395_39564; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^42ULL);
      { { volatile unsigned long long ma400_24065=205959095ULL; volatile unsigned long long mb401_52246=491726585ULL; volatile unsigned long long mc402_34501=ma400_24065^mb401_52246; mc402_34501=((mc402_34501) + 0ULL); (void)mc402_34501; } C.state = 377110; }
      break;
    case 791956:
      
      
      { volatile unsigned long long mh403_21048=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh403_21048; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long mt405_18809=C.cookie;mt405_18809^=43ULL;C.cookie=vm_main_int___a100e2bc_mix(mt405_18809); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 210622; } else { { volatile unsigned long long ma406_57345=3376973639ULL; volatile unsigned long long mb407_30139=2092414797ULL; volatile unsigned long long mc408_11939=ma406_57345^mb407_30139; mc408_11939=(ma406_57345^mb407_30139)+((ma406_57345&mb407_30139)<<1); (void)mc408_11939; } C.state = 210622; }
      break;
    case 836344:
      
      
      { volatile unsigned long long ma409_47062=1310244713ULL; volatile unsigned long long mb410_17523=1021832065ULL; volatile unsigned long long mc411_1446=ma409_47062^mb410_17523; if((((mc411_1446 + 0ULL) ^ (mc411_1446 + 0ULL)) == 1ULL)) mc411_1446^=0xDEADULL; (void)mc411_1446; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { unsigned long long mt413_56113=C.cookie^44ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt413_56113) ^ 0ULL)); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 277786; } else { { volatile unsigned long long ma414_32079=3305273049ULL; volatile unsigned long long mb415_44500=4002971483ULL; volatile unsigned long long mc416_6016=ma414_32079^mb415_44500; mc416_6016=(ma414_32079^mb415_44500)+((ma414_32079&mb415_44500)<<1); (void)mc416_6016; } C.state = 277786; }
      break;
    case 111418:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma417_57328=3852285119ULL; volatile unsigned long long mb418_39299=78227419ULL; volatile unsigned long long mc419_28359=ma417_57328^mb418_39299; for(volatile int _i=0;_i<3;++_i) mc419_28359=vm_main_int___a100e2bc_mix(mc419_28359+_i); (void)mc419_28359; } }
      { unsigned long long mt420_10201=C.cookie^45ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt420_10201) ^ 0ULL)); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 500485; } else { { volatile unsigned long long ma421_15273=1629923421ULL; volatile unsigned long long mb422_19767=231648267ULL; volatile unsigned long long mc423_48125=ma421_15273^mb422_19767; if((((mc423_48125 * 2ULL) & 1ULL) != 0ULL)) mc423_48125^=0xDEADULL; (void)mc423_48125; } C.state = 500485; }
      break;
    case 288614:
      
      
      { volatile unsigned long long mh424_6638=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh424_6638; }
      { unsigned long long mt425_30120=C.cookie^46ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt425_30120) & (mt425_30120)) | ((mt425_30120) & 0ULL))); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma426_25343=2456172469ULL; volatile unsigned long long mb427_38033=1906652397ULL; volatile unsigned long long mc428_35717=ma426_25343^mb427_38033; mc428_35717=(ma426_25343^mb427_38033)+((ma426_25343&mb427_38033)<<1); (void)mc428_35717; } } C.state = 613491;
      break;
    case 157244:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma429_63580=304415609ULL; volatile unsigned long long mb430_2368=854754153ULL; volatile unsigned long long mc431_35155=ma429_63580^mb430_2368; for(volatile int _i=0;_i<2;++_i) mc431_35155=vm_main_int___a100e2bc_mix(mc431_35155+_i); (void)mc431_35155; } }
      { volatile unsigned long long mt432_11109=C.cookie;mt432_11109^=47ULL;C.cookie=vm_main_int___a100e2bc_mix(mt432_11109); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 976608; } else { { volatile unsigned long long ma433_24095=1886753919ULL; volatile unsigned long long mb434_24384=1143779101ULL; volatile unsigned long long mc435_44654=ma433_24095^mb434_24384; mc435_44654=(ma433_24095^mb434_24384)+((ma433_24095&mb434_24384)<<1); (void)mc435_44654; } C.state = 976608; }
      break;
    case 998721:
      
      
      { volatile unsigned long long mh436_44326=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh436_44326; }
      { unsigned long long mt437_64774=C.cookie^48ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt437_64774) & (mt437_64774)) | ((mt437_64774) & 0ULL))); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma438_49488=1065088683ULL; volatile unsigned long long mb439_39920=3695508523ULL; volatile unsigned long long mc440_4253=ma438_49488^mb439_39920; mc440_4253=(ma438_49488^mb439_39920)+((ma438_49488&mb439_39920)<<1); (void)mc440_4253; } } C.state = 970994;
      break;
    case 141754:
      
      
      { volatile unsigned long long ma441_16638=1915255905ULL; volatile unsigned long long mb442_30545=3686631909ULL; volatile unsigned long long mc443_35489=ma441_16638^mb442_30545; mc443_35489=((mc443_35489) + 0ULL); (void)mc443_35489; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long mt445_18869=C.cookie;mt445_18869^=49ULL;C.cookie=vm_main_int___a100e2bc_mix(mt445_18869); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 802929; } else { { volatile unsigned long long ma446_58911=1142378041ULL; volatile unsigned long long mb447_35062=679014269ULL; volatile unsigned long long mc448_41555=ma446_58911^mb447_35062; mc448_41555=(ma446_58911^mb447_35062)+((ma446_58911&mb447_35062)<<1); (void)mc448_41555; } C.state = 802929; }
      break;
    case 1002380:
      
      
      { volatile unsigned long long ma449_31546=2703656211ULL; volatile unsigned long long mb450_42861=405671821ULL; volatile unsigned long long mc451_8505=ma449_31546^mb450_42861; mc451_8505=(((mc451_8505) & (mc451_8505)) | ((mc451_8505) & 0ULL)); (void)mc451_8505; }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma452_28072=1269048555ULL; volatile unsigned long long mb453_36955=19780723ULL; volatile unsigned long long mc454_5695=ma452_28072^mb453_36955; mc454_5695=((mc454_5695) + 0ULL); (void)mc454_5695; } }
      { unsigned long long mt455_48485=C.cookie^50ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt455_48485) | 0ULL)); }
      { { volatile unsigned long long ma459_64573=1915800025ULL; volatile unsigned long long mb460_59479=1693726303ULL; volatile unsigned long long mc461_16583=ma459_64573^mb460_59479; mc461_16583=(ma459_64573^mb460_59479)+((ma459_64573&mb460_59479)<<1); (void)mc461_16583; } C.state = 263652; }
      break;
    case 665186:
      
      
      { volatile unsigned long long mh462_12899=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh462_12899; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^51ULL);
      { { volatile unsigned long long ma467_12455=127991997ULL; volatile unsigned long long mb468_18137=3011165645ULL; volatile unsigned long long mc469_4033=ma467_12455^mb468_18137; for(volatile int _i=0;_i<1;++_i) mc469_4033=vm_main_int___a100e2bc_mix(mc469_4033+_i); (void)mc469_4033; } C.state = 517944; }
      break;
    case 441868:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long mh471_52645=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh471_52645; }
      { unsigned long long mt472_9986=C.cookie^52ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt472_9986) | 0ULL)); }
      { { volatile unsigned long long ma476_47037=4018347117ULL; volatile unsigned long long mb477_43250=3400522353ULL; volatile unsigned long long mc478_28274=ma476_47037^mb477_43250; mc478_28274=(ma476_47037^mb477_43250)+((ma476_47037&mb477_43250)<<1); (void)mc478_28274; } C.state = 386655; }
      break;
    case 396408:
      
      
      { volatile unsigned long long ma479_47437=1769426727ULL; volatile unsigned long long mb480_21730=3447099629ULL; volatile unsigned long long mc481_47891=ma479_47437^mb480_21730; mc481_47891=(ma479_47437^mb480_21730)+((ma479_47437&mb480_21730)<<1); (void)mc481_47891; }
      { volatile unsigned long long mh482_54403=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh482_54403; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^53ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma484_4391=3964770047ULL; volatile unsigned long long mb485_12197=3730150811ULL; volatile unsigned long long mc486_18090=ma484_4391^mb485_12197; mc486_18090=((mc486_18090) | 0ULL); (void)mc486_18090; } } C.state = 50464;
      break;
    case 410389:
      
      
      { volatile unsigned long long ma487_44545=1451312305ULL; volatile unsigned long long mb488_33004=3662208007ULL; volatile unsigned long long mc489_15044=ma487_44545^mb488_33004; mc489_15044=(((mc489_15044) ^ (mc489_15044)) + (mc489_15044)); (void)mc489_15044; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^54ULL);
      { { volatile unsigned long long ma494_42795=990194285ULL; volatile unsigned long long mb495_21347=3908510563ULL; volatile unsigned long long mc496_45100=ma494_42795^mb495_21347; mc496_45100=(((mc496_45100) ^ (mc496_45100)) + (mc496_45100)); (void)mc496_45100; } C.state = 418474; }
      break;
    case 78553:
      
      
      { volatile unsigned long long ma497_2082=1292354501ULL; volatile unsigned long long mb498_17151=1945378925ULL; volatile unsigned long long mc499_61243=ma497_2082^mb498_17151; mc499_61243=(ma497_2082^mb498_17151)+((ma497_2082&mb498_17151)<<1); (void)mc499_61243; }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma500_57859=4267160593ULL; volatile unsigned long long mb501_54603=2815091349ULL; volatile unsigned long long mc502_30987=ma500_57859^mb501_54603; mc502_30987=((mc502_30987) + 0ULL); (void)mc502_30987; } }
      { volatile unsigned long long mt503_60319=C.cookie;mt503_60319^=55ULL;C.cookie=vm_main_int___a100e2bc_mix(mt503_60319); }
      { { volatile unsigned long long ma507_12161=1374691883ULL; volatile unsigned long long mb508_3321=3624056401ULL; volatile unsigned long long mc509_5972=ma507_12161^mb508_3321; mc509_5972=(((mc509_5972) & (mc509_5972)) | ((mc509_5972) & 0ULL)); (void)mc509_5972; } C.state = 639772; }
      break;
    case 647833:
      
      
      { volatile unsigned long long mh510_55977=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh510_55977; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^56ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma512_63825=977002479ULL; volatile unsigned long long mb513_15179=2984384317ULL; volatile unsigned long long mc514_5750=ma512_63825^mb513_15179; mc514_5750=(((mc514_5750) ^ (mc514_5750)) + (mc514_5750)); (void)mc514_5750; } } C.state = 269474;
      break;
    case 837992:
      
      
      { unsigned long long mt515_47605=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt515_47605) ^ (mt515_47605)) + (mt515_47605))); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^57ULL);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 480759; } else { { volatile unsigned long long ma517_17698=3451167613ULL; volatile unsigned long long mb518_29234=3171434919ULL; volatile unsigned long long mc519_47337=ma517_17698^mb518_29234; if((((mc519_47337 + 0ULL) ^ (mc519_47337 + 0ULL)) == 1ULL)) mc519_47337^=0xDEADULL; (void)mc519_47337; } C.state = 480759; }
      break;
    case 246039:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma520_6867=2457234473ULL; volatile unsigned long long mb521_34386=3790286313ULL; volatile unsigned long long mc522_30490=ma520_6867^mb521_34386; mc522_30490=((mc522_30490) ^ 0ULL); (void)mc522_30490; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^58ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 267965; } else { { volatile unsigned long long ma524_17437=3191190605ULL; volatile unsigned long long mb525_61183=985835447ULL; volatile unsigned long long mc526_20647=ma524_17437^mb525_61183; mc526_20647=(((mc526_20647) ^ (mc526_20647)) + (mc526_20647)); (void)mc526_20647; } C.state = 267965; }
      break;
    case 90868:
      
      
      { volatile unsigned long long ma527_2475=2805547277ULL; volatile unsigned long long mb528_47319=3969364407ULL; volatile unsigned long long mc529_31360=ma527_2475^mb528_47319; for(volatile int _i=0;_i<1;++_i) mc529_31360=vm_main_int___a100e2bc_mix(mc529_31360+_i); (void)mc529_31360; }
      { unsigned long long mt530_57760=C.cookie^59ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt530_57760) ^ (mt530_57760)) + (mt530_57760))); }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma531_39171=995099301ULL; volatile unsigned long long mb532_3179=1950164699ULL; volatile unsigned long long mc533_63004=ma531_39171^mb532_3179; for(volatile int _i=0;_i<1;++_i) mc533_63004=vm_main_int___a100e2bc_mix(mc533_63004+_i); (void)mc533_63004; } } C.state = 134309;
      break;
    case 749927:
      
      
      { volatile unsigned long long mh534_32714=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh534_32714; }
      { volatile unsigned long long ma535_44153=3600056333ULL; volatile unsigned long long mb536_62582=3012481727ULL; volatile unsigned long long mc537_62660=ma535_44153^mb536_62582; if((((mc537_62660 | 0ULL) & 0ULL) != 0ULL)) mc537_62660^=0xDEADULL; (void)mc537_62660; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^60ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma539_27910=73178403ULL; volatile unsigned long long mb540_64833=3262229713ULL; volatile unsigned long long mc541_20779=ma539_27910^mb540_64833; mc541_20779=(ma539_27910^mb540_64833)+((ma539_27910&mb540_64833)<<1); (void)mc541_20779; } } C.state = 891920;
      break;
    case 808204:
      
      
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma542_18450=4192165089ULL; volatile unsigned long long mb543_35297=3050182735ULL; volatile unsigned long long mc544_60842=ma542_18450^mb543_35297; mc544_60842=(ma542_18450^mb543_35297)+((ma542_18450&mb543_35297)<<1); (void)mc544_60842; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^61ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 750618; } else { { volatile unsigned long long ma546_20375=4202618215ULL; volatile unsigned long long mb547_11062=1300704817ULL; volatile unsigned long long mc548_62101=ma546_20375^mb547_11062; if((((mc548_62101 | 0ULL) & 0ULL) != 0ULL)) mc548_62101^=0xDEADULL; (void)mc548_62101; } C.state = 750618; }
      break;
    case 134309:
      
      
      { volatile unsigned long long ma549_30658=2846034127ULL; volatile unsigned long long mb550_33407=1167084983ULL; volatile unsigned long long mc551_32986=ma549_30658^mb550_33407; mc551_32986=(ma549_30658^mb550_33407)+((ma549_30658&mb550_33407)<<1); (void)mc551_32986; }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma552_29417=2192554141ULL; volatile unsigned long long mb553_18395=1591894253ULL; volatile unsigned long long mc554_5093=ma552_29417^mb553_18395; mc554_5093=(((mc554_5093) & (mc554_5093)) | ((mc554_5093) & 0ULL)); (void)mc554_5093; } }
      { volatile unsigned long long mt555_6201=C.cookie;mt555_6201^=62ULL;C.cookie=vm_main_int___a100e2bc_mix(mt555_6201); }
      { { volatile unsigned long long ma559_53551=4159644001ULL; volatile unsigned long long mb560_14888=3166666577ULL; volatile unsigned long long mc561_7496=ma559_53551^mb560_14888; if(((mc561_7496 ^ mc561_7496) != 0ULL)) mc561_7496^=0xDEADULL; (void)mc561_7496; } C.state = 57154; }
      break;
    case 209859:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma562_36908=1438036169ULL; volatile unsigned long long mb563_33991=3249649979ULL; volatile unsigned long long mc564_58391=ma562_36908^mb563_33991; for(volatile int _i=0;_i<1;++_i) mc564_58391=vm_main_int___a100e2bc_mix(mc564_58391+_i); (void)mc564_58391; } }
      { volatile unsigned long long mt565_32094=C.cookie;mt565_32094^=63ULL;C.cookie=vm_main_int___a100e2bc_mix(mt565_32094); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma566_51005=95197835ULL; volatile unsigned long long mb567_10668=3320699475ULL; volatile unsigned long long mc568_10452=ma566_51005^mb567_10668; if((((mc568_10452 + 0ULL) ^ (mc568_10452 + 0ULL)) == 1ULL)) mc568_10452^=0xDEADULL; (void)mc568_10452; } } C.state = 875420;
      break;
    case 329388:
      
      
      { volatile unsigned long long mh569_19982=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh569_19982; }
      { volatile unsigned long long ma570_28940=575457071ULL; volatile unsigned long long mb571_48333=3713369643ULL; volatile unsigned long long mc572_59636=ma570_28940^mb571_48333; if((((mc572_59636 * 2ULL) & 1ULL) != 0ULL)) mc572_59636^=0xDEADULL; (void)mc572_59636; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^64ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 11528; } else { { volatile unsigned long long ma574_60757=1402322253ULL; volatile unsigned long long mb575_13829=2851851143ULL; volatile unsigned long long mc576_44173=ma574_60757^mb575_13829; if((((mc576_44173 * 2ULL) & 1ULL) != 0ULL)) mc576_44173^=0xDEADULL; (void)mc576_44173; } C.state = 11528; }
      break;
    case 278926:
      
      
      { volatile unsigned long long ma577_36433=3613216891ULL; volatile unsigned long long mb578_19516=2291573995ULL; volatile unsigned long long mc579_21401=ma577_36433^mb578_19516; if(((mc579_21401 ^ mc579_21401) != 0ULL)) mc579_21401^=0xDEADULL; (void)mc579_21401; }
      { unsigned long long mt580_11195=C.cookie^65ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt580_11195) ^ 0ULL)); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 215310; } else { { volatile unsigned long long ma581_28598=1230827451ULL; volatile unsigned long long mb582_55160=774907713ULL; volatile unsigned long long mc583_21886=ma581_28598^mb582_55160; if((((mc583_21886 + 0ULL) ^ (mc583_21886 + 0ULL)) == 1ULL)) mc583_21886^=0xDEADULL; (void)mc583_21886; } C.state = 215310; }
      break;
    case 718049:
      
      
      { volatile unsigned long long mh584_1636=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh584_1636; }
      { volatile unsigned long long ma585_59760=4218811449ULL; volatile unsigned long long mb586_40941=3232890289ULL; volatile unsigned long long mc587_39615=ma585_59760^mb586_40941; for(volatile int _i=0;_i<1;++_i) mc587_39615=vm_main_int___a100e2bc_mix(mc587_39615+_i); (void)mc587_39615; }
      { unsigned long long mt588_2328=C.cookie^66ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt588_2328) | 0ULL)); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma589_17343=1441096413ULL; volatile unsigned long long mb590_23372=1121492179ULL; volatile unsigned long long mc591_55118=ma589_17343^mb590_23372; if(((mc591_55118 ^ mc591_55118) != 0ULL)) mc591_55118^=0xDEADULL; (void)mc591_55118; } } C.state = 844109;
      break;
    case 384882:
      
      
      { volatile unsigned long long mh592_55222=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh592_55222; }
      { volatile unsigned long long mh593_59343=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh593_59343; }
      { volatile unsigned long long mt594_4183=C.cookie;mt594_4183^=67ULL;C.cookie=vm_main_int___a100e2bc_mix(mt594_4183); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 151121; } else { { volatile unsigned long long ma595_12665=2885656713ULL; volatile unsigned long long mb596_20131=4227305831ULL; volatile unsigned long long mc597_46709=ma595_12665^mb596_20131; mc597_46709=((mc597_46709) | 0ULL); (void)mc597_46709; } C.state = 151121; }
      break;
    case 330667:
      
      
      { volatile unsigned long long ma598_4105=618183715ULL; volatile unsigned long long mb599_10067=3277500635ULL; volatile unsigned long long mc600_35592=ma598_4105^mb599_10067; mc600_35592=((mc600_35592) + 0ULL); (void)mc600_35592; }
      { unsigned long long mt601_26139=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt601_26139) ^ (mt601_26139)) + (mt601_26139))); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^68ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 637519; } else { { volatile unsigned long long ma603_8755=3339329337ULL; volatile unsigned long long mb604_6771=3293784173ULL; volatile unsigned long long mc605_64771=ma603_8755^mb604_6771; for(volatile int _i=0;_i<2;++_i) mc605_64771=vm_main_int___a100e2bc_mix(mc605_64771+_i); (void)mc605_64771; } C.state = 637519; }
      break;
    case 658939:
      
      
      { volatile unsigned long long ma606_48919=3513680947ULL; volatile unsigned long long mb607_38787=1800554407ULL; volatile unsigned long long mc608_59824=ma606_48919^mb607_38787; for(volatile int _i=0;_i<3;++_i) mc608_59824=vm_main_int___a100e2bc_mix(mc608_59824+_i); (void)mc608_59824; }
      { unsigned long long mt609_58392=C.cookie^69ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt609_58392) & (mt609_58392)) | ((mt609_58392) & 0ULL))); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 623159; } else { { volatile unsigned long long ma610_2192=3095925237ULL; volatile unsigned long long mb611_58981=2791219059ULL; volatile unsigned long long mc612_37423=ma610_2192^mb611_58981; mc612_37423=(ma610_2192^mb611_58981)+((ma610_2192&mb611_58981)<<1); (void)mc612_37423; } C.state = 623159; }
      break;
    case 101038:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^70ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma615_16381=3372086825ULL; volatile unsigned long long mb616_5963=1125428951ULL; volatile unsigned long long mc617_4271=ma615_16381^mb616_5963; mc617_4271=(ma615_16381^mb616_5963)+((ma615_16381&mb616_5963)<<1); (void)mc617_4271; } } C.state = 36711;
      break;
    case 253967:
      
      
      { volatile unsigned long long mh618_47549=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh618_47549; }
      { volatile unsigned long long mh619_43143=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh619_43143; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^71ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 425683; } else { { volatile unsigned long long ma621_16724=1505260351ULL; volatile unsigned long long mb622_51820=58423779ULL; volatile unsigned long long mc623_60296=ma621_16724^mb622_51820; for(volatile int _i=0;_i<3;++_i) mc623_60296=vm_main_int___a100e2bc_mix(mc623_60296+_i); (void)mc623_60296; } C.state = 425683; }
      break;
    case 145271:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long mt625_52413=C.cookie;mt625_52413^=72ULL;C.cookie=vm_main_int___a100e2bc_mix(mt625_52413); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 524080; } else { { volatile unsigned long long ma626_60178=970120893ULL; volatile unsigned long long mb627_197=318578209ULL; volatile unsigned long long mc628_63943=ma626_60178^mb627_197; mc628_63943=(((mc628_63943) & (mc628_63943)) | ((mc628_63943) & 0ULL)); (void)mc628_63943; } C.state = 524080; }
      break;
    case 877828:
      
      
      { volatile unsigned long long mh629_53549=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh629_53549; }
      { volatile unsigned long long mt630_6740=C.cookie;mt630_6740^=73ULL;C.cookie=vm_main_int___a100e2bc_mix(mt630_6740); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 125221; } else { { volatile unsigned long long ma631_3326=1414752329ULL; volatile unsigned long long mb632_26073=2578942239ULL; volatile unsigned long long mc633_43694=ma631_3326^mb632_26073; if(((mc633_43694 ^ mc633_43694) != 0ULL)) mc633_43694^=0xDEADULL; (void)mc633_43694; } C.state = 125221; }
      break;
    case 371880:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long mh635_48797=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh635_48797; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^74ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 984519; } else { { volatile unsigned long long ma637_34826=3348332783ULL; volatile unsigned long long mb638_57966=2791973343ULL; volatile unsigned long long mc639_52827=ma637_34826^mb638_57966; for(volatile int _i=0;_i<2;++_i) mc639_52827=vm_main_int___a100e2bc_mix(mc639_52827+_i); (void)mc639_52827; } C.state = 984519; }
      break;
    case 626372:
      
      
      { volatile unsigned long long mh640_22179=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh640_22179; }
      { volatile unsigned long long mt641_1344=C.cookie;mt641_1344^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt641_1344); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^75ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma643_12519=3853178859ULL; volatile unsigned long long mb644_45978=505121463ULL; volatile unsigned long long mc645_10419=ma643_12519^mb644_45978; for(volatile int _i=0;_i<3;++_i) mc645_10419=vm_main_int___a100e2bc_mix(mc645_10419+_i); (void)mc645_10419; } } C.state = 431284;
      break;
    case 263652:
      
      
      { volatile unsigned long long mt646_57319=C.cookie;mt646_57319^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt646_57319); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma647_26111=3354478127ULL; volatile unsigned long long mb648_17769=4283631621ULL; volatile unsigned long long mc649_56172=ma647_26111^mb648_17769; mc649_56172=((mc649_56172) + 0ULL); (void)mc649_56172; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^76ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 331128; } else { { volatile unsigned long long ma651_11203=1250669087ULL; volatile unsigned long long mb652_22133=746585623ULL; volatile unsigned long long mc653_2494=ma651_11203^mb652_22133; for(volatile int _i=0;_i<3;++_i) mc653_2494=vm_main_int___a100e2bc_mix(mc653_2494+_i); (void)mc653_2494; } C.state = 331128; }
      break;
    case 26643:
      
      
      { volatile unsigned long long ma654_46970=379357801ULL; volatile unsigned long long mb655_10512=4110470949ULL; volatile unsigned long long mc656_19569=ma654_46970^mb655_10512; mc656_19569=((mc656_19569) | 0ULL); (void)mc656_19569; }
      { unsigned long long mt657_59413=C.cookie^77ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt657_59413) ^ 0ULL)); }
      { { volatile unsigned long long ma661_62682=3434807167ULL; volatile unsigned long long mb662_41720=640660239ULL; volatile unsigned long long mc663_30323=ma661_62682^mb662_41720; for(volatile int _i=0;_i<2;++_i) mc663_30323=vm_main_int___a100e2bc_mix(mc663_30323+_i); (void)mc663_30323; } C.state = 842480; }
      break;
    case 397641:
      
      
      { volatile unsigned long long mh664_26124=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh664_26124; }
      { volatile unsigned long long mt665_27424=C.cookie;mt665_27424^=78ULL;C.cookie=vm_main_int___a100e2bc_mix(mt665_27424); }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma666_6437=1634394185ULL; volatile unsigned long long mb667_50552=3942950961ULL; volatile unsigned long long mc668_29397=ma666_6437^mb667_50552; mc668_29397=(((mc668_29397) & (mc668_29397)) | ((mc668_29397) & 0ULL)); (void)mc668_29397; } } C.state = 485845;
      break;
    case 692908:
      
      
      { volatile unsigned long long mh669_36730=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh669_36730; }
      { unsigned long long mt670_26999=C.cookie^79ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt670_26999) ^ (mt670_26999)) + (mt670_26999))); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 508935; } else { { volatile unsigned long long ma671_7902=2919678581ULL; volatile unsigned long long mb672_943=2573787951ULL; volatile unsigned long long mc673_18285=ma671_7902^mb672_943; mc673_18285=(ma671_7902^mb672_943)+((ma671_7902&mb672_943)<<1); (void)mc673_18285; } C.state = 508935; }
      break;
    case 610114:
      
      
      { volatile unsigned long long ma674_37830=960491715ULL; volatile unsigned long long mb675_13309=2058947267ULL; volatile unsigned long long mc676_23903=ma674_37830^mb675_13309; mc676_23903=(ma674_37830^mb675_13309)+((ma674_37830&mb675_13309)<<1); (void)mc676_23903; }
      { unsigned long long mt677_32200=C.cookie^80ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt677_32200) | 0ULL)); }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma678_5200=1599202851ULL; volatile unsigned long long mb679_21922=1525120373ULL; volatile unsigned long long mc680_27545=ma678_5200^mb679_21922; mc680_27545=((mc680_27545) | 0ULL); (void)mc680_27545; } } C.state = 65716;
      break;
    case 945152:
      
      
      { volatile unsigned long long ma681_45008=3456939737ULL; volatile unsigned long long mb682_13847=3503862357ULL; volatile unsigned long long mc683_29577=ma681_45008^mb682_13847; for(volatile int _i=0;_i<2;++_i) mc683_29577=vm_main_int___a100e2bc_mix(mc683_29577+_i); (void)mc683_29577; }
      { volatile unsigned long long mh684_12713=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh684_12713; }
      { unsigned long long mt685_8412=C.cookie^81ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt685_8412) + 0ULL)); }
      { { volatile unsigned long long ma689_3611=3702387225ULL; volatile unsigned long long mb690_64794=177375809ULL; volatile unsigned long long mc691_32396=ma689_3611^mb690_64794; mc691_32396=(((mc691_32396) & (mc691_32396)) | ((mc691_32396) & 0ULL)); (void)mc691_32396; } C.state = 20094; }
      break;
    case 351571:
      
      
      { volatile unsigned long long ma692_3496=531348299ULL; volatile unsigned long long mb693_30247=437499991ULL; volatile unsigned long long mc694_32309=ma692_3496^mb693_30247; mc694_32309=(ma692_3496^mb693_30247)+((ma692_3496&mb693_30247)<<1); (void)mc694_32309; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^82ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 78915; } else { { volatile unsigned long long ma696_33233=986082743ULL; volatile unsigned long long mb697_37420=3876265961ULL; volatile unsigned long long mc698_12355=ma696_33233^mb697_37420; mc698_12355=((mc698_12355) + 0ULL); (void)mc698_12355; } C.state = 78915; }
      break;
    case 622635:
      
      
      { volatile unsigned long long ma699_60899=1643067517ULL; volatile unsigned long long mb700_37367=2554116957ULL; volatile unsigned long long mc701_5782=ma699_60899^mb700_37367; for(volatile int _i=0;_i<1;++_i) mc701_5782=vm_main_int___a100e2bc_mix(mc701_5782+_i); (void)mc701_5782; }
      { volatile unsigned long long mh702_7410=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh702_7410; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^83ULL);
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma704_56713=2673127627ULL; volatile unsigned long long mb705_18316=3915172543ULL; volatile unsigned long long mc706_43010=ma704_56713^mb705_18316; for(volatile int _i=0;_i<1;++_i) mc706_43010=vm_main_int___a100e2bc_mix(mc706_43010+_i); (void)mc706_43010; } } C.state = 480759;
      break;
    case 331128:
      
      
      { volatile unsigned long long ma707_47117=2401772107ULL; volatile unsigned long long mb708_3979=4092788391ULL; volatile unsigned long long mc709_39845=ma707_47117^mb708_3979; for(volatile int _i=0;_i<2;++_i) mc709_39845=vm_main_int___a100e2bc_mix(mc709_39845+_i); (void)mc709_39845; }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma710_32639=580789017ULL; volatile unsigned long long mb711_20786=577724981ULL; volatile unsigned long long mc712_3253=ma710_32639^mb711_20786; mc712_3253=(((mc712_3253) ^ (mc712_3253)) + (mc712_3253)); (void)mc712_3253; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^84ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 794174; } else { { volatile unsigned long long ma714_55954=3108039911ULL; volatile unsigned long long mb715_23792=4159745745ULL; volatile unsigned long long mc716_51977=ma714_55954^mb715_23792; mc716_51977=(ma714_55954^mb715_23792)+((ma714_55954&mb715_23792)<<1); (void)mc716_51977; } C.state = 794174; }
      break;
    case 782503:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma717_51732=1939021199ULL; volatile unsigned long long mb718_38754=2967528891ULL; volatile unsigned long long mc719_30563=ma717_51732^mb718_38754; mc719_30563=(ma717_51732^mb718_38754)+((ma717_51732&mb718_38754)<<1); (void)mc719_30563; } }
      { volatile unsigned long long mt720_22975=C.cookie;mt720_22975^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt720_22975); }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^85ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 637519; } else { { volatile unsigned long long ma722_37883=1579526977ULL; volatile unsigned long long mb723_29072=1441992073ULL; volatile unsigned long long mc724_41363=ma722_37883^mb723_29072; mc724_41363=(ma722_37883^mb723_29072)+((ma722_37883&mb723_29072)<<1); (void)mc724_41363; } C.state = 637519; }
      break;
    case 943466:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma725_22314=337419117ULL; volatile unsigned long long mb726_61860=1609311983ULL; volatile unsigned long long mc727_61672=ma725_22314^mb726_61860; mc727_61672=(ma725_22314^mb726_61860)+((ma725_22314&mb726_61860)<<1); (void)mc727_61672; } }
      { volatile unsigned long long ma728_41189=1958683483ULL; volatile unsigned long long mb729_22149=3100172233ULL; volatile unsigned long long mc730_9970=ma728_41189^mb729_22149; for(volatile int _i=0;_i<1;++_i) mc730_9970=vm_main_int___a100e2bc_mix(mc730_9970+_i); (void)mc730_9970; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^86ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 536734; } else { { volatile unsigned long long ma732_56437=1855563109ULL; volatile unsigned long long mb733_18540=2443290595ULL; volatile unsigned long long mc734_5536=ma732_56437^mb733_18540; if((((mc734_5536 * 2ULL) & 1ULL) != 0ULL)) mc734_5536^=0xDEADULL; (void)mc734_5536; } C.state = 536734; }
      break;
    case 404853:
      
      
      { volatile unsigned long long ma735_40101=1162595477ULL; volatile unsigned long long mb736_5646=4192364697ULL; volatile unsigned long long mc737_6618=ma735_40101^mb736_5646; mc737_6618=((mc737_6618) + 0ULL); (void)mc737_6618; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^87ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 553130; } else { { volatile unsigned long long ma739_57363=696030793ULL; volatile unsigned long long mb740_65438=3801905517ULL; volatile unsigned long long mc741_21674=ma739_57363^mb740_65438; if(((mc741_21674 ^ mc741_21674) != 0ULL)) mc741_21674^=0xDEADULL; (void)mc741_21674; } C.state = 553130; }
      break;
    case 912532:
      
      
      { volatile unsigned long long mh742_32492=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh742_32492; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^88ULL);
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma744_17935=2932346679ULL; volatile unsigned long long mb745_55710=691894471ULL; volatile unsigned long long mc746_50482=ma744_17935^mb745_55710; mc746_50482=(ma744_17935^mb745_55710)+((ma744_17935&mb745_55710)<<1); (void)mc746_50482; } } C.state = 144484;
      break;
    case 363001:
      
      
      { volatile unsigned long long mh747_32385=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh747_32385; }
      { unsigned long long mt748_43283=C.cookie^89ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt748_43283) ^ 0ULL)); }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma749_38237=3566464599ULL; volatile unsigned long long mb750_2018=353468487ULL; volatile unsigned long long mc751_4088=ma749_38237^mb750_2018; mc751_4088=((mc751_4088) ^ 0ULL); (void)mc751_4088; } } C.state = 390458;
      break;
    case 551446:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^90ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 125221; } else { { volatile unsigned long long ma754_38385=858348893ULL; volatile unsigned long long mb755_19708=869639143ULL; volatile unsigned long long mc756_2039=ma754_38385^mb755_19708; mc756_2039=((mc756_2039) | 0ULL); (void)mc756_2039; } C.state = 125221; }
      break;
    case 1007329:
      
      
      { volatile unsigned long long mh757_19114=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh757_19114; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^91ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma759_56339=3347750067ULL; volatile unsigned long long mb760_36664=1208528615ULL; volatile unsigned long long mc761_35972=ma759_56339^mb760_36664; for(volatile int _i=0;_i<1;++_i) mc761_35972=vm_main_int___a100e2bc_mix(mc761_35972+_i); (void)mc761_35972; } } C.state = 843160;
      break;
    case 909881:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long mt763_26260=C.cookie;mt763_26260^=92ULL;C.cookie=vm_main_int___a100e2bc_mix(mt763_26260); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma764_60987=1166371187ULL; volatile unsigned long long mb765_12573=2774620447ULL; volatile unsigned long long mc766_10343=ma764_60987^mb765_12573; if(((mc766_10343 ^ mc766_10343) != 0ULL)) mc766_10343^=0xDEADULL; (void)mc766_10343; } } C.state = 485845;
      break;
    case 277803:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma767_41203=3449305839ULL; volatile unsigned long long mb768_18787=1699278023ULL; volatile unsigned long long mc769_38064=ma767_41203^mb768_18787; mc769_38064=(ma767_41203^mb768_18787)+((ma767_41203&mb768_18787)<<1); (void)mc769_38064; } }
      { volatile unsigned long long mt770_4374=C.cookie;mt770_4374^=93ULL;C.cookie=vm_main_int___a100e2bc_mix(mt770_4374); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma771_6269=1013271135ULL; volatile unsigned long long mb772_59079=566084745ULL; volatile unsigned long long mc773_43394=ma771_6269^mb772_59079; if(((mc773_43394 ^ mc773_43394) != 0ULL)) mc773_43394^=0xDEADULL; (void)mc773_43394; } } C.state = 397173;
      break;
    case 571061:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma774_62553=713650669ULL; volatile unsigned long long mb775_39812=183748041ULL; volatile unsigned long long mc776_12855=ma774_62553^mb775_39812; for(volatile int _i=0;_i<1;++_i) mc776_12855=vm_main_int___a100e2bc_mix(mc776_12855+_i); (void)mc776_12855; } }
      { volatile unsigned long long ma777_3150=1694494891ULL; volatile unsigned long long mb778_17202=1169730737ULL; volatile unsigned long long mc779_15337=ma777_3150^mb778_17202; if(((mc779_15337 ^ mc779_15337) != 0ULL)) mc779_15337^=0xDEADULL; (void)mc779_15337; }
      { volatile unsigned long long mt780_52044=C.cookie;mt780_52044^=94ULL;C.cookie=vm_main_int___a100e2bc_mix(mt780_52044); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 439098; } else { { volatile unsigned long long ma781_13861=716877297ULL; volatile unsigned long long mb782_28216=4088291201ULL; volatile unsigned long long mc783_19403=ma781_13861^mb782_28216; for(volatile int _i=0;_i<2;++_i) mc783_19403=vm_main_int___a100e2bc_mix(mc783_19403+_i); (void)mc783_19403; } C.state = 439098; }
      break;
    case 957740:
      
      
      { volatile unsigned long long mh784_23747=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh784_23747; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^95ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma786_48099=1253235449ULL; volatile unsigned long long mb787_37471=3655024849ULL; volatile unsigned long long mc788_53046=ma786_48099^mb787_37471; if((((mc788_53046 | 0ULL) & 0ULL) != 0ULL)) mc788_53046^=0xDEADULL; (void)mc788_53046; } } C.state = 126154;
      break;
    case 742082:
      
      
      { volatile unsigned long long mh789_18901=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh789_18901; }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma790_46328=666207931ULL; volatile unsigned long long mb791_36693=2443387221ULL; volatile unsigned long long mc792_20775=ma790_46328^mb791_36693; for(volatile int _i=0;_i<1;++_i) mc792_20775=vm_main_int___a100e2bc_mix(mc792_20775+_i); (void)mc792_20775; } }
      { unsigned long long mt793_34866=C.cookie^96ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt793_34866) | 0ULL)); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma794_38777=1536557681ULL; volatile unsigned long long mb795_65352=3601338583ULL; volatile unsigned long long mc796_45395=ma794_38777^mb795_65352; if(((mc796_45395 ^ mc796_45395) != 0ULL)) mc796_45395^=0xDEADULL; (void)mc796_45395; } } C.state = 258221;
      break;
    case 553018:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma797_27084=2896837807ULL; volatile unsigned long long mb798_31876=1890476611ULL; volatile unsigned long long mc799_15794=ma797_27084^mb798_31876; for(volatile int _i=0;_i<3;++_i) mc799_15794=vm_main_int___a100e2bc_mix(mc799_15794+_i); (void)mc799_15794; } }
      { volatile unsigned long long ma800_32843=2782883835ULL; volatile unsigned long long mb801_4622=3677355313ULL; volatile unsigned long long mc802_57385=ma800_32843^mb801_4622; mc802_57385=(ma800_32843^mb801_4622)+((ma800_32843&mb801_4622)<<1); (void)mc802_57385; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^97ULL);
      { { volatile unsigned long long ma807_3277=1224625937ULL; volatile unsigned long long mb808_51956=1998103917ULL; volatile unsigned long long mc809_38993=ma807_3277^mb808_51956; if((((mc809_38993 * 2ULL) & 1ULL) != 0ULL)) mc809_38993^=0xDEADULL; (void)mc809_38993; } C.state = 353028; }
      break;
    case 942970:
      
      
      { volatile unsigned long long mt810_12799=C.cookie;mt810_12799^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt810_12799); }
      { volatile unsigned long long mh811_27492=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh811_27492; }
      { unsigned long long mt812_20499=C.cookie^98ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt812_20499) ^ 0ULL)); }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma813_48601=1397573147ULL; volatile unsigned long long mb814_10210=2306146619ULL; volatile unsigned long long mc815_47013=ma813_48601^mb814_10210; mc815_47013=(ma813_48601^mb814_10210)+((ma813_48601&mb814_10210)<<1); (void)mc815_47013; } } C.state = 959754;
      break;
    case 527926:
      
      
      { volatile unsigned long long mh816_56590=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh816_56590; }
      { volatile unsigned long long mh817_46083=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh817_46083; }
      { volatile unsigned long long mt818_26238=C.cookie;mt818_26238^=99ULL;C.cookie=vm_main_int___a100e2bc_mix(mt818_26238); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 462330; } else { { volatile unsigned long long ma819_14688=867018481ULL; volatile unsigned long long mb820_64177=860095737ULL; volatile unsigned long long mc821_39920=ma819_14688^mb820_64177; mc821_39920=((mc821_39920) | 0ULL); (void)mc821_39920; } C.state = 462330; }
      break;
    case 780763:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma822_23763=633722271ULL; volatile unsigned long long mb823_3131=982685827ULL; volatile unsigned long long mc824_64553=ma822_23763^mb823_3131; mc824_64553=((mc824_64553) + 0ULL); (void)mc824_64553; } }
      { unsigned long long mt825_33786=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt825_33786) ^ 0ULL)); }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^100ULL);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 842480; } else { { volatile unsigned long long ma827_51903=4214602147ULL; volatile unsigned long long mb828_34100=4027215845ULL; volatile unsigned long long mc829_1002=ma827_51903^mb828_34100; mc829_1002=((mc829_1002) ^ 0ULL); (void)mc829_1002; } C.state = 842480; }
      break;
    case 257184:
      
      
      { volatile unsigned long long mh830_51813=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh830_51813; }
      { volatile unsigned long long mt831_1174=C.cookie;mt831_1174^=101ULL;C.cookie=vm_main_int___a100e2bc_mix(mt831_1174); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 572550; } else { { volatile unsigned long long ma832_46507=3515447707ULL; volatile unsigned long long mb833_55450=2336236053ULL; volatile unsigned long long mc834_43160=ma832_46507^mb833_55450; if((((mc834_43160 + 0ULL) ^ (mc834_43160 + 0ULL)) == 1ULL)) mc834_43160^=0xDEADULL; (void)mc834_43160; } C.state = 572550; }
      break;
    case 957466:
      
      
      { volatile unsigned long long mh835_22095=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh835_22095; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^102ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma837_65273=700856529ULL; volatile unsigned long long mb838_46701=2778347757ULL; volatile unsigned long long mc839_45628=ma837_65273^mb838_46701; if((((mc839_45628 * 2ULL) & 1ULL) != 0ULL)) mc839_45628^=0xDEADULL; (void)mc839_45628; } } C.state = 613491;
      break;
    case 119993:
      
      
      { volatile unsigned long long mh840_48280=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh840_48280; }
      { volatile unsigned long long mt841_49800=C.cookie;mt841_49800^=103ULL;C.cookie=vm_main_int___a100e2bc_mix(mt841_49800); }
      { { volatile unsigned long long ma845_11083=471625719ULL; volatile unsigned long long mb846_17919=213421053ULL; volatile unsigned long long mc847_35585=ma845_11083^mb846_17919; if(((mc847_35585 ^ mc847_35585) != 0ULL)) mc847_35585^=0xDEADULL; (void)mc847_35585; } C.state = 571422; }
      break;
    case 393923:
      
      
      { volatile unsigned long long ma848_41538=2487313039ULL; volatile unsigned long long mb849_19186=4047237657ULL; volatile unsigned long long mc850_33836=ma848_41538^mb849_19186; if((((mc850_33836 + 0ULL) ^ (mc850_33836 + 0ULL)) == 1ULL)) mc850_33836^=0xDEADULL; (void)mc850_33836; }
      { volatile unsigned long long mt851_64028=C.cookie;mt851_64028^=104ULL;C.cookie=vm_main_int___a100e2bc_mix(mt851_64028); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 354844; } else { { volatile unsigned long long ma852_57750=1602612469ULL; volatile unsigned long long mb853_25546=2789357467ULL; volatile unsigned long long mc854_50012=ma852_57750^mb853_25546; for(volatile int _i=0;_i<2;++_i) mc854_50012=vm_main_int___a100e2bc_mix(mc854_50012+_i); (void)mc854_50012; } C.state = 354844; }
      break;
    case 45192:
      
      
      { volatile unsigned long long mh855_43807=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh855_43807; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^105ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma857_45130=2654248759ULL; volatile unsigned long long mb858_35055=3121786633ULL; volatile unsigned long long mc859_4709=ma857_45130^mb858_35055; if((((mc859_4709 | 0ULL) & 0ULL) != 0ULL)) mc859_4709^=0xDEADULL; (void)mc859_4709; } } C.state = 752439;
      break;
    case 144484:
      
      
      { volatile unsigned long long mt860_46223=C.cookie;mt860_46223^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt860_46223); }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^106ULL);
      { { volatile unsigned long long ma865_43441=133993799ULL; volatile unsigned long long mb866_13452=3693983903ULL; volatile unsigned long long mc867_58849=ma865_43441^mb866_13452; mc867_58849=(ma865_43441^mb866_13452)+((ma865_43441&mb866_13452)<<1); (void)mc867_58849; } C.state = 377110; }
      break;
    case 439098:
      
      
      { volatile unsigned long long mh868_17334=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh868_17334; }
      { volatile unsigned long long ma869_6567=3541205753ULL; volatile unsigned long long mb870_64211=3255430041ULL; volatile unsigned long long mc871_17239=ma869_6567^mb870_64211; mc871_17239=((mc871_17239) | 0ULL); (void)mc871_17239; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^107ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma873_40901=280344451ULL; volatile unsigned long long mb874_58148=2247764859ULL; volatile unsigned long long mc875_18089=ma873_40901^mb874_58148; mc875_18089=(ma873_40901^mb874_58148)+((ma873_40901&mb874_58148)<<1); (void)mc875_18089; } } C.state = 932953;
      break;
    case 348310:
      
      
      { volatile unsigned long long ma876_49655=4104095277ULL; volatile unsigned long long mb877_45311=1153855959ULL; volatile unsigned long long mc878_2443=ma876_49655^mb877_45311; for(volatile int _i=0;_i<3;++_i) mc878_2443=vm_main_int___a100e2bc_mix(mc878_2443+_i); (void)mc878_2443; }
      { volatile unsigned long long mt879_23462=C.cookie;mt879_23462^=108ULL;C.cookie=vm_main_int___a100e2bc_mix(mt879_23462); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 572550; } else { { volatile unsigned long long ma880_14797=1925870709ULL; volatile unsigned long long mb881_13432=1274040101ULL; volatile unsigned long long mc882_23446=ma880_14797^mb881_13432; mc882_23446=(((mc882_23446) ^ (mc882_23446)) + (mc882_23446)); (void)mc882_23446; } C.state = 572550; }
      break;
    case 630316:
      
      
      { volatile unsigned long long mh883_36367=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh883_36367; }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma884_18417=597579303ULL; volatile unsigned long long mb885_58938=1805349825ULL; volatile unsigned long long mc886_49467=ma884_18417^mb885_58938; if((((mc886_49467 + 0ULL) ^ (mc886_49467 + 0ULL)) == 1ULL)) mc886_49467^=0xDEADULL; (void)mc886_49467; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^109ULL);
      { { volatile unsigned long long ma891_7809=3174640455ULL; volatile unsigned long long mb892_49690=2807047589ULL; volatile unsigned long long mc893_12032=ma891_7809^mb892_49690; for(volatile int _i=0;_i<2;++_i) mc893_12032=vm_main_int___a100e2bc_mix(mc893_12032+_i); (void)mc893_12032; } C.state = 750618; }
      break;
    case 562034:
      
      
      { volatile unsigned long long mh894_796=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh894_796; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^110ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma896_33812=680948361ULL; volatile unsigned long long mb897_47561=2169311879ULL; volatile unsigned long long mc898_33216=ma896_33812^mb897_47561; mc898_33216=((mc898_33216) ^ 0ULL); (void)mc898_33216; } } C.state = 859075;
      break;
    case 595737:
      
      
      { volatile unsigned long long mh899_50023=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh899_50023; }
      { unsigned long long mt900_10104=C.cookie^111ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt900_10104) & (mt900_10104)) | ((mt900_10104) & 0ULL))); }
      { { volatile unsigned long long ma904_5101=2065744613ULL; volatile unsigned long long mb905_18043=3632241457ULL; volatile unsigned long long mc906_11978=ma904_5101^mb905_18043; for(volatile int _i=0;_i<3;++_i) mc906_11978=vm_main_int___a100e2bc_mix(mc906_11978+_i); (void)mc906_11978; } C.state = 210622; }
      break;
    case 793360:
      
      
      { volatile unsigned long long mh907_30078=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh907_30078; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^112ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma909_11900=4236965681ULL; volatile unsigned long long mb910_59136=2015519467ULL; volatile unsigned long long mc911_21199=ma909_11900^mb910_59136; for(volatile int _i=0;_i<2;++_i) mc911_21199=vm_main_int___a100e2bc_mix(mc911_21199+_i); (void)mc911_21199; } } C.state = 296863;
      break;
    case 87062:
      
      
      { volatile unsigned long long mt912_52320=C.cookie;mt912_52320^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt912_52320); }
      { volatile unsigned long long mh913_15323=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh913_15323; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^113ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 277786; } else { { volatile unsigned long long ma915_19813=4242544055ULL; volatile unsigned long long mb916_61119=4214418995ULL; volatile unsigned long long mc917_43669=ma915_19813^mb916_61119; for(volatile int _i=0;_i<2;++_i) mc917_43669=vm_main_int___a100e2bc_mix(mc917_43669+_i); (void)mc917_43669; } C.state = 277786; }
      break;
    case 984519:
      
      
      { volatile unsigned long long mh918_59544=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh918_59544; }
      { volatile unsigned long long mh919_22214=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh919_22214; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^114ULL);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 342173; } else { { volatile unsigned long long ma921_33536=910942659ULL; volatile unsigned long long mb922_59826=3802189727ULL; volatile unsigned long long mc923_58593=ma921_33536^mb922_59826; for(volatile int _i=0;_i<2;++_i) mc923_58593=vm_main_int___a100e2bc_mix(mc923_58593+_i); (void)mc923_58593; } C.state = 342173; }
      break;
    case 210622:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma924_5902=2254136203ULL; volatile unsigned long long mb925_57103=3314798821ULL; volatile unsigned long long mc926_64362=ma924_5902^mb925_57103; for(volatile int _i=0;_i<1;++_i) mc926_64362=vm_main_int___a100e2bc_mix(mc926_64362+_i); (void)mc926_64362; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^115ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 464365; } else { { volatile unsigned long long ma928_5898=1017421379ULL; volatile unsigned long long mb929_27030=4173352783ULL; volatile unsigned long long mc930_10785=ma928_5898^mb929_27030; if(((mc930_10785 ^ mc930_10785) != 0ULL)) mc930_10785^=0xDEADULL; (void)mc930_10785; } C.state = 464365; }
      break;
    case 844186:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { unsigned long long mt932_28734=C.cookie^116ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt932_28734) ^ (mt932_28734)) + (mt932_28734))); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 959107; } else { { volatile unsigned long long ma933_59253=4208665147ULL; volatile unsigned long long mb934_43061=4057156609ULL; volatile unsigned long long mc935_26396=ma933_59253^mb934_43061; mc935_26396=(((mc935_26396) & (mc935_26396)) | ((mc935_26396) & 0ULL)); (void)mc935_26396; } C.state = 959107; }
      break;
    case 151121:
      
      
      { volatile unsigned long long ma936_15973=1732622463ULL; volatile unsigned long long mb937_9746=3126373605ULL; volatile unsigned long long mc938_25593=ma936_15973^mb937_9746; for(volatile int _i=0;_i<1;++_i) mc938_25593=vm_main_int___a100e2bc_mix(mc938_25593+_i); (void)mc938_25593; }
      { unsigned long long mt939_56701=C.cookie^117ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt939_56701) + 0ULL)); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 393959; } else { { volatile unsigned long long ma940_29292=615809863ULL; volatile unsigned long long mb941_13962=4258672731ULL; volatile unsigned long long mc942_48230=ma940_29292^mb941_13962; mc942_48230=(ma940_29292^mb941_13962)+((ma940_29292&mb941_13962)<<1); (void)mc942_48230; } C.state = 393959; }
      break;
    case 1002436:
      
      
      { volatile unsigned long long mh943_60576=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh943_60576; }
      { volatile unsigned long long mt944_47240=C.cookie;mt944_47240^=118ULL;C.cookie=vm_main_int___a100e2bc_mix(mt944_47240); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 314028; } else { { volatile unsigned long long ma945_19440=1002856159ULL; volatile unsigned long long mb946_59341=1459704195ULL; volatile unsigned long long mc947_35320=ma945_19440^mb946_59341; mc947_35320=(((mc947_35320) & (mc947_35320)) | ((mc947_35320) & 0ULL)); (void)mc947_35320; } C.state = 314028; }
      break;
    case 431284:
      
      
      { volatile unsigned long long mh948_10191=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh948_10191; }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma949_46343=3265538211ULL; volatile unsigned long long mb950_9557=967621357ULL; volatile unsigned long long mc951_16474=ma949_46343^mb950_9557; mc951_16474=(ma949_46343^mb950_9557)+((ma949_46343&mb950_9557)<<1); (void)mc951_16474; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^119ULL);
      { { volatile unsigned long long ma956_31456=1178159925ULL; volatile unsigned long long mb957_61845=3733412939ULL; volatile unsigned long long mc958_42516=ma956_31456^mb957_61845; for(volatile int _i=0;_i<3;++_i) mc958_42516=vm_main_int___a100e2bc_mix(mc958_42516+_i); (void)mc958_42516; } C.state = 256404; }
      break;
    case 665088:
      
      
      { volatile unsigned long long ma959_53391=696797051ULL; volatile unsigned long long mb960_56767=2182843579ULL; volatile unsigned long long mc961_59916=ma959_53391^mb960_56767; if((((mc961_59916 * 2ULL) & 1ULL) != 0ULL)) mc961_59916^=0xDEADULL; (void)mc961_59916; }
      { unsigned long long mt962_32985=C.cookie^120ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt962_32985) ^ 0ULL)); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 959754; } else { { volatile unsigned long long ma963_22162=1324916081ULL; volatile unsigned long long mb964_13737=2460916873ULL; volatile unsigned long long mc965_54516=ma963_22162^mb964_13737; mc965_54516=(ma963_22162^mb964_13737)+((ma963_22162&mb964_13737)<<1); (void)mc965_54516; } C.state = 959754; }
      break;
    case 354844:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma966_3869=3521249257ULL; volatile unsigned long long mb967_63287=2463819573ULL; volatile unsigned long long mc968_45407=ma966_3869^mb967_63287; mc968_45407=((mc968_45407) | 0ULL); (void)mc968_45407; } }
      { unsigned long long mt969_37997=C.cookie^121ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt969_37997) ^ 0ULL)); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 258221; } else { { volatile unsigned long long ma970_64371=1199530525ULL; volatile unsigned long long mb971_61219=4230400195ULL; volatile unsigned long long mc972_9989=ma970_64371^mb971_61219; for(volatile int _i=0;_i<3;++_i) mc972_9989=vm_main_int___a100e2bc_mix(mc972_9989+_i); (void)mc972_9989; } C.state = 258221; }
      break;
    case 875420:
      
      
      { volatile unsigned long long ma973_4442=3343604661ULL; volatile unsigned long long mb974_20847=2230599195ULL; volatile unsigned long long mc975_5123=ma973_4442^mb974_20847; mc975_5123=((mc975_5123) + 0ULL); (void)mc975_5123; }
      { volatile unsigned long long mt976_35449=C.cookie;mt976_35449^=122ULL;C.cookie=vm_main_int___a100e2bc_mix(mt976_35449); }
      { { volatile unsigned long long ma980_61915=3741641713ULL; volatile unsigned long long mb981_46800=1694038549ULL; volatile unsigned long long mc982_30666=ma980_61915^mb981_46800; if((((mc982_30666 | 0ULL) & 0ULL) != 0ULL)) mc982_30666^=0xDEADULL; (void)mc982_30666; } C.state = 409896; }
      break;
    case 794174:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma983_55437=1229505125ULL; volatile unsigned long long mb984_17029=2537354335ULL; volatile unsigned long long mc985_57691=ma983_55437^mb984_17029; mc985_57691=((mc985_57691) + 0ULL); (void)mc985_57691; } }
      { volatile unsigned long long mt986_6925=C.cookie;mt986_6925^=123ULL;C.cookie=vm_main_int___a100e2bc_mix(mt986_6925); }
      { { volatile unsigned long long ma990_34604=1736327153ULL; volatile unsigned long long mb991_56311=565290047ULL; volatile unsigned long long mc992_5690=ma990_34604^mb991_56311; for(volatile int _i=0;_i<2;++_i) mc992_5690=vm_main_int___a100e2bc_mix(mc992_5690+_i); (void)mc992_5690; } C.state = 296905; }
      break;
    case 591614:
      
      
      { volatile unsigned long long mt993_46983=C.cookie;mt993_46983^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt993_46983); }
      { volatile unsigned long long mh994_47523=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh994_47523; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^124ULL);
      { { volatile unsigned long long ma999_23175=585545237ULL; volatile unsigned long long mb1000_27730=793828825ULL; volatile unsigned long long mc1001_6102=ma999_23175^mb1000_27730; mc1001_6102=((mc1001_6102) + 0ULL); (void)mc1001_6102; } C.state = 859075; }
      break;
    case 46112:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^125ULL);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 750618; } else { { volatile unsigned long long ma1005_34577=4028882975ULL; volatile unsigned long long mb1006_41370=723886083ULL; volatile unsigned long long mc1007_52872=ma1005_34577^mb1006_41370; mc1007_52872=((mc1007_52872) + 0ULL); (void)mc1007_52872; } C.state = 750618; }
      break;
    case 38627:
      
      
      { volatile unsigned long long mh1008_37711=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1008_37711; }
      { unsigned long long mt1009_38353=C.cookie^126ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1009_38353) & (mt1009_38353)) | ((mt1009_38353) & 0ULL))); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1010_41660=3379760533ULL; volatile unsigned long long mb1011_8081=4287352315ULL; volatile unsigned long long mc1012_54122=ma1010_41660^mb1011_8081; mc1012_54122=((mc1012_54122) ^ 0ULL); (void)mc1012_54122; } } C.state = 524080;
      break;
    case 806766:
      
      
      { volatile unsigned long long mh1013_20181=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1013_20181; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^127ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1015_43572=1059986691ULL; volatile unsigned long long mb1016_18327=2976002469ULL; volatile unsigned long long mc1017_21165=ma1015_43572^mb1016_18327; if(((mc1017_21165 ^ mc1017_21165) != 0ULL)) mc1017_21165^=0xDEADULL; (void)mc1017_21165; } } C.state = 621700;
      break;
    case 854692:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1018_44229=3156985117ULL; volatile unsigned long long mb1019_462=3268723485ULL; volatile unsigned long long mc1020_49968=ma1018_44229^mb1019_462; for(volatile int _i=0;_i<2;++_i) mc1020_49968=vm_main_int___a100e2bc_mix(mc1020_49968+_i); (void)mc1020_49968; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^128ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 150460; } else { { volatile unsigned long long ma1022_62933=2059133995ULL; volatile unsigned long long mb1023_38076=1432031941ULL; volatile unsigned long long mc1024_25076=ma1022_62933^mb1023_38076; if((((mc1024_25076 | 0ULL) & 0ULL) != 0ULL)) mc1024_25076^=0xDEADULL; (void)mc1024_25076; } C.state = 150460; }
      break;
    case 935666:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1025_7948=1841597177ULL; volatile unsigned long long mb1026_11675=1544759761ULL; volatile unsigned long long mc1027_60688=ma1025_7948^mb1026_11675; mc1027_60688=(ma1025_7948^mb1026_11675)+((ma1025_7948&mb1026_11675)<<1); (void)mc1027_60688; } }
      { volatile unsigned long long mh1028_29068=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1028_29068; }
      { volatile unsigned long long mt1029_9628=C.cookie;mt1029_9628^=129ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1029_9628); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 422046; } else { { volatile unsigned long long ma1030_20666=734195621ULL; volatile unsigned long long mb1031_27302=3388667799ULL; volatile unsigned long long mc1032_39246=ma1030_20666^mb1031_27302; mc1032_39246=(ma1030_20666^mb1031_27302)+((ma1030_20666&mb1031_27302)<<1); (void)mc1032_39246; } C.state = 422046; }
      break;
    case 601577:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1033_39606=2272193947ULL; volatile unsigned long long mb1034_17756=372608511ULL; volatile unsigned long long mc1035_40162=ma1033_39606^mb1034_17756; mc1035_40162=(ma1033_39606^mb1034_17756)+((ma1033_39606&mb1034_17756)<<1); (void)mc1035_40162; } }
      { volatile unsigned long long mh1036_34289=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1036_34289; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^130ULL);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 316821; } else { { volatile unsigned long long ma1038_17161=2967019095ULL; volatile unsigned long long mb1039_9530=2393364779ULL; volatile unsigned long long mc1040_23361=ma1038_17161^mb1039_9530; mc1040_23361=(ma1038_17161^mb1039_9530)+((ma1038_17161&mb1039_9530)<<1); (void)mc1040_23361; } C.state = 316821; }
      break;
    case 1000488:
      
      
      { volatile unsigned long long ma1041_19400=388189895ULL; volatile unsigned long long mb1042_42329=137827735ULL; volatile unsigned long long mc1043_45828=ma1041_19400^mb1042_42329; mc1043_45828=(((mc1043_45828) & (mc1043_45828)) | ((mc1043_45828) & 0ULL)); (void)mc1043_45828; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long mt1045_11435=C.cookie;mt1045_11435^=131ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1045_11435); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1046_22208=2076436051ULL; volatile unsigned long long mb1047_31429=284973427ULL; volatile unsigned long long mc1048_63737=ma1046_22208^mb1047_31429; if(((mc1048_63737 ^ mc1048_63737) != 0ULL)) mc1048_63737^=0xDEADULL; (void)mc1048_63737; } } C.state = 613491;
      break;
    case 685476:
      
      
      { volatile unsigned long long ma1049_18343=134862513ULL; volatile unsigned long long mb1050_4374=766022817ULL; volatile unsigned long long mc1051_32221=ma1049_18343^mb1050_4374; for(volatile int _i=0;_i<2;++_i) mc1051_32221=vm_main_int___a100e2bc_mix(mc1051_32221+_i); (void)mc1051_32221; }
      { volatile unsigned long long ma1052_50262=4193226179ULL; volatile unsigned long long mb1053_62027=3748114021ULL; volatile unsigned long long mc1054_52365=ma1052_50262^mb1053_62027; mc1054_52365=(ma1052_50262^mb1053_62027)+((ma1052_50262&mb1053_62027)<<1); (void)mc1054_52365; }
      { volatile unsigned long long mt1055_14209=C.cookie;mt1055_14209^=132ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1055_14209); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1056_50609=2130202283ULL; volatile unsigned long long mb1057_25613=36359137ULL; volatile unsigned long long mc1058_37104=ma1056_50609^mb1057_25613; mc1058_37104=(ma1056_50609^mb1057_25613)+((ma1056_50609&mb1057_25613)<<1); (void)mc1058_37104; } } C.state = 553130;
      break;
    case 843160:
      
      
      { volatile unsigned long long ma1059_32410=683409515ULL; volatile unsigned long long mb1060_5239=2147756137ULL; volatile unsigned long long mc1061_13504=ma1059_32410^mb1060_5239; if((((mc1061_13504 * 2ULL) & 1ULL) != 0ULL)) mc1061_13504^=0xDEADULL; (void)mc1061_13504; }
      { volatile unsigned long long ma1062_62909=3573303645ULL; volatile unsigned long long mb1063_23321=3197324885ULL; volatile unsigned long long mc1064_44897=ma1062_62909^mb1063_23321; mc1064_44897=((mc1064_44897) + 0ULL); (void)mc1064_44897; }
      { volatile unsigned long long mt1065_35159=C.cookie;mt1065_35159^=133ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1065_35159); }
      { { volatile unsigned long long ma1069_48054=4257616707ULL; volatile unsigned long long mb1070_6943=3020894103ULL; volatile unsigned long long mc1071_62728=ma1069_48054^mb1070_6943; for(volatile int _i=0;_i<2;++_i) mc1071_62728=vm_main_int___a100e2bc_mix(mc1071_62728+_i); (void)mc1071_62728; } C.state = 764571; }
      break;
    case 333407:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { unsigned long long mt1073_18500=C.cookie^134ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1073_18500) & (mt1073_18500)) | ((mt1073_18500) & 0ULL))); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 120157; } else { { volatile unsigned long long ma1074_2301=3606062775ULL; volatile unsigned long long mb1075_9891=1044908723ULL; volatile unsigned long long mc1076_40553=ma1074_2301^mb1075_9891; mc1076_40553=((mc1076_40553) ^ 0ULL); (void)mc1076_40553; } C.state = 120157; }
      break;
    case 944120:
      
      
      { volatile unsigned long long mh1077_52194=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1077_52194; }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1078_10234=3218241119ULL; volatile unsigned long long mb1079_18187=3338901509ULL; volatile unsigned long long mc1080_7372=ma1078_10234^mb1079_18187; mc1080_7372=((mc1080_7372) | 0ULL); (void)mc1080_7372; } }
      { unsigned long long mt1081_1819=C.cookie^135ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1081_1819) | 0ULL)); }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1082_14850=936252007ULL; volatile unsigned long long mb1083_7176=2519317391ULL; volatile unsigned long long mc1084_45253=ma1082_14850^mb1083_7176; mc1084_45253=(((mc1084_45253) & (mc1084_45253)) | ((mc1084_45253) & 0ULL)); (void)mc1084_45253; } } C.state = 995650;
      break;
    case 454389:
      
      
      { volatile unsigned long long ma1085_16583=423038015ULL; volatile unsigned long long mb1086_2419=1203749707ULL; volatile unsigned long long mc1087_12295=ma1085_16583^mb1086_2419; if((((mc1087_12295 | 0ULL) & 0ULL) != 0ULL)) mc1087_12295^=0xDEADULL; (void)mc1087_12295; }
      { unsigned long long mt1088_4898=C.cookie^136ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1088_4898) | 0ULL)); }
      { { volatile unsigned long long ma1092_30774=1862697929ULL; volatile unsigned long long mb1093_4195=61559617ULL; volatile unsigned long long mc1094_64527=ma1092_30774^mb1093_4195; mc1094_64527=(((mc1094_64527) ^ (mc1094_64527)) + (mc1094_64527)); (void)mc1094_64527; } C.state = 366674; }
      break;
    case 959754:
      
      
      { unsigned long long mt1095_2946=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1095_2946) ^ 0ULL)); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^137ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1097_28894=2100206833ULL; volatile unsigned long long mb1098_6663=2415481221ULL; volatile unsigned long long mc1099_4573=ma1097_28894^mb1098_6663; if((((mc1099_4573 * 2ULL) & 1ULL) != 0ULL)) mc1099_4573^=0xDEADULL; (void)mc1099_4573; } } C.state = 377110;
      break;
    case 508935:
      
      
      { volatile unsigned long long ma1100_27372=1390236415ULL; volatile unsigned long long mb1101_56031=401312117ULL; volatile unsigned long long mc1102_60026=ma1100_27372^mb1101_56031; for(volatile int _i=0;_i<2;++_i) mc1102_60026=vm_main_int___a100e2bc_mix(mc1102_60026+_i); (void)mc1102_60026; }
      { volatile unsigned long long ma1103_53488=3755618279ULL; volatile unsigned long long mb1104_44899=1217730299ULL; volatile unsigned long long mc1105_57288=ma1103_53488^mb1104_44899; mc1105_57288=(ma1103_53488^mb1104_44899)+((ma1103_53488&mb1104_44899)<<1); (void)mc1105_57288; }
      { volatile unsigned long long mt1106_16212=C.cookie;mt1106_16212^=138ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1106_16212); }
      { { volatile unsigned long long ma1110_49557=163441523ULL; volatile unsigned long long mb1111_17767=4147300935ULL; volatile unsigned long long mc1112_48359=ma1110_49557^mb1111_17767; if((((mc1112_48359 + 0ULL) ^ (mc1112_48359 + 0ULL)) == 1ULL)) mc1112_48359^=0xDEADULL; (void)mc1112_48359; } C.state = 468017; }
      break;
    case 256404:
      
      
      { volatile unsigned long long mh1113_30337=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1113_30337; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^139ULL);
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1116_16288=273121827ULL; volatile unsigned long long mb1117_50609=3872392787ULL; volatile unsigned long long mc1118_46015=ma1116_16288^mb1117_50609; mc1118_46015=(ma1116_16288^mb1117_50609)+((ma1116_16288&mb1117_50609)<<1); (void)mc1118_46015; } } C.state = 782313;
      break;
    case 22423:
      
      
      { volatile unsigned long long mh1119_27706=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1119_27706; }
      { volatile unsigned long long ma1120_16831=4153162281ULL; volatile unsigned long long mb1121_28214=416614535ULL; volatile unsigned long long mc1122_22241=ma1120_16831^mb1121_28214; mc1122_22241=(ma1120_16831^mb1121_28214)+((ma1120_16831&mb1121_28214)<<1); (void)mc1122_22241; }
      { volatile unsigned long long mt1123_54008=C.cookie;mt1123_54008^=140ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1123_54008); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 118551; } else { { volatile unsigned long long ma1124_41792=3024509595ULL; volatile unsigned long long mb1125_30909=3758197573ULL; volatile unsigned long long mc1126_4835=ma1124_41792^mb1125_30909; for(volatile int _i=0;_i<1;++_i) mc1126_4835=vm_main_int___a100e2bc_mix(mc1126_4835+_i); (void)mc1126_4835; } C.state = 118551; }
      break;
    case 828784:
      
      
      { volatile unsigned long long ma1127_32275=1589028425ULL; volatile unsigned long long mb1128_23272=829804169ULL; volatile unsigned long long mc1129_31869=ma1127_32275^mb1128_23272; if((((mc1129_31869 + 0ULL) ^ (mc1129_31869 + 0ULL)) == 1ULL)) mc1129_31869^=0xDEADULL; (void)mc1129_31869; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^141ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 592142; } else { { volatile unsigned long long ma1131_61367=232563013ULL; volatile unsigned long long mb1132_54257=3590946699ULL; volatile unsigned long long mc1133_33130=ma1131_61367^mb1132_54257; mc1133_33130=(ma1131_61367^mb1132_54257)+((ma1131_61367&mb1132_54257)<<1); (void)mc1133_33130; } C.state = 592142; }
      break;
    case 154684:
      
      
      { volatile unsigned long long ma1134_47393=4266940665ULL; volatile unsigned long long mb1135_56807=1473278905ULL; volatile unsigned long long mc1136_56919=ma1134_47393^mb1135_56807; mc1136_56919=((mc1136_56919) ^ 0ULL); (void)mc1136_56919; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^142ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 713625; } else { { volatile unsigned long long ma1138_5657=2728365665ULL; volatile unsigned long long mb1139_47765=1921417971ULL; volatile unsigned long long mc1140_6728=ma1138_5657^mb1139_47765; mc1140_6728=((mc1140_6728) ^ 0ULL); (void)mc1140_6728; } C.state = 713625; }
      break;
    case 627826:
      
      
      { volatile unsigned long long mh1141_39921=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1141_39921; }
      { volatile unsigned long long mh1142_15162=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1142_15162; }
      { unsigned long long mt1143_65418=C.cookie^143ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1143_65418) | 0ULL)); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 639772; } else { { volatile unsigned long long ma1144_14690=464834217ULL; volatile unsigned long long mb1145_36676=2174883351ULL; volatile unsigned long long mc1146_47319=ma1144_14690^mb1145_36676; for(volatile int _i=0;_i<2;++_i) mc1146_47319=vm_main_int___a100e2bc_mix(mc1146_47319+_i); (void)mc1146_47319; } C.state = 639772; }
      break;
    case 341051:
      
      
      { volatile unsigned long long mh1147_18685=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1147_18685; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long mt1149_13166=C.cookie;mt1149_13166^=144ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1149_13166); }
      { { volatile unsigned long long ma1153_36144=3196451997ULL; volatile unsigned long long mb1154_22761=3121463563ULL; volatile unsigned long long mc1155_19675=ma1153_36144^mb1154_22761; for(volatile int _i=0;_i<1;++_i) mc1155_19675=vm_main_int___a100e2bc_mix(mc1155_19675+_i); (void)mc1155_19675; } C.state = 877299; }
      break;
    case 623159:
      
      
      { volatile unsigned long long ma1156_31146=920377157ULL; volatile unsigned long long mb1157_53026=715299049ULL; volatile unsigned long long mc1158_55559=ma1156_31146^mb1157_53026; mc1158_55559=((mc1158_55559) + 0ULL); (void)mc1158_55559; }
      { unsigned long long mt1159_42232=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt1159_42232) & (mt1159_42232)) | ((mt1159_42232) & 0ULL))); }
      { unsigned long long mt1160_54209=C.cookie^145ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1160_54209) ^ 0ULL)); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 662711; } else { { volatile unsigned long long ma1161_29996=3256596623ULL; volatile unsigned long long mb1162_15975=3315916493ULL; volatile unsigned long long mc1163_17746=ma1161_29996^mb1162_15975; mc1163_17746=(ma1161_29996^mb1162_15975)+((ma1161_29996&mb1162_15975)<<1); (void)mc1163_17746; } C.state = 662711; }
      break;
    case 780216:
      
      
      { volatile unsigned long long mh1164_19510=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1164_19510; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^146ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 740973; } else { { volatile unsigned long long ma1166_35936=4206389823ULL; volatile unsigned long long mb1167_18250=1594384603ULL; volatile unsigned long long mc1168_8574=ma1166_35936^mb1167_18250; if(((mc1168_8574 ^ mc1168_8574) != 0ULL)) mc1168_8574^=0xDEADULL; (void)mc1168_8574; } C.state = 740973; }
      break;
    case 215310:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { unsigned long long mt1171_20590=C.cookie^147ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1171_20590) + 0ULL)); }
      { { volatile unsigned long long ma1175_20509=415210247ULL; volatile unsigned long long mb1176_60959=2679448979ULL; volatile unsigned long long mc1177_21762=ma1175_20509^mb1176_60959; for(volatile int _i=0;_i<3;++_i) mc1177_21762=vm_main_int___a100e2bc_mix(mc1177_21762+_i); (void)mc1177_21762; } C.state = 583038; }
      break;
    case 436926:
      
      
      { volatile unsigned long long mh1178_10846=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1178_10846; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^148ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 970994; } else { { volatile unsigned long long ma1180_43201=543712589ULL; volatile unsigned long long mb1181_5448=3090524753ULL; volatile unsigned long long mc1182_5892=ma1180_43201^mb1181_5448; mc1182_5892=(ma1180_43201^mb1181_5448)+((ma1180_43201&mb1181_5448)<<1); (void)mc1182_5892; } C.state = 970994; }
      break;
    case 844109:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long mt1184_28632=C.cookie;mt1184_28632^=149ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1184_28632); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 176058; } else { { volatile unsigned long long ma1185_42040=2605767575ULL; volatile unsigned long long mb1186_23217=1753412789ULL; volatile unsigned long long mc1187_62496=ma1185_42040^mb1186_23217; mc1187_62496=(ma1185_42040^mb1186_23217)+((ma1185_42040&mb1186_23217)<<1); (void)mc1187_62496; } C.state = 176058; }
      break;
    case 827821:
      
      
      { volatile unsigned long long mh1188_61457=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1188_61457; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^150ULL);
      { { volatile unsigned long long ma1193_14854=3283404785ULL; volatile unsigned long long mb1194_54833=4022281351ULL; volatile unsigned long long mc1195_61706=ma1193_14854^mb1194_54833; mc1195_61706=(((mc1195_61706) & (mc1195_61706)) | ((mc1195_61706) & 0ULL)); (void)mc1195_61706; } C.state = 774710; }
      break;
    case 1000748:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long ma1197_51306=2964288425ULL; volatile unsigned long long mb1198_1637=58813679ULL; volatile unsigned long long mc1199_12480=ma1197_51306^mb1198_1637; for(volatile int _i=0;_i<3;++_i) mc1199_12480=vm_main_int___a100e2bc_mix(mc1199_12480+_i); (void)mc1199_12480; }
      { unsigned long long mt1200_28383=C.cookie^151ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1200_28383) + 0ULL)); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1201_57755=1915412393ULL; volatile unsigned long long mb1202_36903=583251135ULL; volatile unsigned long long mc1203_24620=ma1201_57755^mb1202_36903; mc1203_24620=(ma1201_57755^mb1202_36903)+((ma1201_57755&mb1202_36903)<<1); (void)mc1203_24620; } } C.state = 536734;
      break;
    case 196711:
      
      
      { volatile unsigned long long ma1204_37228=2982342471ULL; volatile unsigned long long mb1205_9845=3351947785ULL; volatile unsigned long long mc1206_44731=ma1204_37228^mb1205_9845; for(volatile int _i=0;_i<1;++_i) mc1206_44731=vm_main_int___a100e2bc_mix(mc1206_44731+_i); (void)mc1206_44731; }
      { unsigned long long mt1207_14827=C.cookie^152ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1207_14827) ^ (mt1207_14827)) + (mt1207_14827))); }
      { { volatile unsigned long long ma1211_59946=609825351ULL; volatile unsigned long long mb1212_12830=4034883989ULL; volatile unsigned long long mc1213_52905=ma1211_59946^mb1212_12830; mc1213_52905=(((mc1213_52905) & (mc1213_52905)) | ((mc1213_52905) & 0ULL)); (void)mc1213_52905; } C.state = 877299; }
      break;
    case 362362:
      
      
      { volatile unsigned long long ma1214_37670=1922538301ULL; volatile unsigned long long mb1215_20843=2808274733ULL; volatile unsigned long long mc1216_23872=ma1214_37670^mb1215_20843; for(volatile int _i=0;_i<1;++_i) mc1216_23872=vm_main_int___a100e2bc_mix(mc1216_23872+_i); (void)mc1216_23872; }
      { unsigned long long mt1217_26787=C.cookie^153ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1217_26787) ^ 0ULL)); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1218_36662=3440524859ULL; volatile unsigned long long mb1219_41586=616029803ULL; volatile unsigned long long mc1220_13699=ma1218_36662^mb1219_41586; for(volatile int _i=0;_i<2;++_i) mc1220_13699=vm_main_int___a100e2bc_mix(mc1220_13699+_i); (void)mc1220_13699; } } C.state = 422046;
      break;
    case 973913:
      
      
      { volatile unsigned long long mh1221_1317=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1221_1317; }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1222_58509=3189039765ULL; volatile unsigned long long mb1223_7177=3901868321ULL; volatile unsigned long long mc1224_5762=ma1222_58509^mb1223_7177; mc1224_5762=(ma1222_58509^mb1223_7177)+((ma1222_58509&mb1223_7177)<<1); (void)mc1224_5762; } }
      { unsigned long long mt1225_38757=C.cookie^154ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1225_38757) + 0ULL)); }
      { { volatile unsigned long long ma1229_16848=114073501ULL; volatile unsigned long long mb1230_54072=1393564241ULL; volatile unsigned long long mc1231_52404=ma1229_16848^mb1230_54072; if((((mc1231_52404 + 0ULL) ^ (mc1231_52404 + 0ULL)) == 1ULL)) mc1231_52404^=0xDEADULL; (void)mc1231_52404; } C.state = 480759; }
      break;
    case 639772:
      
      
      { volatile unsigned long long mh1232_54886=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1232_54886; }
      { volatile unsigned long long ma1233_25755=3844352187ULL; volatile unsigned long long mb1234_57307=3486258163ULL; volatile unsigned long long mc1235_39728=ma1233_25755^mb1234_57307; if((((mc1235_39728 * 2ULL) & 1ULL) != 0ULL)) mc1235_39728^=0xDEADULL; (void)mc1235_39728; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^155ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1237_18389=1046292267ULL; volatile unsigned long long mb1238_20015=1394642359ULL; volatile unsigned long long mc1239_4662=ma1237_18389^mb1238_20015; for(volatile int _i=0;_i<1;++_i) mc1239_4662=vm_main_int___a100e2bc_mix(mc1239_4662+_i); (void)mc1239_4662; } } C.state = 802929;
      break;
    case 365616:
      
      
      { volatile unsigned long long ma1240_52754=3232928301ULL; volatile unsigned long long mb1241_31269=3027360573ULL; volatile unsigned long long mc1242_37032=ma1240_52754^mb1241_31269; mc1242_37032=(ma1240_52754^mb1241_31269)+((ma1240_52754&mb1241_31269)<<1); (void)mc1242_37032; }
      { unsigned long long mt1243_2297=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt1243_2297) & (mt1243_2297)) | ((mt1243_2297) & 0ULL))); }
      { unsigned long long mt1244_35695=C.cookie^156ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1244_35695) | 0ULL)); }
      { { volatile unsigned long long ma1248_5228=4270890639ULL; volatile unsigned long long mb1249_50555=719020627ULL; volatile unsigned long long mc1250_45014=ma1248_5228^mb1249_50555; mc1250_45014=(ma1248_5228^mb1249_50555)+((ma1248_5228&mb1249_50555)<<1); (void)mc1250_45014; } C.state = 662711; }
      break;
    case 258221:
      
      
      { unsigned long long mt1251_41445=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt1251_41445) & (mt1251_41445)) | ((mt1251_41445) & 0ULL))); }
      { volatile unsigned long long mh1252_26514=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1252_26514; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^157ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 418474; } else { { volatile unsigned long long ma1254_44754=3295004799ULL; volatile unsigned long long mb1255_17042=1671559105ULL; volatile unsigned long long mc1256_34626=ma1254_44754^mb1255_17042; for(volatile int _i=0;_i<3;++_i) mc1256_34626=vm_main_int___a100e2bc_mix(mc1256_34626+_i); (void)mc1256_34626; } C.state = 418474; }
      break;
    case 468017:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1258_7537=1365780029ULL; volatile unsigned long long mb1259_13290=345483135ULL; volatile unsigned long long mc1260_58656=ma1258_7537^mb1259_13290; mc1260_58656=(ma1258_7537^mb1259_13290)+((ma1258_7537&mb1259_13290)<<1); (void)mc1260_58656; } }
      { volatile unsigned long long mt1261_15992=C.cookie;mt1261_15992^=158ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1261_15992); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1262_53783=2368118493ULL; volatile unsigned long long mb1263_25193=2786254499ULL; volatile unsigned long long mc1264_50008=ma1262_53783^mb1263_25193; mc1264_50008=(ma1262_53783^mb1263_25193)+((ma1262_53783&mb1263_25193)<<1); (void)mc1264_50008; } } C.state = 277786;
      break;
    case 524080:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { unsigned long long mt1266_9814=C.cookie^159ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1266_9814) ^ (mt1266_9814)) + (mt1266_9814))); }
      { { volatile unsigned long long ma1270_33159=916069469ULL; volatile unsigned long long mb1271_44302=4251943199ULL; volatile unsigned long long mc1272_30217=ma1270_33159^mb1271_44302; for(volatile int _i=0;_i<2;++_i) mc1272_30217=vm_main_int___a100e2bc_mix(mc1272_30217+_i); (void)mc1272_30217; } C.state = 952311; }
      break;
    case 593343:
      
      
      { volatile unsigned long long mh1273_26663=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1273_26663; }
      { volatile unsigned long long mh1274_47276=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1274_47276; }
      { volatile unsigned long long mt1275_44799=C.cookie;mt1275_44799^=160ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1275_44799); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 782313; } else { { volatile unsigned long long ma1276_59936=2514937385ULL; volatile unsigned long long mb1277_42584=704756383ULL; volatile unsigned long long mc1278_26359=ma1276_59936^mb1277_42584; for(volatile int _i=0;_i<1;++_i) mc1278_26359=vm_main_int___a100e2bc_mix(mc1278_26359+_i); (void)mc1278_26359; } C.state = 782313; }
      break;
    case 705163:
      
      
      { volatile unsigned long long mt1279_2321=C.cookie;mt1279_2321^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt1279_2321); }
      { volatile unsigned long long mh1280_36255=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1280_36255; }
      { unsigned long long mt1281_18625=C.cookie^161ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1281_18625) | 0ULL)); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 296863; } else { { volatile unsigned long long ma1282_2973=980204041ULL; volatile unsigned long long mb1283_4795=2587944745ULL; volatile unsigned long long mc1284_5569=ma1282_2973^mb1283_4795; if((((mc1284_5569 * 2ULL) & 1ULL) != 0ULL)) mc1284_5569^=0xDEADULL; (void)mc1284_5569; } C.state = 296863; }
      break;
    case 568367:
      
      
      { volatile unsigned long long mh1285_33450=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1285_33450; }
      { volatile unsigned long long mh1286_26727=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1286_26727; }
      { unsigned long long mt1287_32479=C.cookie^162ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1287_32479) & (mt1287_32479)) | ((mt1287_32479) & 0ULL))); }
      { { volatile unsigned long long ma1291_39506=1750548187ULL; volatile unsigned long long mb1292_1265=2224712471ULL; volatile unsigned long long mc1293_44234=ma1291_39506^mb1292_1265; mc1293_44234=(((mc1293_44234) & (mc1293_44234)) | ((mc1293_44234) & 0ULL)); (void)mc1293_44234; } C.state = 825141; }
      break;
    case 799640:
      
      
      { volatile unsigned long long mt1294_57735=C.cookie;mt1294_57735^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt1294_57735); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1295_43588=4163551965ULL; volatile unsigned long long mb1296_34178=1632595905ULL; volatile unsigned long long mc1297_26936=ma1295_43588^mb1296_34178; if(((mc1297_26936 ^ mc1297_26936) != 0ULL)) mc1297_26936^=0xDEADULL; (void)mc1297_26936; } }
      { volatile unsigned long long mt1298_50901=C.cookie;mt1298_50901^=163ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1298_50901); }
      { { volatile unsigned long long ma1302_36688=1168159589ULL; volatile unsigned long long mb1303_33492=111329333ULL; volatile unsigned long long mc1304_45335=ma1302_36688^mb1303_33492; mc1304_45335=(((mc1304_45335) ^ (mc1304_45335)) + (mc1304_45335)); (void)mc1304_45335; } C.state = 831320; }
      break;
    case 851445:
      
      
      { volatile unsigned long long mh1305_47462=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1305_47462; }
      { unsigned long long mt1306_41539=C.cookie^164ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1306_41539) | 0ULL)); }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1307_7617=751442375ULL; volatile unsigned long long mb1308_34185=3712588995ULL; volatile unsigned long long mc1309_6270=ma1307_7617^mb1308_34185; mc1309_6270=(ma1307_7617^mb1308_34185)+((ma1307_7617&mb1308_34185)<<1); (void)mc1309_6270; } } C.state = 353028;
      break;
    case 517944:
      
      
      { volatile unsigned long long ma1310_58401=1116475451ULL; volatile unsigned long long mb1311_6212=909201283ULL; volatile unsigned long long mc1312_64803=ma1310_58401^mb1311_6212; mc1312_64803=((mc1312_64803) | 0ULL); (void)mc1312_64803; }
      { volatile unsigned long long ma1313_21319=963185201ULL; volatile unsigned long long mb1314_1275=4238884819ULL; volatile unsigned long long mc1315_48777=ma1313_21319^mb1314_1275; mc1315_48777=(ma1313_21319^mb1314_1275)+((ma1313_21319&mb1314_1275)<<1); (void)mc1315_48777; }
      { volatile unsigned long long mt1316_59751=C.cookie;mt1316_59751^=165ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1316_59751); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 220891; } else { { volatile unsigned long long ma1317_28966=2884741729ULL; volatile unsigned long long mb1318_31949=2603633279ULL; volatile unsigned long long mc1319_1523=ma1317_28966^mb1318_31949; if((((mc1319_1523 * 2ULL) & 1ULL) != 0ULL)) mc1319_1523^=0xDEADULL; (void)mc1319_1523; } C.state = 220891; }
      break;
    case 884668:
      
      
      { volatile unsigned long long mh1320_15154=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1320_15154; }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1321_41615=1573485103ULL; volatile unsigned long long mb1322_13678=3200031071ULL; volatile unsigned long long mc1323_41099=ma1321_41615^mb1322_13678; mc1323_41099=(ma1321_41615^mb1322_13678)+((ma1321_41615&mb1322_13678)<<1); (void)mc1323_41099; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^166ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 471922; } else { { volatile unsigned long long ma1325_31315=2235863913ULL; volatile unsigned long long mb1326_61477=1219930663ULL; volatile unsigned long long mc1327_32096=ma1325_31315^mb1326_61477; for(volatile int _i=0;_i<3;++_i) mc1327_32096=vm_main_int___a100e2bc_mix(mc1327_32096+_i); (void)mc1327_32096; } C.state = 471922; }
      break;
    case 250376:
      
      
      { volatile unsigned long long ma1328_36328=931397947ULL; volatile unsigned long long mb1329_1866=795524473ULL; volatile unsigned long long mc1330_9491=ma1328_36328^mb1329_1866; mc1330_9491=(ma1328_36328^mb1329_1866)+((ma1328_36328&mb1329_1866)<<1); (void)mc1330_9491; }
      { volatile unsigned long long ma1331_35846=2093528701ULL; volatile unsigned long long mb1332_55464=725945723ULL; volatile unsigned long long mc1333_9381=ma1331_35846^mb1332_55464; mc1333_9381=(ma1331_35846^mb1332_55464)+((ma1331_35846&mb1332_55464)<<1); (void)mc1333_9381; }
      { volatile unsigned long long mt1334_9876=C.cookie;mt1334_9876^=167ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1334_9876); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 132028; } else { { volatile unsigned long long ma1335_33651=105724991ULL; volatile unsigned long long mb1336_38586=1249195967ULL; volatile unsigned long long mc1337_54724=ma1335_33651^mb1336_38586; if((((mc1337_54724 * 2ULL) & 1ULL) != 0ULL)) mc1337_54724^=0xDEADULL; (void)mc1337_54724; } C.state = 132028; }
      break;
    case 208051:
      
      
      { volatile unsigned long long mh1338_46756=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1338_46756; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^168ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1340_24996=715549405ULL; volatile unsigned long long mb1341_34576=1319404409ULL; volatile unsigned long long mc1342_48024=ma1340_24996^mb1341_34576; for(volatile int _i=0;_i<3;++_i) mc1342_48024=vm_main_int___a100e2bc_mix(mc1342_48024+_i); (void)mc1342_48024; } } C.state = 69587;
      break;
    case 366674:
      
      
      { volatile unsigned long long mh1343_39613=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1343_39613; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^169ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 220891; } else { { volatile unsigned long long ma1345_27514=3898067855ULL; volatile unsigned long long mb1346_25796=646322749ULL; volatile unsigned long long mc1347_50383=ma1345_27514^mb1346_25796; mc1347_50383=(ma1345_27514^mb1346_25796)+((ma1345_27514&mb1346_25796)<<1); (void)mc1347_50383; } C.state = 220891; }
      break;
    case 869241:
      
      
      { volatile unsigned long long ma1348_2126=2725056877ULL; volatile unsigned long long mb1349_24468=3793735769ULL; volatile unsigned long long mc1350_54971=ma1348_2126^mb1349_24468; if((((mc1350_54971 | 0ULL) & 0ULL) != 0ULL)) mc1350_54971^=0xDEADULL; (void)mc1350_54971; }
      { volatile unsigned long long mt1351_8427=C.cookie;mt1351_8427^=170ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1351_8427); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 202866; } else { { volatile unsigned long long ma1352_9602=641927283ULL; volatile unsigned long long mb1353_61789=288165985ULL; volatile unsigned long long mc1354_53808=ma1352_9602^mb1353_61789; for(volatile int _i=0;_i<1;++_i) mc1354_53808=vm_main_int___a100e2bc_mix(mc1354_53808+_i); (void)mc1354_53808; } C.state = 202866; }
      break;
    case 768325:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { unsigned long long mt1356_64537=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt1356_64537) & (mt1356_64537)) | ((mt1356_64537) & 0ULL))); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^171ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 750618; } else { { volatile unsigned long long ma1358_43055=794445133ULL; volatile unsigned long long mb1359_15822=2232140561ULL; volatile unsigned long long mc1360_44479=ma1358_43055^mb1359_15822; mc1360_44479=((mc1360_44479) ^ 0ULL); (void)mc1360_44479; } C.state = 750618; }
      break;
    case 859075:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1361_22235=2435884375ULL; volatile unsigned long long mb1362_24395=589093707ULL; volatile unsigned long long mc1363_8601=ma1361_22235^mb1362_24395; if((((mc1363_8601 + 0ULL) ^ (mc1363_8601 + 0ULL)) == 1ULL)) mc1363_8601^=0xDEADULL; (void)mc1363_8601; } }
      { unsigned long long mt1364_45299=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1364_45299) + 0ULL)); }
      { volatile unsigned long long mt1365_56207=C.cookie;mt1365_56207^=172ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1365_56207); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 78915; } else { { volatile unsigned long long ma1366_2078=2196634523ULL; volatile unsigned long long mb1367_7355=1824822337ULL; volatile unsigned long long mc1368_49108=ma1366_2078^mb1367_7355; mc1368_49108=(ma1366_2078^mb1367_7355)+((ma1366_2078&mb1367_7355)<<1); (void)mc1368_49108; } C.state = 78915; }
      break;
    case 740973:
      
      
      { unsigned long long mt1369_57704=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1369_57704) + 0ULL)); }
      { unsigned long long mt1370_20929=C.cookie^173ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1370_20929) | 0ULL)); }
      { { volatile unsigned long long ma1374_12759=4266701501ULL; volatile unsigned long long mb1375_61981=3438188681ULL; volatile unsigned long long mc1376_57186=ma1374_12759^mb1375_61981; mc1376_57186=((mc1376_57186) ^ 0ULL); (void)mc1376_57186; } C.state = 349245; }
      break;
    case 448083:
      
      
      { volatile unsigned long long mh1377_16977=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1377_16977; }
      { volatile unsigned long long ma1378_5555=4271963297ULL; volatile unsigned long long mb1379_3753=3064585201ULL; volatile unsigned long long mc1380_22879=ma1378_5555^mb1379_3753; for(volatile int _i=0;_i<2;++_i) mc1380_22879=vm_main_int___a100e2bc_mix(mc1380_22879+_i); (void)mc1380_22879; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^174ULL);
      { { volatile unsigned long long ma1385_64417=1873809537ULL; volatile unsigned long long mb1386_30168=4179078499ULL; volatile unsigned long long mc1387_26038=ma1385_64417^mb1386_30168; if(((mc1387_26038 ^ mc1387_26038) != 0ULL)) mc1387_26038^=0xDEADULL; (void)mc1387_26038; } C.state = 825141; }
      break;
    case 403334:
      
      
      { volatile unsigned long long mt1388_16201=C.cookie;mt1388_16201^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt1388_16201); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long mt1390_48455=C.cookie;mt1390_48455^=175ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1390_48455); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 70818; } else { { volatile unsigned long long ma1391_18013=3796150643ULL; volatile unsigned long long mb1392_29931=1997781961ULL; volatile unsigned long long mc1393_47343=ma1391_18013^mb1392_29931; mc1393_47343=((mc1393_47343) | 0ULL); (void)mc1393_47343; } C.state = 70818; }
      break;
    case 553130:
      
      
      { volatile unsigned long long mh1394_41252=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1394_41252; }
      { volatile unsigned long long ma1395_37426=1608704913ULL; volatile unsigned long long mb1396_43913=4103824951ULL; volatile unsigned long long mc1397_40225=ma1395_37426^mb1396_43913; mc1397_40225=((mc1397_40225) | 0ULL); (void)mc1397_40225; }
      { volatile unsigned long long mt1398_20797=C.cookie;mt1398_20797^=176ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1398_20797); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 150460; } else { { volatile unsigned long long ma1399_26506=2727275795ULL; volatile unsigned long long mb1400_42229=713343937ULL; volatile unsigned long long mc1401_52794=ma1399_26506^mb1400_42229; for(volatile int _i=0;_i<3;++_i) mc1401_52794=vm_main_int___a100e2bc_mix(mc1401_52794+_i); (void)mc1401_52794; } C.state = 150460; }
      break;
    case 746726:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { unsigned long long mt1404_50750=C.cookie^177ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1404_50750) | 0ULL)); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1405_46811=434145557ULL; volatile unsigned long long mb1406_24316=1782569935ULL; volatile unsigned long long mc1407_25806=ma1405_46811^mb1406_24316; mc1407_25806=(ma1405_46811^mb1406_24316)+((ma1405_46811&mb1406_24316)<<1); (void)mc1407_25806; } } C.state = 842480;
      break;
    case 120157:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { unsigned long long mt1409_25821=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1409_25821) ^ 0ULL)); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^178ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1411_38640=2775087861ULL; volatile unsigned long long mb1412_45384=2085639897ULL; volatile unsigned long long mc1413_24044=ma1411_38640^mb1412_45384; mc1413_24044=(ma1411_38640^mb1412_45384)+((ma1411_38640&mb1412_45384)<<1); (void)mc1413_24044; } } C.state = 851570;
      break;
    case 650759:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1414_28224=3246513875ULL; volatile unsigned long long mb1415_7314=3561845263ULL; volatile unsigned long long mc1416_65143=ma1414_28224^mb1415_7314; if((((mc1416_65143 + 0ULL) ^ (mc1416_65143 + 0ULL)) == 1ULL)) mc1416_65143^=0xDEADULL; (void)mc1416_65143; } }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1417_23637=4078238113ULL; volatile unsigned long long mb1418_26427=4105289929ULL; volatile unsigned long long mc1419_22762=ma1417_23637^mb1418_26427; for(volatile int _i=0;_i<3;++_i) mc1419_22762=vm_main_int___a100e2bc_mix(mc1419_22762+_i); (void)mc1419_22762; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^179ULL);
      { { volatile unsigned long long ma1424_4262=1371176437ULL; volatile unsigned long long mb1425_48522=1223866263ULL; volatile unsigned long long mc1426_52754=ma1424_4262^mb1425_48522; mc1426_52754=((mc1426_52754) | 0ULL); (void)mc1426_52754; } C.state = 480759; }
      break;
    case 558893:
      
      
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1427_5682=3863978925ULL; volatile unsigned long long mb1428_6878=3279905175ULL; volatile unsigned long long mc1429_9050=ma1427_5682^mb1428_6878; for(volatile int _i=0;_i<1;++_i) mc1429_9050=vm_main_int___a100e2bc_mix(mc1429_9050+_i); (void)mc1429_9050; } }
      { volatile unsigned long long mh1430_35387=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1430_35387; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^180ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1432_45238=3948530217ULL; volatile unsigned long long mb1433_51322=2808747947ULL; volatile unsigned long long mc1434_3488=ma1432_45238^mb1433_51322; mc1434_3488=(ma1432_45238^mb1433_51322)+((ma1432_45238&mb1433_51322)<<1); (void)mc1434_3488; } } C.state = 220891;
      break;
    case 132028:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1435_51456=3891286581ULL; volatile unsigned long long mb1436_6947=303333173ULL; volatile unsigned long long mc1437_59662=ma1435_51456^mb1436_6947; if((((mc1437_59662 + 0ULL) ^ (mc1437_59662 + 0ULL)) == 1ULL)) mc1437_59662^=0xDEADULL; (void)mc1437_59662; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^181ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1439_18786=3694566755ULL; volatile unsigned long long mb1440_65213=1974778757ULL; volatile unsigned long long mc1441_31206=ma1439_18786^mb1440_65213; for(volatile int _i=0;_i<2;++_i) mc1441_31206=vm_main_int___a100e2bc_mix(mc1441_31206+_i); (void)mc1441_31206; } } C.state = 109131;
      break;
    case 583038:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1442_55394=100001469ULL; volatile unsigned long long mb1443_32833=789052909ULL; volatile unsigned long long mc1444_42633=ma1442_55394^mb1443_32833; mc1444_42633=(ma1442_55394^mb1443_32833)+((ma1442_55394&mb1443_32833)<<1); (void)mc1444_42633; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^182ULL);
      { { volatile unsigned long long ma1449_52840=1216902717ULL; volatile unsigned long long mb1450_13765=514284359ULL; volatile unsigned long long mc1451_1855=ma1449_52840^mb1450_13765; if((((mc1451_1855 + 0ULL) ^ (mc1451_1855 + 0ULL)) == 1ULL)) mc1451_1855^=0xDEADULL; (void)mc1451_1855; } C.state = 183177; }
      break;
    case 465655:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1452_42153=4289910135ULL; volatile unsigned long long mb1453_61412=1924280273ULL; volatile unsigned long long mc1454_23619=ma1452_42153^mb1453_61412; mc1454_23619=(((mc1454_23619) & (mc1454_23619)) | ((mc1454_23619) & 0ULL)); (void)mc1454_23619; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^183ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1456_15568=3877289535ULL; volatile unsigned long long mb1457_25688=990143779ULL; volatile unsigned long long mc1458_38430=ma1456_15568^mb1457_25688; mc1458_38430=(ma1456_15568^mb1457_25688)+((ma1456_15568&mb1457_25688)<<1); (void)mc1458_38430; } } C.state = 831320;
      break;
    case 448562:
      
      
      { unsigned long long mt1459_47607=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1459_47607) ^ 0ULL)); }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1460_40806=2970587809ULL; volatile unsigned long long mb1461_35403=4140096103ULL; volatile unsigned long long mc1462_5755=ma1460_40806^mb1461_35403; mc1462_5755=((mc1462_5755) ^ 0ULL); (void)mc1462_5755; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^184ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 368436; } else { { volatile unsigned long long ma1464_2300=2010549717ULL; volatile unsigned long long mb1465_37448=3370642285ULL; volatile unsigned long long mc1466_48766=ma1464_2300^mb1465_37448; mc1466_48766=(ma1464_2300^mb1465_37448)+((ma1464_2300&mb1465_37448)<<1); (void)mc1466_48766; } C.state = 368436; }
      break;
    case 932953:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1467_29246=515784985ULL; volatile unsigned long long mb1468_49971=2477867821ULL; volatile unsigned long long mc1469_4957=ma1467_29246^mb1468_49971; mc1469_4957=((mc1469_4957) | 0ULL); (void)mc1469_4957; } }
      { volatile unsigned long long mt1470_49671=C.cookie;mt1470_49671^=185ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1470_49671); }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1471_33800=851511703ULL; volatile unsigned long long mb1472_30615=686146095ULL; volatile unsigned long long mc1473_11=ma1471_33800^mb1472_30615; mc1473_11=(((mc1473_11) ^ (mc1473_11)) + (mc1473_11)); (void)mc1473_11; } } C.state = 269474;
      break;
    case 825141:
      
      
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1474_48390=2889354091ULL; volatile unsigned long long mb1475_3856=2068701457ULL; volatile unsigned long long mc1476_6734=ma1474_48390^mb1475_3856; if((((mc1476_6734 * 2ULL) & 1ULL) != 0ULL)) mc1476_6734^=0xDEADULL; (void)mc1476_6734; } }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1477_8523=1840519609ULL; volatile unsigned long long mb1478_58943=1381135199ULL; volatile unsigned long long mc1479_25066=ma1477_8523^mb1478_58943; if((((mc1479_25066 | 0ULL) & 0ULL) != 0ULL)) mc1479_25066^=0xDEADULL; (void)mc1479_25066; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^186ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1481_23157=3025633939ULL; volatile unsigned long long mb1482_36044=143349741ULL; volatile unsigned long long mc1483_47459=ma1481_23157^mb1482_36044; for(volatile int _i=0;_i<1;++_i) mc1483_47459=vm_main_int___a100e2bc_mix(mc1483_47459+_i); (void)mc1483_47459; } } C.state = 20094;
      break;
    case 571422:
      
      
      { volatile unsigned long long ma1484_11878=42966095ULL; volatile unsigned long long mb1485_47650=3632045895ULL; volatile unsigned long long mc1486_37086=ma1484_11878^mb1485_47650; for(volatile int _i=0;_i<3;++_i) mc1486_37086=vm_main_int___a100e2bc_mix(mc1486_37086+_i); (void)mc1486_37086; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^187ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 88282; } else { { volatile unsigned long long ma1488_63820=2834609977ULL; volatile unsigned long long mb1489_19104=2021381313ULL; volatile unsigned long long mc1490_5214=ma1488_63820^mb1489_19104; mc1490_5214=((mc1490_5214) | 0ULL); (void)mc1490_5214; } C.state = 88282; }
      break;
    case 269474:
      
      
      { volatile unsigned long long mh1491_44066=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1491_44066; }
      { volatile unsigned long long mh1492_11074=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1492_11074; }
      { unsigned long long mt1493_36209=C.cookie^188ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1493_36209) + 0ULL)); }
      { { volatile unsigned long long ma1497_10667=3049581899ULL; volatile unsigned long long mb1498_13002=3478595551ULL; volatile unsigned long long mc1499_27103=ma1497_10667^mb1498_13002; for(volatile int _i=0;_i<2;++_i) mc1499_27103=vm_main_int___a100e2bc_mix(mc1499_27103+_i); (void)mc1499_27103; } C.state = 70818; }
      break;
    case 392905:
      
      
      { unsigned long long mt1500_53972=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1500_53972) | 0ULL)); }
      { volatile unsigned long long ma1501_41218=1422092483ULL; volatile unsigned long long mb1502_18531=986063501ULL; volatile unsigned long long mc1503_35128=ma1501_41218^mb1502_18531; for(volatile int _i=0;_i<3;++_i) mc1503_35128=vm_main_int___a100e2bc_mix(mc1503_35128+_i); (void)mc1503_35128; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^189ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1505_20391=1230770529ULL; volatile unsigned long long mb1506_54744=2778355049ULL; volatile unsigned long long mc1507_5296=ma1505_20391^mb1506_54744; if(((mc1507_5296 ^ mc1507_5296) != 0ULL)) mc1507_5296^=0xDEADULL; (void)mc1507_5296; } } C.state = 831320;
      break;
    case 877299:
      
      
      { volatile unsigned long long ma1508_42281=928500653ULL; volatile unsigned long long mb1509_55689=2269710579ULL; volatile unsigned long long mc1510_25526=ma1508_42281^mb1509_55689; for(volatile int _i=0;_i<1;++_i) mc1510_25526=vm_main_int___a100e2bc_mix(mc1510_25526+_i); (void)mc1510_25526; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^190ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1512_11797=3756061491ULL; volatile unsigned long long mb1513_18603=2348239469ULL; volatile unsigned long long mc1514_56029=ma1512_11797^mb1513_18603; mc1514_56029=(ma1512_11797^mb1513_18603)+((ma1512_11797&mb1513_18603)<<1); (void)mc1514_56029; } } C.state = 150460;
      break;
    case 572550:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1515_20870=3095734541ULL; volatile unsigned long long mb1516_57074=1714703037ULL; volatile unsigned long long mc1517_60395=ma1515_20870^mb1516_57074; mc1517_60395=(ma1515_20870^mb1516_57074)+((ma1515_20870&mb1516_57074)<<1); (void)mc1517_60395; } }
      { unsigned long long mt1518_38933=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1518_38933) + 0ULL)); }
      { unsigned long long mt1519_9172=C.cookie^191ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1519_9172) + 0ULL)); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 164343; } else { { volatile unsigned long long ma1520_14313=1532202607ULL; volatile unsigned long long mb1521_14641=4199735489ULL; volatile unsigned long long mc1522_54744=ma1520_14313^mb1521_14641; for(volatile int _i=0;_i<3;++_i) mc1522_54744=vm_main_int___a100e2bc_mix(mc1522_54744+_i); (void)mc1522_54744; } C.state = 164343; }
      break;
    case 537558:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long mt1524_31060=C.cookie;mt1524_31060^=192ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1524_31060); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 764571; } else { { volatile unsigned long long ma1525_7843=1421266577ULL; volatile unsigned long long mb1526_6000=2181103455ULL; volatile unsigned long long mc1527_7011=ma1525_7843^mb1526_6000; mc1527_7011=(ma1525_7843^mb1526_6000)+((ma1525_7843&mb1526_6000)<<1); (void)mc1527_7011; } C.state = 764571; }
      break;
    case 88282:
      
      
      { volatile unsigned long long mh1528_18087=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1528_18087; }
      { volatile unsigned long long ma1529_34874=2748792849ULL; volatile unsigned long long mb1530_60062=3239823391ULL; volatile unsigned long long mc1531_24488=ma1529_34874^mb1530_60062; if((((mc1531_24488 + 0ULL) ^ (mc1531_24488 + 0ULL)) == 1ULL)) mc1531_24488^=0xDEADULL; (void)mc1531_24488; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^193ULL);
      { { volatile unsigned long long ma1536_51138=1349220639ULL; volatile unsigned long long mb1537_63392=1592580171ULL; volatile unsigned long long mc1538_40834=ma1536_51138^mb1537_63392; for(volatile int _i=0;_i<1;++_i) mc1538_40834=vm_main_int___a100e2bc_mix(mc1538_40834+_i); (void)mc1538_40834; } C.state = 124287; }
      break;
    case 418474:
      
      
      { volatile unsigned long long ma1539_29897=689079055ULL; volatile unsigned long long mb1540_60017=1195616051ULL; volatile unsigned long long mc1541_10321=ma1539_29897^mb1540_60017; mc1541_10321=(ma1539_29897^mb1540_60017)+((ma1539_29897&mb1540_60017)<<1); (void)mc1541_10321; }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1542_23975=2550281101ULL; volatile unsigned long long mb1543_46536=851465991ULL; volatile unsigned long long mc1544_28014=ma1542_23975^mb1543_46536; mc1544_28014=((mc1544_28014) | 0ULL); (void)mc1544_28014; } }
      { volatile unsigned long long mt1545_15061=C.cookie;mt1545_15061^=194ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1545_15061); }
      { { volatile unsigned long long ma1549_6911=3080369449ULL; volatile unsigned long long mb1550_37374=2542254587ULL; volatile unsigned long long mc1551_38019=ma1549_6911^mb1550_37374; mc1551_38019=(ma1549_6911^mb1550_37374)+((ma1549_6911&mb1550_37374)<<1); (void)mc1551_38019; } C.state = 621700; }
      break;
    case 518730:
      
      
      { volatile unsigned long long mh1552_46915=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1552_46915; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^195ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1554_14168=2458233831ULL; volatile unsigned long long mb1555_29396=193829451ULL; volatile unsigned long long mc1556_48951=ma1554_14168^mb1555_29396; for(volatile int _i=0;_i<1;++_i) mc1556_48951=vm_main_int___a100e2bc_mix(mc1556_48951+_i); (void)mc1556_48951; } } C.state = 192922;
      break;
    case 880484:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1557_56616=1948846913ULL; volatile unsigned long long mb1558_12649=3357129705ULL; volatile unsigned long long mc1559_32109=ma1557_56616^mb1558_12649; mc1559_32109=(ma1557_56616^mb1558_12649)+((ma1557_56616&mb1558_12649)<<1); (void)mc1559_32109; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^196ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1562_16375=1622711395ULL; volatile unsigned long long mb1563_51951=3705880629ULL; volatile unsigned long long mc1564_53860=ma1562_16375^mb1563_51951; if((((mc1564_53860 * 2ULL) & 1ULL) != 0ULL)) mc1564_53860^=0xDEADULL; (void)mc1564_53860; } } C.state = 500485;
      break;
    case 514242:
      
      
      { volatile unsigned long long mh1565_52914=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1565_52914; }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1566_25356=3673934567ULL; volatile unsigned long long mb1567_1909=3273944813ULL; volatile unsigned long long mc1568_9370=ma1566_25356^mb1567_1909; if((((mc1568_9370 * 2ULL) & 1ULL) != 0ULL)) mc1568_9370^=0xDEADULL; (void)mc1568_9370; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^197ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 536734; } else { { volatile unsigned long long ma1570_28350=3014962999ULL; volatile unsigned long long mb1571_14631=2312286343ULL; volatile unsigned long long mc1572_22126=ma1570_28350^mb1571_14631; mc1572_22126=(((mc1572_22126) & (mc1572_22126)) | ((mc1572_22126) & 0ULL)); (void)mc1572_22126; } C.state = 536734; }
      break;
    case 539228:
      
      
      { volatile unsigned long long ma1573_21301=1579854717ULL; volatile unsigned long long mb1574_25481=843526103ULL; volatile unsigned long long mc1575_49493=ma1573_21301^mb1574_25481; for(volatile int _i=0;_i<3;++_i) mc1575_49493=vm_main_int___a100e2bc_mix(mc1575_49493+_i); (void)mc1575_49493; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^198ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 20094; } else { { volatile unsigned long long ma1577_12174=3912683249ULL; volatile unsigned long long mb1578_49567=3941800613ULL; volatile unsigned long long mc1579_32989=ma1577_12174^mb1578_49567; mc1579_32989=(((mc1579_32989) & (mc1579_32989)) | ((mc1579_32989) & 0ULL)); (void)mc1579_32989; } C.state = 20094; }
      break;
    case 150460:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1580_39318=2403466383ULL; volatile unsigned long long mb1581_58154=1520432671ULL; volatile unsigned long long mc1582_39775=ma1580_39318^mb1581_58154; for(volatile int _i=0;_i<3;++_i) mc1582_39775=vm_main_int___a100e2bc_mix(mc1582_39775+_i); (void)mc1582_39775; } }
      { volatile unsigned long long ma1583_21654=907390261ULL; volatile unsigned long long mb1584_29432=3511305923ULL; volatile unsigned long long mc1585_52852=ma1583_21654^mb1584_29432; mc1585_52852=(ma1583_21654^mb1584_29432)+((ma1583_21654&mb1584_29432)<<1); (void)mc1585_52852; }
      { unsigned long long mt1586_4002=C.cookie^199ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1586_4002) | 0ULL)); }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1587_3923=3148076309ULL; volatile unsigned long long mb1588_26479=3302100177ULL; volatile unsigned long long mc1589_36259=ma1587_3923^mb1588_26479; mc1589_36259=(ma1587_3923^mb1588_26479)+((ma1587_3923&mb1588_26479)<<1); (void)mc1589_36259; } } C.state = 262413;
      break;
    case 976608:
      
      
      { volatile unsigned long long mh1590_10027=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1590_10027; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^200ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 397173; } else { { volatile unsigned long long ma1592_14455=183296537ULL; volatile unsigned long long mb1593_41270=639320917ULL; volatile unsigned long long mc1594_41737=ma1592_14455^mb1593_41270; mc1594_41737=(((mc1594_41737) ^ (mc1594_41737)) + (mc1594_41737)); (void)mc1594_41737; } C.state = 397173; }
      break;
    case 118551:
      
      
      { volatile unsigned long long ma1595_47223=1265412823ULL; volatile unsigned long long mb1596_15159=4048162269ULL; volatile unsigned long long mc1597_26404=ma1595_47223^mb1596_15159; mc1597_26404=((mc1597_26404) + 0ULL); (void)mc1597_26404; }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1598_13316=415885561ULL; volatile unsigned long long mb1599_59702=2918640903ULL; volatile unsigned long long mc1600_41520=ma1598_13316^mb1599_59702; if(((mc1600_41520 ^ mc1600_41520) != 0ULL)) mc1600_41520^=0xDEADULL; (void)mc1600_41520; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^201ULL);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 368436; } else { { volatile unsigned long long ma1602_44705=471474777ULL; volatile unsigned long long mb1603_13527=652157527ULL; volatile unsigned long long mc1604_8404=ma1602_44705^mb1603_13527; for(volatile int _i=0;_i<3;++_i) mc1604_8404=vm_main_int___a100e2bc_mix(mc1604_8404+_i); (void)mc1604_8404; } C.state = 368436; }
      break;
    case 752439:
      
      
      { unsigned long long mt1605_29659=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt1605_29659) ^ (mt1605_29659)) + (mt1605_29659))); }
      { unsigned long long mt1606_19976=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1606_19976) ^ 0ULL)); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^202ULL);
      { { volatile unsigned long long ma1611_64407=311747629ULL; volatile unsigned long long mb1612_9832=1984962453ULL; volatile unsigned long long mc1613_64115=ma1611_64407^mb1612_9832; mc1613_64115=((mc1613_64115) | 0ULL); (void)mc1613_64115; } C.state = 125221; }
      break;
    case 637519:
      
      
      { unsigned long long mt1614_15290=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1614_15290) + 0ULL)); }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^203ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 518447; } else { { volatile unsigned long long ma1616_24812=1476709745ULL; volatile unsigned long long mb1617_2429=3404931803ULL; volatile unsigned long long mc1618_14894=ma1616_24812^mb1617_2429; mc1618_14894=(ma1616_24812^mb1617_2429)+((ma1616_24812&mb1617_2429)<<1); (void)mc1618_14894; } C.state = 518447; }
      break;
    case 782313:
      
      
      { volatile unsigned long long ma1619_25053=1197778031ULL; volatile unsigned long long mb1620_42162=2293346447ULL; volatile unsigned long long mc1621_19642=ma1619_25053^mb1620_42162; mc1621_19642=(ma1619_25053^mb1620_42162)+((ma1619_25053&mb1620_42162)<<1); (void)mc1621_19642; }
      { volatile unsigned long long ma1622_57999=3330013815ULL; volatile unsigned long long mb1623_45746=2709221633ULL; volatile unsigned long long mc1624_60173=ma1622_57999^mb1623_45746; mc1624_60173=(ma1622_57999^mb1623_45746)+((ma1622_57999&mb1623_45746)<<1); (void)mc1624_60173; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^204ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 69587; } else { { volatile unsigned long long ma1626_64901=3432442743ULL; volatile unsigned long long mb1627_49278=3385716537ULL; volatile unsigned long long mc1628_1965=ma1626_64901^mb1627_49278; mc1628_1965=((mc1628_1965) | 0ULL); (void)mc1628_1965; } C.state = 69587; }
      break;
    case 57154:
      
      
      { volatile unsigned long long mh1629_34258=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1629_34258; }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1630_39849=867261183ULL; volatile unsigned long long mb1631_7978=3781662995ULL; volatile unsigned long long mc1632_963=ma1630_39849^mb1631_7978; mc1632_963=(ma1630_39849^mb1631_7978)+((ma1630_39849&mb1631_7978)<<1); (void)mc1632_963; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^205ULL);
      { { volatile unsigned long long ma1637_10418=3736061049ULL; volatile unsigned long long mb1638_20869=1309626761ULL; volatile unsigned long long mc1639_13600=ma1637_10418^mb1638_20869; if((((mc1639_13600 * 2ULL) & 1ULL) != 0ULL)) mc1639_13600^=0xDEADULL; (void)mc1639_13600; } C.state = 220891; }
      break;
    case 747921:
      
      
      { volatile unsigned long long ma1640_28430=1889241031ULL; volatile unsigned long long mb1641_28994=3034021511ULL; volatile unsigned long long mc1642_22410=ma1640_28430^mb1641_28994; mc1642_22410=(((mc1642_22410) & (mc1642_22410)) | ((mc1642_22410) & 0ULL)); (void)mc1642_22410; }
      { volatile unsigned long long ma1643_30916=1889586739ULL; volatile unsigned long long mb1644_35677=2600082181ULL; volatile unsigned long long mc1645_27208=ma1643_30916^mb1644_35677; for(volatile int _i=0;_i<3;++_i) mc1645_27208=vm_main_int___a100e2bc_mix(mc1645_27208+_i); (void)mc1645_27208; }
      { volatile unsigned long long mt1646_7232=C.cookie;mt1646_7232^=206ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1646_7232); }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1647_44232=310692459ULL; volatile unsigned long long mb1648_19698=3123370609ULL; volatile unsigned long long mc1649_52903=ma1647_44232^mb1648_19698; mc1649_52903=((mc1649_52903) + 0ULL); (void)mc1649_52903; } } C.state = 342173;
      break;
    case 878907:
      
      
      { volatile unsigned long long mt1650_19646=C.cookie;mt1650_19646^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt1650_19646); }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^207ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 470319; } else { { volatile unsigned long long ma1652_43979=42484783ULL; volatile unsigned long long mb1653_44360=1605326939ULL; volatile unsigned long long mc1654_33425=ma1652_43979^mb1653_44360; for(volatile int _i=0;_i<2;++_i) mc1654_33425=vm_main_int___a100e2bc_mix(mc1654_33425+_i); (void)mc1654_33425; } C.state = 470319; }
      break;
    case 970994:
      
      
      { volatile unsigned long long ma1655_38646=3355609563ULL; volatile unsigned long long mb1656_47328=2111466295ULL; volatile unsigned long long mc1657_60798=ma1655_38646^mb1656_47328; for(volatile int _i=0;_i<3;++_i) mc1657_60798=vm_main_int___a100e2bc_mix(mc1657_60798+_i); (void)mc1657_60798; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { unsigned long long mt1659_35933=C.cookie^208ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1659_35933) & (mt1659_35933)) | ((mt1659_35933) & 0ULL))); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1660_3678=3343068119ULL; volatile unsigned long long mb1661_53526=3797438069ULL; volatile unsigned long long mc1662_25608=ma1660_3678^mb1661_53526; for(volatile int _i=0;_i<3;++_i) mc1662_25608=vm_main_int___a100e2bc_mix(mc1662_25608+_i); (void)mc1662_25608; } } C.state = 752362;
      break;
    case 662711:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1663_11046=1987756067ULL; volatile unsigned long long mb1664_36847=3918965377ULL; volatile unsigned long long mc1665_29752=ma1663_11046^mb1664_36847; mc1665_29752=(ma1663_11046^mb1664_36847)+((ma1663_11046&mb1664_36847)<<1); (void)mc1665_29752; } }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1666_41317=1924677123ULL; volatile unsigned long long mb1667_31350=2482361315ULL; volatile unsigned long long mc1668_7491=ma1666_41317^mb1667_31350; for(volatile int _i=0;_i<3;++_i) mc1668_7491=vm_main_int___a100e2bc_mix(mc1668_7491+_i); (void)mc1668_7491; } }
      { unsigned long long mt1669_5579=C.cookie^209ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1669_5579) ^ 0ULL)); }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1670_12630=804603679ULL; volatile unsigned long long mb1671_38214=3612804829ULL; volatile unsigned long long mc1672_2655=ma1670_12630^mb1671_38214; if((((mc1672_2655 * 2ULL) & 1ULL) != 0ULL)) mc1672_2655^=0xDEADULL; (void)mc1672_2655; } } C.state = 69587;
      break;
    case 592142:
      
      
      { volatile unsigned long long ma1673_38372=3919292619ULL; volatile unsigned long long mb1674_12816=156892019ULL; volatile unsigned long long mc1675_5223=ma1673_38372^mb1674_12816; for(volatile int _i=0;_i<2;++_i) mc1675_5223=vm_main_int___a100e2bc_mix(mc1675_5223+_i); (void)mc1675_5223; }
      { volatile unsigned long long mt1676_6810=C.cookie;mt1676_6810^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt1676_6810); }
      { unsigned long long mt1677_38851=C.cookie^210ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1677_38851) & (mt1677_38851)) | ((mt1677_38851) & 0ULL))); }
      { { volatile unsigned long long ma1681_30324=2240591219ULL; volatile unsigned long long mb1682_42671=613659165ULL; volatile unsigned long long mc1683_35900=ma1681_30324^mb1682_42671; for(volatile int _i=0;_i<1;++_i) mc1683_35900=vm_main_int___a100e2bc_mix(mc1683_35900+_i); (void)mc1683_35900; } C.state = 952311; }
      break;
    case 20094:
      
      
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1684_48895=4236620683ULL; volatile unsigned long long mb1685_53369=1792176687ULL; volatile unsigned long long mc1686_3620=ma1684_48895^mb1685_53369; mc1686_3620=(ma1684_48895^mb1685_53369)+((ma1684_48895&mb1685_53369)<<1); (void)mc1686_3620; } }
      { unsigned long long mt1687_2368=C.cookie^211ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1687_2368) | 0ULL)); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 956703; } else { { volatile unsigned long long ma1688_32378=2151011873ULL; volatile unsigned long long mb1689_63680=3435024797ULL; volatile unsigned long long mc1690_9493=ma1688_32378^mb1689_63680; if((((mc1690_9493 | 0ULL) & 0ULL) != 0ULL)) mc1690_9493^=0xDEADULL; (void)mc1690_9493; } C.state = 956703; }
      break;
    case 192922:
      
      
      { volatile unsigned long long mh1691_46450=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1691_46450; }
      { unsigned long long mt1692_38192=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt1692_38192) & (mt1692_38192)) | ((mt1692_38192) & 0ULL))); }
      { unsigned long long mt1693_22582=C.cookie^212ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1693_22582) | 0ULL)); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1694_11524=2399282583ULL; volatile unsigned long long mb1695_48482=3285810399ULL; volatile unsigned long long mc1696_62097=ma1694_11524^mb1695_48482; mc1696_62097=(((mc1696_62097) ^ (mc1696_62097)) + (mc1696_62097)); (void)mc1696_62097; } } C.state = 425683;
      break;
    case 262413:
      
      
      { volatile unsigned long long mt1697_54678=C.cookie;mt1697_54678^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt1697_54678); }
      { volatile unsigned long long ma1698_55225=2234306929ULL; volatile unsigned long long mb1699_5074=4102182841ULL; volatile unsigned long long mc1700_2394=ma1698_55225^mb1699_5074; mc1700_2394=(ma1698_55225^mb1699_5074)+((ma1698_55225&mb1699_5074)<<1); (void)mc1700_2394; }
      { unsigned long long mt1701_12968=C.cookie^213ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1701_12968) ^ (mt1701_12968)) + (mt1701_12968))); }
      { { volatile unsigned long long ma1705_23288=764995263ULL; volatile unsigned long long mb1706_6689=839128383ULL; volatile unsigned long long mc1707_49797=ma1705_23288^mb1706_6689; mc1707_49797=(ma1705_23288^mb1706_6689)+((ma1705_23288&mb1706_6689)<<1); (void)mc1707_49797; } C.state = 267965; }
      break;
    case 997667:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^214ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 71590; } else { { volatile unsigned long long ma1710_11714=849561573ULL; volatile unsigned long long mb1711_52927=4141523353ULL; volatile unsigned long long mc1712_58964=ma1710_11714^mb1711_52927; mc1712_58964=((mc1712_58964) + 0ULL); (void)mc1712_58964; } C.state = 71590; }
      break;
    case 480759:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1713_56364=3048668539ULL; volatile unsigned long long mb1714_33246=591067171ULL; volatile unsigned long long mc1715_33284=ma1713_56364^mb1714_33246; if((((mc1715_33284 + 0ULL) ^ (mc1715_33284 + 0ULL)) == 1ULL)) mc1715_33284^=0xDEADULL; (void)mc1715_33284; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^215ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 831320; } else { { volatile unsigned long long ma1717_41360=830872647ULL; volatile unsigned long long mb1718_54769=3852134725ULL; volatile unsigned long long mc1719_32206=ma1717_41360^mb1718_54769; mc1719_32206=(ma1717_41360^mb1718_54769)+((ma1717_41360&mb1718_54769)<<1); (void)mc1719_32206; } C.state = 831320; }
      break;
    case 907895:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1720_36965=3113892133ULL; volatile unsigned long long mb1721_33447=2119462117ULL; volatile unsigned long long mc1722_2875=ma1720_36965^mb1721_33447; if(((mc1722_2875 ^ mc1722_2875) != 0ULL)) mc1722_2875^=0xDEADULL; (void)mc1722_2875; } }
      { volatile unsigned long long ma1723_18653=3273601547ULL; volatile unsigned long long mb1724_25286=848509813ULL; volatile unsigned long long mc1725_53442=ma1723_18653^mb1724_25286; for(volatile int _i=0;_i<1;++_i) mc1725_53442=vm_main_int___a100e2bc_mix(mc1725_53442+_i); (void)mc1725_53442; }
      { volatile unsigned long long mt1726_8109=C.cookie;mt1726_8109^=216ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1726_8109); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1727_26685=4290084317ULL; volatile unsigned long long mb1728_38405=3509888279ULL; volatile unsigned long long mc1729_30613=ma1727_26685^mb1728_38405; mc1729_30613=((mc1729_30613) + 0ULL); (void)mc1729_30613; } } C.state = 613491;
      break;
    case 959107:
      
      
      { volatile unsigned long long mh1730_59535=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1730_59535; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^217ULL);
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1732_280=201718837ULL; volatile unsigned long long mb1733_58099=191178881ULL; volatile unsigned long long mc1734_38816=ma1732_280^mb1733_58099; if((((mc1734_38816 * 2ULL) & 1ULL) != 0ULL)) mc1734_38816^=0xDEADULL; (void)mc1734_38816; } } C.state = 462330;
      break;
    case 71590:
      
      
      { volatile unsigned long long ma1735_44812=4286209607ULL; volatile unsigned long long mb1736_25834=1550491507ULL; volatile unsigned long long mc1737_45002=ma1735_44812^mb1736_25834; if((((mc1737_45002 | 0ULL) & 0ULL) != 0ULL)) mc1737_45002^=0xDEADULL; (void)mc1737_45002; }
      { unsigned long long mt1738_59425=C.cookie^218ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1738_59425) | 0ULL)); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 94321; } else { { volatile unsigned long long ma1739_42634=3833027205ULL; volatile unsigned long long mb1740_40280=995790579ULL; volatile unsigned long long mc1741_5409=ma1739_42634^mb1740_40280; mc1741_5409=((mc1741_5409) ^ 0ULL); (void)mc1741_5409; } C.state = 94321; }
      break;
    case 78915:
      
      
      { unsigned long long mt1742_17384=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1742_17384) ^ 0ULL)); }
      { unsigned long long mt1743_25614=C.cookie^219ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1743_25614) ^ (mt1743_25614)) + (mt1743_25614))); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 125951; } else { { volatile unsigned long long ma1744_12646=3561300563ULL; volatile unsigned long long mb1745_15258=4239125935ULL; volatile unsigned long long mc1746_57470=ma1744_12646^mb1745_15258; for(volatile int _i=0;_i<2;++_i) mc1746_57470=vm_main_int___a100e2bc_mix(mc1746_57470+_i); (void)mc1746_57470; } C.state = 125951; }
      break;
    case 258573:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1747_21185=649986881ULL; volatile unsigned long long mb1748_62007=2547080397ULL; volatile unsigned long long mc1749_22267=ma1747_21185^mb1748_62007; mc1749_22267=(ma1747_21185^mb1748_62007)+((ma1747_21185&mb1748_62007)<<1); (void)mc1749_22267; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { unsigned long long mt1751_30498=C.cookie^220ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1751_30498) ^ 0ULL)); }
      { { volatile unsigned long long ma1755_61533=3525108383ULL; volatile unsigned long long mb1756_273=489293437ULL; volatile unsigned long long mc1757_2646=ma1755_61533^mb1756_273; mc1757_2646=(ma1755_61533^mb1756_273)+((ma1755_61533&mb1756_273)<<1); (void)mc1757_2646; } C.state = 125951; }
      break;
    case 109131:
      
      
      { volatile unsigned long long mh1758_14886=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1758_14886; }
      { volatile unsigned long long mh1759_40321=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1759_40321; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^221ULL);
      { { volatile unsigned long long ma1764_53332=1946127031ULL; volatile unsigned long long mb1765_60254=621562125ULL; volatile unsigned long long mc1766_59484=ma1764_53332^mb1765_60254; for(volatile int _i=0;_i<1;++_i) mc1766_59484=vm_main_int___a100e2bc_mix(mc1766_59484+_i); (void)mc1766_59484; } C.state = 536734; }
      break;
    case 397173:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1767_37056=414716225ULL; volatile unsigned long long mb1768_38924=3310477927ULL; volatile unsigned long long mc1769_54194=ma1767_37056^mb1768_38924; mc1769_54194=((mc1769_54194) | 0ULL); (void)mc1769_54194; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^222ULL);
      { { volatile unsigned long long ma1774_38703=2443083327ULL; volatile unsigned long long mb1775_16751=2040104435ULL; volatile unsigned long long mc1776_23520=ma1774_38703^mb1775_16751; mc1776_23520=(ma1774_38703^mb1775_16751)+((ma1774_38703&mb1775_16751)<<1); (void)mc1776_23520; } C.state = 390458; }
      break;
    case 36711:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long mh1778_12881=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1778_12881; }
      { volatile unsigned long long mt1779_26686=C.cookie;mt1779_26686^=223ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1779_26686); }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1780_31947=3847580581ULL; volatile unsigned long long mb1781_9961=1308757999ULL; volatile unsigned long long mc1782_6168=ma1780_31947^mb1781_9961; if(((mc1782_6168 ^ mc1782_6168) != 0ULL)) mc1782_6168^=0xDEADULL; (void)mc1782_6168; } } C.state = 216980;
      break;
    case 500485:
      
      
      { volatile unsigned long long ma1783_20800=1460678997ULL; volatile unsigned long long mb1784_18848=3187174933ULL; volatile unsigned long long mc1785_5433=ma1783_20800^mb1784_18848; mc1785_5433=(((mc1785_5433) & (mc1785_5433)) | ((mc1785_5433) & 0ULL)); (void)mc1785_5433; }
      { unsigned long long mt1786_7952=C.cookie^224ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1786_7952) ^ (mt1786_7952)) + (mt1786_7952))); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 750618; } else { { volatile unsigned long long ma1787_40969=2335438045ULL; volatile unsigned long long mb1788_26522=3451206901ULL; volatile unsigned long long mc1789_51442=ma1787_40969^mb1788_26522; if((((mc1789_51442 + 0ULL) ^ (mc1789_51442 + 0ULL)) == 1ULL)) mc1789_51442^=0xDEADULL; (void)mc1789_51442; } C.state = 750618; }
      break;
    case 368436:
      
      
      { unsigned long long mt1790_15998=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1790_15998) ^ 0ULL)); }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^225ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 176058; } else { { volatile unsigned long long ma1792_3319=784046337ULL; volatile unsigned long long mb1793_4351=533006299ULL; volatile unsigned long long mc1794_8649=ma1792_3319^mb1793_4351; if((((mc1794_8649 + 0ULL) ^ (mc1794_8649 + 0ULL)) == 1ULL)) mc1794_8649^=0xDEADULL; (void)mc1794_8649; } C.state = 176058; }
      break;
    case 120691:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1795_31637=262110943ULL; volatile unsigned long long mb1796_33546=1972311713ULL; volatile unsigned long long mc1797_16042=ma1795_31637^mb1796_33546; mc1797_16042=((mc1797_16042) + 0ULL); (void)mc1797_16042; } }
      { unsigned long long mt1798_27748=C.cookie^226ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1798_27748) | 0ULL)); }
      { { volatile unsigned long long ma1802_52033=1888475137ULL; volatile unsigned long long mb1803_36471=3129859147ULL; volatile unsigned long long mc1804_52044=ma1802_52033^mb1803_36471; mc1804_52044=(ma1802_52033^mb1803_36471)+((ma1802_52033&mb1803_36471)<<1); (void)mc1804_52044; } C.state = 11528; }
      break;
    case 892443:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1805_37305=3785454289ULL; volatile unsigned long long mb1806_60009=3433299959ULL; volatile unsigned long long mc1807_17019=ma1805_37305^mb1806_60009; for(volatile int _i=0;_i<2;++_i) mc1807_17019=vm_main_int___a100e2bc_mix(mc1807_17019+_i); (void)mc1807_17019; } }
      { volatile unsigned long long ma1808_39376=3129038685ULL; volatile unsigned long long mb1809_45029=2128119455ULL; volatile unsigned long long mc1810_49060=ma1808_39376^mb1809_45029; mc1810_49060=((mc1810_49060) | 0ULL); (void)mc1810_49060; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^227ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1812_12509=4278023639ULL; volatile unsigned long long mb1813_26774=3319449719ULL; volatile unsigned long long mc1814_37921=ma1812_12509^mb1813_26774; mc1814_37921=(((mc1814_37921) & (mc1814_37921)) | ((mc1814_37921) & 0ULL)); (void)mc1814_37921; } } C.state = 350819;
      break;
    case 109396:
      
      
      { volatile unsigned long long mt1815_64278=C.cookie;mt1815_64278^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt1815_64278); }
      { unsigned long long mt1816_36421=C.cookie^228ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1816_36421) & (mt1816_36421)) | ((mt1816_36421) & 0ULL))); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 891920; } else { { volatile unsigned long long ma1817_22282=175600691ULL; volatile unsigned long long mb1818_47901=237531555ULL; volatile unsigned long long mc1819_395=ma1817_22282^mb1818_47901; mc1819_395=(((mc1819_395) & (mc1819_395)) | ((mc1819_395) & 0ULL)); (void)mc1819_395; } C.state = 891920; }
      break;
    case 563450:
      
      
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1820_1899=573185161ULL; volatile unsigned long long mb1821_42489=2668184913ULL; volatile unsigned long long mc1822_26908=ma1820_1899^mb1821_42489; for(volatile int _i=0;_i<3;++_i) mc1822_26908=vm_main_int___a100e2bc_mix(mc1822_26908+_i); (void)mc1822_26908; } }
      { unsigned long long mt1823_21328=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(((mt1823_21328) | 0ULL)); }
      { unsigned long long mt1824_10437=C.cookie^229ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1824_10437) & (mt1824_10437)) | ((mt1824_10437) & 0ULL))); }
      { { volatile unsigned long long ma1828_7841=299309491ULL; volatile unsigned long long mb1829_8559=2557812101ULL; volatile unsigned long long mc1830_50363=ma1828_7841^mb1829_8559; for(volatile int _i=0;_i<1;++_i) mc1830_50363=vm_main_int___a100e2bc_mix(mc1830_50363+_i); (void)mc1830_50363; } C.state = 831320; }
      break;
    case 536734:
      
      
      { volatile unsigned long long ma1831_59435=3440186537ULL; volatile unsigned long long mb1832_39257=200934919ULL; volatile unsigned long long mc1833_52578=ma1831_59435^mb1832_39257; mc1833_52578=((mc1833_52578) ^ 0ULL); (void)mc1833_52578; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^230ULL);
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1835_2032=4082656699ULL; volatile unsigned long long mb1836_53386=2078716995ULL; volatile unsigned long long mc1837_38772=ma1835_2032^mb1836_53386; for(volatile int _i=0;_i<3;++_i) mc1837_38772=vm_main_int___a100e2bc_mix(mc1837_38772+_i); (void)mc1837_38772; } } C.state = 898399;
      break;
    case 70818:
      
      
      { volatile unsigned long long mh1838_55145=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1838_55145; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^231ULL);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 125951; } else { { volatile unsigned long long ma1841_595=2909402941ULL; volatile unsigned long long mb1842_43325=4217368535ULL; volatile unsigned long long mc1843_9950=ma1841_595^mb1842_43325; mc1843_9950=((mc1843_9950) | 0ULL); (void)mc1843_9950; } C.state = 125951; }
      break;
    case 220891:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1844_20927=40253311ULL; volatile unsigned long long mb1845_29469=3202390983ULL; volatile unsigned long long mc1846_9410=ma1844_20927^mb1845_29469; for(volatile int _i=0;_i<1;++_i) mc1846_9410=vm_main_int___a100e2bc_mix(mc1846_9410+_i); (void)mc1846_9410; } }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1847_27770=1821533961ULL; volatile unsigned long long mb1848_53433=1010742545ULL; volatile unsigned long long mc1849_5051=ma1847_27770^mb1848_53433; if((((mc1849_5051 + 0ULL) ^ (mc1849_5051 + 0ULL)) == 1ULL)) mc1849_5051^=0xDEADULL; (void)mc1849_5051; } }
      { volatile unsigned long long mt1850_64314=C.cookie;mt1850_64314^=232ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1850_64314); }
      { { volatile unsigned long long ma1854_37762=2610351097ULL; volatile unsigned long long mb1855_5707=3862728943ULL; volatile unsigned long long mc1856_40541=ma1854_37762^mb1855_5707; if((((mc1856_40541 + 0ULL) ^ (mc1856_40541 + 0ULL)) == 1ULL)) mc1856_40541^=0xDEADULL; (void)mc1856_40541; } C.state = 522169; }
      break;
    case 1007219:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^233ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 891920; } else { { volatile unsigned long long ma1860_34258=3211844881ULL; volatile unsigned long long mb1861_36539=2090786403ULL; volatile unsigned long long mc1862_42523=ma1860_34258^mb1861_36539; for(volatile int _i=0;_i<3;++_i) mc1862_42523=vm_main_int___a100e2bc_mix(mc1862_42523+_i); (void)mc1862_42523; } C.state = 891920; }
      break;
    case 350819:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^234ULL);
      { { volatile unsigned long long ma1868_134=1550635487ULL; volatile unsigned long long mb1869_22240=4070245531ULL; volatile unsigned long long mc1870_45741=ma1868_134^mb1869_22240; mc1870_45741=(ma1868_134^mb1869_22240)+((ma1868_134&mb1869_22240)<<1); (void)mc1870_45741; } C.state = 995650; }
      break;
    case 722997:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^235ULL);
      { { volatile unsigned long long ma1877_65484=935075257ULL; volatile unsigned long long mb1878_6813=777393889ULL; volatile unsigned long long mc1879_50513=ma1877_65484^mb1878_6813; mc1879_50513=((mc1879_50513) + 0ULL); (void)mc1879_50513; } C.state = 750618; }
      break;
    case 317792:
      
      
      { volatile unsigned long long ma1880_41497=2230237591ULL; volatile unsigned long long mb1881_41733=3863179667ULL; volatile unsigned long long mc1882_62156=ma1880_41497^mb1881_41733; mc1882_62156=((mc1882_62156) | 0ULL); (void)mc1882_62156; }
      { unsigned long long mt1883_59140=C.cookie^236ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1883_59140) ^ (mt1883_59140)) + (mt1883_59140))); }
      { { volatile unsigned long long ma1887_30496=1372788549ULL; volatile unsigned long long mb1888_64377=1310419421ULL; volatile unsigned long long mc1889_22546=ma1887_30496^mb1888_64377; if((((mc1889_22546 + 0ULL) ^ (mc1889_22546 + 0ULL)) == 1ULL)) mc1889_22546^=0xDEADULL; (void)mc1889_22546; } C.state = 470319; }
      break;
    case 713625:
      
      
      { volatile unsigned long long ma1890_56107=2735055545ULL; volatile unsigned long long mb1891_4967=4198867297ULL; volatile unsigned long long mc1892_62129=ma1890_56107^mb1891_4967; if((((mc1892_62129 | 0ULL) & 0ULL) != 0ULL)) mc1892_62129^=0xDEADULL; (void)mc1892_62129; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^237ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma1894_5743=3757048231ULL; volatile unsigned long long mb1895_16046=2530784713ULL; volatile unsigned long long mc1896_30482=ma1894_5743^mb1895_16046; mc1896_30482=(ma1894_5743^mb1895_16046)+((ma1894_5743&mb1895_16046)<<1); (void)mc1896_30482; } } C.state = 441032;
      break;
    case 353028:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { unsigned long long mt1898_57254=C.cookie^238ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt1898_57254) | 0ULL)); }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1899_37698=4198486261ULL; volatile unsigned long long mb1900_44330=1463981075ULL; volatile unsigned long long mc1901_62417=ma1899_37698^mb1900_44330; for(volatile int _i=0;_i<2;++_i) mc1901_62417=vm_main_int___a100e2bc_mix(mc1901_62417+_i); (void)mc1901_62417; } } C.state = 126154;
      break;
    case 201554:
      
      
      { volatile unsigned long long mh1902_45282=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1902_45282; }
      { volatile unsigned long long ma1903_42587=1300146573ULL; volatile unsigned long long mb1904_4702=4262466009ULL; volatile unsigned long long mc1905_32711=ma1903_42587^mb1904_4702; mc1905_32711=(((mc1905_32711) ^ (mc1905_32711)) + (mc1905_32711)); (void)mc1905_32711; }
      { volatile unsigned long long mt1906_46766=C.cookie;mt1906_46766^=239ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1906_46766); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 774710; } else { { volatile unsigned long long ma1907_58961=2857579927ULL; volatile unsigned long long mb1908_57800=4056263033ULL; volatile unsigned long long mc1909_44999=ma1907_58961^mb1908_57800; mc1909_44999=(ma1907_58961^mb1908_57800)+((ma1907_58961&mb1908_57800)<<1); (void)mc1909_44999; } C.state = 774710; }
      break;
    case 267965:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1910_10572=1121196641ULL; volatile unsigned long long mb1911_41759=2749230035ULL; volatile unsigned long long mc1912_22725=ma1910_10572^mb1911_41759; if(((mc1912_22725 ^ mc1912_22725) != 0ULL)) mc1912_22725^=0xDEADULL; (void)mc1912_22725; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^240ULL);
      { { volatile unsigned long long ma1917_11291=481911907ULL; volatile unsigned long long mb1918_15737=1999934017ULL; volatile unsigned long long mc1919_54090=ma1917_11291^mb1918_15737; mc1919_54090=((mc1919_54090) + 0ULL); (void)mc1919_54090; } C.state = 621700; }
      break;
    case 386655:
      
      
      { volatile unsigned long long mh1920_28499=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1920_28499; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^241ULL);
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1923_62774=4077286771ULL; volatile unsigned long long mb1924_2758=63770989ULL; volatile unsigned long long mc1925_48060=ma1923_62774^mb1924_2758; for(volatile int _i=0;_i<3;++_i) mc1925_48060=vm_main_int___a100e2bc_mix(mc1925_48060+_i); (void)mc1925_48060; } } C.state = 956703;
      break;
    case 707787:
      
      
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1926_5091=2613460405ULL; volatile unsigned long long mb1927_44893=2058668435ULL; volatile unsigned long long mc1928_61065=ma1926_5091^mb1927_44893; mc1928_61065=(ma1926_5091^mb1927_44893)+((ma1926_5091&mb1927_44893)<<1); (void)mc1928_61065; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^242ULL);
      { { volatile unsigned long long ma1933_48810=4159859293ULL; volatile unsigned long long mb1934_42531=1713004503ULL; volatile unsigned long long mc1935_13760=ma1933_48810^mb1934_42531; for(volatile int _i=0;_i<3;++_i) mc1935_13760=vm_main_int___a100e2bc_mix(mc1935_13760+_i); (void)mc1935_13760; } C.state = 891920; }
      break;
    case 124287:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma1936_15232=1582460363ULL; volatile unsigned long long mb1937_52113=685130323ULL; volatile unsigned long long mc1938_26030=ma1936_15232^mb1937_52113; mc1938_26030=(ma1936_15232^mb1937_52113)+((ma1936_15232&mb1937_52113)<<1); (void)mc1938_26030; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^243ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 277786; } else { { volatile unsigned long long ma1940_11513=272658373ULL; volatile unsigned long long mb1941_22312=976754799ULL; volatile unsigned long long mc1942_29994=ma1940_11513^mb1941_22312; mc1942_29994=((mc1942_29994) | 0ULL); (void)mc1942_29994; } C.state = 277786; }
      break;
    case 173610:
      
      
      { volatile unsigned long long ma1943_49263=2549830467ULL; volatile unsigned long long mb1944_519=1873553719ULL; volatile unsigned long long mc1945_501=ma1943_49263^mb1944_519; mc1945_501=(ma1943_49263^mb1944_519)+((ma1943_49263&mb1944_519)<<1); (void)mc1945_501; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^244ULL);
      { { volatile unsigned long long ma1950_58932=2288924419ULL; volatile unsigned long long mb1951_1849=3662356551ULL; volatile unsigned long long mc1952_15307=ma1950_58932^mb1951_1849; for(volatile int _i=0;_i<3;++_i) mc1952_15307=vm_main_int___a100e2bc_mix(mc1952_15307+_i); (void)mc1952_15307; } C.state = 11528; }
      break;
    case 955357:
      
      
      { volatile unsigned long long mh1953_53130=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1953_53130; }
      { volatile unsigned long long mt1954_28225=C.cookie;mt1954_28225^=245ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1954_28225); }
      { { volatile unsigned long long ma1958_59218=3488189019ULL; volatile unsigned long long mb1959_8883=1829229711ULL; volatile unsigned long long mc1960_27104=ma1958_59218^mb1959_8883; mc1960_27104=(ma1958_59218^mb1959_8883)+((ma1958_59218&mb1959_8883)<<1); (void)mc1960_27104; } C.state = 210889; }
      break;
    case 50464:
      
      
      { volatile unsigned long long ma1961_26782=557930945ULL; volatile unsigned long long mb1962_3304=3287864225ULL; volatile unsigned long long mc1963_12534=ma1961_26782^mb1962_3304; if((((mc1963_12534 * 2ULL) & 1ULL) != 0ULL)) mc1963_12534^=0xDEADULL; (void)mc1963_12534; }
      { volatile unsigned long long mt1964_38432=C.cookie;mt1964_38432^=246ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1964_38432); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 657346; } else { { volatile unsigned long long ma1965_32165=328015575ULL; volatile unsigned long long mb1966_60172=3626900219ULL; volatile unsigned long long mc1967_26808=ma1965_32165^mb1966_60172; if((((mc1967_26808 + 0ULL) ^ (mc1967_26808 + 0ULL)) == 1ULL)) mc1967_26808^=0xDEADULL; (void)mc1967_26808; } C.state = 657346; }
      break;
    case 441032:
      
      
      { volatile unsigned long long ma1968_51910=1242733099ULL; volatile unsigned long long mb1969_58514=3591320939ULL; volatile unsigned long long mc1970_7001=ma1968_51910^mb1969_58514; mc1970_7001=(ma1968_51910^mb1969_58514)+((ma1968_51910&mb1969_58514)<<1); (void)mc1970_7001; }
      { volatile unsigned long long mh1971_30052=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1971_30052; }
      { unsigned long long mt1972_20177=C.cookie^247ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt1972_20177) ^ (mt1972_20177)) + (mt1972_20177))); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 953405; } else { { volatile unsigned long long ma1973_31121=836902749ULL; volatile unsigned long long mb1974_50120=1660304571ULL; volatile unsigned long long mc1975_4368=ma1973_31121^mb1974_50120; mc1975_4368=(ma1973_31121^mb1974_50120)+((ma1973_31121&mb1974_50120)<<1); (void)mc1975_4368; } C.state = 953405; }
      break;
    case 183177:
      
      
      { volatile unsigned long long ma1976_6354=3821568895ULL; volatile unsigned long long mb1977_14101=387959037ULL; volatile unsigned long long mc1978_30995=ma1976_6354^mb1977_14101; if((((mc1978_30995 + 0ULL) ^ (mc1978_30995 + 0ULL)) == 1ULL)) mc1978_30995^=0xDEADULL; (void)mc1978_30995; }
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma1979_13801=2252488501ULL; volatile unsigned long long mb1980_5355=3358028185ULL; volatile unsigned long long mc1981_39624=ma1979_13801^mb1980_5355; if((((mc1981_39624 | 0ULL) & 0ULL) != 0ULL)) mc1981_39624^=0xDEADULL; (void)mc1981_39624; } }
      { volatile unsigned long long mt1982_31078=C.cookie;mt1982_31078^=248ULL;C.cookie=vm_main_int___a100e2bc_mix(mt1982_31078); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma1983_4472=3335304927ULL; volatile unsigned long long mb1984_12718=3148919315ULL; volatile unsigned long long mc1985_41554=ma1983_4472^mb1984_12718; for(volatile int _i=0;_i<1;++_i) mc1985_41554=vm_main_int___a100e2bc_mix(mc1985_41554+_i); (void)mc1985_41554; } } C.state = 125221;
      break;
    case 144442:
      
      
      { volatile unsigned long long mh1986_63311=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1986_63311; }
      { volatile unsigned long long ma1987_38263=2612355259ULL; volatile unsigned long long mb1988_19300=2001536899ULL; volatile unsigned long long mc1989_63694=ma1987_38263^mb1988_19300; for(volatile int _i=0;_i<1;++_i) mc1989_63694=vm_main_int___a100e2bc_mix(mc1989_63694+_i); (void)mc1989_63694; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^249ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 470319; } else { { volatile unsigned long long ma1991_50729=1774940229ULL; volatile unsigned long long mb1992_37261=482808375ULL; volatile unsigned long long mc1993_18988=ma1991_50729^mb1992_37261; if((((mc1993_18988 + 0ULL) ^ (mc1993_18988 + 0ULL)) == 1ULL)) mc1993_18988^=0xDEADULL; (void)mc1993_18988; } C.state = 470319; }
      break;
    case 277786:
      
      
      { volatile unsigned long long mh1994_16460=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh1994_16460; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^250ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 125221; } else { { volatile unsigned long long ma1996_52472=1647734189ULL; volatile unsigned long long mb1997_48348=839342105ULL; volatile unsigned long long mc1998_21147=ma1996_52472^mb1997_48348; mc1998_21147=(ma1996_52472^mb1997_48348)+((ma1996_52472&mb1997_48348)<<1); (void)mc1998_21147; } C.state = 125221; }
      break;
    case 752362:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long mt2000_43443=C.cookie;mt2000_43443^=251ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2000_43443); }
      { { volatile unsigned long long ma2004_29603=485885377ULL; volatile unsigned long long mb2005_17491=1714143025ULL; volatile unsigned long long mc2006_2051=ma2004_29603^mb2005_17491; for(volatile int _i=0;_i<3;++_i) mc2006_2051=vm_main_int___a100e2bc_mix(mc2006_2051+_i); (void)mc2006_2051; } C.state = 200335; }
      break;
    case 125300:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma2007_6841=3009653881ULL; volatile unsigned long long mb2008_62619=3703912005ULL; volatile unsigned long long mc2009_5594=ma2007_6841^mb2008_62619; mc2009_5594=((mc2009_5594) | 0ULL); (void)mc2009_5594; } }
      { unsigned long long mt2010_48912=C.cookie^252ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt2010_48912) ^ (mt2010_48912)) + (mt2010_48912))); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 949916; } else { { volatile unsigned long long ma2011_44224=84720331ULL; volatile unsigned long long mb2012_37295=3054497023ULL; volatile unsigned long long mc2013_54056=ma2011_44224^mb2012_37295; for(volatile int _i=0;_i<3;++_i) mc2013_54056=vm_main_int___a100e2bc_mix(mc2013_54056+_i); (void)mc2013_54056; } C.state = 949916; }
      break;
    case 217347:
      
      
      { volatile unsigned long long mh2014_46846=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2014_46846; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^253ULL);
      { { volatile unsigned long long ma2019_57918=1856439777ULL; volatile unsigned long long mb2020_37529=3682397045ULL; volatile unsigned long long mc2021_2860=ma2019_57918^mb2020_37529; mc2021_2860=(ma2019_57918^mb2020_37529)+((ma2019_57918&mb2020_37529)<<1); (void)mc2021_2860; } C.state = 411956; }
      break;
    case 949916:
      
      
      { volatile unsigned long long mt2022_1063=C.cookie;mt2022_1063^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2022_1063); }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^254ULL);
      { { volatile unsigned long long ma2027_51799=258628865ULL; volatile unsigned long long mb2028_8008=1452974883ULL; volatile unsigned long long mc2029_58127=ma2027_51799^mb2028_8008; if((((mc2029_58127 * 2ULL) & 1ULL) != 0ULL)) mc2029_58127^=0xDEADULL; (void)mc2029_58127; } C.state = 202866; }
      break;
    case 422046:
      
      
      { volatile unsigned long long ma2030_5836=3046410553ULL; volatile unsigned long long mb2031_44434=2114631599ULL; volatile unsigned long long mc2032_19674=ma2030_5836^mb2031_44434; mc2032_19674=((mc2032_19674) + 0ULL); (void)mc2032_19674; }
      { unsigned long long mt2033_28750=C.cookie^255ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt2033_28750) ^ (mt2033_28750)) + (mt2033_28750))); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 774710; } else { { volatile unsigned long long ma2034_38137=4029333395ULL; volatile unsigned long long mb2035_38662=2159159389ULL; volatile unsigned long long mc2036_62768=ma2034_38137^mb2035_38662; if((((mc2036_62768 | 0ULL) & 0ULL) != 0ULL)) mc2036_62768^=0xDEADULL; (void)mc2036_62768; } C.state = 774710; }
      break;
    case 981433:
      
      
      { volatile unsigned long long mt2037_65038=C.cookie;mt2037_65038^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2037_65038); }
      { unsigned long long mt2038_51060=C.cookie^256ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt2038_51060) | 0ULL)); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 164343; } else { { volatile unsigned long long ma2039_49092=611066227ULL; volatile unsigned long long mb2040_22253=3410426033ULL; volatile unsigned long long mc2041_23141=ma2039_49092^mb2040_22253; if((((mc2041_23141 + 0ULL) ^ (mc2041_23141 + 0ULL)) == 1ULL)) mc2041_23141^=0xDEADULL; (void)mc2041_23141; } C.state = 164343; }
      break;
    case 831320:
      
      
      { volatile unsigned long long mh2042_2828=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2042_2828; }
      { volatile unsigned long long mh2043_42581=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2043_42581; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^257ULL);
      { { volatile unsigned long long ma2048_240=2918292695ULL; volatile unsigned long long mb2049_18190=1580702885ULL; volatile unsigned long long mc2050_32499=ma2048_240^mb2049_18190; mc2050_32499=(ma2048_240^mb2049_18190)+((ma2048_240&mb2049_18190)<<1); (void)mc2050_32499; } C.state = 774710; }
      break;
    case 485845:
      
      
      { volatile unsigned long long mh2051_10963=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2051_10963; }
      { volatile unsigned long long mt2052_42117=C.cookie;mt2052_42117^=258ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2052_42117); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma2053_38196=212100691ULL; volatile unsigned long long mb2054_21646=3312952257ULL; volatile unsigned long long mc2055_53814=ma2053_38196^mb2054_21646; mc2055_53814=((mc2055_53814) + 0ULL); (void)mc2055_53814; } } C.state = 424444;
      break;
    case 60342:
      
      
      { volatile unsigned long long ma2056_50924=2681105295ULL; volatile unsigned long long mb2057_52687=2657685999ULL; volatile unsigned long long mc2058_42943=ma2056_50924^mb2057_52687; for(volatile int _i=0;_i<2;++_i) mc2058_42943=vm_main_int___a100e2bc_mix(mc2058_42943+_i); (void)mc2058_42943; }
      { volatile unsigned long long mt2059_37481=C.cookie;mt2059_37481^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2059_37481); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^259ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma2061_25297=495173281ULL; volatile unsigned long long mb2062_27146=1314151117ULL; volatile unsigned long long mc2063_38213=ma2061_25297^mb2062_27146; if((((mc2063_38213 * 2ULL) & 1ULL) != 0ULL)) mc2063_38213^=0xDEADULL; (void)mc2063_38213; } } C.state = 204930;
      break;
    case 349245:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^260ULL);
      { { volatile unsigned long long ma2069_38362=2540144823ULL; volatile unsigned long long mb2070_59087=2258484585ULL; volatile unsigned long long mc2071_20334=ma2069_38362^mb2070_59087; for(volatile int _i=0;_i<3;++_i) mc2071_20334=vm_main_int___a100e2bc_mix(mc2071_20334+_i); (void)mc2071_20334; } C.state = 952311; }
      break;
    case 210889:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma2072_53819=3938489811ULL; volatile unsigned long long mb2073_22295=2251421147ULL; volatile unsigned long long mc2074_46862=ma2072_53819^mb2073_22295; mc2074_46862=(ma2072_53819^mb2073_22295)+((ma2072_53819&mb2073_22295)<<1); (void)mc2074_46862; } }
      { volatile unsigned long long mh2075_35219=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2075_35219; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^261ULL);
      { { volatile unsigned long long ma2080_2484=3014561ULL; volatile unsigned long long mb2081_46231=3964569927ULL; volatile unsigned long long mc2082_9592=ma2080_2484^mb2081_46231; mc2082_9592=(ma2080_2484^mb2081_46231)+((ma2080_2484&mb2081_46231)<<1); (void)mc2082_9592; } C.state = 114126; }
      break;
    case 221745:
      
      
      { volatile unsigned long long ma2083_37856=785858097ULL; volatile unsigned long long mb2084_48444=3616264649ULL; volatile unsigned long long mc2085_56157=ma2083_37856^mb2084_48444; mc2085_56157=((mc2085_56157) + 0ULL); (void)mc2085_56157; }
      { volatile unsigned long long ma2086_41106=414398249ULL; volatile unsigned long long mb2087_45326=3393921425ULL; volatile unsigned long long mc2088_28078=ma2086_41106^mb2087_45326; mc2088_28078=((mc2088_28078) ^ 0ULL); (void)mc2088_28078; }
      { volatile unsigned long long mt2089_54397=C.cookie;mt2089_54397^=262ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2089_54397); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 65716; } else { { volatile unsigned long long ma2090_6455=2396554707ULL; volatile unsigned long long mb2091_1469=735887703ULL; volatile unsigned long long mc2092_23991=ma2090_6455^mb2091_1469; if((((mc2092_23991 * 2ULL) & 1ULL) != 0ULL)) mc2092_23991^=0xDEADULL; (void)mc2092_23991; } C.state = 65716; }
      break;
    case 204930:
      
      
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma2093_35046=832399499ULL; volatile unsigned long long mb2094_27689=2116601071ULL; volatile unsigned long long mc2095_19418=ma2093_35046^mb2094_27689; mc2095_19418=((mc2095_19418) ^ 0ULL); (void)mc2095_19418; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^263ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 200335; } else { { volatile unsigned long long ma2098_57985=1493541423ULL; volatile unsigned long long mb2099_5589=3293516409ULL; volatile unsigned long long mc2100_50636=ma2098_57985^mb2099_5589; mc2100_50636=(((mc2100_50636) ^ (mc2100_50636)) + (mc2100_50636)); (void)mc2100_50636; } C.state = 200335; }
      break;
    case 918008:
      
      
      { volatile unsigned long long mh2101_40453=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2101_40453; }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2102_50275=982885577ULL; volatile unsigned long long mb2103_61143=1238784773ULL; volatile unsigned long long mc2104_55078=ma2102_50275^mb2103_61143; if((((mc2104_55078 * 2ULL) & 1ULL) != 0ULL)) mc2104_55078^=0xDEADULL; (void)mc2104_55078; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^264ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma2106_59384=1074336407ULL; volatile unsigned long long mb2107_84=2103814309ULL; volatile unsigned long long mc2108_34697=ma2106_59384^mb2107_84; mc2108_34697=(ma2106_59384^mb2107_84)+((ma2106_59384&mb2107_84)<<1); (void)mc2108_34697; } } C.state = 613491;
      break;
    case 393959:
      
      
      { volatile unsigned long long mh2109_57810=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2109_57810; }
      { unsigned long long mt2110_4895=C.cookie^265ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt2110_4895) | 0ULL)); }
      { { volatile unsigned long long ma2114_44602=1797722681ULL; volatile unsigned long long mb2115_28764=203190085ULL; volatile unsigned long long mc2116_30546=ma2114_44602^mb2115_28764; for(volatile int _i=0;_i<2;++_i) mc2116_30546=vm_main_int___a100e2bc_mix(mc2116_30546+_i); (void)mc2116_30546; } C.state = 802929; }
      break;
    case 425683:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2117_53593=4286515455ULL; volatile unsigned long long mb2118_19167=3526712209ULL; volatile unsigned long long mc2119_5901=ma2117_53593^mb2118_19167; if(((mc2119_5901 ^ mc2119_5901) != 0ULL)) mc2119_5901^=0xDEADULL; (void)mc2119_5901; } }
      { volatile unsigned long long ma2120_49898=1305595385ULL; volatile unsigned long long mb2121_53851=2858711745ULL; volatile unsigned long long mc2122_13779=ma2120_49898^mb2121_53851; if(((mc2122_13779 ^ mc2122_13779) != 0ULL)) mc2122_13779^=0xDEADULL; (void)mc2122_13779; }
      { unsigned long long mt2123_43534=C.cookie^266ULL;C.cookie=vm_main_int___a100e2bc_mix(((mt2123_43534) + 0ULL)); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 462330; } else { { volatile unsigned long long ma2124_45943=3987140449ULL; volatile unsigned long long mb2125_4120=3386551825ULL; volatile unsigned long long mc2126_59161=ma2124_45943^mb2125_4120; if((((mc2126_59161 + 0ULL) ^ (mc2126_59161 + 0ULL)) == 1ULL)) mc2126_59161^=0xDEADULL; (void)mc2126_59161; } C.state = 462330; }
      break;
    case 71141:
      
      
      { volatile unsigned long long ma2127_62815=1663763877ULL; volatile unsigned long long mb2128_24064=622494307ULL; volatile unsigned long long mc2129_21474=ma2127_62815^mb2128_24064; if((((mc2129_21474 | 0ULL) & 0ULL) != 0ULL)) mc2129_21474^=0xDEADULL; (void)mc2129_21474; }
      { volatile unsigned long long mt2130_33173=C.cookie;mt2130_33173^=267ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2130_33173); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 296863; } else { { volatile unsigned long long ma2131_1120=4153684139ULL; volatile unsigned long long mb2132_1706=45854563ULL; volatile unsigned long long mc2133_48890=ma2131_1120^mb2132_1706; mc2133_48890=(((mc2133_48890) & (mc2133_48890)) | ((mc2133_48890) & 0ULL)); (void)mc2133_48890; } C.state = 296863; }
      break;
    case 94321:
      
      
      { unsigned long long mt2134_36043=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt2134_36043) ^ (mt2134_36043)) + (mt2134_36043))); }
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma2135_55044=3224180241ULL; volatile unsigned long long mb2136_21222=1446279355ULL; volatile unsigned long long mc2137_10027=ma2135_55044^mb2136_21222; for(volatile int _i=0;_i<3;++_i) mc2137_10027=vm_main_int___a100e2bc_mix(mc2137_10027+_i); (void)mc2137_10027; } }
      { volatile unsigned long long mt2138_51197=C.cookie;mt2138_51197^=268ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2138_51197); }
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2139_38912=3995900717ULL; volatile unsigned long long mb2140_44734=2477513239ULL; volatile unsigned long long mc2141_13330=ma2139_38912^mb2140_44734; mc2141_13330=(ma2139_38912^mb2140_44734)+((ma2139_38912&mb2140_44734)<<1); (void)mc2141_13330; } } C.state = 898399;
      break;
    case 314028:
      
      
      { volatile unsigned long long mt2142_29616=C.cookie;mt2142_29616^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2142_29616); }
      { volatile unsigned long long ma2143_11521=3391820795ULL; volatile unsigned long long mb2144_16841=1854590763ULL; volatile unsigned long long mc2145_8673=ma2143_11521^mb2144_16841; for(volatile int _i=0;_i<3;++_i) mc2145_8673=vm_main_int___a100e2bc_mix(mc2145_8673+_i); (void)mc2145_8673; }
      { unsigned long long mt2146_43862=C.cookie^269ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt2146_43862) ^ (mt2146_43862)) + (mt2146_43862))); }
      { { volatile unsigned long long ma2150_26594=1707700955ULL; volatile unsigned long long mb2151_359=1117667539ULL; volatile unsigned long long mc2152_25457=ma2150_26594^mb2151_359; for(volatile int _i=0;_i<1;++_i) mc2152_25457=vm_main_int___a100e2bc_mix(mc2152_25457+_i); (void)mc2152_25457; } C.state = 898399; }
      break;
    case 703921:
      
      
      { unsigned long long mt2153_54161=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt2153_54161) ^ (mt2153_54161)) + (mt2153_54161))); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^270ULL);
      { { volatile unsigned long long ma2158_64630=192716429ULL; volatile unsigned long long mb2159_39124=5753249ULL; volatile unsigned long long mc2160_3167=ma2158_64630^mb2159_39124; mc2160_3167=(ma2158_64630^mb2159_39124)+((ma2158_64630&mb2159_39124)<<1); (void)mc2160_3167; } C.state = 125221; }
      break;
    case 255449:
      
      
      { volatile unsigned long long ma2161_10512=3641558587ULL; volatile unsigned long long mb2162_37100=802737673ULL; volatile unsigned long long mc2163_7442=ma2161_10512^mb2162_37100; mc2163_7442=(ma2161_10512^mb2162_37100)+((ma2161_10512&mb2162_37100)<<1); (void)mc2163_7442; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^271ULL);
      { { volatile unsigned long long ma2168_61024=841774433ULL; volatile unsigned long long mb2169_10001=4198727315ULL; volatile unsigned long long mc2170_10877=ma2168_61024^mb2169_10001; if((((mc2170_10877 + 0ULL) ^ (mc2170_10877 + 0ULL)) == 1ULL)) mc2170_10877^=0xDEADULL; (void)mc2170_10877; } C.state = 424444; }
      break;
    case 462330:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long ma2172_24382=2285589725ULL; volatile unsigned long long mb2173_55059=3215666619ULL; volatile unsigned long long mc2174_56102=ma2172_24382^mb2173_55059; mc2174_56102=(((mc2174_56102) ^ (mc2174_56102)) + (mc2174_56102)); (void)mc2174_56102; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^272ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 65716; } else { { volatile unsigned long long ma2176_60456=2292565055ULL; volatile unsigned long long mb2177_43385=2375446101ULL; volatile unsigned long long mc2178_31831=ma2176_60456^mb2177_43385; mc2178_31831=((mc2178_31831) + 0ULL); (void)mc2178_31831; } C.state = 65716; }
      break;
    case 164343:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2179_38322=2812071873ULL; volatile unsigned long long mb2180_51112=744610173ULL; volatile unsigned long long mc2181_20710=ma2179_38322^mb2180_51112; for(volatile int _i=0;_i<2;++_i) mc2181_20710=vm_main_int___a100e2bc_mix(mc2181_20710+_i); (void)mc2181_20710; } }
      { volatile unsigned long long mh2182_52352=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2182_52352; }
      { volatile unsigned long long mt2183_47518=C.cookie;mt2183_47518^=273ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2183_47518); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 842480; } else { { volatile unsigned long long ma2184_23711=914588701ULL; volatile unsigned long long mb2185_62119=929034897ULL; volatile unsigned long long mc2186_10591=ma2184_23711^mb2185_62119; for(volatile int _i=0;_i<1;++_i) mc2186_10591=vm_main_int___a100e2bc_mix(mc2186_10591+_i); (void)mc2186_10591; } C.state = 842480; }
      break;
    case 750618:
      
      
      { volatile unsigned long long mh2187_47815=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2187_47815; }
      { volatile unsigned long long mt2188_24949=C.cookie;mt2188_24949^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2188_24949); }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^274ULL);
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma2190_63031=3906830369ULL; volatile unsigned long long mb2191_59347=139169013ULL; volatile unsigned long long mc2192_52630=ma2190_63031^mb2191_59347; for(volatile int _i=0;_i<2;++_i) mc2192_52630=vm_main_int___a100e2bc_mix(mc2192_52630+_i); (void)mc2192_52630; } } C.state = 409896;
      break;
    case 69587:
      
      
      { volatile unsigned long long mt2193_37579=C.cookie;mt2193_37579^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2193_37579); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^275ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma2195_47466=4061134899ULL; volatile unsigned long long mb2196_15236=3889114141ULL; volatile unsigned long long mc2197_29062=ma2195_47466^mb2196_15236; mc2197_29062=(((mc2197_29062) & (mc2197_29062)) | ((mc2197_29062) & 0ULL)); (void)mc2197_29062; } } C.state = 657346;
      break;
    case 764571:
      
      
      { volatile unsigned long long ma2198_36077=2235092171ULL; volatile unsigned long long mb2199_49379=2714130395ULL; volatile unsigned long long mc2200_61489=ma2198_36077^mb2199_49379; for(volatile int _i=0;_i<2;++_i) mc2200_61489=vm_main_int___a100e2bc_mix(mc2200_61489+_i); (void)mc2200_61489; }
      { volatile unsigned long long ma2201_26989=831999885ULL; volatile unsigned long long mb2202_38537=3011515111ULL; volatile unsigned long long mc2203_16665=ma2201_26989^mb2202_38537; if((((mc2203_16665 * 2ULL) & 1ULL) != 0ULL)) mc2203_16665^=0xDEADULL; (void)mc2203_16665; }
      { volatile unsigned long long mt2204_9564=C.cookie;mt2204_9564^=276ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2204_9564); }
      { { volatile unsigned long long ma2208_51756=192624577ULL; volatile unsigned long long mb2209_16677=360118513ULL; volatile unsigned long long mc2210_21357=ma2208_51756^mb2209_16677; mc2210_21357=((mc2210_21357) ^ 0ULL); (void)mc2210_21357; } C.state = 802929; }
      break;
    case 657346:
      
      
      { volatile unsigned long long mh2211_447=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2211_447; }
      { volatile unsigned long long mt2212_49398=C.cookie;mt2212_49398^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2212_49398); }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^277ULL);
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 470319; } else { { volatile unsigned long long ma2214_42605=1876532545ULL; volatile unsigned long long mb2215_7817=3068303001ULL; volatile unsigned long long mc2216_38559=ma2214_42605^mb2215_7817; mc2216_38559=(((mc2216_38559) ^ (mc2216_38559)) + (mc2216_38559)); (void)mc2216_38559; } C.state = 470319; }
      break;
    case 613491:
      
      
      { volatile unsigned long long mh2217_49551=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2217_49551; }
      { volatile unsigned long long ma2218_62535=3742638933ULL; volatile unsigned long long mb2219_59425=2453644077ULL; volatile unsigned long long mc2220_1841=ma2218_62535^mb2219_59425; mc2220_1841=(ma2218_62535^mb2219_59425)+((ma2218_62535&mb2219_59425)<<1); (void)mc2220_1841; }
      { unsigned long long mt2221_23748=C.cookie^278ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt2221_23748) & (mt2221_23748)) | ((mt2221_23748) & 0ULL))); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 891920; } else { { volatile unsigned long long ma2222_39065=3176943027ULL; volatile unsigned long long mb2223_60593=755724533ULL; volatile unsigned long long mc2224_22792=ma2222_39065^mb2223_60593; if((((mc2224_22792 | 0ULL) & 0ULL) != 0ULL)) mc2224_22792^=0xDEADULL; (void)mc2224_22792; } C.state = 891920; }
      break;
    case 898399:
      
      
      { volatile unsigned long long mt2225_43859=C.cookie;mt2225_43859^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2225_43859); }
      { volatile unsigned long long ma2226_22388=4280617813ULL; volatile unsigned long long mb2227_38212=1616278973ULL; volatile unsigned long long mc2228_39651=ma2226_22388^mb2227_38212; mc2228_39651=(ma2226_22388^mb2227_38212)+((ma2226_22388&mb2227_38212)<<1); (void)mc2228_39651; }
      { unsigned long long mt2229_2416=C.cookie^279ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt2229_2416) & (mt2229_2416)) | ((mt2229_2416) & 0ULL))); }
      { { volatile unsigned long long ma2233_37906=1639374019ULL; volatile unsigned long long mb2234_36068=2222122821ULL; volatile unsigned long long mc2235_27537=ma2233_37906^mb2234_36068; mc2235_27537=(ma2233_37906^mb2234_36068)+((ma2233_37906&mb2234_36068)<<1); (void)mc2235_27537; } C.state = 774710; }
      break;
    case 216980:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2236_54886=2502928187ULL; volatile unsigned long long mb2237_19838=637551851ULL; volatile unsigned long long mc2238_43481=ma2236_54886^mb2237_19838; for(volatile int _i=0;_i<1;++_i) mc2238_43481=vm_main_int___a100e2bc_mix(mc2238_43481+_i); (void)mc2238_43481; } }
      { volatile unsigned long long mt2239_50868=C.cookie;mt2239_50868^=280ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2239_50868); }
      { { volatile unsigned long long ma2243_28606=1033184715ULL; volatile unsigned long long mb2244_37240=997492481ULL; volatile unsigned long long mc2245_47658=ma2243_28606^mb2244_37240; mc2245_47658=(ma2243_28606^mb2244_37240)+((ma2243_28606&mb2244_37240)<<1); (void)mc2245_47658; } C.state = 342173; }
      break;
    case 409896:
      
      
      { volatile unsigned long long ma2246_32106=1675363249ULL; volatile unsigned long long mb2247_32807=630876867ULL; volatile unsigned long long mc2248_24796=ma2246_32106^mb2247_32807; mc2248_24796=(ma2246_32106^mb2247_32807)+((ma2246_32106&mb2247_32807)<<1); (void)mc2248_24796; }
      { volatile unsigned long long mt2249_49317=C.cookie;mt2249_49317^=281ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2249_49317); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 65716; } else { { volatile unsigned long long ma2250_1536=2722403611ULL; volatile unsigned long long mb2251_5963=3801274347ULL; volatile unsigned long long mc2252_24052=ma2250_1536^mb2251_5963; if((((mc2252_24052 * 2ULL) & 1ULL) != 0ULL)) mc2252_24052^=0xDEADULL; (void)mc2252_24052; } C.state = 65716; }
      break;
    case 390458:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^282ULL);
      { { volatile unsigned long long ma2258_44725=3896686889ULL; volatile unsigned long long mb2259_40628=1463213719ULL; volatile unsigned long long mc2260_43654=ma2258_44725^mb2259_40628; mc2260_43654=((mc2260_43654) | 0ULL); (void)mc2260_43654; } C.state = 522169; }
      break;
    case 621700:
      
      
      { volatile unsigned long long mh2261_49526=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2261_49526; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^283ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 842480; } else { { volatile unsigned long long ma2263_47548=2010300965ULL; volatile unsigned long long mb2264_17404=3840282741ULL; volatile unsigned long long mc2265_31903=ma2263_47548^mb2264_17404; if((((mc2265_31903 + 0ULL) ^ (mc2265_31903 + 0ULL)) == 1ULL)) mc2265_31903^=0xDEADULL; (void)mc2265_31903; } C.state = 842480; }
      break;
    case 176058:
      
      
      { volatile unsigned long long mh2266_7646=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2266_7646; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^284ULL);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 802929; } else { { volatile unsigned long long ma2268_25643=1407298565ULL; volatile unsigned long long mb2269_17937=2392758565ULL; volatile unsigned long long mc2270_14202=ma2268_25643^mb2269_17937; mc2270_14202=((mc2270_14202) + 0ULL); (void)mc2270_14202; } C.state = 802929; }
      break;
    case 126154:
      
      
      { volatile unsigned long long ma2271_34415=2935210083ULL; volatile unsigned long long mb2272_50523=3387549837ULL; volatile unsigned long long mc2273_58865=ma2271_34415^mb2272_50523; mc2273_58865=(ma2271_34415^mb2272_50523)+((ma2271_34415&mb2272_50523)<<1); (void)mc2273_58865; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^285ULL);
      { { volatile unsigned long long ma2278_36995=43980173ULL; volatile unsigned long long mb2279_34243=1963317193ULL; volatile unsigned long long mc2280_7873=ma2278_36995^mb2279_34243; if((((mc2280_7873 + 0ULL) ^ (mc2280_7873 + 0ULL)) == 1ULL)) mc2280_7873^=0xDEADULL; (void)mc2280_7873; } C.state = 377110; }
      break;
    case 202866:
      
      
      { volatile unsigned long long ma2281_10806=1148711317ULL; volatile unsigned long long mb2282_47407=1915013471ULL; volatile unsigned long long mc2283_36458=ma2281_10806^mb2282_47407; mc2283_36458=(((mc2283_36458) ^ (mc2283_36458)) + (mc2283_36458)); (void)mc2283_36458; }
      { volatile unsigned long long mt2284_11671=C.cookie;mt2284_11671^=286ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2284_11671); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 471922; } else { { volatile unsigned long long ma2285_46278=2448156625ULL; volatile unsigned long long mb2286_123=2802915739ULL; volatile unsigned long long mc2287_34321=ma2285_46278^mb2286_123; if((((mc2287_34321 | 0ULL) & 0ULL) != 0ULL)) mc2287_34321^=0xDEADULL; (void)mc2287_34321; } C.state = 471922; }
      break;
    case 522169:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^287ULL);
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma2290_38981=400361365ULL; volatile unsigned long long mb2291_50758=3505871611ULL; volatile unsigned long long mc2292_10806=ma2290_38981^mb2291_50758; mc2292_10806=(ma2290_38981^mb2291_50758)+((ma2290_38981&mb2291_50758)<<1); (void)mc2292_10806; } } C.state = 114126;
      break;
    case 424444:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma2293_41832=1176130511ULL; volatile unsigned long long mb2294_62993=489531823ULL; volatile unsigned long long mc2295_1826=ma2293_41832^mb2294_62993; for(volatile int _i=0;_i<2;++_i) mc2295_1826=vm_main_int___a100e2bc_mix(mc2295_1826+_i); (void)mc2295_1826; } }
      { volatile unsigned long long mt2296_6714=C.cookie;mt2296_6714^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2296_6714); }
      { volatile unsigned long long mt2297_21574=C.cookie;mt2297_21574^=288ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2297_21574); }
      { { volatile unsigned long long ma2301_38814=2912194485ULL; volatile unsigned long long mb2302_60210=2682465977ULL; volatile unsigned long long mc2303_49495=ma2301_38814^mb2302_60210; mc2303_49495=(ma2301_38814^mb2302_60210)+((ma2301_38814&mb2302_60210)<<1); (void)mc2303_49495; } C.state = 774710; }
      break;
    case 464365:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^289ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma2306_51198=2425510805ULL; volatile unsigned long long mb2307_721=1723799609ULL; volatile unsigned long long mc2308_46310=ma2306_51198^mb2307_721; mc2308_46310=(ma2306_51198^mb2307_721)+((ma2306_51198&mb2307_721)<<1); (void)mc2308_46310; } } C.state = 296863;
      break;
    case 802929:
      
      
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma2309_49535=561931335ULL; volatile unsigned long long mb2310_26973=352268353ULL; volatile unsigned long long mc2311_26345=ma2309_49535^mb2310_26973; for(volatile int _i=0;_i<1;++_i) mc2311_26345=vm_main_int___a100e2bc_mix(mc2311_26345+_i); (void)mc2311_26345; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long mt2313_29263=C.cookie;mt2313_29263^=290ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2313_29263); }
      if ((((C.cookie ^ (C.cookie << 1)) | 1ULL) != 0ULL)) { C.state = 296905; } else { { volatile unsigned long long ma2314_30491=1888263187ULL; volatile unsigned long long mb2315_62401=3682242981ULL; volatile unsigned long long mc2316_4926=ma2314_30491^mb2315_62401; mc2316_4926=((mc2316_4926) | 0ULL); (void)mc2316_4926; } C.state = 296905; }
      break;
    case 11528:
      
      
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma2317_62=2855258011ULL; volatile unsigned long long mb2318_18705=3416793897ULL; volatile unsigned long long mc2319_17604=ma2317_62^mb2318_18705; mc2319_17604=((mc2319_17604) | 0ULL); (void)mc2319_17604; } }
      { volatile unsigned long long mh2320_39861=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2320_39861; }
      { volatile unsigned long long mt2321_28476=C.cookie;mt2321_28476^=291ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2321_28476); }
      { { volatile unsigned long long ma2325_27953=634730791ULL; volatile unsigned long long mb2326_16820=2095230705ULL; volatile unsigned long long mc2327_29734=ma2325_27953^mb2326_16820; mc2327_29734=(ma2325_27953^mb2326_16820)+((ma2325_27953&mb2326_16820)<<1); (void)mc2327_29734; } C.state = 518447; }
      break;
    case 377110:
      
      
      { volatile unsigned long long mt2328_35989=C.cookie;mt2328_35989^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2328_35989); }
      { volatile unsigned long long mt2329_53259=C.cookie;mt2329_53259^=(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix(mt2329_53259); }
      { unsigned long long mt2330_25300=C.cookie^292ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt2330_25300) ^ (mt2330_25300)) + (mt2330_25300))); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 774710; } else { { volatile unsigned long long ma2331_25377=2900908175ULL; volatile unsigned long long mb2332_37782=2045342427ULL; volatile unsigned long long mc2333_58081=ma2331_25377^mb2332_37782; if((((mc2333_58081 + 0ULL) ^ (mc2333_58081 + 0ULL)) == 1ULL)) mc2333_58081^=0xDEADULL; (void)mc2333_58081; } C.state = 774710; }
      break;
    case 471922:
      
      
      { volatile unsigned long long ma2334_1527=290105081ULL; volatile unsigned long long mb2335_382=3536110887ULL; volatile unsigned long long mc2336_29490=ma2334_1527^mb2335_382; mc2336_29490=(ma2334_1527^mb2335_382)+((ma2334_1527&mb2335_382)<<1); (void)mc2336_29490; }
      { volatile unsigned long long ma2337_32108=1746630159ULL; volatile unsigned long long mb2338_41813=423705421ULL; volatile unsigned long long mc2339_45772=ma2337_32108^mb2338_41813; mc2339_45772=(((mc2339_45772) ^ (mc2339_45772)) + (mc2339_45772)); (void)mc2339_45772; }
      { volatile unsigned long long mt2340_4520=C.cookie;mt2340_4520^=293ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2340_4520); }
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 316821; } else { { volatile unsigned long long ma2341_61884=230350031ULL; volatile unsigned long long mb2342_21346=3153624725ULL; volatile unsigned long long mc2343_32281=ma2341_61884^mb2342_21346; mc2343_32281=(ma2341_61884^mb2342_21346)+((ma2341_61884&mb2342_21346)<<1); (void)mc2343_32281; } C.state = 316821; }
      break;
    case 851570:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^294ULL);
      { { volatile unsigned long long ma2349_43327=2723392389ULL; volatile unsigned long long mb2350_58356=2111724963ULL; volatile unsigned long long mc2351_45528=ma2349_43327^mb2350_58356; if(((mc2351_45528 ^ mc2351_45528) != 0ULL)) mc2351_45528^=0xDEADULL; (void)mc2351_45528; } C.state = 953405; }
      break;
    case 891920:
      
      
      { volatile unsigned long long mh2352_6685=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2352_6685; }
      { unsigned long long mt2353_823=C.cookie^295ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt2353_823) & (mt2353_823)) | ((mt2353_823) & 0ULL))); }
      { { volatile unsigned long long ma2357_27683=2371055695ULL; volatile unsigned long long mb2358_50180=3722402437ULL; volatile unsigned long long mc2359_58354=ma2357_27683^mb2358_50180; if(((mc2359_58354 ^ mc2359_58354) != 0ULL)) mc2359_58354^=0xDEADULL; (void)mc2359_58354; } C.state = 296863; }
      break;
    case 663646:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { unsigned long long mt2361_41647=C.cookie^296ULL;C.cookie=vm_main_int___a100e2bc_mix((((mt2361_41647) & (mt2361_41647)) | ((mt2361_41647) & 0ULL))); }
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 931051; } else { { volatile unsigned long long ma2362_772=45599477ULL; volatile unsigned long long mb2363_11138=2912419173ULL; volatile unsigned long long mc2364_17532=ma2362_772^mb2363_11138; if((((mc2364_17532 | 0ULL) & 0ULL) != 0ULL)) mc2364_17532^=0xDEADULL; (void)mc2364_17532; } C.state = 931051; }
      break;
    case 296905:
      
      
      { volatile unsigned long long mh2365_61493=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2365_61493; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^297ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2367_50713=897587835ULL; volatile unsigned long long mb2368_22457=4217345079ULL; volatile unsigned long long mc2369_65458=ma2367_50713^mb2368_22457; mc2369_65458=(((mc2369_65458) & (mc2369_65458)) | ((mc2369_65458) & 0ULL)); (void)mc2369_65458; } } C.state = 470319;
      break;
    case 956703:
      
      
      { volatile unsigned long long mh2370_11018=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2370_11018; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^298ULL);
      { { volatile unsigned long long ma2375_48613=280189665ULL; volatile unsigned long long mb2376_63945=770378769ULL; volatile unsigned long long mc2377_50904=ma2375_48613^mb2376_63945; if((((mc2377_50904 + 0ULL) ^ (mc2377_50904 + 0ULL)) == 1ULL)) mc2377_50904^=0xDEADULL; (void)mc2377_50904; } C.state = 200335; }
      break;
    case 200335:
      
      
      { volatile unsigned long long ma2378_6326=2490509497ULL; volatile unsigned long long mb2379_32745=3657527379ULL; volatile unsigned long long mc2380_15492=ma2378_6326^mb2379_32745; if((((mc2380_15492 | 0ULL) & 0ULL) != 0ULL)) mc2380_15492^=0xDEADULL; (void)mc2380_15492; }
      { volatile unsigned long long ma2381_63583=3468195739ULL; volatile unsigned long long mb2382_20237=3571697081ULL; volatile unsigned long long mc2383_3325=ma2381_63583^mb2382_20237; if((((mc2383_3325 * 2ULL) & 1ULL) != 0ULL)) mc2383_3325^=0xDEADULL; (void)mc2383_3325; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^299ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 931051; } else { { volatile unsigned long long ma2385_38335=3556055651ULL; volatile unsigned long long mb2386_59362=65818407ULL; volatile unsigned long long mc2387_51821=ma2385_38335^mb2386_59362; if(((mc2387_51821 ^ mc2387_51821) != 0ULL)) mc2387_51821^=0xDEADULL; (void)mc2387_51821; } C.state = 931051; }
      break;
    case 953405:
      
      
      { unsigned long long mt2388_54156=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt2388_54156) & (mt2388_54156)) | ((mt2388_54156) & 0ULL))); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma2389_27136=1600961123ULL; volatile unsigned long long mb2390_55478=871784383ULL; volatile unsigned long long mc2391_4550=ma2389_27136^mb2390_55478; mc2391_4550=(ma2389_27136^mb2390_55478)+((ma2389_27136&mb2390_55478)<<1); (void)mc2391_4550; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^300ULL);
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma2393_21253=2415226853ULL; volatile unsigned long long mb2394_27952=3440033401ULL; volatile unsigned long long mc2395_27995=ma2393_21253^mb2394_27952; mc2395_27995=(ma2393_21253^mb2394_27952)+((ma2393_21253&mb2394_27952)<<1); (void)mc2395_27995; } } C.state = 518447;
      break;
    case 296863:
      
      
      { volatile unsigned long long mh2396_39111=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2396_39111; }
      { volatile unsigned long long mt2397_19618=C.cookie;mt2397_19618^=301ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2397_19618); }
      { { volatile unsigned long long ma2401_47977=2208126757ULL; volatile unsigned long long mb2402_50261=692199113ULL; volatile unsigned long long mc2403_22070=ma2401_47977^mb2402_50261; for(volatile int _i=0;_i<1;++_i) mc2403_22070=vm_main_int___a100e2bc_mix(mc2403_22070+_i); (void)mc2403_22070; } C.state = 125951; }
      break;
    case 125951:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long mt2405_24382=C.cookie;mt2405_24382^=302ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2405_24382); }
      { { volatile unsigned long long ma2409_764=1539665271ULL; volatile unsigned long long mb2410_791=2987880917ULL; volatile unsigned long long mc2411_55729=ma2409_764^mb2410_791; mc2411_55729=(ma2409_764^mb2410_791)+((ma2409_764&mb2410_791)<<1); (void)mc2411_55729; } C.state = 470319; }
      break;
    case 518447:
      
      
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^(unsigned long long)C.steps);
      { volatile unsigned long long ma2413_61579=2246050047ULL; volatile unsigned long long mb2414_56124=986977915ULL; volatile unsigned long long mc2415_45166=ma2413_61579^mb2414_56124; for(volatile int _i=0;_i<2;++_i) mc2415_45166=vm_main_int___a100e2bc_mix(mc2415_45166+_i); (void)mc2415_45166; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^303ULL);
      if (((C.cookie | 1ULL) != 0ULL)) { C.state = 65716; } else { { volatile unsigned long long ma2417_1227=2215387687ULL; volatile unsigned long long mb2418_44116=2849350275ULL; volatile unsigned long long mc2419_1347=ma2417_1227^mb2418_44116; mc2419_1347=(ma2417_1227^mb2418_44116)+((ma2417_1227&mb2418_44116)<<1); (void)mc2419_1347; } C.state = 65716; }
      break;
    case 842480:
      
      
      { volatile unsigned long long mh2420_41456=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2420_41456; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^304ULL);
      if ((((C.cookie * 0x9E3779B97F4A7C15ULL) | 1ULL) != 0ULL)) { C.state = 342173; } else { { volatile unsigned long long ma2422_1831=1960401957ULL; volatile unsigned long long mb2423_52238=859463571ULL; volatile unsigned long long mc2424_11=ma2422_1831^mb2423_52238; mc2424_11=(((mc2424_11) ^ (mc2424_11)) + (mc2424_11)); (void)mc2424_11; } C.state = 342173; }
      break;
    case 342173:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2425_56514=3250638457ULL; volatile unsigned long long mb2426_41595=3482365009ULL; volatile unsigned long long mc2427_51793=ma2425_56514^mb2426_41595; for(volatile int _i=0;_i<2;++_i) mc2427_51793=vm_main_int___a100e2bc_mix(mc2427_51793+_i); (void)mc2427_51793; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^305ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2429_36986=2567057983ULL; volatile unsigned long long mb2430_39847=496648857ULL; volatile unsigned long long mc2431_31345=ma2429_36986^mb2430_39847; mc2431_31345=((mc2431_31345) | 0ULL); (void)mc2431_31345; } } C.state = 470319;
      break;
    case 995650:
      
      
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2432_8618=2761782815ULL; volatile unsigned long long mb2433_40869=2154252435ULL; volatile unsigned long long mc2434_32113=ma2432_8618^mb2433_40869; mc2434_32113=(((mc2434_32113) & (mc2434_32113)) | ((mc2434_32113) & 0ULL)); (void)mc2434_32113; } }
      { volatile unsigned long long mt2435_53125=C.cookie;mt2435_53125^=306ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2435_53125); }
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma2436_56259=3863916281ULL; volatile unsigned long long mb2437_19541=2192266321ULL; volatile unsigned long long mc2438_12945=ma2436_56259^mb2437_19541; mc2438_12945=(((mc2438_12945) & (mc2438_12945)) | ((mc2438_12945) & 0ULL)); (void)mc2438_12945; } } C.state = 316821;
      break;
    case 774710:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma2439_58160=3949302473ULL; volatile unsigned long long mb2440_6453=3625792001ULL; volatile unsigned long long mc2441_57792=ma2439_58160^mb2440_6453; if((((mc2441_57792 * 2ULL) & 1ULL) != 0ULL)) mc2441_57792^=0xDEADULL; (void)mc2441_57792; } }
      { volatile unsigned long long mt2442_12357=C.cookie;mt2442_12357^=307ULL;C.cookie=vm_main_int___a100e2bc_mix(mt2442_12357); }
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 470319; } else { { volatile unsigned long long ma2443_27396=2543651971ULL; volatile unsigned long long mb2444_43269=2881518877ULL; volatile unsigned long long mc2445_62374=ma2443_27396^mb2444_43269; if(((mc2445_62374 ^ mc2445_62374) != 0ULL)) mc2445_62374^=0xDEADULL; (void)mc2445_62374; } C.state = 470319; }
      break;
    case 65716:
      
      
      { volatile unsigned long long mh2446_49105=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2446_49105; }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^308ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 931051; } else { { volatile unsigned long long ma2449_7421=3417327159ULL; volatile unsigned long long mb2450_45559=804466205ULL; volatile unsigned long long mc2451_58275=ma2449_7421^mb2450_45559; if(((mc2451_58275 ^ mc2451_58275) != 0ULL)) mc2451_58275^=0xDEADULL; (void)mc2451_58275; } C.state = 931051; }
      break;
    case 952311:
      
      
      if ((((C.cookie * 2ULL) & 1ULL) != 0ULL)) { { volatile unsigned long long ma2452_450=3572540781ULL; volatile unsigned long long mb2453_16657=158563151ULL; volatile unsigned long long mc2454_57242=ma2452_450^mb2453_16657; if(((mc2454_57242 ^ mc2454_57242) != 0ULL)) mc2454_57242^=0xDEADULL; (void)mc2454_57242; } }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^309ULL);
      if (((C.cookie ^ C.cookie) != 0ULL)) { { volatile unsigned long long ma2456_37254=1127778427ULL; volatile unsigned long long mb2457_60336=4105223577ULL; volatile unsigned long long mc2458_52986=ma2456_37254^mb2457_60336; for(volatile int _i=0;_i<1;++_i) mc2458_52986=vm_main_int___a100e2bc_mix(mc2458_52986+_i); (void)mc2458_52986; } } C.state = 931051;
      break;
    case 931051:
      
      
      { volatile unsigned long long ma2459_1547=2789440197ULL; volatile unsigned long long mb2460_58943=3820735015ULL; volatile unsigned long long mc2461_43934=ma2459_1547^mb2460_58943; mc2461_43934=((mc2461_43934) + 0ULL); (void)mc2461_43934; }
      { volatile unsigned long long mh2462_25072=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2462_25072; }
      C.cookie=vm_main_int___a100e2bc_mix((C.cookie|0ULL)^310ULL);
      if ((((C.cookie ^ C.cookie) + 1ULL) != 0ULL)) { C.state = 114126; } else { { volatile unsigned long long ma2464_17802=22761815ULL; volatile unsigned long long mb2465_65377=447353939ULL; volatile unsigned long long mc2466_9742=ma2464_17802^mb2465_65377; if((((mc2466_9742 + 0ULL) ^ (mc2466_9742 + 0ULL)) == 1ULL)) mc2466_9742^=0xDEADULL; (void)mc2466_9742; } C.state = 114126; }
      break;
    case 411956:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma2467_36640=1150841231ULL; volatile unsigned long long mb2468_48200=3132042827ULL; volatile unsigned long long mc2469_4533=ma2467_36640^mb2468_48200; mc2469_4533=((mc2469_4533) + 0ULL); (void)mc2469_4533; } }
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^311ULL);
      if ((((C.cookie | 0ULL) & 0ULL) != 0ULL)) { { volatile unsigned long long ma2471_23757=4244358197ULL; volatile unsigned long long mb2472_33020=1665740073ULL; volatile unsigned long long mc2473_44014=ma2471_23757^mb2472_33020; mc2473_44014=((mc2473_44014) ^ 0ULL); (void)mc2473_44014; } } C.state = 114126;
      break;
    case 470319:
      vm_main_int___a100e2bc_H_fetch(&C);
      break;
    case 876360:
      
      
      { volatile unsigned long long mh2474_35536=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2474_35536; }
      { unsigned long long mt2475_34074=C.cookie^(unsigned long long)C.steps;C.cookie=vm_main_int___a100e2bc_mix((((mt2475_34074) & (mt2475_34074)) | ((mt2475_34074) & 0ULL))); }
      C.state = 93225;
      break;
    case 93225:
      switch (C.op) {
      case 0: break;
      case 1: { unsigned i=rd_u32(); spush((u64)vm_main_int___a100e2bc_mod_data::iconst[i]); break; }
      case 2: { unsigned i=rd_u32(); unsigned fw=(C.pc<C.len)?code[C.pc++]:8; if(fw!=4) fw=8; u64 bits=0;
        if(fw==4){ float f=(float)vm_main_int___a100e2bc_mod_data::fconst[i]; std::memcpy(&bits,&f,4); }
        else { double d=vm_main_int___a100e2bc_mod_data::fconst[i]; std::memcpy(&bits,&d,8); }
        spush(bits); break; }
      case 3: { 
        unsigned i=rd_u32();
        spush((u64)(uintptr_t)vm_main_int___a100e2bc_str_get(i));
        break; }
      case 4: { unsigned i=rd_u16(); spush(reg_get((int)i)); break; }
      case 5: { unsigned i=rd_u16(); reg_set((int)i, spop()); break; }
      case 6: case 7: { rd_u16(); break; }
      case 8: { u64 b=spop(),a=spop(); spush(vm_main_int___a100e2bc_alu_mix(0,a,b,C.dyn_salt)); break; }
      case 9: { u64 b=spop(),a=spop(); spush(vm_main_int___a100e2bc_alu_mix(1,a,b,C.dyn_salt)); break; }
      case 10:{ u64 b=spop(),a=spop(); spush(a*b); break; }
      case 11:{ long long b=(long long)spop(),a=(long long)spop(); spush(b?(u64)(a/b):0); break; }
      case 12:{ long long b=(long long)spop(),a=(long long)spop(); spush(b?(u64)(a%b):0); break; }
      case 13: case 14: case 15: case 16: {
        unsigned fw = (C.pc < C.len) ? code[C.pc++] : 8; if(fw!=4) fw=8;
        u64 bb=spop(),aa=spop(); u64 out=0;
        if(fw==4){ float a,b,r; std::memcpy(&a,&aa,4); std::memcpy(&b,&bb,4);
          if(C.op==13)r=a+b; else if(C.op==14)r=a-b; else if(C.op==15)r=a*b; else r=b!=0.f?a/b:0.f;
          std::memcpy(&out,&r,4); }
        else { double a,b,r; std::memcpy(&a,&aa,8); std::memcpy(&b,&bb,8);
          if(C.op==13)r=a+b; else if(C.op==14)r=a-b; else if(C.op==15)r=a*b; else r=b!=0?a/b:0;
          std::memcpy(&out,&r,8); }
        spush(out); break; }
      case 17: { u64 x=spop(); spush(0ull-x); break; }
      case 18: { unsigned fw=(C.pc<C.len)?code[C.pc++]:8; if(fw!=4) fw=8;
        u64 aa=spop(); u64 out=0;
        if(fw==4){ float a; std::memcpy(&a,&aa,4); a=-a; std::memcpy(&out,&a,4); }
        else { double a; std::memcpy(&a,&aa,8); a=-a; std::memcpy(&out,&a,8); }
        spush(out); break; }
      case 19: { u64 x=spop(); spush(x?0:1); break; }
      case 20: { u64 b=spop(),a=spop(); spush((long long)a==(long long)b); break; }
      case 21: { u64 b=spop(),a=spop(); spush((long long)a!=(long long)b); break; }
      case 22: { u64 b=spop(),a=spop(); spush((long long)a<(long long)b); break; }
      case 23: { u64 b=spop(),a=spop(); spush((long long)a<=(long long)b); break; }
      case 24: { u64 b=spop(),a=spop(); spush((long long)a>(long long)b); break; }
      case 25: { u64 b=spop(),a=spop(); spush((long long)a>=(long long)b); break; }
      case 26: { int off=rd_i32(); C.pc=(unsigned)((int)C.pc+off); break; }
      case 27: { int off=rd_i32(); u64 c=spop(); bool fz=(c==0)||(c==0x8000000000000000ULL)||(c==0x80000000ULL); if(fz) C.pc=(unsigned)((int)C.pc+off); break; }
      case 28: { int off=rd_i32(); u64 c=spop(); bool fz=(c==0)||(c==0x8000000000000000ULL)||(c==0x80000000ULL); if(!fz) C.pc=(unsigned)((int)C.pc+off); break; }
      case 29: { C.retv=(long long)spop(); C.state=579700; C.done=1; break; }
      case 30: { C.retv=0; C.state=579700; C.done=1; break; }
      case 31: { (void)spop(); break; }
      case 32: {
        unsigned hid=rd_u16();
        vm_main_int___a100e2bc_seg_ensure(&C, C.pc);
        unsigned argc=code[C.pc++]; long long args[32]; if(argc>32){ C.retv=0; C.done=1; break; }
        long long ref_tmp[32]; int ref_idx[32]; int nref=0;
        for(unsigned i=0;i<argc;++i) {
          long long v=(long long)spop();
          if (((u64)v & 0xFFFFFFFF00000000ULL) == 0x5265663000000000ULL) {
            int ri = (int)((u64)v & 0xFFFFFFFFULL);
            ref_tmp[nref] = (long long)reg_get(ri);
            ref_idx[nref] = ri;
            args[argc-1-i] = (long long)(uintptr_t)&ref_tmp[nref];
            ++nref;
          } else {
            args[argc-1-i] = v;
          }
        }
        ++C.call_depth;
        long long hv = C.host(hid,args,argc);
        --C.call_depth;
        for(int r=0;r<nref;++r) reg_set(ref_idx[r], (u64)ref_tmp[r]);
        C.hist = vm_main_int___a100e2bc_mix(C.hist ^ (u64)hid ^ (u64)C.call_depth);
        spush((u64)hv); break; }
      case 33: { unsigned n=rd_u16(); spush((u64)heap_alloc(n)); break; }
      case 34: { unsigned fi=rd_u16(); long long obj=(long long)spop(); spush(heap_get((int)obj, fi)); break; }
      case 35: { unsigned fi=rd_u16(); long long val=(long long)spop(); long long obj=(long long)spop(); heap_set((int)obj, fi, val); break; }
      case 36: { unsigned i=rd_u16(); spush((u64)0x5265663000000000ULL | (u64)i); break; }
      case 37: { 
        unsigned encsz=code[C.pc++]; bool zext=(encsz&0x80u)!=0; unsigned sz=encsz&0x7Fu; if(!sz)sz=8; if(sz>8)sz=8;
        long long p=(long long)spop();
        if (((u64)p & 0xFFFFFFFF00000000ULL) == 0x5265663000000000ULL) {
          int i=(int)((u64)p & 0xFFFFFFFFULL); spush(reg_get(i));
        } else if (p>0 && p<256) {
          spush(heap_get((int)p, 0));
        } else if (p) {
          long long v=0; std::memcpy(&v, (const void*)(uintptr_t)p, sz);
          /* Normalize narrow loads with the source signedness. */
          if(sz==1){ if(zext){ uint8_t t; std::memcpy(&t,(const void*)(uintptr_t)p,1); v=(long long)t; } else { int8_t t; std::memcpy(&t,(const void*)(uintptr_t)p,1); v=(long long)t; } }
          else if(sz==2){ if(zext){ uint16_t t; std::memcpy(&t,(const void*)(uintptr_t)p,2); v=(long long)t; } else { int16_t t; std::memcpy(&t,(const void*)(uintptr_t)p,2); v=(long long)t; } }
          else if(sz==4){ if(zext){ uint32_t t; std::memcpy(&t,(const void*)(uintptr_t)p,4); v=(long long)t; } else { int32_t t; std::memcpy(&t,(const void*)(uintptr_t)p,4); v=(long long)t; } }
          spush((u64)v);
        } else spush(0);
        break; }
      case 38: { 
        unsigned encsz=code[C.pc++]; bool zext=(encsz&0x80u)!=0; unsigned sz=encsz&0x7Fu; if(!sz)sz=8; if(sz>8)sz=8;
        long long val=(long long)spop(); long long p=(long long)spop();
        if(sz==1){ if(zext) val=(long long)(uint8_t)val; else val=(long long)(int8_t)val; }
        else if(sz==2){ if(zext) val=(long long)(uint16_t)val; else val=(long long)(int16_t)val; }
        else if(sz==4){ if(zext) val=(long long)(uint32_t)val; else val=(long long)(int32_t)val; }
        if (((u64)p & 0xFFFFFFFF00000000ULL) == 0x5265663000000000ULL) {
          int i=(int)((u64)p & 0xFFFFFFFFULL); reg_set(i,(u64)val);
        } else if (p>0 && p<256) {
          heap_set((int)p, 0, val);
        } else if (p) {
          std::memcpy((void*)(uintptr_t)p, &val, sz);
        }
        spush((u64)val);
        break; }
      case 39: { u64 b=spop(),a=spop(); spush(a&b); break; }
      case 40: { u64 b=spop(),a=spop(); spush(a|b); break; }
      case 41: { u64 b=spop(),a=spop(); spush(vm_main_int___a100e2bc_alu_mix(2,a,b,C.dyn_salt)); break; }
      case 42: { u64 b=spop(),a=spop(); spush(a<<b); break; }
      case 43: { long long bb=(long long)spop(), aa=(long long)spop(); unsigned sh=(unsigned)(bb&63); spush((u64)(aa>>sh)); break; }
      case 44: { u64 a=spop(); spush(~a); break; }
      case 45: { 
        int off=rd_i32(); unsigned hpc=(unsigned)((int)C.pc+off);
        if (try_sp < 32) { try_stk[try_sp].handler=hpc; try_stk[try_sp].sp_mark=sp; ++try_sp; }
        break; }
      case 46: { 
        if (try_sp > 0) --try_sp; break; }
      case 47: { 
        unsigned ttag=code[C.pc++];
        exc_val=(long long)spop();
        if (ttag != 0xFEu) exc_type=(int)ttag;
        if (try_sp > 0) {
          --try_sp;
          sp = try_stk[try_sp].sp_mark; if (sp < 0) sp = 0;
          C.pc = try_stk[try_sp].handler;
          spush((u64)exc_val);
          C.state = 470319;
        } else {
          C.retv = exc_val; C.done=1; C.state=579700; C.uncaught=1;
        }
        break; }
      case 48: { 
        unsigned exp=code[C.pc++];
        int foff=rd_i32();
        /* 0xFF = catch(...) matches any */
        if (exp != 0xFFu && (unsigned)exc_type != exp) {
          C.pc = (unsigned)((int)C.pc + foff);
          /* leave exception value on stack for next handler */
        }
        break; }
      case 49: { 
        unsigned aid=rd_u16(); unsigned argc=0; vm_main_int___a100e2bc_seg_ensure(&C, C.pc);
        if (C.pc < C.len) argc=code[C.pc++]; if(argc>32){ C.retv=0; C.done=1; break; }
        long long args[32]; long long ref_tmp[32]; int ref_idx[32]; int nref=0;
        for(unsigned i=0;i<argc;++i) {
          long long v=(long long)spop();
          if (((u64)v & 0xFFFFFFFF00000000ULL) == 0x5265663000000000ULL) {
            int ri = (int)((u64)v & 0xFFFFFFFFULL);
            ref_tmp[nref] = (long long)reg_get(ri);
            ref_idx[nref] = ri;
            args[argc-1-i] = (long long)(uintptr_t)&ref_tmp[nref];
            ++nref;
          } else {
            args[argc-1-i] = v;
          }
        }
        long long hv = C.host(aid,args,argc);
        for(int r=0;r<nref;++r) reg_set(ref_idx[r], (u64)ref_tmp[r]);
        spush((u64)hv); break; }
      default: C.retv=0; C.done=1; C.state=579700; break;
      }
      
      if (!C.done && C.state == 93225) C.state = 753077;
      break;
    case 753077:
      
      C.running_sum = vm_main_int___a100e2bc_mix(C.running_sum ^ C.op ^ C.pc);
      C.hist = vm_main_int___a100e2bc_mix(C.hist ^ C.running_sum ^ C.dyn_salt);
      (void)C.win_seg;
      
      { volatile unsigned long long ma2476_47627=2989202501ULL; volatile unsigned long long mb2477_61373=1405318021ULL; volatile unsigned long long mc2478_49194=ma2476_47627^mb2477_61373; mc2478_49194=((mc2478_49194) ^ 0ULL); (void)mc2478_49194; }
      if (vm_main_int___a100e2bc_opq_ctx_t(C.hist, C.cookie) && ((C.cookie & 3ULL) == 1ULL)) C.state = 910728;
      else C.state = 125221;
      break;
    case 125221:
      
      
      C.cookie=vm_main_int___a100e2bc_mix(C.cookie^(unsigned long long)C.steps);
      { volatile unsigned long long mh2480_13436=vm_main_int___a100e2bc_mix(C.cookie^C.hist); (void)mh2480_13436; }
      {
        int nexts[4] = {470319,201315,316821,470319};
        unsigned long long idx = (C.cookie ^ C.op ^ C.hist) & 3ULL;
        C.state = nexts[idx];
        if (C.state == 201315) C.state = 470319;
        if (vm_main_int___a100e2bc_opq_ctx_f(C.hist, C.cookie)) C.state = 413650;
      }
      break;
    case 316821:
      
      C.cookie ^= C.running_sum;
      C.hist = vm_main_int___a100e2bc_mix(C.hist ^ C.cookie);
      C.state = vm_main_int___a100e2bc_opq_ctx_t(C.hist, C.cookie) ? 470319 : 114126;
      break;
    case 579700:
      C.done = 1; break;
    case 553214:
      C.state = 470319; break;
    default:
      
      
      if ((((C.cookie + 0ULL) ^ (C.cookie + 0ULL)) == 1ULL)) { { volatile unsigned long long ma2481_11253=1350350513ULL; volatile unsigned long long mb2482_11374=3190389373ULL; volatile unsigned long long mc2483_63505=ma2481_11253^mb2482_11374; mc2483_63505=((mc2483_63505) | 0ULL); (void)mc2483_63505; } }
      C.state = 851465;
      break;
    }
  }
      } 
      break;
    default:
      
      L2_vsp_shadow ^= 0x12BADULL;
      break;
    } 
    
    vm_main_int___a100e2bc_l2_vr_scramble(L2_VR, 8, L2_key ^ (u64)L2_VIP ^ 0xA5A5ULL);
    (void)L2_vsp_shadow;
  } 
  C.cookie ^= lane.load(std::memory_order_relaxed);
  for (int i=0;i<nlocals && i<256;++i) locals_plain[i]=(long long)reg_get(i);
  for (unsigned i=0;i<len;++i) code[i]=0;
  (void)vm_main_int___a100e2bc_mod_junk::blob[(size_t)(C.cookie & 1387u)];
  if (C.retv) __vm_alloc_detach((void*)(uintptr_t)C.retv);
  __vm_alloc_cleanup(__vm_alloc_mark);
  if (C.uncaught) {
    
    switch (exc_type) {
    case 10: throw (bool)(C.retv!=0);
    case 11: throw (signed char)C.retv;
    case 12: throw (unsigned char)C.retv;
    case 13: throw (short)C.retv;
    case 14: throw (unsigned short)C.retv;
    case 15: throw (int)C.retv;
    case 16: throw (unsigned)C.retv;
    case 17: throw (long long)C.retv;
    case 18: throw (unsigned long long)C.retv;
    case 20: { float f=0; std::memcpy(&f,&C.retv,4); throw f; }
    case 21: { double d=0; std::memcpy(&d,&C.retv,8); throw d; }
    case 30: throw (void*)(uintptr_t)C.retv;
    default: throw (int)C.retv;
    }
  }
  return C.retv;
}

static long long vm_main_int___a100e2bc_host(unsigned id, long long* args, unsigned argc) {
 (void)argc;
 switch(id){
 case 0: {
  return __vm_native_0(args, argc);
 }
 case 1: {
  return __vm_native_1(args, argc);
 }
 case 2: {
  if(argc>=1 && args[0]) std::cout << (const char*)(uintptr_t)args[0]; return 0;
 }
 case 3: {
  return __vm_native_2(args, argc);
 }
 case 4: {
  
  auto S=[&](long long v)->const char*{
    return v ? (const char*)(uintptr_t)v : "";
  };
  auto W=[&](long long v)->const wchar_t*{
    const char* nstr=S(v);
    static thread_local wchar_t wbuf[1024];
    if(!nstr){ wbuf[0]=0; return wbuf; }
    MultiByteToWideChar(CP_UTF8,0,nstr,-1,wbuf,1024);
    return wbuf;
  };
  (void)S;(void)W;
  return (long long)(uintptr_t)LoadLibraryA(argc>0?S(args[0]):nullptr);
 }
 case 5: {
  return __vm_native_3(args, argc);
 }
 case 6: {
  return __vm_native_4(args, argc);
 }
 case 7: {
  return __vm_native_5(args, argc);
 }
 case 8: {
  return __vm_native_6(args, argc);
 }
 case 9: {
  
  auto S=[&](long long v)->const char*{
    return v ? (const char*)(uintptr_t)v : "";
  };
  auto W=[&](long long v)->const wchar_t*{
    const char* nstr=S(v);
    static thread_local wchar_t wbuf[1024];
    if(!nstr){ wbuf[0]=0; return wbuf; }
    MultiByteToWideChar(CP_UTF8,0,nstr,-1,wbuf,1024);
    return wbuf;
  };
  (void)S;(void)W;
  static HMODULE mods[8]={};
  if(!mods[0]){
    mods[0]=::LoadLibraryA([]{ static const unsigned char _e[]={92,75,110,104,94,78,97,58,205,220,131}; return __vm_xstr(_e,10,55); }());
    mods[1]=::LoadLibraryA([]{ static const unsigned char _e[]={36,59,31,18,110,118,26,10,233,178,137,152,131}; return __vm_xstr(_e,12,107); }());
    mods[2]=::LoadLibraryA([]{ static const unsigned char _e[]={245,231,217,146,228,233,144,137,118,11}; return __vm_xstr(_e,9,9); }());
    mods[3]=::LoadLibraryA([]{ static const unsigned char _e[]={12,24,57,63,89,81,56,40,203,144,171,186,161}; return __vm_xstr(_e,12,73); }());
    mods[4]=::LoadLibraryA([]{ static const unsigned char _e[]={85,95,97,121,14,64,114,127,202,211,224,157}; return __vm_xstr(_e,11,135); }());
    mods[5]=::LoadLibraryA([]{ static const unsigned char _e[]={49,35,25,94,40,37,92,69,186,199}; return __vm_xstr(_e,9,197); }());
    mods[6]=::LoadLibraryA([]{ static const unsigned char _e[]={204,217,171,215,204,220,243,168,95,78,17}; return __vm_xstr(_e,10,165); }());
    mods[7]=::LoadLibraryA([]{ static const unsigned char _e[]={7,12,47,54,65,18,107,114,141,240}; return __vm_xstr(_e,9,242); }());
  }
  FARPROC p=nullptr; for(int mi=0;mi<8&&!p;++mi) if(mods[mi]) p=::GetProcAddress(mods[mi], []{ static const unsigned char _e[]={0,37,1,16,78,122,66,67,175,173,149,253}; return __vm_xstr(_e,11,231); }());
  if(!p) return -1;
  long long a0=argc>0?args[0]:0,a1=argc>1?args[1]:0,a2=argc>2?args[2]:0,a3=argc>3?args[3]:0;
  long long a4=argc>4?args[4]:0,a5=argc>5?args[5]:0,a6=argc>6?args[6]:0,a7=argc>7?args[7]:0;
  long long a8=argc>8?args[8]:0,a9=argc>9?args[9]:0,a10=argc>10?args[10]:0,a11=argc>11?args[11]:0;
  #if defined(_MSC_VER) && defined(_M_IX86)
  #define VM_CC __stdcall
#else
  #define VM_CC
#endif
  using F0=long long(VM_CC *)(); using F1=long long(VM_CC *)(long long); using F2=long long(VM_CC *)(long long,long long);
  using F3=long long(VM_CC *)(long long,long long,long long); using F4=long long(VM_CC *)(long long,long long,long long,long long);
  using F5=long long(VM_CC *)(long long,long long,long long,long long,long long);
  using F6=long long(VM_CC *)(long long,long long,long long,long long,long long,long long);
  using F7=long long(VM_CC *)(long long,long long,long long,long long,long long,long long,long long);
  using F8=long long(VM_CC *)(long long,long long,long long,long long,long long,long long,long long,long long);
  using F9=long long(VM_CC *)(long long,long long,long long,long long,long long,long long,long long,long long,long long);
  using F10=long long(VM_CC *)(long long,long long,long long,long long,long long,long long,long long,long long,long long,long long);
  using F11=long long(VM_CC *)(long long,long long,long long,long long,long long,long long,long long,long long,long long,long long,long long);
  using F12=long long(VM_CC *)(long long,long long,long long,long long,long long,long long,long long,long long,long long,long long,long long,long long);
  switch(argc){
  case 0: return ((F0)p)();
  case 1: return ((F1)p)(a0);
  case 2: return ((F2)p)(a0,a1);
  case 3: return ((F3)p)(a0,a1,a2);
  case 4: return ((F4)p)(a0,a1,a2,a3);
  case 5: return ((F5)p)(a0,a1,a2,a3,a4);
  case 6: return ((F6)p)(a0,a1,a2,a3,a4,a5);
  case 7: return ((F7)p)(a0,a1,a2,a3,a4,a5,a6);
  case 8: return ((F8)p)(a0,a1,a2,a3,a4,a5,a6,a7);
  case 9: return ((F9)p)(a0,a1,a2,a3,a4,a5,a6,a7,a8);
  case 10: return ((F10)p)(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9);
  case 11: return ((F11)p)(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);
  default: return ((F12)p)(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11);
  }
 }
 case 10: {
  return __vm_native_7(args, argc);
 }
 case 11: {
  return __vm_native_8(args, argc);
 }
 case 12: {
  return __vm_native_9(args, argc);
 }
 case 13: {
  return __vm_native_10(args, argc);
 }
 default: return 0; }
}

int main() {
  long long locals[4] = {};
  return (int)vm_main_int___a100e2bc_run(locals, 4);
}

long long __vm_native_0(long long* args, unsigned argc) {
  static const unsigned char __vm_sl0[] = {8,37,23,28,113,122,119,82,132,164,133,148,231,238,192,199,76};
  const char* __vm_hp = new const char[17]();
  { const char* __vm_src = __vm_xstr(__vm_sl0,16,108);
    if (__vm_src) { size_t __n = std::strlen(__vm_src) + 1; if (__n > (size_t)(17)) __n = (size_t)(17); std::memcpy(const_cast<void*>(static_cast<const void*>(__vm_hp)), __vm_src, __n); } }
  __vm_alloc_push(const_cast<void*>(static_cast<const void*>(__vm_hp)), [](void* __p){ delete[] (const char*)__p; });
  return (long long)(uintptr_t)__vm_hp;

}

long long __vm_native_1(long long* args, unsigned argc) {
  auto* __vm_hp = new std::string();
  __vm_alloc_push(__vm_hp, [](void* __p){ delete (std::string*)__p; });
  return (long long)(uintptr_t)__vm_hp;

}

long long __vm_native_2(long long* args, unsigned argc) {
  using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
  std::string& input = *reinterpret_cast<std::string*>(static_cast<uintptr_t>(args[0]));
  (void)(std::getline(std::cin, input));
  return 0;

}

long long __vm_native_3(long long* args, unsigned argc) {
  static const unsigned char __vm_sl1[] = {54,0,59,47,81,65,54,115,151,201,182,164,221,201,190,250,19,52,48,0,22,59,98,155,132,211,202};
  using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
  auto user32 = reinterpret_cast<HMODULE>(static_cast<uintptr_t>(args[0]));
  (void)(std::cerr << __vm_xstr(__vm_sl1,26,62));
  return 0;

}

long long __vm_native_4(long long* args, unsigned argc) {
  using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
  using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
  return 0;

}

long long __vm_native_5(long long* args, unsigned argc) {
  static const unsigned char __vm_sl2[] = {27,34,7,22,115,100,85,99,177,183,189,237};
  using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
  auto user32 = reinterpret_cast<HMODULE>(static_cast<uintptr_t>(args[0]));
  return (long long)(uintptr_t)(reinterpret_cast<MessageBoxA_t>(
            GetProcAddress(user32, __vm_xstr(__vm_sl2,11,247))
        ));

}

long long __vm_native_6(long long* args, unsigned argc) {
  static const unsigned char __vm_sl3[] = {159,169,146,134,248,232,159,218,62,96,1,7,102,107,91,80,172,216,166,255,254,207,206,57,36,50,12,106,68,62,39};
  using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
  (void)(std::cerr << __vm_xstr(__vm_sl3,30,131));
  return 0;

}

long long __vm_native_7(long long* args, unsigned argc) {
  using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
  std::string& input = *reinterpret_cast<std::string*>(static_cast<uintptr_t>(args[0]));
  auto password = reinterpret_cast<const char*>(static_cast<uintptr_t>(args[1]));
  return (long long)(input.length() == std::strlen(password));

}

long long __vm_native_8(long long* args, unsigned argc) {
  using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
  std::string& input = *reinterpret_cast<std::string*>(static_cast<uintptr_t>(args[0]));
  auto password = reinterpret_cast<const char*>(static_cast<uintptr_t>(args[1]));
  return (long long)(std::memcmp(input.data(), password, std::strlen(password)));

}

long long __vm_native_9(long long* args, unsigned argc) {
  static const unsigned char __vm_sl4[] = {149,181,148,133,246,255,209,214,109,53,28,94,106,119,89,72,176,135,131,167,145};
  static const unsigned char __vm_sl5[] = {181,147,182,161,207,198,129};
  using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
  int (*MessageBoxA_Dynamic) (void *, const char *, const char *, unsigned int) = reinterpret_cast<int (*) (void *, const char *, const char *, unsigned int)>(static_cast<uintptr_t>(args[0]));
  return (long long)(MessageBoxA_Dynamic(
            nullptr,
            __vm_xstr(__vm_sl4,20,249),
            __vm_xstr(__vm_sl5,6,245),
            MB_OK | MB_ICONINFORMATION
        ));

}

long long __vm_native_10(long long* args, unsigned argc) {
  static const unsigned char __vm_sl6[] = {254,222,255,238,157,148,186,189,6,94,119,53,11,29,35,62,204,253,249,142,142,234,216};
  static const unsigned char __vm_sl7[] = {195,229,192,215,185,176,247};
  using MessageBoxA_t = int (WINAPI*)(
        HWND,
        LPCSTR,
        LPCSTR,
        UINT
    );
  int (*MessageBoxA_Dynamic) (void *, const char *, const char *, unsigned int) = reinterpret_cast<int (*) (void *, const char *, const char *, unsigned int)>(static_cast<uintptr_t>(args[0]));
  return (long long)(MessageBoxA_Dynamic(
            nullptr,
            __vm_xstr(__vm_sl6,22,236),
            __vm_xstr(__vm_sl7,6,131),
            MB_OK | MB_ICONERROR
        ));

}

