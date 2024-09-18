# ユニットテストを実行するスクリプト (Windows PowerShell)

# PlatformIOのテストコマンドを実行する関数
function Run-Tests {
    param (
        [string]$env
    )
    Write-Host "Running tests for environment: $env"
    pio test -e $env
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Tests failed for environment: $env" -ForegroundColor Red
        exit 1
    } else {
        Write-Host "Tests passed for environment: $env" -ForegroundColor Green
    }
}

# WindowsのPowerShellでは各環境に対してテストを実行
$environments = @("leonardo", "native")

foreach ($env in $environments) {
    Run-Tests -env $env
}
