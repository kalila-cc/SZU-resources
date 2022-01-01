:: author: kalila-cc

@echo off
SET DRCOM_CARD_ID=<#card_id#>
SET DRCOM_PASSWORD=<#password#>
SET LOGIN_URL=http://172.30.255.42:801/eportal/portal/login
@echo on
curl -v %LOGIN_URL%?user_account=%%2C0%%2C%DRCOM_CARD_ID%^&user_password=%DRCOM_PASSWORD%
pause
