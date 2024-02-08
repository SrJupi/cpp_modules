#!/bin/bash

# Color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'

make -s

# Test cases
input_file="test_input.txt"
echo "This is a test string to test the ft_replace function." > $input_file
echo "\n${BLUE}Original file input:${NC}"
cat $input_file
echo

echo "${GREEN}Test Case 1: Replace 'test' with 'example'${NC}"
echo "./ft_replace $input_file \"test\" \"example\""
./ft_replace $input_file "test" "example"
echo -n "cat $input_file.replace = "
cat $input_file.replace
echo

echo "${GREEN}Test Case 2: Replace 'function' with 'procedure'${NC}"
echo "./ft_replace $input_file \"function\" \"procedure\""
./ft_replace $input_file "function" "procedure"
echo -n "cat $input_file.replace = "
cat $input_file.replace
echo

echo "${GREEN}Test Case 3: Replace 'string' with 'array'${NC}"
echo "./ft_replace $input_file \"string\" \"array\""
./ft_replace $input_file "string" "array"
echo -n "cat $input_file.replace = "
cat $input_file.replace
echo

echo "${YELLOW}Test Case 4: Input file is empty${NC}"
touch empty.txt
echo "touch empty.txt"
echo "./ft_replace empty.txt \"test\" \"example\""
./ft_replace empty.txt "test" "example"
echo -n "cat empty.txt.replace = "
cat empty.txt.replace
echo \\n

echo "${RED}Test Case 5: Fail to open input file${NC}"
echo "./ft_replace non_existing_file.txt \"test\" \"example\""
./ft_replace non_existing_file.txt "test" "example"
echo

echo "${RED}Test Case 6: Fail to open output file${NC}"
chmod -w test_input.txt.replace
echo "chmod -w test_input.txt.replace"
echo "./ft_replace $input_file \"test\" \"example\""
./ft_replace $input_file "test" "example"
echo

# Clean up
make -s fclean
rm -f $input_file $input_file.replace empty.txt empty.txt.replace
