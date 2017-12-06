다음과 같은 사항을 반영하도록 small-shell을 update하시오.

 

1. cd command를 실행하도록 수정하시오.

2. 다음 3가지 signal, SIGTSTP; SIGQUIT; SIGINT을 catch하여 그 종류를 터미널에 출력하는 프로그램을 작성하시오.(단, 이때 smallsh이 종료되지 않도록 작성)

3. pipeline 명령을 수행하도록 수정하시오.

3.1 단일 ex) ls -al | grep unix

3.2 중첩 ex) prog1 | prog2 | prog3

4. redirection 명령을 수행하도록 수정하시오.

ex) ls ?al > tmp.txt

ex) sort < ./tmp.txt (변경 전, tmp.log < dmesg)

5. exit을 입력할 경우 종료하시오.