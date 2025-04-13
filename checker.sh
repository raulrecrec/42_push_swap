#!/bin/bash

LOG_FILE="leaks_failed.log"
TOTAL=0
FAILS=0

run_valgrind_test() {
  ARG="$1"
  ((TOTAL++))
  valgrind --leak-check=full --error-exitcode=42 --quiet ./push_swap $ARG > /dev/null
  if [ $? -eq 42 ]; then
    echo "❌ Leak detected with: $ARG"
    echo "$ARG" >> $LOG_FILE
    ((FAILS++))
  else
    echo "✅ OK: $ARG"
  fi
}

run_fast_test() {
  ARG="$1"
  ((TOTAL++))
  ./push_swap $ARG > /dev/null
  if [ $? -eq 0 ]; then
    echo "✅ OK: $ARG"
  else
    echo "❌ FAIL: $ARG"
    ((FAILS++))
  fi
}

test_permutations_n() {
  local n=$1
  > $LOG_FILE
  permute() {
    local arr=("${!1}")
    local n=$2
    if [ $n -eq 1 ]; then
      $3 "${arr[*]}"
      return
    fi
    for ((i = 0; i < n; i++)); do
      permute arr[@] $((n - 1)) "$3"
      if (( n % 2 == 0 )); then
        tmp=${arr[i]}
        arr[i]=${arr[n-1]}
        arr[n-1]=$tmp
      else
        tmp=${arr[0]}
        arr[0]=${arr[n-1]}
        arr[n-1]=$tmp
      fi
    done
  }
  base=($(seq 0 $((n - 1))))
  permute base[@] $n run_valgrind_test
}

generate_random_args() {
  local size=$1
  seq 0 $((size - 1)) | shuf | tr '\n' ' '
}

run_random_tests() {
  local count=$1
  local size=$2
  local use_valgrind=$3
  > $LOG_FILE
  for ((i = 0; i < count; i++)); do
    ARG=$(generate_random_args "$size")
    if [ "$use_valgrind" = true ]; then
      run_valgrind_test "$ARG"
    else
      run_fast_test "$ARG"
    fi
  done
}

case "$1" in
  test3)
    test_permutations_n 3
    ;;
  test4)
    test_permutations_n 4
    ;;
  test5)
    test_permutations_n 5
    ;;
  random)
    run_random_tests "$2" "$3" true
    ;;
  fastrandom)
    run_random_tests "$2" "$3" false
    ;;
  *)
    echo "Uso:"
    echo "  $0 test3|test4|test5"
    echo "  $0 random <n_tests> <size>      # con valgrind"
    echo "  $0 fastrandom <n_tests> <size>  # sin valgrind"
    exit 1
    ;;
esac

echo "------------------------------------------------"
echo "Total tests: $TOTAL"
echo "Leaks or failures: $FAILS"
if [ $FAILS -gt 0 ]; then
  echo "❗ Ver detalles en: $LOG_FILE"
fi
