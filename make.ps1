Remove-item analyser.tab.c
Remove-item analyser.tab.h
Remove-item calculator.exe
Remove-item lex.yy.c
.\..\flex_bison\win_bison.exe -d analyser.y
.\..\flex_bison\win_flex.exe scanner.l
gcc lex.yy.c grammar.c grammar.h analyser.tab.h analyser.tab.c -o calculator
Get-Content config.in | .\calculator.exe