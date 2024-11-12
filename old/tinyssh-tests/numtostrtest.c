/*
20140201
Jan Mojzis
Public domain.
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "fail.h"
#include "numtostr.h"

static long long int128max(void) {

    long long x = 9223372036854775807LL;

    x <<= 32;
    x <<= 32;
    x += 9223372036854775807LL;
    x += 9223372036854775807LL;
    x += 1;

    return x;
}

static void test_bufferoverflow(void) {

    char buf[NUMTOSTR_LEN + 16];
    long long i, j;
    char ch[2] = {0x00, (char)0xff };
    long long  llmaxnum;
    long long llminnum;
    long long numlen = sizeof(long long);

    if (numlen == 16) {
        llmaxnum = int128max();
        llminnum = -llmaxnum - 1LL;
    }
    else if (numlen == 8) {
        llmaxnum = 9223372036854775807LL;
        llminnum = -llmaxnum - 1LL;
    }
    else {
        fail("unsupported size for 'num'");
    }

    if ((NUMTOSTR_LEN) < sizeof("-170141183460469231731687303715884105728")) fail("NUMTOSTR_LEN too small");

    for (j = 0; j < 2; ++j) {
        for (i = 0; i < sizeof buf; ++i) buf[i] = ch[j];
        numtostr(buf + 8, llminnum);
        for (i = 0; i < 8; ++i) if (buf[i] != ch[j]) fail("numtostr() writes before output");
        for (i = 0; i < 8; ++i) if (buf[i + NUMTOSTR_LEN + 8] != ch[j]) fail("numtostr() writes after output");
        for (i = 0; i < sizeof buf; ++i) buf[i] = ch[j];
        numtostr(buf + 8, llmaxnum);
        for (i = 0; i < 8; ++i) if (buf[i] != ch[j]) fail("numtostr() writes before output");
        for (i = 0; i < 8; ++i) if (buf[i + NUMTOSTR_LEN + 8] != ch[j]) fail("numtostr() writes after output");
    }
}

static void test_minmax(void) {

    const char *llmax;
    const char *llmin;
    long long llmaxnum;
    long long llminnum;
    char *x;
    long long numlen = sizeof(long long);

    if (numlen == 16) {
        llmax   = "170141183460469231731687303715884105727";
        llmin   = "-170141183460469231731687303715884105728";
        llmaxnum = int128max();
        llminnum = -llmaxnum - 1LL;
    }
    else if (numlen == 8) {
        llmax   = "9223372036854775807";
        llmin   = "-9223372036854775808";
        llmaxnum = 9223372036854775807LL;
        llminnum = -llmaxnum - 1LL;
    }
    else {
        fail("unsupported size for 'num'");
    }

    x = numtostr(0, llmaxnum);
    if (strcmp(x, llmax)) fail("numtostr() failure");

    x = numtostr(0, llminnum);
    if (strcmp(x, llmin)) fail("numtostr() failure");
}


struct vectors {
    long long num;
    const char *strnum;
} testvectors[] = {
    { -100, "-100" },
    { -99, "-99" },
    { -98, "-98" },
    { -97, "-97" },
    { -96, "-96" },
    { -95, "-95" },
    { -94, "-94" },
    { -93, "-93" },
    { -92, "-92" },
    { -91, "-91" },
    { -90, "-90" },
    { -89, "-89" },
    { -88, "-88" },
    { -87, "-87" },
    { -86, "-86" },
    { -85, "-85" },
    { -84, "-84" },
    { -83, "-83" },
    { -82, "-82" },
    { -81, "-81" },
    { -80, "-80" },
    { -79, "-79" },
    { -78, "-78" },
    { -77, "-77" },
    { -76, "-76" },
    { -75, "-75" },
    { -74, "-74" },
    { -73, "-73" },
    { -72, "-72" },
    { -71, "-71" },
    { -70, "-70" },
    { -69, "-69" },
    { -68, "-68" },
    { -67, "-67" },
    { -66, "-66" },
    { -65, "-65" },
    { -64, "-64" },
    { -63, "-63" },
    { -62, "-62" },
    { -61, "-61" },
    { -60, "-60" },
    { -59, "-59" },
    { -58, "-58" },
    { -57, "-57" },
    { -56, "-56" },
    { -55, "-55" },
    { -54, "-54" },
    { -53, "-53" },
    { -52, "-52" },
    { -51, "-51" },
    { -50, "-50" },
    { -49, "-49" },
    { -48, "-48" },
    { -47, "-47" },
    { -46, "-46" },
    { -45, "-45" },
    { -44, "-44" },
    { -43, "-43" },
    { -42, "-42" },
    { -41, "-41" },
    { -40, "-40" },
    { -39, "-39" },
    { -38, "-38" },
    { -37, "-37" },
    { -36, "-36" },
    { -35, "-35" },
    { -34, "-34" },
    { -33, "-33" },
    { -32, "-32" },
    { -31, "-31" },
    { -30, "-30" },
    { -29, "-29" },
    { -28, "-28" },
    { -27, "-27" },
    { -26, "-26" },
    { -25, "-25" },
    { -24, "-24" },
    { -23, "-23" },
    { -22, "-22" },
    { -21, "-21" },
    { -20, "-20" },
    { -19, "-19" },
    { -18, "-18" },
    { -17, "-17" },
    { -16, "-16" },
    { -15, "-15" },
    { -14, "-14" },
    { -13, "-13" },
    { -12, "-12" },
    { -11, "-11" },
    { -10, "-10" },
    { -9, "-9" },
    { -8, "-8" },
    { -7, "-7" },
    { -6, "-6" },
    { -5, "-5" },
    { -4, "-4" },
    { -3, "-3" },
    { -2, "-2" },
    { -1, "-1" },
    { 0, "0" },
    { 1, "1" },
    { 2, "2" },
    { 3, "3" },
    { 4, "4" },
    { 5, "5" },
    { 6, "6" },
    { 7, "7" },
    { 8, "8" },
    { 9, "9" },
    { 10, "10" },
    { 11, "11" },
    { 12, "12" },
    { 13, "13" },
    { 14, "14" },
    { 15, "15" },
    { 16, "16" },
    { 17, "17" },
    { 18, "18" },
    { 19, "19" },
    { 20, "20" },
    { 21, "21" },
    { 22, "22" },
    { 23, "23" },
    { 24, "24" },
    { 25, "25" },
    { 26, "26" },
    { 27, "27" },
    { 28, "28" },
    { 29, "29" },
    { 30, "30" },
    { 31, "31" },
    { 32, "32" },
    { 33, "33" },
    { 34, "34" },
    { 35, "35" },
    { 36, "36" },
    { 37, "37" },
    { 38, "38" },
    { 39, "39" },
    { 40, "40" },
    { 41, "41" },
    { 42, "42" },
    { 43, "43" },
    { 44, "44" },
    { 45, "45" },
    { 46, "46" },
    { 47, "47" },
    { 48, "48" },
    { 49, "49" },
    { 50, "50" },
    { 51, "51" },
    { 52, "52" },
    { 53, "53" },
    { 54, "54" },
    { 55, "55" },
    { 56, "56" },
    { 57, "57" },
    { 58, "58" },
    { 59, "59" },
    { 60, "60" },
    { 61, "61" },
    { 62, "62" },
    { 63, "63" },
    { 64, "64" },
    { 65, "65" },
    { 66, "66" },
    { 67, "67" },
    { 68, "68" },
    { 69, "69" },
    { 70, "70" },
    { 71, "71" },
    { 72, "72" },
    { 73, "73" },
    { 74, "74" },
    { 75, "75" },
    { 76, "76" },
    { 77, "77" },
    { 78, "78" },
    { 79, "79" },
    { 80, "80" },
    { 81, "81" },
    { 82, "82" },
    { 83, "83" },
    { 84, "84" },
    { 85, "85" },
    { 86, "86" },
    { 87, "87" },
    { 88, "88" },
    { 89, "89" },
    { 90, "90" },
    { 91, "91" },
    { 92, "92" },
    { 93, "93" },
    { 94, "94" },
    { 95, "95" },
    { 96, "96" },
    { 97, "97" },
    { 98, "98" },
    { 99, "99" },
    { 100, "100" },
    { -9223372036854775808LL, "-9223372036854775808" },
    { -9223372036854775807LL, "-9223372036854775807" },
    { -9223372036854775806LL, "-9223372036854775806" },
    { -9223372036854775805LL, "-9223372036854775805" },
    { -9223372036854775804LL, "-9223372036854775804" },
    { -9223372036854775803LL, "-9223372036854775803" },
    { -9223372036854775802LL, "-9223372036854775802" },
    { -9223372036854775801LL, "-9223372036854775801" },
    { -9223372036854775800LL, "-9223372036854775800" },
    { -9223372036854775799LL, "-9223372036854775799" },
    { -9223372036854775798LL, "-9223372036854775798" },
    { -9223372036854775797LL, "-9223372036854775797" },
    { -9223372036854775796LL, "-9223372036854775796" },
    { -9223372036854775795LL, "-9223372036854775795" },
    { -9223372036854775794LL, "-9223372036854775794" },
    { -9223372036854775793LL, "-9223372036854775793" },
    { -9223372036854775792LL, "-9223372036854775792" },
    { -9223372036854775791LL, "-9223372036854775791" },
    { -9223372036854775790LL, "-9223372036854775790" },
    { -9223372036854775789LL, "-9223372036854775789" },
    { -9223372036854775788LL, "-9223372036854775788" },
    { -9223372036854775787LL, "-9223372036854775787" },
    { -9223372036854775786LL, "-9223372036854775786" },
    { -9223372036854775785LL, "-9223372036854775785" },
    { -9223372036854775784LL, "-9223372036854775784" },
    { -9223372036854775783LL, "-9223372036854775783" },
    { -9223372036854775782LL, "-9223372036854775782" },
    { -9223372036854775781LL, "-9223372036854775781" },
    { 9223372036854775780LL, "9223372036854775780" },
    { 9223372036854775781LL, "9223372036854775781" },
    { 9223372036854775782LL, "9223372036854775782" },
    { 9223372036854775783LL, "9223372036854775783" },
    { 9223372036854775784LL, "9223372036854775784" },
    { 9223372036854775785LL, "9223372036854775785" },
    { 9223372036854775786LL, "9223372036854775786" },
    { 9223372036854775787LL, "9223372036854775787" },
    { 9223372036854775788LL, "9223372036854775788" },
    { 9223372036854775789LL, "9223372036854775789" },
    { 9223372036854775790LL, "9223372036854775790" },
    { 9223372036854775791LL, "9223372036854775791" },
    { 9223372036854775792LL, "9223372036854775792" },
    { 9223372036854775793LL, "9223372036854775793" },
    { 9223372036854775794LL, "9223372036854775794" },
    { 9223372036854775795LL, "9223372036854775795" },
    { 9223372036854775796LL, "9223372036854775796" },
    { 9223372036854775797LL, "9223372036854775797" },
    { 9223372036854775798LL, "9223372036854775798" },
    { 9223372036854775799LL, "9223372036854775799" },
    { 9223372036854775800LL, "9223372036854775800" },
    { 9223372036854775801LL, "9223372036854775801" },
    { 9223372036854775802LL, "9223372036854775802" },
    { 9223372036854775803LL, "9223372036854775803" },
    { 9223372036854775804LL, "9223372036854775804" },
    { 9223372036854775805LL, "9223372036854775805" },
    { 9223372036854775806LL, "9223372036854775806" },
    { 9223372036854775807LL, "9223372036854775807" },
    { 0, 0 }
};


static void test_vector(void) {

    long long i;
    char *x;

    for (i = 0; testvectors[i].strnum; ++i) {
        x = numtostr(0, testvectors[i].num);
        if (strcmp(x, testvectors[i].strnum)) fail("numtostr() failure");
    }
}


int main(void) {

    test_bufferoverflow();
    test_minmax();
    test_vector();
    _exit(0);
}