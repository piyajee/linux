#/bin/sh
#del all '-' ':' ' '
echo "2006-11-21 22:16:30" | sed 's/-//g' | sed 's/ //g' | sed 's/://g'
