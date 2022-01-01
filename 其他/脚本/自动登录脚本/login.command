# author: kalila-cc

DRCOM_CARD_ID=<#card_id#>
DRCOM_PASSWORD=<#password#>
LOGIN_URL=http://172.30.255.42:801/eportal/portal/login
curl -v $LOGIN_URL?user_account=%2C0%2C$DRCOM_CARD_ID\&user_password=$DRCOM_PASSWORD
