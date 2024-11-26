#!/bin/bash

# 빌드
make

# 빌드 성공 시 실행
if [ $? -eq 0 ]; then
    ./RockPaperScissors
else
    echo "빌드 실패"
fi