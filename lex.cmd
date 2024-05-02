@echo off
tools\win_bison -H -o src\ci.tab.c src\ci.y
tools\win_flex -o src\ci.yy.c src\ci.l
