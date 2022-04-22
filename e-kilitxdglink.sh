#!/bin/bash
FILE="$HOME/Masaüstü/e-kilit.desktop"
# init
# look for empty dir 

if [ -f $FILE ]; then
chmod 777 $FILE
chown $HOME:$HOME $FILE
/usr/bin/e-kilit
     exit
else
cp /usr/share/applications/e-kilit.desktop $FILE
chmod 777 $FILE
chown $HOME:$HOME $FILE
echo "Dosya Kopyalandı.."
/usr/bin/e-kilit
fi
exit

