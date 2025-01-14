#!/bin/zsh

INT_MIN=-2147483648
INT_MAX=2147483647
LEAK_CHECK=0
CHECKERS=()

show_help() {
  echo "Usage: ./tester.sh [options] <number>"
  echo "Options:"
  echo "  -l           Enable memory leak checking."
  echo "  -c           Use checker_exec instead of checker_Mac."
  echo "  -a           Use both checker_exec and checker_Mac."
  echo "  -h           Show this help message."
  echo "  <number>     Number of random numbers to generate (must be a positive integer)."
}

if [[ "$1" == "-h" ]]; then
  show_help
  exit 0
fi

if [[ "$1" == "-l" ]]; then
  LEAK_CHECK=1
  shift
fi

if [[ "$1" == "-a" ]]; then
  CHECKERS=("checker_exec" "checker_Mac")
  shift
elif [[ "$1" == "-c" ]]; then
  CHECKERS=("checker_exec")
  shift
else
  CHECKERS=("checker/checker")
fi

if [[ -z "$1" || ! "$1" =~ ^[1-9][0-9]*$ ]]; then
  echo "Please specify a valid number of random numbers to generate."
  exit 1
fi

NUMBERS_COUNT=$1

if [ "$NUMBERS_COUNT" -gt $((INT_MAX - INT_MIN + 1)) ]; then
  echo "Error: The number of requested values exceeds the possible unique range between $INT_MIN and $INT_MAX."
  exit 1
fi

typeset -A unique_numbers
ARG=""

while [ ${#unique_numbers[@]} -lt $NUMBERS_COUNT ]; do
  random_number=$(( RANDOM * RANDOM % (INT_MAX - INT_MIN + 1) + INT_MIN ))
  (( random_number % 2 != 0 )) && random_number=$(( random_number * -1 ))
  
  unique_numbers[$random_number]=1
done

ARG="${(k)unique_numbers[@]}"

echo "Generated sequence of numbers: $ARG"
echo "Total numbers generated: ${#unique_numbers[@]}"

start_time_push_swap=$(date +%s)
push_swap_output=$(./push_swap $ARG)
end_time_push_swap=$(date +%s)
echo "Execution time for push_swap: $(( end_time_push_swap - start_time_push_swap )) seconds"

if (( LEAK_CHECK == 1 )); then
  echo "Checking for memory leaks with leaks..."
  leaks --atExit -- ./push_swap $ARG
fi

for CHECKER in "${CHECKERS[@]}"; do
  echo "Running $CHECKER..."
  start_time_checker=$(date +%s)
  echo "$push_swap_output" | ./$CHECKER $ARG
  end_time_checker=$(date +%s)
done

NBR_OPS=$(echo "$push_swap_output" | wc -l)
echo "Number of operations: $NBR_OPS"


echo "\nRun tester.sh -h to view all options."