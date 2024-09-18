#!/bin/bash

# ユニットテストを実行するスクリプト

# PlatformIOのテストコマンドを実行
function run_tests() {
    echo "Running tests for environment: $1"
    pio test -e "$1"
    if [ $? -ne 0 ]; then
        echo "Tests failed for environment: $1"
        exit 1
    else
        echo "Tests passed for environment: $1"
    fi
}

# MacやUbuntuではbashを使用
# 対応する環境を指定
environments=("leonardo" "native")

for env in "${environments[@]}"; do
    run_tests "$env"
done
