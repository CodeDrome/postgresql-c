
clear

#######################################################
# DDL
#######################################################

# gcc ddldemo.c cdpgconnection.c  cdpgddl.c -std=c11 -I/usr/include/postgresql -lpq -o ddldemo
# ./ddldemo

# /./home/chris/Files/C/CodeInC/code2html cdpgconnection.h
# /./home/chris/Files/C/CodeInC/code2html cdpgconnection.c
# /./home/chris/Files/C/CodeInC/code2html cdpgddl.h
# /./home/chris/Files/C/CodeInC/code2html cdpgddl.c
# /./home/chris/Files/C/CodeInC/code2html ddldemo.c

#######################################################
# DML
#######################################################

gcc dmldemo.c cdpgconnection.c  cdpgdml.c -std=c11 -I/usr/include/postgresql -lpq -o dmldemo
./dmldemo

# /./home/chris/Files/C/CodeInC/code2html cdpgconnection.h
# /./home/chris/Files/C/CodeInC/code2html cdpgconnection.c
# /./home/chris/Files/C/CodeInC/code2html gallery.h
# /./home/chris/Files/C/CodeInC/code2html photo.h
# /./home/chris/Files/C/CodeInC/code2html cdpgdml.h
# /./home/chris/Files/C/CodeInC/code2html cdpgdml.c
# /./home/chris/Files/C/CodeInC/code2html dmldemo.c
