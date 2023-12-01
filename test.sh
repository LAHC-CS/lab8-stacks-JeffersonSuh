#echo "Running tests..."
#echo

BIN=${1}
ARGS=${2}
expected_output=${3}

output=$(./bin/${BIN} ${2})


if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

#if [[ "$output" == "$expected_output" ]] ; then
#  echo "Pass: Output is correct"
#else
#  echo "Expected '$expected_output' but got: $output"
#  exit 1
#fi

#echo
#echo ${BIN}"_passed."

exit 0