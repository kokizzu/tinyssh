#ifndef crypto_kem_sntrup761x25519_H
#define crypto_kem_sntrup761x25519_H

#define crypto_kem_sntrup761x25519_tinyssh_SECRETKEYBYTES 1795
#define crypto_kem_sntrup761x25519_tinyssh_PUBLICKEYBYTES 1190
#define crypto_kem_sntrup761x25519_tinyssh_CIPHERTEXTBYTES 1071
#define crypto_kem_sntrup761x25519_tinyssh_BYTES 64
extern int crypto_kem_sntrup761x25519_tinyssh_keypair(unsigned char *,
                                                      unsigned char *);
extern int crypto_kem_sntrup761x25519_tinyssh_enc(unsigned char *,
                                                  unsigned char *,
                                                  const unsigned char *);
extern int crypto_kem_sntrup761x25519_tinyssh_dec(unsigned char *,
                                                  const unsigned char *,
                                                  const unsigned char *);

#define crypto_kem_sntrup761x25519_keypair                                     \
    crypto_kem_sntrup761x25519_tinyssh_keypair
#define crypto_kem_sntrup761x25519_enc crypto_kem_sntrup761x25519_tinyssh_enc
#define crypto_kem_sntrup761x25519_dec crypto_kem_sntrup761x25519_tinyssh_dec
#define crypto_kem_sntrup761x25519_SECRETKEYBYTES                              \
    crypto_kem_sntrup761x25519_tinyssh_SECRETKEYBYTES
#define crypto_kem_sntrup761x25519_PUBLICKEYBYTES                              \
    crypto_kem_sntrup761x25519_tinyssh_PUBLICKEYBYTES
#define crypto_kem_sntrup761x25519_CIPHERTEXTBYTES                             \
    crypto_kem_sntrup761x25519_tinyssh_CIPHERTEXTBYTES
#define crypto_kem_sntrup761x25519_BYTES                                       \
    crypto_kem_sntrup761x25519_tinyssh_BYTES
#define crypto_kem_sntrup761x25519_IMPLEMENTATION "tinyssh"
#define crypto_kem_sntrup761x25519_VERSION "-"

#endif
