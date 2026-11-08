#!/bin/bash
# Jalankan dari folder test_cases:  bash run_tests.sh
# Compile main.cpp (satu folder di atas), jalankan semua input, bandingkan dengan expected output.
cd "$(dirname "$0")"
TMP=$(mktemp -d)
g++ -std=c++11 -Wall -Wextra ../main.cpp -o "$TMP/planner" || exit 1
pass=0; fail=0
for input in tc*_input.txt; do
  expected="${input%_input.txt}_expected.txt"
  actual=$(timeout 5 "$TMP/planner" < "$input" 2>&1 | head -c 100000)
  if [ "$actual" == "$(cat "$expected")" ]; then
    echo "PASS  $input"; pass=$((pass+1))
  else
    echo "FAIL  $input"; fail=$((fail+1))
  fi
done
rm -rf "$TMP"
echo "Hasil: $pass lulus, $fail gagal"
[ "$fail" -eq 0 ]
