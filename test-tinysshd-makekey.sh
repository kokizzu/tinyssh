#!/bin/sh

LANG=C
export LANG

LC_ALL=C
export LC_ALL

cleanup() {
  ex=$?
  rm -rf -- keydir -r
  exit "${ex}"
}
trap "cleanup" EXIT TERM INT

echo '--- tinysshd-makekey prints help'
echo
./tinysshd-makekey 2>/dev/null
echo $?
echo

echo '--- tinysshd-makekey creates key-directory'
echo
rm -rf keydir
./tinysshd-makekey keydir 2>&1
ls keydir/*.pk | sort
echo $?
echo

echo '--- tinysshd-makekey fails when directory exists'
echo
rm -rf keydir
mkdir keydir
./tinysshd-makekey keydir 2>&1
echo $?

echo "--- tinysshd-makekey handles '-r' parameter (prints help)"
echo
./tinysshd-makekey -r 2>/dev/null
echo $?
echo

echo "--- tinysshd-makekey creates '-r' key-directory"
echo
./tinysshd-makekey -- -r 2>&1
echo $?
echo
